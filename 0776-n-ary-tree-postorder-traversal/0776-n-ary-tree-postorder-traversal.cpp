/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    // To store the output result...
    vector<int> output;
    void traverse(Node* root) {
        // Base case: if the tree is empty...
        if(root == NULL) return;
        // Recursively traverse each node in the children array...
        for(auto node:root->children)
            traverse(node);
        // Push the value of the root node to the output...
        output.push_back(root->val);
    }
    vector<int> postorder(Node* root) {
        output.clear();
        traverse(root);
        return output;
    }
};