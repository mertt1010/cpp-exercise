#include<iostream>
#include<stdexcept>
#include<exception>
using namespace std;
int main(){

try {
  int age = 19;
  if (age >= 18) {
    cout << "izin verildi yas gecerli.";
  } else {
    throw (age);
  }
}

catch(int number){
	
	cout <<"en az 18 yasinda olmalisiniz ";
	cout<<"yas: "<<number<<endl;
}
return 0;
}
