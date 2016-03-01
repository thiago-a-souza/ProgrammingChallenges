#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>

#define MAX 50001

using namespace std;

int p[MAX];

int findSet(int x){

	if(x != p[x])
	   p[x] = findSet(p[x]);
	return p[x];
}

int main(){
int n, m;
int a, b, a_set, b_set;
int ans, line=1;

	while(true){
	      scanf("%d %d", &n, &m);
	      
	      if(n == 0 && m == 0)
	         break;
		  
		  for(int i=0; i<MAX; i++)
		      p[i] = i;
		  
		  for(int i=0; i<m; i++){
		      scanf("%d %d",&a,&b);
		      a_set = findSet(a);
		      b_set = findSet(b);
		      if(a_set != b_set)
		         p[a_set] = p[b_set];
		         
		  }
		  
		  ans = 0;
		  for(int i=1; i<=n; i++)
		      if(p[i] == i)
		         ans++;
		  printf("Case %d: %d\n",line, ans);       
		  line++;
	}

	return 0;
}

