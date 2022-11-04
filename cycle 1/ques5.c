#include<stdio.h>
void main()
{
	int n,i,j,a[20][20],c[20],k=1,rem;
	long int hex;
	printf("Enter the no of rows\n");
	scanf("%d",&n);
	printf("Enter the elements\n");
	for(i=0;i<n;i++)
		for(j=0;j<4;j++)
    			scanf("%d",&a[i][j]);
	for(i=0;i<n;i++)
	{
		c[i]=(a[i][0]*1000)+(a[i][1]*100)+(a[i][2]*10)+a[i][3];
	}
	printf("Hexadecimal values\n");
	for(i=0;i<n;i++)
	{
		hex=0;
		while (c[i]!=0)
		{
      			rem=c[i]%10;
      			hex=hex+rem*k;
      			k=k*2;
      			c[i]=c[i]/10;
   		}
   		printf("%X",hex);
   	}
   	
} 
