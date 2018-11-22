/* Antimonotonicity */
#include<iostream>
#include<cstdio>
using namespace std;

main(){
int tests, n, count;
int atual, ant;

	cin >> tests;
	while(tests--){
	     count=0;
	     cin >> n, n--;
	     cin >> atual;
	     while(n--){
	     	  ant = atual;
	     	  cin >> atual;
	          if(count%2==0){
	            if(ant>atual)
	              count++;
	          }
	          else if(ant<atual)
	                 count++;
	     }
	     if(count%2==0){
	       if(ant<atual)
	          count++;
	     }
	     else if(ant>atual)
	            count++;
	     cout << count << endl;
	
	}
}

