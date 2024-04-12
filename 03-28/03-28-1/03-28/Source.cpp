#include<iostream>
using namespace std;
typedef struct Node {
    string data;
    struct Node* next=NULL;
} Node;
Node* push(Node* head,Node**end,string data) {
    Node* New_Node = new Node();
    New_Node->data = data;
    New_Node->next = NULL;
    if (head==NULL)
    {
       // (*end)->next = New_Node;
        (*end) = New_Node;
        head = New_Node;
    }
    else
    {
        (*end)->next = New_Node;
        (*end) = New_Node;
    }
    return head;
}
Node* POP(Node** head, Node* end) {
    Node* temp = *head;
    if (temp->next==NULL)
    {
        (*head) = NULL;
        free(temp);
    }
    else {
        while (temp != NULL)
        {
            if (temp->next == end) {
                cout << "POP : " << temp->next->data << endl;
                end = temp;
                end->next = NULL;
                free(temp->next);
                return end;
            }
            temp = temp->next;
        }
    }
}
void Print_list(Node* ptr) {
    while (ptr!=NULL) {
        cout << ptr->data << " -> ";
        ptr = ptr->next;
    }
}
int main() {
    int choice = 0,stack=0;
    string str = "";
    Node* head = NULL;
    Node* end = NULL;

    while (choice!=-1)
    {
        cout << "(1)PUSH (2)POP (-1)離開 : ";
        cin >> choice;
        switch (choice) {
        case 1://push
            if (stack==5)
            {
                cout << "Stack is full\n";
                break;
            }
            cout << "PUSH :";
            cin >> str;
            head=push(head, &end,str);
            stack++;
            break;
        case 2://pop
            if (stack==0)
            {
                cout << "Stack is Empty!!!!\n"; 
                break;
            }
            end = POP(&head, end);
            stack--;
            break;
        case -1:
            break;
        default:
            cout << "輸入錯誤!!!!\n";
            break;
        }
        Print_list(head);
        cout << "目前stack(" << stack << "/5)\n";
    }
    return 0;
}