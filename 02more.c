//
// Created by 肖应雄 on 2021/12/27.
//
#include <stdio.h>

#define	PAGELEN	24
#define	LINELEN	512

void do_more(FILE *);
int see_more(FILE *);


int main1(int ac,char *av[]){
    FILE *fp;
    if  (ac == 1)
        do_more(stdin);
    else
        while (--ac)
            if((fp= fdopen(*++av,"r")) != NULL){
                do_more(fp);
                fclose(fp);
            } else
            {

            }
    return 0;
}

void do_more(FILE *fp){
    char line[LINELEN];
    int num_of_lines = 0;
    int see_more(FILE*),reply;
    FILE *fp_tty;

    fp_tty = fopen("dev/tty","r");
    if  (fp_tty == NULL)
        return;
    while (fgets(line,LINELEN,fp)){
        if  (num_of_lines == PAGELEN){
            reply = see_more(fp_tty);
            if  (reply == 0)
                break;
            num_of_lines -= reply;
        }
        if  (fputs(line,stdout) == EOF)
            return;
        num_of_lines ++;
    }
}

int see_more(FILE *cmd)				   /* NEW: accepts arg  */
/*
 *	print message, wait for response, return # of lines to advance
 *	q means no, space means yes, CR means one line
 */
{
    int	c;

    printf("\033[7m more? \033[m");		/* reverse on a vt100	*/
    while( (c=getc(cmd)) != EOF )		/* NEW: reads from tty  */
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