/*
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val)
        : data(val)
        , left(nullptr)
        , right(nullptr) {}
};
*/

class Solution {
  public:
    Node* sortedArrayToBST(vector<int>& nums) {
         return buildBST(nums, 0, nums.size() - 1);
    }

private:
    Node* buildBST(vector<int>& nums, int start, int end) {
        if (start > end) {
            return nullptr;
        }
        int mid = start + (end - start) / 2;
        Node* node = new Node(nums[mid]);
        node->left = buildBST(nums, start, mid - 1);
        node->right = buildBST(nums, mid + 1, end);
        return node;
        // Code here
    }
};
