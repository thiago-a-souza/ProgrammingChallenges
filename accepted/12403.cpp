#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

main(){
long long sum = 0, tmp;
int n;
char str[100];

	scanf("%d",&n);
	while(n--){
		scanf("%s",str);
		if(strcmp(str,"donate") == 0){
		  cin >> tmp;
		  sum += tmp;
		}
		else if(strcmp(str,"report") == 0){
		        cout << sum << endl;
		}
		        
		
	}

}

