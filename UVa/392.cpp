#include<iostream>
#include<cstdio>

using namespace std;


main(){
int val[10];
bool first;
        while( scanf("%d",&val[0]) != EOF ){
             for(int i=1; i<9; i++)
                scanf("%d",&val[i]);
             first = true;
             
             for(int i=0; i<9; i++){
                if(val[i] > 0){
                   if(8 - i > 1){
                      if(first){
                         if(val[i] != 1)
                            printf("%dx^%d",val[i],8-i);
                         else
                            printf("x^%d",8-i);
                      } else {
                         if(val[i] != 1)
                            printf(" + %dx^%d",val[i],8-i);
                         else
                            printf(" + x^%d",8-i);
                      }
                      
                   } else if(8 - i == 1){ 
                             if(first){
                                if(val[i] != 1)
                                   printf("%dx",val[i]);
                                else
                                   printf("x");
                             } else {
                                 if(val[i] != 1)
                                    printf(" + %dx",val[i]);
                                 else
                                    printf(" + x");
                             }
                   }
                   else {
                      if(first)
                         printf("%d",val[i]);
                      else 
                         printf(" + %d",val[i]);
                   }
                   first = false;
                } else if(val[i] < 0){
                          if(8 - i > 1){
                             if(first){
                                if(val[i] != -1)
                                   printf("%dx^%d",val[i],8-i);
                                else
                                   printf("-x^%d",8-i);
                             } else {
                                if(val[i] != -1)
                                   printf(" - %dx^%d",-val[i],8-i);
                                else
                                   printf(" - x^%d",8-i);
                             }
                          } else if( 8 - i == 1){
                                       if(first){
                                          if(val[i] != -1)
                                             printf("%dx",val[i]);
                                          else
                                             printf("-x");
                                         
                                       } else {
                                          if(val[i] != -1)
                                             printf(" - %dx",-val[i]);
                                          else
                                             printf(" - x");
                                       }
                          } else {
                              if(first)
                                 printf("%d",val[i]);
                              else
                                 printf(" - %d",-val[i]);
                          }
                          first  = false;
                }
                
             }
             if(first)
                   printf("0");
             printf("\n");
             
             
        }

}

