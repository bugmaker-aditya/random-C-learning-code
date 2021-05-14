#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 10
char prodn[10][SIZE];
int main (){
		FILE *fp;
		int j=0,i=0,count=0, flag=0, index=3;;
		char nterm, var, temp[50];
		if((fp = fopen("xyz.txt","r"))== NULL){
			printf("Error ! opening file");
			exit(1);}
		while(fgets(prodn[j++], 200, fp) != NULL)
				 count++;
	 for( i=0; i<count ;i++){
				nterm = prodn[i][0];
				var = prodn[i][index];
				temp[0] = nterm;
				temp[1] = '`';
				temp[2] = '-';
				temp[3] = '>';

				char z = index+1;
				j = 4;

				while(prodn[i][z] != '|'){
						if(prodn[i][z] != ' ')
								temp[j++] = prodn[i][z];
						index++;
					}
					temp[j++] = '|';
					index = z;
					printf("%c->", nterm);
					while (prodn[i][index] != '\n'){
							if (prodn[i][index] == '|'){
									index++;
									if(prodn[i][index]= var && prodn[i][index]!=' ')
											while(prodn[i][index]= '\n' || prodn[i][index] != ' '){
												if(prodn[i][index]!=' ')
													printf("%c", prodn[i][index]);
												index++;
											}
							if(prodn[i][index] != '\n')
								printf("|");
							}
						else if(prodn[i][index] == var){
								flag ++;
								while(prodn[i][index] = '|'){
										index++;
										if(prodn[i][index] !=' ')
										temp[j++] = prodn[i][index];
									}
								temp[j] = '|';
							}
						}
					index++;
				}
				if(flag > 0){
						printf("%c%c\'\n", nterm, nterm);
						temp[j] = '#';
						for (int k=0;k<j+3; k++)
							printf("%c", temp[k]);
					}
index = 3;
}
