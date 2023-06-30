﻿; ===============================================================================================================================
; Function......: GetCurrentProcess
; DLL...........: Kernel32.dll
; Library.......: Kernel32.lib
; U/ANSI........:
; Author........: jNizM
; Modified......:
; Links.........: https://msdn.microsoft.com/en-us/library/ms683179.aspx
;                 https://msdn.microsoft.com/en-us/library/windows/desktop/ms683179.aspx
; ===============================================================================================================================
GetCurrentProcess()
{
    return DllCall("kernel32.dll\GetCurrentProcess")
}
; ===============================================================================================================================

MsgBox % GetCurrentProcess()





/* C++ ==========================================================================================================================
HANDLE WINAPI GetCurrentProcess(void);                                               // Ptr
============================================================================================================================== */