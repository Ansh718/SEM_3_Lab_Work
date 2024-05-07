#include<iostream>
using namespace std;
template <class T>
class SelectionSort
{
        T *arr;
        int size;
    public:
        SelectionSort(int size)
        {
            this->size=size;
            arr=new T[size];
        }
        void GetData()
        {
            cout<<"\nEnter the Numbers that you want to sort :-> "<<endl;
            for (int i = 0;i < size; i++)
            {
                cin>>arr[i];
            }
        }
        void Sorting()
        {
            cout<<"\n The Array before Sorting :-> "<<endl;
            for (int i=0;i<size;i++)
            {
                cout<<arr[i]<<" ";
            }
            int min;
            T temp;
            for (int i=0;i<size;i++)
            {
                min=i;
                for (int j=i + 1;j<size; j++)
                {
                    if (arr[j] < arr[min])
                    {
                        min = j;
                    }
                }
                if (min != i)
                {
                    temp = arr[min];
                    arr[min] = arr[i];
                    arr[i] = temp;
                }
            }
            cout<<"\n The Array after Sorting :-> "<<endl;
            for (int i = 0;i < size; i++)
            {
                cout<<arr[i]<<" ";
            }
        }
};
int main()
{
    int chc,flag=1,n;
    while(flag)
    {
        cout<<"\nEnter your choices :-> \n 1.Perform Selection Sort on Integer Numbers \n 2.Perform Selection Sort on FLoating Numbers "<<endl;
        cin>>chc;
        switch (chc)
        {
        case 1:
            {
                cout<<"\n Enter the size of the array :-> "<<endl;
                cin>>n;
                SelectionSort <int>S1(n);
                S1.GetData();
                S1.Sorting();
            }
            break;
        case 2:
            {
                cout<<"\n Enter the size of the array :-> "<<endl;
                cin>>n;
                SelectionSort <float>S1(n);
                S1.GetData();
                S1.Sorting();
            }
            break;
        default:
            cout<<"Enter Correct Choice"<<endl;
            break;
        }
        cout<<"\n Do you want to perform another operation ? (1/0) :-> "<<endl;
        cin>>flag;
    }
    return 0;
}