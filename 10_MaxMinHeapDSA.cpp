// Read the marks obtained by 
// students of second year in an 
// online examination of particular 
// subject. Find out maximum and 
// minimum marks obtained in that 
// subject. Use heap data structure. 
// Analyze the algorithm.
// C++ program for implementation of Heap Sort
#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < n && arr[l] > arr[largest])
		largest = l;

	if (r < n && arr[r] > arr[largest])
		largest = r;

	if (largest != i) {
		swap(arr[i], arr[largest]);
		heapify(arr, n, largest);
	}
}

void heapSort(int arr[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	for (int i = n - 1; i > 0; i--) {
		swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
}

void printArray(int arr[], int n)
{
	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";
	cout << "\n";
}

int main()
{
   int n;
   cout<<"Enter no. of students : ";
   cin>>n;
	int arr[n];
   cout<<"Enter Marks of students : ";
   for (int i = 0; i < n; i++)
   {
      cin>>arr[i];
   }
	heapSort(arr, n);
   cout<<"Min marks is : "<<arr[0]<<endl;
   cout<<"Max marks is : "<<arr[n-1];
}
