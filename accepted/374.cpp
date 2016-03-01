/* Big Mod */
#include<iostream>
#include<map>

using namespace std;

int m;

int func(int b, int p){
int tmp;
	if(p == 0)
	   return 1;
	if(p%2 == 0){
	   tmp = func(b,p/2);
      	   return (tmp*tmp)%m;
   	}
	return ((b%m)*func(b,p-1))%m;

}
 
main(){
int b, p;


	while(cin >> b){
	     cin >> p >> m;
	     cout << func(b,p) << endl;
	}


}



