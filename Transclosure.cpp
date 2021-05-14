#include<iostream>
using namespace std;
#define ver 4

void dispSOL(int range[][ver])
{
	cout<<"this is transitive closure of the graph"<<endl<<endl;
	for (int i = 0; i < ver; i++)
		{
			for (int j = 0; j < ver; j++)
				cout<<range[i][j];
			cout<<endl;
	  }
}

void Tclosure(int graph[][ver])
	{
			int range[ver][ver], i, j, k;
			for (i = 0; i < ver; i++)
				{
					for (j = 0; j < ver; j++)
							range[i][j] = graph[i][j];
				}

			for (k = 0; k < ver; k++)
					{
						for (i = 0; i < ver; i++)
							{
								for (j = 0; j < ver; j++)
									range[i][j] = range[i][j] || (range[i][k] && range[k][j]);
							}
					}
			dispSOL(range);
}

int main()
{
	int graph[ver][ver] = { {1, 1, 0, 1},
																{0, 1, 1, 0},
																{0, 0, 1, 1},
																{0, 0, 0, 1}
															};
	Tclosure(graph);
	return 0;
}
