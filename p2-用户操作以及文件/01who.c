//
// Created by 肖应雄 on 2022/2/21.
//

//
// Created by xm on 2022/2/21.
//

#include <stdio.h>
#include<utmp.h>
#include<fcntl.h>
#include<unistd.h>
#include <stdlib.h>  // exit

# define SHOWHOST

void show_info(struct utmp * utbufp){
    printf("%-8.8s", utbufp->ut_name);	/* the logname	*/
    printf(" ");				/* a space	*/
    printf("%-8.8s", utbufp->ut_line);	/* the tty	*/
    printf(" ");				/* a space	*/
    printf("%10ld", utbufp->ut_time);	/* login time	*/
    printf(" ");				/* a space	*/
#ifdef	SHOWHOST
    printf("(%s)", utbufp->ut_host);	/* the host	*/
#endif
    printf("\n");				/* newline	*/
}

int main(){
    struct utmp current_record;
    int utmpfd;
    int reclen = sizeof(current_record);

    if( (utmpfd = open(UTMP_FILE,O_RDONLY)) == -1){
        perror(UTMP_FILE);
        exit(1);
    }

    while(read(utmpfd,&current_record,reclen) == reclen){
        show_info(&current_record);
    }
    close(utmpfd);
    return 0;
}

