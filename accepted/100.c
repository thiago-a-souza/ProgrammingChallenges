/* 3n + 1 */
/* Category: Ad Hoc, Simulation */
/* Little trick: x might be greater than y */

#include <stdio.h>


int result(unsigned long int x){
int cont=0;

	while(x!=1){
		if(x%2)
		  x=3*x+1;
		else
		  x=x/2;
		cont++;
	}	
	return cont;
}

main(){
unsigned long int x,y,temp, i, guarda=0;

	while((scanf("%d", &x))!=EOF && (scanf("%d", &y))!=EOF){
		if(y>=x)
			for(i=x; i<=y; i++){
				temp=result(i);
				if(temp>guarda)
					guarda=temp;
			}
		else
			for(i=y; i<=x;i++){
				temp=result(i);
				if(temp>guarda)
					guarda=temp;
			}
		printf("%d %d %d\n", x, y, guarda+1);
		guarda=0;
	}
}
		
