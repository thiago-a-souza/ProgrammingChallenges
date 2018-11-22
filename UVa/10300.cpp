/* Ecological Premium */
/* Category: Ad Hoc - Very Easy */
#include<iostream>
#include<cstdio>

using namespace std;

main(){
int n, f, x, y, z;
int sum;
	scanf("%d",&n);
	while(n--){
	     sum = 0;
	     scanf("%d",&f);
	     while(f--){
	          scanf("%d %d %d",&x,&y,&z);
	          sum += x*z;
	     }
	     printf("%d\n",sum);
	}
}



