/*
=========================================
LeetCode 101 - Symmetric tree
=========================================

Difficulty :easy 

Pattern    :recursion 

Time        :

Space       :

Date Solved : 2026-07-02

=========================================
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

bool  mir (TreeNode*a , TreeNode*b) {


    if ( a==NULL && b==NULL) return true ;
    if ( a== NULL || b== NULL) return false ;
    if ( a ->val != b -> val) return false ;

    return mir( a->left , b->right ) &&  mir(a->right  , b->left ) ;
}
    bool isSymmetric(TreeNode* root) {
        return mir ( root -> left , root ->right ) ;
        
    }
};