#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>

#define MAX 1000000

using namespace std;

main(){
map<string, int> freq;
char str[MAX], tmp[15], ans[15];
int n, len, max_freq;

	while(scanf("%d ",&n) !=EOF){
	    memset(str, '\0', sizeof(str));
		cin.getline(str, MAX);
		len = strlen(str);
		max_freq = 0;
		memset(ans, '\0', sizeof(ans));
		freq.clear();
		for(int i=0; i<=len-n; i++){
		    memset(tmp, '\0', sizeof(tmp));
		    memcpy(tmp, &str[i], n);
		    freq[tmp] = freq[tmp] + 1;
		    if(freq[tmp] > max_freq){
		       memcpy(ans, tmp, n);
		       max_freq = freq[tmp];
		       
		    }
		}
		cout << ans << endl;
	}
}

