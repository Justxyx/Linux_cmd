
int main(){
    int resopnse;
    tty_mode(0);
    set_mode();
    resopnse = get_resopnse(QUESTION);
    tty_mode(1);
    return resopnse;
}

int get_resopnse(char *question){
    printf("%s(y/n)?",question);
    int input;
    while (1){
        switch (input = getchar()) {
            case 'y':
            case 'Y':
                printf("\n");
                return 0;
            case 'n':
            case 'N':
            case 'EOF':
                printf("\n");
                return 1;
//            default:
//                printf("\ncannot understand %c,",input);
//                printf("Please type y or n \n");
        }
    }
}

tty_mode(int how){
    static  struct termios original_mode;
    if  (how == 0)
        tcgetattr(0,&original_mode);
    else
        return tcsetattr(0,TCSANOW,&original_mode);
}

set_mode(){
    struct termios ttystate;
    tcgetattr(0,&ttystate);
    ttystate.c_lflag &= ~ICANON;    // 不缓冲
    ttystate.c_lflag &= ~ECHO;    // 不回显
    ttystate.c_cc[VMIN] = 1  ;  // just one char
    tcsetattr(0,TCSANOW,&ttystate);
}