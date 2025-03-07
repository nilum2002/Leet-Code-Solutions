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
#include <iostream>
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
        TreeNode* create_node(int key){
            TreeNode* new_node = new TreeNode();
            new_node->val = key;
            new_node->left = new_node->right = nullptr;
            return new_node;

        }
        TreeNode* insert_node(TreeNode* root, int key){
            if (root == nullptr){
                return create_node(key);
            }
            if (key < root->val){
                root->left = insert_node(root->left, key);
            } else if (key > root->val) {
                root->right = insert_node(root->right, key);
            }
            return root;
        }
        void print_ll(TreeNode* root){
            if (root == nullptr){
                return ;
            }
            print_ll(root->left);
            cout << root->val << " ";
            print_ll(root->right); 
        }

        // your codes goes here 
        TreeNode* deleteNode(TreeNode* root, int key) {
            if (root== nullptr) return root;
            if (key < root->val){
                root->left = deleteNode(root->left, key);
            }else if (key > root->val){
                root->right = deleteNode(root->right, key);
            }else{
                // if equals 
                if (root->left== nullptr){
                    TreeNode* temp = root->right;
                    delete root;
                    return temp;
                }else if (root->right == nullptr){
                    TreeNode* temp = root->left;
                    delete root;
                    return temp;
                }
                TreeNode* curr = root->right;
                while (curr->left!= nullptr){
                    curr = curr->left;
                }
                root->val =curr->val;
                //delete curr;
                
                root->right = deleteNode(root->right, curr->val);
    
            }
            return root;
            
        }
    };



    int main(){
        Solution myll;
        TreeNode* root = nullptr;
        root = myll.insert_node(root, 5);
        root = myll.insert_node(root, 3);
        root = myll.insert_node(root, 6);
        root = myll.insert_node(root, 2);
        root = myll.insert_node(root, 4);
        //root = myll.insert_node(root, 0);
        root = myll.insert_node(root, 7);
        root = myll.deleteNode(root, 3);
        myll.print_ll(root);






    }

