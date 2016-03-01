#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack> 
#include <set>
#include <map>
#include <queue>
#include <climits>
#include <cmath>

#define MAX 1000000

int ans[MAX], len;

using namespace std;


main(){
int n, m;
int v[MAX], tmp, min;
set<int> s;
long long cont;

	while(true){
		scanf("%d %d",&n,&m);
		if(n == 0 && m == 0)
		   break;
		s.clear();
		if(n > m){
		   for(int i=0; i<n; i++){
  		      scanf("%d",&tmp);
  		      s.insert(tmp);
  		   }
  		   for(int i=0; i<m; i++)
  		      scanf("%d",&v[i]);  		   
		} else {
		    for(int i=0; i<n; i++)
		        scanf("%d",&v[i]);
		    for(int i=0; i<m; i++){
		        scanf("%d",&tmp);
		        s.insert(tmp);
		    }
		}  
		
		len = 0; 
		cont = 0;
		
		if(n < m)
		   min = n;
		else
		   min = m;
		
		for(int i=0; i<min; i++)
		   if(s.count(v[i]) > 0)
		      cont++;
		
		cout << cont << endl;  
		   
	}

}


