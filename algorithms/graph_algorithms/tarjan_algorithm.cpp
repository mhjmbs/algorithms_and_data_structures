/*
Tarjan's strongly connected components algorithm finds strongly connected components(scc) in a directed graph.
Time Complexity: O(n+e), where n is the number of nodes and e the number of edges in the graph.

A digraph is said to be strongly connected if and only if every vertex v is reachable from every other vertex u.
A strongly connected component in a graph is a maximal strongly connected subgraph.

The algorithm uses a dfs. During it's visit to node u, it does the following:
    Add u to a stack of nodes not associated to any scc so far.
    Set u's discovery time.
    Set u's lowlink as it's own discovery time.

    After trying to visit an adjacency v, if v is on the stack and lowlink[v] < lowlink[u], the following is deduced:
        v can reach an ancestor of u, thus, lowlink[u] must be updated to the value of lowlink[v].
        By only updating if v is on the stack, we guarantee we're only updating at tree and back edges, not cross edges.

    After visiting all u's adjacencies, if lowlink[u] = time of discovery of u, the lowest time of discovery reachable from u is itself.
    This means everything on the stack from u onwards is on the same scc as u(more on this later).
    The algorithm then pops the stack until u is popped. All the popped elements compose a scc of the graph.
    This unstacking is what allows for the property on line 20 to be true.
*/

//Implementation examples:

#include <vector>
#include <stack>

using namespace std;

//Finding sccs

void tarjan(int node, int& currTime, vector<int>& lowlink, vector<int>& time, vector<vector<int>>& adjacencies, stack<int>& s, vector<bool>& is_on_s) {
    lowlink[node] = time[node] = currTime;
    s.push(node);
    is_on_s[node] = true;

    for(int adj : adjacencies[node]) {
        if(!time[adj]) {
            tarjan(adj, ++currTime, lowlink, time, adjacencies, s, is_on_s);
        }

        if(is_on_s[adj]) {
            lowlink[node] = min(lowlink[node], lowlink[adj]);
        }
    }

    if(lowlink[node] == time[node]) {
        int v = -1;
        vector<int> currComponent;

        while(v != node) {
            v = s.top();
            s.pop();
            is_on_s[v] = false;
            currComponent.push_back(v);
        }
    }
}
