from re import S
import sqlite3
import sys
import math
import json

class ScreenXY:
   def __init__(self, resoX, resoY, radius,centerX=-1, centerY=-1):
       self.rX=resoX
       self.rY=resoY
       self.radius=radius
#center adjusting if necessary    
       if centerX<0:
        self.cX=self.rX/2
       else:
        self.cX=centerX
       if centerY<0:
        self.cY=self.rY/2
       else:
        self.cY=centerY
     

class VariableName:
    def __init__(self, varName, varNum):
     self.varName=varName
     self.varNum=varNum


def gen_Quarter_Circle(radius):
    qCircle=[]
    for x in range(radius+1):
        #-1 => Pi°, 1 = > 0°
        #we're building the top left quarter
        angle=math.acos((radius-x)/radius)
        #getting y for each x pixel
        y_pos=math.sin(angle)*radius
        y_pos=round(y_pos)
        qCircle.append(y_pos)
    return qCircle

def gen_Half_Circle(radius):
    LCircle=gen_Quarter_Circle(radius)
    #creating top right quarter
    RCircle=LCircle[::-1]
    #removing last elem to avoid doublons
    LCircle.pop()
    halfCircle=LCircle + RCircle
    return halfCircle

def calculate_offset(container,radius,center): 
     #ADD TEST

    #the +1 is to account for odd numbers
   offset=center-radius
    #check if center can match with item size
    #ITS MISSING THE OTHER CORNER CHECK
   return offset


def Array1920x1020(screen):
 #NEED TO ADD VALUE CHECK (fit() function)
    #set at center if no value is entered
    AHL_dict={}
    offset_x=int(calculate_offset(screen.rX, screen.radius,screen.cX))
    offset_y=int(calculate_offset(screen.rY, screen.radius,screen.cY))
    halfCircle = gen_Half_Circle(screen.radius)
    print(halfCircle)
#recent change: moved to COORDX instead of X
#Could now simply iterate rom -radius to +radius for clarity
    for index,item in enumerate(halfCircle):
        coordX=index+offset_x-int(screen.rX/2)
        coordY=int(item)
        AHL_dict[coordX]=coordY
    return AHL_dict,offset_y,screen.rX-offset_x,screen.rY-offset_y, offset_x

def AHKArrayPrint(arrayVar, dict):
    for i, (k, v) in enumerate(dict.items()):
     print("{}{}[{}]:= {}".format(arrayVar.varName, arrayVar.varNum, k, v))


##def GenerateMin
# iArray(var,miniArraySize): _    string=var.varName+string(var.varNum)+':= {' _ for index,item in enumerate():__ String+=___        it=0__        string="{" __        if (it == miniArraySize):__           temp_string__            temp_string={}__            it=0__        it+=1__    if (len(temp_dict)>0):__       string+=(temp_string)__ def ArrayPrint19201020(dict,miniArraySize=1):__    #ideclaration__    string=""__    #iterator fur array variable naming__    ArrayNum=0__    temp_string=""
print("saucisse")
arrayVar= VariableName("ArrayPos", "")
screen=ScreenXY(1020,1920, 300)
circle,top,right,bottom,left=Array1920x1020(screen)
SquareTRBL=[top,right,bottom,left]
print(SquareTRBL)

   # print("{}: {}".format(a,b))
   # print('{}{}[{}]:={}'.format(arrayName.varName, arrayName.varNum,a,b))
original_stdout= sys.stdout
# __p_string=json.dumps(dict).replace("\"","")__n={}__for x in dict:____    n[x]=1020-dict[x]____n_string=json.dumps(n).replace("\"","")__print
with open("Factorio_Mouse_Zone.ahk", 'w') as f:
    sys.stdout = f # Change the standard output to the file we created.
    print("SquareTRBL:=",end="")
    print(SquareTRBL)
    print("ArrayPos:= {}")
    print("ArrayPos[radius]:= {}".format(screen.radius))
    AHKArrayPrint(arrayVar,circle)
    sys.stdout = original_stdout

l=gen_Half_Circle(350)
print(len(l))
#print(l)
print(math.acos(1))