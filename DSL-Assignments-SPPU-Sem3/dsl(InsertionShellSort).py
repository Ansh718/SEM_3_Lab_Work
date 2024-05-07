class Sorting:
    def __init__(self,data):
        self.ls=data
    def insertion_sort(self):
        myl=self.ls
        for i in range(len(myl)):
            j=i-1
            while j>=0 and myl[i]<myl[j]:
                myl[i],myl[j]=myl[j],myl[i]
                j=j-1
                i=i-1
        return myl
    def shell_sort(self):
        myl=self.ls
        gap=len(myl)//2
        while gap>0:
            j=gap
            while j<len(myl):
                i=j-gap
                while i>=0:
                    if myl[i+gap]>myl[i]:
                        break
                    else:
                        myl[i+gap],myl[i]=myl[i],myl[i+gap]
                    i=i-gap
                j+=1
            gap=gap//2
        return myl
    def top_5(self):
        myl=self.ls
        temp=myl[::-1]
        return temp[0:5]
while(True):
    chc=int(input("Enter your choice \n 1.Give input of percentages \n 2.exit"))
    if chc==2:
        break
    else:
        info=Sorting(list(map(int,input("Enter the percentages").split())))
        while(True):
            chc=int(input("Enter your choice \n 1.Insertion Sort \n 2.Shell Sort \n 3.Top 5 \n 4.exit to main menu"))
            if chc==4:
                break
            if chc==1:
                print(info.insertion_sort())
            if chc==2:
                print(info.shell_sort())
            if chc==3:
                print(info.top_5())
                
