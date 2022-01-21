## My macOS inscriptions

Jymit [The macos security researcher](https://github.com/Jymit/macos-notes/blob/main/mac_security_researcher.md).

Exploit readings, findings and mitigations over @ [readme](https://github.com/Jymit/exploit-notes/blob/main/readme.md).

## Useful tooling

[Browser History Parser](https://github.com/cedowens/macOS-browserhist-parser/tree/master/parse-browser-history)

[some macOS Offensive Tools](https://github.com/xorrior/macOSTools)

[in-memory mach-o code](https://github.com/its-a-feature/macos_execute_from_memory)

## to read

https://themittenmac.com/low-level-process-hunting-on-macos/

## Ive played with

and will comment more on as time goes on

Persistence on mac [KnockKnock](https://objective-see.com/products/knockknock.html)

Vid & Mic Spyware on mac [OverSight](https://objective-see.com/products/oversight.html)

by Patrick Wardle, Creator of http://Objective-See.com - whoop whoop.

## The good stuff

The learnings 

## Mach-O

Mach-O, short for Mach object file format, is a file format for executables, object code, shared libraries, dynamically-loaded code, and core dumps. It was developed to replace the a. out format. Mach-O is used by most systems based on the Mach kernel.

A Unix-like operating system developed at Carnegie-Mellon University in the period between 1985 and 1994. The Mach kernel was designed with a microkernel architecture that makes it easily portable to different platforms. Operating systems based on Mach include NextStep, OSF/1 and macOS.

## MACL

com.apple.macl

The obscure feature, a hidden part of MacOS that underpins Apple’s concept of User-Intent, a shift in focus for MacOS privacy controls in an attempt to stop endless prompts interrupting the user.

The MACL attribute usually consists of a header value of 02 00 followed by a UUID corresponding to the application permitted to access the file. The UUID is unique for each system, user and application meaning that we can’t preempt what this value will be in advance.

xattr -l file1

## Dylib

Dynamic Library, The Mach-O object file format used by Mac OS X for executables and libraries distinguishes between shared libraries and dynamically loaded modules. Use otool -hv some_file to see the filetype of some_file.

https://developer.apple.com/library/archive/documentation/DeveloperTools/Conceptual/DynamicLibraries/100-Articles/OverviewOfDynamicLibraries.html

## MACF

Mandatory Access Control Framework - commonly referred to as MACF.

In a nutshell Mandatory Access Control Framework (MACF) is a private kernel framework that allows Apple kexts to hook a myriad of (MACF) operations. Such hook (or callbacks) will then be invoked automatically by the kernel proper, and thus afford the kext (who registered the hook) the opportunity to a take a action …for example, to examine and block untrusted processes! Taken from Patricks Wardles Obj-See writeup on [Where's the Interpreter!?](https://objective-see.com/blog/blog_0x6A.html)

More about macf and code around that soon...

## KAuth

Mac OS X 10.4 Tiger introduced a new kernel subsystem, Kernel Authorization or Kauth for short, for managing authorization within the kernel. The Kauth subsystem exports a kernel programming interface (KPI) that allows third party kernel developers to authorize actions within the kernel, modify authorization decisions, and extend the kernel's authorization landscape. It can also be used as a notification mechanism.

[KAuth apple doc](https://developer.apple.com/library/archive/technotes/tn2127/_index.html)

- [Monitoring Process Creation via the Kernel (Part II)](https://objective-see.com/blog/blog_0x0A.html)

## Other
### DiskArbitration
A system wide service @ /System/Library/LaunchDaemons/com.apple.diskarbitrationd.plist
com.apple.DiskArbitration.diskarbitrationd (XPC)
It manages disk mounting, unmounting
It calls mount/unmount syscalls under the hood
Goodies
- runs as root
- unsandboxed
- XPC service accessible from application sandbox
- opensource

### app

App Sandbox Entitlement
A Boolean value that indicates whether the app may use access control technology to contain damage to the system and user data if an app is compromised.
Key: com.apple.security.app-sandbox

com.apple.security.network.server
A Boolean value indicating whether your app may listen for incoming network connections.

com.apple.security.network.client
A Boolean value indicating whether your app may open outgoing network connections.

com.apple.security.device.microphone
A Boolean value that indicates whether the app may use the microphone.

com.apple.security.device.usb
A Boolean value indicating whether your app may interact with USB devices.

com.apple.security.device.bluetooth
A Boolean value indicating whether your app may interact with Bluetooth devices.

Location Entitlement
A Boolean value that indicates whether the app may access location information from Location Services.
Key: com.apple.security.personal-information.location

All Files Entitlement (Deprecated)
A Boolean value that indicates whether the app may have access to all files.
Key: com.apple.security.files.all

com.apple.security.files.user-selected.read-write
A Boolean value that indicates whether the app may have read-write access to files the user has selected using an Open or Save dialog.






## mac acronyms, keywords

SIP - System Integrity Protection

TCC - Transparency, Consent, and Control

user space -> req access to file -> kernel space -> TCC -> Validate Code Signing requirement

NSAppTransportSecurity - ATS https://developer.apple.com/documentation/bundleresources/information_property_list/nsapptransportsecurity


## The CLI stuff

## get ssid 
/System/Library/PrivateFrameworks/Apple80211.framework/Resources/airport -I

/System/Library/PrivateFrameworks/Apple80211.framework/Resources/airport -I  | awk -F' SSID: '  '/ SSID: / {print $2}'

## list system_profiler DataTypes
system_profiler -listDataTypes

system_profiler SPBluetoothDataType

system_profiler SPFirewallDataType

system_profiler SPAirPortDataType

## get users
dscl . list /Users | grep -v _

## Hardened Runtime

The Hardened Runtime, along with System Integrity Protection (SIP), protects the runtime integrity of your software by preventing certain classes of exploits, like code injection, dynamically linked library (DLL) hijacking, and process memory space tampering.

- https://developer.apple.com/documentation/security/hardened_runtime

codesign -d -vv Atom.app

```
flags=0x10000(runtime)
```

````
Latest Code Signature Format
````
macOS 11 and later will sign app bundles with the new signature format that include the DER entitlements by default. Check whether an app has the new signature

codesign -dvv Jamf.app

Look in the output for a string such as `CodeDirectory v=20500`. For any value of v less than 20400, you need to re-sign your app.

You can control how your signed code loads signed plug-ins and other signed code without invalidating the signatures of the host code or of the guest (dynamically loaded) code.

## notarization

Notarization gives users more confidence that the Developer ID-signed software you distribute has been checked by Apple for malicious components. Notarization is not App Review. The Apple notary service is an automated system that scans your software for malicious content, checks for code-signing issues, and returns the results to you quickly. If there are no issues, the notary service generates a ticket for you to staple to your software; the notary service also publishes that ticket online where Gatekeeper can find it. [docs link](https://developer.apple.com/documentation/security/notarizing_macos_software_before_distribution)

You can notarize several different types of software deliverables, including:

- macOS apps
- Non-app bundles, such as kernel extensions
- Disk images (UDIF format)
- Flat installer packages

Note: Beginning in macOS 10.14.5, software signed with a new Developer ID certificate and all new or updated kernel extensions must be notarized to run. Beginning in macOS 10.15, all software built after June 1, 2019, and distributed with Developer ID must be notarized. However, you aren’t required to notarize software that you distribute through the Mac App Store because the App Store submission process already includes equivalent security checks.

Additionally, you can use the spctl utility to determine if the software to be notarized will run with the system policies currently in effect.

% spctl -vvv --assess --type exec /path/to/application

### secure timestamp

You can no longer build a release without an internet connection. Secure timestamps for codesign need to be turned on. Generating a secure timestamp requires internet access. macOS accepts only one secure timestamp server, namely timestamp.apple.com, which uses the follow address ranges:
- 17.32.213.0/24
- 17.179.249.0/24
- 17.157.80.0/24

You can check if a binary has a secure timestamp with the following command

% codesign -dvv Jamf.app

The presence of Signed Time in the output indicates the binary doesn’t have a secure timestamp.

### com.apple.security.get-task-allow entitlement

This entitlement facilitates debugging on a system that uses System Integrity Protection (SIP) by circumventing certain security checks.

However, this poses a security risk for a shipping app, because it can allow an attacker to inject code at runtime. As a result, Xcode automatically strips the entitlement from your app when you export and sign it using the standard workflow.

If you use a custom workflow and fail to remove the com.apple.security.get-task-allow entitlement, notarization fails with the following message: The executable requests the com.apple.security.get-task-allow entitlement.

## System Integrity Protection (SIP)

System Integrity Protection is a security technology in OS X El Capitan and later that's designed to help prevent potentially malicious software from modifying protected files and folders on your Mac. System Integrity Protection restricts the root user account and limits the actions that the root user can perform on protected parts of the Mac operating system.

System Integrity Protection is designed to allow modification of these protected parts only by processes that are signed by Apple and have special entitlements to write to system files, such as Apple software updates and Apple installers. Apps that you download from the Mac App Store already work with System Integrity Protection. 

```
System Integrity Protection includes protection for these parts of the system:

/System
/usr
/bin
/sbin
/var
Apps that are pre-installed with OS X
Paths and apps that third-party apps and installers can continue to write to include:

/Applications
/Library
/usr/local
```
```
To disable SIP, do the following:

- Restart your computer in Recovery mode.
- Launch Terminal from the Utilities menu.
- Run the command % csrutil disable
- Restart your computer.


Disable SIP only temporarily to perform necessary tasks, and reenable it as soon as possible. Failure to reenable SIP when you are done testing leaves your computer vulnerable to malicious code.

Same steps as above except % csrutil enable
```

## d2d

xattr -- display and manipulate extended attributes https://ss64.com/osx/xattr.html

codesign -- Create and manipulate code signatures

plutil -- property list utility

spctl -- SecAssessment 
policy security

csrutil -- Configure system security policies
csrutil modifies System Integrity Protection settings.  Some of the commands require the device to be booted into the Recovery OS. [man page](https://www.manpagez.com/man/1/codesign/)

otool -- lvm-otool, the otool-compatible command line parser for llvm-objdump

## CVEs Vulns

CVEs im going to research and write notes about, not limited to just these.
```
CVE-2020-27937, CVE-2020-29621, CVE-2020-10006, CVE-2020-24259, CVE-2020-9771, CVE-2021-1784, CVE-2021-30751, CVE-2020-9963, CVE-2021-1803, CVE-2021-1781, CVE-2021-30750, many more to read, understand and write about.
CVE-2021-30970
```

[MacOS/IOS Vulnerabilities and Exploitations.](https://github.com/hetmehtaa/Mac_Vuln)

