#include <assert.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum {
    MAX_NUMBER_OF_NODES = 1500000, NUM_OF_ALPHA = 26, MAX_LENGTH_OF_WORD = 100,
    MAX_OCCURENCE_OF_SAME_WRONG_WORD = 10000, MAX_NUMBER_OF_WRONG_WORDS = 600000,
};
int trie[MAX_NUMBER_OF_NODES][NUM_OF_ALPHA + 1], next = 0;
typedef long long ll;

void build_trie(char s[]);
bool contains(char s[]);
ll get_word(char s[], FILE *in);
int wrong_word_cmp(const void *p1, const void *p2);
int ll_cmp(const void *p1, const void *p2);
void spell_check(const char *dictionary, const char *article, const char *misspelling);

void build_trie(char s[])
{
    ll i, t = 1;
    for (i = 0; s[i] != '\0'; ++i)
    {
        if (isupper(s[i]))
        {
            s[i] = tolower(s[i]);
        }
        int pos = s[i] - 'a';
        if (trie[t][pos] == 0)
        {
            assert(next < MAX_NUMBER_OF_NODES);
            trie[t][pos] = ++next;
        }
        t = trie[t][pos];
    }
}

/* Check if the trie contains the string s */
bool contains(char s[])
{
    ll i, t = 1;
    for (i = 0; s[i] != '\0'; ++i)
    {
        assert(isalpha((unsigned char)s[i]));
        int pos = tolower((unsigned char)s[i]) - 'a';
        if (pos < 0 || pos > NUM_OF_ALPHA)
        {
            fprintf(stderr, "Assertion: [%s] %lld == %c (pos = %d)\n", s, i, s[i], pos);
        }
        assert(pos >= 0 && pos <= NUM_OF_ALPHA);
        if (trie[t][pos] == 0)
        {
            return false;
        }
        t = trie[t][pos];
    }
    return true;
}

ll current_pos = 0;

static inline int f_getc(FILE *fp)
{
    int c = fgetc(fp);
    if (c != EOF)
        current_pos++;
    return c;
}

ll get_word(char s[], FILE *in)
{
    ll c, begin_of_word = 0, lim = MAX_LENGTH_OF_WORD;
    char *w = s;
    while (!isalpha(c = f_getc(in)) && c != EOF)
        ;
    assert(isalpha(c) || c == EOF);
    if (c == EOF)
    {
        *w = '\0';
        return c;
    }
    *w++ = tolower(c);
    begin_of_word = current_pos;
    for ( ; --lim > 0; ++w)
    {
        if (!isalpha(c = f_getc(in)))   /* End of word. */
        {
            //current_pos = w + 1 - s + begin_of_word;
            break;
        }
        *w = tolower(c);
    }
    *w = '\0';
    printf("%s: %lld %zu [%s]\n", __func__, begin_of_word, strlen(s), s);
    return begin_of_word;
}

typedef struct WrongWord WrongWord;
struct WrongWord
{
    char word[MAX_LENGTH_OF_WORD];
    ll pos;
};

int wrong_word_cmp(const void *p1, const void *p2)
{
    return strcmp((*(const WrongWord **)p1)->word, (*(const WrongWord **)p2)->word);
}

int ll_cmp(const void *p1, const void *p2)
{
    return *((const ll **)p1) - *((const ll **)p2);
}

WrongWord *wrong_word_list[MAX_NUMBER_OF_WRONG_WORDS];

static void read_dictionary(const char *dictionary)
{
    FILE *dict = fopen(dictionary, "r");
    if (dict == NULL)
    {
        fprintf(stderr, "file '%s' cannot be opened for reading\n", dictionary);
        return;
    }
    char word[MAX_LENGTH_OF_WORD];
    while (fgets(word, sizeof word, dict))
    {
        word[strcspn(word, "\r\n")] = 0;
        build_trie(word);
    }
    fclose(dict);
}

void spell_check(const char *dictionary, const char *article, const char *misspelling)
{
    /* Builds the trie from dictionary .*/
    read_dictionary(dictionary);

    FILE *in = fopen(article, "r");
    if (!in)
    {
        fprintf(stderr, "file '%s' cannot be opened for reading\n", article);
        return;
    }
    char str[MAX_LENGTH_OF_WORD];
    ll begin_of_word = 0;
    ll wrong_word_count = 0;
    while ((begin_of_word = get_word(str, in)) != EOF)
    {
        if (!contains(str))
        {
            //WrongWord *wwp = malloc(sizeof wrong_word_list[0]);
            WrongWord *wwp = malloc(sizeof(*wwp));
            static int done = 0;
            if (!done)
                printf("Sizes: %zu %zu %zu\n", sizeof(wrong_word_list[0]), sizeof(*wwp), sizeof(WrongWord)), done++;
            if (!wwp)
            {
                fprintf(stderr, "Memory error!\n");
                return;
            }
            printf("%s: %lld %zu [%s] %lld\n", __func__, begin_of_word, strlen(str), str, wrong_word_count+1);
            strcpy(wwp->word, str);
            wwp->pos = begin_of_word;
            wrong_word_list[wrong_word_count++] = wwp;
        }
    }
    fclose(in);
    qsort(wrong_word_list, wrong_word_count, sizeof wrong_word_list[0], wrong_word_cmp);

    /* Adds a sentinel node. */
    wrong_word_list[wrong_word_count] = malloc(sizeof wrong_word_list[0]);
    strcpy(wrong_word_list[wrong_word_count++]->word, "");

    /* Prints the result into misspelling.txt */
    FILE *out = fopen(misspelling, "w");
    if (!out)
    {
        fprintf(stderr, "file '%s' cannot be opened for writing\n", misspelling);
        return;
    }
    char last_word[MAX_LENGTH_OF_WORD] = "";
    ll i, j, pos[MAX_OCCURENCE_OF_SAME_WRONG_WORD], count = 0;
    for (i = 0; i < wrong_word_count; ++i)
    {
        if (strcmp(last_word, wrong_word_list[i]->word))    /* Meets a new word. */
        {
            if (*last_word)    /* Prints the last word if exists. */
            {
                fprintf(out, "%s ", last_word);
                qsort(pos, count, sizeof pos[0], ll_cmp);
                for (j = 0; j < count; ++j)
                {
                    fprintf(out, "%lld%c", pos[j], j == count - 1 ? '\n' : ' ');
                }
            }
            count = 0;
            strcpy(last_word, wrong_word_list[i]->word);
            pos[count++] = wrong_word_list[i]->pos;
            assert(count < MAX_OCCURENCE_OF_SAME_WRONG_WORD);
        }
        else      /* Same word. */
        {
            pos[count++] = wrong_word_list[i]->pos;
            assert(count < MAX_OCCURENCE_OF_SAME_WRONG_WORD);
        }
    }
    fclose(out);

    /* free wrong word list */
    for (int i = 0; i < wrong_word_count; i++)
    {
        free(wrong_word_list[i]);
    }
    wrong_word_count = 0;

}

int main(int argc, char **argv)
{
    const char *dictionary = "dictionary.txt";
    const char *article = "text.txt";
    const char *misspelling = "misspelling.txt";
    if (argc > 1)
        dictionary = argv[1];
    if (argc > 2)
        article = argv[2];
    if (argc > 3)
        misspelling = argv[3];
    spell_check(dictionary, article, misspelling);
    return 0;
}
