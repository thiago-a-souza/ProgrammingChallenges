#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAX 1000

using namespace std;


main(){
int t, sz;
char str[MAX];

	scanf("%d",&t);
	while(t--){
		cin >> str;
		sz = strlen(str);
		bool ans = false;
		for(int l = 1; l<=sz/2; l++) {
		    if((sz/l)*l != sz)
		       continue;
			bool b = true;
			for(int j=0, k=0; j<sz && b; j++, k=((k+1)%l)) {
				if(str[j] != str[k]){
					b = false;
				}
			}
			if(b) {
			    ans = true;
				printf("%d\n",l);
				break;
			}
		}
		if(!ans)
			printf("%d\n",sz);
		if(t > 0)
			printf("\n");
	}
}