#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAX 100000

using namespace std;

char s[MAX];
int len;

bool isSlump(int start, int end){
int i;

	if(end - start < 2 || (s[start] != 'D' && s[start] != 'E') || s[start+1] != 'F') 
	   return false;
	i = start + 2;
	while(i <= end && s[i] == 'F')
	      i++;
	if(i == end && s[i] == 'G')
	   return true;
	return isSlump(i, end);
}

bool isSlimp(int start, int end){
int i, pos;

    if(start > end)
       return false;

	if(start == end || s[start] != 'A')
	   return false;
	if(start + 1 == end && s[start+1] == 'H')
	   return true;
	if(s[end] != 'C')
	   return false;
	if(s[start+1] == 'B')
	   return isSlimp(start+2, end - 1);
	return isSlump(start + 1, end - 1);
}

main(){
int t;

	scanf("%d\n",&t);
	printf("SLURPYS OUTPUT\n");
	while(t--){
	    memset(s, '\0', sizeof(s));
		scanf("%s",s);
		len = strlen(s);
		bool ans = false;
		for(int i=len-1; i>=0; i--){
		    if(s[i] == 'C' || s[i] == 'H'){
		       ans = ans || (isSlimp(0,i) && isSlump(i+1, len-1));
		    }
		}
		if(ans)
		  cout << "YES" << endl;
		else
		  cout << "NO" << endl;
	}
	printf("END OF OUTPUT\n");
}

