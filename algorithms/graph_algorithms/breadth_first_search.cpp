/*
Breadth first search, or bfs for short, traverses every node in a graph efficiently.
Time Complexity: O(n+e), where n is the number of nodes and e the number of edges.

The algorithm uses a queue to determine the elements to be visited.
It starts by adding a single node to the queue and keeping track it's been visited.
The following steps are followed until the queue is empty:
    Read the node in the front of the queue.
    Add to the queue the non-visited adjacencies of this node, marking them as visited as they're added.
    Pop the queue.

In case of multiple connected components or the graph is directed and not strongly connected:
    A for loop can be used to iterate through nodes, and starts a bfs for each non-visited node in the graph.


Observations:
    Good for finding minimal paths between nodes in graphs where each edge has weight 1.
*/

//Implementation Examples:

#include <vector>
#include <queue>

using namespace std;

//Traversing every node in a connected undirected graph

void bfs(vector<vector<int>>& adjacencies) {
    vector<bool> vis(adjacencies.size(), false);
    queue<int> q;

    q.push(0);
    vis[0] = true;

    while(!q.empty()) {
        int node = q.front();

        for(int adjacency : adjacencies[node]) {
            if(!vis[adjacency]) {
                q.push(adjacency);
                vis[adjacency] = true;
            }
        }

        q.pop();
    }
}