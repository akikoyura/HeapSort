#include<iostream>
using namespace std;

void Swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
void print(int array[], int n)
{
	cout << " n = " << n << "\n";
	for( int i = 0; i < n; i++ )
	{
		cout << array[i] << " ";
	}
}
void heapify(int array[], int n, int i)
{
	int max = i;
	int left = ((2 * i) + 1);
	int right = ((2 * i) + 2);
	if( (left < n) && (array[left]>array[max]) )
	{
		max = left;
	}
	if( (right < n) && (array[right] > array[max]) )
	{
		max = right;
	}
	if(max!=i)
	{
		//Do not create your own swap because it do not work
		/*int temp = array[max];
		array[max] = array[i];
		array[i] = temp;*/
		Swap(array[i], array[max]);
		heapify(array, n, max);
	}
}

void HeapSort(int array[],int n)
{
	for( int i = n / 2 -1; i >= 0; i-- )
	{
		heapify(array, n, i);
	}
	for( int i = (n - 1); i >= 0; i-- )
	{/*
		int temp = array[i];
		array[i] = array[0];
		array[0] = temp;*/
		Swap(array[0], array[i]);
		heapify(array, i, 0);
	}
}


int main()
{
	int array[] = { 3,2,1,4,5};
	int n = 5;
	HeapSort(array,n);

	for( int i = 0; i < n; i++ )
	{
		cout << array[i] << "\n";
	}

	system("pause");
	return 0;
}