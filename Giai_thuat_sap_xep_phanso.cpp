#include <iostream>
using namespace std;
struct PhanSo
{
		int tuso;
		int mauso;
};
void nhapPS(PhanSo &ps);
void xuatPS(PhanSo ps);
void swapPS(PhanSo &psA,PhanSo &psB);
int comparePS(PhanSo psA,PhanSo psB);
void sapxep_bubble(PhanSo ps[],int n);
void sapxep_selection(PhanSo ps[],int n);
void insertion(PhanSo ps[],int n);
void sapxep_interchange(PhanSo ps[],int n);
void quickSort(PhanSo ps[],int left,int right);
void mergeSort(PhanSo ps[], int left, int right);
void merge(PhanSo ps[],int left, int mid, int right);
int main(){
	int chose,n;
	PhanSo ps[100];
	cout<<"Nhap so luong phan tu trong mang phan so: ";
	cin>>n;
	for(int i=0;i<n;i++){
		nhapPS(ps[i]);
	}
	cout<<"chon phuong phap sap xep:"<<endl;
	cout<<"4.Insertion Sort"<<endl;
	cout<<"1.Selection Sort "<<endl;
	cout<<"5.Merge Sort "<<endl; 
	cout<<"2.Interchangge Sort "<<endl;
	cout<<"6.Quick Sort"<<endl;
	cout<<"3.Bubble Sort "<<endl;
	cin>>chose;
	cout<<"ket qua: ";
	switch(chose){
		case 1:sapxep_selection(ps,n);break;
		case 2:sapxep_interchange(ps,n);break;
		case 3:sapxep_bubble(ps,3);break;
		case 4:insertion(ps,n);break;
		case 5:mergeSort(ps,0,n-1);break;
		case 6:quickSort(ps,0,n-1);
	}
	for(int i=0;i<n;i++){
		xuatPS(ps[i]);
	}
	return 0;
}
void nhapPS(PhanSo &ps){
	cout<<"tu so:";
	cin>>ps.tuso;
	cout<<endl; 
	cout<<"mau so:";
	cin>>ps.mauso;
	cout<<endl;
}
void xuatPS(PhanSo ps){
	cout<<ps.tuso<<"/"<<ps.mauso<< " ";
}
void swapPS(PhanSo &psA,PhanSo &psB){
	PhanSo temp;
	temp = psA;
	psA = psB;
	psB = temp;
}
int comparePS(PhanSo psA,PhanSo psB){
	float resultA =  (float)psA.tuso/psA.mauso; 
	float resultB = (float)psB.tuso/psB.mauso;
	if(resultA>resultB)
		return 1;
	else if (resultA = resultB )
		return 0;
	else
		return -1;
}
void sapxep_bubble(PhanSo ps[],int n){
	for(int i=n-1;i>=0;i--){
		for(int j=0;j<i;j++)
			if(comparePS(ps[j],ps[i])==1)
				swapPS(ps[i],ps[j]);
	}
}
void sapxep_selection(PhanSo ps[],int n){
	int min,i,j;
	for(i=0;i<n;i++){
		min=i;
		for(j=i+1;j<n;j++){
			if(comparePS(ps[min],ps[j]))
				min=j;
		}
		swapPS(ps[i],ps[min]);
	}
}
void insertion(PhanSo ps[],int n){
	PhanSo temp;
	int i,j;
	for(i=1;i<n;i++){
		temp=ps[i];
		j=i-1;
		while(j>=0 && comparePS(ps[j],temp)==1 ){
			ps[j+1]=ps[j];
			j--;
		}
		ps[j+1]=temp;
	}
}
void sapxep_interchange(PhanSo ps[],int n){
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
		{
			if(comparePS(ps[i],ps[j])==1)
				swapPS(ps[i],ps[j]);
		}
}
void quickSort(PhanSo ps[],int left,int right){
	int mid=(left+right)/2;
	int i=left;
	int j=right;
	while(i<j){
		while(comparePS(ps[mid],ps[i])==1)
			i++;
		while(comparePS(ps[j],ps[mid])==1)
			j--;
		if(i<=j){
			swapPS(ps[i],ps[j]);
			i++;
			j--;
		}
	}
	if(i<right)
		quickSort(ps,i,right);
	if(j>left)
		quickSort(ps,left,j);
}
void mergeSort(PhanSo ps[], int left, int right){
	if(left<right){
		int mid = (left+right)/2;
		mergeSort(ps,left,mid);
		mergeSort(ps,mid+1,right);
		merge(ps,left,mid,right);
	}
}
void merge(PhanSo ps[],int left, int mid, int right){
	PhanSo *temp;
	temp = new PhanSo[right-left+1];
	int n = 0, i = left, j = mid+1;
	while(n!=right-left+1){
		if(i>mid){
			temp[n] = ps[j];
			j++;
			n++;
		}
		else if(j>right){
			temp[n] = ps[i];
			i++;
			n++;
		}
		else{
			if(comparePS(ps[j],ps[i])==1){
				temp[n] = ps[i];
				i++;
				n++;
			}
			else{
				temp[n] = ps[j];
				j++;
				n++;
			}
		}
	}
	for(int i=0;i<n;i++)
		ps[left+i] = temp[i];
}