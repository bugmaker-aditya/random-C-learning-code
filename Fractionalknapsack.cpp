#include <bits/stdc++.h>
using namespace std;

class items
{
	public:
		int value, weight;
		items(int value, int weight) : value(value), weight(weight)
		{}
};

bool compare( items a, items b)
{
	int r1 = (float)a.value / a.weight;
	int r2 = (float)b.value / b.weight;
	return r1 > r2;
}
float napitems(int W, items ARR[], int n)
{
	sort(ARR, ARR + n, compare);
	int currentweight = 0;
	float finalval = 0.0;
	for (int i = 0; i < n; i++)
	{
		if (currentweight + ARR[i].weight <= W)
	{
			currentweight += ARR[i].weight;
			finalval += ARR[i].value;
	}
		else
	{
			int remain = W - currentweight;
			finalval += ARR[i].value * ((float) remain / ARR[i].weight);
			break;
	}	}
	return finalval;
}

int main()
{
	int W = 100;
	items ARR[] = {{50, 10}, {90, 20}, {60, 25},{200,35},{250,50}};
	int n = sizeof(ARR) / sizeof(ARR[0]);
	cout << "Max value = "<< napitems(W, ARR, n);
	return 0;
}
