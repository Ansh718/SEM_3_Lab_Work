
#include <iostream>
using namespace std;
template<class T>
class item {
    public: 
    T id ;
    int priority ;

    item(T id_  = 0 ,int priority_ = 0 ){
        id = id_;
        priority = priority_ ;
    }
    bool operator <=(item<int> i2){
            if(priority>i2.priority)
            return 1;
            else
            return 0;
        }
        friend class priorityQueue;
};
template <class T>
class PQueue{
    public : 
    item<T> items[20] ;
    int front = -1;
    int end  = -1 ;

    void displayall(){
        for (int i = 0 ; i < 20 ; i ++){
            cout<<items[i].id<<" "<<items[i].priority<<endl;
        }
        cout<<front <<" "<<end;
    }

    void enQueue(item<T> new_item){
        if(front == -1 && front == end ){
            front ++;
            end ++ ;
            items[end].id = new_item.id ;
            items[end].priority = new_item.priority ;
        }
        else {
            if(end == 19){
                cout<<"Queue over flow";
            }
            else {
                end ++ ;
                int j = end ;
                while(new_item<=items[j-1] && j != front){
                    items[j].id = items[j - 1 ].id;
                    items[j].priority = items[j - 1 ].priority;    
                    items[j - 1].id = new_item.id ;
                    items[j - 1].priority = new_item.priority ;
                    j = j - 1 ;
                }
            }
            
        }
    }
    void deQueue(){
        if(front  > end ){
            cout<<"Queue empty";
        }
        else {
            front ++ ;
            // return items[front - 1] ;
        }
    }
    void display(){
        for (int i = front ; i <= end ; i ++ ){
            cout<<items[i].id<<"("<<items[i].priority<<")  "<<endl;
        }
        cout<<endl ;
    }
};


int main(){
    PQueue<int> Q ;
    item<int> I1(1,10), I2(2,100) , I3(3,50), I4(4,75);
    Q.enQueue(I1) ;
    Q.enQueue(I2) ;
    Q.enQueue(I3) ;
    Q.enQueue(I4) ;
    Q.display();
    cout<<"\n";
    Q.deQueue();
    Q.display();
    cout<<"\n";
    Q.deQueue();
    Q.display();
    return 0 ; 
}
