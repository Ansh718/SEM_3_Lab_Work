#include<iostream>
#include<string>
using namespace std;
class Node
{
    public:
    string name;
    Node *next;
    Node(string NewName)
    {
        name=NewName;
        next=NULL;
    }
};
class LinkedList
{
    public:
    Node *head,*tail;
    LinkedList()
    {
        head=tail=NULL;
    }
    LinkedList(string names[],int size)
    {
        head=tail=NULL;
        AppendNames(names,size);
    }
    void AppendName(string NewName)
    {
        if (tail)
        {
            tail->next=new Node(NewName);
            tail=tail->next;
        }
        else
        {
            head=new Node(NewName);
            tail=head;
        }
    }
    void AppendNames(string names[],int size)
    {
        for(int i=0;i<size;i++)
        {
            AppendName(names[i]);
        }
    }
    bool Search(string name)
    {
        Node *itr=head;
        while(itr)
        {
            if(itr->name==name)
            {
                return 1;
            }
            itr=itr->next;
        }
        return 0;
    }
    void Display()
    {
        Node *itr=head;
        while(itr)
        {
            cout<<itr->name<<" ";
            itr = itr->next;
        }
        cout<<"\n";
    }
};
LinkedList Union(LinkedList list1,LinkedList list2)
{
    LinkedList list3;
    Node *itr=list1.head;
    while (itr)
    {
        list3.AppendName(itr->name);
        itr=itr->next;
    }
    itr=list2.head;
    while (itr)
    {
        if (!list3.Search(itr->name))
        {
            list3.AppendName(itr->name);
        }
        itr=itr->next;
    }
    return list3;
}
LinkedList Intersection(LinkedList list1,LinkedList list2)
{
    LinkedList list3;
    Node *itr=list1.head;
    while(itr)
    {
        if(list2.Search(itr->name))
        {
            list3.AppendName(itr->name);
        }
        itr=itr->next;
    }
    return list3;
}
LinkedList Difference(LinkedList list1,LinkedList list2)
{
    LinkedList list3;
    Node *itr=list1.head;
    while(itr)
    {
        if(!list2.Search(itr->name))
        {
            list3.AppendName(itr->name);
        }
        itr=itr->next;
    }
    return list3;
}
int main()
{
    string butterscotch[5] = {"Alice", "Bob", "Charles", "Dan", "Evan"};
    string vanilla[5]= {"Alice", "Bob", "Fred", "Gary", "Holmes"};
    LinkedList butterscotchList= LinkedList(butterscotch, 5);
    LinkedList vanillaList= LinkedList(vanilla,5);
    butterscotchList.Display();
    vanillaList.Display();
    Union(butterscotchList,vanillaList).Display();
    Intersection(butterscotchList,vanillaList).Display();
    Difference(butterscotchList,vanillaList).Display();
    Difference(vanillaList,butterscotchList).Display();
    Difference(Union(butterscotchList,vanillaList),Intersection(butterscotchList,vanillaList)).Display();
    return 0;
}