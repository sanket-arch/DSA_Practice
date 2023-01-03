//graphs here considered as 1-based indexing

#include<bits/stdc++.h>
using namespace std;
class graph
{
private:
    vector<int> *adj;
    int n, m;

public:
    graph(int node, int edge);
    vector<int> BFS();
    vector<int> DFS();
    void crateGraph();
    void createDirectedGraph();
};
graph::graph(int node, int edge)
{
    n = node;
    m = edge;
    adj = new vector<int>[n + 1]; //array of vctor type: we can store vector at each index
}
void graph::crateGraph()
{
    int u, v;
    for (int i = 0; i < m; i++)
    {
        cout << "ajcents node u ";
        cin >> u;
        cout << endl;
        cout << "ajacents node v";
        cin >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}
void graph::createDirectedGraph()
{
    int u, v;
    for (int i = 0; i < m; i++)
    {
        cout << "ajcents node u ";
        cin >> u;
        cout << endl;
        cout << "ajacents node v";
        cin >> v;

        adj[u].push_back(v);
    }
}

vector<int> graph::BFS()
{
    vector<int> bfs;
    vector<int> visited(n + 1, 0);

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            queue<int> q;
            q.push(i);
            visited[i] = 1;
            while (!q.empty())
            {
                int node = q.front();
                q.pop();
                bfs.push_back(node);
                for (auto it : adj[node])
                {
                    if (!visited[it])
                    {
                        q.push(it);
                        visited[it] = 1;
                    }
                }
            }
        }
    }
    return bfs;
}

void dfs(int Node, vector<int> &visited, vector<int> adj[], vector<int> &storeDfs)
{
    storeDfs.push_back(Node);
    visited[Node] = 1;
    for (auto it : adj[Node])
    {
        if (!visited[it])
        {
            dfs(it, visited, adj, storeDfs);
        }
    }
}

vector<int> graph::DFS()
{
    vector<int> visited(n + 1, 0);
    vector<int> storeDfs;

    for (int i = 1; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(i, visited, adj, storeDfs);
        }
    }

    return storeDfs;
}

// void createWeightedGraph()
// {
//     int m, n;
//     cin >> n >> m;
//     vector<pair<int, int>> adj[n + 1];
//     for (int i = 0; i < m; i++)
//     {
//         int u, v, wt;
//         cin >> u >> v >> wt;

//         adj[u].push_back({u, wt});
//         adj[v].push_back({u, wt});
//     }
// }
int main()
{
    graph g(5, 5);
    g.crateGraph();

    cout << "BFS:";
    vector<int> bfs=g.BFS();

    for(auto it:bfs)
    {
        cout<<bfs[it]<<" ";
    }
    cout << endl;
    vector<int> dfs = g.DFS();

    for (auto it : dfs)
    {
        cout << dfs[it] << " ";
    }
    return 0;
}
