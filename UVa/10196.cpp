#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#include<cmath>
#include<set>
#include<cstdlib>
#include<algorithm>
#include<queue>

using namespace std;

char chess[10][10];


bool checkPawn(int r, int c){
bool isBlack = false;

	    if(r < 0 || c < 0) 
	      return false;

		if(chess[r][c] == 'k')
		   isBlack = true;
		   
		if(isBlack){
		   if(r + 1 < 8 && c - 1 >= 0 && chess[r+1][c-1] == 'P')
		      return true;
		   if(r + 1 < 8 && c + 1 < 8 && chess[r+1][c+1] == 'P')
		      return true;
		} else {
		   if(r - 1 >= 0  && c - 1 >= 0 && chess[r-1][c-1] == 'p')
		      return true;
		   if(r - 1 >= 0 && c + 1 < 8 && chess[r-1][c+1] == 'p')
		      return true;
		}
		return false;
}

bool checkKnight(int r, int c){
bool isBlack = false;

	    if(r < 0 || c < 0) 
	      return false;

		if(chess[r][c] == 'k')
		   isBlack = true;
		   
		if(isBlack){
		   if(r - 2 >= 0 && c - 1 >= 0 && chess[r-2][c-1] == 'N')
		      return true;
		   if(r - 2 >= 0 && c + 1 < 8 && chess[r-2][c+1] == 'N')
		      return true;
		   if(r - 1 >= 0 && c - 2 >= 0 && chess[r-1][c-2] == 'N')
		      return true;
		   if(r - 1 >= 0 && c + 2 < 8 && chess[r-1][c+2] == 'N')
		      return true;
		   if(r + 1 < 8 && c - 2 >= 0 && chess[r+1][c-2] == 'N')
		      return true;
		   if(r + 1 < 8 && c + 2 < 8 && chess[r+1][c+2] == 'N')
		      return true;
		   if(r + 2 < 8 && c - 1 >= 0 && chess[r+2][c-1] == 'N')
		      return true;
		   if(r + 2 < 8 && c + 1 < 8 && chess[r+2][c+1] == 'N')
		      return true;		   
		} else {
		   if(r - 2 >= 0 && c - 1 >= 0 && chess[r-2][c-1] == 'n')
		      return true;
		   if(r - 2 >= 0 && c + 1 < 8 && chess[r-2][c+1] == 'n')
		      return true;
		   if(r - 1 >= 0 && c - 2 >= 0 && chess[r-1][c-2] == 'n')
		      return true;
		   if(r - 1 >= 0 && c + 2 < 8 && chess[r-1][c+2] == 'n')
		      return true;
		   if(r + 1 < 8 && c - 2 >= 0 && chess[r+1][c-2] == 'n')
		      return true;
		   if(r + 1 < 8 && c + 2 < 8 && chess[r+1][c+2] == 'n')
		      return true;
		   if(r + 2 < 8 && c - 1 >= 0 && chess[r+2][c-1] == 'n')
		      return true;
		   if(r + 2 < 8 && c + 1 < 8 && chess[r+2][c+1] == 'n')
		      return true;
		}
		
		return false;
}

bool checkBishop(int r, int c){
bool isBlack = false;

	    if(r < 0 || c < 0) 
	      return false;
	      
		if(chess[r][c] == 'k')
		   isBlack = true;
		
		if(isBlack){
		  for(int i=1; i<=8; i++){
		     if(r - i < 0 || c - i < 0)
		        break;
		     if(chess[r-i][c-i] == 'B')
		        return true;
	         if(chess[r-i][c-i] != '.')
		         break;
		  }
		  
		  for(int i=1; i<=8; i++){
		     if(r - i < 0 || c + i >= 8)
		        break;
		     if(chess[r-i][c+i] == 'B')
		        return true;
	         if(chess[r-i][c+i] != '.')
		         break;		        
		  }
		  
		  for(int i=1; i<=8; i++){
		     if(r + i >= 8 || c - i < 0)
		        break;
		     if(chess[r+i][c-i] == 'B')
		        return true;
	         if(chess[r+i][c-i] != '.')
		         break;		        
		  }
		  
		  for(int i=1; i<=8; i++){
		     if(r + i >= 8 || c + i >= 8)
		        break;
		     if(chess[r+i][c+i] == 'B')
		        return true;
	         if(chess[r+i][c+i] != '.')
		         break;		        
		  }
		} else {
		  for(int i=1; i<=8; i++){
		     if(r - i < 0 || c - i < 0)
		        break;
		     if(chess[r-i][c-i] == 'b')
		        return true;
	         if(chess[r-i][c-i] != '.')
		         break;		        
		  }
		  
		  for(int i=1; i<=8; i++){
		     if(r - i < 0 || c + i >= 8)
		        break;
		     if(chess[r-i][c+i] == 'b')
		        return true;
	         if(chess[r-i][c+i] != '.')
		         break;		        
		  }
		  
		  for(int i=1; i<=8; i++){
		     if(r + i >= 8 || c - i < 0)
		        break;
		     if(chess[r+i][c-i] == 'b')
		        return true;
	         if(chess[r+i][c-i] != '.')
		         break;		        
		  }
		  
		  for(int i=1; i<=8; i++){
		     if(r + i >= 8 || c + i >= 8)
		        break;
		     if(chess[r+i][c+i] == 'b')
		        return true;
	         if(chess[r+i][c+i] != '.')
		         break;		        
		  }
		
		}
		
		return false;
}

bool checkRook(int r, int c){
bool isBlack = false;

	    if(r < 0 || c < 0) 
	      return false;

		if(chess[r][c] == 'k')
		   isBlack = true;

		if(isBlack){
		  for(int j=c-1; j>=0; j--){
		     if(chess[r][j] == 'R')
		        return true;
		     if(chess[r][j] != '.')
		        break;
		  }
		  
		  for(int j=c+1; j<8; j++){
		     if(chess[r][j] == 'R')
		        return true;
		     if(chess[r][j] != '.')
		        break;		  
		  }
		  
		  for(int i=r-1; i>=0; i--){
		     if(chess[i][c] == 'R')
		        return true;
		     if(chess[i][c] != '.')
		        break;
		  }
		  
		  for(int i=r+1; i<8; i++){
		     if(chess[i][c] == 'R')
		        return true;
		     if(chess[i][c] != '.')
		        break;
		  }
		  
		} else {
		  for(int j=c-1; j>=0; j--){
		     if(chess[r][j] == 'r')
		        return true;
		     if(chess[r][j] != '.')
		        break;
		  }
		  
		  for(int j=c+1; j<8; j++){
		     if(chess[r][j] == 'r')
		        return true;
		     if(chess[r][j] != '.')
		        break;		  
		  }
		  
		  for(int i=r-1; i>=0; i--){
		     if(chess[i][c] == 'r')
		        return true;
		     if(chess[i][c] != '.')
		        break;
		  }
		  
		  for(int i=r+1; i<8; i++){
		     if(chess[i][c] == 'r')
		        return true;
		     if(chess[i][c] != '.')
		        break;
		  }

		}
		return false;
}

bool checkQueen(int r, int c){
bool isBlack = false;

	    if(r < 0 || c < 0) 
	      return false;

		if(chess[r][c] == 'k')
		   isBlack = true;

		if(isBlack){
		  for(int i=1; i<=8; i++){
		     if(r - i < 0 || c - i < 0)
		        break;
		     if(chess[r-i][c-i] == 'Q')
		        return true;
	         if(chess[r-i][c-i] != '.')
		         break;
		  }
		  
		  for(int i=1; i<=8; i++){
		     if(r - i < 0 || c + i >= 8)
		        break;
		     if(chess[r-i][c+i] == 'Q')
		        return true;
	         if(chess[r-i][c+i] != '.')
		         break;		        
		  }
		  
		  for(int i=1; i<=8; i++){
		     if(r + i >= 8 || c - i < 0)
		        break;
		     if(chess[r+i][c-i] == 'Q')
		        return true;
	         if(chess[r+i][c-i] != '.')
		         break;		        
		  }
		  
		  for(int i=1; i<=8; i++){
		     if(r + i >= 8 || c + i >= 8)
		        break;
		     if(chess[r+i][c+i] == 'Q')
		        return true;
	         if(chess[r+i][c+i] != '.')
		         break;		        
		  }

		  for(int j=c-1; j>=0; j--){
		     if(chess[r][j] == 'Q')
		        return true;
		     if(chess[r][j] != '.')
		        break;
		  }
		  
		  for(int j=c+1; j<8; j++){
		     if(chess[r][j] == 'Q')
		        return true;
		     if(chess[r][j] != '.')
		        break;		  
		  }
		  
		  for(int i=r-1; i>=0; i--){
		     if(chess[i][c] == 'Q')
		        return true;
		     if(chess[i][c] != '.')
		        break;
		  }
		  
		  for(int i=r+1; i<8; i++){
		     if(chess[i][c] == 'Q')
		        return true;
		     if(chess[i][c] != '.')
		        break;
		  }
		
		} else {
		  for(int i=1; i<=8; i++){
		     if(r - i < 0 || c - i < 0)
		        break;
		     if(chess[r-i][c-i] == 'q')
		        return true;
	         if(chess[r-i][c-i] != '.')
		         break;
		  }
		  
		  for(int i=1; i<=8; i++){
		     if(r - i < 0 || c + i >= 8)
		        break;
		     if(chess[r-i][c+i] == 'q')
		        return true;
	         if(chess[r-i][c+i] != '.')
		         break;		        
		  }
		  
		  for(int i=1; i<=8; i++){
		     if(r + i >= 8 || c - i < 0)
		        break;
		     if(chess[r+i][c-i] == 'q')
		        return true;
	         if(chess[r+i][c-i] != '.')
		         break;		        
		  }
		  
		  for(int i=1; i<=8; i++){
		     if(r + i >= 8 || c + i >= 8)
		        break;
		     if(chess[r+i][c+i] == 'q')
		        return true;
	         if(chess[r+i][c+i] != '.')
		         break;		        
		  }

		  for(int j=c-1; j>=0; j--){
		     if(chess[r][j] == 'q')
		        return true;
		     if(chess[r][j] != '.')
		        break;
		  }
		  
		  for(int j=c+1; j<8; j++){
		     if(chess[r][j] == 'q')
		        return true;
		     if(chess[r][j] != '.')
		        break;		  
		  }
		  
		  for(int i=r-1; i>=0; i--){
		     if(chess[i][c] == 'q')
		        return true;
		     if(chess[i][c] != '.')
		        break;
		  }
		  
		  for(int i=r+1; i<8; i++){
		     if(chess[i][c] == 'q')
		        return true;
		     if(chess[i][c] != '.')
		        break;
		  }
		
		}
		return false;
}

main(){
int r1, c1, r2, c2;
int game = 1, len;
char tmp[1000];
bool b;


		while(true){
            for(int i=0; i<8; i++)
               for(int j=0; j<8; j++)
                  scanf(" %c ",&chess[i][j]);
		     b = true;
		     for(int i=0; i<8; i++)
		        for(int j=0; j<8; j++)
		           if(chess[i][j] != '.'){
		              b = false;
		              i = 10; j = 10;
		           }
		     if(b)
		        break;
		     r1 = -1; c1 = -1; r2 = -1; c2 = -1; 
		     for(int i=0; i<8; i++)
		       for(int j=0; j<8; j++){
		          if(chess[i][j] == 'k'){
		             r1 = i; c1 = j;
		          } else if(chess[i][j] == 'K'){
		                  r2 = i; c2 = j;
		          }
		       }

			 if(checkPawn(r1,c1) || checkKnight(r1,c1) || 
			    checkBishop(r1,c1) || checkRook(r1,c1) || checkQueen(r1,c1)){
			    printf("Game #%d: black king is in check.\n",game);    
			 } else if(checkPawn(r2,c2) || checkKnight(r2,c2) || 
  			           checkBishop(r2,c2) || checkRook(r2,c2) || checkQueen(r2,c2)){
                       printf("Game #%d: white king is in check.\n",game);      			           
             } else {
                printf("Game #%d: no king is in check.\n",game);
             }
			 game++;
             

		}
}

