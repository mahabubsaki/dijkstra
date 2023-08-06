#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int INF = 1e9;
int distanceArr[N];
int visited[N];
int nodes, edges;
priority_queue<pair<int, int>> pq;

// dijkstra

vector<pair<int, int>> adj_list[N];

void dijkstra(int node)
{
    pq.push({0, node});
    for (int i = 1; i <= nodes; i++)
    {
        distanceArr[i] = INF;
    }
    distanceArr[node] = 0;

    while (!pq.empty())

    {

        int head_node = pq.top().second;
        int head_distance = pq.top().first;
        pq.pop();
        if (visited[head_node] == 0)
        {
            visited[head_node] = 1;
            for (auto adj_entry : adj_list[head_node])
            {
                int adj_node = adj_entry.first;
                int edge_cost = adj_entry.second;
                if (distanceArr[head_node] + edge_cost < distanceArr[adj_node])
                {
                    distanceArr[adj_node] = distanceArr[head_node] + edge_cost;
                    pq.push({distanceArr[adj_node], adj_node});
                }
            }
        }
    }
}

int main()
{

    cin >> nodes >> edges;

    for (int i = 0; i < edges; i++)
    {
        int from, to, weight;
        cin >> from >> to >> weight;
        adj_list[from].push_back({to, weight});
        adj_list[to].push_back({from, weight});
    }

    int src = 1;

    dijkstra(src);

    for (int i = 1; i <= nodes; i++)
    {
        cout << distanceArr[i] << " ";
    }
    cout << endl;

    return 0;
}