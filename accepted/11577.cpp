#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAX 200

using namespace std;

main(){
int t;
char str[MAX];
int len;
int freq[30], maxfreq;

	scanf("%d\n",&t);
	while(t--){
	    memset(str, '\0', sizeof(str));
	    memset(freq, 0, sizeof(freq));
	    
		cin.getline(str, MAX);
		
		len = strlen(str);
		for(int i=0; i<len; i++){
			if(str[i] >= 'a' && str[i] <= 'z')
			   freq[str[i] - 'a']++;
			else if(str[i] >= 'A' && str[i] <= 'Z')
			        freq[str[i] - 'A']++;
		}
		maxfreq = 0;
		for(int i=0; i<30; i++)
		   if(freq[i] > maxfreq)
		      maxfreq = freq[i];
		for(int i=0; i<30; i++)
		    if(freq[i] == maxfreq)
		       printf("%c",i+'a');
		printf("\n");
		
		
	}
}

