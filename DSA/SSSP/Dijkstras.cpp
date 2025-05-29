#include <iostream>
#include <vector>
#include <queue>
using namespace std;



vector<int> dijkstra(int n,vector<vector<int>> &graph, int start) {
    // construct adj list
    vector<vector<vector<int>>> adj(n + 1);

    for (const auto &edge : graph){
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // since roads are bidirectional
    }

    vector<int> dist(n, INT_MAX);
    
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    pq.push({0, start});


    dist[start] = 0;


    while (!pq.empty()){
        int u = pq.top()[1];
        int d = pq.top()[0];
        pq.pop();
        for ( auto x: adj[u]){
            int v = x[0];
            int w = x[1];
            if (dist[v] > d + w){
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}


int main(){


    int t;
    cin >> t; 



    for (int i = 0; i < t; i++){
        int n, m; 
        vector<vector<int>> graph;
        cin >> n >> m; // n is the number of nodes, m is the number of edges
        for (int j = 0; j < m; j++){
            int x, y, z;
            cin >> x >> y >> z; // x is the first node, y is the second node, z is the weight of the edge
            graph.push_back({x, y, z}); // Add the edge to the graph
        }

        int s;
        cin >> s; // s is the starting node

        vector<int> dist = dijkstra(n, graph, s); // Call the dijkstra function
        for (int j = 0; j <n ; j++){
            if (dist[j] == INT_MAX) continue;
            if (dist[j] == 0){
                cout << -1 << " "; // If the distance is 0, it means it's the starting node, so we print -1
            }else{
            cout << dist[j] << " ";
            }


        }
    }}



/* for best practices 
#include <iostream>
#include <vector> 
#include <queue>
#include <climits>
using namespace std;

typedef pair<int, int> pii;

void dijkstra(int n, vector<vector<pii>>& adj, int s, vector<int>& dist) {
    dist.assign(n + 1, INT_MAX);
    dist[s] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, s});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<pii>> adj(n + 1); // 1-indexed

        for (int i = 0; i < m; i++) {
            int x, y, r;
            cin >> x >> y >> r;
            adj[x].push_back({y, r});
            adj[y].push_back({x, r}); // undirected
        }

        int s;
        cin >> s;

        vector<int> dist;
        dijkstra(n, adj, s, dist);

        // Output distances excluding the starting node s
        for (int i = 1; i <= n; ++i) {
            if (i == s) continue;
            if (dist[i] == INT_MAX)
                cout << -1 << " ";
            else
                cout << dist[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
*/
