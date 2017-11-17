#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <time.h>
#include <sys/time.h> 
#include <math.h>
#include <unistd.h>
#include "timer.h"

struct timeval nowtime;
static void get_format_time(char *tstr)
{
    // time_t t;
    
    // t = time(NULL);
    // strcpy(tstr, ctime(&t));
    // tstr[strlen(tstr)-1] = '\0';
    long oldusec = nowtime.tv_usec;
    // struct timeval time;
    gettimeofday(&nowtime, NULL);
    sprintf(tstr, "usec: %ld ", nowtime.tv_usec - oldusec);
    
    return;
}

TMR_handle_t hdl;

int i = 0;
uint16_t pfnCallback1(TMR_handle_t handle, void *arg)
{
    i++;
    time_t t;
    time(&t);
    printf("time now:%ld\n",t);
    if (i > 3)
    {
        TMR_CancleTimer(hdl);
    }
    
    
    return (1);
}

int main(void)
{
    char arg[50];
    char tstr[200];
    int ret;
    
    

    TMR_Init();
    gettimeofday(&nowtime, NULL);
    hdl = TMR_SetTimer(1000, 1, pfnCallback1, NULL );

    
    while(1)
    {
        // time_t t;
        // time(&t);
        // printf("before time cancel:%ld\n",t);
        // sleep(3);
        // TMR_CancleTimer(hdl);
        // time(&t);
        // printf("time cancel:%ld\n",t);
        sleep(1);
        // break;
    }

    TMR_Shutdown();
    // uint32_t errornum = TMR_ReturnErrorNum();
    // printf("%d, %ld\n", call_cnt[0], errornum, (float)errornum / call_cnt[0] *100);
    
    return 0;
}
