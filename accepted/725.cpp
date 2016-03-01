#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<set>

#define MAX 30240

using namespace std;

int main(){
int a=0, b=0, c=0, d=0, e=0;
int nbr, aux;
bool check[10];
int index = 0;
int v[MAX];
int input;
int solutions;
bool flag; 
int first = true;  
set<int> s;

	for(int j=0; j<=99999; j++){
	    nbr = j;
	    memset(check, 0, sizeof(check));
	     
	    e = nbr%10; nbr = nbr/10;     
	    if(check[e])
	       continue;
	    check[e] = true;
      
	    d = nbr%10; nbr = nbr/10;
	    if(check[d])
	       continue;
	    check[d] = true;
	          
	    c = nbr%10; nbr = nbr/10;
	    if(check[c])
           continue;
        check[c] = true;
        

	    b = nbr%10; nbr = nbr/10;
	    if(check[b])
	       continue;
        check[b] = true;

	    a = nbr%10; nbr = nbr/10;
	    if(check[a])
	       continue;
        check[a] = true;
        
        v[index] = a*10000 + b*1000 + c*100 + d*10 + e;   
        s.insert(v[index]);
        index++;
	}
	
	while(true){
		scanf("%d", &input);
		if(input == 0)
		   break;
		if(!first)
		   printf("\n");
		first = false;
		
		solutions = 0;
		for(int i=0; i<MAX; i++){
		    nbr = v[i]*input;
		    if(nbr > 98765)
		       break;
		    if(s.count(nbr) > 0){
		       memset(check, 0, sizeof(check));
		       aux = v[i];
		       for(int j=0; j<5; j++){
		          check[aux%10] = true;
		          aux = aux/10;
		       }

		       aux = nbr;
		       flag = true;
		       for(int j=0; j<5; j++){
		          if(check[aux%10]){
		             flag = false;
		             break;
		          }  
		          aux = aux/10;
		       }
		       
		       if(flag){
		          printf("%05d / %05d = %d\n",nbr, v[i], input);
		          solutions++;
		       }
		           
		    
		    }
		
		}
		   
    
		if(solutions <= 0 )
		   printf("There are no solutions for %d.\n", input);
	
	}
	             
	   

}

