#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#define MAXR 50000
#define MAXC 30
using namespace std;

main(){
char str[MAXR][MAXC], ch;
int sz[MAXR], lines = 0, cont = 0, index, col=0;
int v[MAXR], repeated[MAXR], last[MAXR]; 
char ans[MAXR];

        for(int i=0; i<MAXR; i++){
           sz[i] = 0;
           for(int j=0; j<MAXC; j++)
               str[i][j] = -1;
        }

        while(true){
              col = 0;
              while(true){
                   ch = getchar();
                if(ch != '\n' && ch != '#' && sz[lines] < 20){
                    str[lines][sz[lines]] = ch;
                    sz[lines]++;
                }
                   else
                      break;
              }
              sz[lines]--;
              if( ch == '#' )
                  break;
              lines++;
        }


        for(int i=0; i<MAXR; i++)
           v[i] = -100;

        
        for(int i=0; i<21; i++){
            for(int j=0; j<lines; j++){
                repeated[j] = 0;
                index = ((int)str[j][i])-65;
                if(i < sz[j] && index >= 0 && index < MAXC && v[index] < 0){
                   v[index] = cont;
                   ans[cont] = str[j][i]; 
                   cont++;
                }
            }
            for(int j=0; j<lines; j++){
                index = ((int)str[j][i])-65;
                if(i < sz[j] && index >= 0 && index < MAXC ){
                  repeated[index]++;
                  last[index] = j;
                }
            }
            for(int j=0; j<lines && j<MAXC; j++){
               if(repeated[j] == 1 )  
                  sz[last[j]] = 0; 
            }
        }
        for(int i=0; i<cont; i++)   
           printf("%c",ans[i]);
        printf("\n");
        return 0;

}

