#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Edge {
    int u, v, weight;
};

vector<int> bellmanFord(int n, vector<Edge>& edges, int start) {
    // Initialize distances
    vector<int> dist(n + 1, INT_MAX);
    dist[start] = 0;
    
    // Relax edges n-1 times
    for (int i = 0; i < n - 1; i++) {
        bool updated = false;
        
        for (auto& edge : edges) {
            int u = edge.u;
            int v = edge.v;
            int w = edge.weight;
            
            // Check both directions since roads are bidirectional
            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                updated = true;
            }
            
        }
        
        // If no update occurred, we can break early
        if (!updated) {
            break;
        }
    }
    
    // Check for negative cycles (optional but good practice)
    for (auto& edge : edges) {
        int u = edge.u;
        int v = edge.v;
        int w = edge.weight;
        
        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            // Negative cycle detected - return empty vector
            return vector<int>();
        }
        if (dist[v] != INT_MAX && dist[v] + w < dist[u]) {
            // Negative cycle detected - return empty vector
            return vector<int>();
        }
    }
    
    return dist;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, m;
        cin >> n >> m;
        
        vector<Edge> edges; 
        
        for (int i = 0; i < m; i++) {
            int x, y, r;
            cin >> x >> y >> r;
            edges.push_back({x, y, r});
        }
        
        int s;
        cin >> s;
        
        // Run Bellman-Ford algorithm
        vector<int> distances = bellmanFord(n, edges, s);
        
        // Prepare output: distances to all cities except starting city
        vector<int> result;
        for (int i = 1; i <= n; i++) {
            if (i != s) {
                if (distances[i] == INT_MAX) {
                    result.push_back(-1);
                } else {
                    result.push_back(distances[i]);
                }
            }
        }
        
        // Print result
        for (int i = 0; i < result.size(); i++) {
            if (i > 0) cout << " ";
            cout << result[i];
        }
        cout << endl;
    }
    
    return 0;
}