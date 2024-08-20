class Solution {
  public:
  void mapParents(Node* root, unordered_map<Node*, Node*>& parentTrack, Node*& targetNode, int target) {
        // BFS to track parents and find the target node
        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            Node* current = q.front();
            q.pop();
            if (current->data == target) {
                targetNode = current;
            }
            if (current->left) {
                parentTrack[current->left] = current;
                q.push(current->left);
            }
            if (current->right) {
                parentTrack[current->right] = current;
                q.push(current->right);
            }
        }
    }

    int minTime(Node* root, int target) 
    {
        if (root == NULL) return 0;
        
        // Step 1: Map all parent nodes and find the target node
        unordered_map<Node*, Node*> parentTrack;
        Node* targetNode = NULL;
        mapParents(root, parentTrack, targetNode, target);
        
        // Step 2: Start BFS from the target node to burn the tree
        queue<Node*> q;
        unordered_map<Node*, bool> visited;
        q.push(targetNode);
        visited[targetNode] = true;
        int time = 0;
        
        while(!q.empty()) {
            int size = q.size();
            bool didBurn = false;
            
            for(int i = 0; i < size; i++) {
                Node* current = q.front();
                q.pop();
                
                // Visit the left child
                if (current->left && !visited[current->left]) {
                    didBurn = true;
                    q.push(current->left);
                    visited[current->left] = true;
                }
                
                // Visit the right child
                if (current->right && !visited[current->right]) {
                    didBurn = true;
                    q.push(current->right);
                    visited[current->right] = true;
                }
                
                // Visit the parent
                if (parentTrack[current] && !visited[parentTrack[current]]) {
                    didBurn = true;
                    q.push(parentTrack[current]);
                    visited[parentTrack[current]] = true;
                }
            }
            
            // Increment time only if some node was burned in this second
            if (didBurn) {
                time++;
            }
        }
        
        return time;
        // Your code goes here
    }
};
