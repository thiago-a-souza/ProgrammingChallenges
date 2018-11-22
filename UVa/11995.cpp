#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <stack>
#include <queue>

using namespace std;

main(){
stack<int> s;
queue<int> q;
priority_queue<int> pq;
int n;
int op, nbr;
int val;
bool is_stack, is_queue, is_pq;

	while(scanf("%d",&n) != EOF){
        while(!s.empty())
		      s.pop();
		while(!q.empty())
		      q.pop();
		while(!pq.empty())
		      pq.pop();
		is_stack = true; 
		is_queue = true; 
		is_pq = true;
		for(int i=0; i<n; i++){
            scanf("%d %d",&op, &nbr);
            if(op == 1){
               if(is_stack)
                 s.push(nbr);
               if(is_queue)
                  q.push(nbr);
               if(is_pq)
                  pq.push(nbr);
            } else {
               if(!s.empty()){
                  val = s.top(); s.pop();
                  if(val != nbr)
                     is_stack = false;
               } else 
                  is_stack = false;
                  
               if(!q.empty()){
                  val = q.front(); q.pop(); 
                  if(val != nbr)
                    is_queue = false;
               } else 
                  is_queue = false;
                  
               if(!pq.empty()){
                  val = pq.top(); pq.pop();
                  if(val != nbr)
                    is_pq = false; 
               } else 
                  is_pq = false; 
            }
		}	
		
		if(is_stack && !is_queue && !is_pq)
		   cout << "stack" << endl;
		else if(!is_stack && is_queue && !is_pq)
		        cout << "queue" << endl;
		else if(!is_stack && !is_queue && is_pq)
		        cout << "priority queue" << endl;
		else if(is_stack || is_queue || is_pq)
		        cout << "not sure" << endl;
		else cout << "impossible" << endl;

		
		
	}

}

