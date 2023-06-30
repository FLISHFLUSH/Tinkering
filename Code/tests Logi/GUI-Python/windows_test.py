import tkinter as tk
from tkinter import *
import os

class currentPath:
  def currentPath(self):
    pass

def onFrameConfigure(canvas):
    '''Reset the scroll region to encompass the inner frame'''
    canvas.configure(scrollregion=canvas.bbox("all"))

root = tk.Tk()
canvas = tk.Canvas(root, borderwidth=0, background="#ffffff")
paned_1= tk.PanedWindow(canvas, 
                        background="#ffffff",
                        orient=HORIZONTAL,
                        sashrelief=RAISED,
                        sashwidth=5,
                        borderwidth =0)
#if tied to canvas, window get sto minimum size
#could be because scollbar bcomes the last widget in the three

#yview recupère et change le view vertical
vsb = tk.Scrollbar(root, orient="vertical", command=canvas.yview)

#xcrollcommand means the scrollbar becomes usable based on x parameters (same for y)
canvas.configure(yscrollcommand=vsb.set)

#root.update()
def flush(event):
 #print(root.winfo_height())
 pass

root.bind('<B1-Motion>',flush)

vsb.pack(side="right", fill="y")
canvas.pack(side="left", fill="both", expand=True)
canvas.create_window((4,4), window=paned_1, anchor="nw")

paned_1.bind("<Configure>", lambda event, canvas=canvas: onFrameConfigure(canvas))

#DOUBLE SOLUCE POUR LIER OBJETS: 1. UTILISER STRINGVAR5) 2. CREER UNE CLASSE (ex:pour changer le BG 
# de chaque lizst au meme index en 1 ligne)
filesName, filesSize= Listbox(paned_1,highlightcolor="red"),Listbox(paned_1)
listBoxList=[filesName,filesSize]

def insert_filesNames_DateNsize(foldersList, sizeList): 
  with os.scandir() as it:   
    for entry in it:     
       filename,filesize= entry.name, os.path.getsize(entry.path)     
       foldersList.insert(END,"{}".format(filename))  
       sizeList.insert(END,"{}GB".format(filesize))

def create_Paned_Listboxes(PanedWin, filesNames):
  insert_filesNames_DateNsize(filesName, filesSize)
  for filesNameox in filesNames:
    PanedWin.add(filesNameox)

create_Paned_Listboxes(paned_1, listBoxList)


def Base_change(color, bits=16):
  while(color>bits):
    color/=bits
  return color

def To_Hex_256(color,x,bits):
  newColor= (min(color*x,bits-1))
        #hex() add 'ox' after convertion
  newColor=hex(int(newColor))[2:]
  return newColor

def RGB_To_Hex_256(colorList,x=1,bits=256):
  colorString=""
  for color in colorList:
   color=Base_change(color,256)
   color=To_Hex_256(color,2,256)
   while(len(color)<2):
     color="0"+color
   colorString+=color
  return colorString



print(RGB_To_Hex_256([0, 30840, 55255],1.3,256))

def listbox_hover_sync(event):
 #get index of listbox item hovered
  index= event.widget.nearest(event.y)
  print(index)
  #get color of selectbackgroun of said item
  bgColor=event.widget["selectbackground"]
  #turn it into processable infortation
  rgb= list(root.winfo_rgb(bgColor))
  rgb= RGB_To_Hex_256( rgb ,1.3)
  #do shit
  for item in listBoxList:
    item.itemconfig(index,{'bg':'#{}'.format(rgb)})
    print(bgColor)
    print(rgb)
    print(root.winfo_rgb(bgColor), end ="")
    print("  ITS A TUPLE")
    
def listbox_sync_select(
  event):
  pass
    #item.activate(index)
filesName.selection_set(3)
filesName.bind('<Motion>', listbox_hover_sync)
print(root.winfo_rgb("SystemHighlight"))
#filesName.bind('<Double-click>', listbox_sync_select)

#populate(frame)

root.mainloop()