class Matrix:
    def __init__(self,matrix):
        self.matrix=matrix
    def sum(self,temp):
        if len(self.matrix)!=len(temp) or len(self.matrix[0])!=len(temp[0]):
            return 'Addition not possible as size of matrices are not same!'
        else:
            ans=[]
            for i in range(len(self.matrtix)):
                ans.append([])
                for j in range(len(self.matrix[0])):
                    ans[i].append(self.matrix[i][j]+temp[i][j])
            return ans
    def difference(self,temp):
        if len(self.matrix)!=len(temp) or len(self.matrix[0])!=len(temp[0]):
            return 'Subtraction not possible as size of matrices are not same!'
        else:
            ans=[]
            for i in range(len(self.matrix)):
                ans.append([])
                for j in range(len(self.matrix[0])):
                    ans[i].append(self.matrix[i][j]-temp[i][j])
            return ans
    def multiplication(self,temp):
        if len(self.matrix[0])!=len(temp):
            return 'Multiplication not possible as number of columns of one matrix is not equal to number of rows of other'
        else:
            ans=[]
            for i in range(len(self.matrix)):
                ans.append([])
                for j in range(len(temp[0])):
                    ans[i].append(0)
                    for k in range(len(temp)):
                        ans[i][j]+=(self.matrix[i][k])*(temp[k][j])
            return ans 
    def transpose(self,temp):
        ans=[]
        for j in range(len(self.matrix[0])):
            ans.append([])
            for i in range(len(self.matrix)):
                ans[j].append(self.matrix[i][j])
        return ans
    def fetch_list(self):
        return self.matrix
def display(list1):
    for i in range(len(list1)):
        ans=""
        for j in range(len(list1[i])):
            ans+=str(list1[i][j]) +" "
        print (ans)
while(True): 
    choice=int(input("ENTER WHAT YOU WANT TO DO:-> \n 1.GIVE INPUT \n 2.I QUIT!!"))
    if choice==2:
        break
    elif choice==1:
        temp=[]
        print("enter data for first matrix space separated,enter to go to next row \n hit enter and leave a blank to finish")
        while(True):
            temp.append(list(map(int,input().split())))
            if len(temp[len(temp)-1])==0:
                temp.pop()
                break
        mat1=Matrix(temp)
        temp=[]
        print("enter data for second  matrix space separated,enter to go to next row \n hit enter and leave a blank to finish")
        while(True):
            temp.append(list(map(int,input().split())))
            if len(temp[len(temp)-1])==0:
                temp.pop()
                break
        mat2=Matrix(temp)
        while(True):
            chc=int(input(("CHOOOSE:->\n 1.SUM \n 2.DIFFERENCE \n 3.MULTIPLICATION \n 4.TRANSPOSE \n 5.return to above choices")))
            if (chc==5):
                break
            elif(chc==1):
                t1=mat2.fetch_list()
                display(mat1.sum(t1))
            elif(chc==2):
                t1=mat2.fetch_list()
                display(mat1.difference(t1))
            elif(chc==3):
                t1=mat2.fetch_list()
                display(mat1.multiplication(t1))
            else:
                display(mat1.transpose())
                display(mat2.transpose()) 

    