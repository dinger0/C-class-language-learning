﻿#include "pch.h"
#include <iostream>
#include"Line.h"

using namespace std;
int main(void)
{
	Line *p = new Line(1, 2, 3, 4);
	p->printInfo();
	delete p;
	p = NULL;
	cout << sizeof(p)<<endl;
	cout << sizeof(Line)<<endl;
	return 0;;
}

