#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#include<cmath>
#include<set>
#include<cstdlib>

#define MAX 100
#define ADDR_1 2130706432

using namespace std;

/*
Big endian    = bit mais significativo para o menos significativo (leitura natural)
Little endian = bit menos significativo para o mais significativo

Ex.: 1000 na base 10 convertido em hexa é 0x03E8

Big    =  03E8
Little =  E803

Na memória 1 int ocupa 32 bits (4 bytes) divididos em 4 grupos de 8 bits cada (1 byte).

+-----------+-----------+-----------+-----------+
| AAAA AAAA | BBBB BBBB | CCCC CCCC | DDDD DDDD |
+-----------+-----------+-----------+-----------+

para converter é preciso inverter as posições

+-----------+-----------+-----------+-----------+
| DDDD DDDD | CCCC CCCC | BBBB BBBB | AAAA AAAA |
+-----------+-----------+-----------+-----------+

*/

main(){
int n, n2, v, ans=0;


		while(scanf("%d",&n) != EOF){
		      n2 = n;
	          ans = 0;
	          
			  v = n2&255;
			  ans = ans|v;
			  ans = ans << 8;
			  
			  n2 = n2 >> 8;
			  v = n2&255;		      
			  ans = ans|v;
		      ans = ans << 8;
		      
		      n2 = n2 >> 8;
			  v = n2&255;		      
			  ans = ans|v;
		      ans = ans << 8;

		      n2 = n2 >> 8;
			  v = n2&255;		      
			  ans = ans|v;

		      cout << n <<" converts to " << ans << endl;		      
		     
		      
		}
}

