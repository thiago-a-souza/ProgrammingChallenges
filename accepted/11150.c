/* Cola */
#include <stdio.h>


main(){
int n, tomou, deb;

	while((scanf("%d",&n))!=EOF){
	tomou = 0;
	deb = 0;
		while(n!=0 && n!=1){
		     if(n%3==0){
			if(deb==0){
			  tomou = tomou + n;
			  n = n/3;
			}
			else{
			  tomou = tomou + deb;
			  n = n - deb;
			  deb = 0;
			}
		     }
		     else if((n+1)%3==0){
			    if(deb == 0){
			      tomou = tomou + n;
			      n = (n+1)/3;
			      deb++;
			    }
			    else{
			      tomou = tomou + deb;
			      n = n - deb;
			      deb = 0;
			    }
			  }
		     else if((n+2)%3==0){
			    if(deb == 0){
			      tomou = tomou + n;
			      n = (n+2)/3;
			      deb += 2;
			    }
			    else{
			      tomou = tomou + deb;
			      n = n - deb;
			      deb = 0;
			    }
			  }

		}		if(n==1)
		  tomou++;
		printf("%d\n", tomou);
	}
}
