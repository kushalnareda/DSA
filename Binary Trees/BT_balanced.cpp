#include <iostream>
#include <cmath>
#include <algorithm>

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
        if (root == NULL) return 0;

        int left = maxDepth(root->left);
        int right = maxDepth(root->right);

        return 1 + std::max(left, right);
    }

    bool isBalanced(TreeNode* root) {
        if (root == nullptr) 
            return true;

        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);

        if (abs(leftDepth - rightDepth) <= 1 && 
            isBalanced(root->left) && 
            isBalanced(root->right)) {
            return true;
        }
        return false;
    }
};

// Helper function to create a new tree node
TreeNode* newNode(int val) {
    return new TreeNode(val);
}

int main() {
    // Creating a simple test tree: 
    //         1
    //        / \
    //       2   3
    //      / \
    //     4   5
    TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    Solution solution;
    bool balanced = solution.isBalanced(root);
    if (balanced) {
        std::cout << "The tree is balanced." << std::endl;
    } else {
        std::cout << "The tree is not balanced." << std::endl;
    }

    return 0;
}
