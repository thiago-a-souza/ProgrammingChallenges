#include<iostream>
#include<cstdio>
#define MAX 100
using namespace std;

int mirror(char ch1, char ch2){
    switch(ch1){
        case 'A' : if(ch2 == 'A') return 1; break;
        case 'E' : if(ch2 == '3') return 1; break;
        case 'H' : if(ch2 == 'H') return 1; break;
        case 'I' : if(ch2 == 'I') return 1; break;
        case 'J' : if(ch2 == 'L') return 1; break;
        case 'L' : if(ch2 == 'J') return 1; break;
        case 'M' : if(ch2 == 'M') return 1; break;
        case 'O' : if(ch2 == 'O') return 1; break;
        case 'S' : if(ch2 == '2') return 1; break;
        case 'T' : if(ch2 == 'T') return 1; break;
        case 'U' : if(ch2 == 'U') return 1; break;
        case 'V' : if(ch2 == 'V') return 1; break;
        case 'W' : if(ch2 == 'W') return 1; break;
        case 'X' : if(ch2 == 'X') return 1; break;
        case 'Y' : if(ch2 == 'Y') return 1; break;
        case 'Z' : if(ch2 == '5') return 1; break;
        case '1' : if(ch2 == '1') return 1; break;
        case '2' : if(ch2 == 'S') return 1; break;
        case '3' : if(ch2 == 'E') return 1; break;
        case '5' : if(ch2 == 'Z') return 1; break;
        case '8' : if(ch2 == '8') return 1; break;
    }
    return 0;

}

main(){
char str[MAX];
int len;
int pali, mir_str;
int index = 0; 
       while(scanf("%s ",str) != EOF){
            len = strlen(str);
            pali = 1; mir_str = 1;
            for(int i=0, j=len-1; i<(len/2); i++, j--){
                if(str[i] != str[j])
                   pali = 0;
                if(mirror(str[i],str[j]) == 0){
                   mir_str = 0;
                } 
            
            }
            if( len == 1 && (str[0] == 'A' || str[0] == 'H' || str[0] == 'I' ||
                str[0] == 'M' || str[0] == 'O' || str[0] == 'T' || str[0] == 'U' || 
                str[0] == 'V' || str[0] == 'W' || str[0] == 'X' || str[0] == 'Y' ||  
                str[0] == '1' || str[0] == '8' ))
                 printf("%s -- is a mirrored palindrome.\n\n",str);
            else if( len == 1)
                    printf("%s -- is a regular palindrome.\n\n",str);            
            else if(pali == 1 && mir_str == 1)
                    printf("%s -- is a mirrored palindrome.\n\n",str);
            else if(pali == 1)
                    printf("%s -- is a regular palindrome.\n\n",str);
            else if(mir_str == 1)
                    printf("%s -- is a mirrored string.\n\n",str);
            else printf("%s -- is not a palindrome.\n\n",str);
            
           
       }
   

}
