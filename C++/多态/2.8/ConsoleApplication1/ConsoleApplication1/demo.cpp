﻿#include "pch.h"
#include <iostream>
#include"Circle.h"
using namespace std;


int main()
{
	Shape shape;
	//cout << sizeof(shape) << endl;

	int *p = (int*)&shape;
	cout << p << endl;
	//cout << (unsigned int)(*p) << endl;


	Circle circle(100);
	//cout << sizeof(circle) << endl;

	int *q = (int*)&circle;
	cout << q << endl;
	cout << (unsigned int)(*q) << endl;
	//q++;
	//cout << (unsigned int)(*q) << endl;


    return 0; 
}

