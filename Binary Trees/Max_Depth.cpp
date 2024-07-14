#include <iostream>
#include <algorithm> 

using namespace std; // Added here

// Definition for a binary tree node (assuming this is given)
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
    int maxDepth(TreeNode* root) {
        if (root == nullptr) { 
            return 0; // Base case: empty tree has depth 0
        }

        // Recursively find depth of left and right subtrees
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right); 

        // Depth of the current node is 1 + max of its subtrees' depths
        return 1 + max(leftDepth, rightDepth);  // No need for std:: prefix
    }
};

// Example usage (you can add a main function to test this)
/*
int main() {
    // Create a sample tree...
    TreeNode* root = ...; 

    Solution sol;
    int maxDepth = sol.maxDepth(root);

    cout << "Maximum depth of the tree is: " << maxDepth << endl;
    return 0;
}
*/
