#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath> 
#define MAX(a,b) ((a) > (b) ? (a) : (b))

using namespace std;

main(){
int n, max_size, tmp, len;
int pos[100], cols, rows, index;
char str[100][61], ans[100][61];



	while(scanf("%d",&n) != EOF){
	     max_size = 0;
	     for(int i=0; i<n; i++){
	        scanf("%s",str[i]);
	
	        tmp = strlen(str[i]);
	        pos[i] = i;
	        if(tmp > max_size)
	           max_size = tmp;
	     }
	   //  cout << "max_size = " << max_size << endl;
	     for(int i=0; i<n-1; i++)
	        for(int j=n-1; j>i; j--){
	            if(strcmp(str[pos[i]], str[pos[j]]) > 0){
	               tmp = pos[i];
	               pos[i] = pos[j];
	               pos[j] = tmp;
	            }
	        }
	    for(int i=0; i<n; i++)
	       strcpy(ans[i],str[pos[i]]);
	    
	    
	    
	    printf("------------------------------------------------------------\n");
	    cols = 1;
	    if(max_size >= 30){
	      for(int i=0; i<n; i++)
	         printf("%s\n",ans[i]);
	    } else {
	        cols += (int)(60-max_size)/(max_size+2);
	       
	       rows = (int)ceil(((double)n)/((double)cols));
	       
	        
	        for(int i=0; i<rows; i++){
	           index = i;
	           for(int j=0; j<cols; j++){
	               
	               
	               if( j != cols -1 || index < n){
	                 printf("%s",ans[index]);
	                 len = strlen(ans[index]);
	                 for(int k=0; k<(max_size+2-len); k++)
	                   printf(" ");
	               } 
	               index += rows;
	           }
	           printf("\n");
	        }       
	              
	    }
	 
	
	}


}