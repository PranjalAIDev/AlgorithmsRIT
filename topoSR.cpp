#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> topologicalSortKahn(int n, const vector<vector<int>>& adj) {
    vector<int> inDegree(n, 0);
    for (int i = 0; i < n; i++) {
        for (int neighbor : adj[i]) {
            inDegree[neighbor]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> topoOrder;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topoOrder.push_back(node);

        for (int neighbor : adj[node]) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
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

    vector<int> topoOrder = topologicalSortKahn(n, adj);

    cout << "Topological Sort using Source Removal Method:" << endl;
    for (int node : topoOrder) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
