#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class Student
{
public:
	int rn;
	string name;
	void accept(string name , int rn)
    {
		this->name=name;
		this->rn=rn;
	}
	void write(ofstream &Entry_file)
    {
		Entry_file<<" "<<name<<endl;
		Entry_file<<" "<<rn<<endl;
	}
};
int main()
{
	ofstream f;
	f.open("File1.txt",ios::out);
	Student s1;
	s1.accept("Ansh", 21111);
	s1.write(f);
	f.close();
    string temp1,temp2;
    ifstream fi;
    fi.open("File1.txt",ios::in);
    fi>>temp1;
    fi>>temp2;
    cout<<"Name is "<<temp1<<endl;
    cout<<"Roll no. is "<<temp2<<endl;
    fi.close();
	return 0;
}
