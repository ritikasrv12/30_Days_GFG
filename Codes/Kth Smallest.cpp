class Solution {
  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k) {
        int n = arr.size();
        int limit = n-k+1;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int num : arr){
            pq.push(num);
            if(pq.size() > limit) pq.pop();
        }
        return pq.top();
    }
};
