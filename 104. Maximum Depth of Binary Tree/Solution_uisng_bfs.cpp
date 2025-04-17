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
    


    queue<TreeNode*> q;
    q.push(root);
    int level = 0;

    while (!q.empty()){
        int size_ = q.size();
        for (int i = 0; i < size_; i++){
            TreeNode* a = q.front();
            q.pop();


            if (a->left){
                q.push(a->left);
            }
            if (a->right){
                q.push(a->right);
            }
        }

        level++;
    }

    return level;
    
}



