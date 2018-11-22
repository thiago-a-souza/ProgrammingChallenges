#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>

#define MAX 50
#define INF 100000000

using namespace std;

int main(){
int participants, budget, hotels, weeks;
int beds, price;
int minprice;


	while(scanf("%d %d %d %d", &participants, &budget, &hotels, &weeks) != EOF) {
	      minprice = INF;
	      for(int i=0; i<hotels; i++){
	          scanf("%d", &price);
	          for(int j=0; j<weeks; j++){
	              scanf("%d", &beds);
	              if(beds >= participants && participants*price < minprice )
	                 minprice = participants*price;
	          }
	      }
	      if(minprice <= budget)
	         printf("%d\n", minprice);
	      else
	         printf("stay home\n");
	         
	} 
}

