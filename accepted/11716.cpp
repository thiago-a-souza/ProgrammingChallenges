#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

#define MAX 10005

using namespace std;


main(){
int T, len;
char str[MAX];

	scanf("%d\n",&T);
	while(T-- > 0){
	    memset(str, '\0', sizeof(str));
		cin.getline(str, MAX);
		len = strlen(str);
		double root = sqrt(len);
		int sq = (int)root;

		if(fabs((double)sq - root) > 0.0000001 && sq*sq != len)
		   cout << "INVALID" << endl;
		else {
		 
		    for(int i=0; i<sq; i++)
		       for(int j=i, k=0; k<sq; k++, j=j+sq )
		    	  printf("%c",str[j]);
		    printf("\n");
		}
	}
}

