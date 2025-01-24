#include<bits/stdc++.h>
using namespace std;

/// Disjoint Set Union - START
struct DSU
{
    int V;
    vector< int > parent;
    vector< int > rank_;

    DSU(int vertices)
    {
        V = vertices;
        parent.resize(V);
        rank_.resize(V);

        for(int i=0; i<V; i++)
            set_(i);
    }

    void set_(int x)
    {
        parent[x] = x;
        rank_[x] = 0;
    }
    int find_(int x)
    {
        if(parent[x] == x) return x;
        else return parent[x] = find_(parent[x]);
    }
    bool union_(int u, int v)
    {
        int repU = find_(u);
        int repV = find_(v);
        if(repU!=repV)
        {
            if(rank_[repU]>rank_[repV])
                parent[repV] = repU;
            else if(rank_[repV]>rank_[repU])
                parent[repU] = repV;
            else
            {
                parent[repV] = repU;
                rank_[repU]+=1;
            }
            return true;
        }
        else
            return false;
    }
};
/// Disjoint Set Union - END


struct Edge
{
    int u, v;
    int w;
};

typedef struct Edge Edge;


bool compare(Edge &left, Edge &right)
{
    if(left.w<=right.w) return true;
    else return false;
}

int main()
{
    int E = 7;
    int V = 5;

    Edge edges[7] = {
        {0, 1, 1},
        {0, 2, 4},
        {1, 2, 2},
        {1, 3, 6},
        {2, 3, 3},
        {2, 4, 5},
        {3, 4, 7},
    };

// sort edges
    DSU *dsu = new DSU(V);
    sort(edges, edges+E, compare);


    int cost = 0;

    for(int i=0; i<E; i++)
    {
        Edge edge = edges[i];
        bool result = dsu->union_(edge.u, edge.v);

        if(result==true)
        {
            cout << edge.u << " " << edge.v << " " << edge.w << endl;

            cost += edge.w;
        }
    }
    cout << "Minimum Spanning Tree (Cost): " << cost << endl;
    return 0;

}
