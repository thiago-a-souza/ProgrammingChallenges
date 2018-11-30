/*****************************************************************************************/
/* AUTHOR: Thiago Alexandre Domingues de Souza                                           */
/* DESCRIPTION: Calculates a^n using the fast exponentiation by squaring method          */
/*****************************************************************************************/

#include <iostream>

#define TRACE(x...) x
#define PRINT(x...) TRACE(printf(x))
#define WATCH(x) TRACE(cout << #x" = " << x << "\n";)

using namespace std;

/* a^n */
long long fast_power(long long a, long long n){
	if(n == 0)
		return 1;
	if(n == 1)
		return a;
	if(n % 2 == 0)
		return fast_power(a*a, n/2);
	else
		return a*fast_power(a*a, (n-1)/2);
}

/* a^n mod m */
long long fast_power_mod(long long a, long long n, int m){
	if(n == 0)
	   return 1;
	if(n == 1)
	   return a % m;
	if(n % 2 == 0)
	   return fast_power_mod((a*a)%m, n/2, m);
	else
	   return ((a%m)*fast_power_mod((a*a)%m, (n-1)/2, m))%m;
}

int main(){

    for(int n=0; n<=30; n++){
        printf("%d^%d = %llu\n", 2, n,  fast_power(2, n));
    }
    
}