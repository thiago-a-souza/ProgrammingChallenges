#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAX 10000

using namespace std;

char s[MAX];
int len;

bool check(int start, int end){
	if(start == end)
	  return ((s[start] == 'A') ? true : false);

	if(end - start >= 2 && s[end - 1] == 'A' && s[end] == 'B')
		return (check(start, end - 2) ? true : false);

	if (end - start >= 2 && s[start] == 'B' && s[end] == 'A')
		return (check(start + 1, end - 1) ? true : false);

	return false;
}


main(){
int t;

	scanf("%d\n",&t);
	while(t--){
	    memset(s, '\0', sizeof(s));
		scanf("%s",s);
		len = strlen(s);
		if(len == 1) {
		  if(s[0] == 'A')
			printf("SIMPLE\n");
		  else
			printf("MUTANT\n");
		} else if(len % 2 == 0) {
		          printf("MUTANT\n");
		} else {
		    if(!check(0, len - 1))
			   printf("MUTANT\n");
			else if(s[len - 1] == 'B')
					printf("FULLY-GROWN\n");
			else if(s[len - 1] == 'A')
					printf("MUTAGENIC\n");
		}
	}
}

