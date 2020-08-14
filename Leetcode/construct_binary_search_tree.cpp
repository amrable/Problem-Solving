/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int id;
    TreeNode* solve(vector<int>& preorder , int limit  ){
      if(id >= preorder.size() ){
        return NULL;
      }
      
      int curr_value = preorder[id];
      
      if(curr_value > limit){
        return NULL;
      }
      
      TreeNode* root = new TreeNode(curr_value);
      id++;
      root->left = solve(preorder, curr_value );
      
      root->right = solve(preorder, limit );
      
      return root;
      
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
      id = 0;
      return solve(preorder , INT_MAX);
    }
};  
