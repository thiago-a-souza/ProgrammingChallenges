#include<iostream>
#include<cstdio>
#define MAX 22
using namespace std;

main(){
long long n, m, c, index, sum, seq, max_con;
long long power[MAX];
bool devices[MAX];

        seq = 1;
        while(true){
           scanf("%llu %llu %llu",&n,&m,&c);
           if(n == 0 || m==0 || c==0)
              break;

           sum = 0; max_con = 0;
            
           for(int i=1; i<=n; i++){
              scanf("%llu",&power[i]);
                 devices[i] = false;
           }
           printf("Sequence %llu\n",seq);
           seq++;
           
           for(int i=0; i<m; i++){
               scanf("%llu",&index);
               if(devices[index] == false){
                  sum += power[index];
                  if(sum > max_con)
                     max_con = sum;
                  devices[index] = true;
               } else {
                  sum -= power[index];
                  devices[index] = false;
               }
               
               if(sum > c){
                  printf("Fuse was blown.\n");
                  for(int j=i+1; j<m; j++)
                     scanf("%llu",&index);
                  break;
               }
           }
           if(max_con <= c)
              printf("Fuse was not blown.\nMaximal power consumption was %llu amperes.\n",max_con);
           printf("\n");
           
        }
}

