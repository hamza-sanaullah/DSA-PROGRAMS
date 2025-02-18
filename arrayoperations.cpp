#include <iostream>

using namespace std;
int main()
{
    int capacity,size,opt,index,number,del,UPD,UpNUMBER;
    // Getting the Capacity of the Array
cout<<"Enter the Capacity of the Array"<<" :";
cin>>capacity;
int Array[capacity];
// Getting the size of the aray
cout<<"How many Elements you want to Add in Array";
cin>>size;
if (size<capacity)
{
    // Inserting the Elements into the array According to the size specified by the user;
   for(int i=0;i<size;i++)
    {
        cout<<"Enter the "<<i<<" "<<"Element of the Array"<<" :";
        cin>>Array[i];
    }
}else{
    cout<<"The Size is Greater than Capacity of the Array";
}
// Printing the Elements of the Array
for (int h = 0; h<size; h++)
{
   cout<<Array[h]<<" "<<endl;
}
cout<<"You Can Perform a Following Operations on the Array\n"<<"1.Traversal\n"<<"2.Insertion\n"<<"3.Deletion\n"<<"4.Updation\n";
cin>>opt;
if (opt==1)
{
    for (int h = 0; h<size; h++)
{
   cout<<Array[h]<<" ";
}
}else if (opt==2)
{
    cout<<"The Total capacity of the Array is"<<" "<< capacity<<endl;
    cout<<"Enter the Index of the Array You want Where you want to insert the Element"<<endl;
    cin>>index;
    cout<<"Enter the Number You Want to insert\n";
    cin>>number;
    if (index>=0 && index<=size)
    {
        for (int i =size; i >index; i--){
            Array[i] = Array[i-1];
            
           }
       Array[index] = number;
       size++;
    }else if (index>size && index<=capacity)
    {
        Array[index] = number;
        size++;
    }else{
        cout<<"There is no spcae in the Array to insert Elements";
    }
    for (int h = 0; h<size; h++)
{
   cout<<Array[h]<<" ";
}
}else if (opt==3)
{
   cout<<"Enter the index of the Element Where you want to delete the Element\n";
   cin>>del;
   if (del>=0 && del<=size)
   {
        for (int  i = del; i < size; i++)
        {
        Array[i] = Array[i+1];
        }
    size--;
    }
     cout<<"Your Updated Array is\n";
    for (int h = 0; h<size; h++)
        {
           
        cout<<Array[h]<<" ";
        }
   
}else if (opt==4)
{
    cout<<"Enter the Index of the Element You want to Update\n";
    cin>>UPD;
    cout<<"Enter the Updated Number\n";
    cin>>UpNUMBER;
    Array[UPD] = UpNUMBER;
    for (int h = 0; h<size; h++)
    {
    cout<<Array[h]<<" ";
    }
}





return 0;
}