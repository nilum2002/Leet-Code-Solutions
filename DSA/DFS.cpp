#include<bits/stdc++.h>
using namespace std;

// I implement the dfs algorithm using iterative method

void dfs (vector<vector<int>> &graph , int start ){

    stack<int> s;
    vector<bool> visitted(graph.size(), false);

    s.push(start);
    visitted[start] = true;
    while (!s.empty()){
        int node =  s.top();
        cout << node << " ";
        s.pop();

        for (auto n: graph[node]){
            if (!visitted[n]){
                s.push(n);
                visitted[n] = true;
            }
        }

    }
}


int main(){
    vector<vector<int>> graph = {
        {1, 2, 3},
        {0, 4},
        {0, 5},
        {0},
        {1},
        {2}
    };

    int start = 0;
    dfs(graph, start);

    return 0;


}