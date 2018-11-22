#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAX 1000
#define CONNECTION 1
#define QUESTION 2

using namespace std;

int N, type, pc1, pc2;
int p[MAX];

int findSet(int x){
	if(x != p[x])
	  p[x] = findSet(p[x]);
	return p[x];
}

void readLine(char *str, int len){
	type = -1;
	for(int i=0; i<len; i++)
	   if(str[i] == 'c' || str[i] == 'q'){
	     if(str[i] == 'c')
	        type = CONNECTION;
	     else 
	        type = QUESTION;
	     break;
	   }
	for(int i=1; i<len; i++)
	   if(str[i] >= '0' && str[i] <= '9'){
	      pc1 = atoi(&str[i]);
	      break;
	   }
	for(int i=len-1; i>0; i--)
	    if(!(str[i] >= '0' && str[i] <= '9')){
		   pc2 = atoi(&str[i+1]);
		   break;
		}
}

main(){
int tests;
char str[MAX];
int len;
int u_set, v_set;
int suc, unsuc;
bool first = true;

	scanf("%d\n",&tests);
	while(tests--){
		 scanf("%d\n",&N);
		 for(int i=0; i<=N; i++)
		     p[i] = i ;
		 suc = 0; unsuc = 0;
		 if(first)
		    first = false;
		 else 
		    printf("\n");
		 while(true){
		 	cin.getline(str, MAX);
		 	len = strlen(str);
		 	if(len == 0)
		 	   break;
		 	   
		 	readLine(str, len);
		 	u_set = findSet(pc1);
		 	v_set = findSet(pc2);
		 	
		 	if(type == CONNECTION){
		 	   p[u_set] = p[v_set];
		 	} else if(type == QUESTION){
		 			  if(u_set == v_set)
		 			     suc++;
		 			  else
		 			     unsuc++;
		 	}
		 }
		 printf("%d,%d\n",suc,unsuc);
	}
}

