#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#include<cmath>
#include<set>
#include<cstdlib>
#include<vector>

#define MAX 300

using namespace std;


main(){
int n, vai_um=0, tmp;
char a[MAX], b[MAX], c[MAX];
vector<string> v;
string s;
	
	   for(int i=0; i<MAX; i++){
	      a[i] = '0'; b[i] = '0'; c[i] = '0';
	   }
	    

        a[MAX-1] = '\0';
        b[MAX-1] = '\0';
        c[MAX-1] = '\0';
        a[MAX-2] = '1';
        b[MAX-2] = '2';
	
	    vai_um = 0;
	    v.push_back(a);
	    v.push_back(b);
	    
	    for(int i=0; i<1000; i++){
           for(int j=MAX-2; j>=0; j--){
               tmp = ((int)a[j]) + ((int)b[j]) + vai_um - 96;
               vai_um = tmp > 9 ? 1 : 0;
               tmp = tmp%10;
               c[j] = (char)(tmp+48);
           }
           strcpy(a,b);
           strcpy(b,c);
           v.push_back(c);
	    }
	    while(scanf("%d",&n) != EOF){
	         s = v[n];
	         tmp = 0;
	         while(s[tmp] == '0')
	               tmp++;
	         cout << s.substr(tmp) << endl;
	    }
	
		
}
