#include <stdio.h>  // 输入输出
#include	<dirent.h>  // DIR
#include	<sys/types.h>
#include	<sys/stat.h>
#include <string.h>
#include <time.h>

#include <pwd.h>   // pwd
#include <grp.h>


void do_ls(char[]);
void do_stat(char *);
void show_file_info(char *,struct stat*);
void mode_to_letters( int , char [] );
char *uid_to_name( uid_t );
char *gid_to_name( gid_t );


int main(int ac, char *av[]){
    ac = 1;
    if  (ac == 1){
        do_ls(".");
    } else{
        while ( -- ac){
            printf("%s:\n",*++av);
            do_ls(*av);
        }
    }
    return 0;
}

void do_ls(char dirname[]){
    DIR *dir_ptr;
    struct dirent *dirent;

    if((dir_ptr = opendir(dirname)) == NULL){
        fprintf(stderr,"ls:cannot open %s\n",dirname);
    } else{
        while ( (dirent = readdir(dir_ptr)) != NULL){
            do_stat(dirent->d_name);
        }
    }
}

void do_stat(char *filename){
    struct stat info;
    if (stat(filename,&info) == -1){
        perror(filename);
    } else{
        show_file_info(filename,&info);
    }
}

void show_file_info(char *filename,struct stat *info_p){

    char modestr[11];
    mode_to_letters(info_p->st_mode,modestr);

    /**
     * 这一段的字符串输出格式可以看看
     */
    printf("%s",modestr);  // mode
    printf("%4d  ",info_p->st_nlink) ; // 链接数
    printf("%-6s", uid_to_name(info_p->st_uid)) ; // u id
    printf("%-6s", gid_to_name( info_p->st_gid)) ; //  g id
    printf("%-12d  ",info_p->st_size) ; //  size
    printf("%.12s   ",4+ ctime( &info_p->st_ctime) ) ; //  time
    printf("%s\n",filename) ; //  file name
//    printf("\n");
}

void mode_to_letters(int mode,char str[]){
    strcpy(str,"----------");

    /**
     * is directory？
     */
    if(S_ISDIR(mode)) str[0] = 'd';
    if(S_ISDIR(mode)) str[0] = 'c';
    if(S_ISDIR(mode)) str[0] = 'b';

    if ( S_ISDIR(mode) )  str[0] = 'd';    /* directory?       */
    if ( S_ISCHR(mode) )  str[0] = 'c';    /* char devices     */
    if ( S_ISBLK(mode) )  str[0] = 'b';    /* block device     */

    if ( mode & S_IRUSR ) str[1] = 'r';    /* 3 bits for user  */
    if ( mode & S_IWUSR ) str[2] = 'w';
    if ( mode & S_IXUSR ) str[3] = 'x';

    if ( mode & S_IRGRP ) str[4] = 'r';    /* 3 bits for group */
    if ( mode & S_IWGRP ) str[5] = 'w';
    if ( mode & S_IXGRP ) str[6] = 'x';

    if ( mode & S_IROTH ) str[7] = 'r';    /* 3 bits for other */
    if ( mode & S_IWOTH ) str[8] = 'w';
    if ( mode & S_IXOTH ) str[9] = 'x';
}



char *uid_to_name(uid_t uid){
    struct	passwd *getpwuid(), *pw_ptr;
    pw_ptr = getpwuid(uid);
    return pw_ptr->pw_name;
}


char *gid_to_name(gid_t gid){
    struct group *getgrgid(),*grp_ptr;
    static char numstr[10];
    grp_ptr = getgrgid(gid);
    return grp_ptr->gr_name;
}










