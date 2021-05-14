#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int searchPat(char *str) {
	FILE *fp;	int fres=0;
	char temp[512];
	if((fp = fopen("xyz.c", "r")) == NULL){	printf("file not present\n");
		exit(0);	}
else	while(fgets(temp, 512, fp) != NULL)
					if((strstr(temp, str)) != NULL)
							fres++;
if(fres == 0)		return NULL;
else	return fres;
if(fp)		fclose(fp);
}

int main()
{
	char op[][2]={"a","b","c","d","e","f","g","h","i","j","k","l","m","n",
								"o","p","q","r","s","t","u","v","w","x","y","z"};

for(int i=0;i<26;i++)
if(searchPat(op[i])!=NULL)
printf("%s = %d\t",op[i],searchPat(op[i]));
return 0;

}
