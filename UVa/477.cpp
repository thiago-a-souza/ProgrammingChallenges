#include<iostream>
#include<cstdio>

using namespace std;

typedef struct {
double x1, y1, x2, y2;
int index;
} TRect;

typedef struct {
double x, y, r;
int index;
} TCirc;



main(){
TRect rect[10];
TCirc circ[10];
int r_sz = 0, c_sz = 0, count=1;
int ans[11], line=1, b;
double x, y, x_min, x_max, y_min, y_max, result;
char ch;

        for(int i=0; i<12; i++) ans[i] = 0;

        while(true){
             scanf("%c",&ch);
             if(ch == '*')
                break;
             if(ch == 'r'){
                scanf("%lf %lf %lf %lf\n",&rect[r_sz].x1, &rect[r_sz].y1, &rect[r_sz].x2, &rect[r_sz].y2);
                rect[r_sz].index = count;
                r_sz++;
             }
             else if(ch == 'c'){
                      scanf("%lf %lf %lf\n",&circ[c_sz].x, &circ[c_sz].y, &circ[c_sz].r);
                //      printf("---> %lf %lf %lf\n",circ[c_sz].x,circ[c_sz].y,circ[c_sz].r);
                      circ[c_sz].index = count;
                      c_sz++;
             }
             count++;
        }
        
     

        while(true){
             scanf("%lf %lf",&x,&y);
             if( x == 9999.9 && y == 9999.9 )
                break;

             for(int i=0; i<c_sz; i++){
                 result = (circ[i].x - x)*(circ[i].x - x) + (circ[i].y - y)*(circ[i].y - y);
                 
                 if( result < circ[i].r*circ[i].r ){
                    ans[circ[i].index] = 1;
                  //printf("circ[i].x=%lf  x=%lf  circ[i].y=%lf  y=%lf \n",circ[i].x,x,circ[i].y,y);
                 //printf("circ result = %lf\n",result);  
                 }
             }
             
             for(int i=0; i<r_sz; i++){
                if(rect[i].x1 > rect[i].x2){
                  x_max = rect[i].x1;
                  x_min = rect[i].x2;
                }
                else{
                  x_max = rect[i].x2;
                  x_min = rect[i].x1;
                }
                
                if(rect[i].y1 > rect[i].y2){
                  y_max = rect[i].y1;
                  y_min = rect[i].y2;
                }
                else{
                  y_max = rect[i].y2;
                  y_min = rect[i].y1;
                }
              //  printf(" x > x_min => %d\n x < x_max => %d\n y > y_min => %d\n y < y_max => %d\n",
              //  x > x_min ? 1 : 0, x < x_max ? 1 : 0, y > y_min ? 1 : 0,  y < y_max ? 1 : 0);
              
           /*   if(x > x_min)
                printf(".. %lf > %lf\n",x,x_min);
              if(x < x_max)
                printf(".. %lf < %lf\n",x,x_max);
              if(y > y_min)
                printf(".. %lf > %lf\n",y,y_min);
              if(y < y_max)
                printf(".. %lf < %lf\n",y,y_max);    */            

              if( x > x_min && x < x_max && y > y_min && y < y_max){
                  // printf("entrou %lf %lf\n",x,y);
                   ans[rect[i].index]  = 1;
                }
                
             }
             b = 0;
             for(int i=1; i<12; i++){
                 if(ans[i] == 1){
                    printf("Point %d is contained in figure %d\n",line,i,i);
                    b = 1;
                 }
                 ans[i] = 0;
             }
             if(b == 0) 
                printf("Point %d is not contained in any figure\n",line);
             line++;
                
                 
        }
    

}


