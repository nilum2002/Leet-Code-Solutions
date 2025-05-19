#include <bits/stdc++.h>

using namespace std;




void bfs(vector<vector<int>> &graph , int start ){

    queue<int> q;
    vector<bool> visited(graph.size(), false);
    q.push(start);
    visited[start] = true;
    while (!q.empty()){
        int node = q.front();
        q.pop();
        // print the node 
        cout << node << " ";
        for (auto n : graph[node]){
            if (!visited[n]){
                q.push(n);
                visited[n] = true;
            }
        }

    }
}






int main(){
    vector<vector<int>> graph = {
        {1, 2, 3},//0
        {0, 4},// 1
        {0, 5}, // 2

        {0}, // 3
        {1}, // 4
        {2}
    };

    int start = 0;
    bfs(graph, start);

    return 0;
}