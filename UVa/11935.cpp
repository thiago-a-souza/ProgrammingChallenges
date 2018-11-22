#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>

#define MAX 100
#define INF 2147483646.0

#define FUEL_CONSUMPTION 1
#define LEAK 2
#define GAS_STATION 3
#define MECHANIC 4
#define GOAL 5

using namespace std;

typedef struct {
int km, type;
int consumption;
} TEvent;

TEvent ev[MAX];
int n;


bool simulate(double volume){
double tank, lastConsumption = 0;
int lastKm = 0, leaks = 0;

    tank = volume;
    
	for(int i=0; i<n; i++){
	    tank -= (ev[i].km - lastKm)*(lastConsumption/100.0 + leaks);
	    lastKm = ev[i].km;
	    if(tank < 0.0)
	       return false;
	    if(ev[i].type == FUEL_CONSUMPTION){
	       lastConsumption = (double)ev[i].consumption;
        } else if(ev[i].type == LEAK){
                  leaks++;
        } else if(ev[i].type == GAS_STATION){
                  tank = volume;
        } else if(ev[i].type == MECHANIC){
                  leaks = 0;
        } else if(ev[i].type == GOAL){
                  break;
        }    
	}
	
	if(tank >= 0.0)
	   return true;
	return false;
}


int main(){
char s[MAX];
int km, cons;
bool flag = true;
double low, mid, high, ans;	
	
	while(true){
	      n = 0;
          while(true){
	            scanf("%d %s", &km, s);
	            if(strcmp(s, "Fuel") == 0){
      	           scanf("%s %d\n", s, &cons);
	               if(km == 0 && cons == 0){
	                  flag = false;
      	              break;	          
	               }
	               ev[n].km = km;
      	           ev[n].type = FUEL_CONSUMPTION;
	               ev[n].consumption = cons;
      	           n++;
	            } else if(strcmp(s, "Leak") == 0){
   	                      ev[n].km = km;
      	                  ev[n].type = LEAK; 
	                      n++;
         	    } else if(strcmp(s, "Gas") == 0){
	                      scanf("%s\n", s);
	                      ev[n].km = km;
	                      ev[n].type = GAS_STATION;
	                      n++;
	            } else if(strcmp(s, "Mechanic") == 0){
	                      ev[n].km = km;
	                      ev[n].type = MECHANIC;
	                      n++;
	            } else if(strcmp(s, "Goal") == 0){
	                      ev[n].km = km;
	                      ev[n].type = GOAL;
	                      n++;
	                      break;
	            } 
	        }
	        if(!flag)
	           break;
	        
	        low = 0.; high = INF;
	        for(int i=0; i<300; i++){
	           mid = (low + high)/2.0;
	           if(simulate(mid)){
	              high = mid;
	              ans = mid;
	           } else { 
	              low = mid;
	           }
	        }
	        
	        printf("%.3lf\n", ans);
	        
	}
	return 0;
}

