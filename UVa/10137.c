/* The Trip */
#include <stdio.h>


double roundValue(double val){
double tmp;


	tmp=(int)val;
	val=(double)val-(int)val;
	val=val*1000;
	if((int)val%10>=5)
	  val=(int)(1+val*0.1);
	else
	  val=(int)(val*0.1);
	val=val*0.01;
	return (tmp+val);	
}



main(){
double value[1000], sum, sum2, valuediv;
int i, n;




	scanf("%d",&n);
	while(n!=0){
	     sum=0.0;
	     for(i=0; i<n; i++){
		scanf("%lf", &value[i]);
		sum+=value[i];
	     }
	     valuediv=sum/n;
	     valuediv=roundValue(valuediv);
	     
	     sum=0.0;
	     sum2=0.0;
	     for(i=0; i<n; i++)
		if((int)value[i]<=(int)valuediv)
		   if(((int)(((double)value[i]-(int)value[i])*100)<(int)(((double)valuediv-(int)valuediv)*100) || 
			((int)value[i]<(int)valuediv ) ))
		    	 sum+=(valuediv-value[i]);
	     for(i=0; i<n; i++)
		if((int)value[i]>=(int)valuediv)
		   if(((int)(((double)value[i]-(int)value[i])*100)>(int)(((double)valuediv-(int)valuediv)*100) || 
			((int)value[i]>(int)valuediv ) ))
		    	 sum2+=(value[i]-valuediv);

	     if((int)sum<(int)sum2)
		printf("$%.2lf\n",sum);
	     else
		  if((int)sum2<(int)sum)
		     printf("$%.2lf\n",sum2);
		  else
		       if( (int)(((double)sum-(int)sum)*100) < (int)(((double)sum2-(int)sum2)*100))
		          printf("$%.2lf\n",sum);
	     	       else
		          printf("$%.2lf\n",sum2);
	     scanf("%d",&n);
	}

}



