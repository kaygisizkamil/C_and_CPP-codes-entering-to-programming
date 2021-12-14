/***********************************************************************************************************************
**								SAKARYA ÜNİVERSİTESİ
**			         BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**				    BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				          PROGRAMLAMAYA GİRİŞİ DERSİ
**				ÖDEV NUMARASI:1
**				ÖĞRENCİ ADI:KAMİL KAYGISIZ
**				ÖĞRENCİ NUMARASI:B211210381
**				DERS GRUBU:1.ÖĞRETİM A
**************************************************************************************************************************/

#include <iostream>
#include<string>//clear() ,length() vs kullanabilmek için
#include<ctime>//rand()function
#include<cstdlib>//srand time için
#include<locale.h>//türkçe karakter kullanabilmek için
using namespace std;

int main() {
	setlocale(LC_ALL, "Turkish");
	const int MAX = 81;//max sehir sayisi 81 oldugu icin sabit tanımladım
	const long int denemeSayisi = 1000000;//ya sehir bulunasıya kadar ya da bu deneme sayısı saglanana kadar arama yapılacak
										//deneme sayısı arttıkca bulma oranı da artıyor
	const int uzunlukDegeri = 15;//random sehir seciminde string array için bir const uzunluk belirlenmeliydi
	string sehirler[MAX] = { "ADANA", "ADIYAMAN", "AFYONKARAHİSAR", "AĞRI", "AKSARAY", "AMASYA", "ANKARA", "ANTALYA", "ARDAHAN",
						 "ARTVİN", "AYDIN", "BALIKESİR", "BARTIN", "BATMAN", "BAYBURT", "BİLECİK", "BİNGÖL", "BİTLİS", "BOLU", "BURDUR",
						 "BURSA", "ÇANAKKALE", "ÇANKIRI", "ÇORUM", "DENİZLİ", "DİYARBAKIR", "DÜZCE", "EDİRNE", "ELAZIĞ",
						 "ERZİNCAN", "ERZURUM", "ESKİŞEHIR", "GAZİANTEP", "GİRESUN", "GÜMÜŞHANE", "HAKKÂRİ", "HATAY", "IĞDIR", "ISPARTA",
						 "İSTANBUL", "İZMİR", "KAHRAMANMARAŞ","KARABÜK", "KARAMAN", "KARS", "KASTAMONU", "KAYSERİ", "KİLİS", "KIRIKKALE",
						 "KIRKLARELİ", "KIRŞEHİR", "KOCAELİ", "KONYA", "KÜTAHYA","MALATYA", "MANİSA", "MARDİN", "MERSİN", "MUĞLA", "MUŞ",
						 "NEVŞEHİR", "NİĞDE", "ORDU", "OSMANİYE", "RİZE", "SAKARYA", "SAMSUN", "ŞANLIURFA","SİİRT", "SİNOP", "SİVAS", "ŞIRNAK",
						 "TEKİRDAĞ", "TOKAT", "TRABZON", "TUNCELİ", "UŞAK", "VAN", "YALOVA", "YOZGAT", "ZONGULDAK" };
	string  kopyaSehir[uzunlukDegeri];/*visual studio sabit olmayan uzunlukta array tanımlamasına izin vermedigi icim icerigini const tanımlamam
										gerekliydi .Random secimler sonucu secilen sehirleri daha sonra birlestirme yapmak icin kopya
										bir string array olusturdum*/

	string kontrolSehiri;//random kelimelerin harflerini bunun icine birlestirecegim
	int min, max, tempMin, tempMax;//sehirlerin en kısa ve en uzununu bulmak icin kullanılacak
	int randomUretilsinmi = 1;//yeni random uretilecek mi kontrol degiskeni
	int randControl;//rand secilecek kelime icin array indexini tutar
	int i, j, x, y;	//dongu kontrol degiskenleri,j'yi ekstra olarak en kısa ve en uzununun indexini tutmak için kullandım
	int k;//string arrayin satır degiskeni(kelime)
	int l = 0;//string arrayin sütun yani harf degiskeni 
	int kelimeBulundu;//bulunmamış varsayıp ilk degerini sıfıra atiyorum bulunursa 1e donecek kontrol saglayacak
	long int denemeCounter = 0;//long olmasının sebebi deneme sayısının istege gore desteklenene max degere artırılabilir olması için
	//en kucuk ve en buyuk uzunluklu sehirleri buluyor.
	min = sehirler[0].length();//ilk sehiri en kucuk varsayip daha sonra ona gore arama yapıyorum
	for (i = 1; i < MAX; i++) {
		if (sehirler[i].length() < min) {
			j = i;//yazdırmak için indexini aldim
			min = sehirler[i].length();
			tempMin = min;//daha sonra bu en kucuk sehiri tekrar kullanabilmek icin baska bir degiskende de tutuyorum
		}
	}
	cout << "En kısa şehir = " << sehirler[j] << " karakter sayısı= " << min << endl;
	max = sehirler[0].length();//ilk sehiri en buyuk  sayıp daha sonra ona gore arama yapıyorum
	for (i = 1; i < MAX; i++) {
		if (sehirler[i].length() > max) {
			j = i;//yazdırmak için indexini aldim..
			max = sehirler[i].length();
			tempMax = max;//daha sonra bu en buyuk sehiri tekrar kullanabilmek için baska bir degiskende de tutuyorum
		}
	}
	cout << "En uzun şehir = " << sehirler[j] << " karakter sayısı= " << max << endl;

	srand((unsigned int)time(NULL));//unsigned yapıldı yoksa VScode warning veriyor
	while (denemeCounter <= denemeSayisi) {//olusturulan random sehir string array icinde yoksa denemeSayoisina  kadar deneme yapilacak		
								//stringi digerine karakter-karakter kopyalarken 0.indexten atayarak kopyalamaya baslıyor
		if (randomUretilsinmi == 1) {//1 ise random şehir sececek 0 ise secilmis sehirin  sırayla harflerini baska stringe kopyalayacak.
			denemeCounter += 1;
			for (i = 0; i < tempMin; i++) {//tempMin en kısa harfli ili temsil ediyor
													//tempMin kadar kelime sececegiz tempMin her seferinde 1 artirilacak tempMaxa kadar
				randControl = rand() % 81;//en kısa harflinin harf sayısı kadar rasgele il seçmek icin index belirliyorum
				kopyaSehir[i] = sehirler[randControl];
				//cout << "rasgele secilmis sehir" << kopyaSehir[i]<<"uzunluk"<<kopyaSehir[i].length()<<endl;//random secim yapılıyor mu kontrol için yazılabilir
			}
			min = kopyaSehir[0].length();//arama yaparken rasgele secilmis kelimelerin en kısa harflisini buldum harf birlestirmede
										//yardımcı olacak en kısa 3 harfliyse diger kelimelerin daha sonraki harfleri icin birlestirmee yapmaya calismayacak
										//arrayin boyut dısını okumaya calısırsak error verebilir
			for (j = 0; j < tempMin; j++) {//sırayla 0 dan baslayıp tempMin'inci kelimeye kadar stringlerin harf uzunluklarını kontrol ediyor
				if (kopyaSehir[j].length() < min) {
					min = kopyaSehir[j].length();//random secilenlerin arasındaki en kısa olanı buluyorum
				}
			}
			randomUretilsinmi = 0;//random seimi bitti secilenlerin birlestirilmesi icin diger adımaa gecmesi lazım bunun icin 0'a atandı.
		}

		if (randomUretilsinmi == 0) {//arama yapıyor 
			for (k = 0; k < tempMin; k++) {//0. indexten baslayip en kısa kelimenin son harfine kadar ekleme yapiyorum
				if (l < min) {//l column indexi eklenecek harfi temsil ediyor.en kısa kelime uzunluguna gelindiyse ekleme yapılmayacak
							//(min random secilen en kısa sehir,tempMin 81 ildeki en kısa sehiri temsil eder
					kontrolSehiri += kopyaSehir[k][l];//harfleri birlestirip bunlari bir stringe atiyorum sonrasında
														//bunu aramada kullanacagım
				}
			}
			if (!kontrolSehiri.empty()) {//kesinlik icin string bos mu kontrol ediyorum good practice
				for (x = 0; x < MAX; x++) {//0 dan baslayip tum sehirler içinde arama yapıyorum
					if (kontrolSehiri.compare(sehirler[x]) == 0) {//0 a esitse kelimeler esit demektir
						kelimeBulundu = 1;//kelime bulunduysa belirtmek icin controllerimi 1e ayarlıyorum
						break;//iç döngüden çıkıp bulunan kelimeyi yazdırıyorum
					}
					else if (kontrolSehiri.compare(sehirler[x]) != 0)//0 dan farklıysa kelimeler farklıdır
						kelimeBulundu = 0;//bulunamadıysa sifira atiyorum ki tekrar birlestirme yapılabilsin
				}
			}
		}

		if (kelimeBulundu == 1) {//kelime bulunduysa  kelimeyi yazdır
			cout << "Random seçim ve birleştirme sonucu " <<
				tempMin << " harfli bulunan şehir: " << kontrolSehiri << endl;
			for (y = 0; y < tempMax; y++) {
				kopyaSehir[y].clear();//sonraki seferler icin stringi temizliyor/ilk haline geri donduruyorum
			}
			kontrolSehiri.clear();//kontrolSehiriini  de sıfırlıyorum yeni eklemelerde lazım olacak
			l = 0;//kelime bulundu sonraki kelimelerin baştan 0.indexlerin kontrolü için ikinci boyut indexini 0ladım
			tempMin += 1;//min harfli birlestirme sonucu bulundu.aka :başta 3 harfli olsun 4 e artırıp 4 tane random sececek
			denemeCounter = 0;//deneme sayısını 0 layıp sonraki seferler icinde istenen kadar denenmesini saglıyorum
			randomUretilsinmi = 1;//1 se yeni random sececek 
		}
		else if (kelimeBulundu == 0) {//eger kelime bulunamadıysa
			if (denemeCounter < denemeSayisi) {//ve eger deneme sayısının sonuna kadar  gelmediysek
				if (l < min) {//ve en kısa harfli kelime sayisinin son indexine kadar butun birlestirmeler yapilmasi tamamlanmadiysa
					randomUretilsinmi = 0;
					kontrolSehiri.clear();//0lamamın sebebi sonraki indexlerin birlestirilip kontrol edilebilmesi eskisinin üstüne
										  // yazılmamasınicim
					l += 1;//sütun yani kelimenin harf indexini artırıyorum
				}
				else if (l == min) {//en kısa kelimenin harf sayısı kadar birlestirmeler yapıldıysa yeni random uretmek gereklidir
					randomUretilsinmi = 1;
					for (y = 0; y < tempMax; y++) {
						kopyaSehir[y].clear();//sonraki seferler icin stringi temizliyor/ilk haline geri donduruyorum
					}
					kontrolSehiri.clear();
					l = 0;//kelime bulunamadi ise sonraki rand secilecek kelimelerin baştan 0.indexlerin kontrolü için
						// ikinci boyut indexini 0ladım
				}
			}
			if (denemeCounter == denemeSayisi) {//deneme sayısı tamamlandıysa
				if (tempMin == tempMax) {//ve max harfli kelime kadar kelime secilip birlestirildiyse dongu tamamlandı demektir
					cout << "Random seçim ve birleştirme sonucu " << tempMin << " harfli şehir listede bulunamadi " << endl;
					break;//döngüden çıkış
				}
				else {
					randomUretilsinmi = 1;
					denemeCounter = 0;//sonraki kelime aramaları için şartı 0lıyorum
					cout << "Random seçim ve birleştirme sonucu " << tempMin << " harfli şehir listede bulunamadi" << endl;
					kontrolSehiri.clear();//üstüne yazmaması için bufferi sıfırladım-temizledim
					l = 0;//kelime bulunamadi ise sonraki rand secilecek kelimelerin baştan 0.indexlerin kontrolü için
						 // ikinci boyut indexini 0ladım
					for (y = 0; y < tempMax; y++) {
						kopyaSehir[y].clear();//sonraki seferler icin stringi temizliyor/ilk haline geri donduruyorum
					}
					tempMin += 1;//sonraki en kısa harfli kelime kadar kelime secilmesi icin artırma yaptım.
				}
			}
		}

	}

}
