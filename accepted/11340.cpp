#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>

#define MAX 10100

using namespace std;

int main(){
long int n, k, m, tmp, sum;
char ch;
map<long int, long int> value;

	scanf("%ld\n",&n);

	while(n--){
	   scanf("%ld\n",&k);
	   value.clear();
	   sum = 0;
	   for(int i=0; i<k; i++){
	       ch = getchar();
	       scanf("%ld\n",&tmp);
	       value[(int)ch] = tmp;
	   }
	   scanf("%ld\n",&m);

	   for(int i=0; i<m; i++){
	      while(true){
	         ch = getchar();
	         if(ch == '\n' || ch == '\r' || ch == EOF)
	            break;
             sum += value[(int)ch];
	      }
	   }
       printf("%ld.%02ld$\n",sum/100,sum%100);
	}

}

