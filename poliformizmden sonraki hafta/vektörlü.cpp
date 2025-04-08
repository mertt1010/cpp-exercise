#include <iostream>
using namespace std;


class vector
{
private:
float x;
float y;
float z;



friend ostream& operator <<(ostream& output, vector& v);
friend istream& operator >>(istream& input, vector& v);



public:





vector()
{
x = 0;
y = 0;
z = 0;
}





vector(float x, float y, float z)
{
this->x = x;
this->y = y;
this->z = z;
}





void setAll(float x, float y, float z)
{
this->x = x;
this->y = y;
this->z = z;
}





void setX(float x)
{
this->x = x;
}





void setY(float y)
{
this->y = y;
}





void setZ(float z)
{
this->z = z;
}





float getX () {
return x;
}





float getY () {
return y;
}





float getZ () {
return z;
}



void add(vector v122,vector v244)
{
this->x= v122.getX() + v244.getX(); //x=v122.getX + v244.getX þeklinde de yapabilirsin sadece belirtmek icin kullanýlýyor
this->y= v122.getY() + v244.getY();
this->z= v122.getZ() + v244.getZ();
}





void mult(vector v122, vector v244)
{
this->x= v122.getX() * v244.getX();
this->y= v122.getY() * v244.getY();
this->z= v122.getZ() * v244.getZ();
}



void add(vector v244)
{
this->x = x + v244.getX();
this->y = y + v244.getY();
this->z = z + v244.getZ();
}





void mult(vector v244)
{
this->x = x * v244.getX();
this->y = y * v244.getY();
this->z = z * v244.getZ();
}





void print()
{
cout << "X degeri : " << x << " " << "Y degeri : " << y << " " << "Z degeri : " << z << endl;



}
// 7 haziranda yazdýklarýmýz ::----------------->>>>>>>>>>>>>>>>>>>>
vector operator = ( vector v ) {



x = v.x;
y = v.y;
z = v.z;



return *this;
}



vector operator + (vector v) {
return vector(x+v.x,y+v.y,z+v.z);
/*
bir ustteki kod aslýnda bunu yapýyor:
vektor temp
temp x=x+v.x;
temp y=y+v.y;
temp z=z+v.z;
return temp;

*/


}



vector operator - (vector v){
return vector(x-v.x,y-v.y,z-v.z);
}
//once arttýrýyor sonra atamasýný yapýyor
vector operator ++(){ // ++v1 seklinde;
return vector(++x,++y,++z);
}



vector operator ++(int){ //v2++ seklinde
return vector(x++,y++,z++);
}



};
ostream& operator<<(ostream& output, vector& v)
{
cout<<v.getX()<<"+"<<v.getY()<<"+"<<v.getZ()<<endl;
return output;
}
istream& operator>>(istream& input, vector& v)
{
cin>>v.x>>v.y>>v.z;
return input;
}





class point
{
private:
int x, y;
public:
float distance(point p)
{


}



};





int main()
{

cout<<"\n\n deneme 1:";
vector v111(5,4,2);
vector v222(-2,5,7);
vector v333;
v333=v111+v222;
v333.print();



vector v444;
v444=v111-v222;
cout<<endl;
v444.print();



cout<<"\n\n";
cout<<v111;



vector v1(1.0, 2.0, 3.0);





vector v2(5.0, 4.0, 3.0);





vector v3, v4, v5, v6, v7;




v3.add(v1, v2); //v1 ile v2 yi topla v3 e esitle



cout << "v3 vektoru : ";



v3.print();



v4.mult(v1, v2);



cout << "v4 vektoru : ";



v4.print();



v5.setAll(10.0, 10.0, 10.0);


v5.add(v1); //v5 ile v1 i topla v5 e esitle




cout << "v5 vektoru : ";


v5.print();



v6.mult(v2);



cout << "v6 vektoru : ";



v6.print();



v6.setX(5.0);



v6.mult(v2);



cout << "v6 vektoru : ";


v6.print();



v6.setY(3.0);


v6.mult(v2);


cout << "v6 vektoru : ";


v6.print();


v6.setZ(25.0);


v6.mult(v2);



cout << "v6 vektoru : ";



v6.print();


v7 = v2;


v7.print();






return 0;
}
