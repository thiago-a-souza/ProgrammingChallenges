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

#define MAX 1000

using namespace std;

main(){
int m, n, len, last;
char str[MAX], tmp[MAX];
long long sal;
map<string, int> dic;



	scanf("%d %d\n",&m,&n);
	for(int i=0; i<m; i++){
	   scanf("%s %llu\n",str,&sal);
	   dic[str] = sal;
	}
	sal = 0;
	while(true){
	     cin.getline(str,MAX);
	     len = strlen(str);
	     if(len == 1 && str[0] == '.'){
	        n--;
	        printf("%llu\n",sal);
	        sal = 0;
	     }
	     if(n == 0)
	        break;

	     last = 0;
	     for(int i=0; i<=len; i++)
	        if(str[i] == ' ' || str[i] == '	' || i == len){
	           memset(tmp, '\0', sizeof(tmp));
	           strncpy(tmp, &str[last], i-last); 
	           sal += dic[tmp];
	           while(str[i] == ' ' || str[i] == '	')
	                 i++;
	           last = i;
	        }
	           
	}

}

