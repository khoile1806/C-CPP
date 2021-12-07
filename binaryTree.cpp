#include "iostream"
using namespace std;

struct Node{
	int key;
	Node* left;
	Node* right;
};

// hàm tạo node
void CreateNode(Node* &p, int data)
{
	p = new Node;
	p->key = data;
	p->left = NULL;
	p->right = NULL;
}

// thêm 1 node vào cây
void AddNode(Node* p, int data)
{
	Node* preNode;
	while(p!= NULL)
	{
		preNode = p;
		if(p->key < data)
			p = p->right;
		else
			p = p->left;
	}
	Node* temp;
	CreateNode(temp,data);
	if(preNode->key > data)
		preNode->left = temp;
	else
		preNode->right = temp;
}

void Visit(Node* p)
{
	cout<<p->key;
}

// hàm duyệt giũa
void inOrder(Node* A)
{
	if(A!=NULL)
	{
		inOrder(A->left);
		Visit(A);
		inOrder(A->right);
	}
}


// hàm duyệt trước 
void preOrder(Node* A)
{
	if(A!=NULL)
	{
		Visit(A);
		preOrder(A->left);
		preOrder(A->right);
	}
}

//  hàm duyệt sau
void postOrder(Node* A)
{
	if(A!=NULL)
	{
		postOrder(A->left);
		postOrder(A->right);
		Visit(A);
	}
}
