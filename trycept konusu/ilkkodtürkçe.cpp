#include<iostream>
#include<stdexcept>
#include<exception>
using namespace std;

class sifirabolmeyecalis:public hata
{
public:
	sifirabolmeyecalis():calismahatasi("sifira bolmeye calisti"){}
};

double bolum(int pay ,int payda)
{
	if(payda==0)
	throw sifirabolmeyecalis();
	return static_cast<double>(pay)/payda;
}

int main(){
	int number 1,number 2;
	double sonuc;
	cinn>>"pay giriniz: ">>number 1>>endl;
	cinn>>"payda giriniz: ">>number 2>>endl;
	
	try
	{
		sonuc=bolum(number 1 , number 2);
        cout<<"bolum: "<<sonuc<<endl;
	}
	
	
	catch(sifirabolmeyecalis&Sifirabolmeyecalis)
	{
		cout<<"istisna gerceklesti "<<Sifirabolmeyecalis.what()<<endl;
	}
	// what() hatayý yazdýrýr
	
	try
	{
		int* dizi=new int[100000];
	}
	
	catch(exception& e)
	{
		cout<<"standart istisna: "<<e.what()<<endl;
	}
	
	
	return 0;
}

