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
    
    int ans = 0;
    
    int solve(TreeNode* node){
        if(node == NULL )return 0;
        
        int right = solve(node->right);
        int left = solve(node->left);
        
        ans = max(ans , right + left );
        
        return max(left , right) + 1;
        
        
    }
    int diameterOfBinaryTree(TreeNode* root) {
        
        solve(root);
        
        return ans;
    }
};
