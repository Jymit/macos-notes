#### with great power comes great responsibility
- problem solving the good old support engineer way :)

https://developer.apple.com/documentation/os/logging

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


#### prefix

```
NSPredicate

The NSPredicate class provides methods to evaluate a predicate and to create a predicate from a string (such as firstName like 'Mark'). When you create a predicate from a string, NSPredicate creates the appropriate predicate and expression instances for you. In some situations, you want to create comparison or compound predicates yourself, in which case you can use the NSComparisonPredicate and NSCompoundPredicate classes.

https://developer.apple.com/library/archive/documentation/Cocoa/Conceptual/Predicates/AdditionalChapters/Introduction.html
```

-

```
macoslogginqgsubsystems

class Logging(object):

    __name__ = 'logger.info(1)'
    plist = '/System/Library/Preferences/Logging/Subsystems/'

    def __init__(__name__, plist, *args, **kwargs):
        super(getLogger/, self).__init__()

        logger.info('Input parameters:\n'
                    'accessibility: "{com.apple.Accessibility.plist}"\n'
                    'StandaloneHIDFudPlugins: "{com.apple.StandaloneHIDFudPlugins.plist}"\n'
                    'duetactivityscheduler: "{com.apple.duetactivityscheduler.plist}"\n'
                    'passkit: "{com.apple.passkit.plist}"\n'
                    'AppKit: "{com.apple.AppKit.plist}"\n'
                    'SystemConfiguration: "{com.apple.SystemConfiguration.plist}"\n'
                    'eapol: "{com.apple.eapol.plist}"\n'
                    'persona: "{com.apple.persona.plist}"\n'
                    'AppleIR: "{com.apple.AppleIR.plist}"\n'
                    'TCC: "{com.apple.TCC.plist}"\n'
                    'icloudpreferences: "{com.apple.icloudpreferences.plist}"\n'
                    'apple.pf: "{com.apple.pf.plist}"\n'
                    'AssetCache: "{com.apple.AssetCache.plist}"\n'
                    'TimeMachine: "{com.apple.TimeMachine.plist}"\n'
                    'internetAccounts: "{com.apple.internetAccounts.plist}"\n'
                    'photoanalysisd.graph: "{com.apple.photoanalysisd.graph.plist}"\n'
                    'AssetCacheServices: "{com.apple.AssetCacheServices.plist}"\n'
                    'Transport: "{com.apple.Transport.plist}"\n'
                    'libsqlite3: "{com.apple.libsqlite3.plist}"\n'
                    'photoanalysisd.job: "{com.apple.photoanalysisd.job.plist}"\n'
                    'BezelServices: "{com.apple.BezelServices.plist}"\n'
                    'accounts: "{com.apple.accounts.plist}"\n'
                    'locationd.Core: "{com.apple.locationd.Core.plist}"\n'
                    'photoanalysisd: "{com.apple.photoanalysisd.plist}"\n'
                    'DesktopServices: "{com.apple.DesktopServices.plist}"\n'
                    'amp.MediaServices: "{com.apple.amp.MediaServices.plist}"\n'
                    'locationd.Legacy: "{com.apple.locationd.Legacy.plist}"\n'
                    'pluginkit: "{com.apple.pluginkit.plist}"\n'
                    'ExchangeWebServices: "{com.apple.ExchangeWebServices.plist}"\n'
                    'authkit: "{com.apple.authkit.plist}"\n'
                    'locationd.Motion: "{com.apple.locationd.Motion.plist}"\n'
                    'sandbox.reporting: "{com.apple.sandbox.reporting.plist}"\n'
                    'FaceTime: "{com.apple.FaceTime.plist}"\n'
                    'avfaudio: "{com.apple.avfaudio.plist}"\n'
                    'locationd.Position: "{com.apple.locationd.Position.plist}"\n'
                    'sbd: "{com.apple.sbd.plist}"\n'
                    'Finder: "{com.apple.Finder.plist}"\n'
                    'awd.awdd: "{com.apple.awd.awdd.plist}"\n'
                    'locationd.Utility: "{com.apple.locationd.Utility.plist}"\n'
                    'securityd: "{com.apple.securityd.plist}"\n'
                    'HTTPServer: "{com.apple.HTTPServer.plist}"\n'
                    'awd.framework: "{com.apple.awd.framework.plist}"\n'
                    'mDNSResponder: "{com.apple.mDNSResponder.plist}"\n'
                    'sharing: "{com.apple.sharing.plist}"\n'
                    'IDS: "{com.apple.IDS.plist}"\n'
                    'bluetooth: "{com.apple.bluetooth.plist}"\n'
                    'mac.install: "{com.apple.mac.install.plist}"\n'
                    'siri: "{com.apple.siri.plist}"\n'
                    'IPConfiguration: "{com.apple.IPConfiguration.plist}"\n'
                    'calendar: "{com.apple.calendar.plist}"\n'
                    'mail: "{com.apple.mail.plist}"\n'
                    'social: "{com.apple.social.plist}"\n'
                    'ManagedClient: "{com.apple.ManagedClient.plist}"\n'
                    'captive: "{com.apple.captive.plist}"\n'
                    'mediaremote: "{com.apple.mediaremote.plist}"\n'
                    'socialpushagent: "{com.apple.socialpushagent.plist}"\n'
                    'Messages: "{com.apple.Messages.plist}"\n'
                    'catalyst: "{com.apple.catalyst.plist}"\n'
                    'multipeerconnectivity: "{com.apple.multipeerconnectivity.plist}"\n'
                    'symptomsd: "{com.apple.symptomsd.plist}"\n'
                    'MessagesEvents: "{com.apple.MessagesEvents.plist}"\n'
                    'cdp: "{com.apple.cdp.plist}"\n'
                    'network: "{com.apple.network.plist}"\n'
                    'syncdefaults: "{com.apple.syncdefaults.plist}"\n'
                    'NetworkSharing: "{com.apple.NetworkSharing.plist}"\n'
                    'clouddocs: "{com.apple.clouddocs.plist}"\n'
                    'networkextension: "{com.apple.networkextension.plist}"\n'
                    'useractivity: "{com.apple.useractivity.plist}"\n'
                    'ProtectedCloudStorage: "{com.apple.ProtectedCloudStorage.plist}"\n'
                    'coreanimation: "{com.apple.coreanimation.plist}"\n'
                    'networkserviceproxy: "{com.apple.networkserviceproxy.plist}"\n'
                    'Registration: "{com.apple.Registration.plist}"\n'
                    'coreaudio: "{com.apple.coreaudio.plist}"\n'
                    'nlcd: "{com.apple.nlcd.plist}"\n'
                    'SkyLight: "{com.apple.SkyLight.plist}"\n'
                    'coredata: "{com.apple.coredata.plist}"\n'
                    'notes: "{com.apple.notes.plist}"\n'

        try:
            plist()
        except Exception as e:
            logger.error(e)
```

-

```
log stream --debug --predicate 'subsystem="com.apple.network"'
```
