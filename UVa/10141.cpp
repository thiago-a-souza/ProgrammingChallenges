#include<iostream>
#include<cstdio>
#include<cstring>

#define MAX 300

using namespace std;

void Cal(int r, int pro) {
        char rec[300], nam[300], ss[300];
        int max = -100, y;
        double cost,x;
        while(r--) {
                gets(nam);
        }
        while(pro--) {
                gets(nam);
                gets(rec);
                sscanf(rec,"%lf%d",&x,&y);
                if(y>max) {
                        max = y;
                        cost = x;
                        strcpy(ss,nam);
                }
                else if(max == y && x<cost) {
                        cost = x;
                        strcpy(ss,nam);
                }
                while(y--) {
                        gets(nam);
                }
        }
        puts(ss);
}


main(){
int n, p, r, max;
char str[MAX], winner[MAX];
double price, min_price;
int line = 1;

        while(gets(str)){
            

             sscanf(str,"%d%d",&n,&p);
             if( n == 0 && p == 0 ) 
                break; 
             if(line > 1)
                printf("\n");
            
             printf("RFP #%d\n",line++);
             Cal(n,p);
             
             
        }



}

