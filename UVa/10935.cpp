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
#include <deque>

using namespace std;

main(){
int n;
deque<int> q;
//bool first = true;

	while(true){
	     scanf("%d",&n);
	     if(n == 0)
	        break;
	     
	     if(n == 1){
	       printf("Discarded cards:\nRemaining card: 1\n");
	       continue;
	     } else if(n < 0){
	               printf("Discarded cards:\nRemaining card: 0\n");
	               continue;
	     }  
	        
	     for(int i=1; i<=n; i++)
	        q.push_back(i);
	        
	        
	     printf("Discarded cards: ");
	     while(q.size() > 2){
	           cout << q.front() << ", ";
	           q.pop_front();
	           q.push_back(q.front());
	           q.pop_front();
	     }
	     cout << q.front() << endl;
	     q.pop_front();
	     cout << "Remaining card: " << q.front() << endl;
	     q.pop_front();
	     q.clear();    
	}
}

