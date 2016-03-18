#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack> 
#include <set>

#define MAX 5000

using namespace std;



int v[MAX], t, n;
set<string> set_sums;



bool cmp(string a, string b){
int min = a.size();
    
    if(b.size() < min)
      min = b.size();
    
    for(int i=0; i<min; i++){
       if(a[i] < b[i])
          return true;
       if(a[i] > b[i])
          return false;
    }
    if(a.size() > b.size())
       return true;
    return false;
    
}


void backtrack(int k, int *a){
int sum = 0, len;
char str[MAX];
bool first;
		if(k > n)
		   return;
		for(int i=0; i<k; i++){
		   sum += (a[i]*v[i]);
		   if(sum > t)
		      return;
		}

	    first = true;
        memset(str,'\0', sizeof(str));
        
		if(sum == t){
		  for(int i=0; i<k; i++)
		      if(a[i] == 1){
		         if(first)
		           sprintf(str,"%d",v[i]);
		         else
		           sprintf(str,"%s+%d",str,v[i]);
		         first = false;
		      }
		  len = strlen(str);
		  if(len > 0)
		     set_sums.insert(str);
		}

		a[k] = 0;
		backtrack(k+1, a);
		a[k] = 1;
		backtrack(k+1, a);
		        
}


main(){
int a[MAX], aux;
set<string> :: iterator it;
vector<string> vstr;
string tmp;



	while(true){
	      scanf("%d %d",&t,&n);
	      if(n == 0 || t == 0)
	         break;
	         
   	      set_sums.clear();
	      vstr.clear();
	      for(int i=0; i<MAX; i++)
	          a[i] = 0;

	      for(int i=0; i<n; i++)
	         scanf("%d",&v[i]);

          for(int i=0; i<(n-1); i++)
	         for(int j=i+1; j<n; j++)
	            if(v[i] < v[j]){
	              aux = v[j];
	              v[j] = v[i];
	              v[i] = aux; 
	            }

	      backtrack(0, a);
	      printf("Sums of %d:\n",t);
	      if(set_sums.size() > 0){
	         for(it = set_sums.begin(); it != set_sums.end(); it++)
	           vstr.push_back(*it);

             for(int i=0; i<vstr.size()-1; i++)	         
                 for(int j=i+1; j<vstr.size(); j++)
                     if(cmp(vstr[i], vstr[j])){
                        tmp = vstr[i];
                        vstr[i] = vstr[j];
                        vstr[j] = tmp;
                     }

	         for(int i=0; i<vstr.size(); i++)
	            cout << vstr[i] << endl;
	         
	      } else {
	         printf("NONE\n");
	      }
	 
	}
}

