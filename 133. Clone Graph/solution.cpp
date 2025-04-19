#include <bits/stdc++.h>



using namespace std;


class Node {
    public:
        int val;
        vector<Node*> neighbors;
        Node() {
            val = 0;
            neighbors = vector<Node*>();
        }
        Node(int _val) {
            val = _val;
            neighbors = vector<Node*>();
        }
        Node(int _val, vector<Node*> _neighbors) {
            val = _val;
            neighbors = _neighbors;
        }
    };
   
    
    class Solution {
    public:
        map<Node*, Node*> oldTonew ;
    
        
       
    
        Node* cloneGraph(Node* node) {
            
    
            if (node == nullptr){
                return nullptr;
            }else{
                return dfs(node);
            }
    
    
    
    
    
            
             
        }
    
         Node* dfs(Node* node){
            
            if (oldTonew.find(node)!= oldTonew.end()){
                return oldTonew[node];
            }
            Node* copy = new Node(node->val);
    
            oldTonew[node] = copy;
            for (auto n: node->neighbors){
                copy->neighbors.push_back(dfs(n));
            }
            return copy;
            }
    
    
    };
