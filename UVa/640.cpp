#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#include<cmath>
#include<set>
#include<cstdlib>
#include<algorithm>

#define MAX 1000100


using namespace std;

main(){
long  val[MAX], aux, sum;

memset(val,0,sizeof(val));

        for(int h=0; h<10; h++)
		for(int i=0; i<10; i++)
	    for(int j=0; j<10; j++)
	    for(int k=0; k<10; k++)
	    for(int l=0; l<10; l++)
	    for(int m=0; m<10; m++)
	    for(int n=0; n<10; n++)
	    for(int o=0; o<10; o++){
	        sum = o + n*10 + m*100 + l*1000 + k*10000 + j*100000 + i*1000000 + h*10000000 + h+ i + j + k + 
	        l + m + n + o;
	        if(sum < MAX)
	           val[sum]++;
	    }
		
		for(long i=1; i<1000001; i++)
		    if(val[i] == 0)
		       cout << i << endl;
		   

}

