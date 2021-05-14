#include <iostream>
using namespace std;

int abs (int n)
	{
		return ( (n>0) ? n : ( n * (-1)));
	}

bool attack(int q1row, int q1col, int q2row, int q2col)
	{
			if (q1row == q2row)
				return true;
			if (q1col == q2col)
				return true;
			if (abs(q1row - q2row) == abs(q1col - q2col))
				return true;
			return false;
}

int main()
{
	int q1row, q1col, q2row, q2col;
	cout<<"enter queen 1 position( row, column)"<<endl;
	cin>>q1row>>q1col;
	cout<<"enter queen 2 position( row, column)"<<endl;
	cin>>q2row>>q2col;
	if (attack(q1row, q1col, q2row, q2col))
		cout << "Yes";
	else
		cout << "No";

	return 0;
}
