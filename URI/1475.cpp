#include <iostream>
#include <vector>

#define MAX 1001
#define INF 0x3F3F3F3F
#define INVALID -1

using namespace std;

int n, c, t1, t2;
int v[MAX];
int memo[MAX];

int search(int left, int right, int target){
    if(left == right){
        if(v[left] > target)
            return left - 1;
        return left;
    }

    if(left + 1 == right){
        if(v[right] <= target)
            return right;
        if(v[left] <= target)
            return left;
        return left -1;
    }

    int mid = (left + right)/2;
    if(v[mid] == target)
        return mid;
    if(v[mid] < target)
        return search(mid+1, right, target);
    return search(left, mid-1, target);

}

int solve(int index){
    if(memo[index] != INVALID)  
        return memo[index];
    if(index == n - 1)
        return memo[index] = min(t1, t2);
    if(index >= n)
        return memo[index] = 0;
    
    int q = INF;
    int i = search(index, n-1, v[index] + t1);
        
    if(i >= 0)
        q = t1 + solve(i+1);
    else 
        q = t1 + solve(index+1);

    i = search(index, n-1, v[index] + t2);
    if(i >= 0)
        q = min(q, t2 + solve(i+1));
    else
        q = min(q, t2 + solve(index+1));

    return memo[index] = q;
}

int main(){

    while(scanf("%d %d %d %d", &n, &c, &t1, &t2) != EOF){
        for(int i=0; i<n; i++)
            scanf("%d", &v[i]);
        
        int ans = INF;
        for(int i=0; i<n; i++){
            for(int j=0; j<=n; j++)
                memo[j] = INVALID;

            ans = min(ans, solve(0));
            int diff = c - v[n-1] + v[0];
            int prev = v[0];
            for(int j=1; j<n; j++){
                int aux = v[j];
                v[j] = prev + diff;
                prev = aux;
            }
            for(int i=0; i<n; i++)
                printf("%d, ", v[i]);
            cout << endl;

        }
        cout << ans << endl;
    }
}
