/* I love Strings!!! - 31/01/2008 */
/* Category: strings KMP Knuth Morris Pratt */
/* Trick: repeated inputs, then use maps! */
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <stack>  

#define foreach(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define mp(a,b) make_pair((a),(b))
#define all(c) (c).begin(),(c).end()
#define ff(i,v,n) for(int i=v; i<n; i++)
#define f(i,n) ff(i,0,n)
#define pb push_back
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define ABS(a) ((a) > 0 ? (a) : (-a))
#define debug(x)
#define MAXLEN1 100010
#define MAXLEN2 1010

using namespace std;

char text[MAXLEN1], pattern[MAXLEN2];
int n, m, next[MAXLEN2];

void getNext(){
int j;

	next[0] = -1;

	for(int i=1; i<m; i++){
		j = next[i-1];
		while(j >= 0 && pattern[i-1] != pattern[j])
		      j = next[j];
		next[i] = j+1;
	}
	
}

bool kmp(){
int i, j;


	i = j = 0;
	while(i<n){
	    if(j == -1)
	      i++, j=0;
	    else if(pattern[j] == text[i]){
		        j++, i++;
		        if(j >= m)
				  return true;
	         }
		else
		     j = next[j];
		if(m-j > n-i)
		   return false;
	}
	return false;
}

main(){
int tests, queries;
map<string,bool> same;

	scanf("%d",&tests);
	while(tests--){
		scanf("%s",text);
		scanf("%d",&queries);
		f(i,queries){
		  scanf("%s",pattern);
		  if(same.find(pattern) != same.end()){
		    if(same[pattern] == true)
		       printf("y\n");
		    else
		       printf("n\n");
		    continue;
		  }
		  n = strlen(text);
	      m = strlen(pattern);
	      if(m > n || m == 0){
	        printf("n\n");
	        continue;
	      }
		  getNext();
		  if(kmp()){
		    printf("y\n");
		    same[pattern] = true;
		  }
		  else{
		    printf("n\n");
		    same[pattern] = false;
		  }
		}
		same.clear();
	
	}

}
