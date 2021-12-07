#include <iostream>
using namespace std;

struct phanSo
{
	int tuSo;
	int mauSo;
};

void nhapPS(phanSo &ps);
void xuatPS(phanSo ps);
void bubbleSort(phanSo ps[], int n);
void swapPS(phanSo &psA,phanSo &psB);
int comparePS(phanSo psA,phanSo psB);

int main()
{
	phanSo ps[3];
	for(int i=0;i<3;i++)
	{
		nhapPS(ps[i]);
	}
	bubbleSort(ps,3);
	for(int i=0;i<3;i++)
	{
		xuatPS(ps[i]);
	}
	return 0;
}
void nhapPS(phanSo &ps)
{
	cout<<"tu so:";
	cin>>ps.tuSo;
	cout<<endl; 
	cout<<"mau so:";
	cin>>ps.mauSo;
	cout<<endl;
}
void xuatPS(phanSo ps)
{
	cout<<ps.tuSo<<"/"<<ps.mauSo<< " ";
}

void swapPS(phanSo &psA,phanSo &psB)
{
	phanSo temp;
	temp = psA;
	psA = psB;
	psB = temp;
}
void bubbleSort(phanSo ps[], int n)
{
	for(int i=n-1;i>=0;i--)
	{
		for(int j=0;j<=i-1;j++)
			if(comparePS(ps[i],ps[j]))
				swapPS(ps[i],ps[j]);
	}
}

int comparePS(phanSo psA,phanSo psB)
{
	int result = psA.tuSo*psB.mauSo > psA.mauSo*psB.tuSo;
	if(result > 0)
		return 1;
	else if (result = 0)
		return 0;
	else
		return -1;
}