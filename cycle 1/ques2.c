#include<stdio.h>
int main()
{
	int i,j,a[100],n,sum=0,temp,max=0,mode,k=0,c[100];
    float mean,median;
	printf("Enter the number of elements in the array\n");

	scanf("%d",&n);
	printf("Enter the elements of the array\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n;i++)
		sum=sum+a[i];
	mean=(float)sum/(float)n;
	printf("Mean of given data : %f\n",mean);	
 	for(i=0;i<n;i++)
  	{
  		for(j=0;j<n-i-1;j++)
   		{
   			if(a[j]>a[j+1])
    			{
    				temp=a[j];
    				a[j]=a[j+1];
    				a[j+1]=temp;
    			}
   		}
  	}
  	if(n%2==0)
  		median=(float)((a[n/2]+a[(n/2)-1])/2);
  	else
  		median=a[(n-1)/2];	
  	printf("Median of the given data : %f\n",median);
  	for(i=0;i<n-1;i++)
  	{
  		mode=0;
  		for(j=i+1;j<n;j++)
   		{
   			if(a[i]==a[j])
   				mode++;
        }
  		if((mode>max)&&(mode!=0))
   		{
   			k=0;
   			max=mode;
   			c[k]=a[i];
			k++;
		}	  
   		else if(mode==max)	   		
  		{
			
			c[k]=a[i];
		}
  	}
    	 if(k==0)
				printf("No mode"); 
		 else  
		 { 
  		printf("Mode of the given data = ");
               for(i=0;i<=k;i++)
          	    printf("%d ",c[i]);
		 }	

return 0;
 }