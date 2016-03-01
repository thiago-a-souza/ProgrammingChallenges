#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

#define MAX 10001
using namespace std;

main(){
vector< pair< int, int > > mat[MAX];
int nonzero[MAX], rowVal[MAX], rowIndex[MAX];
int rows, columns;
int sz, tmp;
int index, val;

	while(scanf("%d %d",&rows, &columns) != EOF){
		for(int i=0; i<rows; i++)
		   for(int j=0; j<columns; j++)
		       mat[i].clear();

		for(int i=0; i<rows; i++){
		   scanf("%d",&sz);
		   for(int j=0; j<sz; j++)
		       scanf("%d",&nonzero[j]);
		   
		   for(int j=0; j<sz; j++){
		       scanf("%d",&tmp);		
		       mat[i].push_back(make_pair(nonzero[j], tmp));
		   }
		}
		printf("%d %d\n",columns, rows);
		for(int i=1; i<=columns; i++){
			sz = 0;
			for(int j=0; j<rows; j++){
				for(int k=0; k<mat[j].size(); k++){
				    index = mat[j][k].first;
				    val = mat[j][k].second;
				    if(index == i){
				    	rowVal[sz] = val;
				    	rowIndex[sz] = j+1;
				    	sz++;
				    }
				    if(index > i)
				       break;
				}
			}
			if(sz == 0)
			   printf("0\n\n");
			else {
				printf("%d", sz);
				for(int j=0; j<sz; j++)
				    printf(" %d",rowIndex[j]);
				printf("\n");
				for(int j=0; j<sz; j++){
				   if(j > 0)
				     printf(" %d",rowVal[j]);
				   else
				     printf("%d", rowVal[j]);
				}
				printf("\n");
			}
		}
		
		
	}
}

