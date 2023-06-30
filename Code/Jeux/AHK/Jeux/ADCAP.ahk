#NoEnv  ; Recommended for performance and compatibility with future AutoHotkey releases.
; #Warn  ; Enable warnings to assist with detecting common errors.
SendMode Input  ; Recommended for new scripts due to its superior speed and reliability.
SetWorkingDir %A_ScriptDir%  ; Ensures a consistent starting directory.
lolo:=0

^RButton::
tudud:= "lulu"
MsgBox, % tudud
tudu%tudud%:="lala"
MsgBox, % tudululu


^w:: 
If (true){
lolo++
;WinGetActiveStats, Title, Width, Height, X, Y
;MsgBox, %X% %Y	%
}

Loop, 2
 {
MsgBox, %A_INdex%
}

WinGetTitle, title, A
MsgBox, "%title%"
If (winActive("AdCap!")) ; requiert les guillemets
MsgBox, lala
return

^LButton::
MouseGetPos, xpos, ypos 
MsgBox,
(
x:%xpos% 
y:%ypos%
)
return

;TAILLE FENETRE VERTICALE: RESO-30px
;1680: x675 y320

fonction qui prend une reso et renvoie des coord
xF() et yF()
fonction qui loop la sequence

f