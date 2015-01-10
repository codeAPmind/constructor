#include<iostream>
using namespace std;

class NoName
{
public:
	NoName();
	NoName(const char *);
	NoName(const NoName &);
	NoName & operator=(const NoName &);
protected:
	void initNoName(const char*);
private:
	char *pstring;
	int ival;
	double dval;
};

 NoName::NoName()
{
	pstring = new char[1];
	*pstring = '\0';
	ival = 0;
	dval = 0.0;
}

void NoName::initNoName(const char *ps)
 {
	 if(ps)
	 {
		 pstring = new char[strlen(ps)+1];
		 strcpy(pstring,ps);
	 }
	 else
	 {
		 pstring = new char[1];
		 *pstring = '\0';
	 }
 }
NoName::NoName(const char *ps)
{
	initNoName(ps);
	ival = 0;
	dval = 0;
}

NoName::NoName(const NoName &str)
{
	initNoName(str.pstring);
	ival = str.ival;
	dval = str.dval;
}

NoName & NoName::operator=(const NoName &str)
{
	if(this == &str)
	{
		return *this;
	}
	else
	{
		int Size = strlen(str.pstring)+1;
		char *temp = new char[Size];
		memcpy(temp,str.pstring, Size*sizeof(char));
		delete []pstring;
		pstring = temp;
		ival = str.ival;
		dval = str.dval;
	}
	return *this;
}

void main()
{
	NoName str;
	const char *ps = "hello";
	NoName ptr("qwe");
	NoName ttr(ptr);
	NoName qtr ;
	NoName *ppt = new NoName;
	*ppt = qtr; 
	//qtr = ppt;
}

