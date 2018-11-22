#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#include<cmath>
#include<set>
#include<cstdlib>

#define MAX 50


using namespace std;

char str[MAX][MAX];
char word[20][MAX];
int len[20], n, m;

bool searchNE(int i, int j, int index){
int x, y, z;

	if(i + 1 - len[index] >= 0 && j + 1 - len[index] >= 0 ){
       for(x = i, y=j, z=0; x>= 0 && y >= 0 && z<len[index]; x--, y--, z++)
           if(str[x][y] != word[index][z])
             return false;
    } else 
       return false;
    return true;
}


bool searchNW(int i, int j, int index){
int x, y, z;

	if(i + 1 - len[index] >= 0 && j + len[index] <= m ){
       for(x = i, y=j, z=0; x>= 0 && y < m && z<len[index]; x--, y++, z++)
           if(str[x][y] != word[index][z])
             return false;
    } else 
       return false;
    return true;
}

bool searchSE(int i, int j, int index){
int x, y, z;

	if(i + len[index] <= n && j + 1 >= len[index]){
	   for(x = i, y = j, z = 0; x < n && y >= 0 && z < len[index]; x++, y--, z++)
	       if(str[x][y] != word[index][z])
	          return false;
    } else 
       return false;
    return true;
}

bool searchSW(int i, int j, int index){
int x, y, z;

	if(i + len[index] <= n && j + len[index] <= m){
	   for(x = i, y = j, z = 0; x < n && y < m && z < len[index]; x++, y++, z++)
	       if(str[x][y] != word[index][z])
	          return false;
    } else 
       return false;
    return true;
}


bool searchE(int i, int j, int index){
int y, z;
    
	if(j+1 >= len[index]){
      for(y = j, z=0; y>= 0 && z<len[index]; y--, z++)
          if(str[i][y] != word[index][z])
             return false;
    } else
       return false;
    return true;
}

bool searchW(int i, int j, int index){
int y, z;
    
	if(j+len[index] <= m){
      for(y = j, z=0; y < m && z<len[index]; y++, z++)
          if(str[i][y] != word[index][z])
             return false;
    } else
       return false;
    return true;
}

bool searchN(int i, int j, int index){
int x, z;

	if(i+1 >= len[index]){
       for(x = i, z=0; x>=0 && z<len[index]; x--, z++)
          if(str[x][j] != word[index][z])
             return false;
    } else 
      return false;    
    return true;
}


bool searchS(int i, int j, int index){
int x, z;
    
	if(i+len[index] <= n ){
       for(x = i, z=0; x<n && z<len[index]; x++, z++)
          if(str[x][j] != word[index][z])
             return false;
    } else 
       return false;
    return true;
}

main(){
int cases, k, tmp;
bool v_bool = false;

	scanf("%d",&cases);
	while(cases--){
	     if(v_bool)
	        printf("\n");
	     v_bool = true;
	     
	     scanf("%d %d",&n,&m);
	     for(int i=0; i<n; i++){
	        scanf("%s",str[i]);
   			for(int j=0; j<m; j++)
   			    str[i][j] = tolower(str[i][j]);
	     }
	     scanf("%d",&k);
	     for(int i=0; i<k; i++){
             scanf("%s",word[i]);
             len[i] = strlen(word[i]);
             for(int j=0; j<len[i]; j++)
                 word[i][j] = tolower(word[i][j]);    
         }
         
         for(int index=0; index<k; index++){
             for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                   if(searchN(i,j,index)){
                      printf("%d %d\n",i+1,j+1);
                      i = n; j = m;
                   } else if(searchNE(i,j,index)){
                             printf("%d %d\n",i+1,j+1);
                             i = n; j = m;
                   } else if(searchE(i,j,index)){
                             printf("%d %d\n",i+1,j+1);
                             i = n; j = m;
                   } else if(searchSE(i,j,index)){
                             printf("%d %d\n",i+1,j+1);
                             i = n; j = m;
                   } else if(searchS(i,j,index)){
                             printf("%d %d\n",i+1,j+1);
                             i = n; j = m;
                   } else if(searchSW(i,j,index)){
                             printf("%d %d\n",i+1,j+1);
                             i = n; j = m;
                   } else if(searchW(i,j,index)){
                             printf("%d %d\n",i+1,j+1);
                             i = n; j = m;
                   } else if(searchNW(i,j,index)){
                             printf("%d %d\n",i+1,j+1);
                             i = n; j = m;
                   }
                }
             }
            
         }
	}



}