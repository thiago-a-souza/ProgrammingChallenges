/*****************************************************************************************/
/* AUTHOR: Thiago Alexandre Domingues de Souza                                           */
/* DESCRIPTION: Find primes between 2 and N using the Sieve of Eratosthenes             */
/*****************************************************************************************/

#include <iostream>
#include <vector>

#define MAXN 1000

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

int main(){
int n = 10000;

    sieve(n);
    printf("there are %lu primes between 2 and %d:\n", primes.size(), n);
    for(int i=0; i<primes.size(); i++){
        printf("%d ", primes[i]);
    }
    printf("\n");
    return 0;
}
