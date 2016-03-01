/* Peter’s Smokes 
Category: ad hoc Simulation
*/
#include <stdio.h>

main(){
int n, k;
int total, bituca;

int fumados;

	while((scanf("%d %d",&n,&k))!=EOF){

	    total = n;
	    fumados = 0;
	    
	    while(total - k >= 0){
	    	 total = total - k;
	    	 fumados += k;
	    	 total++;
	    }
	    fumados+= total;
	    printf("%d\n",fumados);

/*	    total = 0;
	    bituca = 0;
	    while(n>0){
	      total +=n;
	      bituca += n;
	      n = bituca/k;
	      bituca = bituca%k;
	    }
	    printf("%d\n",total);*/
	}
}

