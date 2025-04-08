
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
		name="ALI";
		birth=1990;
		tc="5555555555";
	}
	human(string name,int birth,string tc)
	{
		this -> name=name;
		this -> birth=birth;
		this -> tc=tc;
	}
	
	~human(){}
	virtual	void print()
	{
		cout<<setw(15)<<"Name :"<<name<<endl;
		cout<<setw(15)<<"Birth :"<<birth<<endl;
		cout<<setw(15)<<"TC :"<<tc<<endl;
	}
	virtual string getType(){return "human";}
	string getName(){return name;}
	int getBirth(){return birth;}
	string getTc(){return tc;}
    
};

class student : public virtual human
{
protected:
	string id;
	string department;
public:
	student()
	{
		id="11111";
		department="CEN";
	}
	student(string name,int birth,string tc,string id,string department):human(name,birth,tc)
	{
		this ->id=id;
		this ->department=department;
	}
	void print()
	{//human::print();
		cout<<setw(15)<<"Name :"<<name<<endl;
		cout<<setw(15)<<"Birth :"<<birth<<endl;
		cout<<setw(15)<<"TC :"<<tc<<endl;
		cout<<setw(15)<<"Stu ID :"<<id<<endl;
		cout<<setw(15)<<"Department :"<<department<<endl;
	}
	string getType(){return "student";}
};

class employee:public virtual human
{
protected:
	int salary;
public:
	employee()
	{
		salary=0;
	}
	employee(string name,int birth,string tc,int salary):human(name,birth,tc)
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
		cout<<setw(15)<<"Name :"<<name<<endl;
		cout<<setw(15)<<"Birth :"<<birth<<endl;
		cout<<setw(15)<<"TC :"<<tc<<endl;
		cout<<setw(15)<<"Stu ID :"<<id<<endl;
		cout<<setw(15)<<"Department :"<<department<<endl;
		cout<<setw(15)<<"Salary :"<<salary<<endl;
		cout<<setw(15)<<"Faculty :"<<faculty<<endl;
	}
        string getType(){return "instructor";}
};
class school
{
private:
	string name;
	vector<human *> h;
public:
	school(){name="AREL UNIVERSITY";}
	school(string name)
	{
		this->name=name;
	}
	~school(){}

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
	int x=0;
	for(int z=0;z<h.size();z++)
	{
		if(h[z]->getTc()==e.getTc())
			x=1;
	}
	if(x==0)
		h.push_back(&e);
	}
	void addInstructor(instructor &i)
	{
	int x=0;
	for(int z=0;z<h.size();z++)
	{
		if(h[z]->getTc()==i.getTc())
			x=1;
	}
	if(x==0)
		h.push_back(&i);
	}
	void print()
	{
		for(int i=0;i<h.size();i++)
			h[i]->print();
	}
	void deleteStudent(student s)
	{
		int x=1;
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
			int x=1;
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
		int x=1;
		for(int z=0;z<h.size();z++)
		{
			if(h[z]->getTc()==i.getTc())
			{
				h.erase(h.begin()+z);
				break;
			}
		}
	}
	void findStudent(student s)
	{
	int x=0;
	for(int z=0;z<h.size();z++)
	{
		if(h[z]->getTc()==s.getTc())
		cout<<"Bulundu!..."<<endl;
		else
		cout<<"Bulunamadý";
	}

	}
	void findEmployee(employee e)
	{
	int x=0;
	for(int z=0;z<h.size();z++)
	{
		if(h[z]->getTc()==e.getTc())
		cout<<"Bulundu!..."<<endl;
		else
		cout<<"Bulunamadý";
	}

	}
	void findInstructor(instructor i)
	{
	int x=0;
	for(int z=0;z<h.size();z++)
	{
		if(h[z]->getTc()==i.getTc())
		cout<<"Bulundu!..."<<endl;
		else
			cout<<"Bulunamadý";
	}
	}
	void listStudent()
{
	for(int i=0;i<h.size();i++)
	{
		if(h[i]->getType()=="student")
			h[i]->print();
	}
}
	void listEmployee()
{
	for(int i=0;i<h.size();i++)
	{
		if(h[i]->getType()=="employee")
			h[i]->print();
	}
}
	void listInstructor()
{
	for(int i=0;i<h.size();i++)
	{
		if(h[i]->getType()=="instructor")
			h[i]->print();
	}
}
};

int main()
{
	human h;
	human h2("VELI",1990,"85555");
	h.print();
	h2.print();
	
	student s;
	student s2("Mehmet",1999,"8888","555555","EEN");
	s.print();
	//s2.print();
	employee e;
	employee e2("Hasan",1980,"77777",2750);
	//e.print();
	//e2.print();
	human *hhh=new employee("John",1980,"4444",10000);
	//hhh->print();
	human *x[5];
	x[0]=&h;
	x[1]=&s2;
	x[2]=&e2;
	x[3]=hhh;
	x[4]=&h2;/*
	for(int i=0;i<5;i++)
	{
		x[i]->print();
	} */
	/*
	vector<human *> hxd(2);
	hxd[0]=&h;
	hxd[1]=&h2;
	hxd.push_back(&s2);
	hxd.push_back(&e2);
	hxd.push_back(hhh);
	instructor ins("Alex",1977,"1010","999999","CEN",5000,"MMF");
	hxd.push_back(& ins);
	for(int i=0;i<hxd.size();i++)
	{
		hxd[i]->print();
	}
	system("PAUSE");
	*/
	return 0;
}

