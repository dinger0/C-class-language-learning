#include "pch.h"
#include "Edge.h"

Edge::Edge(int nodeIndexA , int nodeIndexB , int weightValue )
{
	m_iNodeIndexA = nodeIndexA;
	m_iNodeIndexB = nodeIndexB;
	m_iWeightValue = weightValue;
	m_bSelected = false;
}
