//AIM:SCAN ALGORITHM
#include<stdio.h>
int sub(int,int);
void sort(int a[],int,int);
int main()
{	
	int i,cp,n,x=0,y=0,z=0,dir,ub,lb;
	//x is less index and y is more index z is opr index
	printf("enter the current position\n");
    scanf("%d",&cp);
    printf("enter the number of requests\n");
    scanf("%d",&n);
    printf("\nenter lower bound\n");
    scanf("%d",&lb);
    printf("\nenter upper bound\n");
    scanf("%d",&ub);
    printf("enter the request string\n");
    int req[n],less[10],more[10],opr[n];
    for(i=0;i<n;i++){
    	scanf("%d",&req[i]);
	}
	for(i=0;i<n;i++){
		if(req[i]<cp){
			less[x]=req[i];
			x++;
		}
		if(req[i]>cp){
			more[y]=req[i];
			y++;
		}
	}
		int ch1,pl;
	printf("\nenter 1]left	2]right	 3]to enter previous loction\n");
	scanf("%d",&ch1);
	switch(ch1){
		case 1:	printf("you have selected right direction\n");
				dir=1;
				break;
		case 2:	printf("you have selected right direction\n");
				dir=2;
				break;
		case 3:	printf("\nenter previous location\n");
				scanf("%d",&pl);
				if(cp-pl>0){
					dir=2;
					printf("\ndirection is right\n");
				}
				else{
					dir=1;
					("\ndirection is left\n");
				}
				break;
	}
	sort(less,x,2);
	sort(more ,y,1);

	switch(dir){
		case 1:	printf("\nmoving left\n");
            for(i=0;i<x;i++){
                opr[z]=less[i];
                z++;
            }
            opr[z]=lb;
            z++;
            for(i=0;i<y;i++){
                opr[z]=more[i];
                z++;
            }
            break;
        case 2:	printf("\nmoving right\n");
            for(i=0;i<y;i++){
                opr[z]=more[i];
                z++;
            }
            opr[z]=ub;
            z++;
            for(i=0;i<x;i++){
                opr[z]=less[i];
                z++;
            }
            break;
	}
	
	int head=0;
	printf("\n");
	for(i=0;i<z;i++){
		int temp=sub(cp,opr[i]);
		head=head+temp;
		if(i==0)
			printf("%d-->%d",cp,opr[0]);
		else
			printf("-->%d",opr[i]);
		cp=opr[i];
		
	}
	printf("\ntotal head movement =%d\t",head);
	
	
	return 0;
}

void sort(int a[],int n,int ch){
	int i,j,temp=0;
	if(ch==1){
		for(i=0;i<n;i++){
			for(j=0;j<n-1;j++){
				if(a[j]>a[j+1]){
					temp=a[j];
	                a[j]=a[j+1];
	                a[j+1]=temp;
	            }
	        }
	    }
	}
	if(ch==2){
		for(i=0;i<n;i++){
			for(j=0;j<n-1;j++){
				if(a[j]<a[j+1]){
					temp=a[j];
	                a[j]=a[j+1];
	                a[j+1]=temp;
	            }
	        }
	    }
	}
}
int sub(int a,int b){
	if(a>b)
		return a-b;
	return b-a;
}

/*
OUTPUT:
enter the current position
53
enter the number of requests
8

enter lower bound
0

enter upper bound
199
enter the request string
122 124 37 14 183 98 65 67

enter 1]left    2]right  3]to enter previous loction
1
you have selected LEFT direction

moving left

53-->37-->14-->0-->65-->67-->98-->122-->124-->183
total head movement =236
*/