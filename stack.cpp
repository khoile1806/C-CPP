#include <iostream>
using namespace std;
struct Stack{
	int data;
	Stack* next;
}*TOP = NULL;
int pop();
void push(int data){
	Stack *pStack = new Stack();
	pStack->data = data;
	pStack->next = TOP;
	TOP = pStack;
}
void getStack(){
	if(TOP==NULL)
		cout<<"Stack hien tai dang rong!";
	else
		if(TOP!=NULL)
	{
		cout<<"Cac gia tri con lai cua Stack: ";
		Stack *temp = TOP;
		while(temp!=NULL){
			cout<<temp->data<<" ";
			temp=temp->next;
		}
	}
	cout<<endl;
}
int main(){
	push(1);
	push(2);
	push(3);
	push(4);
	getStack();
	pop();
	getStack();
	pop();
	getStack();
	pop();
	pop();
	getStack();
	pop();
	push(5);
	getStack(); 
	return 0;	
}
int pop(){
	if(TOP == NULL)
		cout<<"Stack rong ";
	else
	{
		cout<<"Gia tri lay ra la: "<<TOP->data;
		Stack *a;
		a = TOP;
		TOP = TOP->next;
		a->next =NULL;
		delete a;
	}
	cout<<endl;
	 
}





