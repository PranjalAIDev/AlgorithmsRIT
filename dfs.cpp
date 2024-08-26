#include <iostream>
#include <vector>
#include <stack>

using namespace std;


void DFS(int start, const vector<vector<int>>& graph) {
    vector<bool> visited(graph.size(), false);
    stack<int> stack;

    visited[start] = true; 
    stack.push(start); 

    while (!stack.empty()) {
        int node = stack.top(); 
        stack.pop(); //
        cout << node << " "; 

        
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true; 
                stack.push(neighbor); 
            }
        }
    }
}

int main() {
    
    vector<vector<int>> graph = {
        {},        
        {2, 3},   
        {1, 4},   
        {1, 5},   
        {2},     
        {3}      
    };

    cout << "DFS starting from node 1: ";
    DFS(1, graph); 
    cout << endl;

    return 0;
}