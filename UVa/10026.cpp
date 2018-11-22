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
#include<queue>

#define MAX 2000

using namespace std;

typedef struct {
int index, time, cost;
} TShoe;

main(){
int t, n;
TShoe shoes[MAX], tmp;
bool first = true;

	scanf("%d",&t);
	while(t--){
	     scanf("%d",&n);
	     if(!first)
	        printf("\n");
	     first = false;
	     
	     for(int i=0; i<n; i++){
	        scanf("%d %d",&shoes[i].time, &shoes[i].cost);
	        shoes[i].index = i+1;
	     }
	     
	     for(int i=0; i<n-1; i++)
	        for(int j=i+1; j<n; j++){
	            if(shoes[i].time*shoes[j].cost > shoes[j].time*shoes[i].cost ||
	               (shoes[i].time*shoes[j].cost == shoes[j].time*shoes[i].cost &&
	                shoes[i].index > shoes[j].index)){
	               tmp.index = shoes[i].index;
	               tmp.time = shoes[i].time;
	               tmp.cost = shoes[i].cost;
	               
	               shoes[i].index = shoes[j].index;
	               shoes[i].time = shoes[j].time;
	               shoes[i].cost = shoes[j].cost;
	               
	               shoes[j].index = tmp.index;
	               shoes[j].time = tmp.time;
	               shoes[j].cost = tmp.cost;
	            } 
	        }
	     for(int i=0; i<n; i++){
	         if(i + 1 != n)
	            printf("%d ",shoes[i].index);
	         else
	            printf("%d",shoes[i].index);
	     }
	     printf("\n");
	}

}

