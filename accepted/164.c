/* String Computer - 07/06/2007 */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 1000
#define I 1 
#define C 2
#define D 3

#define min(a,b) (a<b ? a : b)

char str1[MAX], str2[MAX];
int op[MAX][MAX], val[MAX], d[MAX][MAX];
int str1len, str2len;


void printpath(int i , int j){
register int k;
	  if(i==0 && j==0)
	     return;

	  if(op[i][j]==I){
	     printpath(i,j-1);
	     if(val[i]<10)
	       printf("I%c0%d",str2[j-1],val[i]+1);
	     else
	       printf("I%c%d",str2[j-1],val[i]+1);
	     for(k=i; k<=str1len; k++)
	        val[k]++;			        
	  }
	  else if(op[i][j]==C){
	          printpath(i-1,j-1);
	          if(d[i][j]!=d[i-1][j-1])
	            if(val[i]<10)
	               printf("C%c0%d",str2[j-1],val[i]);
	            else
	               printf("C%c%d",str2[j-1],val[i]);
	       }
	   else{
	   	   printpath(i-1,j);
	   	   if(val[i] < 10)
	   	     printf("D%c0%d",str1[i-1],val[i]);
	   	   else
	   	     printf("D%c%d",str1[i-1],val[i]);
	   	   for(k=i; k<=str1len; k++)
	   	      val[k]--;
	   }
}

void editDistance(){
register int i, j;
int cost;

	d[0][0] = 0;
	for(i=1; i<=str1len; i++){
	   d[i][0] = i;
	   op[i][0] = D;  
	}
	for(i=1; i<=str2len; i++){
	   d[0][i] = i;
	   op[0][i] = I;  
	}
	for(i=1; i<=str1len; i++)
	   for(j=1; j<=str2len; j++){
		cost = (str1[i-1]==str2[j-1]) ? 0 : 1;
		d[i][j] = min(d[i-1][j-1]+cost,min(d[i-1][j]+1,d[i][j-1]+1));
		if(d[i][j]==d[i-1][j-1]+cost)
	           op[i][j] = C;
                else if(d[i][j]==d[i][j-1]+1)
		        op[i][j] = I;
		     else
		       op[i][j] = D;
	   }
}

main(){
int i, j;

	scanf("%s",str1);
	while(strcmp(str1,"#")!=0){
	     scanf("%s",str2);
	     str1len = strlen(str1);
	     str2len = strlen(str2);
	     for(i=0; i<MAX; i++)
	        val[i] = i;
	     editDistance(str1,str2);
	     printpath(str1len,str2len);
	     printf("E\n");
	     scanf("%s",str1);
	}
}

