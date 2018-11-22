/* Word Length and Frequency - 17/11/2007*/
/* Category: String */
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <string>
#include <stack> 
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>

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

#define MAXLEN 100

using namespace std;

main(){
char buff[MAXLEN];
int count[31], length, sz = 0;
bool isChar = false;

	memset(count, 0, sizeof(count));

	while(true){
	      cin.getline(buff, MAXLEN);
	      length = strlen(buff);
	      if(!length)
	         return 0;
	      if(length == 1 && buff[0] == '#'){
	        ff(i,1,31)
	          if(count[i] > 0)
	             printf("%d %d\n",i,count[i]);
	        cout << endl;
	        memset(count, 0, sizeof(count));
	        isChar = false;
	        sz = 0;
	        continue;
	      }

	      f(i,length)
	        if((buff[i]>='a' && buff[i] <= 'z') || (buff[i]>='A' && buff[i] <= 'Z')){
	           sz++;
	           isChar = true;
	           if(i == length - 1){
	             count[sz]++;
	             sz = 0;
	             isChar = false;
	           }
	        }
	        else if(buff[i] == '-' || buff[i] == '\'')
	                isChar = true;
	        else if(buff[i] == '!' || buff[i] == '?' || buff[i] == ' ' || buff[i] == ',' ||
	                buff[i] == '.'){ 
	                if(isChar && buff[i-1] != '-')
	                  count[sz]++;
	                sz = 0;
	                isChar = false;
	                     
	             }
	      if(buff[length-1] != '-'){
	         isChar = false;
	         sz = 0;
	      }
	}


}


