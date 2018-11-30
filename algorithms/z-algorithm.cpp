/*****************************************************************************************/
/* AUTHOR: Thiago Alexandre Domingues de Souza                                           */
/* DESCRIPTION: Z algorithm finds the longest substring that starting at s[i] that is    */
/* a prefix of s in O(n). For a zero-indexed array, z[i] = x means that the substring    */
/* s(i, i+x-1) is equals to s(0, x-1).                                                   */
/* EXAMPLE:  STRING = A B C A B C A B A B                                                */
/*                Z = 0 0 0 5 0 0 2 0 2 0                                                */
/* If the string has a pattern followed by a character that's not present in the text,   */
/* it can find the longest substring that matches the pattern in O(m+n).                 */
/* EXAMPLE:  STRING = f o o # A B C D f o o A B C A B A B                                */
/*                Z = 0 0 0 0 0 0 0 0 3 0 0 0 0 0 0 0 0 0                                */
/*****************************************************************************************/

#include <iostream>

#define MAXN 1000

#define TRACE(x...)  
#define PRINT(x...) TRACE(printf(x))
#define WATCH(x) TRACE(cout << #x" = " << x << "\n";)

int z[MAXN];

using namespace std;


void z_algorithm(string s) {
    int len =  s.length();
    int L = 0, R = 0;
    for (int i=1; i < len; i++) {
        if (i <= R)
            z[i] = min(R - i + 1, z[i-L]);
        while(i + z[i] < len && s[z[i]] == s[i + z[i]])
              z[i]++;
        if(i + z[i] - 1 > R)
            L = i, R = i + z[i] - 1;
    }
}

int main(){
    string s = "ABCABCABAB";
    memset(z, 0, sizeof(z));
    
    printf("z function:\n");
    z_algorithm(s);
    for(int i=0; i<s.length(); i++)
        printf("%c ", s[i]);
    printf("\n");
    for(int i=0; i<s.length(); i++)
        printf("%d ", z[i]);
    printf("\n");

    printf("\npattern matching:\n");

    s = "foo#ABCDfooABCABAB";
    memset(z, 0, sizeof(z));
    z_algorithm(s);
    for(int i=0; i<s.length(); i++)
        printf("%c ", s[i]);
    printf("\n");
    for(int i=0; i<s.length(); i++)
        printf("%d ", z[i]);
    printf("\n");
    
}