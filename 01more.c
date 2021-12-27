#include <stdio.h>

#define PAGELEN 24
#define LINELEN 512

void do_more(FILE *);
int see_more();

/**
 * 1.我们首先要清楚unix/linux下的系统编程，main函数上面是有参数的，即main（int ac，char *av[]），
 * 这个带参数是干啥的呢？第一个ac是表示程序运行时输入的参数个数（int型），第二个是一个指针数组，表示参数的符号。举个例子：

./more01 执行之后，ac=1，av[0]=./more01，./more01 more01.c执行之后，ac=2，av[0]=./more01,av[1]=more01.c
 如果执行./more01 -f more01.c 的话，ac=3，av[0]=./more01,av[1]=-f ，av[2]=more01.c，然后至于怎么实现的这样的功能的，
 这里不是讨论的重点，知道就好。

 * @param ac
 * @param av
 * @return
 */

int main1( int ac ,char *av[]){
    FILE *fp;
    if  ( ac == 1)
        do_more(fp);
    else
        while (--ac){
            if( (fp = fopen(*++av,"r")) != NULL){
                do_more(fp);
                fclose(fp);
            } else
            {

            }

        }
    return 0;
}

void do_more( FILE *fp )
/*
 *  read PAGELEN lines, then call see_more() for further instructions
 */
{
    char	line[LINELEN];
    int	num_of_lines = 0;
    int	see_more(), reply;

    while ( fgets( line, LINELEN, fp ) ){		/* more input	*/
        if ( num_of_lines == PAGELEN ) {	/* full screen?	*/
            reply = see_more();		/* y: ask user  */
            if ( reply == 0 )		/*    n: done   */
                break;
            num_of_lines -= reply;		/* reset count	*/
        }
        if ( fputs( line, stdout )  == EOF )	/* show line	*/
            return;			/* or die	*/
        num_of_lines++;				/* count it	*/
    }
}

int see_more()
/*
 *	print message, wait for response, return # of lines to advance
 *	q means no, space means yes, CR means one line
 */
{
    int	c;

    printf("\033[7m more? \033[m");		/* reverse on a vt100	*/
    while( (c=getchar()) != EOF )			/* get response	*/
    {
        if ( c == 'q' )			/* q -> N		*/
            return 0;
        if ( c == ' ' )			/* ' ' => next page	*/
            return PAGELEN;		/* how many to show	*/
        if ( c == '\n' )		/* Enter key => 1 line	*/
            return 1;
    }
    return 0;
}