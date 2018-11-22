#include<cstdio>
#include<iostream>
#include<set>
#include<algorithm>

using namespace std;

main(){
char  str[10] = {'1','1','2','2','3','3','4','5','5'};
bool b;
int cont = 0, x, y;
set<string> s;
bool mapping[10][10];

        do {
           b = true;
           for(int i=0; i<10; i++) 
               for(int j=0; j<10; j++) 
                  mapping[i][j] = false;
           if(str[0] != '1')
             break;
           
           for(int i=0; i<8; i++){
             // printf("%c,%c  ==>  %d,%d\n",str[i],str[i+1],(int)(str[i])-48,(int)(str[i+1])-48);
              x = (int)(str[i])-48;
              y = (int)(str[i+1])-48;
              if(str[i] == '1' && ( str[i+1] == '4' || str[i+1] == '1' || mapping[x][y]  ) ){ 
                   b = false;
              } else if(str[i] == '2' && (str[i+1] == '4' || str[i+1] == '2' || mapping[x][y]  ) ){
                      b = false;
              } else if((str[i] =='3' && str[i+1] == '3') || ( mapping[x][y] ) ){
                      b = false;
              } else if(str[i] == '4' && (str[i+1] == '1' || str[i+1] == '2' || mapping[x][y] )){
                      b = false;
              } else if((str[i] == '5' && str[i+1] == '5' ) || ( mapping[x][y] ) ){
                      b = false;              
              }
              mapping[x][y] = true;
              mapping[y][x] = true;
           }
           if(b && s.count(str) == 0){
                s.insert(str);
                cont++;
                printf("%s\n",str);
              }
        }while(next_permutation(str,str+9));
       // printf("cont = %d\n",cont);


}

