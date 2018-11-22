#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

main(){
char ch[10];
double x1[10], y1[10], x2[10], y2[10];
double min_x, max_x, min_y, max_y;
double p_x, p_y;
int count = 0, point;
bool contain;

     while(true){
          scanf("%s\n",ch);
          if(ch[0] == '*')
             break;
          scanf("%lf %lf %lf %lf",&x1[count],&y1[count],&x2[count],&y2[count]);
          count++;
     } 
     point = 1;
     while(true){
        scanf("%lf %lf",&p_x,&p_y);
        //printf("---> %lf %lf\n",p_x,p_y);
        if(p_x == 9999.9 && p_y == 9999.9 )
           break;
           
        contain = false;
        
        for(int i=0; i<count; i++){
           if(x1[i] > x2[i]){
              max_x = x1[i];
              min_x = x2[i];
           } else {
              max_x = x2[i];
              min_x = x1[i];
           }
           
           if(y1[i] > y2[i]){
              max_y = y1[i];
              min_y = y2[i];
           } else {
              max_y = y2[i];
              min_y = y1[i];
           }
           
           if( p_x > min_x && p_x < max_x && p_y > min_y && p_y < max_y ){
              printf("Point %d is contained in figure %d\n",point,i+1);
              contain = true;
           }
        
        }
        if(contain == false)
           printf("Point %d is not contained in any figure\n",point);
        point++;
            
        
     }
}

