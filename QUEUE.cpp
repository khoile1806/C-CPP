#include <iostream>
using namespace std;
const int MAX = 5;
struct QUEUE
{
	int data[MAX];
	int size;
	int front;
	int rear;
	QUEUE()
	{
		size = 0;
		front = 0;
		rear = 0;
	}
	int enqueue(int value)
	{
		if(size == MAX)
			cout<<"Hang doi day";
		else
		{
			if(rear == 0 && front == 0 & size == 0) //xu ly hang doi ban dau
			{
				data[0]=value;
				size++;
				rear=0;
			}
			else if(rear == MAX-1)
			{
				data[0]=value;
				rear = 0;
				size = size + 1;
			}
			else
			{
				data[rear+1] = value;
				rear++;
				size++;
			}
		}
	}
	int dequeue()
	{
		if(size == 0)
			cout<<"Hang doi rong";
		else
		{
			cout<<data[front];
			front++;
			if(front>=MAX)
				front = 1;
			size--;
		}
	}
};

int main()
{
	QUEUE que;
	que.enqueue(1);
	que.enqueue(2);
	que.enqueue(3);
	que.enqueue(4);
	que.dequeue();
	que.dequeue();
	que.dequeue();
	return 0;
}