void help(Node *root,vector<int> &ans,int level,unordered_map<int,int> &mm){
    if(!root)return;
    if(!mm[level]){
        ans.push_back(root->data);
        mm[level]=1;
    }
    level++;
    help(root->left,ans,level,mm);
    help(root->right,ans,level,mm);
}
//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
    vector<int> ans;
   unordered_map<int,int> mm;
   help(root,ans,0,mm);
   return ans;
   // Your code here
}
