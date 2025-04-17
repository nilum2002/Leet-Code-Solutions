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



TreeNode* Invert_bt(TreeNode* root){
    if (root == nullptr){
        return nullptr;

    }

    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;


    Invert_bt(root->left);
    Invert_bt(root->right);

}