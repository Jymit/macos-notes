#### mac_security_researcher

At the time of writing running macOS Big Sur 11.6.2 (20G314)

#### mac_security_researcher 101

https://twitter.com/RonMasas/status/1470654363639197699?s=20 - Ron Masas

https://twitter.com/_r3ggi - Wojciech Reguła

https://twitter.com/xorrior - Christopher Ross

https://twitter.com/theevilbit - Csaba Fitzl

https://twitter.com/cedowens - Cedric Owens

https://twitter.com/objective_see

https://twitter.com/patrickwardle - Patrick Wardle

The Art Of Macos Malware - https://taomm.org/

Security content of macOS Monterey 12.1 - https://support.apple.com/en-gb/HT212978


#### MacOS != Linux
write data to the victim’s process memory using the ptrace

MITRE: T1055.008

For such purpose you should: 1. get the task of the victim’s app (using for instance the task_for_pid() function); 2. use the mach_vm_write function. I used that technique when I was exploiting iExplorer. You can read more about that here.

2019 - https://wojciechregula.blog/post/dangerous-get-task-allow-entitlement/

Since Mac OS X 10.11 El Capitan, Apple decided to add a new feature called System Integrity Protection (aka Rootless). The idea behind it is to limit the root account’s ability to do anything in the user’s operating system. It’s an excellent idea - implementing an access control mechanism to each sensitive resource is reducing the attack surface.

com.apple.security.get-task-allow entitlement. On macOS when process A wants to control process B, A asks the kernel for the B’s task using task_for_pid() function. Then, the kernel asks taskgated if the B’s task_port should be transferred to A. The taskgated usually accepts the requests if:
- the A is run as root or possesses task_for_pid-allow entitlement
- or the B is signed with com.apple.security.get-task-allow.

taskgated - task_for_pid access control daemon

mach_vm_write - https://developer.apple.com/documentation/kernel/1402070-mach_vm_write

task_for_pid() -

```
To build a utility that will use task_for_pid(), you need to do the following:

1. Create Info.plist file which will be embedded to your executable 
   file and will enable code signing 
2. Create self-signed code signing certificate using Keychain access 
3. Write your program that uses security framework to obtain rights 
   to execute task\_for_pid() 
4. Compile your program and code-sign it.
```

If you want to debug a hardened app (without the get-task-allow entitlement), you should disable the System Integrity Protection. The hardened runtime feature gives macOS some cross-app isolation.

In all new projects, the hardened runtime flag is turned on by default. In the old projects, it was enforced by Apple in the macOS Catalina. All apps that are downloaded from the Internet (outside of the App Store) are quarantined and thus need to be notarized.

- When the process doesn’t have the hardened runtime capability turned on and the com.apple.security.get-task-allow entitlements are not set, the easiest way to inject your code is to use the DYLD_INSERT_LIBRARIES environment variable.

- https://theevilbit.github.io/posts/dyld_insert_libraries_dylib_injection_in_macos_osx_deep_dive/
- Csaba Fitzl


- DYLD_INSERT_LIBRARIES 
- This  is  a colon separated list of dynamic libraries to load before the ones specified in the program.  This lets you test new modules of existing dynamic shared libraries that are used in flat-namespace images by loading a temporary dynamic shared library with just the new modules. Note that this has no effect on images built a two-level  namespace  images  using  a  dynamic shared library unless DYLD_FORCE_FLAT_NAMESPACE is also used.

- it will load any dylibs you specify in this variable before the program loads, essentially injecting a dylib into the application.

### Defense

https://theevilbit.github.io/shield/












