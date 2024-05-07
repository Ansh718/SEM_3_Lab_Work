#include<iostream>
#include<string>
using namespace std;
class DeQue
{
    public:
        int dq[10],f,r;
        DeQue()
        {
            f=-1;
            r=-1;
        }
        void Enqueue_front(int x)
        {
            if(((f==0) && (r==9))||(f==r+1))
            {
                cout<<"Queue is Full"<<endl;
            }
            else if(f==-1 && r==-1)
            {
                f=r=0;
                dq[f]=x;
            }
            else if(f==0)
            {
                f=9;
                dq[f]=x;
            }
            else
            {
                f--;
                dq[f]=x;
            }
        }
        void Enqueue_rear(int x)
        {
            if(((f==0) && (r==9))||(f==r+1))
            {
                cout<<"Queue is Full"<<endl;
            }
            else if(f==-1 && r==-1)
            {
                f=r=0;
                dq[r]=x;
            }
            else if(r==9)
            {
                r=0;
                dq[r]=x;
            }
            else
            {
                r++;
                dq[r]=x;
            }
        }
        void display()
        {
            int i=f;
            while(i!=r)
            {
                cout<<dq[i]<<" "<<endl;
                i=(i+1)%10;
            }
            cout<<dq[r]<<endl;
        }
        void Dequeue_front()
        {
            if (f==-1 && r==-1)
            {
                cout<<"Queue is Empty"<<endl;
            }
            else if (f==r)
            {
                f=r=-1;
            }
            else if(f==9)
            {
                cout<<"Dequeued Element is: "<<dq[f]<<endl;
                f=0;
            }
            else
            {
                cout<<"Dequeued Element is: "<<dq[f]<<endl;
                f++;
            }
        }
        void Dequeue_rear()
        {
            if (f==-1 && r==-1)
            {
                cout<<"Queue is Empty"<<endl;
            }
            else if(f==r)
            {
                f=r=-1;
            }
            else if(r==0)
            {
                cout<<"Dequeued Element is: "<<dq[r]<<endl;
                r=9;
            }
            else
            {
                cout<<"Dequeued Element is: "<<dq[r]<<endl;
                r--;
            }
        }
};
int main()
{
    DeQue dq1;
    dq1.Enqueue_front(1);
    dq1.Enqueue_rear(10);
    dq1.Enqueue_front(2);
    dq1.Enqueue_rear(9);
    dq1.Enqueue_front(3);
    dq1.Enqueue_front(4);
    cout<<endl;
    dq1.display();
    cout<<endl;
    dq1.Dequeue_front();
    cout<<endl;
    dq1.display();
    cout<<endl;
    dq1.Dequeue_rear();
    cout<<endl;
    dq1.display();
    cout<<endl;
    dq1.Dequeue_front();
    cout<<endl;
    dq1.display();
    cout<<endl;
    dq1.Dequeue_rear();
    dq1.display();
    cout<<endl;
    return 0;

}