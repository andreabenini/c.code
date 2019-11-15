Do not use `ls` for huge dirs, this method uses linux syscalls and `dirent` structure in order to avoid `readdir() [man 2]`
that is limited to 32K of directory entries at a time. This reads directory structure directly from disk on inodes.  
Here are few samples
- You can list a directory containing 8 million files! But not with ls.  
    http://be-n.com/spw/you-can-list-a-million-files-in-a-directory-but-not-with-ls.html
- getdents man(2)  
    http://man7.org/linux/man-pages/man2/getdents.2.html
