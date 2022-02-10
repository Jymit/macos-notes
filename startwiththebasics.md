## macos

### Versioning
```
OS X 10 beta: Kodiak - 13 September 2000
OS X 10.0: Cheetah - 24 March 2001
OS X 10.1: Puma - 25 September 2001
OS X 10.2: Jaguar - 24 August 2002
OS X 10.3 Panther (Pinot) - 24 October 2003
OS X 10.4 Tiger (Merlot) - 29 April 2005
[OS X 10.4.4 Tiger (Chardonnay)]
OS X 10.5 Leopard (Chablis) - 26 October 2007
OS X 10.6 Snow Leopard - 28 August 2009
OS X 10.7 Lion (Barolo) - 20 July 2011
OS X 10.8 Mountain Lion (Zinfandel) - 25 July 2012
OS X 10.9 Mavericks (Cabernet) - 22 October 2013
OS X 10.10: Yosemite (Syrah) - 16 October 2014
OS X 10.11: El Capitan (Gala) - 30 September 2015
macOS 10.12: Sierra (Fuji) - 20 September 2016
macOS 10.13: High Sierra (Lobo) - 25 September 2017
macOS 10.14: Mojave (Liberty) - 24 September 2018
macOS 10.15: Catalina (Jazz) - 7 October 2019
macOS 11: Big Sur - 12 November 2020
macOS 12: Monterey - 25 October 2021
```

### FileVault
Encrypt the startup disk on your Mac
FileVault full-disk encryption (FileVault 2) uses XTS-AES-128 encryption with a 256-bit key to help prevent unauthorized access to the information on your startup disk. [link](https://support.apple.com/en-us/HT204837)
`sudo fdesetup status`

### Recovery keys
An institutional recovery key (IRK) to unlock FileVault-encrypted Intel-based Mac computers and recover data.

### APFS
Apple File System (APFS) is a Proprietary file system developed and deployed by Apple Inc. for macOS Sierra (10.12.4) and later

https://www.mac4n6.com/blog/2017/11/26/mount-all-the-things-mounting-apfs-and-4k-disk-images-on-macos-1013


### Mach-O 
Mach-O files, or Mach Object Files, are an executable format used on Operating Systems based on the Mach Kernel. 

Starting with the Mach Header. It’s purpose is to describe what the file contains, and how the Kernel and Dynamic Linker should handle it. The first 4 bytes are, like with any file, it’s “Magic Number”. A Magic Number is used to identify a file format. In the case of Mach-O’s there are three Magic Numbers that one may come across. 0xfeedface for 32-bit, 0xfeedfacf for 64-bit and 0xcafebabe for Mach Universal Binaries / Object files.

Other properties of a Mach-O Header include the cpu type and sub type which define the architecture the Mach-O is built for (e.g. arm64, x86_64, arm64_32), the number of Load Commands and the size of that area and flags to be passed to the Dynamic Linker.
```
struct mach_header {
        uint32_t            magic;          // mach magic number
        cpu_type_t          cputype;        // cpu specifier
        cpu_subtype_t       cpusubtype;     // cpu subtype specifier
        uint32_t            filetype;       // type of mach-o e.g. exec, dylib ...
        uint32_t            ncmds;          // number of load commands
        uint32_t            sizeofcmds;     // size of load command region
        uint32_t            flags;          // flags
        uint32_t            reserved;       // *64-bit only* reserved
    };
```
Load Commands are placed directly after the Mach-O header in the file. They specify the logical structure of the file and the layout of the file in virtual memory.

All Load Commands have a common 8 byte structure which identifies the type of the command and it’s size. This common structure is defined as follows:
```
struct load_command {
        uint32_t			cmd;			// type of load command
        uint32_t			cmdsize;		// size of load command
    };
```

But Segment Commands are not the only commands that are included in the majority of Mach-O files. The LC_DYLD_INFO and LC_LOAD_DYLINKER commands specify information such as rebase, bind, weak, lazy and export information for the Dynamic Linker, and the path of the Dynamic Linker the Kernel should use to execute the binary respectively. Mach-O’s frequently require Dynamic Libraries, especially /usr/lib/libSystem.B.dylib. The LC_DYLIB command defines the path for Linker to find the Dylib, and there can be however many of these commands as are required for the number of Dynamic Libraries.


LC_DYLD_INFO

LC_LOAD_DYLINKER

/usr/lib/libSystem.B.dylib

LC_DYLIB - command defines the path for Linker to find the Dylib, and there can be however many of these commands as are required for the number of Dynamic Libraries.
