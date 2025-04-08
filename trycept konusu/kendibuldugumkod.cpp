#include<iostream>
#include<stdexcept>
#include<exception>
using namespace std;

void paydakontrol(float pay , float payda)
{
	if (payda==0)
		throw 37;
	else
	cout<<"sonuc: "<<float(pay)/payda<<endl;
}

int main(){
	
	int pay , payda;
	
	cout<<"----------BOLME ISLEMI-------------"<<endl<<endl;
    
	cout<<"pay giriniz: "<<endl;
    cin>>pay;
    
	cout<<"payda giriniz: "<<endl; 
    cin>>payda;


   try 
   {
   	paydakontrol(pay,payda);
   }
   
   catch(...)//üç nokta sýnýrsýz hata tespit imkaný verir..
   {
   	cout<<"tanimsiz payda sifir olamaz. "<<endl;
   }
return 0;
}
