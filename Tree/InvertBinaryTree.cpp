/*
翻转一棵二叉树
1         1
 / \       / \
2   3  => 3   2
   /       \
  4         4
*/

/*
lintcode和leetcode上的题目格式有点区别，但是本质差不多。
lintcode上的版本，没有返回值。
递归的版本比较简单，直接左子树递归，右子树递归，然后直接设立一个tmp互换就OK。
leetcode上有返回值要注意判断==NULL，这个要return NULL；

非递归版本还没想到。。。

Google: 90% of our engineers use the software you wrote (Homebrew),
but you can’t invert a binary tree on a whiteboard so fuck off.    
*/

//lint:
/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param root: a TreeNode, the root of the binary tree
     * @return: nothing
     */
    void invertBinaryTree(TreeNode *root) {
       if(root==NULL) return;
       invertBinaryTree(root->left);
       invertBinaryTree(root->right);
       
       TreeNode* tmp = root->left;
       root->left = root->right;
       root->right = tmp;
    }
};

//leetcode:

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
    TreeNode* invertTree(TreeNode* root) {
       if(root==NULL) return NULL;
       root->left = invertTree(root->left);
       root->right = invertTree(root->right);
       
       TreeNode* tmp = root->left;
       root->left = root->right;
       root->right = tmp;
       return root;
    }
};
