#NoEnv  ; Recommended for performance and compatibility with future AutoHotkey releases.
; #Warn  ; Enable warnings to assist with detecting common errors.
SendMode Input  ; Recommended for new scripts due to its superior speed and reliability.
SetWorkingDir %A_ScriptDir%  ; Ensures a consistent starting directory.


AutoTrim, on
#INCLUDE Factorio_Mouse_Zone.ahk


a:= {}
a:={max:2}
MsgBox,% ArrayPos[810]

 ;insert if reso = reso_x,reso_y ... blabla
 ;####### VARIABLES #######
  radius:=ArrayPos[radius]
  resoX:=1920
  resoY:=1020
  centre_x:=1920/2
  centre_y:=1020/2
  in_Vert_Cone:= False 
  in_Horiz_Cone:= False


  
  ;defining the dir of our Exclusive Top-bot-left-right movement   
  ;values are identical since our cones are symetric along the x / y axis
  
;some variables might be redundant
TopLeft:=-3
TopRight:=3
RightTop:=0.11
RightBottom:=-0.11
 
BottomRight:= TopLeft   ;different variables, same lines
LeftTop:=RightBottom   ;different variables, same lines
LeftBottom:= RightTop   ;different variables, same lines
BottomLeft:= TopRight   ;different variables, same lines
;##transform x & y using symetry rules for case where y < centre_y


;##1st check if in square, then check if inside circle then do the calculatioons
;
;
;Assumption: y > centre_y
papa:= 1
;########START CODE########
 #IfWinActive, ahk_class Factorio
            ;apparently, putting commands after endline doesn't behave the same
;^Lbutton::Send, {z Down}
;^Lbutton UP::Send {z UP}


 MouseGetPos, x, y, w, h
                  ;  distance:=  Abs(reso_y-centre_y - y)
test := x<SquareLBRT[1]
test := test || x>SquareLBRT[3]
test := test || y>SquareLBRT[2]
test := test || y<SquareLBRT[4]

if (test) ;
{
;#test if outside the circle
 if 1
  {
   ; turning x & y into coordinates
   y_coord:= resoY-y-centre_y
   x_coord:= x-centre_x
  leadingCoeff:= y_coord/x_coord
  ;MsgBox, %leadingCoeff%  %y_coord% %x_coord% 
  in_Vert_Cone:= 1 ;TopRight > leadingCoeff
  in_Horiz_Cone:= RightTop < leadingCoeff
  ;MsgBox, %in_Vert_Cone% V   %in_Horiz_Cone% H 
  if (0) ;
    {
    ~Lbutton::Send, {z Down}
	~Lbutton UP::Send {z UP}
    }
  else ;
   if (1)
   Lbutton::Send, {s Down}
	~Lbutton UP::Send {s UP}
    {
    ;Send {down}
    }
  }  
}
else ;
{

}
r:=centre_y+radius
 ; MsgBox,  %y% + %r%


;opposite part
;
;
;


Line1:=0
Line2:=0
  
;###########END CODE###########