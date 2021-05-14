#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int searchPat(char *str) {
	FILE *fp;
	int fres=0;
	char temp[512];
	if((fp = fopen("xyz.c", "r")) == NULL)
	{printf("file not present\n");
		exit(0);
	}
else{
	while(fgets(temp, 512, fp) != NULL) {
		if((strstr(temp, str)) != NULL) {
			fres++;
		}
	}
}

	if(fres == 0) {
		return NULL;
	}
	else
	return fres;
	if(fp) {
		fclose(fp);
	}
}

int main()
{
printf("\noperators:\n");
	if(searchPat("=")!=NULL)
			printf("assignment operator(=):\t%d\n",searchPat("="));
	if(searchPat("+")!=NULL)
			printf("addition(+):\t%d\n",searchPat("+"));
	if(searchPat("-")!=NULL)
			printf("subtraction(-):\t%d\n",searchPat("-"));
	if(searchPat("*")!=NULL)
			printf("multiplication(*):\t%d\n",searchPat("*"));
	if(searchPat("/")!=NULL)
			printf("division(/):\t%d\n",searchPat("/"));
	if(searchPat("%")!=NULL)
			printf("modulas(%):\t%d\n",searchPat("%"));
	if(searchPat("==")!=NULL)
			printf(" (==):\t%d\n",searchPat("=="));
	if(searchPat("!=")!=NULL)
			printf("(!=):\t%d\n",searchPat("!="));
	if(searchPat(">=")!=NULL)
			printf("(>=):\t%d\n",searchPat(">="));
	if(searchPat("<=")!=NULL)
			printf("(<=):\t%d\n",searchPat("<="));
	if(searchPat("++")!=NULL)
			printf("(++):\t%d\n",searchPat("++"));
	if(searchPat("--")!=NULL)
			printf("(--):\t%d\n",searchPat("--"));
	if(searchPat("&&")!=NULL)
			printf("(&&):\t%d\n",searchPat("&&"));
	if(searchPat("||")!=NULL)
			printf("(||):\t%d\n",searchPat("||"));
	if(searchPat("!")!=NULL)
			printf("(!):\t%d\n",searchPat("!"));

char op[][10]={"auto","break","case","char","const","continue","default","do",
							 "double","else","enum","extern","float","for","goto","if","int",
							 "long","register","return","short","signed","sizeof","static",
							 "struct","switch","typedef","union","unsigned","void","volatile",
							 "while"};
printf("\nkeywords:\n");
for(int i=0;i<32;i++)
if(searchPat(op[i])!=NULL)
printf("%s\t%d\n",op[i],searchPat(op[i]));
return 0;

}
