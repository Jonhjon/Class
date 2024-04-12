#include<iostream>
using namespace std;
typedef struct Node {
    string data;
    struct Node* next = NULL;
} Node;
Node* push(Node* head, Node** end, string data) {
    Node* New_Node = new Node();
    New_Node->data = data;
    New_Node->next = NULL;
    if (head == NULL)//判斷開頭有沒有node，
    {
        (*end) = New_Node;//頭尾儲存新的
        head = New_Node;
    }
    else//否則就加在尾
    {
        (*end)->next = New_Node;
        (*end) = New_Node;
    }
    return head;
}
void POP(Node** head) {
    Node* temp = *head;
    cout << "POP : "<<temp->data<<endl;
    (*head) = (*head)->next;
    free(temp);
}
void Print_list(Node* ptr) {
    while (ptr != NULL) {
        cout << ptr->data << " -> ";
        ptr = ptr->next;
    }
}void Free(Node* current) {
    Node* temp;
    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }
}
int main() {
    int choice = 0, stack = 0;
    string str = "";
    Node* head = NULL;
    Node* end = NULL;

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
            head = push(head, &end, str);
            stack++;
            break;
        case 2://pop
            if (stack == 0)
            {
                cout << "Stack is Empty!!!!\n";
                break;
            }
            POP(&head);
            stack--;
            break;
        case -1:
            if (head!=NULL)
            {
                Free(head);
                if (head!=NULL)
                {
                    cout << "刪除完了!!!\n";
                }
                else {
                    cout << "梅山除乾淨!!\n";
                }
            }
            return 0;
            break;
        default:
            cout << "輸入錯誤~!!!!\n";
            break;
        }
        Print_list(head);
        cout << "\nstack(" << stack << "/5)\n";
    }
    
}