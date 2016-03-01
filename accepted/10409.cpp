#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>

using namespace std;

main(){
char str[20];
int n, north, south, west, east, top, bottom;
int tmp;

	while(true){
	     scanf("%d",&n);
	     if( n == 0 )
	        break;
	     top = 1; bottom = 6;
	     north = 2; south = 5;
	     west = 3; east = 4;
	     
	     for(int i=0; i<n; i++){
	        scanf("%s",str);
	        //printf("str = %s\n",str);
	        if(strcmp(str,"north") == 0){
	          // printf("north\n");
	           tmp = top;
	           top = south;
	           south = bottom;
	           bottom = north;
	           north = tmp;
	        } else if(strcmp(str,"south") == 0){
	               //   printf("south\n");
	                  tmp = top;
	                  top = north;
	                  north = bottom;
	                  bottom = south;
	                  south = tmp;
	        } else if(strcmp(str,"east") == 0){
	        		//  printf("east\n");
	                  tmp = top;
	                  top = west;
	                  west = bottom;
	                  bottom = east;
	                  east = tmp;
	        } else if(strcmp(str,"west") == 0){
	        	//	  printf("west\n");
	                  tmp = top;
	                  top = east;
	                  east = bottom;
	                  bottom = west;
	                  west = tmp;
	        }
	     }
	    // printf("top=%d bottom=%d north=%d south=%d west=%d east=%d\n",top,
	    // bottom, north, south, west, east);
	    printf("%d\n",top);
	}
	
}

