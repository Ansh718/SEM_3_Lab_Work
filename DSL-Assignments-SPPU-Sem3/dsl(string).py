class StringOps:
    def __init__(self,string):
        self.string=string
    def LongestWord(self):
        blanks=[0]
        length=[]
        final=set()
        temp=self.string+" "
        for i in range(len(temp)):
            if temp[i]==" ":
                blanks.append(i+1)
        for i in range(len(blanks)-1):
            length.append(blanks[i+1]-blanks[i]-1)
        max_=max(length)
        for i in range(len(length)):
            if length[i]==max_:
                final.add(temp[blanks[i]:blanks[i+1]-1])
        return final
    def FrequencyCharacter(self):
        ch=str(input("Enter the character you are concerned with :-> "))
        ctr=0
        for i in self.string:
            if i==ch:
                ctr+=1
        return ctr
    def CheckPallindrome(self):
        for i in range(len(self.string)):
            if self.string[i]==self.string[len(self.string)-i-1]:
                continue
            else:
                return ("The given string is not a pallindrome")
        return ("The given string is a pallindrome")
    def CheckSubstringFirstOccurence(self):
        substring=str(input("Enter the substring you are concerned with :-> "))
        for i in range(len(self.string)-len(substring)+1):
            if self.string[i:i+len(substring)]==substring:
                return ("The substring is present in the string and it's first occurence is at :-> "+str(i+1))
        return ("No the given substring is not in the given string")
    def FrequencyEachWord(self):
        temp=[]
        tmp=''
        for i in self.string:
            if i==" ":
                temp.append(tmp)
                tmp=''
            else:
                tmp+=i
        if tmp:
            temp.append(tmp)
        WordFrequence=[temp.count(p) for p in temp]
        return ("Frequency of every word in the given string :-> ",dict(zip(temp,WordFrequence)))
print("Enter String :-> ")
string_=StringOps(str(input()))
while True:
    print(" 1.LONGEST WORD \n 2.FREQUENCY OF A PARTICULAR CHARACTER \n 3,CHECK FOR PALLINDROME CHARACTERISTIC \n 4.FIRST APPEARANCE OF SPECIFIC WORD \n 5.FREQUENCY OF EVERY WORD \n 6.EXIT")
    chc=int(input())
    if chc==6:
        break
    elif chc==1:
        print(string_.LongestWord())
    elif chc==2:
        print(string_.FrequencyCharacter())
    elif chc==3:
        print(string_.CheckPallindrome())
    elif chc==4:
        print(string_.CheckSubstringFirstOccurence())
    elif chc==5:
        print(string_.FrequencyEachWord())



