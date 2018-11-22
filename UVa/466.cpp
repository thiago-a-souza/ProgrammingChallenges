/* Mirror, Mirror */
#include<iostream>
#include<cstdio>
#include<cstring>

#define f(i,n) for(int i=0; i<n; i++)

using namespace std;

int sz;
char source[10][10], pattern[10][10];
char cp_source[10][10];

bool isSame(){

	f(i, sz)
	  f(j, sz)
	    if(source[i][j] != pattern[i][j])
	       return false;
	return true;

}

bool rotate(){
char tmp[10][10];

	for(int i=0; i<sz; i++)
	   strcpy(tmp[i], cp_source[i]);
	      
	for(int i=0; i<sz; i++)
	   for(int j1=0, i2=sz-1; j1<sz; j1++,i2--)
	      cp_source[i][j1] = tmp[i2][i];
	      
	for(int i=0; i<sz; i++)
	   for(int j=0; j<sz; j++)
	       if(cp_source[i][j] != pattern[i][j])
	          return false;
	return true;

}

bool reflect(){

	for(int i1=0, i2=sz-1; i1<sz; i1++,i2--)
	   for(int j=0; j<sz; j++)
	       cp_source[i1][j] = source[i2][j];
	
	for(int i=0; i<sz; i++)
	   for(int j=0; j<sz; j++)
	       if(cp_source[i][j] != pattern[i][j])
	          return false;
	return true;
}




int main(){
int ite = 1;

	

	while(scanf("%d",&sz) == 1){
		f(i, sz){
		    scanf("%s",source[i]);
		    strcpy(cp_source[i],source[i]);
		    scanf("%s",pattern[i]);
		}
		
		if(isSame())
		  printf("Pattern %d was preserved.\n",ite);	
		else if(rotate())
			printf("Pattern %d was rotated 90 degrees.\n",ite);
		else if(rotate())
		       printf("Pattern %d was rotated 180 degrees.\n",ite);
		else if(rotate())
		       printf("Pattern %d was rotated 270 degrees.\n",ite);
		else if(reflect())
		       printf("Pattern %d was reflected vertically.\n",ite);
		else if(rotate())
			printf("Pattern %d was reflected vertically and rotated 90 degrees.\n",ite);
		else if(rotate())
		       printf("Pattern %d was reflected vertically and rotated 180 degrees.\n",ite);
		else if(rotate())
		       printf("Pattern %d was reflected vertically and rotated 270 degrees.\n",ite);       
		else printf("Pattern %d was improperly transformed.\n",ite);
		ite++;
				        
	}




}



