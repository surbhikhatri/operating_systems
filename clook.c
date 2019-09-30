//AIM:CLOOK ALGO
#include<stdio.h>

int sub(int,int);
void sort(int a[],int);
int main()
{	
	int i,cp,n,x=0,y=0,z=0,dir;
	//x is less index and y is more index z is opr index
	printf("enter the current position\n");
    scanf("%d",&cp);
    printf("enter the number of requests\n");
    scanf("%d",&n);
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
	sort(less,x);
	sort(more ,y);
	
	for(i=0;i<x;i++)
		printf("%d\t",less[i]);
	for(i=0;i<y;i++)
		printf("%d\t",more[i]);
	
	switch(dir){
		case 1:	printf("\nmoving left\n");
			  	for(i=0;i<x;i++){
			  		opr[z]=less[i];
			  		z++;
			  	}
			  	for(i=0;i<y;i++){
			  		opr[z]=more[i];
			  		z++;
				}
				break;
		case 2:	printf("\nmoving right\n");
			  	for(i=0;i<y;i++){
			  		opr[z]=less[i];
			  		z++;
			  	}
			  	for(i=0;i<x;i++){
			  		opr[z]=more[i];
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

void sort(int a[],int n){
	int i,j,temp=0;
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
int sub(int a,int b){
	if(a>b)
		return a-b;
	return b-a;
}
/*
OUPUT:

enter the current position
53
enter the number of requests
8
enter the request string
98 138 14 37 122 124 65 67

enter 1]left    2]right  3]to enter previous loction
3

enter previous location
90
moving left

53-->37-->14-->138-->124-->122-->98-->67-->65
total head movement =236
*/