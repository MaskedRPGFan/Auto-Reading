
[![](https://i.postimg.cc/Nj2mWwpw/Ko-fi-small.png)](https://ko-fi.com/maskedrpgfan)   [![](https://i.postimg.cc/MKTymBBH/Buy-Me-ACoffee-small.png)](https://buymeacoffee.com/maskedrpgfan)   [![](https://i.postimg.cc/28Knc5dw/Patreon-small.png)](https://www.patreon.com/maskedrpgfan)

<p align="center"><img src="https://github.com/user-attachments/assets/9211dd7b-6751-410b-b9e2-4c4bdb31f57a"  width="200" height="200" /></p>

# Auto Reading

## Introduction

SKSE plugin that automatically read all books from the player's inventory with a hotkey or spell. Lets you decide what type of book you will read.

## Features

* ➡️ Automatically read all books from the player's inventory with a hotkey.
* ➡️ Automatically read all books from the player's inventory with a spell.
* ➡️ Ability to choose the type of book to automatically read: normal book, skill book or spell book.
* ➡️ Ability to eat spell tomes after read.
* ➡️ Track the number of auto-read books.

## Requirements

* 🔗[Address Library for SKSE Plugins](https://www.nexusmods.com/skyrimspecialedition/mods/32444)
* 🔗[SkyUI](https://www.nexusmods.com/skyrimspecialedition/mods/12604)
* 🔗[MCM Helper](https://www.nexusmods.com/skyrimspecialedition/mods/53000)
* 🔗[Latest Microsoft Visual C++ Redistributable package](https://aka.ms/vs/17/release/vc_redist.x64.exe)

## Installation

You can install this mod during existing gameplay.

## Uninstallation

You can uninstall this mod anytime. It will not leave any data in your save file.

## How to use

Use a hotkey or spell to automatically read all books of the selected type from your inventory.

## Configuration

Using MCM/ini settings ⚒️, you can change these options:

* **Normal Book**: if enabled, will make **Auto Reading**  ability read all books that do not improve skills or teach spells. **Enabled** by default.
* **Skill  Book**: if enabled, will make **Auto Reading**  ability read all books that improve skills. **Enabled** by default.
* **Spell Book**: if enabled, will make **Auto Reading**  ability read all books that teach spells. **Enabled** by default.
* **Eat Spell Book**: if enabled, will make **Auto Reading**  ability **eat**  spell books after reading, removing them from the player's inventory. **Enabled** by default.
* **Add Spell**: if enabled, will add **Auto Reading**  spell to player spellbook. **Enabled** by default.
* **Notifications**: if enabled, displays notifications for each book that is auto read. It also displays information about eating a spell book. **Enabled** by default.
* **Hotkey**: if set, will allow you to use the **Auto Reading**  ability when you press the assigned hotkey. **Not set** by default.
* **Hotkey Restriction**: if set, will not allow you to use the **Auto Reading** hotkey outside player inventory. **Enabled** by default.

## Compatibility

Created with CommonLibSSE-NG for Skyrim SE, AE, and VR.

Current state of compatibility with other mods:
* ✅ [Missives](https://www.nexusmods.com/skyrimspecialedition/mods/17576)
* ✅ [Experience](https://www.nexusmods.com/skyrimspecialedition/mods/17751)

## Troubleshooting

I tested mod as much as I could and should be no problems, but if something is not working correctly, please use **[Bugs](https://www.nexusmods.com/skyrimspecialedition/mods/130553?tab=bugs)**  tab and create bug report ☠️:

* ✳️ Describe bug.
* ✳️ List steps to reproduce it.
* ✳️ Upload logs from the following locations to 🔗[Pastebin](https://pastebin.com/) and post link to it in bug report.
  * ➡️ **"[Path to My Documents]\My Games\Skyrim Special Edition\SKSE\skse64.log"**
  * ➡️ **"[Path to My Documents]\My Games\Skyrim Special Edition\SKSE\AutoReading.log"**
  * ➡️ **"[Path to My Documents]\My Games\Skyrim Special Edition\SKSE\MCMHelper.log"**
  * ➡️ **"[Path to My Documents]\My Games\Skyrim Special Edition\Logs\Script\Papyrus.0.log"**

## FAQ

### I do not need MCM, can I use only dll?

Yes. You can use just 3 files: dll, pdb and ini. Plugin, scripts and other files are just for MCM. Keep in mind that without MCM you will need to reload save to apply settings from ini file and you will lose ability to use spell.

## Credits

* The SKSE team for SKSE.
* meh321 for Address Library for SKSE Plugins
* Ryan-rsm-McKenzie, powerof3, CharmedBaryon, alandtse for various versions of CommonLibSSE.
* SkyUI Team for SkyUI.
* Parapets for MCM Helper.

## Permissions

This mod is open-source. I encourage you to learn from the [source files](https://github.com/MaskedRPGFan/Auto-Reading). If you want to add a new feature or change something, please submit a pull request on GitHub. If you have any questions or for any other matters, please feel free to contact me.
