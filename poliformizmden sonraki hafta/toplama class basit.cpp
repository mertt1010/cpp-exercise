#include<iostream>
#include<cmath>
using namespace std;


class toplama{
	private:
		float sayi;
		public:
			
		toplama()
			{
				sayi=15;
			}

     void operator ++()
     {
     	sayi=sayi+6;
	 }
	 float getsayi(){return sayi;}

};

main(){
	toplama ornek;

    cout << "ornek: " << ornek.getsayi() << endl;

    ++ornek;

    cout << "ornek: " << ornek.getsayi() << endl;

    return 0;
	
	
	
	
	
}
