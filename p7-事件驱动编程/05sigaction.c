#define INPUTLEN 100
int main(){
    struct sigaction newhandler;
    sigset_t blocked;
    void inthandler();
    char x[INPUTLEN];

    newhandler.sa_handler = inthandler;     // 老模式
    newhandler.sa_flags = SA_RESETHAND;   // 函数调用时重置
    
    // 阻塞设置 这个在下章中详解
    sigemptyset(&blocked);
    sigaddset(&blocked,SIGQUIT);
    newhandler.sa_mask = blocked;

    if (sigaction(SIGINT,&newhandler,NULL) == -1){
        perror("sigaction");
    } else{
        while (1){
            fgets(x,INPUTLEN,stdin);
            printf("input:%s",x);
        }
    }

    return 0;
}

void inthandler(int s){
    printf("Callen with signal %d \n",s);
    sleep(s);
    printf("done handing signal %d \n",s);
}