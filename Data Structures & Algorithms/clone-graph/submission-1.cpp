/*
// Definition for a Node.
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
*/

class Solution {
public:
    Node* dfs(Node* node, map<Node*,Node*> &mp){
        if(node== nullptr) return nullptr;
        if(mp.find(node)!=mp.end()) return mp[node]; // return the copy if its there already in the map
        Node* copy = new Node(node->val);
        mp[node]=copy;
        for(auto it : node->neighbors){
           copy->neighbors.push_back(dfs(it,mp));     
        }
        return copy;
    }
    Node* cloneGraph(Node* node) {
        map<Node*,Node*> mp;
        // mapping is original -> copy
       return dfs(node,mp);
    }
};
