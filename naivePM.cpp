#include <bits/stdc++.h>
using namespace std;

void search(char* P, char* T)
{
	int M = strlen(P);
	int N = strlen(T);
	for (int i = 0; i <= N - M; i++)
	{
		int j;
		for (j = 0; j < M; j++)
			if (T[i + j] != P[j])
				break;
		if (j == M)
			cout << "Pattern found at index "
				<< i << endl;
	}
}

int main()
{
	char T[] = "AABAACAADAABAAABAA";
	char P[] = "AABAA";
	search(P, T);
	return 0;
}
