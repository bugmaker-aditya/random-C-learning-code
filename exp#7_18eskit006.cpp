#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define SIZE 10
int main (){
	 char nterm, beta, alpha, prodn[10][SIZE];;
	 int i=0, num,index=3;
	 FILE *fptr;
	 if ((fptr = fopen("xyz.txt", "r")) == NULL)
    { printf("Error! Opening file");	exit(1);	}
		while (fgets(prodn[i++],20, fptr)!=NULL) { }
		num=i-1;

		for( i=0; i<num ; i++){
				printf("\nGRAMMAR : : : %s", prodn[i]);
				nterm=prodn[i][0];
				if(nterm==prodn[i][index]){
						alpha=prodn[i][index+1];
						printf(" is left recursive. \n");
						while( prodn[i][index]!= 0 && prodn[i][index]!='1' )
							index++;
						if(prodn[i][index]!=0){
								beta=prodn[i][index+1];
								printf("Grammar without left recursion:\n");
								printf("%c->%c%c\"", nterm, beta, nterm);
								printf("\n%c\'->%c%c\'E\n", nterm, alpha, nterm);			}
						else
								printf(" can't be reduced\n");	}
				else
					printf(" is not left recursive. \n");
				index=3; }
    }
