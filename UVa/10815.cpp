#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#include<cmath>
#include<set>
#include<cstdlib>
#include<algorithm>
#include<queue>

#define MAXL 1000

using namespace std;

main(){
char line[MAXL], tmp[MAXL];
int i, len, start, end;
set<string> s;
set<string> :: iterator it;

	while(cin.getline(line,MAXL)){
	     len = strlen(line);
	     for(i=0; i<len; i++)
	         line[i] = tolower(line[i]);
	     start = 0;
	     
	     while(start < len){
	         while(start < len && !(line[start] >= 'a' && line[start] <= 'z'))
	               start++;
	       
	         end = start+1;
	         
	         while(end < len && line[end] >= 'a' && line[end] <= 'z')
	              end++;
	         
	         
	         if(end > start+1 || (start+1 == end && line[start] >='a' && line[start] <= 'z') ){
	             memset(tmp,'\0', sizeof(tmp));
	             for(int j=0, i=start; i<end; i++, j++)
	                 tmp[j] = line[i];
	             s.insert(tmp);
	         }
	         start = end;
	     }
	     
	           
	}
	
	for(it = s.begin(); it != s.end(); it++)
	   cout << *it << endl;

}

