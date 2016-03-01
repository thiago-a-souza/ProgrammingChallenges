#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>

using namespace std;
int _i, _v, _x, _l, _c;

void roman(int n){
string tmp;
int lim;
     if( n == 0) 
        return ;
        
     if(n < 10){
          switch(n){
           case 1 : _i++; break; // return "I";
           case 2 : _i+=2; break; //return "II";
           case 3 : _i+=3; break; //return "III";
           case 4 : _i++; _v++; break; // return "IV";
           case 5 : _v++; break; //return "V";
           case 6 : _i++; _v++; break; //return "VI";
           case 7 : _i+=2; _v++; break; //return "VII";
           case 8 : _i+=3; _v++; break; //return "VIII";
           case 9 : _i++; _x++; break;//return "IX";
          }
     } else if( n <= 39) {
              tmp = ""; 
              lim = (int)(n/10);
              for(int i=0; i<lim; i++){
               //     tmp = tmp + "X"; 
                      _x++;
              }
              if( n%10 != 0){
                 // tmp+roman(n-10*lim);
                 roman(n-10*lim);
              }
              /*else{
                 return tmp;
              }*/
     } else if( n < 50 ){
               //return "XL" + roman(n-40);
               _x++; _l++; roman(n-40);
     } else if( n < 90 ){
              // return "L" + roman(n-50);
                _l++; roman(n-50);
     } else if( n <= 99){
              // return "XC"+ roman(n-90);
              _x++; _c++; roman(n-90);
     } else if( n == 100){
      //         return "C";
              _c++;
     }

}

main(){
int mat[101][5];
int n;

      mat[0][0] = 0;
      mat[0][1] = 0;
      mat[0][2] = 0;
      mat[0][3] = 0;
      mat[0][4] = 0;

     for(int i=1; i<=100; i++){
        _i=0; _v=0; _x=0; _l=0; _c=0;
        roman(i);
        mat[i][0] = _i + mat[i-1][0];
        mat[i][1] = _v + mat[i-1][1];
        mat[i][2] = _x + mat[i-1][2];
        mat[i][3] = _l + mat[i-1][3];
        mat[i][4] = _c + mat[i-1][4];
     }
     
     while(true){
       scanf("%d",&n);
       if(n == 0) 
          break;
       printf("%d: %d i, %d v, %d x, %d l, %d c\n",n,mat[n][0],mat[n][1],mat[n][2],mat[n][3],mat[n][4]);
     }
}

