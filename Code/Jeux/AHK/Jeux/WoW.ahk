random
#NoEnv  ; Recommended for performance and compatibility with future AutoHotkey releases.
; #Warn  ; Enable warnings to assist with detecting common errors.
SendMode Input  ; Recommended for new scripts due to its superior speed and reliability.
SetWorkingDir %A_ScriptDir%  ; Ensures a consistent starting directory.

$Mbutton::
Send {Mbutton}
BreakLoop:=0
return
;BreakLoop:= Mod(BreakLoop+=1,2) ; FONCTIONNE
;MsgBox,% BreakLoop

If (WinActive("World of Warcraft"))
{
+Mbutton::
BreakLoop :=1
;MsgBox,% BreakLoop


/*

*/
 while BreakLoop
{
 time:=0S
 ;ControlSend,, w, World of Warcraft
 Random, randomDelay,0,10
 time:= 100 + 80*RandomDelay
  Send, {w}
  sleep, %time%
}        
 return
 }