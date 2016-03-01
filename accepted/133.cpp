#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#include<cmath>
#include<set>
#include<cstdlib>
#include<algorithm>

using namespace std;

main(){
int N, K, M;
int v[50], count;
int ki, mi;
int a, last;

		while(true){
		     scanf("%d %d %d",&N,&K,&M);
		     if(N == 0 && K == 0 && M == 0)
		       break;
		     memset(v, 0, sizeof(v));
		     count = N;

		     ki = 1; mi = N;
		     last = -1;
		     while(count > 0){
		          a = 0;
		          while(true){
		                if(v[ki] == 0)
		                   a++;
		                if(a == K ){
		                   v[ki] = 1;
		                   count--;
		                   printf("%3d",ki);
		                   last = ki;
		                   ki = (ki + 1)%(N+1);
		                   if(ki == 0) 
		                      ki = 1;
		                   break;
		                }
		                ki = (ki + 1)%(N+1);
		                if(ki == 0)
		                   ki = 1;
		          }

		          if(count <= 0)
		             break;
		             
		          a = 0;
		          while(true){
		               if(v[mi] == 0 || (v[mi] == 1 && mi == last ))
		                  a++;
		               if(a == M && v[mi] == 1 && mi == last){
		                 printf(",");
		                 break;
		               }
		               if(a >= M && v[mi] == 0){
		                  v[mi] = 1;
		                  count--;
		                  if(count > 0)
		                    printf("%3d,",mi);
		                  else
		                    printf("%3d",mi);
		                  mi--;
		                  if(mi <= 0)
		                    mi = N;
		                  break;
		               }
		               mi--;
		               if(mi <=0 )
		                  mi = N;
		          }
		     }
		     printf("\n");
		}

}