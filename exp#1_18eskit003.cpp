#include <stdio.h>
#include <string.h>

int keyword(char *str) {
	FILE *fp;
	int lnum = 1;
	int fres=0;
	char temp[512];
	if((fp = fopen("xyz.c", "r")) == NULL)
		return(-1);
  else{
		while(fgets(temp, 512, fp) != NULL) {
				if((strstr(temp, str)) != NULL) {
							printf("\n%s", str);
							fres++;
						}
		lnum++;
				}
		 }

	if(fres == 0)
		printf("");
	if(fp)
		fclose(fp);
   	return(0);
}

int main()
{ char o[][10]={"auto","union","default","signed","volatile","case","long","short","const","sizeof","switch",
								"unsigned","void","static","goto","struct","typedef","char","float","return","double","continue",
								"break","do","while","int","extern","register","enum","for","if","else"};
	for(int i=0; i<32;i++)
		keyword(o[i]);
		return 0;

}
