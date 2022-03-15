/**
 * sleep 的实现过程
 */

void wakeup(int);
int main(){
    printf("about to sleep for 4 seconds\n");
    signal(SIGALRM,wakeup);  // 信号处理的三种模式 还记得吗
    alarm(4);                // 当时间到了以后，内核发送SIGALRM到该进程
    pause(); // 挂起，等待信号。 不仅仅是SIGALRM时钟信号，别的信号也可以唤醒，或者死亡
    printf(" has end");
}

void wakeup(int signum){
    printf(("Alarm received from kernel\n"));
}