# macos-notes

Mach-O

Mach-O, short for Mach object file format, is a file format for executables, object code, shared libraries, dynamically-loaded code, and core dumps. It was developed to replace the a. out format. Mach-O is used by most systems based on the Mach kernel.

A Unix-like operating system developed at Carnegie-Mellon University in the period between 1985 and 1994. The Mach kernel was designed with a microkernel architecture that makes it easily portable to different platforms. Operating systems based on Mach include NextStep, OSF/1 and macOS.

MACL

com.apple.macl

The obscure feature, a hidden part of MacOS that underpins Apple’s concept of User-Intent, a shift in focus for MacOS privacy controls in an attempt to stop endless prompts interrupting the user.

The MACL attribute usually consists of a header value of 02 00 followed by a UUID corresponding to the application permitted to access the file. The UUID is unique for each system, user and application meaning that we can’t preempt what this value will be in advance.

xattr -l file1

Dylib

Dynamic Library, The Mach-O object file format used by Mac OS X for executables and libraries distinguishes between shared libraries and dynamically loaded modules. Use otool -hv some_file to see the filetype of some_file.

https://developer.apple.com/library/archive/documentation/DeveloperTools/Conceptual/DynamicLibraries/100-Articles/OverviewOfDynamicLibraries.html





# macos security

SIP - System Integrity Protection

TCC - Transparency, Consent, and Control

user space -> req access to file -> kernel space -> TCC -> Validate Code Signing requirement


# get ssid 
/System/Library/PrivateFrameworks/Apple80211.framework/Resources/airport -I

/System/Library/PrivateFrameworks/Apple80211.framework/Resources/airport -I  | awk -F' SSID: '  '/ SSID: / {print $2}'

# list system_profiler DataTypes
system_profiler -listDataTypes

system_profiler SPBluetoothDataType

system_profiler SPFirewallDataType

system_profiler SPAirPortDataType



# get users
dscl . list /Users | grep -v _


# runtime flag

The Hardened Runtime, along with System Integrity Protection (SIP), protects the runtime integrity of your software by preventing certain classes of exploits, like code injection, dynamically linked library (DLL) hijacking, and process memory space tampering.

- https://developer.apple.com/documentation/security/hardened_runtime

codesign -d -vv Atom.app

```
flags=0x10000(runtime)
```

# d2d

xattr -- display and manipulate extended attributes https://ss64.com/osx/xattr.html

codesign -- Create and manipulate code signatures https://www.manpagez.com/man/1/codesign/

otool -- lvm-otool, the otool-compatible command line parser for llvm-objdump



# CVEs Vulns
```
CVE-2020-27937, CVE-2020-29621, CVE-2020-10006, CVE-2020-24259, CVE-2020-9771, CVE-2021-1784, CVE-2021-30751, CVE-2020-9963, CVE-2021-1803, CVE-2021-1781, CVE-2021-30750, many more to read, understand and write about.
```

https://github.com/hetmehtaa/Mac_Vuln




