/* 
Carmichael Numbers
Category: Math 
*/
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

#define MAXV 100


using namespace std;

vector<int> primos;

int ehPrimo(int n){

	if(n == 2)
	   return 1;
	if(n<=1 || n%2 == 0)
	   return 0;
	for(int i=3; i*i<=n; i+=2)
	   if(n%i == 0)
	      return 0;
	return 1;

}


int funcMod(int a, int b, int m){
int ans = 1;
	
	for(int i=0; i<b; i++)
	    ans = (ans*a)%m;
	return ans;

}


int main(){

/*
int a, n;

	primos.push_back(2);
	for(int i=3; i<65000; i++)
	   if(ehPrimo(i))
	      primos.push_back(i);
	      
	for(n=2; n<65000; n++){
	    for(a=2; a<n; a++)
	        if(funcMod(a,n,n) != a)
	           break;	
	    if(a == n && !binary_search(primos.begin(),primos.end(),n))
	       cout << "carmichael => " << n << endl;
	}
*/
// algoritmo acima gera os carmichael numbers

int ans[] = {561,1105,1729,2465,2821,6601,8911,10585,15841,29341,41041,46657,52633,62745,63973};
int n;

	while(true){
	     scanf("%d",&n);
	     if( n == 0)
	        break;
	     if(binary_search(ans,ans+15,n))
	        printf("The number %d is a Carmichael number.\n",n);
	     else
	        printf("%d is normal.\n",n);
	
	}
	

}


