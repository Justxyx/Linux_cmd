#include	<stdio.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<dirent.h>
#include <stdlib.h>
#include <unistd.h>


/**
 *
 * stat 结构：
 *
 *
 * struct stat {
    dev_t         st_dev;       //文件的设备编号
    ino_t         st_ino;       //节点
    mode_t        st_mode;      //文件的类型和存取的权限
    nlink_t       st_nlink;     //连到该文件的硬连接数目，刚建立的文件值为1
    uid_t         st_uid;       //用户ID
    gid_t         st_gid;       //组ID
    dev_t         st_rdev;      //(设备类型)若此文件为设备文件，则为其设备编号
    off_t         st_size;      //文件字节数(文件大小)
    unsigned long st_blksize;   //块大小(文件系统的I/O 缓冲区大小)
    unsigned long st_blocks;    //块数
    time_t        st_atime;     //最后一次访问时间
    time_t        st_mtime;     //最后一次修改时间
    time_t        st_ctime;     //最后一次改变时间(指属性)
};
 */

ino_t	get_inode(char *);
void    printpathto(ino_t);
void    inum_to_name(ino_t , char *, int );

int main(){
    ino_t path_node = get_inode(".");
    printpathto(path_node);
}

void printpathto(ino_t this_inode){
    ino_t my_inode;
    char its_name[BUFSIZ];

    if  (get_inode("..") != this_inode){
        chdir("..");
        inum_to_name(this_inode,its_name,BUFSIZ);
        my_inode = get_inode(".");
        printpathto(my_inode);
        printf("/%s",its_name);
    }
}


ino_t get_inode(char *fname){
    struct stat info;
    if  (stat(fname,&info) == -1){
        printf("has error open");
        exit(1);
    }
    return info.st_ino;   // 节点
}

void inum_to_name(ino_t inode_to_find , char *namebuf, int buflen)

{
    DIR		*dir_ptr;		/* the directory */
    struct dirent	*direntp;		/* each entry	 */

    dir_ptr = opendir( "." );
    if ( dir_ptr == NULL ){
        perror( "." );
        exit(1);
    }

    /*
     * search directory for a file with specified inum
     */

    while ( ( direntp = readdir( dir_ptr ) ) != NULL )
        if ( direntp->d_ino == inode_to_find )
        {
            strncpy( namebuf, direntp->d_name, buflen);
            namebuf[buflen-1] = '\0';   /* just in case */
            closedir( dir_ptr );
            return;
        }
    fprintf(stderr, "error looking for inum %d\n", inode_to_find);
    exit(1);
}