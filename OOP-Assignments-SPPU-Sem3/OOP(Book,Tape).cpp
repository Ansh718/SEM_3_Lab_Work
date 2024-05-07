#include<iostream>
#include<string>
using namespace std;
class Publication
{
    protected:
        string title;
        float price;
};
class Book:public Publication
{
        int PageCount;
    public:
        void SetDetails();
        void Display();
};
class Tape:public Publication
{
        float PlayTime;
    public:
        void SetDetails();
        void Display();
};
void Book::SetDetails()
{
    try
    {
        cout<<"Enter Title of the Book :-> "<<endl;
        getline(cin,title);
        cout<<"Enter Price of the Book :-> "<<endl;
        cin>>price;
        cout<<"Enter number of Pages of the Book :-> "<<endl;
        cin>>PageCount;
        if (this->title.size() < 3.0)
        {
            cout<<"\n This title is too short"<<endl;
            throw this->title;
        }
        if (this->price < 0.0)
        {
            cout<<"Invalid Price "<<endl;
            throw this->price;
        }
        if(this->PageCount < 0)
        {
            cout<<"Invalid PageCount"<<endl;
            throw this->PageCount;
        }
    }
    catch(string &title)
    {
        this->title="";
        this->price=0.0;
        this->PageCount=0;
    }
    catch(float price)
    {
        this->title="";
        this->price=0.0;
        this->PageCount=0; 
    }
    catch(int PageCount)
    {
        this->title="";
        this->price=0.0;
        this->PageCount=0;
    }
}
void Book::Display()
{
    cout<<"Details of the book :-> "<<endl;
    cout<<"Title of the book :-> "<<title<<endl;
    cout<<"Price of the book :-> "<<price<<endl;
    cout<<"Pages in the book :-> "<<PageCount<<endl;
}
void Tape::SetDetails()
{
     try
    {
        cout<<"Enter Title of the Tape :-> "<<endl;
        cin.ignore();
        getline(cin,title);
        cout<<"Enter Price of the Tape :-> "<<endl;
        cin>>price;
        cout<<"Enter PlayTime of the Tape :-> "<<endl;
        cin>>PlayTime;
        if (this->title.size() < 3.0)
        {
            cout<<"\n This title is too short"<<endl;
            throw this->title;
        }
        if (this->price < 0.0)
        {
            cout<<"Invalid Price "<<endl;
            throw this->price;
        }
        if(this->PlayTime < 0.0)
        {
            cout<<"Invalid PageCount"<<endl;
            throw this->PlayTime;
        }
    }
    catch(string &title)
    {
        this->title="";
        this->price=0.0;
        this->PlayTime=0.0;
    }
    catch(float price)
    {
        this->title="";
        this->price=0.0;
        this->PlayTime=0.0; 
    }
    catch(int PageCount)
    {
        this->title="";
        this->price=0.0;
        this->PlayTime=0.0;
    }
}
void Tape::Display()
{
    cout<<"Details of the tape :-> "<<endl;
    cout<<"Title of the tape :-> "<<title<<endl;
    cout<<"Price of the tape :-> "<<price<<endl;
    cout<<"Playtime of the tape :-> "<<PlayTime<<endl;
}
int main()
{
    Book b;
    Tape t;
    b.SetDetails();
    b.Display();
    t.SetDetails();
    cout<<"\n";
    t.Display();
    return 0;
}
