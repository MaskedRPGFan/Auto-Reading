ScriptName AutoReadingMCMScript Extends MCM_ConfigBase

;--- Functions ------------------------------------------------------------

; Returns version of this script.
Int Function GetVersion()
    return 1 ;MCM Helper
EndFunction 

; Called when this config menu is closed.
Event OnConfigClose()
    parent.OnConfigClose()
    AutoReading.LoadSettings()
EndEvent

; Called when a new page is selected, including the initial empty page.
Event OnPageSelect(String a_page)
    parent.OnPageSelect(a_page)
    If CurrentPage == "$General_Page"
        AddTextOption("$NormalBook", AutoReading.GetNormalBooks())
        AddTextOption("$SkillBook", AutoReading.GetSkillBooks())
        AddTextOption("$SpellBook", AutoReading.GetSpellBooks())
    EndIf
EndEvent

; Called when game is reloaded.
Event OnGameReload()
    parent.OnGameReload()
    If GetModSettingBool("bLoadSettingsonReload:Maintenance")
        LoadSettings()
        VerboseMessage("OnGameReload: Settings autoloaded!")
    EndIf
EndEvent

; Called when this config menu is opened.
Event OnConfigOpen()
    parent.OnConfigOpen()
    SetModSettingString("sAutoReading:SKSEDLL", AutoReading.Version())
EndEvent

; Called when this config menu is initialized.
Event OnConfigInit()
    parent.OnConfigInit()
    LoadSettings()
EndEvent

; Called when setting changed to different value.
Event OnSettingChange(String a_ID)
    parent.OnSettingChange(a_ID)
    If a_ID == "bAddSpell:General"
        AutoReading.SetSpell()
    EndIf
EndEvent

Function Default()
    SetModSettingBool("bNormalBook:General", True)
    SetModSettingBool("bSkillBook:General", True)
    SetModSettingBool("bSpellBook:General", True)
    SetModSettingBool("bEatSpellBook:General", True)
    SetModSettingBool("bAddSpell:General", True)
    SetModSettingBool("bNotifications:General", True)
    SetModSettingInt("iHotkey:General", -1)
    SetModSettingBool("bHotkeyRestricted:General", True)
    SetModSettingBool("bEnabled:Maintenance", True)
    SetModSettingInt("iLoadingDelay:Maintenance", 0)
    SetModSettingBool("bLoadSettingsonReload:Maintenance", False)
    SetModSettingBool("bVerbose:Maintenance", False)
    SetModSettingBool("bDebugMode:Maintenance", False)
    VerboseMessage("Settings reset!")
    Load()
EndFunction

Function Load()
    AutoReading.LoadSettings()
    AutoReading.SetSpell()
    VerboseMessage("Settings applied!")
EndFunction

Function LoadSettings()
    If GetModSettingBool("bEnabled:Maintenance") == false
        return
    EndIf
    Utility.Wait(GetModSettingInt("iLoadingDelay:Maintenance"))
    VerboseMessage("Settings autoloaded!")
    Load()
EndFunction

Function VerboseMessage(String m)
    Debug.Trace("[Auto Reading] " + m)
    If GetModSettingBool("bVerbose:Maintenance")
        Debug.Notification("[Auto Reading] " + m)
    EndIf
EndFunction
