#include<bits/stdc++.h>
using namespace std;
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
        else return parent[x] = find_(parent[x]); // the recursive call  
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
int main()
{
    DSU *dsu = new DSU(5);

    for(int i=0; i<5; i++)
    {
        cout << "Parent of " << i << " is: ";
        cout << dsu->parent[i] << endl;
    }

    cout << endl << endl;

    dsu->union_(0, 2);

    for(int i=0; i<5; i++)
    {
        cout << "Parent of " << i << " is: ";
        cout << dsu->parent[i] << endl;
    }


    cout << endl << endl;
    dsu->union_(1, 3);

    for(int i=0; i<5; i++)
    {
        cout << "Parent of " << i << " is: ";
        cout << dsu->parent[i] << endl;
    }


    cout << endl << endl;
    dsu->union_(2, 3);

    for(int i=0; i<5; i++)
    {
        cout << "Parent of " << i << " is: ";
        cout << dsu->parent[i] << endl;
    }


    cout << dsu->union_(2, 4) << endl;


    return 0;
}
