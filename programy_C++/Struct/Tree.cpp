#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};
Node* createNode(int data){
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}
void printTree(Node* root){
    if(root==nullptr){
        return;
    }
    printTree(root->left);
    cout<<root->data<<" ";
    printTree(root->right);
}


void Insert(Node** root,int data){
    if(root==nullptr){
        root=createNode(data);
    }
    else if(data<=root->data){
        Insert(root->left,data);
    }
    else{
        Insert(root->right,data);
    }
}
bool Search(Node* root, int data){
    if(root==nullptr){
        return false;
    }
    else if(root->data==data){
        return true;
    }
    else if(data<=root->data){
        return Search(root->left,data);
    }
    else{
        return Search(root->right,data);
    }
}

int main(){
    Node* root = createNode(0);
    Insert(&root,1);
    

    printTree(root);

    int number;
    cin>>number;
    if(Search(root,number)==true){
        cout<<"Found"<<endl;
    }
    else{
        cout<<"Not Found"<<endl;
    }

}