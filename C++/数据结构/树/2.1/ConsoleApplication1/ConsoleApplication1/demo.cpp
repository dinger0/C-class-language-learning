﻿#include "pch.h"
#include <iostream>
#include "Tree.h"
using namespace std;
int main()
{
	int root = 3;
	Tree *pTree = new Tree(10,&root);
	int node1 = 5;
	int node2 = 8;
	int node3 = 2;
	int node4 = 6;
	int node5 = 9;
	int node6 = 7;



	pTree->AddNode(0, 0, &node1);
	pTree->AddNode(0, 1, &node2);
	pTree->AddNode(1, 0, &node3);
	pTree->AddNode(1, 1, &node4);
	pTree->AddNode(2, 0, &node5);
	pTree->AddNode(2, 1, &node6);

	int node = 0;
	pTree->DeleteNode(6,&node);
	cout << "node=" << node << endl;

	pTree->TreeTraverse();

	int *temp = pTree->SearchNode(2);
	cout << endl << "node=" << *temp << endl;


	delete pTree;
    return 0; 
}

