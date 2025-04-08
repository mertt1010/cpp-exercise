#include<iostream>
#include<string>
using namespace std;

class mekan{
	protected:
		string mekanadi;
		float metrekare;
		string kapasite;
		string type;
		public:
			mekan(){type="mekan";}
			mekan(string mekanadi,float metrekare,string kapasite)
			{
				this -> mekanadi=mekanadi;
				this -> metrekare=metrekare;
				this ->kapasite=kapasite;
			}
			
			void print(){
				cout<<"mekanadi:"<<mekanadi<<" metrekare:"<<metrekare<<" kapasite:"<<kapasite<<" mekanturu: "<<type<<endl;
			}
			
			string getmekanadi(){return mekanadi;}
			float getmetrekare(){return metrekare;}
			string getkapasite(){return kapasite;}
			string gettype(){return type;}
			
			void setmekanadi(string mekanadi){this -> mekanadi=mekanadi;}
			void setmetrekare(float metrekare){this -> metrekare=metrekare;}
			void setkapasite(string kapasite){this -> kapasite=kapasite;}
};

class derslik:public mekan{
	private:
	public:	
	derslik(){type="derslik";}
	derslik(string mekanadi,float metrekare,string kapasite)
	{
		this ->mekanadi=mekanadi;
		this ->metrekare=metrekare;
		this ->kapasite=kapasite;
		type="lab";
	}
	
}; 

class office:public mekan{
	private:
	public:
		office(){type="office";}
		office(string mekanadi,float metrekare,string kapasite )
		{
			this ->mekanadi=mekanadi;
			this ->metrekare=metrekare;
			this ->kapasite=kapasite;
			type="office";
		}
};

class ksalonu:public mekan{
	private:
	public:
	ksalonu(){type="ksalonu";}
	ksalonu(string mekanadi,float metrekare,string kapasite)
	{
		this -> mekanadi=mekanadi;
		this -> metrekare=metrekare;
		this -> kapasite=kapasite;
		type="konferans salonu";
	}
};

class kat{
	private:
		vector<mekan> mekanlar;
		string katadi;
		int katno;
		public:
			kat(){katadi="00000000";}
			kat(string katadi,int katno, mekan M1)
			{
				this -> katadi=katadi;
				this ->katno=katno;
				mekanlar.push_back(M1);
			}
			
			void addmekan(mekan M1)
			{
				mekanlar.push_back(M1);
			}
			
			void setkatadi(string katadi){this->katadi=katadi;}
			void setkatno(int katno){this ->katno=katno;}
			
			string getkatadi(){return katadi;}
			int getkatno(){return katno;}
			
			void print(){
				cout<<"katadi:"<<katadi<<endl;
				cout<<"katno:"<<katno<<endl;
				cout<<"------------------------"<<endl;
				for(int i=0; i<mekanlar.size(); i++)
				mekanlar[i].print();
			}
};

class bina{
	private:
		vector<kat> katlar;
		string binaadi;
		public:
			binaadi(){="---------";}
			binaadi(string binaadi,kat K1)
			{
				this ->binaadi=binaadi;
				katlar.push_back(K1);
			}
void print(){
	cout<<"binaadi:"<<binaadi<<endl;
	cout<<"----------------"<<endl;
	for(int i=0; i<katlar.size(); i++){
		katlar[i].print();
	}
}	

void addkat(kat K1){katlar.push_back(K1);}
void setbinaadi(string binaadi){this ->binaadi;}

};

class yerleske{
	private:
		string yAdi;
		string Yadresi;
		int yYolcumu;
		int Ybilgileri;
		vector<bina> binalar;
		public:
		yerleske(){yAdi="----------";}
		yerleske(string yAdi,string yAdresi,int yYolcumu,int yBilgileri,Bina B1)
		{
			this -> yAdi=yAdi;
			this -> yAdresi=yAdresi;
			this -> yYolcumu=yYolcumu;
			this -> yBilgileri=yBilgileri;
			binalar.push_back(B1);
		}
		void addbina(string ){
		binalar.push_back(B1);
		}
		
		void setyAdi(string yAdi){this -> yAdi=yAdi;}
		void setyAdresi(string yAdresi){this -> yAdresi=yAdresi;}
		void setyYolcumu(int yYolcumu){this -> yYolcumu=yYolcumu;}
		void setyBilgileri(int yBilgileri){this->yBilgileri=yBilgileri;}
		
		string getyAdi(){return yAdi;}
		string getyAdresi(){return yAdresi;}
		int getyYolcumu(){return yYolcumu;}
		int getyBilgileri(){return yBilgileri;}	

     void print(){
     	cout<<"yerleske adi:"<<yAdi<<endl;
     	cout<<"yerleske adresi:"<<yAdresi<<endl;
     	cout<<"yerleske yuzolcumu:"<<yYolcumu<<endl;
     	cout<<"yerleske bilgileri:"<<yBilgileri<<endl;
     	cout<<"--------------------";
	 }
	 
	 for(int i=0; i<binalar.size(); i++)
	 {
	 	binalar[i].print();
	 }


};

int main(){
	
	derslik d1("d404",52.4,35);
	d1.print();
	cout<<"******************************"<<endl;
	
	kat k1("kat 4",4,d1);
	k1.print();
	cout<<"************************"<<endl;
    bina b1("e blok",K1);
	b1.print();
	cout<<"*******************************"<<endl;
	
	yerleske y1("goztepe yerleskesi","kadikoy",150,212450120,b1);
	y1.print();
	cout<<"***********************************"<<endl;
		
	uni U1("marmara",y1);
	u1.print();
	
	
}


























































