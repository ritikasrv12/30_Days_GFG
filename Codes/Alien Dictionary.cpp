class Solution {
  public:
    string findOrder(string dict[], int n, int k) {
        // Step 1: Create an adjacency list for the graph
        vector<int> adj[k];
        vector<int> indegree(k, 0);
        
        // Step 2: Build the graph by comparing adjacent words
        for (int i = 0; i < n - 1; ++i) {
            string word1 = dict[i];
            string word2 = dict[i + 1];
            
            for (int j = 0; j < min(word1.size(), word2.size()); ++j) {
                if (word1[j] != word2[j]) {
                    adj[word1[j] - 'a'].push_back(word2[j] - 'a');
                    indegree[word2[j] - 'a']++;
                    break;
                }
            }
        }
        
        // Step 3: Topological Sort using Kahn's algorithm (BFS)
        queue<int> q;
        for (int i = 0; i < k; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        
        string order;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            order += (char)(node + 'a');
            
            for (int neighbor : adj[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        
        // If the order string contains k characters, it's a valid topological order.
        if (order.size() == k) return order;
        return "";
        // code here
    }
};
