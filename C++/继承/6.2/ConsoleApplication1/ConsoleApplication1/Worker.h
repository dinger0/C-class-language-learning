#include<string>
#include"Person.h"
using namespace std;

class Worker:virtual public Person
{
public:
	Worker(string code="001",string color="blue");
	virtual ~Worker();
	void carry();
protected:
	string m_strCode;
};