#include <iostream>
#include <conio.h>
using namespace std;

bool issorted(int Arr[],int size)
{
    for (int i = 0; i < size-1; i++)
    {
       if (Arr[i]>Arr[i+1])
       {
        return false;
        
    }
       }
        return true;
}


void autocheck(int Arr[],int size)
{
    if (issorted(Arr,size))
    {
        cout<<"Your Arrray is Sorted in the Ascending order";
    }else
    {
        cout<<"Your Arrray is not sorted in the Ascending order";
    }
}

void Bubblesort(int size,int arr[])
{
    if (issorted(arr,size))
    {
       cout<<"Your Arrray is Already sorted in the Ascending order";
       
    }else{

    
   
    
for (int j = 0; j < size-1; j++)
{
    for(int i=0;i<size-j;i++)
	{
		if(arr[i]>arr[i+1])
		{
			int temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1]= temp;
		}
	}
	

}
    
cout<<"Sorted Array";
for (int h = 0; h<size; h++)
{
   cout<<arr[h]<<" ";
}
autocheck(arr,size);
    }

}

int main(){
    
    int size;
    cout<<"Enter the size of the Array"<<"  :";
    cin>>size;
    int array[size];

    for(int i=0;i<size;i++)
    {
        cout<<"Enter the "<<i<<" "<<"Element of the Array"<<" :";
        cin>>array[i];
    }
        Bubblesort(size,array);
        
    return 0;
}