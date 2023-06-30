#NoEnv  ; Recommended for performance and compatibility with future AutoHotkey releases.
; #Warn  ; Enable warnings to assist with detecting common errors.
SendMode Input  ; Recommended for new scripts due to its superior speed and reliability.
SetWorkingDir %A_ScriptDir%  ; Ensures a consistent starting directory.

boxStatus=0 ;(main menu)



yClick(Horiz_Reso=1080){
return 700
}
mustacheMan=0;
mustacheMan_x=0;
mustacheMan_y=200
box1_Spam_x:= xClick()+MustacheMan*mustacheMan_x
box1_Spam_y:= yclick()+MustacheMan*mustacheMan_y

 ;SetDefaultMouseSpeed, 0 ; Move the mouse instantly.

!LButton::
MouseGetPos, xpos, ypos 
MsgBox,
(
x:%xpos% 
y:%ypos%
)
return

box1_spam:
Loop, 30
{
Click, box1_Spam_x, box1_Spam_y
/* Same speed, approximatively. Upcomiong lines useless
Click, 1500, 700
Click, 700, 900
Click, 1500, 900
*/
}
}

