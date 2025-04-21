#include <iostream>

struct Node {
    int val;
    Node* left;
    Node* right;

    Node(int value) : val(value), left(nullptr), right(nullptr) {};
};

// Insert node to the Binary Search Tree using the recursive function
Node* recursiveInsert(Node* root, int value) { // Time: O(n) 
    if (root == nullptr) {
        return new Node(value);
    }
    
    if (value < root->val) {
        root->left = recursiveInsert(root->left, value);
    }
    else if (value > root->val) {
        root->right = recursiveInsert(root->right, value);
    }
    else {
        std::cout << "Duplicate value. Insertion skipped." << std::endl;
    }

    return root;
}

void dfs(Node* root) {
    if (root == nullptr) return;

    std::cout << root->val << " ";
    dfs(root->left);
    dfs(root->right);
}

void bfs(Node* root) {
    std::queue<Node*> treeQueue;
    treeQueue.push(root);

    while (!treeQueue.empty()) {
        auto front = treeQueue.front();
        treeQueue.pop();

        std::cout << front->val <<  " ";

        if (front->left != nullptr) treeQueue.push(front->left);
        if (front->right != nullptr) treeQueue.push(front->right);
    }
}

int main() {
    Node* root = recursiveInsert(nullptr, 10);
    recursiveInsert(root, 30);
    recursiveInsert(root, 7);
    recursiveInsert(root, 25);
    recursiveInsert(root, 1);

    dfs(root);
    std::cout << std::endl;
    bfs(root);

    return 0;
}