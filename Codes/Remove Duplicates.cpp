class Solution {
  public:

    string removeDups(string str) {
        unordered_set<char> seen;
        string result;
        
        for (char c : str) {
            if (seen.find(c) == seen.end()) {
                seen.insert(c);
                result.push_back(c);
            }
        }
        
        return result;
        // Your code goes here
    }
};
