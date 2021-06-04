#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int> &hT, int i) {
  int size = hT.size();
  int largest = i;
  int l = 2 * i + 1;
  int r = 2 * i + 2;
  if (l < size && hT[l] > hT[largest])
    largest = l;
  if (r < size && hT[r] > hT[largest])
    largest = r;

  if (largest != i) {
    swap(&hT[i], &hT[largest]);
    heapify(hT, largest);
  }
}

void insert(vector<int> &hT, int newNum) {
  int size = hT.size();
  if (size == 0) {
    hT.push_back(newNum);
  } else {
    hT.push_back(newNum);
    for (int i = size / 2 - 1; i >= 0; i--) {
      heapify(hT, i);
    }
  }
}

void deleteNode(vector<int> &hT, int num) {
  int size = hT.size();
  int i;
  for (i = 0; i < size; i++) {
    if (num == hT[i])
      break;
  }
  swap(&hT[i], &hT[size - 1]);

  hT.pop_back();
  for (int i = size / 2 - 1; i >= 0; i--) {
    heapify(hT, i);
  }
}
bool isEmpty(vector<int> &hT){
	if(hT.size()==0){
		return true;
	}else{
		return false;
	}
}
int removeMax(vector<int> &hT){
	deleteNode(hT,hT[0]);
}
int removeMin(vector<int> &hT){
	int mn=*min_element(hT.begin(),hT.end());
	deleteNode(hT,mn);
	return mn;
}
int getMin(vector<int> &hT){
	int mn=*min_element(hT.begin(),hT.end());
	return mn;
}
int getMax(vector<int> &hT){
	if(hT.size()==0){
		return -1;
	}
	int mx=hT[0];
	return mx;
}
