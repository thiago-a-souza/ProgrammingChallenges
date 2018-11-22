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

using namespace std;

main(){
unsigned long long val;
bool first;
		while(true){
		     cin >> val;
		     if(val == 0)
		        break;
		     first = true;
		     for(int i=9; i>=0; i--)
		        if( (val*10 - i)%9 == 0){
		           if(first)
		              first = false;
		           else
		              printf(" ");   
		           cout << (val*10 - i)/9;
		           
		        }
		     cout << endl;
		}
}

