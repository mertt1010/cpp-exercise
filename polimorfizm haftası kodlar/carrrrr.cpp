//polimorfizm haftasý attý 31 mayýs 

 
#include <cstdlib>
#include <iostream>
#include <string>
#include <time.h>
using namespace std;

 
void sleep(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}
class car{
private:
        int speed;
        int rpm;
        int engineIsOn;
        int CC;
        int gear;
        int topSpeed;
        string brand;
        string model;
public:
       car()
       {
            speed=0;
            topSpeed=0;
            rpm=0;
            engineIsOn=0;
            CC=0;
            gear=0;
            brand="car";
            model="XXX";    
       }
       car(string b,string m,int tS,int c)
       {
            speed=0;
            if(tS%5!=0)
                tS=tS-(tS%5);
            topSpeed=tS;
            rpm=0;
            engineIsOn=0;
            CC=c;
            gear=0;
            brand=b;
            model=m;    
            cout<<"A new car is created"<<endl;
            cout<<"It is a "<<brand<<" "<<model<<endl;
            cout<<"It is "<<CC<<"CC"<<endl;
            cout<<"Top Speed is "<<topSpeed<<" km/h"<<endl;
       }
       ~car(){}
       void startEngine()
       {
            if(engineIsOn==0)
            {
               engineIsOn=1;
               rpm=800;
               cout<<"Engine is started!!!"<<endl;
            }
       }
       void stopEngine()
       {
            if(speed==0)
            {
                engineIsOn=0;
                rpm=0;
                cout<<"Engine is stopped!!!"<<endl;
            }
       }
	   void printReport()
	   {
		   cout<<"Gear  : "<<gear<<endl;
		   cout<<"Speed : "<<speed<<endl;
		   cout<<"RPM   : "<<rpm<<endl;
		   cout<<"_________________"<<endl;

	   }
       void accelerateUp()
       {
            if(engineIsOn)
            {
                if(speed==0)
                    gearUp();
                else if(speed==(topSpeed/5))
                     gearUp();
                else if(speed==((topSpeed/5)*2))
                     gearUp();
                else if(speed==((topSpeed/5)*3))
                     gearUp();
                else if(speed==((topSpeed/5)*4))
                     gearUp();
                if(speed<topSpeed)
                {
					for(int i=0;i<5;i++)
					 {
						 sleep(500);
						 speed++;
						 rpm+=50;
						 printReport();
					 }
                }          
            }
       }
       void accelerateDown()
       {
            if(engineIsOn)
            {
                if(speed==(topSpeed/5-20))
                     gearDown();
                else if(speed==((topSpeed/5)*2-20))
                     gearDown();
                else if(speed==((topSpeed/5)*3-20))
                     gearDown();
                else if(speed==((topSpeed/5)*4-20))
                     gearDown();
                if(speed>0)
                {
					 for(int i=0;i<5;i++)
					 {
						 sleep(500);
						 speed--;
						 rpm-=50;
						 printReport();
						 if(speed==1)
							gearDown();
					 }
                }
                              
            }
       }
       void gearUp()
       {
            if(engineIsOn)
            {
                if(gear<5)
                {
                   gear++;
                   rpm=(gear==1)?800:1500;
                }
            }
            cout<<"Gear is UPED!!! and now gear is "<<gear<<" RPM is "<<rpm<<endl;
            cout<<"///_________________///"<<endl;
       }
       void gearDown()
       {
            if(engineIsOn)
            {
                if(speed==0)
                {
                    gear=0;
                    rpm=800;
                }
                else if(gear>1)
                {
                    gear--;
                    rpm=2500;
                }
                else if(gear==1)
                {
                    gear--;
                    rpm=800;
                }
                cout<<"Gear is DOWNED!!! and now gear is "<<gear<<" RPM is "<<rpm<<endl;
                cout<<"///_________________///"<<endl;
            }
       }
        
              
};

int main()
{
	car c1("BMW","320i",200,2000);
    c1.startEngine();
    for(int i=0;i<10;i++)
        c1.accelerateUp();
    for(int i=0;i<10;i++)
        c1.accelerateDown();
    c1.stopEngine();
    system("PAUSE");
	return 0;
}

