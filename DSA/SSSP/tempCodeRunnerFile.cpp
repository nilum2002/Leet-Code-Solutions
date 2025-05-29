if (dist[v] != INT_MAX && dist[v] + w < dist[u]) {
                dist[u] = dist[v] + w;
                updated = true;
            }