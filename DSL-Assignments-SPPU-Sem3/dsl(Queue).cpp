#include<iostream>
using namespace std;
int q[100],n=100,f=-1,r=-1;
void Insert()
{
    int val;
    if (r==n-1)
    {
        cout<<"Queue Overflow"<<endl;
    }
    else
    {
        if (f==-1)
        f=0;
        cout<<" Enter the element you want to Insert in queue : "<<endl;
        cin>>val;
        r++;
        q[r]=val;
    }
}
void Delete()
{
    if(f==-1 || f>r)
    {
        cout<<"Queue Underflow "<<endl;
    }
    else
    {
        cout<<"Element deleted from queue is : "<< q[f] <<endl;
        f++;
    }
}
void Display()
{
    if(f==-1)
    {
        cout<<"Queue Underflow "<<endl; 
    }
    else
    {
        cout<<"Queue Elements are :-> ";
        for (int i=f;i<=r;i++)
        {
            cout<<q[i]<<" ";
        }
        cout<<"\n";
    }
}
int main()
{
    int ch,flag=1;
    while(flag)
   {
    cout<<"1) Insert element to queue"<<endl;
    cout<<"2) Delete element from queue"<<endl;
    cout<<"3) Display all the elements of queue"<<endl;
    cout<<"Enter your choice : "<<endl;
    cin>>ch;
    switch (ch)
    {
        case 1: 
            Insert();
            break;
        case 2: 
            Delete();
            break;
        case 3: 
            Display();
            break;
        default:
            cout<<"Invalid choice"<<endl;
    }
        cout<<"\nDo you want to perform any other operation? (1 for yes/0 for no): "<<endl;
       
        cin>>flag;
   }
   return 0;
}