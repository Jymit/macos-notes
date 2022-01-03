#### mac_security_researcher

At the time of writing running macOS Big Sur 11.6.2 (20G314)

#### mac_security_researcher 101

https://twitter.com/RonMasas/status/1470654363639197699?s=20

https://twitter.com/_r3ggi

https://twitter.com/xorrior


#### MacOS != Linux
write data to the victim’s process memory using the ptrace

MITRE: T1055.008

For such purpose you should: 1. get the task of the victim’s app (using for instance the task_for_pid() function); 2. use the mach_vm_write function. I used that technique when I was exploiting iExplorer. You can read more about that here.

2019 - https://wojciechregula.blog/post/dangerous-get-task-allow-entitlement/

Since Mac OS X 10.11 El Capitan, Apple decided to add a new feature called System Integrity Protection (aka Rootless). The idea behind it is to limit the root account’s ability to do anything in the user’s operating system. It’s an excellent idea - implementing an access control mechanism to each sensitive resource is reducing the attack surface.

com.apple.security.get-task-allow entitlement. On macOS when process A wants to control process B, A asks the kernel for the B’s task using task_for_pid() function. Then, the kernel asks taskgated if the B’s task_port should be transferred to A. The taskgated usually accepts the requests if:
- the A is run as root or possesses task_for_pid-allow entitlement
- or the B is signed with com.apple.security.get-task-allow.

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



















