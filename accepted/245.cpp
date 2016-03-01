#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<list>
#include<set>
#include <iterator>

#define MAX 10000
#define MIN(a,b) ((a) < (b) ? (a) : (b))

using namespace std;

int main(){
char line[MAX];
int len;
int index, start;
int nbr;

bool first = true;
string tmp;
list<string> l;
list<string>::iterator it;

	while(true){
	     cin.getline(line,MAX);
	     if(strcmp(line, "0") == 0)
	        break; 
	     
	     if(!first)
	        printf("\n");
	     first = false;
	     len = strlen(line);
	     index = 0;
	     while(index < len){
	           start = index;
	           if(line[start] >= '0' && line[start] <= '9'){
	             nbr = atoi(&line[start]);
	             it = l.begin();
	             for(int i=0; i<nbr-1; i++)
	                it++;
	             tmp = *it;
	             l.erase(it);
	             l.push_front(tmp);
	             
	             cout << tmp ;
	            
	             while(start < len && line[start] >= '0' && line[start] <='9')
	                   start++;
	           }

	           while(start < len && !(line[start] >= '0' && line[start] <= '9' ) && 
	                 !((line[start] >= 'a' && line[start] <= 'z') || (line[start] >= 'A' && line[start] <= 'Z'))){
	                    printf("%c", line[start]);
	                    start++;
	           }
	           index = start;      
	           if(line[index] >= '0' && line[index] <= '9')
	              continue;
	           while(index < len && ((line[index] >= 'a' && line[index] <= 'z') || (line[index] >= 'A' && line[index] <= 'Z')))
	                 index++;
	           
	           tmp = string(line+start, index - start);
               if((line[start] >= 'a' && line[start] <= 'z') || (line[start] >= 'A' && line[start] <= 'Z'))
                   l.push_front(tmp);
               cout << tmp;


	     }
	          

	}
	
	printf("\n");
	return 0;
}

