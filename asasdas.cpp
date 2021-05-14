#include <iostream>
using namespace std;

void countMoney(int total)
{
	int notes[10] = { 2000, 500, 200, 100,	50, 20, 10, 5, 1,2 };
	int count[9] = { 0 };

	for (int i = 0; i < 9; i++) {
		if (total >= notes[i]) {
			count[i] = total / notes[i];
			total = total - count[i] * notes[i];
		}
	}

	int sum=0;
	for(int i = 0; i<9;i+=1)
	if (count[i] != 0)
	sum = sum + count[i];


	cout << "no of notes coins = "<<sum<<endl;
	cout<<"and notes and coins are ";
	for (int i = 0; i < 9; i++)
	{
		if (count[i] != 0)
		{
			for( int j =0 ;j<count[i];j+=1)
			cout << notes[i]<<" ";
		}
	}
}

int main()
{	 int a= 90;
				countMoney(a);
	return 0;
}
