//AIM:SSTF
#include<stdio.h>
int sub(int,int);
void sort(int a[],int,int);
int main()
{	
	int i,cp,n,x=0,y=0,z=0,dir,j;
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
	sort(less,x,2);
	sort(more ,y,1);


    int tp=cp;
    i=j=0;
    int k,m;
    for(k=0;k<x+y;k++){
        if(sub(tp,less[i]) < sub(tp,more[j])){
            //printf("less %d\t",less[i]);
            opr[z]=less[i];
            tp=less[i];
            k++;
            i++;
            z++;
            
        }
        else{
            opr[z]=more[j];
            //printf("more %d\t",more[j]);
            tp=more[j];
            k++;
            z++;
            j++;
            
        }
        if(i==x){
            for(m=j;m<y;m++){
                opr[z]=more[m];
                z++;
            }
        }
        if(j==y){
            for(m=i;m<x;m++){
                opr[z]=less[m];
                z++;
            }
        }
    }
    int head=0,str,temp=0;
    printf("\n");
	for(i=0;i<z;i++){
		//printf("%d",cp);
		temp=sub(cp,opr[i]);
		head=head+temp;
		//printf("head %d",head);
		if(i==0)
			printf("%d-->%d",cp,opr[0]);
		else
			printf("-->%d",opr[i]);
		cp=opr[i];
		opr[i]=-1;
		
		
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
enter the request string
183 98 122 124 14 37 65 67

enter 1]left    2]right  3]to enter previous loction
1
you have selected LEFT direction
53-->65-->67-->37-->14-->98-->122-->124-->183
total head movement =236
*/