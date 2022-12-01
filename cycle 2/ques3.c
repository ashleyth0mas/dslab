
#include <stdio.h>
int main()
{
    typedef struct
    {
        int row;
        int col;
        int value;
    } elements;
    elements sparse[100];
    int rownum, colnum, count;
    printf("Enter total number of rows, columns and non-zero values : ");
    scanf("%d%d%d", &rownum, &colnum, &count);
    printf("Enter row, column and non-zero value : \n");
    for (int i = 1; i <= count; i++)
    {
        scanf("%d%d%d", &sparse[i].row, &sparse[i].col, &sparse[i].value);
    }
    sparse[0].row = rownum;
    sparse[0].col = colnum;
    sparse[0].value = count;
    printf("Sparse representation is : \n");
    for (int i = 0; i <= count; i++)
            printf("%d\t%d\t%d\n", sparse[i].row, sparse[i].col, sparse[i].value);
        float sparsity = (float)(sparse[0].row * sparse[0].col - sparse[0].value) / (sparse[0].row *      sparse[0].col);
    printf("Sparsity : %0.2f\n", sparsity);
}


