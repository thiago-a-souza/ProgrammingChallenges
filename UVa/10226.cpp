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

#define MAX 10001
using namespace std;

typedef struct {
char name[50];
int cont;
} Node;

Node node[MAX];

int cmp(const void * x, const void * y){
  Node a = *(Node*)x;
  Node b = *(Node*)y;
  return strcmp(a.name,b.name);
}


main(){
map<string, int> m;
int t;
char str[50];
int len, index, tmp;
int total;
bool first = true;

		scanf("%d\n\n",&t);
		while(t--){
		     m.clear();
		     index = 0;
		     total = 0;
		     for(int i=0; i<MAX; i++)
		        memset(node[i].name, '\0', 50);
		     if(first)
		       first = false;
		     else
		       printf("\n");
		     
		     while(true){
		           cin.getline(str,50);
	 	           len = strlen(str);
	 	       //    cout << "=>" << str << "<=" << endl;
	 	           if(len == 0)
	 	              break;
                   total++;
                   
	 	           if(m.count(str) > 0)
	 	              node[m[str]].cont++;
	 	           else {
	 	               strcpy(node[index].name, str);
	 	               m[str] = index;
	 	               node[index].cont = 1;    
	 	               index++;
	 	           }
	 	              
		     }  
		     qsort(node,index, sizeof(Node), cmp); 
		     for(int i=0; i<index; i++)
		         printf("%s %.4lf\n",node[i].name, (((double)node[i].cont)/((double)total))*100.0 );
		}


}

