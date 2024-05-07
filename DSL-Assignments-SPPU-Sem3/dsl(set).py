def Check(set1):
    ans=[]
    for i in range(len(set1)):
        if set1[i] not in ans:
            ans.append(set1[i])
    return ans
def Union(set1,set2):
    ans=set1+set2
    return ans
def Intersection(set1,set2):
    ans=[]
    for i in range(len(set1)):
        if set1[i] in set2:
            ans.append(set1[i])
    return ans
def Difference(set1,set2):
    ans=[]
    for i in range(len(set1)):
        if set1[i] not in set2:
            ans.append(set1[i])
    return ans
def Symmetric_Difference(set1,set2):
    set1_=Union(set1,set2)
    set2_=Intersection(set1,set2)
    ans=Difference(set1_,set2_)
    return ans
while True:
    chc=int(input("Enter your choice: \n 1.Give input of roll numbers of students  \n 2.See the list of students in respective sports \n 3.See the required output of details asked \n 4.Exit"))
    if chc==4:
        break
    elif chc==1:
        print("Enter the roll numbers of total students in the class \n enter 0 to finish")
        all=[]
        all.append([])
        while True:
            temp=int(input())
            if temp==0:
                break
            else:
                all[0].append(temp)
        total=Check(all[0])
        print("Enter the roll numbers of cricket students in the class \n enter 0 to finish")
        all.append([])
        while True:
            temp=int(input())
            if temp==0:
                break
            else:
                all[1].append(temp)
        cricket=Check(all[1])
        print("Enter the roll numbers of badminton students in the class \n enter 0 to finish")
        all.append([])
        while True:
            temp=int(input())
            if temp==0:
                break
            else:
                all[2].append(temp)
        badminton=Check(all[2])
        print("Enter the roll numbers of football students in the class \n enter 0 to finish")
        all.append([])
        while True:
            temp=int(input())
            if temp==0:
                break
            else:
                all[3].append(temp)
        football=Check(all[3])
    elif chc==2:
        print("Total Students:-> ",total)
        print("Cricket Students:-> ",cricket)
        print("Badminton Students:-> ",badminton)
        print("Football Students:-> ",football)
    elif chc==3:
        print("Cricket and Badminton :-> ",Intersection(cricket,badminton))
        print("Cricket and Badminton but not both :-> ",Symmetric_Difference(cricket,badminton))
        print("Neither Cricket nor Badminton :-> ",Difference(total,Union(cricket,badminton)))
        print("Cricket and Football but not Badminton :-> ",Difference(Intersection(cricket,football),Intersection(Intersection(cricket,badminton),Intersection(badminton,football))))
        



