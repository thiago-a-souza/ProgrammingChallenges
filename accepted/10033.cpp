#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#include<cmath>
#include<set>
#include<cstdlib>

using namespace std;

main(){
char str[4], inst[1000][4], tmp[4];
int reg[10], x, y;
int n, len, count, ans, index;
bool skip, first=true;

		scanf("%d\n",&n);
		while(true){
		    count = 0;
			memset(reg, 0, sizeof(reg));
			
			
			
  			while(true){
				 
				 if(!cin.getline(str,4))
					break;
				 len = strlen(str);
	
				 if(len == 0)
					break;
				 strcpy(inst[count], str);
				 count++;
				  
			}
			if(count == 0)
			   break;
            if(!first)
			   printf("\n");
			first = false;


			ans = 0; index = 0;
			while(true){
                  ans++;
                  x = ((int)inst[index][1]) - 48;
                  y = ((int)inst[index][2]) - 48;
                  if(x < 0 || x > 9 || y < 0 || y > 9){
                    index++;
                    continue;
                  }
                     
                  skip = false;
                  if(inst[index][0] == '1' && inst[index][1] == '0' && inst[index][2] == '0')
                     break;
                  else if(inst[index][0] == '2'){
                          reg[x] = y%1000;
                  } else if(inst[index][0] == '3'){
                            reg[x] = (reg[x] + y)%1000;
                  } else if(inst[index][0] == '4'){
                            reg[x] = (reg[x]*y)%1000;
                  } else if(inst[index][0] == '5'){
                            reg[x] = reg[y]%1000;
                  } else if(inst[index][0] == '6'){
                            reg[x] = (reg[x]+reg[y])%1000;
                  } else if(inst[index][0] == '7'){
                            reg[x] = (reg[x]*reg[y])%1000;
                  } else if(inst[index][0] == '8'){
                            reg[x] = atoi(inst[reg[y]])%1000;
                  } else if(inst[index][0] == '9'){
                            sprintf(tmp,"%03d",reg[x]);
                            strcpy(inst[reg[y]], tmp);
                  } else if(inst[index][0] == '0'){
                            if(reg[y] != 0){
                               index = reg[x];
                               skip = true;
                            }
                  }
                  if(skip == false)
			         index++;
			}
			printf("%d\n",ans);			
		}

}

