#include<iostream>
using namespace std;
class Node
{
    public:
    int status,seat;
    Node *prev,*next;
};
class CDLL
{
    public:
    Node *head,*tail,*temp;
    CDLL()
    {
        head=temp=NULL;
    }
    void Create();
    void Display();
    void Book();
    void Cancel();
    void Availability();
};
int main()
{
    CDLL cinema;
    cinema.Create();
    int chc,flag=1;
    while(flag)
    {
        cinema.Display();
        cout<<"\n*********************************************\n";
        cout<<" CINEMAX MOVIE THEATRE\n";
        cout<<"*********************************************\n";
        cout<<"\n Enter your choice :-> \n 1.Current Seat Status \n 2.Book a Seat \n 3.Cancel a Seat \n 4.Availability of a Particular Seat"<<endl;
        cin>>chc;
        switch (chc)
        {
        case 1:
            cinema.Display();
            break;
        case 2:
            cinema.Book();
            break;
        case 3:
            cinema.Cancel();
            break;
        case 4:
            cinema.Availability();
            break;
        default:
            cout<<"Enter Correct Choice"<<endl;
        }
        cout<<"Do you want to perform any other operation? (1/0) :-> "<<endl;
        cin>>flag;
    }
    return 0;
}
void CDLL::Create()
{
    temp=new Node;
    temp->status=0;
    temp->seat=1;
    head=tail=temp;
    for(int i=2;i<=70;i++)
    {
        Node *t;
        t=new Node();
        t->seat=i;
        t->status=0;
        tail->next=t;
        t->prev=tail;
        tail=t;
        tail->next=head;
        head->prev=tail;
    }
}
void CDLL::Book()
{
    int SeatNumber;
    cout<<"Which seat number you want to book?"<<endl;
    cin>>SeatNumber;
    if(SeatNumber>=1 && SeatNumber<=70)
    {
        temp=head;
        while(temp->seat!=SeatNumber)
        {
            temp=temp->next;
        }
        temp->status=1;
        cout<<"\n The Seat Number "<<SeatNumber<<" has been booked."<<endl;
        
    }
    else
    {
        cout<<"The Seat Number "<<SeatNumber<<" is out of range."<<endl;
    }
}
void CDLL::Cancel()
{
    int SeatNumber;
    cout<<"Which seat number you want to book?"<<endl;
    cin>>SeatNumber;
    if(SeatNumber>=1 && SeatNumber<=70)
    {
        temp=head;
        while(temp->seat!=SeatNumber)
        {
            temp=temp->next;
        }
        temp->status=0;
        cout<<"\n The Seat Number "<<SeatNumber<<" has been cancelled."<<endl;
        
    }
    else
    {
        cout<<"The Seat Number "<<SeatNumber<<" is out of range."<<endl;
    }
}
void CDLL::Availability()
{
    int SeatNumber;
    cout<<"Which seat number's availability are you concerned with?"<<endl;
    cin>>SeatNumber;
    if(SeatNumber>=1 && SeatNumber<=70)
    {
        temp=head;
        while(temp->seat!=SeatNumber)
        {
            temp=temp->next;
        }
        if(temp->status==0)
        {
            cout<<"The Seat Number "<<SeatNumber<<" is available to book."<<endl;
        }
        else
        {
            cout<<"The Seat Number "<<SeatNumber<<" is unavailable to book."<<endl;
        }
    }
    else
    {
        cout<<"The Seat Number "<<SeatNumber<<" is out of range."<<endl;
    }
}
void CDLL::Display()
{
    temp=head;
    int itr=1;
    cout<<"\n-------------------------------------------------------"<<endl;
    cout<<"Screen This Way"<<endl;
    cout<<"-------------------------------------------------------"<<endl;
    while(temp->next!=head)
    {
        if (temp->seat/10==0)
        {
            cout<<"S0"<<temp->seat;
        }
        else
        {
            cout<<"S"<<temp->seat;
        }
        if(temp->status==0)
        {
            cout<<"|___|";
        }
        else
        {
            cout<<"|_B_|";
        }
        if(itr%7==0)
        {
            cout<<endl;
        }
        temp=temp->next;
        itr++;
    }
    cout<<"S"<<temp->seat;
    if(temp->status==0)
    {
        cout<<"|___|";
    }
    else
    {
        cout<<"|_B_|";
    }
}
