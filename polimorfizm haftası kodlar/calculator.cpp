

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
static int count;
using namespace std;
int control(string s)
{
	string reg = "0123456789-+*/()";
	int par=0;
	int len=s.length();
	for(int i=0;i<len;i++)
	{
		if(string::npos==reg.find(s[i]))
			return 0;
		if(s[i]=='(')
			par++;
		else if(s[i]==')')
			par--;
		if(par<0)
			return 0;
	}
	if(par!=0)
		return 0;
	return 1;
}
string calc(string s1, string s2, char op)
{
	
	int result;
	int a,b;
	stringstream ss;
	a=atoi(s1.c_str());
	b=atoi(s2.c_str());
	switch (op)
	{
		case '*':
			result=a*b; break;
		case '/':
			if(b!=0)
				result=a/b;
			else
				result=0; break;
		case '+':
			result=a+b; break;
		case '-':
			result=a-b; break;
		default:
			result=0;
	}
	ss<<result;
	return ss.str();
}
string operate(string s)
{
	string op="/*-+";
	string s1,s2,s3;
	int beg=-1;
	int end=-1;
	int target;
	int mul,div;
	int okay=0;
	int findMUL=s.find('*');
	int findDIV=s.find('/');
	int len=s.length();
	int f,l;
	int i;
	int asd;
	while( ((findMUL < len) && findMUL>-1) || ((findDIV <len)  && findDIV>-1) )
	{
		
			mul=s.find('*');
			div=s.find('/');
			if((mul<div||div==-1) && mul>-1)
				target=mul;
			else
				target=div;
			i=target;
			while(beg==-1)
			{	i--;
				f=op.find(s[i]);
				l=op.length();
				if( (f<l && f>0) || i==0)
					beg = i;				
			}
			i=target;
			while(end==-1)
			{
				i++;
				f=op.find(s[i]);
				l=op.length();
				if(f < l && f>0)
					end=i-1;
				else if(i==len-1)
					end=i;
				
			}
			s1=s.substr(beg,target-beg);
			s2=s.substr(target+1,end-target);
			s3=calc(s1,s2,s[target]);
			s.replace(beg,end-beg+1,s3);
			findMUL=s.find('*');
			findDIV=s.find('/');
			len=s.length();
	}
	i=0;
	len=s.length();
	int isOp;
	int hold=-1;
	while(i<len)
	{
		isOp=op.find(s[i]);
		if((s[i]=='+' || s[i]=='-') && hold==-1)
		{
			op=s[i];
			s1=s.substr(0,i);
			hold=i;
		}
		else if(((s[i]=='+' || s[i]=='-') && hold!=-1) || (i==len-1 && hold!=-1))
		{
			s=calc(s1,s.substr(hold+1,i-hold),op[0]);
			i=-1;
			hold=-1;
			s1.empty();
			s2.empty();
			op.clear();
		}
		
		i++;
		len=s.length();
	}
	return s;
}
string cleanParan(string s)
{
	string sub;
	int end=s.find(')');
	int i=end-1;
	int beg=-1;
	while(beg==-1)
	{
		if(s[i]=='(')
			beg=i;
		i--;
	}
	sub=operate(s.substr(beg+1,end-beg-1));
	s.replace(beg,end-beg+1,sub);
	return s;
}

int calculate(string s)
{
	int bla;
	int find=s.find(')');
	int len=s.length();
	while(len>find && find>-1)
	{
		s=cleanParan(s);
		find=s.find(')');
		len=s.length();
	}
	s=operate(s);
	return atoi(s.c_str());
}
int _tmain(int argc, _TCHAR* argv[])
{
	string reg = "0123456789-+*//*()";
	string s;
	int a;

	cout<<"Enter Your calculation"<<endl;
	cin>>s;
	
	while(!control(s))
	{
		cout<<"Enter Your calculation Correctly!..."<<endl;
		cin>>s;
	}
	int result=calculate(s);
	cout<<"Result is : "<<result<<endl;
	system("PAUSE");
	return 0;
}


