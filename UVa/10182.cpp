#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack> 
#include <set>
#include <map>
#include <queue>
#include <climits>
#include <cmath>

#define MAX 100000
using namespace std;

typedef struct {
int x, y;
} TAdj;
TAdj ans[MAX*2];

int x, y, step;

void walk(){
    ans[step].x = x;
    ans[step].y = y;
    step++;
}

void walkSouth(int track){
    while(track--){
          y++;
          walk();
    }
}

void walkSouthWest(int track){
	while(track--){
	     x--;
	     y++;
	     walk();
	}
}

void walkNorthWest(int track){
	while(track--){
		x--;
		walk();
	}
}

void walkNorth(int track){
	while(track--){
		y--;
		walk();
	}
}

void walkNorthEast(int track){
	while(track--){
		x++;
		y--;
		walk();
	}
}

void walkSouthEast(int track){
	while(track--){
		x++;
		walk();
	}
}

int main(){
int n;

	step = 1;
	x = 0;
	y = -1;
	walkSouth(2);
	for(int i=1; step<MAX; i++){
	     walkNorthWest(i);
	     walkNorth(i);
	     walkNorthEast(i);
	     walkSouthEast(i);
	     walkSouth(i+1);
	     walkSouthWest(i);
	}
	
	while(scanf("%d",&n) != EOF){
		printf("%d %d\n",ans[n].x, ans[n].y);
	}
	
	return 0;
}

