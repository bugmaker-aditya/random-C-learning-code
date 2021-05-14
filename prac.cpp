#include<bits/stdc++.h>
using namespace std;
int minLen(string arr[], int n)
{
	int min = INT_MAX;

	for (int i=0; i<=n-1; i++)
		if (arr[i].length() < min)
			min = arr[i].length();
	return(min);
}
bool allContainsPrefix(string arr[], int n, string str,
					int start, int end)
{
	for (int i=0; i<=n-1; i++)
		for (int j=start; j<=end; j++)
			if (arr[i][j] != str[j])
				return (false);
	return (true);
}
string commonPrefix(string arr[], int n)
{
	int index = minLen(arr, n);
	string prefix;
	int low = 0, high = index;
	while (low <= high)
	{
		int mid = low + (high - low) / 2;
		if (allContainsPrefix (arr, n, arr[0], low, mid))
		{
			prefix = prefix + arr[0].substr(low, mid-low+1);
			low = mid + 1;
		}
		else
			high = mid - 1;
	}
	return (prefix);
}
int main()
{
	string arr[] = {"String", "Str","StrName"};
	string arr1[] = {"String"};
	int n = sizeof (arr) / sizeof (arr[0]);
	int n1 = sizeof (arr1) / sizeof (arr1[0]);
	string ans = commonPrefix(arr, n);
	string ans1 = commonPrefix(arr1, n1);
	if (ans.length())
		cout << ans<<endl;
	else
		cout << "no common prefix";
	if (ans1.length())
			cout << ans1;
		else
			cout << "no common prefix";
	return (0);
}
