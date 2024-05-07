#include<iostream>
using namespace std;
class Node
{
    public:
    int status,stime,min,max;
    Node *next;
};
class Appointment
{
    public:
    Node *head, *tail, *temp;
    Appointment()
    {
        head=tail=NULL;
    }
    void create();
    void free_slots();
    void book();
    void cancel();
};
int main()
{
    Appointment patient;
    patient.create();
    int chc,flag=1;
    while(flag)
    {
        cout<<"Enter: \n1. Check Free slots\n2. Book a slot\n3. Cancel a booking:  ";
        cin>>chc;
        switch (chc)
        {
        case 1:
            patient.free_slots();
            break;
        case 2:
            patient.book();
            break;
        case 3:
            patient.cancel();
            break;
        default:
            cout<<"Enter valid input"<<endl;
        }
        cout<<"\nDo you want to perform any other operation? (1/0): ";
        cin>>flag;
    }
    return 0;
}
void Appointment::create()
{
    temp=new Node;
    temp->stime=9;
    head=tail=temp;
    int counter=10;
    for(int i=2;i<=8;i++)
    {
        Node *t=new Node;
        t->status=0;
        t->stime=counter++;
        tail->next=t;
        tail=t;
    }

}
void Appointment::free_slots()
{
    temp=head;
    while(temp!=NULL)
    {
        if (temp->status==0)
        {
            cout<<"Slot at "<<temp->stime<<" is empty"<<endl;
        }
        temp=temp->next;
    }
}
void Appointment::book()
{
    int time;
    cout<<"\nEnter the time which you want to book (9-17): ";
    cin>>time;
    if (time>=9 && time<17)
    {
        temp=head;
        while (temp->stime!=time)
        {
            temp=temp->next;
        }
        temp->status=1;
        cout<<"\nEnter the minimum time: ";
        cin>>temp->min;
        cout<<"\n Enter the maximum time: ";
        cin>>temp->max;
        cout<<"\nTime slot of "<<temp->stime<<" has been booked"<<endl;
    }
}
void Appointment::cancel()
{
    int time;
    cout<<"\nEnter the time which you want to cancel (9-17): ";
    cin>>time;
    temp=head;
    while (temp->stime!=time)
    {
        temp=temp->next;
    }
    temp->status=0;
    cout<<"\nTime slot of "<<temp->stime<<" has been cancelled"<<endl;
}
