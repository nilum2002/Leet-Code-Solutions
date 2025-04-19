#include <bits/stdc++.h>

using namespace std;



 struct TreeNode {
     int val;
     TreeNode *left;
    TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
    public:
    
        void get_leaves(TreeNode* root, vector<int>&l){
            if (root == nullptr) return ;
            if (root->left == nullptr && root->right == nullptr){
                l.push_back(root->val);
            }
            get_leaves(root->left, l);
            get_leaves(root->right,l);
        }
        bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    
            vector<int> l1, l2;
    
            get_leaves(root1, l1);
            get_leaves(root2, l2);
            return l1 == l2;
    
    
    
    
            
        }
    };