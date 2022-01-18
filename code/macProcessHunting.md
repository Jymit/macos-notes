Process creation on Mac is one of the most critical components for a Mac threat hunter to understand.

## fork
man fork
```
“fork() causes creation of a new process.  The new process (child process) is an exact copy of the calling process (parent process)…”
```
Taken from [here](https://themittenmac.com/low-level-process-hunting-on-macos/)

Compile the program and run i
```
% gcc iFork.c -o iFork 
./iFork
```
Fork is not designed to execute a new binary. Instead, it is designed to create an exact copy of the process that is already running. Some of you are probably looking at the resulting output from our code and wondering how in the world we got two lines of output when the only two print functions are in opposing sections of the if/else statement. Remember, when we called fork we cloned this process, meaning it was run a total of two times: the time we executed it, and the time it forked and “re-executed itself” as a new process. 

## exec

execvp()
This is relevant because if you’re using a tool that records processes in real time, you’re bound to eventually see two processes created around the same time that share the same process id and the same parent process. From a developer perspective, note that once you’ve called exec in this manner, you will not be able to return execution back to your original program. As soon as exec runs, the new program takes over and the old disappears. This gets us a step closer to understanding the “sh -c whoami” scenario described in the first section of this post.

## fork + exec
fork() which runs a program by cloning the currently running process and exec() which runs a program by overwriting the current process image.

Running exec will not allow a developer (or malware author) to return control of the original executed program. This is a problem for malware because it often uses built-in commands to collect recon data on the system. For example, If malware execs the “uname -a” command and then wants to parse the output to get the kernel version, it won’t be able to. After the malware execs“uname -a” the malware will be dead. So instead, what the malware author will do is first fork (duplicate) the malware process, and then exec the “uname -a” program within that fork so that the duplicated process is then overtaken by the uname command. After uname terminates, control is then returned to the process that called it (the malware) and the developer is able get the output. This is all functionality that we take for granted nowadays thanks to high level programming languages that do it all for us.

