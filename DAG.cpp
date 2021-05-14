#include<iostream>
#include <list>
#include <stack>

using namespace std;

class graph
{
	int ver;
	list<int> *adja;
	void TpSortUtl(int v, bool visit[],	stack<int> &Stack);
public:
	graph(int ver);
	void NEdge(int v, int w);
	void Tsort();
};

graph::graph(int ver)
{
	this->ver = ver;
	adja = new list<int>[ver];
}

void graph::NEdge(int v, int w)
{
	adja[v].push_back(w);
}

void graph::TpSortUtl(int v, bool visit[],	stack<int> &Stack)
{
	visit[v] = true;

	list<int>::iterator i;
	for (i = adja[v].begin(); i != adja[v].end(); ++i)
		if (!visit[*i])
			TpSortUtl(*i, visit, Stack);

	Stack.push(v);
}

void graph::Tsort()
{
	stack<int> Stack;

	bool *visit = new bool[ver];
	for (int i = 0; i < ver; i++)
		visit[i] = false;

	for (int i = 0; i < ver; i++)
	if (visit[i] == false)
		TpSortUtl(i, visit, Stack);
	while (Stack.empty() == false)
	{
		cout << Stack.top() << " ";
		Stack.pop();
	}
}

int main()
{

	graph g(6);
	g.NEdge(5, 2);
	g.NEdge(5, 0);
	g.NEdge(4, 0);
	g.NEdge(4, 1);
	g.NEdge(2, 3);
	g.NEdge(3, 1);

	cout << "this is a topological sort of the graph \n";
	g.Tsort();

	return 0;
}
