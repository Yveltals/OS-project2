#ifndef USERPROG_SYSCALL_H
#define USERPROG_SYSCALL_H

#include "threads/synch.h"
#include "threads/thread.h"
void syscall_init (void);

#define ERROR -1
#define NOT_LOADED 0
#define LOADED 1
#define LOAD_FAIL 2
#define CLOSE_ALL_FD -1
#define USER_VADDR_BOTTOM ((void *) 0x08048000)

struct exitcode {
    int pid;
    int status;
    struct list_elem elem;
};

struct openfile {
    struct file *file;
    int fd;
    struct list_elem elem;
};

struct lock file_system_lock;


void syscall_close(int fd);

int getpage_ptr (const void *vaddr);
struct exitcode* find_exitcode (int pid);
void remove_child_process (struct exitcode *child);
struct file* find_file(int fd);
void syscall_exit (int status);
#endif /* userprog/syscall.h */