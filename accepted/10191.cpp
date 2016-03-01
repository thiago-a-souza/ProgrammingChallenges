#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack> 
#include <set>

#define MAX 2000
#define FREE 0
#define BUSY 1

using namespace std;

main(){
int n, len;
char str[MAX];
int sch[MAX];
int hh1, mm1, hh2, mm2;
int v1, v2, last, max, cont, min_index, index;
int days = 1;
		while(scanf("%d\n",&n) != EOF){
		      memset(sch, FREE, sizeof(sch));
		      if(n == 0){
		        printf("Day #%d: the longest nap starts at 10:00 and will last for 8 hours and 0 minutes.\n",days);
		        days++;
		        continue;
		      }
		      for(int i=0; i<n; i++){
		          cin.getline(str,MAX);
		          len = strlen(str);
		          hh1 = atoi(&str[0]);
		          mm1 = atoi(&str[3]);
		          hh2 = atoi(&str[6]);
		          mm2 = atoi(&str[9]);
		          v1 = hh1*60 + mm1;
		          v2 = hh2*60 + mm2 - 1;
		          for(int i=v1; i<=v2; i++)
		              sch[i] = BUSY;
		      }
		      last = FREE; max = -1; cont = 0; index = 600;
		      
		      for(int i=600; i<1080; i++){
		         if(sch[i] == FREE){
		            if(last == FREE)
		               cont++;
		            else if(last == BUSY){
		                    if(cont > max){
		                       max = cont; 
		                       min_index = index;
		                    }
		                    index = i;
		                    cont = 1;
		            }
		         } else if(sch[i] == BUSY){
		                   if(cont > max){
		                      max = cont;
		                      min_index = index;
		                   }
		                   cont = 0;
		         }
		         last = sch[i];
		      }
		      
		      if(cont > max){
		         max = cont;
		         min_index = index;
		      }
		      if(max < 60)
		         printf("Day #%d: the longest nap starts at %02d:%02d and will last for %d minutes.\n",days,(int)(min_index/60), min_index-(((int)(min_index/60))*60),max);
		      else
		         printf("Day #%d: the longest nap starts at %02d:%02d and will last for %d hours and %d minutes.\n",days,(int)(min_index/60), min_index-(((int)(min_index/60))*60),(int)(max/60), max - (((int)(max/60))*60) );
		      days++;
		      
		}
}

