class QuickS:
    def __init__(self,data):
        self.ls=data
    def division(self,ls,low,high):
        pivot=ls[high]
        i=low-1
        for j in range(low,high):
            if ls[j]<=pivot:
                i=i+1
                ls[i],ls[j]=ls[j],ls[i]
        ls[i+1],ls[high]=ls[high],ls[i+1]
        return i+1
    def quick_sort(self,ls,low,high):
        if  low<high:
            di=self.division(ls,low,high)
            self.quick_sort(ls,low,di-1)
            self.quick_sort(ls,di+1,high)
        return ls
while(True):
    chc=int(input("Enter your choice \n 1.Give input of students percentages \n 2.Exit"))
    info=QuickS([])
    if chc==2:
        break
    else:
        data=list(map(float,input("Enter the percentages:").split()))
        while(True):
            chc=int(input("Enter your choice \n 1.QuickSort \n 2.Top5 candidates \n 3.Exit"))
            if chc==3:
                break
            if chc==2:
                temp=info.quick_sort(data,0,len(data)-1)
                temp=temp[::-1]
                print(temp[0:5])
            if chc==1:
                print(info.quick_sort(data,0,len(data)-1))



