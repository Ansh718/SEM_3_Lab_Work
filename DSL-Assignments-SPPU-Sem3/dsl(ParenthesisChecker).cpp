#include<iostream>
#include<string>
using namespace std;
class StoringStack
{
    public:
    int top,n;
    char *arr;
    StoringStack(){}
    StoringStack(int n)
    {
        this->n=n;
        arr=new char[n];
        top=-1;
    }
    friend class Expression;
    void push(char x);
    void pop();
    bool isEmpty();
    char peek();
    void display();
};
class Expression
{
    public:
    string exp;
    void input();
    bool CheckParenthesis();
};
int main()
{
    Expression expr;
    expr.input();
    if (expr.CheckParenthesis())
    {
        cout<<"Given Expression is VALID!"<<endl;
    }
    else
    {
        cout<<"Given Expression is INVALID!"<<endl;
    }
    return 0;
}
void StoringStack::push(char x)
{
    if(top==n-1)
    {
        cout<<"Stack Overflow"<<endl;
    }
    else
    {
        arr[++top]=x;
    }
}
void StoringStack::pop()
{
    if(top==-1)
    {
        cout<<"Stack Underflow"<<endl;
    }
    else
    {
        top--;
    }
}
void StoringStack::display()
{
    int itr=0;
    while(itr<=top)
    {
        cout<<arr[itr]<<endl;
        itr++;
    }
}
char StoringStack::peek()
{
    return arr[top];
}
bool StoringStack::isEmpty()
{
    if(top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void Expression::input()
{
    cout<<"Enter Expression :-> "<<endl;
    cin>>exp;
}
bool Expression::CheckParenthesis()
{
    StoringStack S(20);
    for(int i=0;i<exp.length();i++)
    {
        if (exp[i]=='('||exp[i]=='['||exp[i]=='{')
        {
            S.push(exp[i]);
        }
        else if(exp[i]==')'||exp[i]==']'||exp[i]=='}')
        {
            if(S.isEmpty())
            {
                return 0;
            }
            else
            {
                char t=S.peek();
                if(exp[i]==')' && t=='(')
                {
                    S.pop();
                    continue;
                }
                else if(exp[i]==']' && t=='[')
                {
                    S.pop();
                    continue;
                }
                else if(exp[i]=='}' && t=='{')
                {
                    S.pop();
                    continue;
                }
                else
                {
                    return 0;
                }
            }
        }
        else
        {
            continue;
        }
    }
    cout<<"Element at Top of the Stack is :-> "<<S.peek()<<endl;
    if(!S.isEmpty())
    {
        return 0;
    }
    else
    {
        return 1;
    }
}