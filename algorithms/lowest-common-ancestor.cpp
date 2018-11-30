/*****************************************************************************************/
/* AUTHOR: Thiago Alexandre Domingues de Souza                                           */
/* DESCRIPTION:                                                                          */
/*****************************************************************************************/

#include <iostream>

#define MAX_V 100 // max number of nodes
#define MAX_E 100 // max number of children per node

#define TRACE(x...) x
#define PRINT(x...) TRACE(printf(x))
#define WATCH(x) TRACE(cout << #x" = " << x << "\n";)

using namespace std;

int adj[MAX_V][MAX_E];   // graph representing the tree
int degree[MAX_V];       // node degree
int visited[MAX_V];      // node visited

int euler_tour[2*MAX_V]; // path transversing all nodes
int sz = 0;              // size of the euler_tour
int height[MAX_V];       // height of the node
int first[MAX_V];        // first occurence of the node
int segtree[4*MAX_V];    // segment tree

void build(int node, int start, int end){
    if(start == end){
        segtree[node] = euler_tour[start];
    } else {
        int mid = (start + end)/2;
        build(2*node + 1, start, mid);
        build(2*node + 2, mid + 1, end);
        int left = segtree[2*node + 1];        
        int right = segtree[2*node + 2];
        if(height[left] < height[right])
            segtree[node] = left;
        else 
            segtree[node] = right;
    }
}

int query(int node, int start, int end, int i, int j){
    if(start > j || end < i)
        return -1;
    if(i <= start && j >= end)
        return segtree[node];
    int mid = (start + end)/2;
    int left = query(2*node + 1, start, mid, i, j);
    int right = query(2*node + 2, mid + 1, end, i, j);

    if(left == -1)
        return right;
    if(right == -1)
        return left;

    if(height[left] < height[right])
        return left;
    return right;
}


void dfs(int s, int h){
	visited[s] = 1;
    height[s] = h;
    first[s] = sz;
    euler_tour[sz++] = s;

	for(int i=0; i<degree[s]; i++){
	   int t = adj[s][i];
	   if(!visited[t]){
	     dfs(t, h+1);
         euler_tour[sz++] = s;
	   }
	}
}


int lca(int u, int v){
    int left = first[u];
    int right = first[v];
    if(left <= right)
       return query(0, 0, sz-1, left, right);
    return query(0, 0, sz-1, right, left);    
}

int main(){
int m, root;
int u, v;

    scanf("%d",&m);
    scanf("%d",&root);
    for(int i=0; i<m; i++){
        scanf("%d %d", &u, &v);
        adj[u][degree[u]++] = v;
    }

    dfs(root, 0);
    printf("euler_tour: ");
    for(int i=0; i<sz; i++)
        printf("%d ", euler_tour[i]);
    printf("\n");
    build(0, 0, sz-1);

    traversal(0, 0, sz - 1);
    cout << "lca => " << lca(7,12) << endl;


}


