#SingleInstance, Force
SendMode Input
SetWorkingDir, %A_ScriptDir%
iOSVSliderProvider.initialize()
return

Volume_Mute::iOSVSliderProvider.volMute()
Volume_Up::iOSVSliderProvider.volUp(2, 8, 250)
Volume_Down::iOSVSliderProvider.volDown(2, 8, 250)



#Include, assets/iOSVSliderProvider.ahk