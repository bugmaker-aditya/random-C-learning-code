#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char prodn[10][50], lead[10][50];

int leadset(int cnt, int idx){
		char nterm;
		int k=0;
		for(int i=0; i<cnt ;i++){
			nterm=prodn[i][0];
			while (idx != '\n'){
				if(prodn[i][idx] != nterm && (prodn[i][idx] >='A' || prodn[i][idx] <= 'Z'))
						leadset(cnt-1,0);
				else
					if( (prodn[i][idx]=='(')  || (prodn[i][idx]==')') || (prodn[i][idx]=='*') || (prodn[i][idx]=='+') ||  (prodn[i][idx]=='-') || (prodn[i][idx]=='/') ){
						lead[i][k]=prodn[1][idx];
						k=k+1;
						}
				else
					if( (prodn[i][idx]=='i') && (prodn[i][idx+1]=='d')){
						lead[i][k]=prodn[i][idx];
						lead[i][k+1]=prodn[i][idx+1];
						k=k+1	;
				}
			  else
					return 0;
			}
		idx = 3;
	}
}

int main (){
		FILE *fp;
		int i,j=0, n ,cnt=0, flag=0,k=0, idx=3;
		if((fp = fopen("xyz.txt", "r")) == NULL){
			printf("Error | opening file");
			exit(1);
		}
		while(fgets(prodn[j++], 200, fp ) != NULL)
				cnt++;
			leadset (cnt,idx);
			printf("\nthe Leading(A) is : \n ");
			for (int i=0; i<cnt; i++){
					printf("{ ");
					for(int j=0;j<k;j++){
						if((lead[i][j]=='i') && (lead[i][j+1]=='d'))
							printf("%c%c", lead[1][3], lead[i][j+1]);
						else
							printf("%c" ,lead[i][j]);
					}
				printf("}\n");
			}
			return 0;
}
