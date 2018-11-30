/*****************************************************************************************/
/* AUTHOR: Thiago Alexandre Domingues de Souza                                           */
/* DESCRIPTION: Calculates a^n using the fast exponentiation by squaring method          */
/*****************************************************************************************/

#include <iostream>
#include <vector>

#define TRACE(x...) x
#define PRINT(x...) TRACE(printf(x))
#define WATCH(x) TRACE(cout << #x" = " << x << "\n";)

using namespace std;

vector<int> primes;
vector< pair<int, int> > factors;


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


void factorization(int n){
int count;

    factors.clear();

    for(int i=0; primes[i]*primes[i] <= n; i++){
        if(n%primes[i] == 0){
            count = 0;
            while(n % primes[i] == 0){
                n = n/primes[i];
                count++;
            }
            factors.push_back(make_pair(primes[i], count));
        }
    }
    if(n != 1){
        factors.push_back(make_pair(n, 1));
    }
}

int main(){


    sieve(1000);

    cout << "number => prime factors" << endl;
    for(int i=2; i<10; i++){
        cout << i << " => ";
        factorization(i);
        for(int j=0; j<factors.size(); j++){
            cout << factors[j].first << "^" << factors[j].second << " ";
        }
        cout << endl;
    }


    
}