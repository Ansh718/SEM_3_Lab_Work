#include<iostream>
using namespace std;
class Node
{
    public:
        Node *prev,*next;
        bool n;
        friend class Binary;
    Node(){}
    Node(bool n)
    {
        this->n=n;
        prev=next=NULL;
    }
};
class Binary
{
    public:
        Node *start;
    Binary()
    {
        start=NULL;
    }
    void generate(int num);
    void DisplayBinary();
    void OnesComplement();
    void TwosComplement();
    Binary operator+ (Binary num1);
    bool insert(bool val)
    {
        Node *temp=new Node(val);
        if(start==NULL)
        {
            start=temp;
        }
        else
        {
            temp->next=start;
            start->prev=temp;
            start=temp;
        }
        return true;
    }
};
int main()
{
    int number1,number2,chc,flag=1;
    Binary b1,b2,b3;
    while(flag)
    {
        cout<<"\n BINARY OPERATIONS \n 1.Generate Binary \n 2.One's Complement \n 3.Two's Complement \n 4.Addition of two Binary numbers \n Enter your choice:-> "<<endl;
        cin>>chc;
        switch (chc)
        {
        case 1:
            cout<<"Enter the number in decimal form:-> "<<endl;
            cin>>number1;
            b1.generate(number1);
            cout<<"The Binary representation of the number is:-> "<<endl;
            b1.DisplayBinary();
            break;
        case 2:
            cout<<"Enter the number in decimal form:-> "<<endl;
            cin>>number1;
            b1.generate(number1);
            cout<<"The Binary representation of the number is:-> "<<endl;
            b1.DisplayBinary();
            cout<<"The One's complement representation of the number is:-> "<<endl;
            b1.OnesComplement();
            break;
        case 3:
            cout<<"Enter the number in decimal form:-> "<<endl;
            cin>>number1;
            b1.generate(number1);
            cout<<"The Binary representation of the number is:-> "<<endl;
            b1.DisplayBinary();
            cout<<"The Two's complement representation of the number is:-> "<<endl;
            b1.TwosComplement();
            break;
        case 4:
            cout<<"Enter the numbers in decimal form which are to be added:-> "<<endl;
            cin>>number1>>number2;
            b1.generate(number1);
            b2.generate(number2);
            b1.DisplayBinary();
            cout<<" + "<<endl;
            b2.DisplayBinary();
            cout<<" = "<<endl;
            b3=b1+b2;
            b3.DisplayBinary();
            break;
        default:
            cout<<"Enter correct choice"<<endl;
            break;
        }
        cout<<"\n Do you want to perform any other operations? (1/0) :-> "<<endl;
        cin>>flag;
    }
    return 0;
}
void Binary::generate(int num)
{
    bool rem;
    Node *t;
    rem=num%2;
    start=new Node(rem);
    num/=2;
    while(num!=0)
    {
        rem=num%2;
        num/=2;
        t=new Node(rem);
        t->next=start;
        start->prev=t;
        start=t;
    }
}
void Binary::DisplayBinary()
{
    Node *t;
    t=start;
    while(t!=NULL)
    {
        cout<<t->n;
        t=t->next;
    }
}
void Binary::OnesComplement()
{
    Node *t;
    t=start;
    while(t!=NULL)
    {
        if(t->n==1)
        {
            t->n=0;
        }
        else
        {
            t->n=1;
        }
        t=t->next;
    }
    DisplayBinary();
}
void Binary::TwosComplement()
{
    OnesComplement();
    cout<<"\n";
    bool carry=1;
    Node *t;
    t=start;
    while(t->next!=NULL)
    {
        t=t->next;
    }
    while(t!=NULL)
    {
        if(t->n==1&&carry==1)
        {
            t->n=0;
            carry=1;
        }
        else if(t->n==0&&carry==1)
        {
            t->n=1;
            carry=0;    
        }
        else if(carry==0)
        break;
        t=t->prev;   
    }
    if (t==NULL && carry==1)
    {
        insert(1);
    }
    DisplayBinary();
}
Binary Binary::operator+(Binary n1)
{
    Binary sum;
    Node *a=start;
    Node *b=n1.start;
    bool carry=0;
    while(a->next!=NULL)
    {
        a=a->next;
    }
    while(b->next!=NULL)
    {
        b=b->next;
    }
    while(a!=NULL && b!=NULL)
    {
        sum.insert((a->n)^(b->n)^carry);
        carry=((a->n && carry)||(a->n && b->n)||(b->n && carry));
        a=a->prev;
        b=b->prev;
    }
    while(a!=NULL)
    {
        sum.insert(a->n^carry);
        a=a->prev;
    }
    while(b!=NULL)
    {
        sum.insert(b->n^carry);
        b=b->prev;
    }
    sum.insert(carry);
    return sum;
}