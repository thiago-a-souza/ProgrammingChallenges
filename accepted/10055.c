/* Hashmat the Brave Warrior */
#include <stdio.h>

main(){
long long  i,j,res;

	while((scanf("%lld %lld",&i,&j))!=EOF){
	     res = i-j;
	     if(res<0)
		res=-res;
	     printf("%lld\n",res);
	}
}

