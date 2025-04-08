#include <iostream>
using namespace std;


template < class T >
void printarray(T a[], int size){

for (int i=0; i<size; i++){
cout << i << ". eleman: " << a[i] << endl;
}
}



int main(){

int a=5, b=9;

char c='a', d='b';



int x[5] = {9,8,7,6,5} ;
printarray<int>(x,5);

char y[5]={"elma"};
printarray<char>(y,5);


return 0;
}
