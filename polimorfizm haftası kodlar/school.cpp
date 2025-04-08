

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

class human
{
protected:
	string name;
	int birth;
	string tc;
public:
	human()
	{
		name="Ali";
		birth=1990;
		tc="11111111";
	}
	human(string name,int birth,string tc)
	{
		this ->name=name;
		this ->birth=birth;
		this ->tc=tc;
	}
	~human(){cout<<"Destructed human class"<<endl;}
	virtual void print()
	{
		cout<<setw(15)<<"Name :"<<name<<endl;
		cout<<setw(15)<<"Birth :"<<birth<<endl;
		cout<<setw(15)<<"TC No :"<<tc<<endl;
	}
	string getType(){return "human";}
	string getName(){return name;}
	int getBirth(){return birth;}
	string getTc(){return tc;}
};
class student:public virtual human
{
protected:
	string id;
	string department;
public:
	student()
	{
		id="090303003";
		department="CEN";
	}
	student(string name,int birth,string tc,string id,string department):human(name,birth,tc)
	{
		this ->id=id;
		this ->department=department;
	}
	~student(){cout<<"Destructed student class...\n";}
	void print()
	{
		human::print();
		cout<<setw(15)<<"ID :"<<id<<endl;
		cout<<setw(15)<<"Department :"<<department<<endl;
	}
	string getType(){return "student";}
};
class employee:public virtual human
{
protected:
	string salary;
public:
	employee()
	{
		salary="4500";
	}
	employee(string name,int birth,string tc,string salary):human(name,birth,tc)
	{
		this ->salary=salary;
	}
	void print()
	{
		human::print();
		cout<<setw(15)<<"Salary :"<<salary<<endl;
	}
	string getType(){return "employee";}
};
class instructor:public student,public employee
{
protected:
	string faculty;
public:
	instructor()
	{
		faculty="ENG\n";
	}
	instructor(string name,int birth,string tc,string id,string department,string salary,string faculty)
	{
		this->name=name;
		this->birth=birth;
		this->tc=tc;
		this->id=id;
		this->department=department;
		this->salary=salary;
		this->faculty=faculty;
	}
	void print()
	{
		student::print();
		cout<<setw(15)<<"Salary :"<<salary<<endl;
		cout<<setw(15)<<"Faculty :"<<faculty<<endl;
	}
	~instructor(){cout<<"Instructor class destructed!.."<<endl;}
	string getType(){return "instructor";}
};
class school
{
protected:
	string name;
	vector<human *> h;
public:
	school()
	{name="Arel University\n";}
	school(string name)
	{
		this ->name=name;
	}
	~school(){cout<<"School class destructed!..\n";}
	void addStudent(student &s)
	{
		int x=1;
		for(int i=0;i<h.size();i++)
		{
			if(h[i]->getTc()==s.getTc())
			x=0;
		}
		if(x==1)
			h.push_back(&s);
	}
	void addEmployee(employee &e)
	{
		int x=1;
		for(int i=0;i<h.size();i++)
		{
			if(h[i]->getTc()==e.getTc())
				x=0;
		}
		if(x==1)
			h.push_back(&e);
	}
	void addInstructor(instructor &i)
	{
		int x=1;
		for(int j=0;j<h.size();j++)
		{
			if(h[j]->getTc()==i.getTc())
				x=0;
		}
		if(x==1)
			h.push_back(&i);
	}
	void print()
	{
		for(int z=0;z<h.size();z++)
			h[z]->print();
	}
	void deleteStudent(student s)
	{
		for(int i=0;i<h.size();i++)
		{
			if(h[i]->getTc()==s.getTc())
			{
				h.erase(h.begin()+i);
				break;
			}
		}
	}
	void deleteEmployee(employee e)
	{
		for(int i=0;i<h.size();i++)
		{
			if(h[i]->getTc()==e.getTc())
			{
				h.erase(h.begin()+i);
				break;
			}
		}
	}
	void deleteInstructor(instructor i)
	{
		for(int j=0;j<h.size();j++)
		{
			if(h[j]->getTc()==i.getTc())
			{
				h.erase(h.begin()+j);
				break;
			}
		}
	}
	void listStudent()
	{
		for(int i=0;i<h.size();i++)
		{
			if(h[i]->getType()=="student")
			{
				h[i]->print();
			}
		}
	}
	void listEmployee()
	{
		for(int i=0;i<h.size();i++)
		{
			if(h[i]->getType()=="employee")
			{
				h[i]->print();
			}
		}
	}
	void listInstructor()
	{
		for(int j=0;j<h.size();j++)
		{
			if(h[j]->getType()=="instructor")
			{
				h[j]->print();
			}
		}
	}
	void findStudent(student s)
	{
		for(int i=0;i<h.size();i++)
		{
			if(h[i]->getTc()==s.getTc())
			{
				cout<<"Bulundu...";
				h[i]->print();
			}
			else
				cout<<"Bulunamadi...\n";
		}
	}
	void findEmployee(employee e)
	{
		for(int i=0;i<h.size();i++)
		{
			if(h[i]->getTc()==e.getTc())
			{
				cout<<"Bulundu...";
				h[i]->print();
			}
			else
				cout<<"Bulunamadi...\n";
		}
	}
	void findInstructor(instructor i)
	{
		for(int j=0;j<h.size();j++)
		{
			if(h[j]->getTc()==i.getTc())
			{
				cout<<"Bulundu...";
				h[j]->print();
			}
			else
				cout<<"Bulunamadi...\n";
		}
	}
};


int main()
{
	instructor ins("Alex",1977,"1010","999999","CEN","5000","MMF");
	ins.print();
	system("PAUSE");
	return 0;
}

