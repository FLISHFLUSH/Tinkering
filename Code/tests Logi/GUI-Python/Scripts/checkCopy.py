import os

def addendum_directory(dirString="",mypath= os.getcwd(),addition=True):
 DirName= os.path.basename(mypath)
 if (addition):
  DirName=  DirName+dirString
 return os.path.join(mypath,DirName)
 
def gen_directory(mypath):
   f = []
   for (dirpath, dirnames, filenames) in os.walk(mypath):
    f.extend(filenames)
    break 
   return f

def same_directory(pathOne, pathTwo):
 fOne= gen_directory(pathOne)
 fTwo= gen_directory(pathTwo)
 if (len(fOne) != len(fTwo)):
   return False
 else:
  for 



print(f)


print(addendum_directory("-encode"))

mypath=os.getcwd()
f = []
for (dirpath, dirnames, filenames) in os.walk(mypath):
   f.extend(filenames)
   break
print(f)