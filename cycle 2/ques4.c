#include <stdio.h>
#define maxterms 100
typedef struct
{
    int row;
    int col;
    int value;
}sparse;

sparse sp1[maxterms];
sparse sp2[maxterms];
int size1, size2;
 sparse sparseSum[maxterms];
int sumsize;
int ROWS, COLS;
int matrix1[100][100], matrix2[100][100];
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
    
    for (int i = 1; i <=nonzero; i++)
    {
        
        printf("%d\t%d\t%d", sp[i].row, sp[i].col, sp[i].value);
        printf("\n");
    }
}
void CalculateSum(sparse sp1[],sparse sp2[],int size1,int size2)
{
    sparseSum[0].row = sp1[0].row;
    sparseSum[0].col = sp1[0].col;
    int i = 1, j = 1, k = 1;
    while (i <=size1 && j <= size2)
    {
        if (sp1[i].row == sp2[j].row && sp1[i].col == sp2[j].col) 
        {
            sparseSum[k].row = sp1[i].row;
            sparseSum[k].col = sp1[i].col;
            sparseSum[k].value = sp1[i].value + sp2[j].value;
            i++;
            j++;
        }
        else if (sp1[i].row == sp2[j].row) 
        {
            sparseSum[k].row = sp1[i].row;
            if (sp1[i].col < sp2[j].col && i < size1)
            {
                sparseSum[k].col = sp1[i].col;
                sparseSum[k].value = sp1[i].value;
                i++;
            }
            else 
            {
                sparseSum[k].col = sp2[j].col;
                sparseSum[k].value = sp2[j].value;
                j++;
            }
        }
        else 
        {
            if (sp1[i].row < sp2[j].row) 
            {
                sparseSum[k].row = sp1[i].row;
                sparseSum[k].col = sp1[i].col;
                sparseSum[k].value = sp1[i].value;
                i++;
            }
            else 
            {
                sparseSum[k].row = sp2[j].row;
                sparseSum[k].col = sp2[j].col;
                sparseSum[k].value = sp2[j].value;
                j++;
            }
        }
        k++;
    }
    while (i < size1) 
    {
        sparseSum[k].row = sp1[i].row;
        sparseSum[k].col = sp1[i].col;
        sparseSum[k].value = sp1[i].value;
        k++;
        i++;
    }
    while (j < size2) 
    {
        sparseSum[k].row = sp2[j].row;
        sparseSum[k].col = sp2[j].col;
        sparseSum[k].value = sp2[j].value;
        k++;
        j++;
    }
    sumsize = k;
    sparseSum[0].value = k - 1;
}


int main()
{
    int i, j, row2, col2,non_zero1,non_zero2;
    printf("\nEnter Dimensions of matrix 1\n");
    scanf("%d\n%d", &ROWS, &COLS);
    printf("Enter the no of non zero values:");
    scanf("%d", &non_zero1);
 
    printf("\nEnter Dimensions of matrix 2\n");
    scanf("%d%d", &row2, &col2);
     printf("Enter the no of non zero values:");
    scanf("%d", &non_zero2);
    if (row2 != ROWS || col2 != COLS)
    {
        printf("\nInvalid dimensions for addition\n");
        return 0;
    }
     printf("Enter matrix 1 elements:\n");
     inputSparse(sp1,non_zero1);
    
    printf("\nSparse Matrix 1 \n");
    displayToSparseMatrix(sp1,ROWS,COLS,non_zero1);
     printf("Enter matrix 2 elements:\n");
    inputSparse(sp2, non_zero2);
    printf("\nSparse Matrix 2\n ");
    displayToSparseMatrix(sp2,ROWS,COLS,non_zero2);
  
    CalculateSum(sp1,sp2,non_zero1,non_zero2);
    printf("\nSum of Sparse Matrices\n");
    displayToSparseMatrix(sparseSum, ROWS,COLS,sparseSum[0].value);
      return 0;
}