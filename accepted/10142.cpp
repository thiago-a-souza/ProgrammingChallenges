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


using namespace std;

main(){
int tests, cand, ballots, max_vote, min_vote;
int rank[30], len, tmp, removed;
bool first = true, deleted[30], b;
char names[30][100], str[10000];
queue<int> q[1001];

	scanf("%d",&tests);
	while(tests--){
	     scanf("%d\n", &cand);
	     for(int i=0; i<cand; i++){
	        cin.getline(names[i],100);
	     }
	     ballots = 0;
	     while(true){
	          cin.getline(str,10000);
	          len = strlen(str);
	          
	          if(len == 0)
	             break;
	          while(!q[ballots].empty())
	                q[ballots].pop();
	                
	          for(int i=0; i<len; i++){
	             tmp = atoi(&str[i]);
	             q[ballots].push(tmp-1);
	            while(i<len && str[i] != 9 && str[i] != 32)
	                   i++;
	             	             
	          }
	          ballots++;
	     }
	     for(int i=0; i<30; i++)
	        deleted[i] = false;
	     
	     while(true){
	           max_vote = 0;
	           for(int i=0; i<30; i++)
	               rank[i] = 0;
	           
	           for(int i=0; i<ballots; i++){
	              while(q[i].empty() == false && deleted[q[i].front()] == true)
	                    q[i].pop();
	              if(q[i].empty() == false){
	                tmp = q[i].front(); 
	                rank[tmp]++;
	                if(rank[tmp] > max_vote)
	                   max_vote = rank[tmp];
	              }
	           }
	           if(max_vote*2 > ballots)
	              break;
	              
	           min_vote = max_vote;
	           for(int i=0; i<cand; i++)
	               if(rank[i] < min_vote && deleted[i] == false)
	                  min_vote = rank[i];
	           if(min_vote == max_vote)
	              break;
	           removed = 0;
	           
               for(int i=0; i<ballots; i++)
                  if(q[i].empty() == false && rank[q[i].front()] == min_vote){
                     deleted[q[i].front()] = true;
                     q[i].pop();
                     while(q[i].empty() == false && deleted[q[i].front()] == true){
                           q[i].pop();
                     }
                     removed++;
                  }
               if(removed == 0){
                  for(int i=0; i<cand; i++)
                     if(rank[i] == min_vote)
                        deleted[i] = true;
                  b = false;
                  for(int i=0; i<cand; i++)
                      if(rank[i] > min_vote && rank[i] < max_vote){
                         b = true;
                         break;
                      }
                  if(b == false)       
                     break;
               }
        }
        if(first)
           first = false;
        else
           printf("\n");
           
        for(int i=0; i<cand; i++)
           if(rank[i] == max_vote)
              printf("%s\n",names[i]);	     
	     
	     
	}
	
	
}

