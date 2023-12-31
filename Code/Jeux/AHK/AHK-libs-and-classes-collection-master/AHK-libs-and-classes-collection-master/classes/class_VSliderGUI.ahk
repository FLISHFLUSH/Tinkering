Class VSliderGUI {


    static bcolor := "090909" ;background color
    static pcolor := "E9E9E9" ;progressbar color
    static tcolor := "666666" ;text color
    
    
    __New(guiName, width, height, tsize, iconOffsetx, iconOffsety, bradius, y, transtarget, timeToDecay, playSound := 1){
        this.guiName := guiName
        this.width := width
        this.height := height
        this.tsize := tsize
        this.iconOffset := {"x": iconOffsetx, "y": iconOffsety}
        this.bradius := bradius
        this.y := y
        this.transtarget := transtarget
        this.timeToDecay := timeToDecay
        this.playSound := playSound
        this._registerGui()
        this._addControls()
        this._finaliseGui()
    }


    update(vol, icon){
        if(!this.vanishTimer)
            this.show(vol, icon)

        GuiControl, , % this.vol.slider, % vol
        GuiControl, , % this.vol.icon, % icon

        this._tempTimer(this.vanishTimer, this.timeToDecay, -1)
        if(this.playSound){
            if(!this.testVolTimer)
                this.testVolTimer := this._testVol.Bind(this)
            this._tempTimer(this.testVolTimer, this.timeToDecay * 0.6, -1)
        }
    }


    show(vol, icon){
        GuiControl, , % this.vol.slider, % vol
        GuiControl, , % this.vol.icon, % icon
        WinGetPos, , , width, height, % "ahk_id " . this.hwnd ; Get GUI info
        x := (A_ScreenWidth / 2) - (width / 2) ; Calculate true screen center
        Gui, % this.hwnd ":Show"
                , % "x" x 
                    . " y" . this.y
                    . " NA"
        WinSet, Region, % Format("0-0 w{1:d} h{2:d} r{3:d}-{3:d}"
                            , width
                            , height
                            , this.bradius) ; Apply rounded corners
                , % "ahk_id " . this.hwnd
        While(A_Index < 11
                , (x := this._transmation(this.transtarget, 10, A_Index))){
            Sleep, 1
            WinSet, Transparent, % x, % "ahk_id " . this.hwnd
        }

        this.vanishTimer := this.hide.Bind(this)
        this._tempTimer(this.vanishTimer, this.timeToDecay, -1)
    }


    hide(){
        While(A_Index < 11)
                , (x := this._transmation(this.transtarget, 10, 10 - A_Index)){
            WinSet, Transparent, % x, % "ahk_id " . this.hwnd
            Sleep, 1
        }
        WinSet, Transparent, 0, % "ahk_id " . this.hwnd
        Gui, % this.hwnd . ":Hide"
        this.vanishTimer := ""
    }


    _transmation(target, steps, x){
        return, Floor(target / steps * x)
    }


    _testVol(){
        SoundPlay, % A_WinDir . "\Media\Windows Background.wav"
        this.testVolTimer := ""
    }


    _tempTimer(timer, period, prio){
        SetTimer, % timer, % -Abs(period), % prio
    }


    ; -- helper methods for creating the instances gui --

    _registerGui(){
        Gui, % this.guiName ":New" ; create GUI with needed options
                , %  "+Hwndhwnd +LastFound +ToolWindow +AlwaysOnTop -Caption -Disabled"
                , this.guiName
        this.hwnd := hwnd
        DllCall("SetClassLong" ; Drop Shadow
                , "UInt", this.hwnd
                , "Int", -26
                , "Int", DllCall("GetClassLong"
                        , "UInt", this.hwnd
                        , "Int", -26) | 0x20000)
        Gui, % this.hwnd ":Color" ; setting background Color
                , this.tcolor, this.tcolor
    }


    _addControls(){
        Gui, % this.hwnd ":Add"
                , Progress
                , % "HwndVolSlider"
                    . " x" . -1
                    . " y" . -1
                    . " w" . this.width
                    . " h" . this.height
                    . " c" . this.pcolor
                    . " Background" this.bcolor
                , 50
        Gui, % this.hwnd ":Font"
                , % "s" . this.tsize . " c" . this.tcolor
                , Segoe MDL2 Assets
        Gui, % this.hwnd ":Add"
                , Text
                , % "BackgroundTrans" 
                    . " HwndVolIcon"
                    . " x" . this.iconOffset.x
                    . " y" . this.iconOffset.y
                , % ""
        Gui, % this.hwnd ":Margin", 0, 0

        this.vol := {}
        this.vol.slider := VolSlider
        this.vol.icon := VolIcon
    }


    _finaliseGui(){
        DetectHiddenWindows, On
        Gui, % this.hwnd ":Show", Hide ; Pre-render GUI
        WinSet, Transparent, 0, % "ahk_id " . this.hwnd ; Apply 0% transparency
    }


    ; -- other methods --

    __Delete(){
        Gui, % this.hwnd . ":Destroy"
    }


}