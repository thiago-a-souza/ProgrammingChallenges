#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<set>

#define MAX 10000

using namespace std;

main(){
char line[MAX];
int len, num, eqA, eqB;
set<int> a, b;
set<int> :: iterator it, it2;

	while(cin.getline(line,MAX)){
	    // printf("%s\n",line);
	     len = strlen(line);
	     for(int i=0; i<len; i++){
	        if(line[i] != ' '){
	           num = atoi(&line[i]);
	          // printf("=> %d\n",num);
	           a.insert(num);
	           while(line[i] != ' ' && i<len)
	                 i++;
	        }
	     }
	     cin.getline(line,MAX);
	    // printf("%s\n",line);
	     len = strlen(line);
	     for(int i=0; i<len; i++){
	        if(line[i] != ' '){
	           num = atoi(&line[i]);
	        //   printf("=> %d\n",num);
	           b.insert(num);
	           while(line[i] != ' ' && i<len)
	                 i++;
	        }
	     }
		 eqA = 0; eqB = 0;
	     if( a == b){
	        cout << "A equals B"<< endl; 
	     } else {
	       for(it = a.begin(); it != a.end(); it++)
	        if( b.find(*it) != b.end())
	           eqA++;
	       for(it = b.begin(); it != b.end(); it++)
	        if( a.find(*it) != a.end())
	           eqB++; 
	      // cout << "eqA = " << eqA << " eqB = " << eqB << endl;
	       if(eqA == 0 && eqB == 0)
	          cout << "A and B are disjoint" << endl;
	       else if(eqA == a.size())
	              cout << "A is a proper subset of B" << endl;
	       else if(eqB == b.size())
	              cout << "B is a proper subset of A" << endl;
	       else cout << "I'm confused!" << endl;
	     
	     }
	    // cout << " -------- " << endl;
	     a.clear(); b.clear();
	     
	}

}