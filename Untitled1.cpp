
#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;



int main()
{int gd = DETECT, gm, errorcode;
initgraph (&gd, &gm, NULL );

	int P[] = {150, 160, 80,125,125,130,150,160};
	int T = 20;
drawpoly(4, P);
	setcolor (RED);
	 for(int i=0;i<8;i++)
	 	 {
		 P[i] += T;
	 }

	 setcolor(RED);
drawpoly(4, P);


	delay(5000);
	closegraph();
	return 0;
}
