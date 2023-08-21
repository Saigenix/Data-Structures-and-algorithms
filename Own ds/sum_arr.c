// Data Structure
#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int total_size;
    int used_size;
    int *ptr;
};

void createArray(struct Array *a, int tSize, int uSize)
{
    a->total_size = tSize;
    a->used_size = uSize + 2;
    a->ptr = (int *)malloc((tSize) * sizeof(int));
}

void show(struct Array *a)
{
    for (int i = 0; i < a->used_size; i++)
    {
        printf(": %d :", (a->ptr)[i]);
    }
    printf("\nTotal Sum: %d\n", (a->ptr)[a->used_size - 2]);
    printf("Total product: %d\n", (a->ptr)[a->used_size - 1]);
}

void SumAndProd(struct Array *a)
{
    int sum = 0;
    int prod = 1;
    for (int i = 0; i < a->used_size - 2; i++)
    {
        sum += (a->ptr)[i];
    }
    for (int i = 0; i < a->used_size - 2; i++)
    {
        prod *= (a->ptr)[i];
    }
    (a->ptr)[a->used_size - 1] = prod;
    (a->ptr)[a->used_size - 2] = sum;
}

void setVal(struct Array *a)
{
    int n;
    // int arr[a->used_size - 2];
    for (int i = 0; i < a->used_size - 2; i++)
    {
        printf("Enter element %d: ", i);
        scanf("%d", &n);
        // arr[i]= n;
        (a->ptr)[i] = n;
    }
    SumAndProd(a);
}

void add(struct Array *a)
{
    int n;
    printf("Enter element : ");
    scanf("%d", &n);
    a->used_size += 1;
    (a->ptr)[a->used_size - 1] = (a->ptr)[a->used_size - 2];
    (a->ptr)[a->used_size - 2] = (a->ptr)[a->used_size - 3];
    (a->ptr)[a->used_size - 3] = n;
    SumAndProd(a);
}
void delete (struct Array *a)
{
    printf("%d deleted", (a->ptr)[a->used_size - 3]);
    (a->ptr)[a->used_size - 3] = (a->ptr)[a->used_size - 2];
    (a->ptr)[a->used_size - 2] = (a->ptr)[a->used_size - 1];
    a->used_size -= 1;
    SumAndProd(a);
}

int main()
{
    struct Array a1;
    int n, m, u;
    while (1)
    {
        printf("\n1.Set Value\t2.Add\t3.Display\t4.Delete\n");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            printf("Enter max size: ");
            scanf("%d", &m);
            printf("Enter Used size: ");
            scanf("%d", &u);
            createArray(&a1, m, u);
            printf("Set Value \n");
            setVal(&a1);
            break;
        case 2:
            add(&a1);
            break;
        case 3:
            printf("Display : \n");
            show(&a1);
            break;
        case 4: delete (&a1);
            break;
        }
        }
        return 0;
    }