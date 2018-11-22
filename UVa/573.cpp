#include<iostream>
#include<cstdio>

using namespace std;

main(){
int H, U, D, F;
int day;
double initial, after_climbing, after_sliding;
double climb, dec_factor;

        while(true){
             scanf("%d %d %d %d",&H, &U, &D, &F);
             if(H == 0)
                break;
            // printf("--> %d %d %d %d\n",H,U,D,F);
             day = 1;
             initial = 0.0;
             after_climbing = 0.0;
             after_sliding = 0.0;
             climb = (double)U;
             dec_factor = ((double)U)*(((double)F)/100.0);
             
             while(after_climbing <= H && after_sliding >= 0.0){
                 if(climb >= 0.0)
                    after_climbing = initial + climb;
                 else
                    after_climbing = initial;
                 after_sliding = after_climbing - (double)D;
                // printf("initial=%.2lf climb=%.2lf after_climbing=%.2lf after_sliding=%.2lf\n",initial,climb,after_climbing,after_sliding);
                 initial = after_sliding;
                 climb = climb - dec_factor;
                 day++;
             } 
            // printf("initial=%.2lf climb=%.2lf after_climbing=%.2lf after_sliding=%.2lf\n",initial,climb,after_climbing,after_sliding);
             if(after_climbing > H)
                printf("success on day %d\n",day-1);
             else
                printf("failure on day %d\n",day-1);
        }

}

