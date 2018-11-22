/* Stacks of Flapjacks - 20/11/2007 */
/* Category: Sorting */
#include <iostream>
#include <cstdio>

#define ff(i,v,n) for(int i=v; i<n; i++)
#define fd(i,v,n) for(int i=n; i>=v; i--)
#define f(i,n) ff(i,0,n)
#define debug(x) 
#define MAXLEN 1000

using namespace std;

int num[101], cont;

void swap(int *a, int *b){
int x, y;

	x = *a;
	*a = *b;
	*b = x;

}

void inverte(int pos){
int n;

	for(int i=0, j=pos; i<=pos/2; i++, j--)
	    swap(&num[i], &num[j]);

}

void flips(){
int maior, pos;

	for(int i=cont-1; i>=0; i--){
           maior = -1;
           pos = -1;
           for(int j=0; j<=i && i != 0; j++)
              if(num[j] > maior){
                 maior = num[j];
                 pos = j;
              }
           if(pos == 0){
              inverte(i);
              printf("%d ",cont - i);
           }
           else if(pos != i && pos != -1){
              inverte(pos);
              printf("%d ",cont - pos);
              inverte(i);
              printf("%d ",cont-i);
           }
	}
}

main(){
char buff[MAXLEN];
int sz, val;


	while(true){
	     cin.getline(buff,MAXLEN);
	     sz = strlen(buff);

	     if(sz == 0)
	       return 0;

	     cont = 0;

	     f(i, sz){
	       if(buff[i] == ' ')
	         continue;
	         
	       val = atoi(&buff[i]);
	       num[cont++] = val;
	       
	       while(buff[i] >= '0' && buff[i] <= '9')
	             i++;
	     }
	    
	    f(i, cont)
	     if(i != cont - 1)
	        printf("%d ",num[i]);
	     else
	        printf("%d\n",num[i]); 
	    flips();
	    cout << "0\n";
	}

}


