#include<iostream>
#include<stdexcept>
#include<exception>
using namespace std;

int main(){
	
	try{
		int age=30;
		if(age>=20){
			cout<<"gecis basarili.";
		}
		else
		throw 505;
	}
	catch(...){
		cout<<"giris basarisiz. "<<endl;
	}
	
}
