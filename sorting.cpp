#include <bits/stdc++.h>
using namespace std;
void swap(int *ap,int *bp){
	int temp= *ap;
	*ap=*bp;
	*bp=temp;
}

// Bubble Sort- Compare all the adjacent elements and swap
// In 1st pass, the largest element is moved at the end
// Avg & worst O(n*n) 
// Best O(n)
// Space O(1) 
void BubbleSort(vector<int> &a){
	int n=a.size();
	for(int i=0;i<n;i++){
		for(int j=1;j<=n-1-i;j++){
			if(a[j-1]>a[j]){
				swap(&a[j-1],&a[j]);
			}
		}
	}
}

// Selection Sort - Find the index of min element and swap with 0,1,2,...
// 1st pass, the min element is moved at the start
// Time O(n)
// Space O(1)
void SelectionSort(vector<int> &a){
	int n=a.size();
	for(int i=0;i<n;i++){
		int mni=i;
		for(int j=i+1;j<n;j++){
			if(a[j]<a[mni]){
				mni=j;
			}
		}
		swap(&a[i],&a[mni]);
	}
}

// Insert Sort - Card Sort, 
// Time - O(n)
// Space O(1)
void InsertionSort(vector<int> &a){
	int n=a.size();
	for(int i=1;i<n;i++){
		int key=a[i];
		int j=i-1;
		while(j>=0&&a[j]>key){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=key;
	}
}


// Merge Sort
// time (worst,avg,best)- O(nlogn)
// space O(n) for temp array
void Merge(vector<int> &a,int l,int m,int r){
	vector<int> left,right;
	for(int i=l;i<=m;i++){
		left.push_back(a[i]);
	}
	for(int i=m+1;i<=r;i++){
		right.push_back(a[i]);
	}
	int i=0;
	int j=0;
	int k=l;
	int n1=left.size(),n2=right.size();
	while(i<n1||j<n2){
		if(i<n1&&j<n2){
			if(left[i]<right[j]){
				a[k]=left[i];
				i++;
				k++;
			}else{
				a[k]=right[j];
				j++;
				k++;
			}
		}else if(i<n1){
			a[k]=left[i];
			i++;
			k++;
		}else{
			a[k]=right[j];
			j++;
			k++;
		}
	}
	return ;
}
void MergeSort(vector<int> &a,int l,int r)
{
	if(l>=r){
		return;
	}
	int mid=(l+r)/2;
	MergeSort(a,l,mid);
	MergeSort(a,mid+1,r);
	Merge(a,l,mid,r);
	return ;
}


// Quick Sort, select pivot, 
// x<pivot - pivot - x>pivot
// time O(nlogn)
// space O(1) in place
int partition(vector<int> &a, int l, int r)
{
	int pivot=a[r];
	int bef=l-1;
	for(int i=l;i<r;i++){
		if(a[i]<pivot){
			bef++;
			swap(&a[bef],&a[i]);
		}
	}
	swap(&a[bef+1],&a[r]);
	return bef+1;
}
void QuickSort(vector<int> &a,int l,int r)
{
	if(l>=r){
		return;
	}
	int pr=partition(a,l,r);
	QuickSort(a,l,pr-1);
	QuickSort(a,pr+1,r);
}

// Heap Sort
// time O(nlogn)
// for creating heap O(n)
void heapify(vector<int> &a, int n, int i)
{
    int largest = i; 
    int l =2*i+1; 
    int r =2*i+2;
    if (l < n && a[l] > a[largest])
        largest = l;
    if (r < n && a[r] > a[largest])
        largest = r;
    if (largest != i) {
        swap(&a[i], &a[largest]);
        heapify(a, n, largest);
    }
}

void HeapSort(vector<int> &a)
{
	int n=a.size();
    for (int i =n/2-1;i>=0;i--)
        heapify(a,n,i);
    for (int i=n-1;i>0;i--){
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}
int main(){
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	HeapSort(a);
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}
