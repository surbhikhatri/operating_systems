AIM:FCFS ALGORITHM
# include<stdio.h>
int main()
{
	int n,a[20],i,count,sum=0;
	printf("enter the no of request \n");
	scanf("%d",&n);
	printf("enter the requests \n");
	for(i=0;i<n;i++){
  		scanf("%d",&a[i]);
  	}
  	printf("head movement \n");
	for(i=0;i<n-1;i++){
		if(a[i]>a[i+1])
			count=a[i]-a[i+1];
		else
			count=a[i+1]-a[i];
		sum=sum+count;
		printf("a[%d]-a[%d]=%d",a[i],a[i+1],count);
	}
	printf("total head movement= %d \n",sum);
}
/*
output:

enter the no of request
8
enter the requests
98 183 14 37 122 124 65 67
head movement
a[98]-a[183]=85
a[183]-a[14]=169
a[14]-a[37]=23
a[37]-a[122]=85
a[122]-a[124]=2
a[124]-a[65]=59
a[65]-a[67]=2
total head movement= 425
*/