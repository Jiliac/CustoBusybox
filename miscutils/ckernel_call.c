#include <unistd.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <stdlib.h>
#include "busybox.h"

#define MALLOC_SIZE     8 * 1048576

void toto(void){
        printf("function toto do nothing\n");
}

void ckernel_syscall(pid_t pid) {
        long int amma;

        pid = getpid();
        printf("ckernel call pid: %d\n", (int) pid);
        printf("function addr: %p\n", toto);

        printf("Calling cKernel prototyped by a system call\n");
        amma = syscall(378, pid, (unsigned long) toto);
        printf("System call sys_ckernel_proto returned %ld\n", amma);

}

int ckernel_call_main(void)
{
        pid_t pid;

        printf("message before forking\n");
        pid = fork();
        if(pid)
                printf("child process of forking as %d pid\n", (int) pid);
        else
                sleep(1);
        ckernel_syscall(getpid());

        return 0;
}
