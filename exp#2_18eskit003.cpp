#include <stdio.h>
#include <string.h>
int operators(const char *wd){
  FILE *xyz;
  xyz = fopen("xyz.c", "r");
  if (xyz == NULL)  {
      printf("Unable to open file.\n");
      return 0;
  }
    char str[512],*pos;
    int inx, flag=0;
    while ((fgets(str,512, xyz)) != NULL){
        inx = 0;
        while ((pos = strstr(str + inx, wd)) != NULL) {
            inx = (pos - str) + 1;
            flag++;
        }  }
if (flag>0) return 1;
else   return 0;
fclose(xyz);
}

int main(){
printf("Operators:\n");
  if(operators("+")==1)     {printf("addition operator (+)\n");}
	if(operators("=")==1)    {printf("assignment operator (=)\n");}
	if(operators("*")==1)     {printf("multiplication operator *+)\n");}
	if(operators("-")==1)     {printf("minus operator (-)\n");}
	if(operators("/")==1)     {printf("Division operator (/)\n");}
	if(operators("%")==1)     {printf("modulas operator (%)\n");}
	if(operators("++")==1)    {printf("increament operator (++)\n");}
	if(operators("--")==1)    {printf("decrement operator (--)\n");}
  return 0;
}
