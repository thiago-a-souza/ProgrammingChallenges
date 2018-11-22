#include<iostream>
#include<cstdio>
#include<set>

using namespace std;

int v[10000], pos;

int findme(int x){

	for(int ii=0; ii<pos; ii++)
	   if(v[ii] == x)
	      return ii;
	return -1;

}


main(){
int Z, I, M, L;
int ans, line=1;
	while(true){
	   scanf("%d %d %d %d",&Z,&I,&M,&L);
	   if(Z==0 && I==0 && M==0 && L==0)
	      break;
	   pos = 0;
	   v[pos++] = L;
	  
	   while(true){
	      L = (Z*L+I)%M;
	      ans = findme(L);
	      if(ans >= 0){
	     //    printf("found => %d\n",L);
		 break;
		 
	      }
	      v[pos++] = L;
	   
	   }
	   //for(int ii=0; ii<pos; ii++) printf("%d\n",v[ii]);
	   printf("Case %d: %d\n",line,pos-ans);
	   line++;
	
	}
	


}


