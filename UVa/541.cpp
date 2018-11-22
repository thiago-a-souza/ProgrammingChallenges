#include<iostream>
#include<cstdio>

main(){
int n, mat[100][100], row[100], col[100];
int sum;


	while(true){
	     scanf("%d",&n);
	     if(n == 0) 
	        break;
	     
	     for(int i=0; i<n; i++)
	        for(int j=0; j<n; j++)
	            scanf("%d",&mat[i][j]);
	     
	     for(int i=0; i<n; i++) 
                row[i] = col[i] = 0;
                
	     for(int i=0; i<n; i++)
	        for(int j=0; j<n; j++) 
	           if(mat[i][j] == 1){
	              row[i]++;
	              col[j]++;
	           }
	           
	     int row_index=-1, col_index = -1;
	     bool corrupt = false;
	     
	     for(int i=0; i<n; i++){
	         if(row[i]%2 != 0){
	            if(row_index >= 0){
	               corrupt = true;
	               break;
	            }
	            row_index = i;
	         }
	         if(col[i]%2 != 0){
	            if(col_index >= 0){
	               corrupt = true;
	               break;
	            }
	            col_index = i;
	         }
	     }
	     if(corrupt || ((row_index < 0 && col_index >=0) || (row_index >= 0 && col_index < 0)))
	       printf("Corrupt\n");
	     else if(row_index < 0 && col_index < 0)
	             printf("OK\n");
	     else printf("Change bit (%d,%d)\n",row_index+1,col_index+1);

	}


}


