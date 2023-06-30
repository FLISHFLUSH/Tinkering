from tkinter import *
height=800
length=600
window = Tk("{}x{}".format(height, length))


label= Label(window,text="lalalsdddddssssssssssdffsssssssssssssssssssss")
label.pack()

x=IntVar()
python_photo= PhotoImage(file="5qdbk.png")
def click():
    pass
def shoufle():
    if x.get():
        print(x)
def __cluck__():
    print(value)

c_button= Checkbutton(window,
                      text="popopo", 
                      variable=x,
                      command=shoufle,
                      onvalue=1, offvalue=0,
                      image=python_photo,
                      compound="left")
c_button.pack()
v = StringVar(window, "1")

#/!\/!\/!\/!\/!\ V.GET() Agit sur widget cliqué /!\/!\/!\/!\/!\
def cluck():
       print(v.get())
def submit():
    print("The temperature is: "+ str(scale.get())+ " degrees C")



#hotLabel = Label(image=hotImage)
#hotLabel.pack()


scale = Scale(window,
              from_=100,
              to=0,
              length=600,
              orient=VERTICAL, #orientation of scale
              font = ('Consolas',20),
              tickinterval = 10, #adds numeric indicators for value
              #showvalue = 0, #hide current value
              resolution = 5, #increment of slider
              troughcolor = '#69EAFF',
              fg = '#FF1C00',
              bg = '#111111'
              )

scale.set(((scale['from']-scale['to'])/2)+scale['to']) #set current value of slider

scale.pack()

#coldLabel = Label(image=coldImage)
#coldLabel.pack()
button = Button(window,text='submit',command=submit)
button.pack()


# Dictionary to create multiple buttons
values = {"RadioButton 1" : "1",
          "RadioButton 2" : "2",
          "RadioButton 3" : "3",
          "RadioButton 4" : "4",
          "RadioButton 5" : "5"}
 
# Loop is used to create multiple Radiobuttons
# rather than creating each button separately
for (text, value) in values.items():
    print(value)
    Radiobutton(window, text = text, variable = v,
                value = value, indicator = 0,
                command=cluck,
                background = "light blue").pack(fill = X, ipady = 5)



button1 = Button(window, text="samere", bg="blue",command=click,padx=length/30.)
button1.pack(side=LEFT)


entry= Entry(button1,font=("Adrial",40),text="5555555555555")
entry.pack(side=LEFT)

#LIST = TEXT positionned thanks to \n, => no command or special actions
listB= Listbox(window, bg="yellow")
listB.insert(1,"2")
listB.insert(2,"2")
listB.insert(1,"")
listB.config(height=listB.size())
listB.pack()


window.mainloop()

