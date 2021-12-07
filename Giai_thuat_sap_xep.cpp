#include <iostream>

using namespace std;
void insertion(int a[], int size_arr);
void hoanvi(int &a, int&b);
void xuatmang(int a[], int n);
void dichphai(int a[],int i,int j);
void quickSort(int a[],int left, int right);
void mergeSort(int a[], int left, int right);
void merge(int a[],int left, int mid, int right);
void merge2(int a[],int left, int mid, int right);
void heapModify(int a[], int n);
void heap_sort(int a[], int n);
void bubbleSort(int a[], int n);
int main(){
	int arr[] = {7,9,11,10,15,5,2,1,4,6,3};
	int size_arr = sizeof(arr)/sizeof(arr[0]);
	mergeSort(arr,0,size_arr-1);
	xuatmang(arr,size_arr);
}
void insertion(int a[], int size_arr){
	for(int i=1;i<size_arr;i++){
		int j;
		for(j=i-1;j>=0;j--)
			if(a[j]<a[i])
				break;
		int temp = a[i];
		dichphai(a,i,j);
		a[j+1] = temp;
	}
}
void dichphai(int a[],int i, int j){
	for(int k=i;k>j;k--)
		a[k] = a[k-1];
}
void hoanvi(int &a, int&b){
	int temp = a;
	a = b;
	b = temp;
}
void xuatmang(int a[], int n){
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
}
void quickSort(int a[],int left, int right){

	int mid = (left+right)/2;
	int i = left;
	int j = right;
	while(i < j){
		while(a[i]<a[mid])
			i++;
		while(a[j]>a[mid])
			j--;
		if(i<=j){
			hoanvi(a[i],a[j]);
			i++;
			j--;
		}	
	}
	if(i<right)
		quickSort(a,i,right);
	if(j>left)
		quickSort(a,left,j);
}
void mergeSort(int a[], int left, int right){
	if(left<right){
		int mid = (left+right)/2;
		mergeSort(a,left,mid);
		mergeSort(a,mid+1,right);
		merge(a,left,mid,right);
	}
}

void merge(int a[],int left, int mid, int right){
	//khai bao mang tam co kich thuoc = right -left + 1 phan tu
	int *temp;
	temp = new int[right-left+1];
	
	//gan gia tri can trai cho 2 mang tam
	int n = 0, i = left, j = mid+1;
	
	while(n!=right-left+1){
		if(i>mid){
			temp[n] = a[j];
			j++;
			n++;
		}
		else if(j>right){
			temp[n] = a[i];
			i++;
			n++;
		}
		else{
			if(a[i]<a[j]){
				temp[n] = a[i];
				i++;
				n++;
			}
			else{
				temp[n] = a[j];
				j++;
				n++;
			}
		}
	}
	for(int i=0;i<n;i++)
		a[left+i] = temp[i];
}

void merge2(int a[],int left, int mid, int right){

}
void heapModify(int a[], int n){	
	for(int i=n/2 - 1;i>=0;i--){
		int largest = i;
		int left = 2*i+1;
		int right = 2*i+2;
		if(left < n && a[left]>a[largest])
			largest = left;
		if(right < n && a[right]>a[largest])
			largest = right;
		if(largest!=i)
			hoanvi(a[largest],a[i]);
	}
}

void heap_sort(int a[], int n){
	for(int i=n-1;i>0;i--){
		heapModify(a,i);
		xuatmang(a,n);
		cout<<endl;
		hoanvi(a[0],a[i]);
	}
}

void bubbleSort(int a[], int n){
	for(int i=n-1;i>=0;i--){
		for(int j=0;j<=i-1;j++)
			if(a[j]>a[j+1])
				hoanvi(a[j],a[j+1]);
	}
}
