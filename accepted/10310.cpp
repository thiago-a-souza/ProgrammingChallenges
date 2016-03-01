#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#include<cmath>
#include<set>
#include<cstdlib>

main(){
int n;
double x1, y1, x2, y2, x3, y3;
double gopher, dog;
bool b;
		while(scanf("%d %lf %lf %lf %lf",&n, &x1,&y1,&x2,&y2) != EOF){
		      b = false;
		    //  printf("==> %lf %lf\n",x1,y1);
		      for(int i=0; i<n; i++){
		          scanf("%lf %lf",&x3,&y3);
		          if(b)
		            continue;
		          gopher = sqrt((x1-x3)*(x1-x3) + (y1-y3)*(y1-y3));
		          dog = sqrt((x2-x3)*(x2-x3) + (y2-y3)*(y2-y3));
		          
		          if(gopher*2.0 <= dog){
		            printf("The gopher can escape through the hole at (%.3lf,%.3lf).\n",x3,y3);
		            b = true;
		          }
		      }
		      if(b == false)
		         printf("The gopher cannot escape.\n");
		
		}

}

