#include<iostream>
#include<fstream>
#include<string>

using namespace std;
typedef struct node {
	int num;
	int pow;
	string sym;
	struct node* Next;
}node;
node* Add(node* ptr, int num, int pow,string sym) {
	node* Add = new node();
	node* temp = ptr;
	if (sym =="-")
	{
		num *=-1;
	}
	Add->num = num;
	Add->pow = pow;
	Add->sym = sym;
	if (temp == NULL)
	{
		ptr = Add;
		return ptr;
	}
	while (temp->Next != NULL)
	{
		if (temp->Next->pow < Add->pow) {
			Add->Next = temp->Next;
			temp->Next = Add;
			return ptr;
		}
		temp = temp->Next;
	}
	temp->Next = Add;
	return ptr;
}
void Free(node* cur) {
	node* temp;
	while (cur != NULL)
	{
		temp = cur;
		cur = cur->Next;
		free(temp);
	}
}
void Print_List(node* current) {
	cout << " " << current->num << "x^" << current->pow;
	current = current->Next;
	while (current != NULL)
	{
		if (current->pow == 0)
		{
			cout << " + " << current->num << " ";
		}
		else {
			cout << " " << current->sym << abs(current->num) << "x^" << current->pow;
		}
		current = current->Next;
	}
}
node* readfile(node* ptr,string str) {
	//ifstream file;
	int num = 0, pow = 0;
	string sym=" ";
	//getline(file, str);
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i]=='+'||str[i]=='-')
		{
			sym = str[i];
		}
		else if (isdigit(str[i]) && isdigit(str[i + 1]))
		{
			num = (str[i] - '0') * 10 + str[i + 1] - '0';
			//check2 = 1;
			i++;
			/*pre = str[i];
			check = 1;*/
		}
		else if (isdigit(str[i]))
		{
			num = str[i] - '0';
			//check2 = 1;
			/*temp = str[i];
			check++;*/
		}
		else if (str[i] == 'x' && str[i + 1] == '^')
		{
			if (isdigit(str[i + 2]) && isdigit(str[i + 3]))
			{
				pow = (str[i + 2] - '0') * 10 + str[i + +3] - '0';
				//check2 = 1;
				i+=3;
				/*pre = str[i];
				check = 1;*/
			}
			else if (isdigit(str[i + 2]))
			{
				pow = str[i + 2] - '0';
				i+=2;
				//check2 = 1;
				/*temp = str[i];
				check++;*/
			}
			/*if (check == 2)
			{
				num = stoi(pre) * 10 + stoi(temp);
				sym = " ";
			}
			else 	num = stoi(pre);
			check = 0;*/
		}
		else if (str[i] == ' ' && (str[i + 1] == '+' || str[i + 1] == '-'))
		{
			/*if (check == 2)
			{
				pow = stoi(pre) * 10 + stoi(temp);
			}
			else {
				pow = stoi(pre);
			}*/
			//check = 0;
			ptr = Add(ptr, num, pow, sym);
			num = 0;
			pow = 0;
		}
	}
	ptr = Add(ptr, num, pow, sym);
	return ptr;
}
node* Insert(node* A, node* B) {
	node* result = NULL;
	node* cur_A = A;
	node* cur_b = B;
	while (cur_A!=NULL&&cur_b!=NULL)
	{
		if (cur_A->pow > cur_b->pow)
		{
			result = Add(result, cur_A->num, cur_A->pow, cur_A->sym);
			cur_A = cur_A->Next;
		}
		else if (cur_A->pow < cur_b->pow) {
			result = Add(result, cur_b->num, cur_b->pow, cur_b->sym);
			cur_b = cur_b->Next;
		}
		else
		{
			int sum = cur_A->num + cur_b->num;
			if (sum!=0)
			{
				result = Add(result, sum, cur_A->pow, sum < 0 ? "-" : "+");
			}
			cur_A = cur_A->Next;
			cur_b = cur_b->Next;
		}
	}
	while (cur_A!=NULL)
	{
		result = Add(result, cur_A->num, cur_A->pow, cur_A->sym);
		cur_A = cur_A->Next;
	}
	while (cur_b!=NULL)
	{
		result = Add(result, cur_b->num, cur_b->pow, cur_b->sym);
		cur_b = cur_b->Next;
	}
	return result;
}
node* multi(node* A, node* B) {
	node* result = NULL, * cur_A = A, * cur_B = B;
	while (cur_A!=NULL)
	{
		cur_B = B;
		while (cur_B != NULL) {
			result = Add(result, cur_A->num * cur_B->num, cur_A->pow + cur_B->pow, cur_A->num * cur_B->num < -1 ? "-" : "+");
			cur_B = cur_B->Next;
		}
		cur_A = cur_A->Next;
	}
	return result;
}
void len(node* ptr) {
	int count = 0;
	while (ptr!=NULL)
	{
		count++;
		ptr = ptr->Next;
	}
	cout << count;
}
node* Invert(node* ptr) {
	node* result = NULL;
	node* temp = NULL;
	while (ptr != NULL) {
		// 創建一個新節點
		temp = new node();
		if (temp == NULL) {
			printf("記憶體分配失敗\n");
			exit(1);
		}

		// 複製資料
		temp->num = ptr->num;
		temp->pow = ptr->pow;

		// 將新節點插入到反轉的鏈表中
		temp->Next = result;
		result = temp;

		// 移動到下一個節點
		ptr = ptr->Next;
	}
	return result;
}
void new_print(node* ptr) {
	cout << ptr->num << "," << ptr->pow; 
	ptr = ptr->Next;
	while (ptr!=NULL)
	{
		cout <<" -> " << ptr->num << "," << ptr->pow;
		ptr = ptr->Next;
	}
}
int main() {
	node* head_A = NULL;
	node* head_b = NULL;
	node* head_add = NULL;
	node* head_mult = NULL;
	node* Invert_add = NULL;
	int num = 0, pow = 0;
	string str;
	ifstream file;
	file.open("1.txt");
	if (!file.is_open())
	{
		cout << "�ɮ׶}�ҿ��~!\n"; return 0;
	}

	getline(file, str);
	head_A = readfile(head_A,str);
	cout << "a =";
	Print_List(head_A);



	getline(file, str);
	head_b = readfile(head_b,str);
	cout << "\nb =";
	Print_List(head_b);



	head_add = Insert(head_A, head_b);
	cout << "\n\n1) a + b =";
	Print_List(head_add);



	cout << "\n2) a * b =";
	head_mult = multi(head_A, head_b);
	Print_List(head_mult);



	cout << "\n3) a+b : length =";
	len(head_add);
	cout << "\n3) a*b : length =";
	len(head_mult);



	cout << "\n4) ";
	head_add = Invert(head_add);
	new_print(head_add);


	cout << endl;
	file.close();
	Free(head_A);
	Free(head_b);
	Free(head_add);
	Free(head_mult);
	return 0;
}
