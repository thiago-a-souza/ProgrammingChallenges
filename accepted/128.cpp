#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <inttypes.h>
#include <ctype.h>
#include <algorithm>
#include <utility>
#include <iostream>
#include <sstream>
#include <vector>

#define MAX 2000
#define GG 34943

using namespace std;

main(){
char str[MAX];
unsigned int len, sum, crc;
int i;

		while(gets(str)){
		     if(str[0] == '#')
		        break;
		        
		     len = strlen(str);
		     sum = 0;
		     
		     for(int i=0; i<len; i++)
		         sum = ((sum<<8) + str[i])%GG;
		     
		     sum = (sum << 16)%GG;
		     crc = (sum ? GG-sum : 0);
		     printf("%02X %02X\n", crc >> 8, crc&0xFF);
		     
		}

		

}

