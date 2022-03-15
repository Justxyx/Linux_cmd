int main(int ac,char *av[]){
    struct termios settings;
    int rv;
    ac = 2;
    av[1] = "n";
    rv = tcgetattr(0,&settings);  // 终端为0号 我也不知道为啥是0  tcgetattr  获取设备属性
    if  (rv == -1){
        perror("tcgetattr error");
        exit(1);
    }
    if( settings.c_cflag & ECHO )       // 这里主要看termios 这个数据结构 里面写的还很清楚
        printf("echo is open\n");
    else
        printf("echo is off\n");

    printf("ready change ECHO\n");

    if  (ac  == 1)
        return 0;

    if( av[1] == "y"){
        settings.c_cflag |= ECHO;
        printf("CHANGE ECHO is OPen\n ")        ;
    }
    else{
        settings.c_cflag &= ~ECHO;
        printf("CHANGE ECHO is closed   \n");
    }
}