#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfs(int node, vector<bool>& visited, stack<int>& Stack, const vector<vector<int>>& adj) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, visited, Stack, adj);
        }
    }
    Stack.push(node);
}

vector<int> topologicalSortDFS(int n, const vector<vector<int>>& adj) {
    vector<bool> visited(n, false);
    stack<int> Stack;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, visited, Stack, adj);
        }
    }

    vector<int> topoOrder;
    while (!Stack.empty()) {
        topoOrder.push_back(Stack.top());
        Stack.pop();
    }

    return topoOrder;
}

int main() {
    int n = 6; 
    vector<vector<int>> adj(n);


    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    vector<int> topoOrder = topologicalSortDFS(n, adj);

    cout << "Topological Sort using DFS:" << endl;
    for (int node : topoOrder) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
