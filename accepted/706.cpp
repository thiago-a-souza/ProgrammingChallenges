#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>

using namespace std;

void one(int row, int s){

	if(row == 0 || row == s+1 || row == 2*s + 2 ){
	   for(int i=0; i<s+2; i++)
	       printf(" ");
	} else {
	   for(int i=0; i<s+1; i++)
	      printf(" ");
	    printf("|");
	}
}

void two(int row, int s){

	if(row == 0 || row == s+1 || row == 2*s + 2){
	   printf(" ");
	   for(int i=0; i<s; i++)
	       printf("-");
	   printf(" ");
	} else if(row < s+1){
	          for(int i=0; i<s+1; i++)
			      printf(" ");
	          printf("|");
	} else {
			printf("|");
			for(int i=0; i<s+1; i++)
			      printf(" ");
	}
}

void three(int row, int s){
	if(row == 0 || row == s+1 || row == 2*s + 2){
	   printf(" ");
	   for(int i=0; i<s; i++)
	       printf("-");
	   printf(" ");
	} else {
	  for(int i=0; i<s+1; i++)
	     printf(" ");
      printf("|");
	}
}

void four(int row, int s){
	if(row == 0 || row == 2*s + 2){
	   for(int i=0; i<(s+2); i++)
	       printf(" ");
	} else if(row < s+1) {
	          printf("|");
			  for(int i=0; i<s; i++)
			      printf(" ");
			  printf("|");
	} else if(row == s+1){
	          printf(" ");
			  for(int i=0; i<s; i++)
			      printf("-");
			  printf(" ");
	} else {
	     for(int i=0; i<(s+1); i++)
		     printf(" ");
	     printf("|");
	}
}

void five(int row, int s){
	if(row == 0 || row == s+1 || row == 2*s + 2){
	   printf(" ");
	   for(int i=0; i<s; i++)
	      printf("-");
	   printf(" ");
	} else if(row < s+1){
	          printf("|");
		      for(int i=0; i<s+1; i++)
		          printf(" ");
	} else {
	       for(int i=0; i<s+1; i++)
		          printf(" ");
		   printf("|");
	}
}

void six(int row, int s){
	if(row == 0 || row == s+1 || row == 2*s + 2){
	   printf(" ");
	   for(int i=0; i<s; i++)
	      printf("-");
	   printf(" ");
	} else if(row < s+1){
	         printf("|");
		     for(int i=0; i<s+1; i++)
		          printf(" ");
	} else {
	    printf("|");
		for(int i=0; i<s; i++)
		    printf(" ");
	    printf("|");
	}
}

void seven(int row, int s){
	if(row == 0){
	   printf(" ");
	   for(int i=0; i<s; i++)
	       printf("-");
	   printf(" ");
	} else if(row == s+1 || row == 2*s + 2){
	          for(int i=0; i<(s+2); i++)
			      printf(" ");
	} else {
	   for(int i=0; i<s+1; i++)
	      printf(" ");
	   printf("|");
	}
}

void eight(int row, int s){
	if(row == 0 || row == s+1 || row == 2*s + 2){
	   printf(" ");
	   for(int i=0; i<s; i++)
	      printf("-");
	   printf(" ");
	} else {
	   printf("|");
	   for(int i=0; i<s; i++)
	      printf(" ");
	   printf("|");
	}
}

void nine(int row, int s){
	if(row == 0 || row == s+1 || row == 2*s + 2){
	   printf(" ");
	   for(int i=0; i<s; i++)
	      printf("-");
	   printf(" ");
	} else if( row < s+1){
			   printf("|");
			   for(int i=0; i<s; i++)
				  printf(" ");
			   printf("|");
	} else {
			for(int i=0; i<s+1; i++)
		          printf(" ");
		    printf("|");
	}

}

void zero(int row, int s){
	if(row == 0 || row == 2*s+2){
	   printf(" ");
	   for(int i=0; i<s; i++)
	      printf("-");
	   printf(" ");
	} else if(row == s+1){
	          for(int i=0; i<(s+2); i++)
			      printf(" ");
	} else {
	    printf("|");
		for(int i=0; i<s; i++)
			printf(" ");
	    printf("|");
	}
}

int main(){
int s, n_length;
char n[10];



	
	
	while(true){
	   scanf("%d %s",&s,n);
	   if(s == 0 && strcmp(n,"0") == 0)
	      break;
	   n_length = strlen(n);
	   for(int row=0; row<2*s+3; row++){
	      for(int j=0; j<n_length; j++){
		      switch(n[j]){
			      case '0' :  zero(row,s); break;
				  case '1' :  one(row,s); break;
				  case '2' :  two(row,s); break;
				  case '3' :  three(row,s); break;
				  case '4' :  four(row,s); break;
				  case '5' :  five(row,s); break;
				  case '6' :  six(row,s); break;
				  case '7' :  seven(row,s); break;
				  case '8' :  eight(row,s); break;
				  case '9' :  nine(row,s); break;
			  }
			  if( j != n_length - 1)
			     printf(" ");
		  }
		  printf("\n");
	   
	   }
	   printf("\n");
	  
	
	}

}

