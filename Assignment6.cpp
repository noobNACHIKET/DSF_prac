#include<iostream>
#define MAX 20
#define INT_MAX 999999 
using namespace std;

class prims
{  
    int graph[MAX][MAX];
    int vert,edge;
    bool visited[MAX];
    int dist[MAX], parent[MAX];
    
    public:
    void create();
    void mst(); 
    int minimum(); 
    void print(); 
    void cost(); 
};

int prims::minimum()
{
    int min_index, min_ele = INT_MAX;
    for(int i = 0; i < vert; i++) {
        if(visited[i] == false && dist[i] < min_ele) {
            min_ele = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

void prims::mst()
{
    for (int i = 0; i < vert; i++) {
        visited[i] = false;
        dist[i] = INT_MAX;
    }
    dist[0] = 0;
    parent[0] = -1;
    
    for (int i = 0; i < vert - 1; i++) {
        int u = minimum();
        visited[u] = true;
        
        for (int j = 0; j < vert; j++) {
            if (graph[u][j] && visited[j] == false && graph[u][j] < dist[j]) {
                parent[j] = u;
                dist[j] = graph[u][j];
            }
        }
    }
    print();
}

void prims::create()
{
    int src,dest,wt;
    cout<<"\n Enter Number of vertices: ";
    cin>>vert;
    cout<<"\n Enter Number of edges: ";
    cin>>edge;
    
    for (int i = 0; i < vert; i++) {
        for (int j = 0; j < vert; j++) {
            graph[i][j] = 0; // Initialize graph with 0
        }
    }
    
    for (int i = 0; i < edge; i++) {
        cout<<"\n Enter Source, Destination & weight (S,D,W): ";
        cin>>src>>dest>>wt;
        graph[src][dest] = wt;
        graph[dest][src] = wt;
    }
}

void prims::print()
{
    cout<<"\nEdge \tWeight ";
    for (int i = 1; i < vert; i++) {
        cout<<"\n"<<parent[i]<<" - "<<i<<"\t"<<dist[i];
    }
    cout<<endl<<endl;
}

void prims::cost()
{
    int min_cost = 0;
    for (int i = 1; i < vert; i++) {
        min_cost += dist[i];
    }
    cout<<"\n Minimum cost = "<<min_cost<<endl;
}
int main(){
    prims obj;
    int ch;
    do{
        cout<<"\n 1. Create MST";
        cout<<"\n 2. Display MST";
        cout<<"\n 3. Minimum Cost";
        cout<<"\n 4. EXIT";
        cout<<"\n   Enter choice: ";
        cin>>ch;
        if(ch==1)
            obj.create();
        else if(ch==2)
            obj.mst();
        else if(ch==3)
            obj.cost();
    }
    while(ch!=4);
}