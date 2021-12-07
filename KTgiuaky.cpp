	#include <iostream>
	using namespace std;


	struct Node{
		int value;
		Node* Next;
	};

	struct Stack
	{
		int value;
		Stack* next;
	}*TOP = NULL;

	struct PhanSo
	{
		int tuSo;
		int mauSo;
	};

	void addHead(Node* &pHead, int data);
	void getList(Node *pHead);
	void splitList(Node* &list,Node* &listA, Node* &listB);
	void sortList(Node *list);
	void push(int value);
	void Exchange(int soChuted);
	int pop();
	void getStack();
	int compare(PhanSo phanSoA, PhanSo PhanSoB);
	void print(PhanSo a[],int n);
	int binarySearch(PhanSo a[],int l, int r, PhanSo x);
	void pushPS(PhanSo *ps);

	Node* createNode(Node* p, int data){
		p = new Node;
		p->value = data;
		p->Next = NULL;
		return p;
	}

	void addHead(Node* &pHead, int data){
		Node *pNode = new Node;
		pNode = createNode(pNode,data);
		if(pHead == NULL)
			pHead = pNode;
		else{
			pNode->Next = pHead;
			pHead = pNode;
		}
	}

	void getList(Node *pHead){
		while(pHead!=NULL){
			cout<<pHead->value<<" ";
			pHead = pHead->Next;
		}
	}

	void splitList(Node* &list,Node* &listA, Node* &listB){
		while(list != NULL){
			int temp = list->value;
			if(temp % 2 == 0)
				addHead(listA, temp);
			else	
				addHead(listB, temp);
			list = list->Next;
		}
	}

	void sortList(Node *list){
		for(Node *i = list; i != NULL; i = i ->Next)
			for(Node *j = i -> Next; j != NULL; j = j->Next){
				if(i -> value > j ->value){
					int temp = i->value;
					i->value = j->value;
					j->value = temp;
				}
			}
	}

	void push(int value){
		Stack *pStack = new Stack();
		pStack -> value = value;
		pStack -> next = TOP;
		TOP = pStack;
	}

	void Exchange(int soChuted){
		while(soChuted != 0){
			int x = soChuted % 16;
			push(x);
			soChuted /= 16;
		}
	}

	int pop(){
		if(TOP == NULL)
			cout << "Stack empty khong the pop!!!";
		else{
			Stack *temp;
			temp = TOP;
			TOP = TOP->next;
			temp->next = NULL;
			return temp->value;
		}
		cout << endl;
		return 0;
	}

	void getStack(){
		while (TOP != NULL){
			int x = pop();
			if(x < 10)
				cout << x;
			else{
				if(x == 10)
					cout << "A";
				else if(x == 11)
					cout << "B";
				else if(x == 12)
					cout << "C";
				else if(x == 13)
					cout << "D";
				else if(x == 14)
					cout << "E";
				else if(x == 15)
					cout << "F";
			}
		}
		
	}

	int compare(PhanSo phanSoA, PhanSo PhanSoB){
		float psA = (float)phanSoA.tuSo/phanSoA.mauSo;
		float psB = (float)PhanSoB.tuSo/PhanSoB.mauSo;
		if(psA > psB)
			return 1;
		else if(psA == psB)
			return 0;
		else
			return -1;
	}

	void print(PhanSo a[],int n){
		for(int i = 0; i < n; i++)
			cout << a[i].tuSo << "/" << a[i].mauSo << endl;
	}

	int binarySearch(PhanSo a[],int l, int r, PhanSo x){	
		if (r >= l){
			int mid = l + (r - l) / 2;
			if (compare(a[mid],x) == 0)
				return mid + 1;
			if (compare(a[mid],x) == 1)
				return binarySearch(a, l, mid - 1, x);
			return binarySearch(a, mid + 1, r, x);
		}
		return -1;
	}

	void pushPS(PhanSo *ps){
		ps[0].tuSo =  1;
		ps[0].mauSo = 2;
		ps[1].tuSo = 1;
		ps[1].mauSo = 3;
		ps[2].tuSo = 1;
		ps[2].mauSo = 4;
		ps[3].tuSo = 1;
		ps[3].mauSo = 5;
		ps[4].tuSo = 1;
		ps[4].mauSo = 6;
		ps[5].tuSo = 1;
		ps[5].mauSo = 7;
	}

	int main(){
		PhanSo ps[5];
		PhanSo x;
		x.tuSo = 2;
		x.mauSo = 5;
		pushPS(ps);
		print(ps,6);
		int index = binarySearch(ps,0,5,x);
		if(index == -1)
			cout << "Khong tim thay" << endl;
		else
			cout << "Tim thay x = " << x.tuSo << "/" << x.mauSo << " tai vi tri thu " << index << endl;

		cout << "-------------------------" << endl;
		Exchange(1350);
		getStack();
		cout << endl;
		cout << "-------------------------" << endl;

		Node *list = NULL;
		Node *listA = NULL;
		Node *listB = NULL;
		addHead(list,8);
		addHead(list,2);
		addHead(list,7);
		addHead(list,3);
		addHead(list,1);
		addHead(list,6);
		addHead(list,4);
		addHead(list,11);
		addHead(list,22);
		getList(list);
		cout << endl;
		splitList(list,listA,listB);
		sortList(listA);
		sortList(listB);
		getList(listA);
		cout << endl;
		getList(listB);
		cout << endl ;

		return 0;
	}
