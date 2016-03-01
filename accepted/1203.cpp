#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>

#define MAX 1000

using namespace std;

main(){
char str[MAX];
int len;
priority_queue< pair<int, int> > heap;
int id, time, aux;
int K;
	
	while(true){
		cin.getline(str,MAX);
		len = strlen(str);
		if(len == 1 && str[0] == '#')
		   break;
		for(int i=0; i<len; i++)
		   if(str[i] >= '0' && str[i] <= '9'){
		   	  id = atoi(&str[i]);
		   	  break;
		   }
		for(int i=len-1; i>=0; i--)
		   if(!(str[i] >= '0' && str[i] <= '9')){
		   	  time = atoi(&str[i+1]);
		   	  break;
		   }
		aux = time;
		while(true){
			  heap.push(make_pair(-aux, -id));
			  aux = aux + time;
			  if(aux > 3000)
			     break;
		} 
	}
	
	scanf("%d",&K);
	for(int i=0; i<K; i++){
	  cout << -heap.top().second << endl;
	   heap.pop();
	}
	
	
}

