#include <iostream>
#include<vector>
#include<queue>
using namespace std;

// Node structure
struct Node {
    string data;
    Node* left;
    Node* right;

    Node(string val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Function to insert nodes into the tree
void insert(Node* &root, string val) {
    if (root == NULL) {
        root = new Node(val);
        return;
    }

    if (val < root->data) {
        insert(root->left, val);
    }
    else {
        insert(root->right, val);
    }
}

void levelorder(Node* root) {
    if (root == NULL) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            Node* curr = q.front();
            q.pop();
            cout << curr->data << " ";

            if (curr->left != NULL) {
                q.push(curr->left);
            }
            if (curr->right != NULL) {
                q.push(curr->right);
            }
        }
    }
}

// Function to perform inorder traversal
void inorder(Node* root) {
    if (root == NULL) {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Function to perform preorder traversal
void preorder(Node* root) {
    if (root == NULL) {
        return;
    }

    cout << root->data << " ";
    inorder(root->left);
    inorder(root->right);
}

// Function to perform postorder traversal
void postorder(Node* root) {
    if (root == NULL) {
        return;
    }

    inorder(root->left);
    inorder(root->right);
    cout << root->data << " ";
}

void diagonal(Node *root){

   if(!root){
       return;
   }
   queue<Node*>q;
   q.push(root);
   
   while(!q.empty()){
       Node* frontNode = q.front();
       q.pop();
       while(frontNode){
           if (frontNode->left){
               q.push(frontNode->left);
           }
           cout << frontNode->data << " ";

           frontNode = frontNode->right;
       }
    }
}
   
int main() {
    Node* root = NULL;
    int n;
    cout << "Enter number of values you want to input: ";
    cin >> n; 
    vector<string>arr; 
    for(int i = 0; i < n; i++){
        string temp;
        cout << "Enter value " << i + 1 << ": ";
        cin >> temp;
        arr.push_back(temp);
    }
    
    for (string val : arr) {
        insert(root, val);
    }

    cout << "Inorder Traversal of the Binary Tree: ";
    inorder(root);
    cout << endl;
    cout << "Preorder Traversal of the Binary Tree: ";
    preorder(root);
    cout << endl;
    cout << "Postorder Traversal of the Binary Tree: ";
    postorder(root);
    cout << endl;
    cout << "Diagonal View of the Binary Tree: ";
    diagonal(root);
    cout << endl;
    cout << "Level order of Binary Tree: ";
    levelorder(root);
    cout << endl;
    cout << "Thank you for using " << endl;
    return 0;
}
