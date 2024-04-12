#include<iostream>
using namespace std;
typedef struct Node {
    string data;
    struct Node* next = NULL;
} Node;
Node* push(Node* head,string data) {
    Node* New_Node = new Node();
    New_Node->data = data;
    New_Node->next = head;
    //head = New_Node;
    return New_Node;
}
Node* POP(Node* head) {
    Node* temp = head;
    head = head->next;
    cout << "POP : " << temp->data<<endl;
    free(temp);
    return head;
}
void Print_list(Node* ptr) {
    if (ptr == NULL)
        return;
    cout << ptr->data;
    ptr = ptr->next;
    while (ptr != NULL) {
        cout << " -> " << ptr->data ;
        ptr = ptr->next;
    }
}
int main() {
    int choice = 0, stack = 0;
    string str = "";
    Node* ptr=NULL;

    while (choice != -1)
    {
        cout << "(1)PUSH (2)POP (-1)離開 : ";
        cin >> choice;
        switch (choice) {
        case 1://push
            if (stack == 5)
            {
                cout << "Stack is full\n";
                break;
            }
            cout << "PUSH :";
            cin >> str;
            ptr = push(ptr,str);
            stack++;
            break;
        case 2://pop
            if (stack == 0)
            {
                cout << "Stack is Empty!!!!\n";
                break;
            }
            ptr = POP(ptr);
            stack--;
            break;
        case -1:
            break;
        default:
            cout << "輸入錯誤!!!!\n";
            break;
        }
        Print_list(ptr);
        cout << "\n目前stack(" << stack << "/5)\n";
    }
    return 0;
}
