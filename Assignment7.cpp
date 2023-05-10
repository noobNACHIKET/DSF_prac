#include<iostream>
#include<algorithm>
#define MAX 20 

using namespace std;

class kruskal {
    int n, e;
    int parent[MAX], rank[MAX];
    struct edge {
        int src, dest, wt;
    } edges[MAX];

    public:
        void create(); 
        void mst(); 
        void cost();
        int find(int); 
        void Union(int, int); 
        static bool compare(const edge&, const edge&);
        edge result[MAX];

};

void kruskal::create() {
    cout << "\nEnter Number of vertices: ";
    cin >> n;
    cout << "\nEnter Number of edges: ";
    cin >> e;

    for (int i = 0; i < e; i++) {
        cout << "\nEnter Source, Destination & weight of edge " << i+1 << ": ";
        cin >> edges[i].src >> edges[i].dest >> edges[i].wt;
    }
}

bool kruskal::compare(const edge& a, const edge& b) {
    return a.wt < b.wt;
}

int kruskal::find(int v) {
    if (parent[v] == v) return v;
    return parent[v] = find(parent[v]);
}

void kruskal::Union(int x, int y) {
    int xr = find(x), yr = find(y);
    if (xr == yr) return;

    if (rank[xr] < rank[yr]) {
        parent[xr] = yr;
    } else if (rank[xr] > rank[yr]) {
        parent[yr] = xr;
    } else {
        parent[xr] = yr;
        rank[yr]++;
    }
}

void kruskal::mst() {
    sort(edges, edges+e, compare);

    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    int numEdges = 0, i = 0;

    while (numEdges < n-1) {
        edge currEdge = edges[i++];

        int x = find(currEdge.src), y = find(currEdge.dest);
        if (x != y) {
            result[numEdges++] = currEdge;
            Union(x, y);
        }
    }

    cout << "\nMinimum Spanning Tree edges:\n";
    for (int i = 0; i < numEdges; i++) {
        cout << result[i].src << " - " << result[i].dest << " : " << result[i].wt << endl;
    }
}

void kruskal::cost()
{
    int min_cost = 0;
    for (int i = 1; i < n; i++) {
        min_cost += result[i].wt;
    }
    cout<<"\n Minimum cost = "<<min_cost<<endl;
}

int main() {
    kruskal obj;
    int ch;

    do {
        cout << "\n1. Create Graph";
        cout << "\n2. Find Minimum Spanning Tree";
        cout << "\n3. Minumum cost";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> ch;

        switch(ch) {
            case 1:
                obj.create();
                break;

            case 2:
                obj.mst();
                break;

            case 3:
                obj.cost();
                break;
            case 4:
                cout << "\nExiting...\n";
                break;
            default:
                cout << "\nInvalid choice!\n";
                break;
        }
    } while (ch != 4);

    return 0;
}
