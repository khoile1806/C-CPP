#include "iostream"
using namespace std;
struct Node{
	int Key;
	Node* Next;
};
Node* createNode(Node* p, int data){
	p = new Node;
	p->Key = data;
	p->Next = NULL;
	return p;
}
void addHead(Node* &pHead, int data)
{
	Node *pNode = new Node;
	pNode = createNode(pNode,data);
	if(pHead == NULL)
		pHead = pNode;
	else{
		pNode->Next = pHead;
		pHead = pNode;
	}
}
void getList(Node *pHead)
{
	while(pHead!=NULL)
	{
		cout<<pHead->Key<<" ";
		pHead = pHead->Next;
	}
}
int main(){
	Node *list = NULL;
	addHead(list,1);
	addHead(list,2);
	addHead(list,3);
	addHead(list,4);
	getList(list);
	return 0;	
}