#include<bits/stdc++.h>
using namespace std;

class DSU{
    vector<int> parent;
    vector<int> rank;


    public :
    DSU(int n){
        parent.resize(n);
        rank.resize(n, 0);
        for (int i =0; i <n; i++){
            parent[i] = i;
            rank[i] = 1;
        }
    }

    int find(int i ){
        return (parent[i]==i)? i: parent[i] = find(parent[i]);
    }
    void unite(int x , int y){
        int s1 = find(x);
        int s2 = find(y);
        if (s1  != s2){
            if (rank[s1] < rank[s2]){
                parent[s1] = s2;
            }
            else if (rank[s1] > rank[s2]){
                parent[s2] = s1;
            }
            else {
                parent[s2] = s1;
                rank[s1]++;
            }   
        }
    }
   





};

bool comparator(vector<int> &a, vector<int> b){
    return (a[2] < b[2]) ? true: false;


} 


int kruskal(vector<vector<int>>&edges, int n){
    DSU dsu(n);
    sort(edges.begin(), edges.end(), comparator);
    int cost = 0;
    for (auto edge : edges){
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];
        if (dsu.find(u) != dsu.find(v)){
            cost += w;
            dsu.unite(u, v);
        }
    }
    return cost;
}






int main(){

    vector <vector<int>> edges = {
        {1, 2, 3},
        {2, 3, 4},
        {1, 3, 5},
        {3, 4, 6},
        {4, 5, 7}
    };
    int n = 5;


    cout << "Minimum cost of the MST is : " << kruskal(edges, n) << endl;
}

