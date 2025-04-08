#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
using namespace std;

class human{
	protected:
	string name;
	string birth;
	string tc;
	
	public:
		
		human()
		{
		name="mert";
		birth="2003";
		tc=	"523811";
		}
		human(string name,string birth,string tc)
		{
			this -> name=name;
			this -> birth=birth;
			this -> tc=tc;
		}
		
	 void print() //virtual void print
	{
		cout<<"name: "<<name<<endl;
		cout<<"birth: "<<birth<<endl;
		cout<<"tc: "<<tc<<endl;
	}
};



	class student : public virtual human
{
	protected:
		string id;
		string department;
		public:
			student()
			{
				id="1453";
				department="computer engineering";
			}
			student(string name,string birth,string tc,string id,string department):human(name,birth,tc)
			{
				this -> id=id;
				this -> department=department;
			}
			
			void print()
			{
				cout<<"name: "<<name<<endl;
				cout<<"birth: "<<birth<<endl;
				cout<<"tc: "<<tc<<endl;
				cout<<"id: "<<id<<endl;
				cout<<"department: "<<department<<endl;
			}
			string gettype(){return "student";}      //bu satýr ne iþe yarýyor
};
	
	
	
	class employee : public virtual human
	{
	protected:
	string salary;
	public:
	employee()
	{
	 salary ="5200";	
	}	
	employee(string name,string tc,string birth,string id,string department,string salary):human(name,birth,tc)
	{
	this -> salary=salary;	
	}
	void print()
	{
		human::print();
		cout<<"salary: "<<salary<<endl;
	}
	string gettype(){return "employee";}
	};
	
	
	
	
	class instructor:public student,public employee
{
private:
	string faculty;
public:
	instructor()
	{
		faculty="ENG";
	}
	instructor(string name,int birth,string tc,string id,string department,int salary,string faculty)
	{
		this->name=name;
		this -> birth=birth;
		this -> tc=tc;
		this ->id=id;
		this ->department=department;
		this ->salary=salary;
		this ->faculty=faculty;
	}
	void print()
	{
		cout<<"Name :"<<name<<endl;
		cout<<"Birth :"<<birth<<endl;
		cout<<"TC :"<<tc<<endl;
		cout<<"Stu ID :"<<id<<endl;
		cout<<"Department :"<<department<<endl;
		cout<<"Salary :"<<salary<<endl;
		cout<<"Faculty :"<<faculty<<endl;
	}
        string getType(){return "instructor";}
};
	
	
	
	
	class school
	{
		private:
		string schoolnames;
	public:
	
		school()
	{
	schoolnames="marmara";	
	}	
		school(string schoolnames , string name , string id , int salary)
		{
			this -> schoolnames=schoolnames;
		
		}
		void print()
		{
			cout<<"schoolnames: "<<schoolnames<<endl;
	
		}
		string gettype(){return "schoolnames";}
	};
	
	
	
	
	
	
	
	
	
	
		

int main(){
	human h;
	h.print();
	
	cout<<"--------------------------"<<endl;
	
	student s;
	s.print();
	
	cout<<"--------------------------"<<endl;
	
	employee e;
	e.print();
	
	cout<<"--------------------------"<<endl;
	
	instructor i;
	i.print();
	cout<<"-------------------------------------"<<endl;
	//instructor i2("mert",2003,"52381150152","210601027","ceng",4200,"engineering");
	//i2.print();
	
	
	school s1;
	s1.print();
}

