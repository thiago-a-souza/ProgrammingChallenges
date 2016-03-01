#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>

using namespace std;

int main(){
int year;
int gen;
int ans[] = {3,5,8,12,20,34,57,98,170,300,536,966,1754,
             3210,5910,10944,20366,38064,71421,134480,254016};
	while(true){
		scanf("%d",&year);
		if(year == 0)
		   break;
		gen = (year - 1960)/10;
		printf("%d\n",ans[gen]);
	}	
	return 0;
}

