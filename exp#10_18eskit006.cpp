#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
void f(){
	printf("NOT OPERATOR GRAMMAR");
	exit(0);
}
int main (){
	FILE *fp;
	char grm[20][20],c;
	int j=2,i=0,n,count=0, flag=0;
	if ((fp=fopen("xyz.txt", "r")) == NULL)	{
		printf("Error! Opening file");
		exit(1);
	}
	while(fgets(grm[n++], 200, fp) != NULL)
		count++;
	for( i=0; i<count ;i++){
		c = grm[1][2];
		while(c != '\e'){
			if (grm[i][3] == '+' || grm[i][3] == '-' || grm[i][3] == '*' || grm[i][3] == '/')
			flag = 1;
		else{
			flag = 0;
			f();
		}
		if (c=='$'){
			flag = 0;
			f();
		}
		c = grm[i][++j];
	}
}
if (flag== 1)
		printf("OPERATOR GRAMMAR\n");
return 0;
}
