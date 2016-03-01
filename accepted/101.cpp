#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#include<cmath>
#include<set>
#include<cstdlib>
#include<algorithm>

#define MAX 1000

using namespace std;

int matrix[MAX][MAX], grade[MAX];
int blocks, src, dst;

void move_onto(){
int x1, y1, x2, y2;

	for(int i=0; i<blocks; i++)
	   for(int j=0; j<grade[i]; j++){
	       if(matrix[i][j] == src){
	          x1 = i; y1 = j;
	       } else if(matrix[i][j] == dst){
                     x2 = i; y2 = j;
           }
       }
	
	if(x1 == x2)
	  return;
	           
    for(int j=y1+1; j<grade[x1]; j++){
        matrix[matrix[x1][j]][0] = matrix[x1][j];
        grade[matrix[x1][j]] = 1;
    }
    grade[x1] = y1+1;
           
    for(int j=y2+1; j<grade[x2]; j++){
        matrix[matrix[x2][j]][0] = matrix[x2][j];
        grade[matrix[x2][j]] = 1;
    }
    grade[x2] = y2+1;
		           
    matrix[x2][grade[x2]++] = matrix[x1][y1];
    grade[x1]--;
}

void move_over(){
int x1, y1, x2, y2;

	for(int i=0; i<blocks; i++)
	   for(int j=0; j<grade[i]; j++){
	       if(matrix[i][j] == src){
	          x1 = i; y1 = j;
	       } else if(matrix[i][j] == dst){
                     x2 = i; y2 = j;
           }
       }

    if(x1 == x2)
       return;
       
    for(int j=y1+1; j<grade[x1]; j++){
        matrix[matrix[x1][j]][0] = matrix[x1][j];
        grade[matrix[x1][j]] = 1;
    }
    grade[x1] = y1+1;

    matrix[x2][grade[x2]++] = matrix[x1][y1];
    grade[x1]--;    

}

void pile_onto(){
int x1, y1, x2, y2;
	for(int i=0; i<blocks; i++)
	   for(int j=0; j<grade[i]; j++){
	       if(matrix[i][j] == src){
	          x1 = i; y1 = j;
	       } else if(matrix[i][j] == dst){
                     x2 = i; y2 = j;
           }
       }

    if(x1 == x2) 
       return;

    for(int j=y2+1; j<grade[x2]; j++){
        matrix[matrix[x2][j]][0] = matrix[x2][j];
        grade[matrix[x2][j]] = 1;
    }
    grade[x2] = y2+1;
    
    for(int j=y1; j<grade[x1]; j++){
        matrix[x2][grade[x2]++] = matrix[x1][j];
    }
    grade[x1] = y1;
}

void pile_over(){
int x1, y1, x2, y2;
	for(int i=0; i<blocks; i++)
	   for(int j=0; j<grade[i]; j++){
	       if(matrix[i][j] == src){
	          x1 = i; y1 = j;
	       } else if(matrix[i][j] == dst){
                     x2 = i; y2 = j;
           }
       }
    
    if(x1 == x2)
       return;
    
    for(int j=y1; j<grade[x1]; j++){
        matrix[x2][grade[x2]++] = matrix[x1][j];
    }
    grade[x1] = y1;


}


main(){
char str1[20], str2[20];

	while(scanf("%d",&blocks) != EOF){
		for(int i=0; i<MAX; i++){
		   matrix[i][0] = i;
		   grade[i] = 1;
		}
		
		while(true){
		     scanf("%s",str1);
		     if(strcmp(str1,"quit") == 0)
		        break;
		     scanf("%d %s %d",&src,str2,&dst);
		     if(src > blocks-1 || dst > blocks-1 || src == dst){
		        continue;
		     }
		     if(strcmp(str1, "move") == 0){
		        if(strcmp(str2, "onto") == 0){		        
		           move_onto();
		        } else if(strcmp(str2, "over") == 0){
		                  move_over();
		        }
		     } else if(strcmp(str1, "pile") == 0){
		              if(strcmp(str2, "onto") == 0){
		                 pile_onto();
		              } else if(strcmp(str2, "over") == 0){
		                        pile_over();
		              }
		     } 
		}
		 for(int i=0; i<blocks; i++){
		        printf("%d:",i);
		        for(int j=0; j<grade[i]; j++)
		            printf(" %d",matrix[i][j]);
		        printf("\n");
		     }
	}		     
}

