#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>

using namespace std;

main(){
unsigned long long f[21], rep;
int ascii[30], n, len;
int count;

char str[1000];
    
    f[0] = 1;
	for(int i=1; i<=21; i++)
	   f[i] = f[i-1]*i;
    
    scanf("%d",&n);
    count = 1;
    while(n--){
         scanf("%s",str);
         for(int i=0; i<30; i++)
            ascii[i] = 0;
         
         rep = 1;
         len = strlen(str);
         
         for(int i=0; i<len; i++)
             ascii[((int)str[i]) - 'A']++;
         for(int i=0; i<30; i++)
            if(ascii[i] > 1)
               rep = rep*f[ascii[i]];
            //   cout << "rep = " << rep << endl;
         cout << "Data set " << count << ": " << f[len]/rep << endl;    
         count++;
    }
    
}