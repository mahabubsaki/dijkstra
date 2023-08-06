#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

vector<int> adj_list[N];
int visited[N], level[N];

int parent[N];

void bfs(int src)
{
    visited[src] = 1;
    level[src] = 1;
    parent[src] = -1;
    queue<int> que;
    que.push(src);

    while (!que.empty())
    {
        int head = que.front();
        que.pop();

        for (int adj_node : adj_list[head])
        {
            if (visited[adj_node] == 0)
            {
                parent[adj_node] = head;
                visited[adj_node] = 1;
                level[adj_node] = level[head] + 1;
                que.push(adj_node);
            }
        }
    }
}

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;
    for (int i = 0; i < edges; i++)
    {
        int from, to;
        cin >> from >> to;
        adj_list[from].push_back(to);
        adj_list[to].push_back(from);
    }

    int src_node = 1;

    bfs(src_node);
    int dest_node = nodes;
    if (visited[dest_node] != 0)
    {
        cout << level[dest_node] << '\n';
        int selected_node = dest_node;
        vector<int> path;
        while (true)
        {
            path.push_back(selected_node);
            if (selected_node == src_node)
            {
                break;
            }
            selected_node = parent[selected_node];
        }

        reverse(path.begin(), path.end());

        for (int node : path)
        {
            cout << node << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "IMPOSSIBLE\n";
    }

    return 0;
}