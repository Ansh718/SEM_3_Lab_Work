#include<iostream>
#include<map>
#include<string>
using namespace std;
class Map
{
    string name;
    long p;
public:
    map<string , long> map1;
    void insert()
    {
        cout<<"Enter the name of state : ";
        cin>>name;
        cout<<"\nEnter the population of state : "<<endl;
        cin>>p;
        map1.insert(pair<string , long>(name,p));
    }
    void display_all_states()
    {
        map<string , long>::iterator itr;
        for(itr = map1.begin() ; itr != map1.end() ; ++itr)
        {
            cout<<"\n State : "<<itr->first<<" and population is "<<itr->second<<endl;
        }
    }
    void display_specific_state()
    {
        map<string , long>::iterator itr;
        string name;
        cout<<"Enter the state you want to know about : ";
        cin>>name;
        for(itr = map1.begin() ; itr != map1.end() ; ++itr)
        {
            if (itr->first == name )
            {
                cout<<"\n State : "<<itr->first<<" and population is "<<itr->second<<endl;
                break;
            }
            else if ( itr == map1.end())
            {
                cout<<"state not found in container."<<endl;
            }
        }
    }
};
int main()
{
    Map m1;
    bool flag = true;
    while (flag)
    {   
        int choice;
        cout<<"\nPress 1 to insert a state : "<<endl;
        cout<<"Press 2 to display all states : "<<endl;
        cout<<"Press 3 to search a state : "<<endl;
        cout<<"Press 4 to end : "<<endl;
        cout<<"Enter operation : ";
        cin>>choice;
        switch (choice)
        {
        case 1:
            m1.insert();
            break;
        case 2:
            m1.display_all_states();
            break;
        case 3:
            m1.display_specific_state();
            break;
        case 4:
            flag = false;
            break;
        default:
            cout<<"Enter correct chioce"<<endl;
            break;
        }
	}
    return 0;
}
