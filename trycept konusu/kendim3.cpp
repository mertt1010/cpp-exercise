#include<iostream>
#include<stdexcept>
#include<exception>
using namespace std;

int main(){
	
	try{
	int age=15;
	if(age>=18){
		cout<<"gecis izni verildi.";
	}	
	else
	throw 404;
	}
	
	catch(int number){
	
	cout<<"basarisiz yasin kucuk"<<endl;
	cout<<"hata "<<number;
		
	}
	
	
	
	
	
}

