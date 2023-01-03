#include <bits/stdc++.h>
using namespace std;

class weightedGraph
{
    vector<pair<int, int>> *adj;
    int edge, node;

public:
    weightedGraph(int nodes, int edges);
    void createunGraph();

    // TRAVERSALS
    void bfs();
    void dfs();

    // ALGOS
    void dijketra();
    void prims();
    void print();
};

weightedGraph::weightedGraph(int noOfNodes, int noOfEdge)
{
    node = noOfNodes;
    edge = noOfEdge;
    adj = new vector<pair<int, int>>[node + 1];
}

void weightedGraph::createunGraph()
{
    int fromNode, toNode, weight;

    for (int i = 1; i <= edge; i++)
    {
        cout << "from: ";
        cin >> fromNode;
        cout << "To: ";
        cin >> toNode;
        cout << "weight: ";
        cin >> weight;
        adj[fromNode].push_back(make_pair(toNode, weight));
        adj[toNode].push_back(make_pair(fromNode, weight));
    }
}

void weightedGraph::bfs()
{
    vector<int> visited(edge + 1, 0);
    vector<int> bfsList;

    for (int i = 1; i < edge; i++)
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
                    if (visited[it.first] == 0)
                    {
                        visited[it.first] = 1;
                        q.push(it.first);
                    }
                }
            }
        }
    }

    for (auto it : bfsList)
    {
        cout << it << " ";
    }
    cout << endl;
}

vector<int> performDFS(int node, vector<pair<int, int>> adjList[], vector<int> &visited, vector<int> dfsList)
{
    visited[node] = 1;
    dfsList.push_back(node);

    for (auto it : adjList[node])
    {
        if (visited[it.first] == 0)
        {
            dfsList = performDFS(it.first, adjList, visited, dfsList);
        }
    }
    return dfsList;
}

void weightedGraph::dfs()
{
    vector<int> visited(edge + 1, 0);
    vector<int> dfsList;

    for (int i = 1; i < edge; i++)
    {
        if (visited[1] == 0)
            dfsList = performDFS(i, adj, visited, dfsList);
    }

    for (auto it : dfsList)
    {
        cout << it << " ";
    }
    cout << endl;
}

void weightedGraph::dijketra()
{
    int source;
    cout << "enter source";
    cin >> source;
    vector<int> dist(edge + 1, INT_MAX);
    // SEKELTON for priority queue of min heap
    // priority_queue<int,vector<int>,greater<int>> pq;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    // It is prirority queue

    pq.push(make_pair(0, source));
    dist[source] = 0;

    while (!pq.empty())
    {
        int prevNode = pq.top().second;
        int prevDist = pq.top().first;
        pq.pop();
        vector<pair<int, int>>::iterator it;
        for (auto it : adj[prevNode])
        {
            int nextNode = it.first;
            int nextDist = it.second;
            if (dist[nextNode] > nextDist + prevDist)
            {
                dist[nextNode] = nextDist + prevDist;
                pq.push(make_pair(dist[nextNode], nextNode));
            }
        }
    }

    for (int i = 1; i < edge; i++)
    {
        cout << "distance from " << source << " To " << i << " is " << dist[i] << endl;
    }
    cout << endl;
}

void weightedGraph::prims()
{
    vector<int> parents(edge, -1);
    vector<int> weightList(edge, INT_MAX);
    vector<bool> MSt(edge, false);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push(make_pair(0, 1));
    weightList[1] = 0;
    while (!pq.empty())
    {
        int prevWt = pq.top().first;
        int prevNode = pq.top().second;
        MSt[prevNode] = true;
        pq.pop();

        for (auto it : adj[prevNode])
        {
            int weight = it.second;
            int vertex = it.first;

            if (!MSt[vertex] && weight < weightList[vertex])
            {
                weightList[vertex] = weight;
                parents[vertex] = prevNode;
                pq.push(make_pair(weightList[vertex], vertex));
            }
        }
    }
    for (int i = 1; i < edge; i++)
    {
        cout << i << "--" << parents[i] << endl;
    }
}

void weightedGraph::print()
{
    for (int i = 1; i < edge; i++)
    {
        cout << "Node " << i << "makes edges with \n";
        for (auto it = adj[i].begin(); it != adj[i].end(); it++)
        {
            cout << "\t Node " << it->first << " with weight =" << it->second << "\n";
        }
        cout << "\n";
    }
}
int main()
{
    weightedGraph wtgraph(4, 5);
    wtgraph.createunGraph();
    wtgraph.prims();
    return 0;
}