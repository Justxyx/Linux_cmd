#include	<stdio.h>
#include	<sys/types.h>
#include	<dirent.h>

void do_ls(char[]);

main(int ac,char *av[]){
    if  (ac == 1)
        do_ls(".");
    else
        while (--ac){
            printf("%s:\n",*++av);
            do_ls(*av);
        }
}

void do_ls(char dirname[]){
    DIR *dir_ptr;
    struct dirent *direntp;
    if((dir_ptr = opendir(dirname)) == NULL){
        printf("no direct");
    } else
    {
        while ((direntp = readdir(dir_ptr)) != NULL){
            printf("%s\n",direntp->d_name);
        }
        closedir(dir_ptr);
    }
}
