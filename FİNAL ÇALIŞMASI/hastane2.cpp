
#include<iostream>
#include<string>
#include <algorithm>
#include <fstream>
#include <ctype.h>
#include <vector>

using namespace std;

class insan {

	protected:
		string tc;
		string ad;
		string soyAd;

	public:
		insan() {
			tc = "00000000000";
			ad = "ad";
			soyAd = "soyad";
		}

		insan(string tc, string ad, string soyAd) {
			this->tc = tc;
			this->ad = ad;
			this->soyAd = soyAd;
		}

		void setAll(string tc, string ad, string soyAd) {
			this->tc = tc;
			this->ad = ad;
			this->soyAd = soyAd;
		}

		void settc(string x) { tc = x; }
		void setad(string x) { ad = x; }
		void setsoyAd(string x) { soyAd = x; }

		string gettc() { return tc; }
		string getad() { return ad; }
		string getsoyAd() { return soyAd; }

		virtual void print() {
			cout << "Tc :" << tc << "\t Ad :" << ad << "\t Soyad :" << soyAd << endl;
		}
};

class hasta : public insan {
	protected:
		int hastaID;

	public:
		hasta() :insan() {
			hastaID = 0;
		}

		hasta(string tc, string ad, string soyAd, int hastaID) :insan(tc, soyAd, ad) 
		{
			this->hastaID = hastaID;
		}

		void setAll(string tc, string ad, string soyAd, int hastaID) 
		{
			this->tc = tc;
			this->ad = ad;
			this->hastaID = hastaID;
			this->soyAd = soyAd;
		}

		void sethastaID(int x) { hastaID = x; }

		int gethastaID() { return hastaID; }

		void print() {
			cout << "Tc :" << tc << "\t Ad :" << ad << "\t Soyad :" << soyAd << "\t hastaID :" << hastaID << endl;
		}
};


class doktor :public insan {
	protected:
		int doktorID;
		poliklinik poli;

	public:
		doktor() :insan() {
			doktorID = 0;
		}

		doktor(string tc, string ad, string soyAd, int doktorID, poliklinik poli) :insan(tc, soyAd, ad) {
			this->doktorID = doktorID;
			this->poli = poli;
		}

		void setAll(string tc, string ad, string soyAd, int doktorID, poliklinik poli) {
			this->tc = tc;
			this->ad = ad;
			this->doktorID = doktorID;
			this->soyAd = soyAd;
			this->poli = poli;
		}

		void setdoktorID(int x) { doktorID = x; }
		void setpoli(poliklinik x) { poli = x; }

		int getdoktorID() { return doktorID; }
		poliklinik getpoli() { return poli; }

		void print() {
			cout << "Tc :" << tc << "\t Ad :" << ad << "\t Soyad :" << soyAd << "\t doktorID :" << doktorID <<"        Poliklinik Bilgiler :    " << poli ;
		}
};


class poliklinik {
	private:
		int poliklinikID;
		string bolum;
		int isBaslamaSaati; // 0 ile 24 arasý bir deðer 
		int isBitisSaati;   //

		friend ostream& operator<<(ostream& output, poliklinik& v);
	public:
		poliklinik() {
			poliklinikID = 0;
			bolum = "";
			isBaslamaSaati = 0;
			isBitisSaati = 0;
		}

		poliklinik(int poliklinikID,string bolum,int isBaslamaSaati,int isBitisSaati) {
			this->poliklinikID = poliklinikID;
			this->bolum = bolum;
			this->isBaslamaSaati = isBaslamaSaati;
			this->isBitisSaati = isBitisSaati;
		}

		void setAll(int poliklinikID, string bolum, int isBaslamaSaati, int isBitisSaati) {
			this->poliklinikID = poliklinikID;
			this->bolum = bolum;
			this->isBaslamaSaati = isBaslamaSaati;
			this->isBitisSaati = isBitisSaati;
		}

		void setpoliklinikID(int x) { poliklinikID = x; }
		void setbolum(int x) { bolum = x; }
		void setisBaslamaSaati(int x) { isBaslamaSaati = x; }
		void setisBitisSaati(int x) { isBitisSaati = x; }
		

		int getpoliklinikID() { return poliklinikID; }
		string getbolum() { return bolum; }
		int getisBaslamaSaati() { return isBaslamaSaati; }
		int getisBitisSaati() { return isBitisSaati; }

		void print() {
			cout << "poliklinikID :" << poliklinikID << "  bolum  :" << bolum << "  isBaslamaSaati  :" << isBaslamaSaati << "  isBitisSaati  :" << isBitisSaati << endl;
		}

		poliklinik operator = (poliklinik v) {
			poliklinikID = v.poliklinikID;
			bolum = v.bolum;
			isBaslamaSaati = v.isBaslamaSaati;
			isBitisSaati = v.isBitisSaati;

			return *this;
		}


};

class randevu {
private:
	int randevuID;
	int rhastaID;
	int rdoktorID;
	int rpoliklinikID;
	string tarih;
	string saat;

	int s;
	int d;
	
public:
	randevu() {
		randevuID = 0;
		rhastaID = 0;
		rdoktorID = 0;
		rpoliklinikID = 0;
		tarih = "";
		saat = "";

		s = 0;
		d = 0;
	}

	randevu(int randevuID, int rhastaID, int rdoktorID, int rpoliklinikID, string tarih, string saat) {
		this->randevuID = randevuID;
		this->rhastaID = rhastaID;
		this->rdoktorID = rdoktorID;
		this->rpoliklinikID = rpoliklinikID;
		this->tarih = tarih;
		this->saat = saat;
	}

	void sets(int x) { s = x; }
	void setd(int x) { d = x; }

	void setAll(int randevuID, int rhastaID, int rdoktorID, int rpoliklinikID, string tarih, string saat, int s, int d) {
		this->randevuID = randevuID;
		this->rhastaID = rhastaID;
		this->rdoktorID = rdoktorID;
		this->rpoliklinikID = rpoliklinikID;
		this->tarih = tarih;
		this->saat = saat;
		this->s = s;
		this->d = d;
	}

	void setRandevuID(int x) { randevuID = x; }
	void setRhastaID(int x) { rhastaID = x; }
	void setRdoktorID(int x) { rdoktorID = x; }
	void setRpoliklinikID(int x) { rpoliklinikID = x; }
	void setTarih(string x) { tarih = x; }
	void setSaat(string x) { saat = x; }

	int getRandevuID() { return randevuID; }
	int getRhastaID() { return rhastaID; }
	int getRdoktorID() { return rdoktorID; }
	int getRpoliklinikID() { return rpoliklinikID; }
	string getTarih() { return tarih; }
	string getSaat() { return saat; }
	int getS() { return s; }
	int getD() { return d; }

	void print() {
		cout << "Randevu ID : " << randevuID
			<< "  Hasta ID : " << rhastaID
			<< "  Doktor ID : " << rdoktorID
			<< "  Poliklinik ID : " << rpoliklinikID
			<< "  Tarih : " << tarih
			<< "  Tam Saat : " << saat 
			<< "  Saat : " << s
			<< "  Dakika : " << d
			<< endl;
	}
};


bool anadongu = 1;

vector <hasta> hastaV;
vector <poliklinik> poliklinikV;
vector <doktor> doktorV;
vector <randevu> randevuV;

void PoliklinikSirala() {
	system("cls");
	bool dongu = 1;
	while (dongu) {
		cout << "Polikliniði hangi sira ile siralamak istersiniz. Lutfen yapicaginiz islemi seciniz" << endl;
		cout << "  1  :  Poliklinik ID " << endl;
		cout << "  2  :  Bolum" << endl;
		cout << "  3  :  Is baslama saati" << endl;
		cout << "  4  :  Is bitis saati" << endl;
		cout << endl;
		cout << "  0  :  Ana Menu'ye donmek icin" << endl;

		int menu;
		cin >> menu;
		switch (menu) {
		case 0:
			system("cls");
			dongu = 0;
			break;
		case 1:
			
			for (int i = 0;i < poliklinikV.size();i++)
				for (int j = 0; j < poliklinikV.size() - i - 1; j++)
					if (poliklinikV[j].getpoliklinikID() > poliklinikV[j + 1].getpoliklinikID())
						swap(poliklinikV[j], poliklinikV[j + 1]);
			system("cls");
			for (int i = 0; i < poliklinikV.size();i++) {
				poliklinikV[i].print();
			}
			cout << endl;
			cout << endl;
			break;

		case 2:
			
			for (int i = 0;i < poliklinikV.size();i++)
				for (int j = 0; j < poliklinikV.size() - i - 1; j++)
					if (poliklinikV[j].getbolum() > poliklinikV[j + 1].getbolum())
						swap(poliklinikV[j], poliklinikV[j + 1]);
			system("cls");
			for (int i = 0; i < poliklinikV.size();i++) {
				poliklinikV[i].print();
			}
			cout << endl;
			cout << endl;
			break;

		case 3:
			
			for (int i = 0;i < poliklinikV.size();i++)
				for (int j = 0; j < poliklinikV.size() - i - 1; j++)
					if (poliklinikV[j].getisBaslamaSaati() > poliklinikV[j + 1].getisBaslamaSaati())
						swap(poliklinikV[j], poliklinikV[j + 1]);
			system("cls");
			for (int i = 0; i < poliklinikV.size();i++) {
				poliklinikV[i].print();
			}
			cout << endl;
			cout << endl;
			break;

		case 4:
			
			for (int i = 0;i < poliklinikV.size();i++)
				for (int j = 0; j < poliklinikV.size() - i - 1; j++)
					if (poliklinikV[j].getisBitisSaati() > poliklinikV[j + 1].getisBitisSaati())
						swap(poliklinikV[j], poliklinikV[j + 1]);
			system("cls");
			for (int i = 0; i < poliklinikV.size();i++) {
				poliklinikV[i].print();
			}
			cout << endl;
			cout << endl;
			break;

		default:
			system("cls");
			cout << "Lutfen gecerli bir sayi giriniz" << endl;
			cout << endl;
			dongu = 1;
			break;
		}
	}
}
void DoktorSirala() {
	system("cls");
	bool dongu = 1;
	while (dongu) {
		cout << "Doktor hangi sira ile siralamak istersiniz. Lutfen yapicaginiz islemi seciniz" << endl;
		cout << "  1  :  DoktorID " << endl;
		cout << "  2  :  doktor tc'si" << endl;
		cout << "  3  :  doktor adi" << endl;
		cout << "  4  :  doktor soy adi" << endl;
		cout << "  5  :  doktorun polikliniginin adi" << endl;
		cout << endl;
		cout << "  0  :  Ana Menu'ye donmek icin" << endl;

		int menu;
		cin >> menu;
		switch (menu) {
		case 0:
			system("cls");
			dongu = 0;
			break;
		case 1:

			for (int i = 0;i < doktorV.size();i++)
				for (int j = 0; j < doktorV.size() - i - 1; j++)
					if (doktorV[j].getdoktorID() > doktorV[j + 1].getdoktorID())
						swap(doktorV[j], doktorV[j + 1]);
			system("cls");
			for (int i = 0; i < doktorV.size();i++) {
				doktorV[i].print();
			}
			cout << endl;
			cout << endl;
			break;
		case 2:

			for (int i = 0;i < doktorV.size();i++)
				for (int j = 0; j < doktorV.size() - i - 1; j++)
					if (doktorV[j].gettc() > doktorV[j + 1].gettc())
						swap(doktorV[j], doktorV[j + 1]);
			system("cls");
			for (int i = 0; i < doktorV.size();i++) {
				doktorV[i].print();
			}
			cout << endl;
			cout << endl;
			break;
		case 3:

			for (int i = 0;i < doktorV.size();i++)
				for (int j = 0; j < doktorV.size() - i - 1; j++)
					if (doktorV[j].getad() > doktorV[j + 1].getad())
						swap(doktorV[j], doktorV[j + 1]);
			system("cls");
			for (int i = 0; i < doktorV.size();i++) {
				doktorV[i].print();
			}
			cout << endl;
			cout << endl;
			break;
		case 4:

			for (int i = 0;i < doktorV.size();i++)
				for (int j = 0; j < doktorV.size() - i - 1; j++)
					if (doktorV[j].getsoyAd() > doktorV[j + 1].getsoyAd())
						swap(doktorV[j], doktorV[j + 1]);
			system("cls");
			for (int i = 0; i < doktorV.size();i++) {
				doktorV[i].print();
			}
			cout << endl;
			cout << endl;
			break;


		case 5:

			for (int i = 0;i < doktorV.size();i++)
				for (int j = 0; j < doktorV.size() - i - 1; j++)
					if (doktorV[j].getpoli().getbolum() > doktorV[j + 1].getpoli().getbolum())
						swap(doktorV[j], doktorV[j + 1]);
			system("cls");
			for (int i = 0; i < doktorV.size();i++) {
				doktorV[i].print();
			}
			cout << endl;
			cout << endl;
			break;

		default:
			system("cls");
			cout << "Lutfen gecerli bir sayi giriniz" << endl;
			cout << endl;
			dongu = 1;
			break;
		}
	}
}
void HastaSirala() {
	system("cls");
	bool dongu = 1;
	system("color 72");
	while (dongu) {
		cout << "Hastalari hangi sira ile siralamak istersiniz. Lutfen yapicaginiz islemi seciniz" << endl;
		cout << "  1  :  hastaID " << endl;
		cout << "  2  :  hasta tc'si" << endl;
		cout << "  3  :  hasta adi" << endl;
		cout << "  4  :  hasta soy adi" << endl;
		cout << endl;
		cout << "  0  :  Ana Menu'ye donmek icin" << endl;

		int menu;
		cin >> menu;
		switch (menu) {
		case 0:
			system("cls");
			dongu = 0;
			break;
		case 1:

			for (int i = 0;i < hastaV.size();i++)
				for (int j = 0; j < hastaV.size() - i - 1; j++)
					if (hastaV[j].gethastaID() > hastaV[j + 1].gethastaID())
						swap(hastaV[j], hastaV[j + 1]);
			system("cls");
			for (int i = 0; i < hastaV.size();i++) {
				hastaV[i].print();
			}
			cout << endl;
			cout << endl;
			break;
		case 2:
			for (int i = 0;i < hastaV.size();i++)
				for (int j = 0; j < hastaV.size() - i - 1; j++)
					if (hastaV[j].gettc() > hastaV[j + 1].gettc())
						swap(hastaV[j], hastaV[j + 1]);
			system("cls");
			for (int i = 0; i < hastaV.size();i++) {
				hastaV[i].print();
			}
			cout << endl;
			cout << endl;
			break;
		case 3:
			for (int i = 0;i < hastaV.size();i++)
				for (int j = 0; j < hastaV.size() - i - 1; j++)
					if (hastaV[j].getad() > hastaV[j + 1].getad())
						swap(hastaV[j], hastaV[j + 1]);
			system("cls");
			for (int i = 0; i < hastaV.size();i++) {
				hastaV[i].print();
			}
			cout << endl;
			cout << endl;
			break;
		case 4:
			for (int i = 0;i < hastaV.size();i++)
				for (int j = 0; j < hastaV.size() - i - 1; j++)
					if (hastaV[j].getsoyAd() > hastaV[j + 1].getsoyAd())
						swap(hastaV[j], hastaV[j + 1]);
			system("cls");
			for (int i = 0; i < hastaV.size();i++) {
				hastaV[i].print();
			}
			cout << endl;
			cout << endl;
			break;

		default:
			system("cls");
			cout << "Lutfen gecerli bir sayi giriniz" << endl;
			cout << endl;
			dongu = 1;
			break;
		}
	}
}
void kayitSiralaMenu() {
	bool dongu = 1;
	system("color 72");
	while (dongu) {
		cout << "kayit siralama sistemine hos geldiniz. Lutfen yapicaginiz islemi seciniz" << endl;
		cout << "  1  :  hasta kayitlarini siralamak icin " << endl;
		cout << "  2  :  doktor kayitlarini siralamak icin" << endl;
		cout << "  3  :  poliklinik kayitlarini siralamak icin" << endl;
		cout << endl;
		cout << "  0  :  Ana Menu'ye donmek icin" << endl;

		int menu;
		cin >> menu;
		switch (menu) {
		case 0:
			system("cls");
			dongu = 0;
			break;
		case 1:
			HastaSirala();
			dongu = 0;
			break;
		case 2:
			DoktorSirala();
			dongu = 0;
			break;
		case 3:
			PoliklinikSirala();
			dongu = 0;
			break;

		default:
			system("cls");
			cout << "Lutfen gecerli bir sayi giriniz" << endl;
			cout << endl;
			dongu = 1;
			break;
		}
	}
}

void PoliklinikKayit() {
	system("cls");
	bool kontrol = 1;
	string tctemp;
	string adtemp;
	string soyAdtemp;
	string temp;
	int hastaidtemp;

	hasta hastatemp;

	while (kontrol) {
		cout << "Hasta Tc'sini giriniz :" << endl;

		getline(cin >> ws, temp);
		int rakamsayisi = 0;
		if (temp.size() == 11) {
			for (int i = 0; i < temp.size();i++) {
				if (isdigit(temp[i]))  // isdigit (ctype.h) fonksiyonu karakter rakam degilse 0 verir
					rakamsayisi++;
			}
			if (rakamsayisi == 11) {
				hastatemp.settc(temp);
				temp.clear();
				kontrol = 0;
			}
			else { system("cls"); cout << "Lutfen deðerleri sayi olarak giriniz" << endl; }
		}
		else { system("cls"); cout << "Lutfen 11 haneli veri giriniz" << endl; }
	}
	kontrol = 0;

	cout << "--------Tc kaydedildi" << endl;

	cout << "Hasta Ad'ini giriniz :" << endl;
	getline(cin >> ws, temp);
	hastatemp.setad(temp);
	cout << "--------Ad kaydedildi" << endl;
	temp.clear();

	cout << "Hasta Soy Ad'ini giriniz :" << endl;
	getline(cin >> ws, temp);
	hastatemp.setsoyAd(temp);
	cout << "--------Ad kaydedildi" << endl;
	temp.clear();

	for (int i = 0;i < hastaV.size();i++)
		for (int j = 0; j < hastaV.size() - i - 1; j++)
			if (hastaV[j].gethastaID() > hastaV[j + 1].gethastaID())
				swap(hastaV[j], hastaV[j + 1]);

	hastatemp.sethastaID(hastaV.size() + 1);

	hastaV.push_back(hastatemp);
	system("cls");
	cout << "+++++++++++++++++++++ Hasta  kaydedildi" << endl;
}
void HastaKayit() {
	system("cls");
	bool kontrol = 1;
	string tctemp;
	string adtemp;
	string soyAdtemp;
	string temp;
	int hastaidtemp;

	hasta hastatemp;

	while (kontrol) {
		cout << "Hasta Tc'sini giriniz :" << endl;
		
		getline(cin >> ws, temp);
		int rakamsayisi = 0;
		if (temp.size() == 11) {
			for (int i = 0; i < temp.size();i++) {
				if (isdigit(temp[i]))  // isdigit (ctype.h) fonksiyonu karakter rakam degilse 0 verir
					rakamsayisi++;
			}
			if (rakamsayisi == 11) {
				hastatemp.settc(temp);
				temp.clear();
				kontrol = 0;
			}
			else { system("cls"); cout << "Lutfen deðerleri sayi olarak giriniz" << endl; }
		}
		else { system("cls"); cout << "Lutfen 11 haneli veri giriniz" << endl;}
	}
	kontrol = 0;

	cout << "--------Tc kaydedildi" << endl;

	cout << "Hasta Ad'ini giriniz :" << endl;
	getline(cin >> ws, temp);
	hastatemp.setad(temp);
	cout << "--------Ad kaydedildi" << endl;
	temp.clear();

	cout << "Hasta Soy Ad'ini giriniz :" << endl;
	getline(cin >> ws, temp);
	hastatemp.setsoyAd(temp);
	cout << "--------Ad kaydedildi" << endl;
	temp.clear();
	
	for (int i = 0;i < hastaV.size();i++)
		for (int j = 0; j < hastaV.size() - i - 1; j++)
			if (hastaV[j].gethastaID() > hastaV[j + 1].gethastaID())
				swap(hastaV[j], hastaV[j + 1]);

	hastatemp.sethastaID(hastaV.size() + 1);
	
	hastaV.push_back(hastatemp);
	system("cls");
	cout << "+++++++++++++++++++++ Hasta  kaydedildi" << endl;
}
void kayitMenu() {
	bool dongu = 1;
	system("color 7D");
	while (dongu) {
		cout << "kayit sistemine hos geldiniz. Lutfen yapicaginiz islemi seciniz" << endl;
		cout << "  1  :  Yeni hasta kayiti yapmak icin " << endl;
		cout << "  2  :  Yeni doktor kayiti yapmak icin" << endl;
		cout << "  3  :  Yeni poliklinik Kayiti yapmak icin" << endl;
		cout << endl;
		cout << "  0  :  Ana Menu'ye donmek icin" << endl;

		int menu;
		cin >> menu;
		switch (menu) {
		case 0:
			system("cls");
			dongu = 0;
			break;
		case 1:
			HastaKayit();
			dongu = 0;
			break;
		case 2:

			dongu = 0;
			break;
		case 3:

			dongu = 0;
			break;

		default:
			system("cls");
			cout << "Lutfen gecerli bir sayi giriniz" << endl;
			cout << endl;
			dongu = 1;
			break;
		}
	}
}

void AnaMenu(){
	bool dongu = 1;
	system("color 71");
	while (dongu) {
	cout << "Sistemine hos geldiniz. Lutfen yapicaginiz islemi seciniz" << endl;
	cout << "  1  :  Kayit yapmak icin " << endl;
	cout << "  2  :  Kayit siralamak icin" << endl;
	cout << "  3  :  Randevu olusturmak icin" << endl;
	cout << endl;
	cout << "  0  :  Programi kapamak icin" << endl;
	int menu;
	cin >> menu;
		switch (menu) {
		case 0:
			system("cls");
			anadongu = 0;
			dongu = 0;
			break;
		case 1:
			system("cls");
			kayitMenu();
			dongu = 0;
			break;
		case 2:
			system("cls");
			kayitSiralaMenu();
			dongu = 0;
			break;
		case 3:

			dongu = 0;
			break;

		default:
			system("cls");
			cout << "Lutfen gecerli bir sayi giriniz" << endl;
			cout << endl;
			dongu = 1;
			break;
		}
	}
}

void splitForHasta(hasta& b, string satir)
{
	int p1 = satir.find(':');
	int p2 = satir.find(":", p1 + 1);
	int p3 = satir.find(":", p2 + 1);
	int p4 = satir.size() - 1;
	b.setAll(satir.substr(0, p1), satir.substr(p1 + 1, p2 - p1-1), satir.substr(p2 + 1, p3 - p2-1), stoi(satir.substr(p3 + 1, p4 - p3)));
}
poliklinik bolumilepoliCagirici(string x) {
	for (int i = 0; i < poliklinikV.size();i++) {
		if (poliklinikV[i].getbolum() == x) {
			return poliklinikV[i];
		}
	}

	poliklinik temp(0, "BOYLE BIR POLIKLINIK YOK", 0, 0);
	return temp;
}
void splitForDoktor(doktor& b, string satir)
{
	int p1 = satir.find(':');
	int p2 = satir.find(":", p1 + 1);
	int p3 = satir.find(":", p2 + 1);
	int p4 = satir.find(":", p3 + 1);
	int p5 = satir.size() - 1;

	b.setAll(satir.substr(0, p1), satir.substr(p1 + 1, p2 - p1 - 1), satir.substr(p2 + 1, p3 - p2 - 1), stoi(satir.substr(p3 + 1, p4 - p3 -1)), bolumilepoliCagirici(satir.substr(p4 + 1, p5 - p4)));
}
void splitForPoliklinik(poliklinik& b, string satir)
{
	int p1 = satir.find(':');
	int p2 = satir.find(":", p1 + 1);
	int p3 = satir.find(":", p2 + 1);
	int p4 = satir.size() - 1;

	b.setAll(stoi(satir.substr(0, p1)), satir.substr(p1 + 1, p2 - p1 - 1), stoi(satir.substr(p2 + 1, p3 - p2 - 1)), stoi(satir.substr(p3 + 1, p4 - p3 )));
}
void splitForRandevu(randevu& b, string satir)
{
	int p1 = satir.find(':');
	int p2 = satir.find(":", p1 + 1);
	int p3 = satir.find(":", p2 + 1);
	int p4 = satir.find(":", p3 + 1);
	int p5 = satir.find(":", p4 + 1);
	int p6 = satir.find(":", p5 + 1);
	int p7 = satir.find(":", p6 + 1);
	int p8 = satir.size() - 1;
	
	//1:2:3:4:30/07:30/07:22:5

	b.setAll(stoi(satir.substr(0, p1)), 
			stoi(satir.substr(p1 + 1, p2 - p1 - 1)), 
			stoi(satir.substr(p2 + 1, p3 - p2 - 1)), 
			stoi(satir.substr(p3 + 1, p4 - p3 - 1)),
			satir.substr(p4 + 1, p5 - p4 - 1),
			satir.substr(p5 + 1, p6 - p5 - 1),
			stoi(satir.substr(p6 + 1, p7 - p6 - 1)),
			stoi(satir.substr(p7 + 1, p8 - p7))
	);


}

void hastaReadFile(vector<hasta>& b, string fileName) {
	string satir;
	hasta temp;
	ifstream myFile;
	myFile.open(fileName);
	if (myFile.is_open())
	{
		while (!myFile.eof())
		{
			getline(myFile, satir);

			if (satir.size() > 10)
			{
				splitForHasta(temp, satir);
				b.push_back(temp);
			}
		}
	}
}
void doktorReadFile(vector<doktor>& b, string fileName) {
	string satir;
	doktor temp;
	ifstream myFile;
	myFile.open(fileName);
	if (myFile.is_open())
	{
		while (!myFile.eof())
		{
			getline(myFile, satir);

			if (satir.size() > 10)
			{
				splitForDoktor(temp, satir);
				b.push_back(temp);
			}
		}
	}
}
void randevuReadFile(vector<randevu>& b, string fileName) {
	string satir;
	randevu temp;
	ifstream myFile;
	myFile.open(fileName);
	if (myFile.is_open())
	{
		while (!myFile.eof())
		{
			getline(myFile, satir);

			if (satir.size() > 10)
			{
				splitForRandevu(temp, satir);
				b.push_back(temp);
			}
		}
	}
}
void poliklinikReadFile(vector<poliklinik>& b, string fileName) {
	string satir;
	poliklinik temp(1234, "emre", 22, 5);
	ifstream myFile;
	myFile.open(fileName);
	if (myFile.is_open())
	{
		while (!myFile.eof())
		{
			getline(myFile, satir);

			if (satir.size() > 10)
			{
				splitForPoliklinik(temp, satir);
				b.push_back(temp);
			}
		}
	}
}

void hastafillFile(vector<hasta> b, string fileName)
{
	ofstream myFile(fileName);
	string ayrac = ":";
	
	for (int i = 0; i < b.size(); i++)
	{
		myFile << b[i].gettc() << ayrac << b[i].getad() << ayrac
			<< b[i].getsoyAd() << ayrac << b[i].gethastaID() 
			<< endl;
	}

	myFile.close();
}
void doktorFillFile(vector<doktor> b, string fileName)
{
	ofstream myFile(fileName);
	string ayrac = ":";

	for (int i = 0; i < b.size(); i++)
	{
		myFile << b[i].gettc() << ayrac << b[i].getad() << ayrac
			<< b[i].getsoyAd() << ayrac << b[i].getdoktorID() << ayrac << b[i].getpoli().getbolum() << endl;
	}

	myFile.close();
}
void poliklinikFillFile(vector<poliklinik> b, string fileName)
{
	ofstream myFile(fileName);
	string ayrac = ":";

	for (int i = 0; i < b.size(); i++)
	{
		myFile << b[i].getpoliklinikID() << ayrac << b[i].getbolum() << ayrac << b[i].getisBaslamaSaati()
			<< ayrac << b[i].getisBitisSaati() << endl;
	}

	myFile.close();
}
void randevuFillFile(vector<randevu> b, string fileName)
{
	ofstream myFile(fileName);
	string ayrac = ":";

	for (int i = 0; i < b.size(); i++)
	{
		myFile << b[i].getRandevuID() << ayrac 
			<< b[i].getRhastaID() << ayrac 
			<< b[i].getRdoktorID() << ayrac
			<< b[i].getRpoliklinikID() << ayrac
			<< b[i].getTarih() << ayrac
			<< b[i].getSaat() << ayrac
			<< b[i].getS() << ayrac
			<< b[i].getD() << endl;
	}

	myFile.close();
}

int main()
{
	hastaReadFile(hastaV, "Hastalar");
	hastafillFile(hastaV, "Hastalar");

	poliklinikReadFile(poliklinikV, "Poliklinikler");
	poliklinikFillFile(poliklinikV, "Poliklinikler");

	doktorReadFile(doktorV, "Doktorlar");
	doktorFillFile(doktorV, "Doktorlar");

	randevuReadFile(randevuV, "Randevular");
	randevuFillFile(randevuV, "Randevular");
	

	while (anadongu) {
		AnaMenu();
	}

	return 0;
}
