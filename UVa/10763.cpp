#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<map>

using namespace std;

int main(){
map< pair<int, int>, int> exch; 
int a, b, aux, n;
int sum;



	while(true){
	     scanf("%d",&n);
	     if(n == 0)
	        break;
	     exch.clear();
	     sum = 0;
	     for(int i=0; i<n; i++){
	         scanf("%d %d",&a, &b);
	         aux = exch[make_pair(b, a)];
	         if(aux > 0){
	            exch[make_pair(b, a)] = aux - 1;
	            sum--;
	         } else {
	            aux = exch[make_pair(a, b)];
	            exch[make_pair(a, b)] = aux + 1;
	            sum++;
	         }
	     }
	     
	     if(sum == 0)
	        printf("YES\n");
	     else
	        printf("NO\n");
	     
	}
}

