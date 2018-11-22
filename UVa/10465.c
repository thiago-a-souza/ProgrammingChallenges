/* Homer Simpson - 23/05/2007 
	se beers[i-m]==beers[i-n]
	   entao burguers[i] = burguers[i-m]+1
	         beers[i] = beers[i-m]
	senao se beers[i-m] < beers[i-n]
		entao burguers[i] = burguers[i-m]
		      beers[i] = beers[i-m]
	senao
	      burguers[i] = burguers[i-n]
	      beers[i] = beers[i-n]
*/

#include<stdio.h>

#define MAX 10001

main(){
register int i;
int burguers[MAX], beers[MAX];
int m, n, t, min, max, max2;

	while((scanf("%d %d %d",&m,&n,&t))!=EOF){
	     for(i=0; i<=t; i++){
	        burguers[i]=0;
	        beers[i]=0;
	     }
	     if(m<n)
	       min = m;
	     else
	       min = n;
	       
	     for(i=0; i<min; i++)
	        beers[i]=i;
	     for(i=min; i<=t; i++){
	        if(i-m>=0 && i-n>=0){
	           if(beers[i-m]==beers[i-n]){
	               if(burguers[i-m]>burguers[i-n])
	                 burguers[i]=burguers[i-m]+1;
	               else
	                 burguers[i]=burguers[i-n]+1;
		       beers[i]=beers[i-m];
		    }
	            else
		        if(beers[i-m]<beers[i-n]){
		           burguers[i]=burguers[i-m]+1;
		           beers[i]=beers[i-m];
		        }
		        else{
		           burguers[i]=burguers[i-n]+1;
		           beers[i]=beers[i-n];
		        }
		}
		else if(i-m<0 && i-n>=0){
		        beers[i] = beers[i-n];
		        burguers[i] = burguers[i-n]+1;
		     }
		     else if(i-m>=0 && i-n<0){
		             beers[i] = beers[i-m];
		             burguers[i] = burguers[i-m]+1;
		          }
	     }  
	     if(beers[t]==0)
	       printf("%d\n", burguers[t]);
	     else
	       printf("%d %d\n",burguers[t],beers[t]);

	}
}

