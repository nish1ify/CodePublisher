#pragma once
/////////////////////////////////////////////////////////////////////
//  Strong Component.h -  Class analysing Strong Components        //
//  ver 1.0                                                        //
//                                                                 //
//  Language:      Visual C++ 2008, SP1                            //
//  Platform:      Dell Inspiron, Windows 8.1			           //
//  Application:   CodeAnalyzerEx - CIS 687 Project 3             //
//  Author:        Nishanth Chandrasekaran SUID:215242434		   //
/////////////////////////////////////////////////////////////////////
/*
Module Operations:
==================
This module defines a control class class
* - The functions defined in this class are used for,
> Finding out Strong Compnents by matching Dependency keys
ublic Interface:
=================
SCCUtil;SCC;
Maintenance History:
====================
ver 2.0 : 6 April 2017
- first release
*/
#include<iostream>
#include <list>
#include <stack>
#include<math.h>
#include<algorithm>
#include<vector>
#include <unordered_map>
#define NIL -1
using namespace std;

/////////////////////////////////////////////////////////////////////
// Graph Class used to store the dependency files as a graph
// -to find the strong Component class
// 
class Graph
{
	int V;    
	list<int> *adj;    
	void SCCUtil(int u, int disc[], int low[],
		stack<int> *st, bool stackMember[]);
	std::vector<std::vector<int>> bigvec;

public:
	Graph(int V);   
	void addEdge(int v, int w);   
	std::vector<std::vector<int>>  SCC();    
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
}


//FUnction to store the strong component values
void Graph::SCCUtil(int u, int disc[], int low[], stack<int> *st,bool stackMember[])
{
std::vector<int> vector;
static int time = 0;
disc[u] = low[u] = ++time;
st->push(u);
stackMember[u] = true;
list<int>::iterator i;
for (i = adj[u].begin(); i != adj[u].end(); ++i)
{
int v = *i;  
if (disc[v] == -1)
{
SCCUtil(v, disc, low, st, stackMember);
low[u] = min(low[u], low[v]);
}
else if (stackMember[v] == true)
low[u] = min(low[u], disc[v]);
}
int w = 0;  
vector.erase(vector.begin(), vector.end());
if (low[u] == disc[u])
{
while (st->top() != u)
{
w = (int)st->top();
//cout << w << " ";
vector.push_back(w);
stackMember[w] = false;
st->pop();
}
w = (int)st->top();
//cout << w << "\n";
vector.push_back(w);
stackMember[w] = false;
st->pop();
}
bigvec.push_back(vector);
}


//Function to call SCC Util
std::vector<std::vector<int>> Graph::SCC()
{
    int *disc = new int[V];
	int *low = new int[V];
	bool *stackMember = new bool[V];
	stack<int> *st = new stack<int>();

	for (int i = 0; i < V; i++)
	{
		disc[i] = NIL;
		low[i] = NIL;
		stackMember[i] = false;
	}

	
	for (int i = 0; i < V; i++)
		if (disc[i] == NIL)
			SCCUtil(i, disc, low, st, stackMember);

	return bigvec;

}

