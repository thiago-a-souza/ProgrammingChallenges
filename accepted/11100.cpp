#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <vector>

#define MAX 10000
#define INF 999999999
using namespace std;

main(){
int n, v, len, sz, index;
priority_queue<int> heap;
vector<int> ans[MAX];
bool first = true;

	while(true){
		scanf("%d",&n);
		if(n == 0)
		   break;

		if(first)
		   first = false;
		else
		   cout << endl;
		   
		for(int i=0; i<len; i++)
		   ans[i].clear();
		   
		for(int i=0; i<n; i++){
			scanf("%d",&v);
			heap.push(-v);
		}
		len = 0;
		while(!heap.empty()){
			v = -heap.top();
			heap.pop();
			sz = INF;
			for(int i=0; i<len; i++){
			    if(ans[i].back() < v && ans[i].size() < sz){
			       sz = ans[i].size();
			       index = i;
			    }
			}
			if(sz >= INF)
			   ans[len++].push_back(v);
			else
			   ans[index].push_back(v);
			
			
		}
		cout << len << endl;
		for(int i=0; i<len; i++){
		   for(int j=0; j<ans[i].size(); j++){
		       if(j == 0)
		          printf("%d", ans[i][j]);
		       else
		          printf(" %d", ans[i][j]);
		   }
		   printf("\n");
	    }
		
		
		   
	}
}

