#include<stdio.h>


int main(){

    printf("How many process ? : ");
    int totalProcess=0;
    scanf("%d",&totalProcess);

    int allBurstTime[totalProcess];
    for(int i=0;i<totalProcess;i++){

        printf("\nEnter Burst time of process %d : ",i+1);
        scanf("%d",&allBurstTime[i]);

    }

    printf("\nEnter Time Quantum : ");
    int timeQuantum=0;
    scanf("%d",&timeQuantum);


    int loopNeeded=0;
    for(int i=0;i<totalProcess;i++){

        loopNeeded +=  allBurstTime[i]/timeQuantum;
        loopNeeded += allBurstTime[i]%timeQuantum;
    }

   // printf("\nTotal Loop Needed %d ",loopNeeded );

   int TATList[totalProcess];

   int processNumber[loopNeeded];
   int BurstTime[loopNeeded];
   int processDetails[loopNeeded];
   int processFinishedTAT[totalProcess];
   int processFinishedTATIndex[totalProcess];

   for(int i=0;i<totalProcess;i++){

        BurstTime[i] = allBurstTime[i];
        processNumber[i] = i;
        processDetails[i]=i;

   }

    int tmp=0;
    int sequesnceNumber=0;
    int totalCompletedProcess=0;
    int totalRunningLoop=0;
    int TotalTAT=0;
   for(int i=0;i<loopNeeded;i++){


        totalRunningLoop++;

        int RemainingBurstTime = BurstTime[i]-timeQuantum;

        if(RemainingBurstTime>0){



            BurstTime[totalProcess+sequesnceNumber] = RemainingBurstTime;
            processNumber[sequesnceNumber+totalProcess] = totalProcess+i;
            processDetails[sequesnceNumber+totalProcess] = processDetails[i];


            if(RemainingBurstTime>timeQuantum){
                tmp += timeQuantum;
                TATList[i] = tmp;
            }else{


                 tmp += timeQuantum;
                TATList[i] = tmp;
            }

            sequesnceNumber++;

        }else{

            totalCompletedProcess++;



             if(RemainingBurstTime==0){

                tmp += timeQuantum;

             }else{

                 tmp += (timeQuantum+RemainingBurstTime);

             }

             TATList[i] = tmp;

              TotalTAT+= tmp;


            processFinishedTAT[totalCompletedProcess-1]=tmp;
            processFinishedTATIndex[totalCompletedProcess-1] = processDetails[i];

        }

        if(totalCompletedProcess==totalProcess){
            break;
        }


   }


   for(int i=0;i<totalRunningLoop;i++){


        printf("\nS %d P%d B %d   TAT %d ",i+1,processDetails[i]+1,BurstTime[i],TATList[i]);

   }


   printf("\nTotal TAT = %d ",TotalTAT);
   float avgTAT = ((float)TotalTAT/(float)totalProcess*1.0);
   printf("\n AVG TAT = %.2f ",avgTAT);


   int totalWaitingTime=0;

   for(int i=0;i<totalProcess;i++){

        printf("\nP%d  WT %d TAT %d ",processFinishedTATIndex[i]+1,processFinishedTAT[i]-allBurstTime[processFinishedTATIndex[i]],processFinishedTAT[i]);

        totalWaitingTime+= processFinishedTAT[i]-allBurstTime[processFinishedTATIndex[i]];


   }

   printf("\nTotal Waiting Time : %d ",totalWaitingTime);
   printf("\nAVG Waiting Time : %0.2f ",(float)totalWaitingTime/(float)totalProcess);






    return 0;
}
