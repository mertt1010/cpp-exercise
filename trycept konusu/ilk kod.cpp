#include <iostream>
#include <stdexcept>
#include <exception>
using namespace std;
// kod b�lme i�lemi yap�yor 

// tehlikeli kodlar try icinde yazilir.(calismama ihtimali olan)

//try : kodu calistirmaya calisiyor , hata verirse throw ediyor (atiyor) ve catch yakal�yor

//catch cal�smayan kodu yakal�yor , hata vermesi gerekiyorsa hata veriyor. veya d�zeltiyor

//quatient: b�l�m  divide: b�lmek numerator:pay  denominator:payda
//e.what()=

class DividedByZeroException:public runtime_error
{
public:
DividedByZeroException():runtime_error(" attempted to divide by zero"){}

};



double quotient(int numerator, int denominator){

if(denominator==0)
throw DividedByZeroException();
return static_cast<double>(numerator)/denominator;
}




int main()
{
int number1,number2;
double result;
cin>>number1>>number2;
try
{
result=quotient(number1,number2);
cout<<"The quotient is: "<<result<<endl;

}
//quotient : b�l�m
//divide : b�lmek
catch(DividedByZeroException& dividedByZeroException)
{
cout<<"Exception accured"<<dividedByZeroException.what()<<endl;
}
//.what() hatay� yazd�r�yor

try
{
	int* myarray=new int [10000000];
}
catch(exception& e)
{
	cout<<"standart exception: "<<e.what()<<endl;
}

return 0;
}
