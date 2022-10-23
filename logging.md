#### with great power comes great responsibility
- problem solving the support engineer way :)

Pre 10.12 ASl and syslog logging: https://crucialsecurity.wordpress.com/2011/06/22/the-apple-system-log-%E2%80%93-part-1/
macOS 10.12+ the switch to what "unified logging" happened, now Logs are stored in tracev3 format. https://developer.apple.com/documentation/os/logging

```
ASL in 10.4, /private/var/log/asl.log
ASL in 10.5 to 10.5.6: /private/var/log/asl.db in binary format
syslog –f /private/var/log/asl.db
ASL after 10.5.6 is found /private/var/log/asl/
syslog –d /private/var/log/asl
```

```
watch the stream:

% log stream

specific:

% log stream --predicate 'eventMessage contains "Twitter"'

search saved logs:

log show --predicate 'eventMessage contains "Hello Logs"' --last 3m

Predicates!

subsystem - Look in /System/Library/Preferences/Logging/Subsystems/ macOS 11.6 there are 247 files in that location

```


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
/System/Library/Preferences/Logging/Subsystems
macOS 11.7 250 to date
```
```
com.apple.AVConference.plist
com.apple.AVConferenceFramework.plist
com.apple.Accessibility.plist
com.apple.AccessibilityPerformance.plist
com.apple.AppKit.plist
com.apple.AppleIR.plist
com.apple.AppleMediaServices.plist
com.apple.AppleServiceToolkit.plist
com.apple.AquaAppearanceHelper.logging.plist
com.apple.AssetCache.plist
com.apple.AssetCacheServices.plist
com.apple.BackBoardServices.fence.plist
com.apple.BaseBoard.plist
com.apple.BezelServices.plist
com.apple.BoardServices.plist
com.apple.BootPolicy.plist
com.apple.CFNetwork.plist
com.apple.CarbonCore.plist
com.apple.ClassKit.plist
com.apple.ConditionInducer.HighSeverity.plist
com.apple.ConditionInducer.LowSeverity.plist
com.apple.ConditionInducer.MediumSeverity.plist
com.apple.CoreAnalytics.stability-event.plist
com.apple.CoreDisplay.plist
com.apple.CoreML.plist
com.apple.CoreRoutine.plist
com.apple.DataDeliveryServices.plist
com.apple.DesktopServices.plist
com.apple.DiagnosticPipeline.plist
com.apple.DumpPanic.plist
com.apple.EnergyTracing.plist
com.apple.ExchangeWebServices.plist
com.apple.FileProvider.plist
com.apple.Finder.plist
com.apple.Foundation.plist
com.apple.FrontBoard.plist
com.apple.FrontBoard.workspace.plist
com.apple.GameKit.plist
com.apple.GeoAnalytics.plist
com.apple.GeoServices.Logging.plist
com.apple.GeoServices.plist
com.apple.HMFoundation.plist
com.apple.HTTPServer.plist
com.apple.HealthKit.plist
com.apple.Home.plist
com.apple.HomeKit.plist
com.apple.IPConfiguration.plist
com.apple.InputTranscoder.plist
com.apple.LanguageModeling.plist
com.apple.ManagedClient.plist
com.apple.ManagedConfiguration.plist
com.apple.Maps.RequestResponse.plist
com.apple.Maps.Suggestions.plist
com.apple.Maps.plist
com.apple.MessageSecurity.plist
com.apple.Messages.telemetry.plist
com.apple.MobileSoftwareUpdate.plist
com.apple.Multitouch.plist
com.apple.Navigation.plist
com.apple.NetworkSharing.plist
com.apple.NewDeviceOutreach.plist
com.apple.PerformanceAnalysis.plist
com.apple.PlugInKit.plist
com.apple.ProtectedCloudStorage.plist
com.apple.RealityKit.plist
com.apple.ReportMemoryException.plist
com.apple.Sentry.Framework.Lifecycle.plist
com.apple.Sentry.FrameworkSignposts.plist
com.apple.ShareSheet.plist
com.apple.SkyLight.plist
com.apple.SoftwareUpdate.plist
com.apple.SoftwareUpdateMacController.plist
com.apple.StandaloneHIDFudPlugins.plist
com.apple.StoreServices.accounts.plist
com.apple.StoreServices.plist
com.apple.SystemConfiguration.plist
com.apple.TextInput.plist
com.apple.TimeMachine.plist
com.apple.ToneLibrary.plist
com.apple.Translation.plist
com.apple.Transparency.plist
com.apple.UserNotifications.plist
com.apple.UserNotificationsUI.plist
com.apple.VectorKit.GeoGL.plist
com.apple.VectorKit.plist
com.apple.WirelessRadioManager.Coex.plist
com.apple.WirelessRadioManager.iRAT.plist
com.apple.accessories.core.iap1.plist
com.apple.accessories.core.iap2.plist
com.apple.accessories.core.plist
com.apple.accessories.feature-plugins.plist
com.apple.accessories.frameworks.plist
com.apple.accessories.platform-plugins.plist
com.apple.accessories.plist
com.apple.accessories.transport-plugins.plist
com.apple.accounts.plist
com.apple.amp.MediaServices.plist
com.apple.amp.iTunesCloud.plist
com.apple.amp.inappmessages.plist
com.apple.amp.itunescloudd.plist
com.apple.amp.mediaplaybackcore.plist
com.apple.amp.mediaplayer.plist
com.apple.amp.mediaremote.plist
com.apple.app_launch_measurement.plist
com.apple.appinstallation.plist
com.apple.appleaccount.plist
com.apple.appleevents.plist
com.apple.appleidauthentication.plist
com.apple.appstored.plist
com.apple.appstorefoundation.plist
com.apple.authkit.plist
com.apple.avatar.AvatarUI.plist
com.apple.avfaudio.plist
com.apple.awd.awdd.plist
com.apple.awd.framework.plist
com.apple.bluetooth.plist
com.apple.calendar.plist
com.apple.calls.intenthandler.plist
com.apple.captive.plist
com.apple.catalyst.plist
com.apple.cdp.plist
com.apple.classroom.plist
com.apple.clouddocs.plist
com.apple.cmio.plist
com.apple.contacts.autocomplete.plist
com.apple.contacts.carddav.plist
com.apple.containermanager.plist
com.apple.coreanimation.plist
com.apple.coreaudio.plist
com.apple.corecaptured.plist
com.apple.coredata.plist
com.apple.coremedia.plist
com.apple.corerepair.plist
com.apple.coreservicesstore.plist
com.apple.dasd.signpost.plist
com.apple.defaults.plist
com.apple.display.reconfig.plist
com.apple.duetactivityscheduler.plist
com.apple.eapol.plist
com.apple.email.signposts.plist
com.apple.eventkitui.plist
com.apple.family.plist
com.apple.followup.plist
com.apple.frontboard.applibrary.plist
com.apple.greentea.plist
com.apple.icloud.fmfd.plist
com.apple.icloudpreferences.plist
com.apple.inputmethodkit-perf.plist
com.apple.installcoordination.plist
com.apple.internetAccounts.plist
com.apple.iohid.plist
com.apple.kernelmanagerd.logging.plist
com.apple.kext.plist
com.apple.kvs.plist
com.apple.launchd.helper.plist
com.apple.launchservices.plist
com.apple.libktrace.plist
com.apple.libsqlite3.plist
com.apple.lightsoutmanagementd.plist
com.apple.locationd.Core.plist
com.apple.locationd.Legacy.plist
com.apple.locationd.Motion.plist
com.apple.locationd.Position.plist
com.apple.locationd.Utility.plist
com.apple.loginwindow.Lifecycle.plist
com.apple.loginwindow.logging.plist
com.apple.mDNSResponder.plist
com.apple.mac.install.plist
com.apple.mail.plist
com.apple.mecabra.plist
com.apple.metrickit.log.plist
com.apple.mobileaccessoryupdater.plist
com.apple.mobileactivationd.plist
com.apple.mobileassetd.plist
com.apple.mobilenotes.plist
com.apple.mobiletimer.logging.plist
com.apple.multipeerconnectivity.plist
com.apple.network.plist
com.apple.networkextension.plist
com.apple.networkserviceproxy.plist
com.apple.networkstatistics.plist
com.apple.nfc.signpost.plist
com.apple.nlcd.plist
com.apple.notes.plist
com.apple.opendirectoryd-installer.plist
com.apple.opendirectoryd.plist
com.apple.osanalytics.preoslog.plist
com.apple.parsec-fbf.plist
com.apple.parsecd.plist
com.apple.passkit.plist
com.apple.pencilkit.plist
com.apple.persona.plist
com.apple.pf.plist
com.apple.photoanalysisd.graph.plist
com.apple.photoanalysisd.job.plist
com.apple.photoanalysisd.plist
com.apple.photoanalysisd.presentation.plist
com.apple.photos.Neutrino.plist
com.apple.photos.backend.plist
com.apple.photos.cpl.plist
com.apple.photos.plist
com.apple.photos.ui.export.plist
com.apple.photos.ui.plist
com.apple.powerui.smartcharging.plist
com.apple.proactive.PersonalizationPortrait.Signposts.plist
com.apple.proactive.PersonalizationPortrait.plist
com.apple.revisiond.plist
com.apple.runningboard.plist
com.apple.sandbox.reporting.plist
com.apple.sbd.plist
com.apple.scenekit.plist
com.apple.security.ckks.plist
com.apple.security.libcryptex.plist
com.apple.security.trustedpeers.plist
com.apple.securityd.plist
com.apple.sharing.plist
com.apple.shfuc.plist
com.apple.shortcuts.plist
com.apple.siri.DialogEngine.plist
com.apple.siri.SiriDialogEngine.plist
com.apple.siri.audio.plist
com.apple.siri.findmy.plist
com.apple.siri.homeautomation.plist
com.apple.siri.inference.plist
com.apple.siri.messages.plist
com.apple.siri.phone.plist
com.apple.siri.playbackcontrols.plist
com.apple.siri.plist
com.apple.siri.sirikit.plist
com.apple.siri.video.plist
com.apple.social.plist
com.apple.spindump.plist
com.apple.spotlight.performance.plist
com.apple.spotlight.trace.plist
com.apple.stocks.plist
com.apple.su.plist
com.apple.suggestions.plist
com.apple.symptomsd.NWActivityHelper.plist
com.apple.symptomsd.plist
com.apple.symptomstool.plist
com.apple.syncdefaults.plist
com.apple.syspolicy.plist
com.apple.tailspin.plist
com.apple.timed.plist
com.apple.triald.plist
com.apple.useractivity.plist
com.apple.watchkit.plist
```
-
```
log stream --debug --predicate 'subsystem="com.apple.network"'
```
