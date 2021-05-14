#include<bits/stdc++.h>
using namespace std;

class graph
{
	int vertices;
	list<int> *adjancent;
	void DFSUtil(int v, bool visited[]);
public:
	graph(int vertices);
	void newEdg(int v, int w);
	void DFS(int v);
};

graph::graph(int vertices)
{
	this->vertices = vertices;
	adjancent = new list<int>[vertices];
}
void graph::newEdg(int v, int w)
{
	adjancent[v].push_back(w);
}

void graph::DFSUtil(int v, bool visited[])
{
	visited[v] = true;
	cout << v << " ";
	list<int>::iterator i;
	for (i = adjancent[v].begin(); i != adjancent[v].end(); ++i)
		if (!visited[*i])
			DFSUtil(*i, visited);
}
void graph::DFS(int v)
{
	bool *visited = new bool[vertices];
	for (int i = 0; i < vertices; i++)
		visited[i] = false;
	DFSUtil(v, visited);
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
		cout << " Depth First Traversal from vertex "<<i<<endl;
		g.DFS(i);
		cout<<endl;
	}
	return 0;
}
