/*****************************************************************************************/
/* AUTHOR: Thiago Alexandre Domingues de Souza                                           */
/* DESCRIPTION: Segment tree                                                             */
/*****************************************************************************************/

#include <iostream>

#define MAXN 1000
#define TRACE(x...) x
#define PRINT(x...) TRACE(printf(x))
#define WATCH(x) TRACE(cout << #x" = " << x << "\n";)

using namespace std;

int v[] = {10, 20, 30, 40, 50};
int tree[4*MAXN];


void build(int node, int start, int end){
    if(start == end)
        tree[node] = v[start];
    else {
        int mid = (start + end)/2;
        build(2*node + 1, start, mid);
        build(2*node + 2, mid + 1, end);
        tree[node] = tree[2*node + 1] + tree[2*node + 2];
    }
}

void update(int node, int start, int end, int index, int value){
    if(start == end){
        tree[node] = value;
    } else {
        int mid = (start + end)/2;
        if(index <= mid)
            update(2*node + 1, start, mid, index, value);
        else
            update(2*node + 2, mid + 1, end, index, value);
        tree[node] = tree[2*node + 1] + tree[2*node + 2];
    }
}

int sum(int node, int start, int end, int i, int j){
    if(start > j || end < i)
       return 0;

    if(i <= start && j >= end)
       return tree[node];

    int mid = (start + end)/2;
    return sum(2*node + 1, start, mid, i, j) +
           sum(2*node + 2, mid + 1, end, i, j);
}

void traversal(int node, int start, int end){
    printf("sum[%d-%d] = %d\n", start, end, tree[node]);
    int mid = (start+end)/2;

    if(start != end){
       traversal(2*node + 1, start, mid);
       traversal(2*node + 2, mid + 1, end);
    }
}

int main(){
int n = 5; // number of items

    // node,start = 0 and end = last index of the array v
    build(0, 0, n-1);
    

    // displaying segment tree nodes
    printf("segment tree ============================\n");
    traversal(0, 0, n-1);
    printf("\n");

    int a = 2, b = 4;
    // sum of the inverval [a,b], where a >= 0 and b < n
    printf("query ===================================\n");
    printf("sum[%d,%d] = %d\n\n", a, b, sum(0, 0, n-1, a, b));


    int index = 2, value = 100; 
    printf("update ==================================\n");
    printf("segment tree update value from %d to %d\n\n", v[index], value);
    // node, start = 0, end = last index of the array v, index = corresponding index from the array v
    update(0, 0, n-1, index, value);
    // optional: array v does not need to be modified
    v[index] = value;

    // displaying segment tree after updating a value
    traversal(0, 0, n-1);
}
