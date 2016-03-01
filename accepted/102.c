/* Ecological Bin Packing */
#include <stdio.h>
#include <string.h>


main(){
int i, num[9], sum[3][3], min, tmp;
char str[4];

    while((scanf("%d",&num[0]))!=EOF){
           for(i=1; i<9; i++)
               scanf("%d",&num[i]);
           sum[0][0]=num[0]+num[3];
           sum[0][1]=num[0]+num[6];
           sum[0][2]=num[3]+num[6];
           sum[1][0]=num[1]+num[4];
           sum[1][1]=num[1]+num[7];
           sum[1][2]=num[4]+num[7];
           sum[2][0]=num[2]+num[5];
           sum[2][1]=num[2]+num[8];
           sum[2][2]=num[5]+num[8];
           min = sum[0][0]+sum[1][1]+sum[2][2];
           
           strcpy(str,"CGB");
           tmp = sum[0][0]+sum[1][2]+sum[2][1];
           if(tmp<min){
              min = tmp;
              strcpy(str,"GCB");
           }
           else
               if(tmp==min)
                 if(strcmp(str,"GCB")>0){
                    min = tmp;
                    strcpy(str,"GCB");
                 }
           tmp = sum[0][1]+sum[1][0]+sum[2][2];
           if(tmp<min){
              min = tmp;
              strcpy(str,"CBG");
           }
           else
                if(tmp==min)
                  if(strcmp(str,"CBG")>0){
                     min = tmp;
                     strcpy(str,"CBG");
                  }
tmp = sum[0][1]+sum[1][2]+sum[2][0];
	if(tmp<min){
	  min = tmp;
	  strcpy(str,"GBC");
	}
	else
	    if(tmp==min)
		if(strcmp(str,"GBC")>0){
		  min = tmp;
		  strcpy(str,"GBC");
		}

	tmp = sum[0][2]+sum[1][0]+sum[2][1];
	if(tmp<min){
	  min = tmp;
	  strcpy(str,"BCG");
	}
	else
	    if(tmp==min)
		if(strcmp(str,"BCG")>0){
		  min = tmp;
		  strcpy(str,"BCG");
		}

	tmp = sum[0][2]+sum[1][1]+sum[2][0];
	if(tmp<min){
	  min = tmp;
	  strcpy(str,"BGC");
	}
	else
	    if(tmp==min)
		if(strcmp(str,"BGC")>0){
		  min = tmp;
		  strcpy(str,"BGC");
		}

	printf("%s %d\n",str,min);
    }
}

