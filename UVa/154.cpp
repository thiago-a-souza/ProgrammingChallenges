#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<set>
#include<map>

#define MAX 200
#define INF 999999999

#define red 0
#define orange 1
#define yellow 2
#define green 3
#define blue 4

#define plastic 6
#define glass 7
#define aluminium 8
#define steel 9
#define newspaper 10

using namespace std;



int bin[MAX][5];
int cities;

void calculate(){
int minSwaps, swaps;
int index;
	
	minSwaps = INF;
	for(int c1=0; c1<cities; c1++){
	   swaps = 0;
	   for(int c2=0; c2<cities; c2++){
	       if(c1 == c2)
	          continue;
	       for(int j=0; j<5; j++)
	          if(bin[c1][j] != bin[c2][j])
	             swaps++;
	   }
	   if(swaps < minSwaps){
	      minSwaps = swaps;
	      index = c1;
	   }
	}
	
	printf("%d\n", index+1);
	   

}

int main(){
string line;
int len;
int clr, mat;

	cities = 0;
	
	while(true){
		cin >> line;
		if(line[0] == '#')
		   break;
		if(line[0] == 'e'){
		   calculate();
		   cities = 0;
		   continue;
		}
		for(int i=0,j=2; i<=16; i+=4, j+=4){
		    switch(line[i]){
		      case 'r': clr = red; break;
		      case 'o': clr = orange; break;
		      case 'y': clr = yellow; break;
		      case 'g': clr = green; break;
		      case 'b': clr = blue; break;		      
		    }
		    switch(line[j]){
		      case 'P': mat = plastic; break;
		      case 'G': mat = glass; break;
		      case 'A': mat = aluminium; break;
		      case 'S': mat = steel; break;
		      case 'N': mat = newspaper; break;		      
		    } 
		    bin[cities][clr] = mat;
		}
		cities++;
		
	}

	return 0;
}

