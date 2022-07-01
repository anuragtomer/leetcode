on run argv
tell application "Reminders"
    set newremind to make new reminder
    set name to (item 1 of argv)
end tell
end run
