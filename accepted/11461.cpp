#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <inttypes.h>
#include <ctype.h>
#include <algorithm>
#include <utility>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

main(){
int v[320], a, b, index, count;

        
		for(int i=1; i<320; i++)
		   v[i] = i*i;

		while(true){
		     scanf("%d %d",&a,&b);
		     if(a == 0 && b == 0)
		        break;
		     for(int i=0; i<320; i++)
		        if(v[i] >= a){
		           index = i;
		           break;
		        }
		     count = 0;
		     for(int i=index; i<320; i++){
		        if(v[i] > b)
		          break;
		        count++;
		     }
		     printf("%d\n",count);
		}
}

