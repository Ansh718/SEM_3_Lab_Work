#include<iostream>
#include<string>
using namespace std;
int Precedence(char c)
{
    if ( c=='*'|| c=='/' )
    {
        return 3;
    }
    else if ( c=='+' || c=='-' )
    {
        return 2;
    }
    else
    {
        return 1;
    }
}
class StoringStack
{
    public:
    int *arr,top,n;
    StoringStack(){}
    StoringStack(int n)
    {
        this->n=n;
        arr=new int[n];
        top=-1;
    }
    void push(char x);
    void pop();
    bool isEmpty();
    char peek();
    int peek1();
};
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
char StoringStack::peek()
{
    return arr[top];
}
int StoringStack::peek1()
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
class Expression
{
    public:
    string exp,result;
    void Input();
    void InfixToPostfix();
    void Evaluation();
};
void Expression::Input()
{
    exp="";
    cout<<"Enter the Infix Expression"<<endl;
    cin>>exp;
}
void Expression::InfixToPostfix()
{
    StoringStack S(20);
    result="";
    for (int i=0;i<exp.length();i++)
    {
        if(exp[i]=='(')
        {
            S.push(exp[i]);
        }
        else if(exp[i]==')')
        {
            while(S.peek()!='(')
            {
                result+=S.peek();
                S.pop();
            }
            S.pop();
        }
        else if(exp[i]=='/'||exp[i]=='*'||exp[i]=='+'||exp[i]=='-')
        {
            if(S.isEmpty())
            {
                S.push(exp[i]);
            }
            else
            {
                if (Precedence(exp[i])>Precedence(S.peek()))
                {
                    S.push(exp[i]);
                }
                else
                {
                    while((Precedence(exp[i])<=Precedence(S.peek())) && exp[i]!='(')
                    {
                        result+=S.peek();
                        S.pop();
                    }
                    S.push(exp[i]);
                }
                
            }
        }
        else
        {
            result+=exp[i];
        }
    }
    while(!S.isEmpty())
    {
        result+=S.peek();
        S.pop();
    }
    cout<<"Infix to Postfix converted Expression :-> "<<result<<endl;
}
void Expression::Evaluation()
{
    StoringStack S(20);
    for (int i=0;i<exp.length();i++)
    {
        if (result[i]>='0' && result[i]<='9')
        {
            S.push(result[i]-48);
        }
        else
        {
            int n=S.peek1();
            S.pop();
            int m=S.peek1();
            S.pop();
            if (result[i]=='/')
            {
                S.push(m/n);
            }
            else if(result[i]=='*')
            {
                S.push(m*n);
            }
            else if(result[i]=='+')
            {
                S.push(m+n);
            }
            else
            {
                S.push(m-n);
            }
        }
    }
    cout<<"Value of the expression is :-> "<<S.peek1()<<endl;
}
int main()
{
    Expression expr;
    int chc,flag=1;
    while(flag)
    {
        cout<<"Enter Choice: \n1.Input Expression \n 2.Infix to Postfix \n 3.Evaluation"<<endl;
        cin>>chc;
        switch (chc)
        {
        case 1:
            expr.Input();
            break;
        case 2:
            expr.InfixToPostfix();
            break;
        case 3:
            expr.Evaluation();
            break;
        default:
            cout<<"Enter Correct Choice"<<endl;
            break;
        }
        cout<<"Do you want to perform any other operation?(1/0) :-> "<<endl;
        cin>>flag;
    }
    return 0;
}