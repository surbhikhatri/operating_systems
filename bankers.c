#include<stdio.h>

void calculateNeed(int ,int ,int [10][10], int [10][10],int [10][10]);
void resource_req(int ,int ,int [],int [10][10],int [10][10],int [10][10]);
int isSafe( int ,int ,int [], int [10][10],int [10][10],int [10][10]);

int main(){
	int P,R,i,j,x,choice;
	printf("\nenter no. of processes\n");
	scanf("%d",&P);
	printf("enter no. of resources\n");
	scanf("%d",&R);
	int maxm[P][R],allot[P][R],avail[P],need[P][R];

	printf("enter available resources\n");
	for(i=0;i<R;i++){
		scanf("%d",&avail[i]);
	}

	printf("\enter allocated resources\n");
	for(i=0;i<P;i++){
		for(j=0;j<R;j++)
			scanf("%d",&allot[i][j]);
	}

	printf("\enter maximum need\n");
	for(i=0;i<P;i++){
		for(j=0;j<R;j++)
			scanf("%d",&maxm[i][j]);
	}

    calculateNeed(P,R,need, maxm, allot);
    for(i=0;i<P;i++){
		for(j=0;j<R;j++)
			printf("%d\t",need[i][j]);
        printf("\n");
	}

    x=isSafe(P,R,avail, maxm, allot, need);
    if(x){
        do{
            printf("\ndo you want to enter any request press 1 for yes\n");
            scanf("%d",&choice);

            if(choice){
                resource_req(P,R,avail,allot,need,maxm);
            }

            else
                return 0;

        }while(choice!=0);

    }
    return 0;
}


void calculateNeed(int P,int R,int need[P][R], int maxm[P][R],int allot[P][R]){
    int i,j;
    for ( i = 0 ; i < P ; i++)
        for ( j = 0 ; j < R ; j++)

            need[i][j] = maxm[i][j] - allot[i][j];
}

int isSafe( int P,int R,int avail[], int maxm[][R],int allot[][R],int need[P][R])
{
    int i,j,p,k;


    int finish[P],safeSeq[P],work[R],count=0,found=0;
     for (i = 0; i < P ; i++)
        finish[i]=0;

    for (i = 0; i < R ; i++)
        work[i] = avail[i];


    while (count < P){

        for (p = 0; p < P; p++){

            if (finish[p] == 0){
                for (j = 0; j < R; j++){
                    if (need[p][j] > work[j])
                        break;
                }

                if (j == R){
                    for ( k = 0 ; k < R ; k++)
                        work[k] += allot[p][k];

                    safeSeq[count++] = p;
                    finish[p] = 1;
                    found = 1;
                }
            }
        }

        if (found == 0){
            printf("System is not in safe state\n");
            return 0;
        }
    }

    printf("System is in safe state.\nSafe sequence is: \n");
    for (int i = 0; i < P ; i++)
        printf("%d\t",safeSeq[i]);

    return 1;
}


void resource_req(int P,int R,int avail[],int allot[P][R],int need[P][R],int maxm[P][R]){
    int choice,request[R],flag1=0,flag2=0,req,i,x,w,k;
    printf("\nenter the process no. which wants to request\n");
    scanf("%d",&req);
    printf("enter no. of resources required\n");
    for(i=0;i<R;i++){
        scanf("%d",&request[i]);

    }
    for(i=0;i<R;i++){
        if(request[i] <= need[req][i])
            flag1++;
    }
        //printf("\nflag1=%d",flag1);

    for(i=0;i<R;i++){
        if(request[i] <= avail[i])
            flag2++;
    }
        //printf("\nflag2=%d",flag2);
    if(flag2==R && flag1==R){
        for(i=0;i<R;i++){
            avail[i]=avail[i]-request[i];
            allot[req][i]=allot[req][i]+request[i];
            need[req][i]=need[req][i]-request[i];
        }

        x=isSafe(P,R,avail, maxm,allot,need);
        if(x){
            printf("\nrequest can be granted\n");}
        else
        printf("\nrequest cannot be granted\n");
    }
}







