/*
Dijkstra's algorithm finds the shortest path from a node u to every other node in a graph with weighted edges.
Time Complexity: O(n+e), where n is the number of nodes and e the number of edges.

The algorithm initially defines de distance from u to every other node as infinite, except u->u, where dist = 0.
A priority queue will be used to visit nodes from the closest to u to furthest.
Node u is added to the priority queue, and the following steps are repeated until it's empty:
    Read the node in the front of the queue.
    Pop the queue;
    If node is visited, skip this node
    Mark it as visited.
    For each non-visited adjacency:
        distance to adjacency = min(distance to adjacency, distance to node + edge from node to adjacency).
        Add adjacency to priority queue if distance to adjacency has been successfully deacreased.


Observations:
    Once a node is visited, it's minimum distance from u has been found and will not change, because every node in the priority queue has distance >= than dist[node].
*/

//Implementation Examples:

#include <vector>
#include <queue>
#include <climits>

using namespace std;
using pii = pair<int,int>;

//Finding minimum path from node 0 to every other node in an undirected connected graph

void dijkstra(vector<vector<pii>>& adjacencies, vector<vector<int>>) {
    vector<bool> vis(adjacencies.size(), false);
    priority_queue<pii, vector<pii>, greater<pii>> prioq;
    vector<int> dist(adjacencies.size(), INT_MAX);

    dist[0] = 0;
    prioq.emplace(dist[0],0);

    while(!prioq.empty()) {
        int node = prioq.top().second;
        int nodeDist = prioq.top().first;
        prioq.pop();

        if(vis[node]) continue;
        vis[node] = true;

        for(pii adjacency : adjacencies[node]) {
            int adj = adjacency.second;
            int adjWeight = adjacency.first;

            if(!vis[adj] && dist[adj] > dist[node] + adjWeight) {
                dist[adj] = dist[node] + adjWeight;
                prioq.emplace(dist[adj], adj);
            }
        }
    }
}