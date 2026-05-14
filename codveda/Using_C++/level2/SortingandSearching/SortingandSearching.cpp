#include<iostream>
using namespace std;
void swap(int &a,int &b)
{
	int temp=a;
	a=b;
	b=temp;
}

void bubbleSort(int arr[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				swap(arr[j],arr[j+1]);
			}
		}
	}
}

void binarySearch(int arr[],int left,int right,int key)
{
	while(left<=right)
	{
		int mid=left+(right-left)/2;
		if(arr[mid]==key)
		{
			cout<<"Element found at index: "<<mid;
			return;
		}
		else if(arr[mid]<key)
			left=mid+1;
		else
			right=mid-1;
	}
	cout<<"Element not found in the array.\n";
}

int main()
{
	int arr[100];
	int n;
	cout<<"Enter the number of elements: ";
	cin>>n;
	cout<<"Enter the elements: ";
	for(int i=0;i<n;i++)
		cin>>arr[i];
	// Sorting the array using bubble sort
	bubbleSort(arr, n);
	cout << "\nArray sorted using Bubble Sort." << endl;
	cout << "time complexity: O(n^2)" << endl;
	cout<<"Sorted array: ";
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	// Searching for an element using binary search
	int key;
	cout << "\n\nEnter the element to search: ";
	cin >> key;
	int left = 0, right = n - 1, mid;
	bool found = false;
	cout << "Performing Binary Search." << endl;
	cout << "time complexity: O(log n)" << endl;
	binarySearch(arr, left, right, key);

	
	return 0;
}