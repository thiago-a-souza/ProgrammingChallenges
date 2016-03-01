#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#include<cmath>
#include<set>
#include<cstdlib>

#define MAX 1000

using namespace std;

main(){
int C, N, grades[MAX], aboveAvg;
double average;

	scanf("%d",&C);
	while(C--){
	     scanf("%d",&N);
	     average = 0.0;
	     
	     for(int i=0; i<N; i++){
	        scanf("%d",&grades[i]);
	        average += grades[i];
	     }
	     average = average/((double)N);
	     aboveAvg = 0;
	     for(int i=0; i<N; i++){
	        if(grades[i]*1000 > ((int)average*1000.0))
	           aboveAvg++;
	     }
	     printf("%.3lf%%\n", ((double)aboveAvg*100.0)/((double)N)   );
	}
}