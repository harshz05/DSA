/*
=========================================
LeetCode 129 - Sum Root to Leaf Numbers
=========================================

Difficulty :medium

Pattern    :dfs + carry state 

Time        :

Space       :

Date Solved : 2026-07-18

=========================================
*/

class Solution {
public:

int dfs( TreeNode* root , int cur) {
   if ( root == nullptr) return 0 ;

   cur = cur*10 + root -> val ;
   if( root -> left == nullptr && root -> right == nullptr) return cur ;
   return dfs(root->left , cur) + dfs(root -> right , cur ) ;
 }
    int sumNumbers(TreeNode* root) {

        return dfs(root , 0 ) ;

    }
};
