class Array2D:
    def _init_(self):
        return
    def Matrix(self,R,C):
        self.row=R
        self.col=C
        self.matrix=[0]*R
        for i in range(R):
            self.matrix[i]=[0]*C

    def Rows(self):
        return self.row

    def Cols(self):
        return self.col

    def prn2d( self ):
        for i in range( self.Rows() ):
            for j in range(self.Cols() ):
                print(self.matrix[i][j],end=" ")
            print("")
        return("")

    def Confi(self,coordlist) :
        for (r,c) in coordlist :
            self.matrix[r][c]=1
        self.prn2d()

    def Clrcell(self,r,c) :
        self.matrix[r][c]=0
        self.prn2d()

    def setCell(self,r,c) :
        self.matrix[r][c]=1
        self.prn2d()

    def isLiveCell(self,r,c) :
        if(self.matrix[r][c]==1):
            return True
        else: 
            return False

    def numLiveNeighbors(self,r,c) :
        count=0 
        Tra = [(0,1),(1,0),(-1,0),(0,-1),(1,-1),(1,1),(-1,1),(-1,-1)]
        for (r1,c1) in Tra :
            if(0<=r+r1<len(self.matrix) and 0<=c+c1<len(self.matrix[0]) and self.matrix[r+r1][c+c1]==1) :
                count+=1
        return count


A2=Array2D()
A2.Matrix(5,6)
A2.Confi(([(2,2),(1,3),(1,4),(2,4),(3,4),(3,3)]))
A2.isLiveCell(2,4)
A2.isLiveCell(0,0)
A2.setCell(0,0)
A2.Clrcell(4,5)
print("Total number of neighbours are :",(A2.numLiveNeighbors(2,4)))


# 0 0 0 0 0 0 
# 0 0 0 1 1 0 
# 0 0 1 0 1 0 
# 0 0 0 1 1 0 
# 0 0 0 0 0 0 
# Total number of neighbours are : 4
