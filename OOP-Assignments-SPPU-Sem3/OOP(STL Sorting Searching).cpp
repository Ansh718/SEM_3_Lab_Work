#include<iostream>
#include<algorithm>
#include<vector>
#include<iterator>
using namespace std;
class Personal
{
    public:
    char fname[25];
    long long int dob,contact;
    bool operator==(const Personal &p1)
    {
        if(contact==p1.contact)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    bool operator<(const Personal &p1)
    {
        if(contact<p1.contact)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
};
vector<Personal> person;
void Print(Personal &p1);
void Display();
void Insert();
void Search();
void Delete();
bool compare_dob(const Personal &p1,const Personal &p2)
{
    return p1.dob < p2.dob;
}
bool compare_contact(const Personal &p1,const Personal &p2)
{
    return p1.contact < p2.contact;
}
bool compare_fname(const Personal &p1,const Personal &p2)
{
    return p1.fname < p2.fname;
}
int main()
{
    int ch,flag=1;
    while(flag)
    {
        cout<<"\nEnter your choice : \n1.Insert \n2.Display\n3.Search\n4.Sort\n5.Delete"<<endl;
        cin>>ch;
        switch(ch)
        {
            case 1:
            Insert();
            break;
            case 2:
            Display();
            break;
            case 3:
            Search();
            break;
            case 4:
            sort(person.begin(),person.end(),compare_fname);
            cout<<"\n \n Sorted on First Name :-> "<<endl;
            Display();
            sort(person.begin(),person.end(),compare_dob);
            cout<<"\n \n Sorted on Date of Birth :-> "<<endl;
            Display();
            sort(person.begin(),person.end(),compare_contact);
            cout<<"\n \n Sorted on Contact Details :-> "<<endl;
            Display();
            break;
            case 5:
            Delete();
            break;
            default:
            cout<<"Enter correct choice"<<endl;
        }
        cout<<"Do you want to perform another operation?(1/0) :-> "<<endl;    
        cin>>flag;
    } 
    return 0;
}
void Insert()
{
    Personal p1;
    cout<<"\n Enter Person's First Name :->"<<endl;
    cin>>p1.fname;
    cout<<"\n Enter Person's Date of Birth :->"<<endl;
    cin>>p1.dob;
    cout<<"\n Enter Person's Contact Number :->"<<endl;
    cin>>p1.contact;
    person.push_back(p1);
}
void Display()
{
    for_each(person.begin(),person.end(),Print);
}
void Print(Personal &p1)
{
    cout<<"\n Person's First Name :-> "<<p1.fname<<endl;
    cout<<"\n Person's Date of Birth :-> "<<p1.dob<<endl;
    cout<<"\n Person's Conatact Details :-> "<<p1.contact<<endl;
    cout<<"\n \n"<<endl;
}
void Search()
{
    vector<Personal>::iterator i;
    Personal p1;
    cout<<"\n Enter Person's Contact Details to be Searched :-> "<<endl;
    cin>>p1.contact;
    i=find(person.begin(),person.end(),p1);
    if (i==person.end())
    {
        cout<<"\n This person was not found."<<endl;
    }
    else
    {
        cout<<"\n This person was found."<<endl;
    }
}
void Delete()
{
    vector<Personal>::iterator i;
    Personal p1;
    cout<<"\n Enter Person's Contact Details to be Deleted :-> "<<endl;
    cin>>p1.contact;
    i=find(person.begin(),person.end(),p1);
    if (i==person.end())
    {
        cout<<"\n This person was not found."<<endl;
    }
    else
    {
        person.erase(i);
        cout<<"\n This person was deleted from database."<<endl;
    }
    
}