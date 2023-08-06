#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int INF = 1e9;
int d[N];
int visited[N];
int nodes, edges;

// dijkstra

vector<pair<int, int>> adj_list[N];

void dijkstra(int node)
{
    for (int i = 1; i <= nodes; i++)
    {
        d[i] = INF;
    }
    d[node] = 0;
    for (int i = 0; i < nodes; i++)
    {
        int selected_node = -1;
        for (int j = 1; j <= nodes; i++)
        {
            if (visited[j] == 1)
                continue;
            if (selected_node == -1 || d[selected_node] > d[j])
            {
                selected_node = j;
            }
        }

        visited[selected_node] = 1;

        for (auto adj_entry : adj_list[selected_node])
        {
            int adj_node = adj_entry.first;
            int edge_cost = adj_entry.second;
            if (d[selected_node] + edge_cost < d[adj_node])
            {
                d[adj_node] = d[selected_node] + edge_cost;
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
        adj_list[to].push_back({to, weight});
    }

    int src = 1;

    dijkstra(src);

    for (int i = 1; i <= nodes; i++)
    {
        cout << d[i] << " ";
    }
    cout << endl;

    return 0;
}