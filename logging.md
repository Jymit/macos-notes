#### with great power comes great responsibility
- problem solving the good ol fashioned support engineer way :)

```
% log stream --debug --predicate 'subsystem="com.objective-see.oversight"'
```
```
Timestamp                       Thread     Type        Activity             PID    TTL  
2022-01-12 13:37:04.302185+0000 0x705f3f   Debug       0x0                  40281  0    OverSight: [com.objective-see.oversight:application] started: /Applications/OverSight.app/Contents/MacOS/OverSight (pid: 40281 / uid: 502)
2022-01-12 13:37:04.302613+0000 0x705f3f   Debug       0x0                  40281  0    OverSight: [com.objective-see.oversight:application] arguments: (
    "/Applications/OverSight.app/Contents/MacOS/OverSight"
)
.
.
```

```
Gather all available System logs.
gzcat /private/var/log/system.log.{9..0}.gz > ~/Downloads/system_all.log
cat /private/var/log/system.log >> ~/Downloads/system_all.log
```
```
Show if screen is locked or not
log show --predicate 'eventMessage contains "com.apple.sessionagent.screenIs"'

Show how screen was unlocked
log show --predicate 'eventMessage contains "LWScreenLockAuthentication"'

Show screenlocks, logouts, reboot; look for com.apple.[shutdownInitiated | logoutcancelled | restartinitiated]
log show --predicate 'eventMessage contains "SessionAgentNotificationCenter"'

Privilege Escalation, sudo
log show --predicate '(process == "su" or process == "sudo") and eventMessage contains "TTY="'
```
