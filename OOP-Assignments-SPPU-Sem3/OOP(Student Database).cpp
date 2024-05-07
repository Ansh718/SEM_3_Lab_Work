#include<iostream>
#include<string>
using namespace std;
class StudentDatabase
{
    static int Entries ;
    string Name ;
    int RollNumber ;
    char Division ;
public: 
    StudentDatabase()
    {
        this -> Name = "default" ;
        this -> RollNumber = 0 ;
        this -> Division ='n';
        Entries ++ ;
    }
    StudentDatabase(string Name , int RollNumber , char Division)
    {
        this -> Name = Name ;
        this -> RollNumber = RollNumber ;
        this -> Division = Division;
        Entries ++ ;
    }
    StudentDatabase(StudentDatabase &S)
    {
        this -> Name = S.Name ;
        this -> RollNumber = S.RollNumber ;
        this -> Division = S.Division;
        Entries ++ ;
    }
    inline void DisplayData()
    {
        cout<<"\nName of the Student :-> "<<Name<<endl;
        cout<<"Roll Number of the Student :-> "<<RollNumber<<endl;
        cout<<"Division of the Student :-> "<<Division<<endl;
    }
    static void number_of_entries()
    {
        cout<<"\nNumber of entries are :-> "<<Entries<<endl;
    }
    friend class Counter ;
    ~StudentDatabase() 
    {
        cout<<"Object(Student) is Destroyed!"<<endl ;
    }
};
class Counter
{
    public:
    void DisplayData(StudentDatabase* S)
    {
        cout<<"\nName of the Student :-> "<<S->Name<<endl;
        cout<<"Roll Number of the Student :-> "<<S->RollNumber<<endl;
        cout<<"Division of the Student :-> "<<S->Division<<endl;
    }
};
int StudentDatabase :: Entries = 0 ;      
int main()
{
    string name ;
    int rn ;
    char div ;
    cout<<"Enter Name of the Student :-> \n";
    cin >> name ;
    roll_entry:
        try{
            cout<<"\nEnter Roll Number of the Student :->\n";
            cin>>rn ;
            if(rn<=0)
            {
                throw rn ;
            }
        }
        catch (int rn){
            cout<<"\nInvaild Roll Number\n";
            goto roll_entry ;
        }
    cout<<"\nEnter the Division of the Student :->\n";  
    cin>>div ;
    StudentDatabase *new_student = new StudentDatabase(name , rn , div );
    new_student -> DisplayData();
    Counter C ;
    C.DisplayData(new_student);
    new_student -> number_of_entries();
    StudentDatabase *new_student1 = new StudentDatabase("Somesh" , 12 , 'd' );
    new_student1 -> DisplayData();
    new_student -> number_of_entries();
    delete new_student ;
    delete new_student1 ;    
    return 0 ;
}