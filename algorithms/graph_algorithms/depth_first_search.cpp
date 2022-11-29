/*
Depth first search, or dfs for short, traverses every node in a graph efficiently.
Time Complexity: O(n+e), where n is the number of nodes and e the number of edges.

The algorithm uses a stack to determine the elements to be visited.
It starts by adding a single node to the stack.
The following steps are followed until the stack is empty:
    Read the node in the top of the stack.
    Pop the stack.
    Keep track that it's been visited.
    Add to the stack the non-visited adjacencies of this node.

In case of multiple connected components or the graph is directed and not strongly connected:
    A for loop can be used to iterate through nodes, and starts a dfs for each non-visited node in the graph.


Observations:
    DFS is normally recursively implemented, using the function call stack as it's stack.

    A non-recursive dfs must mark nodes visited in the moment they're added to the stack, else they might be visited more than once.

    DFS's execution generates a tree, whose edges are categorized as:
        Tree edges: edges pointing to an unvisited descendant,thus, used to find new nodes.
        Back edges: edges pointing to an ancestor.
        Cross edges: edges pointing to a node in another subtree.
        Forward edges: edges pointing to a visited descendant.

    For an undirected graph, it's dfs tree will only have tree edges and back edges.

    A back edge closes a cycle on the graph.

    The lowlink of a vertex u is the lowest reachable discovery time from u.
*/

//Implementation Examples:

#include <vector>
#include <stack>

using namespace std;

//Recursive dfs

void dfs1(int node, vector<vector<int>>& adjacencies, vector<bool> vis) {
    vis[node] = true;

    for(int adjacency : adjacencies[node]) {
        if(!vis[adjacency]) {
            dfs1(adjacency, adjacencies, vis);
        }
    }
}

//Iterative dfs

void dfs2(vector<vector<int>>& adjacencies) {
    vector<bool> vis(adjacencies.size(), false);
    stack<int> s;

    s.push(0);
    vis[0] = true;

    while(!s.empty()) {
        int node = s.top();
        s.pop();

        for(int adjacency : adjacencies[node]) {
            if(!vis[adjacency]) {
                s.push(adjacency);
                vis[adjacency] = true;
            }
        }
    }
}
