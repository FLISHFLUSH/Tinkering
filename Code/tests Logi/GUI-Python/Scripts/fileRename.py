import os
import re

def removeReg(STRegex, string):
 a= re.sub(r'{}'.format(STRegex),"",string)
 return a

mypath=os.getcwd()
f = []
for (dirpath, dirnames, filenames) in os.walk(mypath):
    f.extend(filenames)
    break
print(f)

for file in f:
    print("Im in")
    os.rename(file,removeReg("[sS]eg\d--",file))
