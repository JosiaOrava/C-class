#include <stdio.h>


void sleep(int hTime,int  mTime,int  hSleep,int mSleep,int *wakeH,int *wakeM){

    //hours
    for (int i = 0; i < hSleep; i++){
        hTime++;
        if(hTime == 24){
            hTime = 0;
        }
    }
    //minutes
    for (int x = 0; x < mSleep; x++){
        mTime++;
        if (mTime > 59){
            mTime = 0;
        }
    }
    *wakeH = hTime;
    *wakeM = mTime;
}

int main(){
    int hoursTime, minutesTime, hoursSleep, minutesSleep, wakeH = 0, wakeM = 0;
    
    printf("Enter current time (hh:mm): ");
    scanf("%d:%d", &hoursTime, &minutesTime);
    printf("How long do you want to sleep (h:mm): ");
    scanf("%d:%d", &hoursSleep, &minutesSleep);

    sleep(hoursTime, minutesTime, hoursSleep, minutesSleep, &wakeH, &wakeM);

    printf("If you go to bed now you must wake up at %d:%d", wakeH, wakeM);
    return 0;
}