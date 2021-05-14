#include<stdio.h>
#include<ctype.h>
#include<string.h>
void findfirst(char, int, int);
int count, n = 0, k;
char CalFirst[10][100], production[10][10], first[10];
int main(){
    int jm = 0,i=0, kay, ptr = -1, point1 = 0, point2, xxx;
    count = 8;
    char c , done[count];
    FILE *fptr ;
    fptr = fopen("xyz.txt", "r");
    while(fgets(production[i], 128, fptr)) {
        production[i][strlen(production[i]) - 1] = '\0';  i++;
    }
    for(k = 0; k < count; k++){
        for(kay = 0; kay < 100; kay++)
        for(k = 0; k < count; k++)
            CalFirst[k][kay] = '!';
        c = production[k][0];
        point2 = 0;
        xxx = 0;
        for(kay = 0; kay <= ptr; kay++)
            if(c == done[kay])
                xxx = 1;
        if (xxx == 1)
            continue;
        findfirst(c, 0, 0);
        ptr += 1;       done[ptr] = c;
        printf("\n First(%c) = { ", c);
        CalFirst[point1][point2++] = c;
        for(i = 0 + jm; i < n; i++) {
            int lark = 0, chk = 0;
            for(lark = 0; lark < point2; lark++)
                if (first[i] == CalFirst[point1][lark])      {
                    chk = 1;
                    break;         }
            if(chk == 0){          printf("%c, ", first[i]);
                CalFirst[point1][point2++] = first[i];
            }
        }
        printf("}\n");
        jm = n,   point1++;
    }    printf("\n");


void findfirst(char c, int q1, int q2){
    int j;
    if(!(isupper(c)))
        first[n++] = c;
    for(j = 0; j < count; j++)
      if(production[j][0] == c){
            if(production[j][2] == '#'){
                if(production[q1][q2] == '\0')             first[n++] = '#';
                else if(production[q1][q2] != '\0' && (q1 != 0 || q2 != 0))
                    findfirst(production[q1][q2], q1, (q2+1));
                else       first[n++] = '#';
            }
            else if(!isupper(production[j][2]))
                first[n++] = production[j][2];
            else     findfirst(production[j][2], j, 3);
        }
    }
