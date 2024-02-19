#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
};
void printList(Node* head){
    if(head==nullptr){
        return;
    }
    cout<<head->data<<" ";
    printList(head->next);
}
void insertAtTheFront(Node**head,int data){
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}
void insertAtTheEnd(Node** head,int data){
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    if(*head==nullptr){
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while(temp->next!=nullptr){
        temp = temp->next;
    }
    temp->next = newNode;
}
void insertAtTheMiddle(Node** head,int data,int position){
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    if(position==1){
        newNode->next = *head;
        *head = newNode;
        return;
    }
    Node* temp = *head;
    for(int i=0;i<position-2;i++){
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}


int main(){
    Node* head = new Node();
    head->data = 1;
    head->next = nullptr;
    insertAtTheFront(&head,2);
    insertAtTheEnd(&head,3);
    insertAtTheMiddle(&head,4,2);

   
    printList(head);
    return 0;
}