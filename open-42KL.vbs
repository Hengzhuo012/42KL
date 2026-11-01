Set WshShell = CreateObject("WScript.Shell")
WshShell.Run "cmd /c code --profile ""42KL"" --remote wsl+Ubuntu ""/mnt/d/Personal Folders/42KL""", 0, False
