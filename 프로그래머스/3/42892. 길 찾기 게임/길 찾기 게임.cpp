#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> answer;

typedef struct Info{
    int key, x, y;
}Info;
vector<Info> nodes;

class Node{
public:
    Info info;
    Node *left, *right;
    Node(Info i) : info(i), left(nullptr), right(nullptr) {}
};

Node* makeBinaryTree(Node* root, Info info){
    if (!root)
        return new Node(info);
    if ((root->info).x > info.x)
        root->left = makeBinaryTree(root->left, info);
    else
        root->right = makeBinaryTree(root->right, info);
    return root;
}

void preOrder(Node *node){
    if (!node) return;
    answer[0].push_back((node->info).key);
    preOrder(node->left);
    preOrder(node->right);
}

void postOrder(Node *node){
    if (!node) return;
    postOrder(node->left);
    postOrder(node->right);
    answer[1].push_back((node->info).key);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    
    for (int i = 0; i < nodeinfo.size(); ++i){
        nodes.push_back({i + 1, nodeinfo[i][0], nodeinfo[i][1]});
    }
    sort(nodes.begin(), nodes.end(),
        [](Info &a, Info &b) -> bool {
            if (a.y == b.y)
                return a.x < b.x;
            return a.y > b.y;
        });
    
    Node *root = nullptr;
    for (auto &info : nodes){
        root = makeBinaryTree(root, info);
    }
    
    answer.resize(2);
    preOrder(root);
    postOrder(root);
    
    return answer;
}