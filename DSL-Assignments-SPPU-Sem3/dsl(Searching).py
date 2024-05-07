class Search:
    def __init__(self,info):
        self.ls=info
    def insertion_sort(self,myl):
        for i in range(len(self.ls)):
            j=i-1
            while j>=0 and self.ls[i]<self.ls[j]:
                self.ls[i],self.ls[j]=self.ls[j],self.ls[i]
                i=i-1
                j=j-1
        return self.ls
    def linear_search(self):
        t=int(input("WHICH ROLL NO. ARE YOU CONCERNED WITH?"))
        for i in range(len(self.ls)):
            if t==self.ls[i]:
                return('YES THIS STUDENT WAS PRESENT AND WAS AT',i+1,'POSITION')
        return("NOT ATTENDED!")
    def sentinal_search(self):
        t=int(input("WHICH ROLL NO. ARE YOU CONCERNED WITH?"))
        last=self.ls[len(self.ls)-1]
        self.ls[len(self.ls)-1]=t
        i=0
        while(self.ls[i]!=t):
            i+=1
        self.ls[len(self.ls)-1]=last
        if i<len(self.ls)-1 or t==self.ls[len(self.ls)-1]:
            return('YES THIS STUDENT WAS PRESENT AND WAS AT',i+1,'POSITION')
        else:
            return("NOT ATTENDED!")
    def binary_search(self):
        t=int(input("WHICH ROLL NO. ARE YOU CONCERNED WITH?"))
        t1=self.insertion_sort(self.ls)
        start=0
        end=len(t1)-1
        while(start<=end):
            mid=(start+end)//2
            if t1[mid]==t:
                return('YES THIS STUDENT WAS PRESENT AND WAS AT',mid+1,'POSITION')
            elif t1[mid]>t:
                end=mid
            else:
                start=mid+1
        return('NOT ATTENDED!')
    def fibonaccci_Search(self):
        t1=int(input("GIVE THE CONCERNED NUMBER:"))
        t=self.insertion_sort(self.ls)
        # t.sort()
        
        size=len(t)
        f0=0                                          
        f1=1
        f2=1
        while(f2<=size):
            f0=f1
            f1=f2
            f2=f0+f1
        s=-1
        while(f2>1):
            ind=min(s+f0,size-1)
            if t[ind]<t1:
                f2 = f1
                f1 = f0
                f0 = f2-f1
                s = ind
            elif t[ind]>t1:
                f2 = f0
                f1 = f1 - f0
                f0 = f2 - f1
            else:
                return ('YES THIS STUDENT WAS PRESENT AND WAS AT' ,ind+1,'POSITION')
        if f1 and t[size-1]==t1:
            return ('YES THIS STUDENT WAS PRESENT AND WAS AT' ,size-1,'POSITION')
        return ('Not attended!!')
while(True):
    choice=int(input("ENTER WHAT YOU WANT TO DO \n 1.TO GIVE THE INFO OF ROLL NUMBERS OF STUDENTS WHO ATTENDED \n 2.EXIT"))
    if choice==2:
        break
    elif choice==1:
        info=Search(list(map(int,input("ENTER THE ROLL NUMBERS").split())))
        while(True):
            chc=int(input("ENTER YOUR ACTION : \n 1.LINEAR SEARCH \n 2.SENTINAL SEARCH \n 3.BINARY SEARCH \n 4.EXIT \n5.FIBONACCI SEARCH"))
            if chc==4:
                break
            if chc==1:
                print(info.linear_search())
            if chc==2:
                print(info.sentinal_search())
            if chc==3:
                print(info.binary_search())
            if chc==5:
                print(info.fibonaccci_Search())             
                         
            
            

