#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> answer;

class Node{
public:
    int key, x, y;
    Node *left = nullptr;
    Node *right = nullptr;
    Node(int key, int x, int y) : key(key), x(x), y(y) {}
};

Node* makeBinaryTree(Node* root, Node* newNode){
    if (!root)
        return newNode;
    if (root->x > newNode->x)
        root->left = makeBinaryTree(root->left, newNode);
    else
        root->right = makeBinaryTree(root->right, newNode);
    return root;
}

void preOrder(Node *node){
    if (!node) return;
    answer[0].push_back(node->key);
    preOrder(node->left);
    preOrder(node->right);
}

void postOrder(Node *node){
    if (!node) return;
    postOrder(node->left);
    postOrder(node->right);
    answer[1].push_back(node->key);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    
    vector<Node *> nodes;
    for (int i = 0; i < nodeinfo.size(); ++i){
        nodes.push_back(new Node(i + 1, nodeinfo[i][0], nodeinfo[i][1]));
    }
    sort(nodes.begin(), nodes.end(),
        [](Node *a, Node *b) -> bool {
            if (a->y == b->y) return a->x < b->x;
            return a->y > b->y;
        });
    
    Node *root = nullptr;
    for (auto node : nodes){
        root = makeBinaryTree(root, node);
    }
    
    answer.resize(2);
    preOrder(root);
    postOrder(root);
    
    return answer;
}