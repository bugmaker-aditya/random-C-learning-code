#include <iostream>
#include <list>
using namespace std;

class graph
{
	int vertice;
	list<int> *adjacent;
public:
	graph(int vertice);
	void newEdg(int v, int w);
	void BFS(int s);
};

graph::graph(int vertice)
	{
			this->vertice = vertice;
			adjacent = new list<int>[vertice];
	}

void graph::newEdg(int v, int w)
{ 	adjacent[v].push_back(w); }

void graph::BFS(int s){
	bool *visited = new bool[vertice];
	for(int i = 0; i < vertice; i++)
		visited[i] = false;
	list<int> queue;
	visited[s] = true;
	queue.push_back(s);
	list<int>::iterator i;
while(!queue.empty())
	{
		s = queue.front();
		cout << s << " ";
		queue.pop_front();
		for (i = adjacent[s].begin(); i != adjacent[s].end(); ++i)
				if (!visited[*i])
					{	visited[*i] = true;
						queue.push_back(*i);
					}
	}
}

int main()
{
	graph g(6);
	g.newEdg(0, 1);
	g.newEdg(2, 0);
	g.newEdg(1, 2);
	g.newEdg(2, 1);
	g.newEdg(3, 2);
	g.newEdg(3, 4);
	g.newEdg(4, 3);
	g.newEdg(4, 5);
	g.newEdg(5, 4);

	for(int i= 0; i<6;i+=1)
	{
		cout << "Breadth First Traversal from vertex "<<i<<endl;
		g.BFS(i);
		cout<<endl;
	}
return 0;
}
