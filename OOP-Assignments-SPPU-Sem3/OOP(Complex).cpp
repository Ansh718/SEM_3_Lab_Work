#include<iostream>
using namespace std;
class Complex
{
    public:
    int real,img;
    Complex(int r=0, int i=0)
    {
        real=r;
        img=i;
    }
    Complex operator+ (Complex x)
    {
        Complex ans;
        ans.real=real+x.real;
        ans.img=img+x.img;
        return ans;
    }
    Complex operator* (Complex x)
    {
        Complex ans;
        ans.real=(real*(x.real))-(img*(x.img));
        ans.img=(real*(x.img))+(img*(x.real));
        return ans;
    }
    friend ostream &operator <<(ostream &out,Complex &c);
    friend istream &operator >>(istream &in,Complex &c);
};
ostream &operator <<(ostream &out,Complex &c)
{
    out<<c.real<<" + "<<c.img<<"i"<<endl;
    return out;
}
istream &operator >>(istream &in,Complex &c)
{
    cout<<"Enter real part :-> "<<endl;
    in>>c.real;
    cout<<"Enter Imaginary part :-> "<<endl;
    in>>c.img;
    return in;
}
int main()
{
    while(1>0)
    {
		int choice;
		cout<<"ENTER YOUR REQUIREMENT"<<endl<< "1.TO GIVE INPUT"<<endl<< "2.EXIT"<<endl;
		cin>>choice;
		if(choice==2){
			break;
		}
		else{
			cout<<"ENTER THE DATA OF COMPLEX NUMBERs"<<endl;
			Complex C1,C2;
			cin>>C1>>C2;
			while(1>0)
            {
				int chc;
				cout<<"ENTER THE OPERATION YOU WANT TO PERFORM"<<endl<<"1.ADDITION"<<endl<<"2.MULTIPLICATION"<<endl<<"3.EXIT";
				cin>>chc;
				if (chc==1)
				{
					Complex C3;
					C3=C1+C2;
					cout<<C3<<endl;
				}

				else if(chc==2){
					Complex C3;
					C3=C1*C2;
					cout<<C3<<endl;
				}

				else if(chc==3){
					break;
				}
				else
                {
					cout<<"INVALID INPUT";
				}

			}
		}
	}
}

