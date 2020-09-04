#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	
	int* A=new int[n];
	
	for(int i=0; i<n; i++)
	{
		cin>>A[i];
	}
	
	for(int i=1; i<n; i++)
	{
		int key = A[i];
		int j = i-1;
		while(A[j]>key && j>=0)
		{
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = key;
	}
	
	cout<<"\n";
	
	for(int i=0; i<n; i++)
		cout<<A[i]<<" ";
}
