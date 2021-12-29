# macos-notes

Mach-O

Mach-O, short for Mach object file format, is a file format for executables, object code, shared libraries, dynamically-loaded code, and core dumps. It was developed to replace the a. out format. Mach-O is used by most systems based on the Mach kernel.

A Unix-like operating system developed at Carnegie-Mellon University in the period between 1985 and 1994. The Mach kernel was designed with a microkernel architecture that makes it easily portable to different platforms. Operating systems based on Mach include NextStep, OSF/1 and macOS.



# macos security

SIP - System Integrity Protection

TCC - Transparency, Consent, and Control


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

