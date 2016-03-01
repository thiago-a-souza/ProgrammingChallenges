#include<iostream>
#include<cstdio>

using namespace std;

main(){
int n, amp, freq;

        scanf("%d",&n);
       // printf("n=%d\n",n);
        while(n--){
             scanf("%d",&amp);
             scanf("%d",&freq);
            // printf("n===> %d\n",n);
             for(int k=0; k<freq; k++){
                for(int i=1; i<=amp; i++){
                    for(int j=0; j<i; j++)
                       printf("%d",i);
                    printf("\n");
                }
                for(int i=amp-1; i>0; i--){
                    for(int j=0; j<i; j++)
                        printf("%d",i);
                    printf("\n");
                }
                if(k < freq - 1)
                   printf("\n");
             }
             if(n > 0)
                printf("\n");
        }

}

