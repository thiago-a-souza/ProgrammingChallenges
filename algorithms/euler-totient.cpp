/*****************************************************************************************/
/* AUTHOR: Thiago Alexandre Domingues de Souza                                           */
/* DESCRIPTION: Calculates the number of integers between 1 and n that are coprime to n  */
/*              using Euler's Totient function:                                          */
/*                                                                                       */
/*              phi(n) = (p1^(n-1)) * (p1 - 1) * ... * (pk^(n-1)) * (pk - 1)             */
/*              where p is the prime factor, and n is the prime factor power             */
/*                                                                                       */
/*              Example: 500 = 2^2 * 5^3                                                 */
/*                       phi(500) = (2^1)*(2-1)*(5^2)*(5-1) = 200                        */
/*****************************************************************************************/

#include <iostream>
#include <vector>
#include <cmath>

#define TRACE(x...) x
#define PRINT(x...) TRACE(printf(x))
#define WATCH(x) TRACE(cout << #x" = " << x << "\n";)

using namespace std;

vector<int> primes;


void sieve(int N) {
bool isPrime[N+1];

    for(int i=0; i<=N; i++)
        isPrime[i] = true;

    isPrime[0] = isPrime[1] = false;

    for(int i=2; i<=N; i++){
        if(isPrime[i]){
            for(int j=i*2; j<=N; j+= i)
                isPrime[j] = false;
            primes.push_back(i);
        }
    }
}


int phi(int n){
int p, ans = 1;
    
    if(n == 1)
        return 0;

    for(int i=0; primes[i]*primes[i] <= n; i++){
        if(n%primes[i] == 0){
            p = 1;
            n = n/primes[i];
            while(n % primes[i] == 0){
                n = n/primes[i];
                p = p*primes[i];
            }
            ans = ans * p * (primes[i] - 1);
        }
    }
    if(n != 1)
        ans = ans * (n-1);
    return ans;
}

int main(){
int n = 500;





    sieve(sqrt(n));

    
    cout << phi(n) << endl;

    
}