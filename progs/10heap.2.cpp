#include<iostream>
using namespace std;
// min heap
void mininsert(int arr[],int i)
{
    int parent=(i-1)/2;
    int cur=i;
    while(parent>=0 && arr[parent]>arr[cur])
    {
        swap(arr[parent],arr[cur]);
        cur=parent;
        parent=(cur-1)/2;
    }
}
//max heap
void maxinsert(int arr[],int i)
{
    int parent=(i-1)/2;
    int cur=i;
    while(parent>=0 && arr[parent]<arr[cur])
    {
        swap(arr[parent],arr[cur]);
        cur=parent;
        parent=(cur-1)/2;
    }
}
int main()
{	
 	int arr[100],i,n;
  	cout<<"Enter the total number= ";
	cin>>n;
  	cout<<"Enter the numbers=";
	for(i=0;i<n;i++)
	{	
		cin>>arr[i];
	}
	cout<<"Entered numbers are:";
	for(i=0;i<n;i++)
	{	
		cout<<arr[i]<<" ";
	}
	cout<<endl;
  	for(int i=1;i<n;i++)
  	{
  		mininsert(arr,i);
  	}
  	cout<<"min value is:"<<arr[0]<<endl;  
  	for(int i=1;i<n;i++)
  	{
  	  maxinsert(arr,i);
  	}
  	cout<<"max value is:"<<arr[0]<<endl;
}
