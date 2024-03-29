#include "pch.h"
#include "Tree.h"
#include "Node.h"
#include <iostream>
Tree::Tree()
{
	m_pRoot = new Node();
}

Tree::~Tree()
{
	//DeleteNode(0,NULL);
	m_pRoot->DeleteNode();
}

Node *Tree::SearchNode(int nodeIndex)
{
	return m_pRoot->SearchNode(nodeIndex);
}

bool Tree::AddNode(int nodeIndex, int direction, Node *pNode)
{
	Node *temp = SearchNode(nodeIndex);
	if (temp == NULL)
	{
		return false;
	}
	Node *node = new Node();
	if (node == NULL)
	{
		return false;
	}
	node->index = pNode->index;
	node->data = pNode->data;
	node->pParent = temp;
	if (direction == 0)
	{
		temp->pLChild = node;
	}
	if (direction == 1)
	{
		temp->pRChild = node;
	}
	return true;
}

bool Tree::DeleteNode(int nodeIndex, Node *pNode)
{
	Node *temp = SearchNode(nodeIndex);
	if (temp == NULL)
		return false;
	if (pNode != NULL)
		pNode->data = temp->data;
	temp->DeleteNode();
	return true;
}

void Tree::PreorderTraverse()
{
	m_pRoot->PreorderTraverse();
}

void Tree::InorderTraverse()
{
	m_pRoot->InorderTraverse();
}

void Tree::PosorderTraverse()
{
	m_pRoot->PosorderTraverse();
}