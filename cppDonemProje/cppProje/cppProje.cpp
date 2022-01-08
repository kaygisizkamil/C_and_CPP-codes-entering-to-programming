// fileProject.cpp : Bu dosya 'main' iÅŸlevi iÃ§eriyor. Program yÃ¼rÃ¼tme orada baÅŸlayÄ±p biter.

#include <iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include<cstring>

using namespace std;
string searchForSiparis(string  urununKodu,string musteriTipi,int* kontrol) {
    string kod;//alinan kontrol degerine gore ilgili urun koduna ait musteri tipini bulan fonksiyon kontrol 1 ise musteri kayitli demektir gemel veya ozel farketmez
    string urunAdi;
    string uretici;
    string teminSuresi;
    string uretimTarihi;
    string fiyatGenel;
    string fiyatOzel;
    string kdvRate;
    string stokNum;
    ifstream finUrun;
    string genel, ozel;
    string donecekTip;
    
    genel = "GENEL";
    ozel = "OZEL";
    finUrun.open("URUN.txt");
    char c = ',';

    *kontrol= -1;
    while (finUrun) {
        //urun bulunursa siparis fiyatini genel veya ozelden hesaplayabilmek icin musteri hangisine kayıitıysa onu dondurur. 
        getline(finUrun, kod, ',');
        getline(finUrun, urunAdi, ',');
        getline(finUrun, uretici, ',');
        getline(finUrun, teminSuresi, ',');
        getline(finUrun, uretimTarihi, ',');
        getline(finUrun, fiyatGenel, ',');
        getline(finUrun, fiyatOzel, ',');
        getline(finUrun, kdvRate, ',');
        getline(finUrun, stokNum);
        if (urununKodu == kod) {
            if (musteriTipi == genel) {
                donecekTip = fiyatGenel;
            }
            else if (musteriTipi == ozel) {
                donecekTip = fiyatGenel;
            }
            *kontrol = 1;
            break;
        }
        if (finUrun.eof()) {
            break;
        }
    }
    return donecekTip;


    finUrun.close();
}
string searchForOther(string firmaNUM) {//musteri kategorisi return etmek icin kullanilir genel veya ozel olmasina gore class icinde ustteki fonk cagirilarak siparis islemleri olacak
    string firmNum;
    string firmAd;
    string firmTel;
    string firmSor;
    string musteriKat;
    string adres;
    ifstream finCari;
    ofstream foutCari;
    ofstream foutCopyCari;
    ofstream foutCopyCari2;
    finCari.open("CARI.txt");
    string temp = "gecersiz";

    while (finCari) {

        getline(finCari, firmAd, ',');
        getline(finCari, firmNum, ',');
        getline(finCari, firmTel, ',');
        getline(finCari, firmSor, ',');
        getline(finCari, musteriKat, ',');
        getline(finCari, adres);
        if (finCari.eof()) {

            break;
        }
        if (firmaNUM == firmNum) {


            temp.clear();
            temp = musteriKat;
            break;
        }
        else {
            temp = "gecersiz";
        }
    }
    return temp;
    finCari.close();

}


class Urun {//for urun.txt
    
public:
    Urun() {
        counter = 0;
         kod = "";
         urunAdi = "";
         uretici = "";
        teminSuresi = "";
         uretimTarihi = "";
        fiyatGenel = "";
        fiyatOzel = "";
         kdvRate = "";
        stokNum = "";
        

       
    
    }
  

    void ekleUrun() {//ekleme ve duzeltme bu fonk icinde olacak  
        ++counter;
        char c = ',';
        cout <<"\n"<<"Lutfen ilgili kisimlari doldurunuz" << endl;
        cout << "\n"<<"URUN KODU: ";        getline(cin, kod);
        cout << "URUN ADI: ";         getline(cin, urunAdi);
        cout << "URUN URETICISI: ";   getline(cin, uretici);//stokNuma kadar cin ile alinmisti getline kullanimina gecildi
        cout << "URUN TEMIN SURESI:(Kac gun) ";  getline(cin, teminSuresi);
        cout << "URUN URETIM TARIHI:(xx.xx.xxxx) ";  getline(cin, uretimTarihi);
        cout << "URUN FIYATI(GENEL) : "; getline(cin, fiyatGenel);
        cout << "URUN FIYATI(OZEL): ";  getline(cin, fiyatOzel);
        cout << "KDV ORANI: ";          getline(cin, kdvRate);
        cout << "STOK SAYISI:(Sayi giriniz): ";          getline(cin, stokNum);
        cout << endl;
        //cin.ignore(numeric_limits<streamsize>::max(), '\n');;//bundan sonraki cagirmalarda getline yeni okuma yaparken \n gorup okuma orada sonlanmasin diye.

        foutUrun.open("URUN.txt", ios::app | ios::out);
        if (!foutUrun)
            cerr << "Dosya acilamadi" << endl;
        else {
            foutUrun << kod << c << urunAdi << c << uretici << c << teminSuresi
                << c << uretimTarihi << c <<
                fiyatGenel << c << fiyatOzel << c <<
                kdvRate << c << stokNum << endl;
            foutUrun.close();
        }

    }


    void searchUrun() {
        finUrun.open("URUN.txt");
        string thatKod;
        cout << "\n" << "Lutfen aramak istediginiz urunun kodunu giriniz: " ;    getline(cin, thatKod);
        char c = ',';

        //cin.ignore(numeric_limits<streamsize>::max(), '\n');
        while (true) {
           
            getline(finUrun, kod, ',');
            getline(finUrun, urunAdi, ',');
            getline(finUrun, uretici, ',');
            getline(finUrun, teminSuresi, ',');
            getline(finUrun, uretimTarihi, ',');
            getline(finUrun, fiyatGenel, ',');
            getline(finUrun, fiyatOzel, ',');
            getline(finUrun, kdvRate, ',');
            getline(finUrun, stokNum);

            if (finUrun.eof()) {
                if (thatKod != kod)
                    cout << "\n" << "Aradiginiz urunle ilgili kayit bulunamadi." << endl;
                break;
            }

            if (thatKod == kod) {
                cout << "\n" << "Aranan urunle ilgili dosyada bulunan kayit:" << endl;
                cout << "\n"<<"URUN KODU: "  << kod << "\n" << "URUN ADI: " << urunAdi << "\n" << "URUN URETICISI: " << uretici << "\n" <<
                    "URUN TEMIN SURESI: " << teminSuresi << "\n"
                    << "URUN URETIM TARIHI: "  << uretimTarihi << "\n" << "URUN FIYATI:(G) "  << fiyatGenel << "\n" <<
                    "URUN FIYATI(O): " << fiyatOzel << "\n"
                    << "KDV ORANI: " << kdvRate << "\n" << "STOK SAYISI: "  << stokNum << endl;
                break;

            }
        }
        finUrun.close();
    }
   

    void showUrun() {//butun urunleri listeleyen func
        char c = ',';
        finUrun.open("URUN.txt");
        foutCopyUrun.open("DEGISTIRME.txt", ios::out);
        while (true) {
           
         
            getline(finUrun, kod, ',');
            getline(finUrun, urunAdi, ',');
            getline(finUrun, uretici, ',');
            getline(finUrun, teminSuresi, ',');
            getline(finUrun, uretimTarihi, ',');
            getline(finUrun, fiyatGenel, ',');
            getline(finUrun, fiyatOzel, ',');
            getline(finUrun, kdvRate, ',');
            getline(finUrun, stokNum);

            if (finUrun.eof()) {
                break;
            }


            cout << "\n"<<"URUN KODU : " << kod << "\n" << "URUN ADI : " << urunAdi << "\n" << "URUN URETICISI : " << uretici << "\n" <<
                "URUN TEMIN SURESI: " << teminSuresi << "\n"
                << "URUN URETIM TARIHI: " << uretimTarihi << "\n" << "URUN FIYATI(G): " << fiyatGenel << "\n" <<
                "URUN FIYATI(O): " << fiyatOzel << "\n"
                << "KDV ORANI: " << kdvRate << "\n" << "STOK SAYISI: " << stokNum << endl;
        }
        finUrun.close();


    }


    void duzeltUrun() {
        char c = ',';
        bool kelimeBulundu = false;
        string thatCode;
        cout <<"\n"<< "Degistirmek istediginiz urunun kodunu giriniz: ";
        getline(cin, thatCode);
        finUrun.open("URUN.txt");
        foutCopyUrun.open("DEGISTIRME.txt", ios::out);
        while (finUrun) {
            
            getline(finUrun, kod, ',');
            getline(finUrun, urunAdi, ',');
            getline(finUrun, uretici, ',');
            getline(finUrun, teminSuresi, ',');
            getline(finUrun, uretimTarihi, ',');
            getline(finUrun, fiyatGenel, ',');
            getline(finUrun, fiyatOzel, ',');
            getline(finUrun, kdvRate, ',');
            getline(finUrun, stokNum);

            if (finUrun.eof()) {
                if (!kelimeBulundu) {
                    cout <<"\n" <<"Guncellemek istediginiz urune ait kayit bulunamadi." << endl;
                }
                else {
                    cout << "\n" << "Ilgili urun guncellendi." << endl;
                }
                break;
            }


            if (thatCode != kod) {//eger urun listede bulunmuyorsa

                foutCopyUrun << kod << c << urunAdi << c << uretici << c << teminSuresi
                    << c << uretimTarihi << c <<
                    fiyatGenel << c << fiyatOzel << c <<
                    kdvRate << c << stokNum << endl;
            }


            else if (thatCode == kod) {//eger urun listede bulunuyorsa
                kelimeBulundu = true;
                cout <<"\n"<< "Guncellemek istediginiz urunun onceki ozellikleri asagidaki gibidir" << endl;
                cout <<"\n"<< "URUN KODU: " << kod << "\n" << "URUN ADI: " << urunAdi << "\n" << "URUN URETICISI: " << uretici << "\n" <<
                    "URUN TEMIN SURESI: " << teminSuresi << "\n"
                    << "URUN URETIM TARIHI: " << uretimTarihi << "\n" << "URUN FIYATI(G): " << fiyatGenel << "\n" <<
                    "URUN FIYATI(O): " << fiyatOzel << "\n"
                    << "KDV ORANI: " << kdvRate << "\n" << "STOK SAYISI: " << stokNum << endl;
                cout << "Yeni urun kodunu giriniz: ";        getline(cin, kod);
                cout << "Yeni urun adini giriniz: ";         getline(cin, urunAdi);
                cout << "Yeni urun ureticisi giriniz: ";   getline(cin, uretici);
                cout << "Yeni temin suresini giriniz: ";  getline(cin, teminSuresi);
                cout << "Yeni uretim tarihini giriniz: ";  getline(cin, uretimTarihi);
                cout << "Yeni urun fiyatini giriniz(ozel): "; getline(cin, fiyatGenel);
                cout << "Yeni urun fiyatini giriniz(genel): ";  getline(cin, fiyatOzel);
                cout << "Yeni KDV orani giriniz: ";          getline(cin, kdvRate);
                cout << "Yeni stok sayisini giriniz: ";           getline(cin, stokNum);
               
                foutCopyUrun << kod << c << urunAdi << c << uretici << c << teminSuresi
                    << c << uretimTarihi << c <<
                    fiyatGenel << c << fiyatOzel << c <<
                    kdvRate << c << stokNum << endl;
             


            }





        }
        finUrun.close();
        foutCopyUrun.close();
        remove("URUN.txt");
        rename("DEGISTIRME.txt", "URUN.txt");
    }
   
    void deleteUrun() {
        --counter;
        bool kelimeBulundu = false;
        char c = ',';
        string thatCode;
        cout <<"\n"<< "Silmek istediginiz urunun kodunu giriniz: " ;
       getline(cin,thatCode);
        finUrun.open("URUN.txt");
        foutCopyUrun.open("DEGISTIRME.txt", ios::out);
        while (true) {
            if (counter == 0) {
              //  cout << "\n"<<"Kayitli urun olmadigi icin silme yapilamiyor lutfen once urun girisi saglayiniz" << endl;
                break;
            }

            getline(finUrun, kod, ',');
            getline(finUrun, urunAdi, ',');
            getline(finUrun, uretici, ',');
            getline(finUrun, teminSuresi, ',');
            getline(finUrun, uretimTarihi, ',');
            getline(finUrun, fiyatGenel, ',');
            getline(finUrun, fiyatOzel, ',');
            getline(finUrun, kdvRate, ',');
            getline(finUrun, stokNum);
            if (finUrun.eof()) {
                if (!kelimeBulundu) {
                    cout << "\n"<<"Silmek istediginiz urune ait kayit bulunamadi" << endl;

                }
                else {
                    cout << "\n"<<"Urun listeden silindi" << endl;
                }
                break;
            }
            /* if (searchUrun(thatCode) == false)
             else*/


            if (thatCode == kod) {//eger urun listede bulunuyorsa
                //bu kisma show code kismi gelecek.
                kelimeBulundu = true;
                cout << "\n"<<"Silmek istediginiz urunun ozellikleri: " << endl;
                cout <<"\n"<< "URUN KODU: " << kod << "\n" << "URUN ADI: " << urunAdi << "\n" << "URUN URETICISI: " << uretici << "\n" <<
                    "URUN TEMIN SURESI: " << teminSuresi << "\n"
                    << "URUN URETIM TARIHI: " << uretimTarihi << "\n" << "URUN FIYATI(G): " << fiyatGenel << "\n" <<
                    "URUN FIYATI(O): " << fiyatOzel << "\n"
                    << "KDV ORANI: " << kdvRate << "\n" << "STOK SAYISI: " << stokNum << endl;
         
            }
            else {//eger urun listede bulunmuyorsa
                foutCopyUrun << kod << c << urunAdi << c << uretici << c << teminSuresi
                    << c << uretimTarihi << c <<
                    fiyatGenel << c << fiyatOzel << c <<
                    kdvRate << c << stokNum << endl;
            }
        }
        finUrun.close();
        foutCopyUrun.close();
        remove("URUN.txt");
        rename("DEGISTIRME.txt", "URUN.txt");



    }
   
 
   

private:
    string kod;
    string urunAdi;
    string uretici;
    string teminSuresi;
    string uretimTarihi;
    string fiyatGenel;
    string fiyatOzel;
    string kdvRate;
    string stokNum;
    ifstream finUrun;

    ofstream foutUrun;
    ofstream foutCopyUrun;
    int counter;
    friend class Siparis;


};

class Cari {//for cari.txt
    
public:
    Cari(){
        sayac = 0;
        firmNum="";
        firmAd="";
        firmTel="";
        firmSor="";
         musteriKat="genel";//hata cikmamasi icin initialize ettim
        adres="";

    };
    string harfBuyut(string str) {//kullanici genel-ozel girerse musteri ve siparis kisimlarinda harflerini buyuk harfe cevirmek icin kullanilacak
        for (int i = 0; str[i] != 0; i++) {
            if (str[i] <= 'z' && str[i] >= 'a')
                str[i] += 'A' - 'a';
        }
        return str;
    }
    void ekleMusteri() {//ekleme ve duzeltme bu fonk icinde olacak 1 girdigi surece yeni siparis ekleme devam edecek.
        ++sayac;
        char c = ',';
        string temp;
        string genel = "GENEL";
        string ozel = "OZEL";
        bool dogruMu = false;
       
        cout << "\n" << "Lutfen ilgili kisimlari doldurunuz" << endl;
        cout << "FIRMA ADI: ";       getline(cin, firmAd);
        cout << "FIRMA NUMARASI: ";   getline(cin,firmNum);
        cout << "FIRMA TELEFONU: ";  getline(cin, firmTel);
        cout << "FIRMA SORUMLUSU: "; getline(cin, firmSor);
        cout << "MUSTERI KATEGORISI(GENEL/OZEL): "; getline(cin, musteriKat);
        cout << "FIRMA ADRESI: ";  getline(cin,adres);
        temp=harfBuyut(musteriKat);    //genel veya ozel girmesine gore harflerin hepsini buyutup kiyaslamada kolaylik saglayacak
        musteriKat.clear();
        musteriKat=temp;
        cout <<"musteri kat"<< musteriKat << endl;
        while (!dogruMu) {
            if (musteriKat.compare(genel) == 0 || musteriKat.compare(ozel) == 0) {
                dogruMu = true;
                break;
            }
            else if (musteriKat.compare(genel) != 0 || musteriKat.compare(ozel) != 0) {
                cout << "Musteri kategorisi icin gecersiz bir deger girisi yaptini lutfen genel veya ozel seklinde tekrar giris saglayiniz" << endl;
                getline(cin, musteriKat);
                musteriKat = harfBuyut(musteriKat);    //genel veya ozel girmesine gore harflerin hepsini buyutup kiyaslamada kolaylik saglayacak

            }
           
        }
  
        foutCari.open("CARI.txt", ios::app | ios::out);


            if (!foutCari)
                cerr << "Dosya acilamadi" << endl;
            else {
                foutCari << firmAd << c << firmNum << c << firmTel << c << firmSor
                    << c << musteriKat <<c<<adres<<endl;
              
            }
            foutCari.close();


    }
    void searchMusteri() {
        string firNo;
       
        cout <<"\n"<<"Lutfen aramak istediginiz musteri icin firma numarasini giriniz" << endl;
        getline(cin,firNo);
        finCari.open("CARI.txt");
        while (true) {
           
            getline(finCari, firmAd, ',');
            getline(finCari, firmNum, ',');
            getline(finCari, firmTel, ',');
            getline(finCari, firmSor, ',');
            getline(finCari, musteriKat, ',');
            getline(finCari, adres);

            if (finCari.eof()) {
                if (firNo != firmNum)
                    cout <<"\n"<<"Aradiginiz firma numarasiyla kayitli musteri bulunamadi" << endl;
                break;
            }
            if (firNo == firmNum) {
        
                cout<<"\n"<<"FIRMA ADI: "<< firmAd <<"\n"<<"FIRMA NUMARASI: "<< firmNum <<"\n"<<"FIRMA TELEFONU: "<< firmTel<<"\n"<<
                    "FIRMA SORUMLUSU: "<< firmSor<<"\n"<<
                    "MUSTERI KATEGORISI: " << musteriKat <<"\n"<<"FIRMA ADRESI: "<<adres<< endl;
                break;
            }
            
        }
        finCari.close();


    }

    
    
    void showMusteri(){//butun musterileri gostermek icin cagirilan func
        finCari.open("CARI.txt");
        while (true) {
            

            getline(finCari, firmAd, ',');
            getline(finCari, firmNum, ',');
            getline(finCari, firmTel, ',');
            getline(finCari, firmSor, ',');
            getline(finCari, musteriKat, ',');
            getline(finCari, adres);

            if (finCari.eof()){
                break;
            }

            cout << "\n" << "FIRMA ADI: " << firmAd << "\n" << "FIRMA NUMARASI : " << firmNum << "\n" << "FIRMA TELEFONU : " << firmTel << "\n" <<
                "FIRMA SORUMLUSU: " << firmSor << "\n" <<
                "MUSTERI KATEGORISI: " << musteriKat << "\n" << "FIRMA ADRESI: " <<adres<< endl;
        }
        finCari.close();


    }

    void duzeltMusteri() {
        
        char c = ',';
        bool musteriBulundu = false;
        string firmaNo;
        string genel = "GENEL";
        string ozel = "OZEL";
        string temp;
        finCari.open("CARI.txt");
        foutCopyCari.open("CARIKOPYA.txt", ios::out);
        cout<<"Degistirmek istediginiz firmanin numara bilgisini giriniz: ";
        getline(cin,firmaNo);

        while (!musteriBulundu) {
          
         
            getline(finCari, firmAd, ',');
            getline(finCari, firmNum, ',');
            getline(finCari, firmTel, ',');
            getline(finCari, firmSor, ',');
            getline(finCari, musteriKat, ',');
            getline(finCari, adres);

            if (finCari.eof()) {
                if (!musteriBulundu) {
                    cout << "\n" << "Guncellemek istediginiz firma ile ilgili kayit listede bulunamadi" << endl;
                }
                else {
                    cout << "\n" << "Ilgili firma guncellendi" << endl;
                }
              break;
            }
            if (firmaNo != firmNum) {
                foutCopyCari << firmAd << c << firmNum << c << firmTel << c << firmSor
                    << c << musteriKat << c << adres << endl;
            
            }
            else if (firmaNo == firmNum) {
                musteriBulundu = true;
                cout << "\n"<<"Guncellemek istediginiz musteri ile ilgili bilgiler asagidaki gibidir" << endl;
                cout << "\n" << "FIRMA ADI: " << firmAd << "\n" << "FIRMA NUMARASI : " << firmNum << "\n" << "FIRMA TELEFONU : " << firmTel << "\n" <<
                    "FIRMA SORUMLUSU: " << firmSor << "\n" <<
                    "MUSTERI KATEGORISI: " << musteriKat << "\n" << "FIRMA ADRESI: " << adres << endl;
                cout << "\n" << "Lutfen musteri bilgilerini asagida istene sekilde doldurunuz\n";
                cout << "FIRMA ADI: ";       getline(cin, firmAd);
                cout << "FIRMA NUMARASI: ";   getline(cin, firmNum);
                cout << "FIRMA TELEFONU: ";  getline(cin, firmTel);
                cout << "FIRMA SORUMLUSU "; getline(cin, firmSor);
                cout << "MUSTERI KATEGORISI(GENEL/OZEL): "; getline(cin, musteriKat);
                cout << "FIRMA ADRESI: ";  getline(cin, adres);
                temp= harfBuyut(musteriKat);//genel veya ozel girmesine gore harflerin hepsini buyutup kiyaslamada kolaylik saglayacak
                musteriKat.clear();
                musteriKat = temp;
                while (true) {
                    if (musteriKat.compare(genel) == 0 || musteriKat.compare(ozel) == 0) {
                        break;
                    }
                    else {
                        cout << "Musteri kategorisi icin gecersiz bir deger girisi yaptini lutfen genel veya ozel seklinde tekrar giris saglayiniz" << endl;
                        temp = harfBuyut(musteriKat);//genel veya ozel girmesine gore harflerin hepsini buyutup kiyaslamada kolaylik saglayacak
                        musteriKat.clear();
                        musteriKat = temp;
                    }
                   
                }

                foutCopyCari << firmAd << c << firmNum << c << firmTel << c << firmSor
                    << c << musteriKat << c << adres << endl;
            }
            
        }
        finCari.close();
        foutCopyCari.close();
        remove("CARI.txt");
        rename("CARIKOPYA.txt", "CARI.txt");
    }
    void deleteMusteri() {
        --sayac;
        string firmaNumarasi;
        char c = ',';
        bool musteriBulundu = false;
        cout<<"Silmek istediginiz firmanin ilgili firma numarasini giriniz: ";
        getline(cin,firmaNumarasi);
        finCari.open("CARI.txt");
        foutCopyCari.open("CARIKOPYA2.txt",ios::out);
        while (true) {
           
            getline(finCari, firmAd, ',');
            getline(finCari, firmNum, ',');
            getline(finCari, firmTel, ',');
            getline(finCari, firmSor, ',');
            getline(finCari, musteriKat, ',');
            getline(finCari, adres);

            if (finCari.eof()) {
                if (!musteriBulundu)
                    cout << "\n" << "Silmek istediginiz firma ile ilgili kayit listede bulunamadi" << endl;
                else
                    cout << "\n" << "Ilgili firma guncellendi" << endl;
                break;
            }

            if (firmaNumarasi==firmNum) {
                musteriBulundu = true;
                cout<<"\n"<<"Silmek istediginiz firma ile ilgili bilgiler asagidaki gibidir" << endl;
                cout << "\n" << "FIRMA ADI: " << firmAd << "\n" << "FIRMA NUMARASI : " << firmNum << "\n" << "FIRMA TELEFONU : " << firmTel << "\n" <<
                    "FIRMA SORUMLUSU: " << firmSor << "\n" <<
                    "MUSTERI KATEGORISI: " << musteriKat << "\n" << "FIRMA ADRESI: " << adres << endl;
             }
            else{
                foutCopyCari << firmAd << c << firmNum << c << firmTel << c << firmSor
                    << c << musteriKat << c << adres << endl;
            }
        }
        finCari.close();
        foutCopyCari.close();
        remove("CARI.txt");
        rename("CARIKOPYA2.txt", "CARI.txt");

    }



private:
    string firmNum;
    string firmAd;
    string firmTel;
    string firmSor;
    string musteriKat;
    string adres;
    ifstream finCari;
    ofstream foutCari;
    ofstream foutCopyCari;
    ofstream foutCopyCari2;
    int sayac;
    


};

 class Siparis {
     
    public:
        Siparis() {


        };
       
        
      
        void ekleSiparis() {//olusturma ve duzeltme burada
            foutSiparisList.open("SIPARISLIST.txt");
            int kontrol =0;
            char c = ',';
            string genel = "GENEL";
            string ozel = "OZEL";
            double geciciMiktarTwo=0;
            int artiSiparis=-1;
            double geciciFiyat=0;
            bool dogruMu = false;
            double fiyatD=0;
            string fiyatS;
            string kopyalanacakA,kopyalanacakB;
            cout << "\n"<<"SIPARIS TARIHI : ";             getline(cin, siparisTarih);
            cout << "SIPARIS ALICISI:  ";              getline(cin, alici);
            cout << "FIRMA NO: ";                    getline(cin, firNo);
            cout << "URUN KODU: ";                    getline(cin, urunKodu);
            cout << "KAC ADET SIPARIS VERILECEK: ";    getline(cin, urunAdet);//kullanicini sadece int girmeme ihtimaline karsi
        

            foutSiparis.open("SIPARIS.txt", ios::app | ios::out);
 
     
            while (true) {

                if (genel.compare(searchForOther(firNo))==0  ||     ozel.compare(searchForOther(firNo))==0) {
                   // dogruMu = true; string  urununKodu,string musteriTipi,int* kontrol
                    if (searchForOther(firNo) ==genel) {
                        searchForSiparis(urunKodu, genel, &kontrol);
                        if (kontrol== 1) {
                            kopyalanacakA = searchForSiparis(urunKodu, genel, &kontrol);
                            fiyatD = stod(kopyalanacakA);                      
                            kopyalanacakA.clear(); 
                            geciciMiktarTwo = stod(urunAdet);         
                            geciciFiyat = fiyatD * geciciMiktarTwo;
                            siparisFiyat=to_string(geciciFiyat);
                            
                        }
                        else {
                            cout << "Eklemek istediginiz siparise ait kayitli urun sistemde bulunamadi,lutfen tekrar giris saglayiniz" << endl;
                            cout << "SIPARIS TARIHI: ";             getline(cin, siparisTarih);
                            cout << "SIPARIS ALICISI:  ";              getline(cin, alici);
                            cout << "FIRMA NO: ";                    getline(cin, firNo);
                            cout << "URUN KODU: ";                    getline(cin, urunKodu);
                            cout << "KAC ADET SIPARIS VERILECEK: ";    getline(cin, urunAdet);//kullanicini sadece int girmeme ihtimaline karsi
                            searchForSiparis(urunKodu, genel, &kontrol);

                        }
                  
                        
                    }
                    else if (searchForOther(firNo) == ozel) {
                        searchForSiparis(urunKodu, ozel, &kontrol);
                        if (kontrol == 1) {
                            kopyalanacakA = searchForSiparis(urunKodu, ozel, &kontrol);
                            fiyatD = stod(kopyalanacakA);

                            kopyalanacakA.clear();
                            geciciMiktarTwo = stod(urunAdet);
                            geciciFiyat = fiyatD * geciciMiktarTwo;
                            siparisFiyat = to_string(geciciFiyat);
                
                        }
                        else {
                            cout << "Eklemek istediginiz siparise ait kayitli urun sistemde bulunamadi,lutfen tekrar giris saglayiniz" << endl;
                            cout << "SIPARIS TARIHI: ";             getline(cin, siparisTarih);
                            //   cout << "SIPARIS FIYATI: ";              getline(cin,siparisFiyat);
                            cout << "SIPARIS ALICISI:  ";              getline(cin, alici);
                            cout << "FIRMA NO: ";                    getline(cin, firNo);
                            cout << "URUN KODU: ";                    getline(cin, urunKodu);
                            cout << "KAC ADET SIPARIS VERILECEK: ";    getline(cin, urunAdet);//kullanicini sadece int girmeme ihtimaline karsi
                            searchForSiparis(urunKodu, ozel, &kontrol);

                        }
                    }
                    break;
                }

                else if(genel !=searchForOther(firNo) || ozel !=searchForOther(firNo)) {
                    if(kontrol!=1){
                    cout << "Eklemek istediginiz siparise kayitli musteri bulunamadi lutfen tekrar gecerli bir firma numarasi girin" << endl;
                    getline(cin, firNo);
                    }
                }
                
               
              
              
                
            }


            if (!foutSiparis)
                cerr << "Dosya acilamadi" << endl;
            else {
             
   
                foutSiparisList << urunKodu << c<<urunAdet << endl;
                foutSiparis << siparisTarih << c <<siparisFiyat  << c << alici << c << firNo
                    << c << urunKodu <<c<<urunAdet << endl;
               



                    
            }
            foutSiparis.close();
            foutSiparisList.close();
        
        }
        void searchSiparis() {
            bool bulunduMu = false;
            string kimAldi;
            string code;
            string adet;
            finSiparis.open("SIPARIS.txt");
            cout << "Lutfen arama istediginiz siparisin alicisini giriniz: " << endl;
            getline(cin, kimAldi);
            cout << "Lutfen siparis verilen urunun kodunu giriniz: " << endl;
            getline(cin,code);
            cout << "Lutfen kac adet siparis verdiginizi giriniz " << endl;
            getline(cin,adet);



            while (finSiparis) {
                getline(finSiparis, siparisTarih, ',');
                getline(finSiparis, siparisFiyat, ',');
                getline(finSiparis, alici, ',');
                getline(finSiparis, firNo, ',');
                getline(finSiparis, urunKodu, ',');
                getline(finSiparis, urunAdet);
                if (finSiparis.eof())
                    break;
              
               

                if (kimAldi==alici ) {//string olarak tanimlandigi icin == veya a.compare(b)==x de kullanilabilir
                    bulunduMu = true;
                    cout << "Siparis bulundu" << endl;
                    cout << "SIPARIS TARIHI: " << siparisTarih << "\n" << "SIPARIS FIYATI: " << siparisFiyat << "\n" << "SIPARIS ALICISI: "<< alici <<
                        "\n" <<"FIRMA NO: " << firNo
                        << "\n" << "URUN KODU: " << urunKodu << "\n" << "URUN ADEDI: " << urunAdet << endl;
                }
               

             }
            if (!bulunduMu) {
                cout << "Siparis bulunamadi" << endl;
            }
             finSiparis.close();

         }
       
        void deleteSiparis() {
            int eksiSiparis=-1;//silinen sparis sayisi kadar urun stoguna eklenme yapilacak;
            string alan;
            string urunCode;
            string copyCode;
           
            string firmaNo;
            int geciciMiktar=0;
            char c = ',';
            finSiparis.open("SIPARIS.txt");
            foutSiparis.open("COPYSIPARIS.txt");
            finSiparisList.open("SIPARISLIST.txt");
            foutSiparisList.open("SIPARISLISTTMP.txt");
            cout<<"Silmek istediginiz siparisin kodunu giriniz"<<endl;
            getline(cin,urunCode);
            cout<<"Silmek istediginiz siparisin alici ismini giriniz"<<endl;
            getline(cin,alan);
            cout << "Silmek istediginiz siparisin firma numarasini giriniz" << endl;
            getline(cin, firmaNo);

            while(finSiparis){
                getline(finSiparis, siparisTarih, ',');
                getline(finSiparis, siparisFiyat, ',');
                getline(finSiparis, alici, ',');
                getline(finSiparis, firNo, ',');
                getline(finSiparis, urunKodu, ',');
                getline(finSiparis, urunAdet);
                if (finSiparis.eof())
                    break;
               
                if(urunCode==urunKodu &&  alan==alici ){
                    copyCode = urunKodu;
                    cout<<"Silmek istediginiz siparis ile ilgili bilgiler asagidaki gibidir"<<endl;
                    cout << "SIPARIS TARIHI: " << siparisTarih << "\n" << "SIPARIS FIYATI: " << siparisFiyat << "\n" << "SIPARIS ALICISI: " << alici <<
                        "\n" << "FIRMA NO: " << firNo
                        << "\n" << "URUN KODU" << urunKodu << "\n" << "URUN ADEDI: " << urunAdet << endl;
                }
                else{
                    foutSiparis << siparisTarih << c << siparisFiyat << c << alici << c << firNo
                        << c << urunKodu << c << urunAdet << endl; 

                }

            }
            while (finSiparisList) {
                if (copyCode == urunKodu) {
                    ;//do nothing
                }
                
                if(finSiparisList.eof()){
                	break;
				}
                else {
                    foutSiparisList << urunKodu << c << urunAdet << endl;
                }
            }
            finSiparis.close();
            foutSiparis.close();
            foutSiparisList.close();
            remove("SIPARIS.txt");
            rename("COPYSIPARIS.txt","SIPARIS.txt");
            remove("SIPARIS_LIST.txt");
            rename("SIPARISLIST.tmp", "SIPARISLIST.txt");


        }
        void duzeltSiparis(){
            string alan;
            string urunCode;
        
            int kontrol = 0;
            char c = ',';
            string genel = "GENEL";
            string ozel = "OZEL";
           double geciciMiktarTwo = 0;
            int artiSiparis = -1;
            double geciciFiyat = 0;
            bool dogruMu = false;
            double fiyatD = 0;
            string fiyatS;
            string kopyalanacakA, kopyalanacakB;

           
            


          
            finSiparis.open("SIPARIS.txt");
            foutSiparis.open("COPYSIPARIS.txt",ios::out);
            cout<<"Degistirmek istediginiz siparisin kodunu giriniz"<<endl;
            getline(cin,urunCode);
            cout<<"Degistirmek istediginiz siparisin alici ismini giriniz"<<endl;
            getline(cin,alan);

            while(true){
                getline(finSiparis, siparisTarih, ',');
                getline(finSiparis, siparisFiyat, ',');
                getline(finSiparis, alici, ',');
                getline(finSiparis, firNo, ',');
                getline(finSiparis, urunKodu, ',');
                getline(finSiparis, urunAdet);
        
                if (finSiparis.eof())
                    break;
                if(urunCode==urunKodu &&  alan==alici){
                    cout<<"Degistirmek istediginiz siparisin onceki bilgileri sekildeki gibidir"<<endl;
                    cout << "SIPARIS TARIHI: " << siparisTarih << "\n" << "SIPARIS FIYATI: " << siparisFiyat << "\n" << "SIPARIS ALICISI: " << alici <<
                        "\n" << "FIRMA NO: " << firNo
                        << "\n" << "URUN KODU" << urunKodu << "\n" << "URUN ADEDI: " << urunAdet << endl;
                    cout << "Lutfen yeni bilgileri giriniz" << endl;
                    cout << "SIPARIS TARIHI: ";             getline(cin, siparisTarih);
                    cout << "SIPARIS ALICISI:  ";              getline(cin, alici);
                    cout << "FIRMA NO: ";                    getline(cin, firNo);
                    cout << "URUN KODU: ";                    getline(cin, urunKodu);
                    cout << "KAC ADET SIPARIS VERILECEK: ";    getline(cin, urunAdet);
                    if (genel.compare(searchForOther(firNo)) == 0 || ozel.compare(searchForOther(firNo)) == 0) {
                        if (searchForOther(firNo) == genel) {
                            searchForSiparis(urunKodu, genel, &kontrol);
                            if (kontrol == 1) {
                                kopyalanacakA = searchForSiparis(urunKodu, genel, &kontrol);
                                fiyatD = stod(kopyalanacakA);
                                kopyalanacakA.clear();
                                geciciMiktarTwo = stod(urunAdet);
                                geciciFiyat = fiyatD * geciciMiktarTwo;
                                siparisFiyat = to_string(geciciFiyat);

                            }
                            else {
                                cout << "Degistirmek istediginiz siparise ait kayitli urun sistemde bulunamadi,lutfen tekrar giris saglayiniz" << endl;
                                cout << "SIPARIS TARIHI: ";             getline(cin, siparisTarih);
                                //   cout << "SIPARIS FIYATI: ";              getline(cin,siparisFiyat);
                                cout << "SIPARIS ALICISI:  ";              getline(cin, alici);
                                cout << "FIRMA NO: ";                    getline(cin, firNo);
                                cout << "URUN KODU: ";                    getline(cin, urunKodu);
                                cout << "KAC ADET SIPARIS VERILECEK: ";    getline(cin, urunAdet);//kullanicini sadece int girmeme ihtimaline karsi
                                searchForSiparis(urunKodu, genel, &kontrol);

                            }


                        }
                        else if (searchForOther(firNo) == ozel) {
                            searchForSiparis(urunKodu, ozel, &kontrol);
                            if (kontrol == 1) {
                                kopyalanacakA = searchForSiparis(urunKodu, ozel, &kontrol);
                                fiyatD = stod(kopyalanacakA);

                                kopyalanacakA.clear();
                  
                                geciciMiktarTwo = stod(urunAdet);

                                geciciFiyat = fiyatD * geciciMiktarTwo;
                                siparisFiyat = to_string(geciciFiyat);

                            }
                            else {
                                cout << "Degistirmek istediginiz siparise ait kayitli urun sistemde bulunamadi,lutfen tekrar giris saglayiniz" << endl;
                                cout << "SIPARIS TARIHI: ";             getline(cin, siparisTarih);
                                //   cout << "SIPARIS FIYATI: ";              getline(cin,siparisFiyat);
                                cout << "SIPARIS ALICISI:  ";              getline(cin, alici);
                                cout << "FIRMA NO: ";                    getline(cin, firNo);
                                cout << "URUN KODU: ";                    getline(cin, urunKodu);
                                cout << "KAC ADET SIPARIS VERILECEK: ";    getline(cin, urunAdet);//kullanicini sadece int girmeme ihtimaline karsi
                                searchForSiparis(urunKodu, ozel, &kontrol);

                            }
                        }
                        
                    }
                    foutSiparis << siparisTarih << c << siparisFiyat << c << alici << c << firNo
                        << c << urunKodu << c << urunAdet << endl;//ilgili kayit haici diget seyleri dosyaya yaziyoruz
                }
                else{
                 

                    foutSiparis << siparisTarih << c << siparisFiyat << c << alici << c << firNo
                        << c << urunKodu << c << urunAdet << endl;//ilgili kayit haici diget seyleri dosyaya yaziyoruz
                }

            }
            finSiparis.close();
            foutSiparis.close();
            remove("SIPARIS.txt");
            rename("COPYSIPARIS.txt","SIPARIS.txt");


        }
        void raporSiparis(){//raporlama burada yapilacak siparisList listesinin icine gerekli bilgiler yazilacak
            finSiparis.open("SIPARIS.txt");
            cout << "Kayitli siparislerin raporu asagidaki gibidir" << endl;
            while (true) {
                getline(finSiparis, siparisTarih, ',');
                getline(finSiparis, siparisFiyat, ',');
                getline(finSiparis, alici, ',');
                getline(finSiparis, firNo, ',');
                getline(finSiparis, urunKodu, ',');
                getline(finSiparis, urunAdet);
                if (finSiparis.eof())
                    break;
                cout << "\n"<<"SIPARIS TARIHI: " << siparisTarih << "\n" << "SIPARIS FIYATI: " << siparisFiyat << "\n" << "SIPARIS ALICISI: " << alici <<
                    "\n" << "FIRMA NO: " << firNo
                    << "\n" << "URUN KODU" << urunKodu << "\n" << "URUN ADEDI: " << urunAdet << endl;
            }
            finSiparis.close();

        }

    private:
        string siparisTarih;
        string siparisFiyat;
        // SipariÅŸ listesi dosyasÄ±(Ã¶rneÄŸin xyz)//siparis listesi icindeki dosyayay bu class icinde erisecegiz
        string alici;
        string firNo;
        ifstream finSiparis;
        ofstream foutSiparis;
        ofstream foutSiparisList;
        ifstream finSiparisList;
        string urunKodu;//bu ve urunAdeti siparis raporlanmasi icin siparis_rapor.txt icinde tutulacak
        string geciciUrunAdet;//daha sonra stok sayisindan bu adetleri dusebilmek icin ayriyeten b
        string urunAdet;

    };





int main()
{
    Urun* urunler = new Urun();
    Cari* musteriler = new Cari();
    Siparis* siparisler = new Siparis();
    bool devamMi=false;
    bool ustMenu = false;
    int secim;
    //urunler->showUrun();
    while (!devamMi) {

        cout << "\n"<<"1)URUN ISLEMLERI" << endl;
        cout << "2)MUSTERI ISEMLERI" << endl;
        cout << "3)SIPARIS ISLEMLERI" << endl;
        cout << "4)CIKIS" << endl;

        cout << "Lutfen bir secim yapiniz: ";
        cin >> secim;
        cin.clear();
        cin.ignore();
       
       
        ustMenu = false;
       
          
        if (!ustMenu) {
            if (secim == 1) {
                cout << "\n" << "1)URUN EKLEME" << endl;
                cout << "2)URUN LISTELEME" << endl;
                cout << "3)URUN ARAMA" << endl;
                cout << "4)URUN DUZELTME" << endl;
                cout << "5)CIKIS(Bir Ust Menuye)" << endl;
                cout << "Lutfen bir secim yapiniz: ";
                cin >> secim;
                cin.clear();
                cin.ignore();
                if (secim == 1) {
                    urunler->ekleUrun();


                }
                else if (secim == 2) {
                    urunler->showUrun();
                }
                else if (secim == 3) {
                    urunler->searchUrun();
                }
                else if (secim == 4) {
                    urunler->duzeltUrun();
                }
                else if (secim == 5) {
                    ustMenu = true;
                }
                else {
                    cout << "Gecersiz secim yaptiniz devam etmek icin herhangi bir sayi tuslayiniz" << endl;
                    cin >> secim;
                    cin.clear();
                    cin.ignore();
                  
                    //break;
                }
            }

            else if (secim == 2) {
                cout << "\n" << "1)MUSTERI EKLEME" << endl;
                cout << "2)MUSTERI LISTELEME" << endl;
                cout << "3)MUSTERI ARAMA" << endl;
                cout << "4)MUSTERI DUZELTME" << endl;
                cout << "5)CIKIS(Bir Ust Menuye)" << endl;
                cout << "Lutfen bir secim yapiniz: ";
                cin >> secim;
                cin.clear();
                cin.ignore();
                if (secim == 1) {
                    musteriler->ekleMusteri();

                }
                else if (secim == 2) {
                    musteriler->showMusteri();
                }
                else if (secim == 3) {
                    musteriler->searchMusteri();
                }
                else if (secim == 4) {
                    musteriler->duzeltMusteri();
                }
                else if (secim == 5) {
                    ustMenu = true;
                }
                else {
                    cout << "Gecersiz secim yaptiniz devam etmek icin herhangi bir sayi tuslayiniz" << endl;
                    cin >> secim;
                    cin.clear();
                    cin.ignore();
                }
            }
            else if (secim == 3) {
                cout << "\n" << "1)SIPARIS EKLEME" << endl;
                cout << "2)SIPARIS LISTELEME" << endl;
                cout << "3)SIPARIS ARAMA" << endl;
                cout << "4)SIPARIS DUZELTME" << endl;
                cout << "5)CIKIS(Bir Ust Menuye)" << endl;
                cout << "Lutfen bir secim yapiniz: ";
                cin >> secim;
                cin.clear();
                cin.ignore();
                if (secim == 1) {
                    siparisler->ekleSiparis();
                }
                else if (secim == 2) {
                    siparisler->raporSiparis();
                }
                else if (secim == 3) {
                    siparisler->searchSiparis();
                }
                else if (secim == 4) {
                    siparisler->duzeltSiparis();
                }
                else if (secim == 5) {
                    ustMenu = true;
                }
                else {
                    cout << "Gecersiz secim yaptiniz devam etmek icin herhangi bir sayi tuslayiniz" << endl;
                    cin >> secim;
                    cin.clear();
                    cin.ignore();
                }
            }
            else if (secim == 4) {
                cout << "Program sona erdi" << endl;
                devamMi = true;
                break;
            }
            else {
                cout << "Gecersiz secim yaptiniz devam etmek icin herhangi bir sayi tuslayiniz" << endl;
                cin >> secim;
                ustMenu = true;




                //ustMenu = true;
            }

        }

    }
   }
    
   

