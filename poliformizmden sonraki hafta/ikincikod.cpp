#include<iostream>
using namespace std;

template<class T>
void swap(T* x, T* y)
{
	T temp;
	temp=x;
	x=y;
	y=temp;
}

int main(){
	float a,b;
	a=4;
	b=8;
	
	float k,l;
	k=3.5;
	l=2.8;
	
	swap(a,b);
	cout<<"a: "<<a<<endl<<"b: "<<b<<endl;
	swap(k,l);
	cout<<"k: "<<k<<endl<<"l: "<<l<<endl;
}
