#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>

using namespace std;

void decToHex(int n){
char ans[100];
int len = 0, remainder = 0;

        while( n >= 16 ){
             remainder = n%16;
             n = n/16;
             switch(remainder){
                case 0: ans[len] = '0'; break;
                case 1: ans[len] = '1'; break;
                case 2: ans[len] = '2'; break;
                case 3: ans[len] = '3'; break;
                case 4: ans[len] = '4'; break;
                case 5: ans[len] = '5'; break;
                case 6: ans[len] = '6'; break;
                case 7: ans[len] = '7'; break;
                case 8: ans[len] = '8'; break;
                case 9: ans[len] = '9'; break;
                case 10: ans[len] = 'A'; break;
                case 11: ans[len] = 'B'; break;
                case 12: ans[len] = 'C'; break;
                case 13: ans[len] = 'D'; break;
                case 14: ans[len] = 'E'; break;
                case 15: ans[len] = 'F'; break;
             }
             len++;
        }
        
        switch(n){
             case 0: ans[len] = '0'; break;
             case 1: ans[len] = '1'; break;
             case 2: ans[len] = '2'; break;
             case 3: ans[len] = '3'; break;
             case 4: ans[len] = '4'; break;
             case 5: ans[len] = '5'; break;
             case 6: ans[len] = '6'; break;
             case 7: ans[len] = '7'; break;
             case 8: ans[len] = '8'; break;
             case 9: ans[len] = '9'; break;
             case 10: ans[len] = 'A'; break;
             case 11: ans[len] = 'B'; break;
             case 12: ans[len] = 'C'; break;
             case 13: ans[len] = 'D'; break;
             case 14: ans[len] = 'E'; break;
             case 15: ans[len] = 'F'; break;
        }
        len++;
        printf("0x");
        for(int i=len-1; i>=0; i--)
           printf("%c",ans[i]);
        printf("\n");
}

void hexToDec(char *n){
int len, numb, mul = 1;
int ans = 0;
        len = strlen(n);
        for(int i=len-1; i>1; i--){
           switch(n[i]){
             case '0': numb = 0; break;
             case '1': numb = 1; break;
             case '2': numb = 2; break;
             case '3': numb = 3; break;
             case '4': numb = 4; break;
             case '5': numb = 5; break;
             case '6': numb = 6; break;
             case '7': numb = 7; break;
             case '8': numb = 8; break;
             case '9': numb = 9; break;
             case 'A': numb = 10; break;
             case 'B': numb = 11; break;
             case 'C': numb = 12; break;
             case 'D': numb = 13; break;
             case 'E': numb = 14; break;
             case 'F': numb = 15; break;
           }
           ans = ans + (numb*mul);
           mul = mul*16;
        }
        printf("%d\n",ans);
}

main(){
char ch[100];
int n;

        while(true){
             scanf("%s",ch);
             if( ch[1] != 'x' ){
                n = atoi(ch);
                if(n < 0 )
                   break;
                decToHex(n);
             } else {
                hexToDec(ch);
             }
        }


}

