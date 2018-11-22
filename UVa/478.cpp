#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<cmath>

using namespace std;

#define R 1
#define C 2
#define T 3

typedef struct{
int type;
double x1, y1, x2, y2, x3, y3;
double r;
} TFig;

main(){
char ch;
int count = 0;
int sum;
double x1, y1, x2, y2, x3, y3;
double s, s2, s3, s4;
vector<TFig> v;
TFig temp;

	while(true){
	   scanf("%c",&ch);
	   if(ch == '*')
	      break;
	   if(ch == 'r'){
	     scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2);
	     temp.type = R;
	     temp.x1 = x1;
	     temp.y1 = y1;
	     temp.x2 = x2;
	     temp.y2 = y2;
	     v.push_back(temp);
	   } else if(ch == 'c') {
	            scanf("%lf %lf %lf",&x1,&y1,&x2);
	            temp.type = C;
	            temp.x1 = x1;
	            temp.y1 = y1;
	            temp.r = x2;
	            v.push_back(temp);
	   } else if(ch == 't'){
	           // cout << "t !!!" << endl;
	            scanf("%lf %lf %lf %lf %lf %lf",&x1,&y1,&x2,&y2,&x3,&y3);
	            temp.type = T;
	            temp.x1 = x1;
	            temp.y1 = y1;
	            temp.x2 = x2;
	            temp.y2 = y2;
	            temp.x3 = x3;
	            temp.y3 = y3;
	            v.push_back(temp);
	   }
	
	}
	
	while(true){
	     scanf("%lf %lf",&x1,&y1);
	     count++;
	     sum = 0;
	     if(x1 == 9999.9 && y1 == 9999.9)
	        break;
	     for(int i=0; i<v.size(); i++){
	        //temp = v[i];
	        if(v[i].type == R){
	           if(v[i].x1 < v[i].x2){
	             x2 = v[i].x1; x3 = v[i].x2;
	           } else {
	             x2 = v[i].x2; x3 = v[i].x1;
	           }
	           if(v[i].y1 < v[i].y2){
	             y2 = v[i].y1; y3 = v[i].y2;
	           } else {
	             y2 = v[i].y2; y3 = v[i].y1;
	           }
	           
	           if(x1 > x2 && x1 < x3 && y1 > y2 && y1 < y3){
	             printf("Point %d is contained in figure %d\n",count,i+1);
	             sum++;
	           }
	        }
	        else if(v[i].type == C){
	                 s = (v[i].x1 - x1)*(v[i].x1 - x1) + (v[i].y1 - y1)*(v[i].y1 - y1);
	                 if( s < v[i].r*v[i].r){
	                     printf("Point %d is contained in figure %d\n",count,i+1);
	                     sum++;
	                 }
	         
	        } else if(v[i].type == T){
	                // printf("s=%lf s2=%lf s3=%lf s4=%lf\n",s,s2,s3,s4);
	                 s = fabs( v[i].x1*v[i].y2 + v[i].x3*v[i].y1 + v[i].x2*v[i].y3
	                     - v[i].x3*v[i].y2 - v[i].x2*v[i].y1 - v[i].x1*v[i].y3);
	                 s2 = fabs(x1*v[i].y2 + v[i].x3*y1 + v[i].x2*v[i].y3
	                     - v[i].x3*v[i].y2 - v[i].x2*y1 - x1*v[i].y3);
	                 
	                 s3 = fabs(v[i].x1*y1 + v[i].x3*v[i].y1 + x1*v[i].y3
	                     - v[i].x3*y1 - x1*v[i].y1 - v[i].x1*v[i].y3);
	                 s4 = fabs(v[i].x1*v[i].y2 + x1*v[i].y1 + v[i].x2*y1
	                     - x1*v[i].y2 - v[i].x2*v[i].y1 - v[i].x1*y1);
	                 
	                 if(fabs(s2+s3+s4-s) <= 0.000001){
	                    printf("Point %d is contained in figure %d\n",count,i+1);
	                    sum++;
	                 }
	        }
	        
	     }
	     if(sum == 0)
	       printf("Point %d is not contained in any figure\n",count);
	}
}

