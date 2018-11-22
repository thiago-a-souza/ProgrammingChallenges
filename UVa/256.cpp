/* Quirksome Squares - ad hoc, number theory*/
#include<iostream>
#include<cstdio>
#include<cmath>


int main(){
char dois[][10] = {"00","01","81"};
char quatro[][10] = {"0000","0001","2025","3025","9801"};
char seis[][10] = {"000000","000001","088209","494209","998001"};
char oito[][10] = {"00000000","00000001","04941729","07441984","24502500","25502500","52881984","60481729","99980001"};

int n;

	while(scanf("%d",&n) != EOF){
		switch(n){
			case 2 : for(int i=0; i<3; i++) printf("%s\n",dois[i]); break;
			case 4 : for(int i=0; i<5; i++) printf("%s\n",quatro[i]); break;
			case 6 : for(int i=0; i<5; i++) printf("%s\n",seis[i]); break;
			case 8 : for(int i=0; i<9; i++) printf("%s\n",oito[i]); break;
		}
	}

/*
int num[10], sz;
int result;



	for(int i=1; i<99999999; i++){
		double d = sqrt(i);
		int conv = (int)d;
		
		if(d - conv == 0.0){

			for(int j=0; j<10; j++){
				  num[j] = 0;
			}
			sz = 0; 
			int val = i;			  
			while(val != 0){
				   num[sz++] = val%10;
				   val = val/10;
			}
			
			while(sz <= 8){
			    if(sz % 2 != 0)
				    num[sz++] = 0;
				result = 0;
				int mult = 1;
				for(int j=0, k=sz/2; j<sz/2; j++, k++){
					result = result + (num[j]*mult) + (num[k]*mult);
					mult = mult*10;
				}
				if(result * result == i)
					printf("%d  --->  sz=%d\n",i,sz);
				num[sz++] = 0;
		    }
		}
	}*/

}

