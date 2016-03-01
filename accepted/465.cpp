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
#include <climits>

#define MAX 100000

using namespace std;

main(){
char a[MAX], b[MAX], oper;
int len_a, len_b;
bool big;
long double x, y;

		while(scanf("%s %c %s",a,&oper,b) != EOF){
		     printf("%s %c %s\n",a,oper,b);
		     len_a = strlen(a);
		     len_b = strlen(b);
		     
		     big = false;
		     
		     while(len_a > 1 && a[0] == '0'){
		          for(int i=0; i<len_a; i++)
		             a[i] = a[i+1];
		          len_a--;
		     }
		     
   		     while(len_b > 1 && b[0] == '0'){
		          for(int i=0; i<len_b; i++)
		             b[i] = b[i+1];
		          len_b--;
		     }
		     
		     if(len_a > 10)
		        printf("first number too big\n");
		     else if(atof(a) > 2147483647)
		             printf("first number too big\n");
		     
		     
		     
		     if(len_b > 10)
 		        printf("second number too big\n");
		     else if(atof(b) > 2147483647)
		            printf("second number too big\n");
		     
		     if(len_a > 10 && len_b > 10)
		        printf("result too big\n");
		     else {
		        x = atof(a);
		        y = atof(b);
		        if(oper == '+')
		           x = x + y;
		        else
		           x = x*y;
		        if(x > 2147483647)
		          printf("result too big\n");
		     }

		     
		      
		}

}

