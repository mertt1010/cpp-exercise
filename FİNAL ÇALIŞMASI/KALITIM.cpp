#include<string>
#include<iostream>
using namespace std;

class human{
	protected:
	string name;
	string surname;
	string gender;
public:
	human(){}
    human(string name,string surname , string gender)
    {
    
    	this ->name=name;
    	this ->surname=surname;
    	this ->gender=gender;
	}
	
	void print(){
		cout<<" name:"<<name<<" surname:"<<surname<<" gender:"<<gender;
	}
	
    string getname(){return name;}
    string getsurname(){return surname;}
    string getgender(){return gender;}

    void setname(string name){name=name;}
    void setsurname(string surname){surname=surname;}
    void setgender(string gender){gender=gender;}
 
};

class student : public human{
	private:
	string department;
	string id;
	public:
		student(){}
		student(string name,string surname,string gender,string department,string id):human(name,surname,gender)
		{
			this -> department=department;
			this -> id=id;
		}
		
		string getdepartment(){return department;}
		string getid(){return id;}
		
		void setdepartment(string department){department=department;}
		void setid(string id){id=id;}
		
		void prints(){
			cout<<"name:"<<name<<" surname:"<<surname<<" gender:"<<gender<<" department:"<<department<<" id:"<<id;
		}
		
};


class isci : public human{
	private:
		string sosno;
		string maas;
		public:
			isci(){}
			isci(string name,string surname,string gender,string sosno,string maas):human(name,surname,gender)
			{
				this -> sosno=sosno;
				this -> maas=maas;
			}
			
			string getsosno(){return sosno;}
			string getmaas(){return maas;}
			
			void setsosno(string sosno){sosno=sosno;}
			void setmaas(string maas){maas=maas;}
			
			void printm(){
				cout<<"name:"<<name<<" surname:"<<surname<<" gender:"<<gender<<" sosno:"<<sosno<<" maas:"<<maas;
			}
};





int main(){
	human h1("mert","tosun","erkek");
	h1.print();
	
	cout<<endl;
  
   student s1("alper","karacam","erkek","maliye","1903");
   s1.prints();
   cout<<endl;
   isci i1("mahir","unal","erkek","123","4250");
   i1.printm();
	
}
