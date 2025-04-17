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

int maxDepth(TreeNode* root) {
    if (root == nullptr){
        return 0;
    }
    int res = 1;
    stack<pair<TreeNode*, int>> stk;
    stk.push({root, 1});


    while (!stk.empty()){
        auto [node, depth] = stk.top();
        stk.pop();

        if (node){
            res = max(res, depth);
            if (node->left){
                stk.push({node->left, depth+1});
            }
            if (node->right){
                stk.push({node->right, depth+1});
            }
            
            
        }

        
    }

    return res;




}
