/* HUMIDEX 17/07/2007 */
#include<iostream>
#include<cmath>

using namespace std;

main(){
double H, T, D;
double ezinho, hzinho;
bool bh, bt, bd;
char letter;

	cin >> letter;
	while(letter!='E'){
	     bt = false;
	     bd = false;
	     bh = false;
	     if(letter=='T'){
	       cin >> T;
	       bt = true;
	     }
	     else if(letter=='D'){
	            cin >> D;
	            bd = true;
	          }
	     else{
	         cin >> H;
	         bh = true;
	     }
	     cin >> letter;
	     if(letter=='T'){
	       cin >> T;
	       bt = true;
	     }
	     else if(letter=='D'){
	            cin >> D;
	            bd = true;
	          }
	     else{
	         cin >> H;
	         bh = true;
	     }
	     if(bt && bd){
	       ezinho = 6.11*exp (5417.7530 * ((1/273.16) - (1/(D+273.16))));
	       hzinho = (0.5555)*(ezinho - 10.0);
	       H = T + hzinho;
	     }
	     else if(bt && bh){
	            hzinho = H - T;
	            ezinho = (hzinho/0.5555) + 10.0;
	            D = (-1/((log(ezinho/6.11)/(5417.7530))-(1/273.16)))-273.16;
	     	  }
	     	  else{
	     	    ezinho = 6.11*exp (5417.7530 * ((1/273.16) - (1/(D+273.16))));
	     	    hzinho = (0.5555)*(ezinho-10.0);
	     	    T = H - hzinho;
	     	  }
	     printf("T %.1lf D %.1lf H %.1lf\n",T,D,H);
	     cin >> letter;	     
	}
}
