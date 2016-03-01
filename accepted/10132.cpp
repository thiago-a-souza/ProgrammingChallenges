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


set<string> combinations[300];
set<string> result;
int lines;

void intersectionOfSets(){
set<string> :: iterator it;
set<string> ans;

    result.clear();
    for(it = combinations[0].begin(); it != combinations[0].end(); it++)
        result.insert(*it);
    
    for(int i=1; i<lines; i++){
       for(it = combinations[i].begin(); it != combinations[i].end(); it++)
           if(result.count(*it) > 0)
              ans.insert(*it);
       if(ans.size() > 0){
          result.clear();
          for(it = ans.begin(); it != ans.end(); it++)
              result.insert(*it);
          ans.clear();
       }
          
    }
                
    
}

void showSet(){
set<string> :: iterator it;

     if(result.begin() != result.end()){
        it = result.begin();
        cout << *it << endl;
     }
}

main(){
int tests;
char str[300][300], sorted[300][300], tmp[300];
int len_str[300], len_sorted[300];
int index, max_size;
bool first = true;

	scanf("%d\n\n",&tests);
	while(tests--){
	     lines = 0;
	     memset(str,'\0', sizeof(str));
	     memset(sorted,'\0', sizeof(sorted));
	     index = 0;
	     max_size = 0;
	     
	     while(true){
	          cin.getline(str[lines],300);
	          len_str[lines] = strlen(str[lines]);
	          if(len_str[lines] == 0)
	             break;
	          if(len_str[lines] > max_size)
	             max_size = len_str[lines];
	          lines++;
	     }
	     for(int i=1; i<=max_size; i++){
	        for(int j=0; j<lines; j++){
	            if(len_str[j] == i){
	               strcpy(sorted[index], str[j]);
	               len_sorted[index] = i;
	               index++;
	            }
	        }
	     }
        for(int i=0; i<lines; i++)
            combinations[i].clear();
        index = 0;
	    for(int i=0,j=lines-1; i<lines/2; i++, j--){
	       memset(tmp,'\0',sizeof(tmp));
	       strcat(tmp,sorted[i]);
	       strcat(tmp,sorted[j]);
	       combinations[index].insert(tmp);
	       memset(tmp,'\0',sizeof(tmp));
	       strcat(tmp,sorted[j]);
	       strcat(tmp,sorted[i]);
	       combinations[index].insert(tmp);
	       index++;
	    }
        intersectionOfSets();
	    if(first)
	       first = false;
	    else
	       printf("\n");
	    showSet();
	    
	     
	     
	}
}

