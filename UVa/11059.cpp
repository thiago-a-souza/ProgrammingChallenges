#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<set>

using namespace std;

#define MAX 20


int main(){
int n, v[MAX];
long long tmp, max;
int line = 1; 

	while(scanf("%d",&n) != EOF){
	     for(int i=0; i<n; i++)
	         scanf("%d", &v[i]);
	     max = 0;
	     for(int i=0; i<n; i++){
	         tmp = 1;
	         for(int j=i; j<n; j++){
	            tmp = tmp*v[j];
	            if(tmp > max)
	               max = tmp;
	         }
	         
	     }
	     
	     printf("Case #%d: The maximum product is %llu.\n\n", line, max);
	     line++;
	        
	}


}

