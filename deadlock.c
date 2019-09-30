# include<stdio.h>
void detect(int ,int,int [10][10],int [10][10],int[10],int [10],int ,int );
int main(){
    int n,m,i,j,k,p=0,t;
    printf("enter the no of resources\n");
    scanf("%d",&m);
    printf("enter the no of process\n");
    scanf("%d",&n);
    int allo[n][m];
    int req[n][m];
    int ava[m];
    int fin[n];
    printf("\nenter allocation\n");
    for(i=0;i<n;i++){
        fin[i]=0;
        for(j=0;j<m;j++){
            scanf("%d",&allo[i][j]);
          }
       }
    t=fact(n);
    printf("\nenter request\n");
    for(i=0;i<n;i++){
        for(j=0;j<m;j++)
            scanf("%d",&req[i][j]);
    }
    printf("\nenter avaiable\n");
    for(i=0;i<m;i++)
        scanf("%d",&ava[i]);
    int maxi=99;
    detect(n,m,allo,req,ava,fin,t,maxi);
}

void detect(int n,int m,int allo[n][m],int req[n][m],int ava[m],int fin[n],int t,int maxi){
    int dead[m];
    int k=0,i,j,count=0;
    for(i=0;i<n; i++){
        if(i!=maxi){
            count=0;
            if(fin[i]==0){
                for (j=0;j<m;j++){
                    if(req[i][j]<=ava[j])
                        count++;
                }
                if(count==m){
                    for(j=0;j<m;j++)
                        ava[j]=ava[j]+allo[i][j];
                   fin[i]=1;
                }
            }
        }
    }
    t--;
    if(t!=0)
        detect(n,m,allo,req,ava,fin,t,maxi);
    if(t==0){
        for(i=0;i<n ;i++){
            if(fin[i]==0 && i!=maxi){
                dead[k]=i;
                k++;
           }
       }
        for(i=0;i<k;i++)
        printf("deadlock process %d",dead[i]);
        if(k!=0)
            recovery(n,m,allo,req,ava,fin,t,k,dead);
        else
            printf("\nNO DEADLOCK\n");
   }
}

int recovery(int n,int m,int allo[n][m],int req[n][m],int ava[m],int fin[n],int t,int k,int dead[k]){
    int sum[n],l,i,j,maxi;
    printf("\n ---Apply recovery to slove deadlock problem----\n ");
    for(i=0;i<n;i++)
        sum[i]=0;
    i=0;
    while(i<k){
        l=dead[i];
        for(j=0;j<m;j++)
        sum[l]=sum[l]+allo[l][j];
        i++;
    }
    maxi=max(sum,n);
    printf("\n ---- Abort the process %d having highest number of resources----\n",maxi);
    for(j=0;j<m;j++)
        ava[j]=ava[j]+allo[maxi][j];
   t=fact(n);
   detect(n,m,allo,req,ava,fin,t,maxi);
}

int fact(int n){
    if(n>=1)
        return n*fact(n-1);
    else
        return 1;
}

int max (int sum[],int n){
    int o,i,h;
    o=sum[0];
    for(i=0;i<n;i++){
        if(sum[i]>o){
            o=sum[i];
            h=i;
        }
    }
    return h;
}















