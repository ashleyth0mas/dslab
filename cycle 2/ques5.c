#include <stdio.h>
#define maxterms 100
typedef struct
{
    int row;
    int col;
    int value;
}sparse;
int ROWS,COLS,k=1;
sparse spm[maxterms];
sparse tsp[maxterms];
void inputSparse(sparse sp[],int nonzero)
{
    
    for(int i=1;i<=nonzero;i++)
    scanf("%d\t%d\t%d",&sp[i].row,&sp[i].col,&sp[i].value);
}


void displayToSparseMatrix(sparse sp[],int r,int c, int nonzero)
{
    
    sp[0].row=r;
    sp[0].col=c;
    sp[0].value=nonzero;
     
    printf("%d\t%d\t%d \n", sp[0].row, sp[0].col, sp[0].value);
    
    for (int i = 1; i<=nonzero; i++)
    {
        
        printf("%d\t%d\t%d", sp[i].row, sp[i].col, sp[i].value);
        printf("\n");
    }
}
void convertotranspose( sparse sp[])
{
    tsp[0].row=sp[0].col;
    tsp[0].col=sp[0].row;
    tsp[0].value=sp[0].value;
   
    for(int i=0;i<sp[0].col;i++)
    {
        for(int j=1;j<=sp[0].value;j++)
        {
        if(sp[j].col==i)
        
        {
    
        tsp[k].row=i;
        tsp[k].col=sp[j].row;
        tsp[k++].value=sp[j].value;
        }
        }
    }
}
void printranspose()
{
    printf("Transpose:");
    for(int i=0;i<k;i++)
    printf("\n %d  %d  %d \n",tsp[i].row,tsp[i].col,tsp[i].value);
    
}
int main()
{
    int i, j, non_zero;
    printf("\nEnter Dimensions of matrix \n");
    scanf("%d\n%d", &ROWS, &COLS);
    printf("Enter the no of non zero values:");
    scanf("%d", &non_zero);
    printf("Enter the elements:\n");
    inputSparse(spm,non_zero);
    printf("Sparse representation:\n");
    displayToSparseMatrix(spm,ROWS,COLS,non_zero);
    convertotranspose(spm);
    printf("Transpose:\n");
    displayToSparseMatrix(tsp,COLS,ROWS,non_zero);
}