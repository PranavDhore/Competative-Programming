#include<iostream>
using namespace std;


int binarySearch(int arr[],int l,int h,int key){
	
	if(l>h)
		return -1;
		
	int mid = (l + h)/2;
	
	if(key == arr[mid]){
		return mid;
	}
	
	if(key>arr[mid]){
		return binarySearch(arr,mid+1,h,key);
	}
	
	return binarySearch(arr,l,mid-1,key);
	
}

int findPivot(int arr[],int low,int high){
	
	if(high<low)
		return -1;
	if(low==high)
		return low;
		
	int mid = (low + high)/2;
	
	if(mid<high && arr[mid]>arr[mid+1]){
		return mid;
	}
	if(mid>low && arr[mid]<arr[mid-1]){
		return mid-1;
	}
	
	if(arr[low]>=arr[mid]){
		return findPivot(arr,low,mid-1);
	}
	
	return findPivot(arr,mid+1,high);
}

int binaryRotateSearch(int arr[],int n,int key){
	
	int pivot = findPivot(arr,0,n-1);
	
	if(pivot==-1){
		return binarySearch(arr,0,n-1,key);
	}
	
	if(arr[pivot] == key)
		return pivot;
	
	if(arr[0] <= key)
		return binarySearch(arr,0,pivot-1,key);
	
	return binarySearch(arr,pivot + 1,n-1,key);
	
	
	
}

int main(){
	
	int arr[100]={4,5,6,7,1,2,3},n=6,key=7;
	int findIndex;
	findIndex = binaryRotateSearch(arr,n,key);
	
	cout<<"Element Present at "<<findIndex<<" ";
	
}
