#include <stdio.h>
#include	<dirent.h>
#include	<sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

ino_t  get_inode(char *);
void printPathTo(ino_t);
void    inum_to_name(ino_t , char *, int );


int main() {
    printPathTo(get_inode("."));
    putchar('\n');
    return 0;
}

void printPathTo(ino_t inode) {
    ino_t  myInode ;
    char itsName[BUFSIZ];

    if (get_inode("..") != inode){
        chdir("..");
        inum_to_name(inode,itsName,BUFSIZ);
        myInode = get_inode(".");
        printPathTo(myInode);
    }
    printf("/%s",itsName);
}


ino_t get_inode(char *fname){
    struct stat info;
    if (stat (fname ,& info) == -1){
        perror(fname);
        exit(1);
    }
    return info.st_ino;
}

void inum_to_name(ino_t inode, char *names, int BUFSIZE) {
        DIR *dir_ptr;
        struct  dirent *dirent;

        dir_ptr = opendir(".");
    if (dir_ptr == NULL){
        perror(".");
        exit(1);
    }

    while ( (dirent = readdir( dir_ptr)) != NULL){
        if ( dirent->d_ino == inode){
            strncpy(names,dirent->d_name,BUFSIZE);
            names[BUFSIZE - 1] = '\0';
            closedir(dir_ptr);
            return;
        }
    }
    perror("error looking");
    exit(1);
}
