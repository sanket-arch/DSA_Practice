#include <bits/stdc++.h>
using namespace std;
class Graph
{
    vector<int> *adj;
    int node, edges;

public:
    Graph(int noOfNode, int noOfEdges);
    void createUnGraph();
    void createDirGraph();

    void bfs();
    void dfs();
};
Graph::Graph(int noOfnode, int noOfEdges)
{
    node = noOfnode;
    edges = noOfEdges;
    adj = new vector<int>[node + 1];
}
void Graph::createUnGraph()
{
    int fromNode, toNode;

    for (int i = 1; i <= edges; i++)
    {
        cout << "from: ";
        cin >> fromNode;
        cout << "To: ";
        cin >> toNode;
        adj[fromNode].push_back(toNode);
        adj[toNode].push_back(fromNode);
    }
}
void Graph::createDirGraph()
{
    int fromNode, toNode;

    for (int i = 1; i <= edges; i++)
    {
        cout << "from: ";
        cin >> fromNode;
        cout << "To: ";
        cin >> toNode;
        adj[fromNode].push_back(toNode);
    }
}
void Graph::bfs()
{
    vector<int> visited(edges + 1, 0);
    vector<int> bfsList;

    for (int i = 1; i < edges; i++)
    {
        if (visited[i] == 0)
        {
            queue<int> q;
            q.push(i);
            visited[i] = 1;
            while (!q.empty())
            {
                int node = q.front();
                q.pop();
                bfsList.push_back(node);
                for (auto it : adj[node])
                {
                    if (visited[it] == 0)
                    {
                        visited[it] = 1;
                        q.push(it);
                    }
                }
            }
        }
    }
    for (auto it : bfsList)
    {
        cout << it << "->";
    }
    cout << "end";
}
vector<int> performDFS(int node, vector<int> adjList[], vector<int> &visited, vector<int> DFSList)
{
    DFSList.push_back(node);
    visited[node] = 1;
    for (auto it : adjList[node])
    {
        if (visited[it] == 0)
        {
            DFSList = performDFS(it, adjList, visited, DFSList);
        }
    }
    return DFSList;
}
void Graph::dfs()
{
    vector<int> visited(edges + 1, 0);
    vector<int> dfsList;

    for (int i = 0; i < edges; i++)
    {
        if (visited[i] == 0)
        {
            dfsList = performDFS(i, adj, visited, dfsList);
        }
    }
    for (int i = 1; i <= edges; i++)
    {
        cout << dfsList[i] << " ";
    }
    cout << endl;
}

int main()
{
    Graph graph(9, 9);
    graph.createUnGraph();
    graph.dfs();
    return 0;
}