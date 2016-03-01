#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>

using namespace std;

int main(){
int h1, m1, h2, m2;

	while(true){
		scanf("%d %d %d %d",&h1, &m1, &h2, &m2);
		if(h1 == 0 && m1 == 0 && h2 == 0 && m2 == 0)
		   break;
		   
	    if(h1 == h2 && m1 == m2){
	       printf("0\n");
	       continue;
	    }
	    
	    if(h2 > h1){
	       printf("%d\n", (h2*60+m2)-(h1*60 + m1));
	       continue;
	    } 
	    
	    if(h2 < h1 || (h2 == h1 && m2 < m1) ){
	       printf("%d\n", (h2*60+m2) + (23-h1)*60 + (59-m1+1));
	       continue;
	    } 
	    
	    if(h2 == h1 && m2 > m1){
	       printf("%d\n", m2-m1);
	       continue;
	    }
	    

	    
	    
	}


}