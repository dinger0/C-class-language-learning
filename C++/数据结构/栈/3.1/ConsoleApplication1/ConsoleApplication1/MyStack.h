#ifndef MYSTACK_H
#define MYSTACK_H
#include "Coordinate.h"
class MyStack
{
public:
	MyStack(int size);
	~MyStack();
	bool stackEmpty();
	bool stackFull();
	void clearStack();
	int stackLength();
	bool push(Coordinate elem);
	bool pop(Coordinate &elem);
	void stackTraverse(bool isFromButtom);

private:
	Coordinate *m_pBuffer;
	int m_iSize;
	int m_iTop;
};


#endif