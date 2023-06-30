#NoEnv  ; Recommended for performance and compatibility with future AutoHotkey releases.
; #Warn  ; Enable warnings to assist with detecting common errors.
SendMode Input  ; Recommended for new scripts due to its superior speed and reliability.
SetWorkingDir %A_ScriptDir%  ; Ensures a consistent starting directory.
#INCLUDE Factorio_Mouse_Zone.ahk

In_Cone_Vert:= 0
In_Cone_Horiz:= 0

;####Functions#### ; X & y are COORD, not pixel locationµµµµ
InsideSquare_r(radius)
{
test := x<radius
test := test || x>radius
test := test || y>radius
test := test || y<radius

return test
}
InUpperDemiCircle_y_cy(y,centre_y)
{
return y>0
}

toCoord_y_ry(y,reso_y)
{
return reso_y-y
}
InsideDemiCircle_x_y_dc(x,y, Demicircle)
{
return (demiCircle[x]>y)
}

;####End_Functions####
;####VARIABLES###
a:= {}
a:={max:2}
MsgBox,% ArrayPos[210]

 radius:=ArrayPos[radius]
  resoX:=1920
  resoY:=1020
  centre_x:=1920/2
  centre_y:=1020/2
  in_Vert_Cone:= False 
  in_Horiz_Cone:= False

TopLeft:=-3
TopRight:=3
RightTop:=0.11
RightBottom:=-0.11
;####end_VARIABLES####

~^Lbutton::
 MouseGetPos, x, y, w, h
y:= resoY - y -centre_y
x:= x- centre_x
MsgBox, %x% %y%

if(InsideSquare_r(radius))
MsgBox, saucisson
{
 if (!InUpperDemiCircle_y_cy(y,centre_y))
 {
  coordx:=-coordx
  coordy:=-coordy
MsgBox, %x% %y% upper DC
 }
 if (InsideDemiCircle_x_y_dc(x,coordy,ArrayPos))
 { 
  MsgBox, %x% %y% %centre_y% inside DC






















































 }
}
;Inside_if (button pressed)_search if inside square_if no if inside circle_if no search if up or down_if down, change value_else calculate leaing coeff_compare value to determine if in Vert or Horiz_loop_{_The_Send TheRIghtKey_}__