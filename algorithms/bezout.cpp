/*****************************************************************************************/
/* AUTHOR: Thiago Alexandre Domingues de Souza                                           */
/* DESCRIPTION:                                                                          */
/*****************************************************************************************/

#include <iostream>
#include <vector>
#include <cmath>

#define TRACE(x...) x
#define PRINT(x...) TRACE(printf(x))
#define WATCH(x) TRACE(cout << #x" = " << x << "\n";)

using namespace std;

vector<int> primes;

int gcd(int a, int b, int &x, int &y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    int x1, y1;
    int d = gcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

int main(){
int a, b, x, y;


    a = 3; b = 4; 
    cout << gcd(a, b, x, y) << endl;
    cout << "x="<< x << " y="<< y << endl;

    
}