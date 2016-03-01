#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#include<cmath>
#include<set>
#include<cstdlib>

#define MAX 100000

using namespace std;

int tree[MAX];
int passed[MAX];
bool isValid;

void verifyPath(int i){

	if(i>=0 && tree[i] > 0)
	  passed[i] = 1;

	if(i == 1 && tree[1] < 0){
	  isValid = false;
	  return;
	}
	

    if(i > 1 && tree[i] > 0 && tree[i/2] < 0){
      isValid = false;
      return;
    }
    
    if(i > 0 && tree[i] > 0){
       verifyPath(2*i);
       verifyPath(2*i+1);
    }
}


main(){
char str[MAX];
int len, val, last;
bool isNew = true;
bool dup = false;

		while(gets(str)){
		  //  cout << str << endl;
		    len = strlen(str);
		    
		    if(isNew){
		       for(int i=0; i<MAX; i++)
		          tree[i] = -1;
		       isNew = false;
		    }
		    
		    for(int i=0; i<len; i++){
		       if(str[i] == '('){
		         if(i+1 < len && str[i+1] >= '0' && str[i+1] <= '9'){
		            val = atoi(&str[i+1]);
				//	printf("val = %d, index = %d\n",val,i+1);
		         } 
		       } else if(str[i] == ','){
		                 last = 1;
		                 while(++i < len && str[i] != ')'){
		                      if(str[i] == 'L'){
		                         last = last*2;
		                      } else if(str[i] == 'R'){
		                                last = last*2 + 1;
		                      }
		                 }
		                 dup = false;
		                 if(tree[last] > 0){
		                    isNew = true; 
		                    dup = true;
		                    break;
		                 }
		                 tree[last] = val;
		       } else if(str[i] == ')' && str[i-1] == '('){
		                 isNew = true;
		                 break;
		       }
		    }
		    if(isNew && dup == false){
		      isValid = true;
		      for(int i=0; i<MAX; i++)
		          passed[i] = -1;
		      verifyPath(1);
		      if(isValid){
		         for(int i=1; i<MAX; i++)
		            if(tree[i] > 0 && passed[i] < 0)
		                isValid = false;
		         if(isValid){
		            for(int i=1; i<MAX; i++)
		               if(tree[i] > 0)
		                 if(i > 1)
 		                    printf(" %d",tree[i]);
 		                 else
 		                    printf("%d",tree[i]);
		             printf("\n");
		         } else {
		           printf("not complete\n");
		         }
		      } else {
		         printf("not complete\n");
		      }
		      
		    } else if(dup == true){
		              printf("not complete\n");
		    
		    }
		       
		}
}