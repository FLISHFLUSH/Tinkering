
#NoEnv  ; Recommended for performance and compatibility with future AutoHotkey releases.
; #Warn  ; Enable warnings to assist with detecting common errors.
SendMode Input  ; Recommended for new scripts due to its superior speed and reliability.
SetWorkingDir %A_ScriptDir%  ; Ensures a consistent starting directory.
DrawLine(hdc, rX1, rY1, rX2, rY2) {																			;-- used DLLCall to draw a line

	DllCall("MoveToEx", Int, hdc, Int, rX1, Int, rY1, UInt, 0)
	DllCall("LineTo", Int, hdc, Int, rX2, Int, rY2)

} ;</05.01.000013>
DrawLine(hdc, 50, 50, 50, 50)