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
int tests, n;
map<string, int> turtleid;
map<int, string> turtlename;
set<int> marked;
char str[100];
int index, pos;
int original[300], desired[300];
bool first = true;


	scanf("%d\n",&tests);
	while(tests--){
	      scanf("%d\n",&n);
	      index = 1;
	      turtleid.clear();
	      turtlename.clear();
	      for(int i=0; i<n; i++){
	          cin.getline(str,100);
	          turtleid[str] = index;
	          turtlename[index] = str;
	          original[i] = index;
	          index++;
	      }
	      
	      for(int i=0; i<n; i++){
	         cin.getline(str,100);
	         desired[i] = turtleid[str];
	      }
	      index = n-1; pos = 0;
	      marked.clear();
	      for(int i=n-1; i>=0 && index >=0; i--){
	         if(original[i] == desired[index])
	            index--;
	         else
	            marked.insert(original[i]);
	      }
	      
	      
	      for(int i=n-1; i>=0; i--)
	          if(marked.count(desired[i]) != 0)
	             cout << turtlename[desired[i]] << endl;
	      cout << endl;
	}
}

