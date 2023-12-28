#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
#include <random>
#include <time.h>
#include <algorithm>

using namespace std;

void oyuncu_olusturma(int a, string takim_ismi);
void oyuncu_guncelle(int sayac);

string telno = "05";
string tcno, mevki, dosyamiz, lisans;
int gercek_lisans;

class butun_bilgiler {		/*Oyuncular ve takimlar burdaki verilerin arasindan secilen rastgele degerler ile olusuyor*/
public:
	vector <string> oyuncu_isim = {
		"Lionel", "Cristiano", "Neymar", "Kylian", "Mohamed", "Robert", "Kevin", "Harry", "Erling","Frenkie",
		"Luka", "Karim", "Sergio", "Toni", "NGolo", "Virgil", "Joshua", "Manuel", "Paul", "Raheem","Aymeric",
		"Alisson", "Ederson", "Gianluigi", "Romelu", "Jadon", "Mason", "Thiago", "Casemiro", "Vinicius", 
		"Luis", "Antoine", "Marco", "Serge", "Riyad", "Phil", "irfan", "Ruben", "Bernardo", "Denis", "Ella",
		"Jordan", "Sadio", "Andrew", "Trent", "Marcus", "Bruno", "Jack", "Wilfred", "Ciro", "Lorenzo","ivan",
		"Thibaut", "Eden", "Volkan", "Youri", "Hakim", "Georginio", "Miralem", "Aleksandar", "Dusan",  "iker",
		"Joao", "Ruben", "Diogo", "Pedro","Burak", "Ruubean","Mats", "Eduardo", "Gabriel", "Fabio", "Daniel",
		"Paulinho","Emre", "Can", "Mert", "Ahmet", "Ege", "Levent", "Michael","Lucas","Noah", "Olivia", "Baris"
		"Mia", "Arda", "Sophie", "Sebastian","Yusuf", "Mehmet", "Ellif", "Zara", "Victor", "Alex", "isaac","Luna", 
		"Mateo", "Leo", "Bengamin", "Oliver", "Aria", "Ethan", "Zoe", "Mila", "Liam", "Noah", "Aiden", "Gavi",
		"Kerem", "Ferdi", "Gedson", "Cengiz", "Davinson", "Tanguy", "Dominic", "Fred", "Michy", "Rodrigo", "Atiba",
		 "Mia", "Ugurcan","Rodri", "Enzo", "Phil", "Cristopher", "Martin", "Gabrieal", "Thierry", "Steven", "Sergios",
		 "Gude", "Aurelian", "David", "Pedri", "Federico", "Joaox", "Ronald", "Raphinha", "Charles", "Alfredo",
		 "Xavi", "Raul", "Jordi", "Antonio", "Tolga", "Ryan", "Batista", "Vincent", "Emmanuel", "Bakhtiyar", 
		"Serhat", "Tolgacan", "Memduh", "Ozgur", "Kemal", "Umitcan", "Umit", "Murta", "Murat", "Semsi", "Bakasaste"
	};
	vector <string> oyuncu_soyisim = {
		"Yilmaz", "Demir", "Kaya", "Celik", "Lukaku", "Sancho", "Mount", "Alcantara", "Sonmez", "Kilic", 
		"Arslan","Ekinci", "Yildirim", "Sahin", "Ozturk", "Koc", "Aydin", "Kurt","Erdogan", "Cetin","Kara",
		"Kocak","Neto", "Dias", "Ozdemir","Ozkan", "Ozsoy","Dogan", "Guler", "Polat", "Yavuz", "Karahan", 
		"Turan", "Tas", "Karadeniz", "Kurtulus", "Cinar", "Tasdemir", "Ozgun", "Duman", "Kaplan", "Guzel",
		"Serin", "Buyuk", "Uzun", "Akman", "Aktas", "Sancak", "Erbay", "Kayaalp", "Kizil", "Bilgic",
		"Messi", "Ronaldo", "Mbappe", "Salah", "Lewandowski", "Bruyne", "Kane", "Haaland", "Sterling", 
		"Modric", "Benzema", "Ramos", "Kroos", "Kante", "Diyk", "Kimmich", "Neuer", "Pogba","Mitrovic",
		"Becker", "Moraes", "Donnarumma", "Casemiro", "Junior", "Jong","Immobile", "Insigne","Ozgur",
		"Suarez", "Griezmann", "Reus", "Gnabry", "Alaba", "Mahrez", "Foden", "Silva", "Laporte", "Aslan",
		"Henderson", "Mane", "Robertson", "Arnold", "Rashford", "Guimaraes", "Grealish", "Ndidi","Tadic",
		"Szymanski", "Rossi", "Courtois", "Hazard", "Tielemans", "Ziyech", "Wiynaldum", "Pyanic", "Sari",
		"Vlahovic", "Petkovic", "Cancelo", "Neves", "Gota", "Cakir", "Akturkoglu", "Kadioglu", "Huttinchson",
		"Fernandes", "Under", "Sanchez", "Ndombele", "Livakovic", "Rodrigoes", "Batshuayi", "Becao",
		"Casillas", "Cigerci", "Kent", "Mendy", "Aboubakar", "Dennis", "Zaynutdinov", "Miguel", "Alper",
		 "Kilicdaroglu",
	};
	vector <string> oyuncu_mevki = {
		"kaleci", "stoper", "stoper", "sag bek", "sol bek", "iki yonlu orta saha", "defansif orta saha", 
		"ofansif orta saha", "sag kanat", "sol kanat", "forvet",
		"yedek kaleci", "yedek stoper", "yedek stoper", "yedek sag bek", "yedek sol bek", "yedek iki yonlu orta saha",
		"yedek defansif orta saha", "yedek ofansif orta saha", "yedek sag kanat", "yedek sol kanat",
		"yedek forvet"
	};
	vector <string> superLigTakimlari = {
		"Besiktas", "Fenerbahce", "Galatasaray", "ManchesterCity", "Basaksehir", "BayernMunih",
		"Goztepe", "RealMadrid", "Barcelona", "Sevilla", "Dortmund", "Kasimpasa", "Liverpool", "Genclerbirligi",
		"Chelsea", "ParisSaintGermain", "Leverkusen", "Tottenham" 
	};
	vector <string> sehirler = {
		"Adana", "Adiyaman", "Afyon", "Agri", "Amasya", "Ankara", "Antalya", "Artvin", "Aydin", "Balikesir", "Bilecik",
		"Bingol", "Bitlis", "Bolu", "Burdur", "Bursa", "Canakkale", "Cankiri", "Corum", "Denizli", "Diyarbakir", "Edirne",
		"Elazig", "Erzincan", "Erzurum", "Eskisehir", "Gaziantep", "Giresun", "Gumushane", "Hakkari", "Hatay", "Isparta",
		"Mersin", "Istanbul", "Izmir", "Kars", "Kastamonu", "Kayseri", "Kirklareli", "Kirsehir", "Kocaeli", "Konya", "Kutahya",
		"Malatya", "Manisa", "Kahramanmaras", "Mardin", "Mugla", "Mus", "Nevsehir", "Nigde", "Ordu", "Rize", "Sakarya", "Samsun",
		"Siirt", "Sinop", "Sivas", "Tekirdag", "Tokat", "Trabzon", "Tunceli", "Sanliurfa", "Usak", "Van", "Yozgat", "Zonguldak",
		"Aksaray", "Bayburt", "Karaman", "Kirikale", "Batman" , "Sirnak", "Bartin", "Ardahan", "Igdir", "Yalova", "Karabuk", 
		"Kilis", "Osmaniye", "Duzce"
	};
};
butun_bilgiler* oyuncu = new butun_bilgiler(); /*Bu verilere erismek icin olusturdugum nesne*/

class Takim { /*Takim bilgilerini tutan class icerisinde farkli classlar da var*/
public:
	string Isim;
	string Sehir;
	string Yonetici;
	int puan = 0;
	int atilan_gol = 0;
	int yenilen_gol = 0;
	int averaj = 0;
	int Silindi_mi = 1; /*silidi mi, tabloda mi, mac_sayaci gibi kontrol mekanizmalari sayesinde isime yarayacak istatistkleri tutuyorum*/
	int tabloda_mi = 0;
	int mac_sayaci = 0;
	vector<int> gol_atan;

	class Maclari { /*Bu takimlarin maclarinin bilgilerini tutan class*/
	public:
		string maci;
		string maci_detayli;
		vector<string> ev_golleri;
		vector<string> dep_golleri;
	};

	Maclari maclari[40]; /*maclar nesnesi her takimin 30-40 arasi mac yaptigi varsayildigi icin 40 nesne olusturuldu*/

	class Oyuncu {		/*takim class'inin icinde bulunan bir oyuncu class'i. bu sayede erisim kolay ve dogru oluyor*/
	public:
		string Ad;
		string Soyad;
		string Tc;
		string Telno;
		string Lisans;
		string Dogum_tarih;
		string Dogum_yer;
		string Mevki;
		bool oyunda_mi = 0;	/*oyuncular icin kontrol mekanizmasi*/
		int gol_sayisi = 0;
		bool gol_kralliginde_mi = 0;

		class Mevkiler {		/*farkli mevkiler farkli siklikta gol attigi icin mevkilere gore belirli oranda oranda gol atmalarini saglayan class*/
		public:

			int Silindi_mi = 1;
			int oyuncu_sirasi;

			double gol_atma_olasiligi = 0;
			float kaleci = 0.001;
			float yedek_kaleci = 0.0005;
			float savunma = 0.1;
			float yedek_savunma = 0.05;
			float orta_saha = 0.2;
			float yedek_orta_saha = 0.1;
			float kanat = 0.3;
			float yedek_kanat = 0.15;
			float forvet = 0.5;
			float yedek_forvet = 0.25;

			bool kaleci_mi = 0;
			bool yedek_kaleci_mi = 0;
			bool savunma_mi = 0;
			bool yedek_savunma_mi = 0;
			bool orta_saha_mi = 0;
			bool yedek_orta_saha_mi = 0;
			bool kanat_mi = 0;
			bool yedek_kanat_mi = 0;
			bool forvet_mi = 0;
			bool yedek_forvet_mi = 0;
		};
		int mevkisi;

		Mevkiler mevkiler;
	};
	
	Oyuncu oyuncular[25];
};
class Takim takim[20];

void mevkiler_gol() {		/*mevkiler class'inin icindeki gol vectorlerini dolduran fonksiyon*/
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 25; j++) {
			if (takim[i].Silindi_mi != 1 && takim[i].oyuncular[j].mevkiler.Silindi_mi != 1) {
				for (int k = 0; k < (1000 * takim[i].oyuncular[j].mevkiler.gol_atma_olasiligi); k++) {
					takim[i].gol_atan.push_back({ j });
				}
			}
			random_shuffle(takim[i].gol_atan.begin(), takim[i].gol_atan.end());
		}
	}
}

void gol_olasiligi_belirleyici(int takimi, int oyuncusu) {		/*oyuncularin mevkilerine gore gol olasiligi atayan fonksiyon*/
	if (takim[takimi].oyuncular[oyuncusu].mevkiler.kaleci_mi == 1) {
		takim[takimi].oyuncular[oyuncusu].mevkiler.gol_atma_olasiligi = 0.001;
	}
	if (takim[takimi].oyuncular[oyuncusu].mevkiler.savunma_mi == 1) {
		takim[takimi].oyuncular[oyuncusu].mevkiler.gol_atma_olasiligi = 0.1;
	}
	if (takim[takimi].oyuncular[oyuncusu].mevkiler.orta_saha_mi == 1) {
		takim[takimi].oyuncular[oyuncusu].mevkiler.gol_atma_olasiligi = 0.2;
	}
	if (takim[takimi].oyuncular[oyuncusu].mevkiler.kanat_mi == 1) {
		takim[takimi].oyuncular[oyuncusu].mevkiler.gol_atma_olasiligi = 0.3;
	}
	if (takim[takimi].oyuncular[oyuncusu].mevkiler.forvet_mi == 1) {
		takim[takimi].oyuncular[oyuncusu].mevkiler.gol_atma_olasiligi = 0.5;
	}

	if (takim[takimi].oyuncular[oyuncusu].mevkiler.yedek_kaleci_mi == 1) {
		takim[takimi].oyuncular[oyuncusu].mevkiler.gol_atma_olasiligi = 0.001;
	}
	if (takim[takimi].oyuncular[oyuncusu].mevkiler.yedek_savunma_mi == 1) {
		takim[takimi].oyuncular[oyuncusu].mevkiler.gol_atma_olasiligi = 0.1;
	}
	if (takim[takimi].oyuncular[oyuncusu].mevkiler.yedek_orta_saha_mi == 1) {
		takim[takimi].oyuncular[oyuncusu].mevkiler.gol_atma_olasiligi = 0.2;
	}
	if (takim[takimi].oyuncular[oyuncusu].mevkiler.yedek_kanat_mi == 1) {
		takim[takimi].oyuncular[oyuncusu].mevkiler.gol_atma_olasiligi = 0.3;
	}
	if (takim[takimi].oyuncular[oyuncusu].mevkiler.yedek_forvet_mi == 1) {
		takim[takimi].oyuncular[oyuncusu].mevkiler.gol_atma_olasiligi = 0.5;
	}
}

class Skor {	/*skorla ilgili bilgilerin oldugu class*/
private:
	struct Gol_olasiligi {
		float gol_0 = 0.10;
		float gol_1 = 0.22;
		float gol_2 = 0.26;
		float gol_3 = 0.22;
		float gol_4 = 0.16;
		float gol_5 = 0.12;
		float gol_5_15 = 0.001;
		float gol_15_25 = 0.0001;
		float gol_sayisi = 10000;
	};
	Gol_olasiligi gol_olasiligi;
public:
	vector<int> goller;
	Skor() {		/*bu belirli olasiliklara gore dizi dolduran fonksiyon*/
		for (int i = 0; i < (gol_olasiligi.gol_sayisi * gol_olasiligi.gol_0); i++) {
			goller.push_back({ 0 });
		}
		for (int i = 0; i < (gol_olasiligi.gol_sayisi * gol_olasiligi.gol_1); i++) {
			goller.push_back({ 1 });
		}
		random_shuffle(goller.begin(), goller.end());
		for (int i = 0; i < (gol_olasiligi.gol_sayisi * gol_olasiligi.gol_2); i++) {
			goller.push_back({ 2 });
		}
		for (int i = 0; i < (gol_olasiligi.gol_sayisi * gol_olasiligi.gol_3); i++) {
			goller.push_back({ 3 });
		}
		random_shuffle(goller.begin(), goller.end());
		for (int i = 0; i < (gol_olasiligi.gol_sayisi * gol_olasiligi.gol_4); i++) {
			goller.push_back({ 4 });
		}
		for (int i = 0; i < (gol_olasiligi.gol_sayisi * gol_olasiligi.gol_5); i++) {
			goller.push_back({ 5 });
		}
		for (int i = 0; i < (gol_olasiligi.gol_sayisi * gol_olasiligi.gol_5_15); i++) {
			goller.push_back({ (rand() % 11 + 5) });
		}
		for (int i = 0; i < (gol_olasiligi.gol_sayisi * gol_olasiligi.gol_15_25); i++) {
			goller.push_back({ (rand() % 11 + 15) });
		}
		random_shuffle(goller.begin(), goller.end());
	}
};

Skor skor;

class Mac {		/*mac bilgilerinini tutuldugu class*/
public:
	vector<string> karsilasmalar;
	vector<int> ev_sahibi_gol;
	vector<int> deplasman_gol;

	vector<int> ev_sahibi_asist;
	vector<int> deplasman_asist;

	vector<string> ev_sahibi_gol_atan;
	vector<string> deplasman_gol_atan;

	vector<string> ev_sahibi_asist_atan;
	vector<string> deplasman_asist_atan;

	vector<string> ev_sahibi_degisiklik;
	vector<string> deplasman_degisiklik;
};

Mac mac;

void takim_ekleme() {		/*takim eklememizi saglayan fonksiyon*/
	int girilen_takim;
	string takim_isim, takim_yonetici_ismi, takim_yonetici_soyismi, takim_sehri;
	cout << "eklemek istediginiz takimin ismini giriniz(!lutfen bosluk kullanmayiniz!):";
	cin >> takim_isim;
	cout << "takimin yoneticisinin ismini giriniz:";
	cin >> takim_yonetici_ismi;
	cout << "takimin yoneticisinin soyismini giriniz:";
	cin >> takim_yonetici_soyismi;
	cout << "takimin sehrini giriniz:";
	cin >> takim_sehri;
	for (int i = 0; i < 20; i++) {		/*takim nesnesini kontrol edip silinmis olan ilk takimin yerine yeni olusturulan takimimn bilgilerini dolduruyor*/
		if (takim[i].Silindi_mi == 1) {
			girilen_takim = i;
			takim[i].Isim = takim_isim;
			takim[i].Yonetici = takim_yonetici_ismi;
			takim[i].Sehir = takim_sehri;
			takim[i].Silindi_mi = 0; 
			i = 30;
		}
	}
	system(("mkdir C:\\Users\\Vıctus\\Desktop\\proje\\Projeodevi\\takimlar\\" + takim_isim).c_str());

	dosyamiz = "C:\\Users\\Vıctus\\Desktop\\proje\\Projeodevi\\takimlar\\" + takim_isim + "\\" + takim_isim + ".txt";
	ofstream takim_olustur;;
	takim_olustur.open(dosyamiz, ios::app);

	takim_olustur << takim_isim << endl
		<< takim_yonetici_ismi<<" "<< takim_yonetici_soyismi << endl
		<< takim_sehri << endl;
	takim_olustur.close();
	cout << "takimin olusturuldu oyunculari yaratiliyor...";

	oyuncu_olusturma(girilen_takim, takim_isim);
}

void takim_silme() {		/*takim silmemizi saglayan fonksiyon*/
	int sec;
	string takim_ismi;
	cin >> sec;
	takim_ismi = takim[sec - 1].Isim;
	system(("rmdir /s /q C:\\Users\\Vıctus\\Desktop\\proje\\Projeodevi\\takimlar\\" + takim_ismi).c_str());
	takim[sec-1].Isim = takim_ismi + "(silindi)";
	takim[sec - 1].Silindi_mi = 1;
	for (int i = 0; i < 25; i++) {		/*silinene takimin kontrol mekanizmalarini olmasi gerektigi sekilde ayarliyor*/
		takim[sec - 1].oyuncular[i].mevkiler.Silindi_mi = 1;
		takim[sec - 1].oyuncular[i].oyunda_mi = 0;
	}
}

string takim_olusturma(int a){		/*kod calistirildiginda rastgele sekilde olusacak takimlari yapan fonksiyon*/
	int rastgele = rand() % 150;
	int rastgele1 = rand() % 133;
	string eleman1 = oyuncu->oyuncu_isim[rastgele];
	string eleman2 = oyuncu->oyuncu_soyisim[rastgele1];
	string isim = eleman1 + " " + eleman2;

	int rastgele3 = rand() % 81;
	string sehir = oyuncu->sehirler.at(rastgele3);

	string takim_ismi = oyuncu->superLigTakimlari.at(a);
	system(("mkdir C:\\Users\\Vıctus\\Desktop\\proje\\Projeodevi\\takimlar\\" + takim_ismi).c_str());		/*rastgele secilen takimin klasorunu olusturuyor*/
	dosyamiz = "C:\\Users\\Vıctus\\Desktop\\proje\\Projeodevi\\takimlar\\" + takim_ismi + "\\" + takim_ismi + ".txt";
	ofstream takim_olustur;
	//cout << isim << endl;
	takim_olustur.open(dosyamiz, ios::app);

	takim[a].Isim = oyuncu->superLigTakimlari.at(a);
	takim[a].Sehir = sehir;			/*classin icine takimin biliglerini veriyor*/
	takim[a].Yonetici = isim;
	takim[a].Silindi_mi = 0;

	takim_olustur << takim_ismi << endl
		<< isim << endl
		<< sehir << endl;		/*acilan klassorun icine takimla ayni isimde txt dosyasi olusturup icine takimin bilgilerini yaziyor*/
	takim_olustur.close();
	return takim_ismi;
}

void takima_oyuncu_ekleme(string takim_ismi, int no, int oyuncu_sayac) {		/*el ile bir takima oyuncu eklememizi saglayan fonksiyon*/
	int secim;
	dosyamiz = "C:\\Users\\Vıctus\\Desktop\\proje\\Projeodevi\\takimlar\\" + takim_ismi;
	string isim, soyisim, tc, telno, lisans, mevki, dogum_tarihi, dogum_yeri;
	cout << "Oyuncunun ismini giriniz: ";
	cin >> isim;
	cout << "Soyismini giriniz: ";
	cin >> soyisim;
	cout << "Lisans kodunu giriniz(6 haneli sayi): ";
	cin >> lisans;								/*oyuncunun bilgilerini giriyoruz*/
	cout << "TC numarasini giriniz: ";
	cin >> tcno;
	cout << "Tel nosunu giriniz: ";
	cin >> telno;
	cout << "Dogum tarihini giriniz: ";
	cin >> dogum_tarihi;
	cout << "Dogum yerini giriniz: ";
	cin >> dogum_yeri;

	cout << "1) Kaleci\n"
		<< "2) Savunma\n"		/*rolunu seciyoruz*/
		<< "3) Orta saha\n"
		<< "4) Kanat\n"
		<< "5) Forvet\n"
		<< "6) Yedek Kaleci\n"
		<< "7) Yedek Savunma\n"
		<< "8) Yedek Orta saha\n"
		<< "9) Yedek Kanat\n"
		<< "10) Yedek Forvet\n";
	
	cout << "Mevkisini seciniz : ";
	cin >> secim;
	
	for (int i = 0; i < 25; i++) {
		if (takim[no].oyuncular[i].mevkiler.Silindi_mi == 1) {
			switch (secim) {
			case 1:
				takim[no].oyuncular[i].mevkiler.kaleci_mi = 1;
				takim[no].oyuncular[i].mevkiler.gol_atma_olasiligi = 0.001;
				takim[no].oyuncular[i].oyunda_mi = 1;			/*secilen role uygun gol atma olasiliklarini atiyoruz*/
				mevki = "kaleci";
				break;
			case 2:
				takim[no].oyuncular[i].mevkiler.savunma_mi = 1;
				takim[no].oyuncular[i].mevkiler.gol_atma_olasiligi = 0.1;
				takim[no].oyuncular[i].oyunda_mi = 1;
				mevki = "savunma";
				break;
			case 3:
				takim[no].oyuncular[i].mevkiler.orta_saha_mi = 1;
				takim[no].oyuncular[i].mevkiler.gol_atma_olasiligi = 0.2;
				takim[no].oyuncular[i].oyunda_mi = 1;
				mevki = "orta saha";
				break;
			case 4:
				takim[no].oyuncular[i].mevkiler.kanat_mi = 1;
				takim[no].oyuncular[i].mevkiler.gol_atma_olasiligi = 0.3;
				takim[no].oyuncular[i].oyunda_mi = 1;
				mevki = "kanat";
				break;
			case 5:
				takim[no].oyuncular[i].mevkiler.forvet_mi = 1;
				takim[no].oyuncular[i].mevkiler.gol_atma_olasiligi = 0.5;
				takim[no].oyuncular[i].oyunda_mi = 1;
				mevki = "forvet";
				break;
			case 6:
				takim[no].oyuncular[i].mevkiler.yedek_kaleci_mi = 1;
				takim[no].oyuncular[i].mevkiler.gol_atma_olasiligi = 0.0005;
				mevki = " yedek kaleci";
				break;
			case 7:
				takim[no].oyuncular[i].mevkiler.yedek_savunma_mi = 1;
				takim[no].oyuncular[i].mevkiler.gol_atma_olasiligi = 0.05;
				mevki = "yedek savunma";
				break;
			case 8:
				takim[no].oyuncular[i].mevkiler.yedek_orta_saha_mi = 1;
				takim[no].oyuncular[i].mevkiler.gol_atma_olasiligi = 0.1;
				mevki = "yedek orta saha";
				break;
			case 9:
				takim[no].oyuncular[i].mevkiler.yedek_kanat_mi = 1;
				takim[no].oyuncular[i].mevkiler.gol_atma_olasiligi = 0.15;
				mevki = "yedek kanat";
				break;
			case 10:
				takim[no].oyuncular[i].mevkiler.yedek_forvet_mi = 1;
				takim[no].oyuncular[i].mevkiler.gol_atma_olasiligi = 0.25;
				mevki = "yedek forvet";
				break;
			}
			takim[no].oyuncular[i].Ad = isim;
			takim[no].oyuncular[i].Soyad = soyisim;
			takim[no].oyuncular[i].Tc = tcno;
			takim[no].oyuncular[i].Telno = telno;		/*bosta bulunan ilk nesnenin icine oyuncunun bilgilerini dolduruyoruz*/
			takim[no].oyuncular[i].Lisans = lisans;
			takim[no].oyuncular[i].Mevki = mevki;
			takim[no].oyuncular[i].Dogum_tarih = dogum_tarihi;
			takim[no].oyuncular[i].Dogum_yer = dogum_yeri;
			takim[no].oyuncular[i].mevkiler.Silindi_mi = 0;
			takim[no].oyuncular[i].mevkiler.oyuncu_sirasi = i;
			i = 30;
		}
	}
	dosyamiz = "C:\\Users\\Vıctus\\Desktop\\proje\\Projeodevi\\takimlar\\" + takim_ismi + "\\" + isim + " " + soyisim + ".txt";
	ofstream oyuncu_ekleme;
	oyuncu_ekleme.open(dosyamiz, ios::app);
	oyuncu_ekleme << lisans << endl
		<< isim << endl
		<< tcno << endl
		<< telno << endl		/*bir txt dosyasi olusturup oyuncunun bilgilerini icine yaziyoruz*/
		<< dogum_tarihi << endl
		<< dogum_yeri << endl
		<< mevki << endl;
	oyuncu_ekleme.close();
}

void  takimdan_oyuncu_silme(int secim, int secim1) {		/*sectigimiz bir takimdan sectigimiz bir oyuncuyu silen fonksiyon*/
	takim[secim].oyuncular[secim1].mevkiler.Silindi_mi = 1;
	string dosya = "C:\\Users\\Vıctus\\Desktop\\proje\\Projeodevi\\takimlar\\" +
		takim[secim].Isim + "\\" + takim[secim].oyuncular[secim1].Ad + " " +
		takim[secim].oyuncular[secim1].Soyad + ".txt";
	remove(dosya.c_str());
	takim[secim].oyuncular[secim1].mevkiler.Silindi_mi = 1;
	takim[secim].oyuncular[secim1].Soyad += "(silindi)";
}

void oyuncu_olusturma(int a, string takim_ismi) {	/*rastgele sekilde yaratilan takim classinin icindeki oyuncu classini yine rastgele bilgilerle dolduruyor*/
	
	for (int i = 0; i < 22; i++) {
		dosyamiz = "C:\\Users\\Vıctus\\Desktop\\proje\\Projeodevi\\takimlar\\" + takim_ismi;
		int rastgele = rand() % 150;
		int rastgele1 = rand() % 133;
		string eleman1 = oyuncu->oyuncu_isim[rastgele];
		string eleman2 = oyuncu->oyuncu_soyisim[rastgele1];
		string isim = eleman1 + " " + eleman2;

		for (int i = 0; i < 11; i++) {	/*tc no olusturuyor*/
			int rastgele = rand() % 10;
			string s = to_string(rastgele);
			tcno = tcno + s;
		}
		for (int i = 0; i < 9; i++) {	/*tel no olusturuyor*/
			int rastgele = rand() % 10;
			string s = to_string(rastgele);
			telno = telno + s;
		}
		for (int i = 0; i < 8; i++) {		/*lisans no olusturuyor*/
			int rastgele = rand() % 10;
			string s = to_string(rastgele);
			lisans += s;
		}
		string dogum_yili = to_string(2023 - (rand() % 40));
		string dogum_ayi = to_string(rand() % 12 + 1);		/*dogum gununu olusturuyor*/
		string dogum_günü = to_string(rand() % 31 + 1);
		string dogum_tarihi = dogum_günü +"/" + dogum_ayi +"/" + dogum_yili;
		int k = rand() % 81;
		string dogum_yeri = oyuncu->sehirler.at(k);
		string mevki = oyuncu->oyuncu_mevki.at(i);

		if (i == 0) {
			takim[a].oyuncular[i].mevkiler.kaleci_mi = 1;
			takim[a].oyuncular[i].oyunda_mi = 1;		/*rolune uygun gol olasiligi ekliyor*/
		}
		else if (i > 0 && i < 5) {
			takim[a].oyuncular[i].mevkiler.savunma_mi = 1;
			takim[a].oyuncular[i].oyunda_mi = 1;
		}
		else if (i > 4 && i < 8) {
			takim[a].oyuncular[i].mevkiler.orta_saha_mi = 1;
			takim[a].oyuncular[i].oyunda_mi = 1;
		}
		else if (i > 7 && i < 10) {
			takim[a].oyuncular[i].mevkiler.kanat_mi = 1;
			takim[a].oyuncular[i].oyunda_mi = 1;
		}
		else if (i == 10) {
			takim[a].oyuncular[i].mevkiler.forvet_mi = 1;
			takim[a].oyuncular[i].oyunda_mi = 1;
		}

		else if (i == 11) {
			takim[a].oyuncular[i].mevkiler.yedek_kaleci_mi = 1;
		}
		else if (i > 11 && i < 16) {
			takim[a].oyuncular[i].mevkiler.yedek_savunma_mi = 1;
		}
		else if (i > 15 && i < 19) {
			takim[a].oyuncular[i].mevkiler.yedek_orta_saha_mi = 1;
		}
		else if (i > 18 && i < 21) {
			takim[a].oyuncular[i].mevkiler.yedek_kanat_mi = 1;
		}
		else if (i == 21) {
			takim[a].oyuncular[i].mevkiler.yedek_forvet_mi = 1;
		}


		takim[a].oyuncular[i].Ad = eleman1;

		takim[a].oyuncular[i].Soyad = eleman2;

		takim[a].oyuncular[i].Tc = tcno;

		takim[a].oyuncular[i].Telno = telno;

		takim[a].oyuncular[i].Lisans = lisans;
		takim[a].oyuncular[i].Dogum_tarih = dogum_tarihi;
		takim[a].oyuncular[i].Dogum_yer = dogum_yeri;		/*oyuncunun bilgilerini classin icine dolduruyor*/
		takim[a].oyuncular[i].Mevki = mevki;
		takim[a].oyuncular[i].mevkiler.Silindi_mi = 0;
		takim[a].oyuncular[i].mevkisi = i;
		takim[a].oyuncular[i].mevkiler.oyuncu_sirasi = i;

		dosyamiz = dosyamiz + "\\" + isim + ".txt";
		ofstream oyuncu_isimleri;
		oyuncu_isimleri.open(dosyamiz, ios::app);
		if (oyuncu_isimleri.is_open()) {
		}
		else {
			cerr << "Hata:"
				<< dosyamiz << " olusturulamadi." << endl;
		}
		
		oyuncu_isimleri
			<< lisans << endl
			<< isim << endl
			<< tcno << endl
			<< telno << endl		/*oyuncunun bilgilerini bir txt dosyasin olusturup icine dolduruyor*/
			<< dogum_tarihi << endl
			<< dogum_yeri << endl
			<< mevki << endl;
		tcno = "";
		lisans = "";
		telno = "05";
		oyuncu_isimleri.close();

		gol_olasiligi_belirleyici(a, i);
	}
}

void takim_yazdirma() {		/*silinmemis takimlari ekrana yazdiriyor*/
	for (int i = 0; i < 20; i++) {
		if (takim[i].Silindi_mi == 0) {
			cout << "Takimin ismi: " << takim[i].Isim << endl
				<< "Takimin sehri: " << takim[i].Sehir << endl
				<< "Takimin yoneticisi: " << takim[i].Yonetici << endl << endl;
		}
	}
}

void futbolcu_ayrintili_listeleme() {		/*silinmemis takimlari tum bilgileri ile ekrana yazdiriyor*/
	int secim;
	for (int i = 0; i < 20; i++) {
		if (takim[i].Silindi_mi == 0) {
			cout << i+1 << ". Takimin ismi: " << takim[i].Isim << endl;
		}
	}
	cout << "Hangi takimin futbolcularini ayrintili listelemek istiyorsunuz:";
	cin >> secim;
	secim -= 1;
	for (int i = 0; i < 23; i++) {
		if (takim[secim].oyuncular[i].mevkiler.Silindi_mi == 0) {
			cout << i + 1 << ") Ismi: "
				<< takim[secim].oyuncular[i].Ad
				<< " " << takim[secim].oyuncular[i].Soyad << endl
				<< "Mevkisi: " << takim[secim].oyuncular[i].Mevki << endl
				<< "Telefon numarasi: " << takim[secim].oyuncular[i].Telno << endl
				<< "TC kimlik numarasi: " << takim[secim].oyuncular[i].Tc << endl
				<< "Lisans kodu: " << takim[secim].oyuncular[i].Lisans << endl
				<< "Dogum tarihi: " << takim[secim].oyuncular[i].Dogum_tarih << endl
				<< "Dogum yeri: " << takim[secim].oyuncular[i].Dogum_yer << endl << endl;
		}
	}
}

void oyuncu_listele() {		/*bir takimin silinmemis oyuncularini ekrana yazdiriyor*/
	int secilecek;
	for (int i = 0; i < 18; i++) {
		cout<<takim[i].Isim<<endl;
	}
	cout << "Oyuncularini gormek istediginiz takimi seciniz\n";
	cin >> secilecek;
	secilecek--;
	
	for (int i = 0; i < 20; i++) {
		cout << takim[secilecek].oyuncular[i].Ad << " " << takim[secilecek].oyuncular[i].Soyad << endl;
	}
}

void oyuncu_guncelle(int sayac) {		/*sectigimiz bir oyuncunun bilgilerinin guncellememizi saglayan fonksiyon*/
	string isim, soyisim, tc, telno, lisans, mevki, dogum_tarihi, dogum_yeri;
	int secim;
	int secim1;
	int secim2;

	for (int i = 0; i < sayac + 18; i++) {
		if (takim[i].Silindi_mi == 0) {
			cout << i + 1 << ")" << takim[i].Isim << endl;
		}
	}

	cout << "Hangi takimin oyuncusunu guncellemek istiyorsun:";
	cin >> secim;
	secim -= 1;

	for (int i = 0; i < 25; i++) {
		if (takim[secim].oyuncular[i].mevkiler.Silindi_mi == 0) {
			cout << i + 1 << ")"
				<< takim[secim].oyuncular[i].Ad << " "
				<< takim[secim].oyuncular[i].Soyad << endl;
		}
	}
	cout << "Hangi oyuncuyu guncellemek istiyorsun:";
	cin >> secim1;
	secim1 -= 1;

	dosyamiz = "C:\\Users\\Vıctus\\Desktop\\proje\\Projeodevi\\takimlar\\" +
		takim[secim].Isim + "\\" + takim[secim].oyuncular[secim1].Ad + " "
		+ takim[secim].oyuncular[secim1].Soyad + ".txt";
	remove(dosyamiz.c_str());
	cout << "Degistirmek istemediginiz kisimlarda parantez icindeki eski bilgiyi yaziniz\n";		/*oyuncunun yeni bilgilerini giriyoruz*/
	cout << "(" << takim[secim].oyuncular[secim1].Ad << ") Oyuncunun ismini giriniz: ";
	cin >> isim;
	cout << "(" << takim[secim].oyuncular[secim1].Soyad << ") Soyismini giriniz: ";
	cin >> soyisim;
	cout << "(" << takim[secim].oyuncular[secim1].Lisans << ") Lisans kodunu giriniz(6 haneli sayi): ";
	cin >> lisans;
	cout << "(" << takim[secim].oyuncular[secim1].Tc << ") TC numarasini giriniz: ";
	cin >> tcno;
	cout << "(" << takim[secim].oyuncular[secim1].Telno << ") Tel nosunu giriniz: ";
	cin >> telno;
	cout << "1) Kaleci\n"
		<< "2) Savunma\n"
		<< "3) Orta saha\n"
		<< "4) Kanat\n"
		<< "5) Forvet\n"
		<< "6) Yedek Kaleci\n"
		<< "7) Yedek Savunma\n"
		<< "8) Yedek Orta saha\n"
		<< "9) Yedek Kanat\n"
		<< "10) Yedek Forvet\n";
	cout << "(" << takim[secim].oyuncular[secim1].Mevki << ") Mevkisini seciniz: ";
	cin >> secim2;

	switch (secim2) {
	case 1:
		takim[secim].oyuncular[secim1].mevkiler.kaleci_mi = 1;		/*oyuncunun rolunu seciyoruz ve ona uygun gol olasiligi ataniyor*/
		takim[secim].oyuncular[secim1].mevkiler.gol_atma_olasiligi = 0.001;
		takim[secim].oyuncular[secim1].oyunda_mi = 1;
		mevki = "kaleci";
		break;
	case 2:
		takim[secim].oyuncular[secim1].mevkiler.savunma_mi = 1;
		takim[secim].oyuncular[secim1].mevkiler.gol_atma_olasiligi = 0.1;
		takim[secim].oyuncular[secim1].oyunda_mi = 1;
		mevki = "savunma";
		break;
	case 3:
		takim[secim].oyuncular[secim1].mevkiler.orta_saha_mi = 1;
		takim[secim].oyuncular[secim1].mevkiler.gol_atma_olasiligi = 0.2;
		takim[secim].oyuncular[secim1].oyunda_mi = 1;
		mevki = "orta saha";
		break;
	case 4:
		takim[secim].oyuncular[secim1].mevkiler.kanat_mi = 1;
		takim[secim].oyuncular[secim1].mevkiler.gol_atma_olasiligi = 0.3;
		takim[secim].oyuncular[secim1].oyunda_mi = 1;
		mevki = "kanat";
		break;
	case 5:
		takim[secim].oyuncular[secim1].mevkiler.forvet_mi = 1;
		takim[secim].oyuncular[secim1].mevkiler.gol_atma_olasiligi = 0.5;
		takim[secim].oyuncular[secim1].oyunda_mi = 1;
		mevki = "forvet";
		break;

	case 6:
		takim[secim].oyuncular[secim1].mevkiler.yedek_kaleci_mi = 1;
		takim[secim].oyuncular[secim1].mevkiler.gol_atma_olasiligi = 0.0005;
		mevki = "yedek kaleci";
		break;
	case 7:
		takim[secim].oyuncular[secim1].mevkiler.yedek_savunma_mi = 1;
		takim[secim].oyuncular[secim1].mevkiler.gol_atma_olasiligi = 0.05;
		mevki = "yedek savunma";
		break;
	case 8:
		takim[secim].oyuncular[secim1].mevkiler.yedek_orta_saha_mi = 1;
		takim[secim].oyuncular[secim1].mevkiler.gol_atma_olasiligi = 0.1;
		mevki = "yedek orta saha";
		break;
	case 9:
		takim[secim].oyuncular[secim1].mevkiler.yedek_kanat_mi = 1;
		takim[secim].oyuncular[secim1].mevkiler.gol_atma_olasiligi = 0.15;
		mevki = "yedek kanat";
		break;
	case 10:
		takim[secim].oyuncular[secim1].mevkiler.yedek_forvet_mi = 1;
		takim[secim].oyuncular[secim1].mevkiler.gol_atma_olasiligi = 0.25;
		mevki = "yedek forvet";
		break;
	}

	cout << "(" << takim[secim].oyuncular[secim1].Dogum_tarih << ") Dogum tarihini giriniz: ";
	cin >> dogum_tarihi;
	cout << "(" << takim[secim].oyuncular[secim1].Dogum_yer << ") Dogum yerini giriniz: ";
	cin >> dogum_yeri;

	takim[secim].oyuncular[secim1].Ad = isim;
	takim[secim].oyuncular[secim1].Soyad = soyisim;
	takim[secim].oyuncular[secim1].Lisans = lisans;		/*yeni bilgiler classa kaydediliyor*/
	takim[secim].oyuncular[secim1].Tc = tcno;
	takim[secim].oyuncular[secim1].Telno = telno;
	takim[secim].oyuncular[secim1].Mevki = mevki;
	takim[secim].oyuncular[secim1].Dogum_tarih = dogum_tarihi;
	takim[secim].oyuncular[secim1].Dogum_yer = dogum_yeri;

	string yeni_oyuncu = "C:\\Users\\Vıctus\\Desktop\\proje\\Projeodevi\\takimlar\\" +
		takim[secim].Isim + "\\" + isim + " "
		+ soyisim + ".txt";

	ofstream guncelle;
	guncelle.open(yeni_oyuncu, ios::app);

	guncelle << lisans << endl
		<< isim << endl
		<< tcno << endl		/*yeni bilgiler yeni bir txt dosyasinin icine tekrar yaziliyor*/
		<< telno << endl
		<< dogum_tarihi << endl
		<< dogum_yeri << endl
		<< mevki << endl;
	guncelle.close();
}

void play_off(int takim1, int takim2) {		/*eger atilan goller dahil butun puanlama teknikleri esitse bir play off maci oynatiyor*/
	int k = 1;
	int random1;
	int random2;
	int ev_gol;
	int dep_gol;
	string atan1 = "";
	string atan2 = "";

	while (k == 1) {		
		random1 = rand() % skor.goller.size();
		random2 = rand() % skor.goller.size();

		ev_gol = skor.goller.at(random1);
		dep_gol = skor.goller.at(random2);
		if(ev_gol != dep_gol){
			k = 0;
		}
	}
	for (int a = 0; a < ev_gol; a++) {
		int dk = rand() % 91;
		int random;
		int atan_indis;
		int n = 1;

		while (n == 1) {
			random = rand() % takim[takim1].gol_atan.size();
			atan_indis = takim[takim1].gol_atan.at(random);
			if (takim[takim1].oyuncular[atan_indis].mevkiler.Silindi_mi == 0 && takim[takim1].oyuncular[atan_indis].oyunda_mi == 1) {
				n = 0;
			}
		}
		atan1 += takim[takim1].oyuncular[atan_indis].Ad + " "
			+ takim[takim1].oyuncular[atan_indis].Soyad + "  DK:'" + to_string(dk) + "\n";
		takim[takim1].oyuncular[atan_indis].gol_sayisi += 1;
	}
	for (int s = 0; s < dep_gol; s++) {
		int dk = rand() % 91;
		int n = 1;
		int atan_indis;
		int random;

		while (n == 1) {
			random = rand() % takim[takim2].gol_atan.size();
			atan_indis = takim[takim2].gol_atan.at(random);
			if (takim[takim2].oyuncular[atan_indis].mevkiler.Silindi_mi == 0 && takim[takim2].oyuncular[atan_indis].oyunda_mi == 1) {
				n = 0;
			}
		}
		atan2 += takim[takim2].oyuncular[atan_indis].Ad + " "
			+ takim[takim2].oyuncular[atan_indis].Soyad + "  DK:'" + to_string(dk) + "\n";
		takim[takim2].oyuncular[atan_indis].gol_sayisi += 1;
	}
	cout << takim[takim1].Isim << " " << atan1 << takim[takim2].Isim << " " << atan2;
}

int buyuk_mu(int sayi) {		/*lig tablosu icin takimlarin puan, averaj, atilan ve yenilen gol degerlerini karsilastiriyor*/
	for (int i = 0; i < 20; i++) {
		if (takim[i].tabloda_mi == 0 && sayi != i) {		/*eger fonksiyona parametre olarak gelen takim puanda dusukse return 0 oluyor*/
			if (takim[sayi].puan < takim[i].puan) {
				return 0;
			}
			else if (takim[sayi].puan > takim[i].puan) {		/*puan esit olursa averaj avreaj esitse atilan gol seklinde devam ederek dogru birl sekilde siralamayi yapıyor*/
			}
			else if (takim[sayi].puan == takim[i].puan) {
				if (takim[sayi].averaj > takim[i].averaj) {
				}
				else if (takim[sayi].averaj < takim[i].averaj) {
					return 0;
				}
				else if (takim[sayi].averaj == takim[i].averaj) {
					if (takim[sayi].atilan_gol > takim[i].atilan_gol) {
					}
					else if (takim[sayi].atilan_gol < takim[i].atilan_gol) {
						return 0;
					}
					else if (takim[sayi].atilan_gol == takim[i].atilan_gol) {
						if (takim[sayi].yenilen_gol > takim[i].yenilen_gol) {
							return 0;
						}
						else if (takim[sayi].yenilen_gol < takim[i].yenilen_gol) {
						}
						else if (takim[sayi].yenilen_gol == takim[i].yenilen_gol) {		/*eger her konuda bir esitlik soz konusu ise playoff fonksiyonu cagriliyor*/
							cout << takim[sayi].Isim << " ve " << takim[i].Isim << " her istatistikte esitler...\n"
								<< "play off oynanacak";
							play_off(sayi, i);
						}
					}
				}
			}
		}
	}
	return 1;
}

void fikstur() {		/*takimlarin fiksturu olusturulup maclar oynaniyor*/
	string atan1 = "";
	string atan2 = "";
	string kadro2 = "";
	string kadro3 = "";
	string ev_degisikler = "";
	string dep_degisiklikler = "";
	vector<int> sayilar;

	cout << "Fiksturu kurup maclari oynatmak icin bir tusa basiniz\n";
	system("pause");			/*atilan, yenilen goller, oyuncu degisiklikleri... gibi butun durumlar bu fonksiyon icerisinde yapilip gerekli classlara gonderiliyor*/
	for (int i = 0; i < 20; i++) {
		if (takim[i].Silindi_mi == 0) {
			for (int j = 0; j < 20; j++) {
				if (takim[j].Silindi_mi == 0) {
				int t = 1;
				int t_sayac = 0;
				for (int a = 0; a < 7; a++) {		/*dep takimi icin oyuncu  degisiklikleri yapiliyor*/
					int dep_girecek = rand() % 15 + 10;
					int dep_cikacak = rand() % 11;
					if (takim[j].oyuncular[dep_cikacak].mevkiler.Silindi_mi == 0
						&& takim[j].oyuncular[dep_girecek].mevkiler.Silindi_mi == 0
						&& takim[j].oyuncular[dep_cikacak].oyunda_mi == 1
						&& takim[j].oyuncular[dep_girecek].oyunda_mi == 0) {

						takim[j].oyuncular[dep_girecek].oyunda_mi = 1;
						takim[j].oyuncular[dep_cikacak].oyunda_mi = 0;
						dep_degisiklikler += "Giren oyuncu-> " + takim[j].oyuncular[dep_girecek].Ad
							+ " " + takim[j].oyuncular[dep_girecek].Soyad + "\n"
							+ "Cikan oyuncu<- " + takim[j].oyuncular[dep_cikacak].Ad
							+ " " + takim[j].oyuncular[dep_cikacak].Soyad + "\n\n";
					}
				}
					if (i != j) {
						int t = 1;
						int t_sayac = 0;
						for (int a = 0; a < 8; a++) {		/*ev takimi icin oyuncu degisiklikleri yapiliyor*/
							int ev_girecek = rand() % 15 + 11;
							int ev_cikacak = rand() % 11;
							if (takim[i].oyuncular[ev_cikacak].mevkiler.Silindi_mi == 0
								&& takim[i].oyuncular[ev_girecek].mevkiler.Silindi_mi == 0
								&& takim[i].oyuncular[ev_cikacak].oyunda_mi == 1
								&& takim[i].oyuncular[ev_girecek].oyunda_mi == 0) {

								takim[i].oyuncular[ev_girecek].oyunda_mi = 1;
								takim[i].oyuncular[ev_cikacak].oyunda_mi = 0;
								ev_degisikler += "Giren oyuncu-> " + takim[i].oyuncular[ev_girecek].Ad
									+ " " + takim[i].oyuncular[ev_girecek].Soyad + "\n"
									+ "Cikan oyuncu<- " + takim[i].oyuncular[ev_cikacak].Ad
									+ " " + takim[i].oyuncular[ev_cikacak].Soyad + "\n\n";
							}
						}
						int sayi = rand() % skor.goller.size();
						int sayi1 = rand() % skor.goller.size();

						int ev_gol = skor.goller.at(sayi);
						int dep_gol = skor.goller.at(sayi1);

						for (int a = 0; a < ev_gol; a++) {
							int dk = rand() % 91;
							int random;
							int atan_indis;
							int n = 1;

							while (n == 1) {		/* ev ve depin attigi goller hesaplanip atan oyuncuular ve dk'si rastgele belirleniyor*/
								random = rand() % takim[i].gol_atan.size();
								atan_indis = takim[i].gol_atan.at(random);
								if (takim[i].oyuncular[atan_indis].mevkiler.Silindi_mi == 0 && takim[i].oyuncular[atan_indis].oyunda_mi == 1) {
									n = 0;
								}
							}
							atan1 += takim[i].oyuncular[atan_indis].Ad + " " 
								+ takim[i].oyuncular[atan_indis].Soyad + "  DK:'" + to_string(dk) + "\n";
							takim[i].oyuncular[atan_indis].gol_sayisi += 1;
						}
						for (int s = 0; s < dep_gol; s++) {
							int dk = rand() % 91;
							int n = 1;
							int atan_indis;
							int random;

							while (n == 1) {
								random = rand() % takim[j].gol_atan.size();  //dizinin eleman sayisi 0 oluyor
								atan_indis = takim[j].gol_atan.at(random);
								if (takim[j].oyuncular[atan_indis].mevkiler.Silindi_mi == 0 && takim[j].oyuncular[atan_indis].oyunda_mi == 1) {
									n = 0;
								}
							}
							atan2 += takim[j].oyuncular[atan_indis].Ad + " " 
								+ takim[j].oyuncular[atan_indis].Soyad + "  DK:'" + to_string(dk) + "\n";
							takim[j].oyuncular[atan_indis].gol_sayisi += 1;
						}

						takim[i].atilan_gol += ev_gol;
						takim[i].yenilen_gol += dep_gol;
						takim[j].atilan_gol += dep_gol;		/*olusan degerler gerekli classlarin iceriisine gonderiliyor*/
						takim[j].yenilen_gol += ev_gol;
						takim[i].averaj += ev_gol - dep_gol;
						takim[j].averaj += dep_gol - ev_gol;

						if (ev_gol > dep_gol) {
							takim[i].puan += 3;
						}
						else if (ev_gol == dep_gol) {
							takim[i].puan += 1;
							takim[j].puan += 1;
						}
						else if (ev_gol < dep_gol) {
							takim[j].puan += 3;
						}

						string c = to_string(ev_gol);
						string d = to_string(dep_gol);

						mac.karsilasmalar.push_back({ takim[i].Isim
							+ " " + c + " - " + d + " "
							+ takim[j].Isim
							+ atan1 });

						takim[i].maclari[takim[i].mac_sayaci].maci = (takim[i].Isim
							+ " " + c + " - " + d + " "
							+ takim[j].Isim
							+ "\nEv : \n" + atan1
							+ "\nDep : \n"
							+ atan2);

						takim[j].maclari[takim[j].mac_sayaci].maci = (takim[i].Isim
							+ " " + c + " - " + d + " "
							+ takim[j].Isim
							+ "\nEv : \n" + atan1
							+ "\nDep : \n"
							+ atan2);

						for (int w = 0; w < 25; w++) {
							if (takim[i].oyuncular[w].mevkiler.Silindi_mi != 1 ) {
								kadro2 += takim[i].oyuncular[w].Ad + " "
									+ takim[i].oyuncular[w].Soyad + " "
									+ " (" + takim[i].oyuncular[w].Mevki + ")\n";
							}
						}
						for (int w = 0; w < 25; w++) {
							if (takim[j].oyuncular[w].mevkiler.Silindi_mi != 1) {		/*ekrana yazilacak degerler hazirlaniyor*/
								kadro3 += takim[j].oyuncular[w].Ad + " "
									+ takim[j].oyuncular[w].Soyad + " "
									+ " (" + takim[j].oyuncular[w].Mevki + ")\n";
							}
						}
						takim[i].maclari[takim[i].mac_sayaci].maci_detayli = takim[i].maclari[takim[i].mac_sayaci].maci
							+ "\n\n*****Ev kadrosu*****\n\n" + kadro2 + "\n\n\tEv oyuncu degisiklikleri:\n" + ev_degisikler
							+ "\n\n*****Deplasman kadrosu*****\n\n" + kadro3 + "\n\n\tDeplasman oyuncu degisiklikleri:\n" + dep_degisiklikler;

						takim[j].maclari[takim[j].mac_sayaci].maci_detayli = takim[i].maclari[takim[i].mac_sayaci].maci
							+ "\n\n*****Ev kadrosu*****\n\n" + kadro2 + "\n\n\tEv oyuncu degisiklikleri:\n" + ev_degisikler
							+ "\n\n*****Deplasman kadrosu*****\n\n" + kadro3 + "\n\n\tDeplasman oyuncu degisiklikleri:\n" + dep_degisiklikler;

						atan1 = "";
						atan2 = "";
						kadro2 = "";
						kadro3 = "";
						ev_degisikler = "";
						dep_degisiklikler = "";

						for (int s = 0; s < 25; s++) {
							takim[i].oyuncular[s].oyunda_mi = 1;
							takim[j].oyuncular[s].oyunda_mi = 1;
							if (s > 10) {
								takim[i].oyuncular[s].oyunda_mi = 0;
								takim[j].oyuncular[s].oyunda_mi = 0;
							}
						}
						takim[i].mac_sayaci++;
						takim[j].mac_sayaci++;
					}
				}
			}
		}
	}
}

void tablo() {		/*lig tablosunu hazirlayan fonksiyon*/
	int t = 1;
	int test = 1;
	vector<int> siralama;

	for (int k = 0; k < 500; k++) {
		for (int i = 0; i < 20; i++) {
			if (takim[i].Silindi_mi == 0 && takim[i].tabloda_mi == 0) {
				if (buyuk_mu(i) == 1) {
					cout << t << ") " << takim[i].Isim << endl
						<< "Puani:" << takim[i].puan << endl
						<< "Averaj: " << takim[i].averaj << endl
						<< "Attigi gol:" << takim[i].atilan_gol << endl
						<< "Yedigi gol:" << takim[i].yenilen_gol << endl << endl;
					takim[i].tabloda_mi = 1;
					siralama.push_back({ i });
					t++;
					i = 0;
				}
			}
		}
	}
}

void setw_tablo() {
	int t = 1;
	int test = 1;
	vector<int> siralama;

	cout << "Takim" << setw(20) << "Puan" << setw(15) << "Averaj" << setw(15) << "Atilan gol" << setw(15) << "Yenilen gol\n";

	for (int k = 0; k < 500; k++) {
		for (int i = 0; i < 20; i++) {
			if (takim[i].Silindi_mi == 0 && takim[i].tabloda_mi == 0) {
				if (buyuk_mu(i) == 1) {

					cout << t << ") " << takim[i].Isim << setw(20)
						<< takim[i].puan << setw(15)
						<< takim[i].averaj << setw(15)
						<< takim[i].atilan_gol << setw(15)
						<< takim[i].yenilen_gol << endl;
					takim[i].tabloda_mi = 1;
					siralama.push_back({ i });
					t++;
					i = 0;
				}
			}
		}
	}
}

void anamenu() {		/*oyuncu ekleme ve silme, takim ekleme ve silme.. gibi islemleri yapabildigimiz ana menu*/
	int secenek;
	int k = 1;
	int olusturma_sayaci = 0;
	int oyuncu_sayaci = 0;
	cout << "Futbol lig takip sistemine hosgeldiniz\n";

	while (k==1) {
		cout << "*******---Yapmak istediginiz islemi seciniz---*******\n"
			<< "1) - Takim olusturma\n"
			<< "2) - Takim silme\n"
			<< "3) - Takim listeleme\n"
			<< "4) - Takima futbolcu ekleme\n"		/*yapabildigimiz islemler*/
			<< "5) - Takimdan futbolcu silme\n"
			<< "6) - Takimdaki futbolculari listeleme\n"
			<< "7) - Takimdaki futbolculari ayrintili listeleme\n"
			<< "8) - Takimdaki bir futbolcuyu guncelleme\n"
			<< "9) - Ligi baslatma\n";
		cin >> secenek;
		switch (secenek) {
		case 1:
			if (olusturma_sayaci > 1) {		/*sectigimiz islemleri yerine getiren switch case yapisi*/
				cout << "20 takim ile federasyon tarafindan koyulan takim sayisi limitine ulasildi\n"
					<< "Bir takimi silmeden baska bir takim ekleyemezsiniz\n";
				break;
			}
			cout << "Takim olusturma islemine hosgeldiniz\n";
			takim_ekleme();
			olusturma_sayaci++;
			break;
		case 2:
			for (int i = 0; i < 20; i++) {
				cout << i + 1 << takim[i].Isim << endl;

			}
			cout << "*******---Silmek istediginiz takimi seciniz---*******\n";
			takim_silme();
			olusturma_sayaci--;
			break;
		case 3:
			cout << "Takimlar listeleniyor";
			takim_yazdirma();
			break;
		case 4:
			int secim;
			if (oyuncu_sayaci == 3) {
				cout << "Federasyonun koydugu oyuncu sayisi limitine ulastiniz!!\n"
					<< "Daha fazla oyuncu ekleyebilmek icin oyuncu silmeniz gerekli!";
				break;
			}
			for (int i = 0; i < 20; i++) {
				if (takim[i].Silindi_mi == 0) {
					cout << i + 1 << ") " << takim[i].Isim << endl;
				}
			}
			cout << "Hangi takima oyuncu eklemek istiyorsunuz:";
			cin >> secim;
			takima_oyuncu_ekleme(takim[secim - 1].Isim, secim - 1, oyuncu_sayaci);
			oyuncu_sayaci++;
			break;
		case 5:
			int secim1;
			for (int i = 0; i < 20; i++) {
				if (takim[i].Silindi_mi == 0) {
					cout << i + 1 << ") " << takim[i].Isim << endl;
				}
			}
			cout << "Hangi takimdan oynucu silmek istiyorsunuz";
			cin >> secim;
			secim -= 1;
			for (int i = 0; i < 25; i++) {
				if (takim[secim].Silindi_mi == 0) {
					cout << i + 1 << ")" << takim[secim].oyuncular[i].Ad << " " << takim[secim].oyuncular[i].Soyad << endl;
				}
			}
			cout << "Hangi oyuncuyu silmek istiyorsunuz:";
			cin >> secim1;
			secim1 -= 1;
			takimdan_oyuncu_silme(secim, secim1);
			oyuncu_sayaci--;
			break;
		case 6:
			for (int i = 0; i < 20; i++) {
				if (takim[i].Silindi_mi == 0) {
					cout << i + 1 << ")" << takim[i].Isim << endl;
				}
			}
			cout << "Hangi takimin oyuncularini listelemek istiyorsunuz: ";
			cin >> secim;
			secim -= 1;
			for (int i = 0; i < 25; i++) {
				if (takim[secim].oyuncular[i].mevkiler.Silindi_mi == 0) {
					cout << i + 1 << ")" << takim[secim].oyuncular[i].Ad << " " << takim[secim].oyuncular[i].Soyad << endl;
				}
				else if (takim[secim].oyuncular[i].mevkiler.Silindi_mi == 1) {
					cout << i + 1 << ")" << takim[secim].oyuncular[i].Ad << " " << takim[secim].oyuncular[i].Soyad << "(yok)" << endl;
				}
			}
			break;
		case 7:
			futbolcu_ayrintili_listeleme();
			break;
		case 8:
			oyuncu_guncelle(olusturma_sayaci);
			break;
		case 9:		/*k 0'a esitlenip bu ana menu sona erdiliyor, maclar oynaniyor*/
			k = 0;
			break;
		default:
			cout << "Hatali bir islem sectiniz";
			break;
		}
	}
}

bool gol_kralligi(int i, int j) {		/*gol kralligi tablosu hazirlaniyor*/
	if (takim[i].oyuncular[j].gol_kralliginde_mi == 1) {
		return 0;
	}
	for (int k = 0; k < 20; k++) {
		for (int f = 0; f < 25; f++) {
			if (takim[k].oyuncular[f].gol_kralliginde_mi == 0) {
				if (takim[i].oyuncular[j].gol_sayisi < takim[k].oyuncular[f].gol_sayisi) {
					return 0;
				}
			}
		}
	}
	return 1;
}

void yeni_anamenu() {		/*maclar oynandiktan sonra mac sonuclarina, gol kralligi tablosuna bakabildigimiz ana menu*/
	int secenek;
	int k = 1;
	cout << "**********Lig sonra erdi**********\n";
	while (k == 1) {
		cout << "*******---Yapmak istediginiz islemi seciniz---*******\n"
			<< "1) Bir takimin maclarini goruntuleme\n"
			<< "2) Maclari kadro dahil goruntuleme\n"
			<< "3) Gol kralligi tablosunu goruntuleme\n"
			<< "0) Cikis\n";
		cin >> secenek;
		switch (secenek) {
		case 1:
			int seca;
			for (int i = 0; i < 20; i++) {
				if (takim[i].Silindi_mi == 0) {
					cout << i + 1 << ") " << takim[i].Isim << endl;
				}
			}
			cout << "Hangi takimin maclarini gormek istiyorsunuz:";
			cin >> seca;
			seca -= 1;

			for (int i = 0; i < takim[seca].mac_sayaci; i++) {
				cout << takim[seca].maclari[i].maci << endl;
			}
			break;
		case 2:
			int secenek;
			for (int i = 0; i < 20; i++) {
				if (takim[i].Silindi_mi == 0) {
					cout << i + 1 << ") " << takim[i].Isim << endl;
				}
			}
			cout << "Hangi takimin maclarini detayli gormek istiyorsun:";
			cin >> secenek;
			secenek -= 1;
			for (int i = 0; i < takim[secenek].mac_sayaci; i++) {
				cout << takim[secenek].maclari[i].maci_detayli << endl << endl;
			}
			break;
		case 3:
			int krallik_sayaci = 0;
			for (int a = 0; a < 1000; a++) {
				for (int i = 0; i < 20; i++) {
					for (int j = 0; j < 25; j++) {
						if (takim[i].Silindi_mi != 1
							&& takim[i].oyuncular[j].mevkiler.Silindi_mi != 1) {
							if (gol_kralligi(i, j)) {
								takim[i].oyuncular[j].gol_kralliginde_mi = 1;
								cout << takim[i].oyuncular[j].Ad << " "
									<< takim[i].oyuncular[j].Soyad << " \n"
									<< "Gol sayisi: " << takim[i].oyuncular[j].gol_sayisi
									<< "\nTakimi: " << takim[i].Isim << " \n" << endl << endl;
								krallik_sayaci++;
							}
							if (krallik_sayaci == 20) {
								a = 1001;
							}
						}
					}
				}
			}
		}
	}
}

int main() {		/*main fonksiyonumuz*/
	srand(time(NULL));
	for (int a = 0; a < 18; a++) {
		oyuncu_olusturma(a, takim_olusturma(a));
	}
	anamenu();
	mevkiler_gol();
	fikstur();
	tablo();
	yeni_anamenu();
}