#include <iostream>

using namespace std;

int const s =4 ;
int const in = 99999;

void solution(int dis[][s])
{
	cout<<"the shortest distances between every pair of vertices \n";
	for (int i = 0; i < s; i++)
	{
		for (int j = 0; j < s; j++)
					(dis[i][j] == in) ?	cout<<"in"<<"	 ":	cout<<dis[i][j]<<"	 ";
		cout<<endl;
	}
}
void floyd (int distgraph[][s])
		{
				int dis[s][s] ;
				for (int i = 0; i < s; i++)
						for (int j = 0; j < s; j++)
							dis[i][j] = distgraph[i][j];

				for (int k = 0; k < s; k++)
						for (int i = 0; i < s; i++)
									for (int j = 0; j < s; j++)
												if (dis[i][k] + dis[k][j] < dis[i][j])
																	dis[i][j] = dis[i][k] + dis[k][j];
				solution(dis);
		}

int main()
{
	int distgraph[s][s] = { {0	 , 4	 , in 	, 16	 },
													{in	 , 0	 , 12  	, in 	 },
													{in	 , in	 , 0  	, 17	 },
													{in	 , in	 , in		, 0		 }
												};

	floyd(distgraph);
	return 0;
}
