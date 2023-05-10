#include<iostream>
using namespace std;
struct BstNode {
    int data;
    BstNode* left;
    BstNode* right;
};
BstNode* GetNewNode(int data){
    BstNode* newNode = new BstNode();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;

}
BstNode* Insert(BstNode* root, int data){
    if(root == NULL){
        root = GetNewNode(data);
    }
    else if(data <= root->data){
        root->left = Insert(root->left, data);
    }
    else{
        root->right = Insert(root->right, data);
    }
    return root;
}
bool Search(BstNode* root, int data){
    if(root == NULL)return false;
    else if(root->data == data) return true;
    else if(data <= root->data) return Search(root->left, data);
    else return Search(root->right, data);
}
int printcheck(BstNode* node){
    if(node == NULL) return 0;
    int x = node->data;
    return x;
}

int main(){
    BstNode* root;
    root = NULL;
    root = Insert(root, 15);
    root = Insert(root, 10);
    root = Insert(root, 20);
    if(Search(root, 15)){
        cout << 15 << ", Left: " << printcheck(root->left) << ", Right: " << printcheck(root->right)<< '\n';
    }
    if(Search(root, 10)){
        cout << root->left->data << ", Left: " <<  printcheck(root->left->left) << ", Right: " <<  printcheck(root->left->right) << '\n';
    }
    if(Search(root, 20)){
        cout << root->right->data << ", Left: " <<  printcheck(root->right->left) << ", Right: " <<  printcheck(root->right->right) << '\n';
    }
    if(Search(root, 5)){
        cout << false;
    }
}