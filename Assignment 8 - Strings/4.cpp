#include <iostream>
#include <sstream>
#include <vector>
#include <stack>

 struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* str2tree(const std::string& s) {
    if (s.empty())
        return nullptr;

    std::istringstream iss(s);
    return constructTree(iss);
}

TreeNode* constructTree(std::istringstream& iss) {
    int rootValue;
    iss >> rootValue;

    TreeNode* root = new TreeNode(rootValue);
    if (iss.peek() == '(') {
        iss.get();  
        root->left = constructTree(iss);
        iss.get();  
    }

    if (iss.peek() == '(') {
        iss.get();  
        root->right = constructTree(iss);
        iss.get();  
    }

    return root;
}

 void inorderTraversal(TreeNode* root, std::vector<int>& result) {
    if (!root)
        return;

    inorderTraversal(root->left, result);
    result.push_back(root->val);
    inorderTraversal(root->right, result);
}

int main() {
    std::string s = "4(2(3)(1))(6(5))";
    TreeNode* root = str2tree(s);

    std::vector<int> result;
    inorderTraversal(root, result);

    std::cout << "Output: [";
    for (size_t i = 0; i < result.size(); ++i) {
        std::cout << result[i];
        if (i < result.size() - 1)
            std::cout << ",";
    }
    std::cout << "]" << std::endl;

     std::stack<TreeNode*> nodes;
    nodes.push(root);
    while (!nodes.empty()) {
        TreeNode* node = nodes.top();
        nodes.pop();
        if (node->right)
            nodes.push(node->right);
        if (node->left)
            nodes.push(node->left);
        delete node;
    }

    return 0;
}
