/*
Given a binary tree, find its maximum depth.
The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
*/

/*
这个题最早在知乎上看到解法。好巧妙
自己在递归的时候加了ans变量，不过貌似不用，直接每次递归结果加一就可以了。
*/

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
    int maxDepth(TreeNode* root) {
        int ans=1;
        if(root == NULL) return 0;
        else ans+=max(maxDepth(root->left),maxDepth(root->right));
        return ans;
        
    }
};
