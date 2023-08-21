// Set Data Structure
#include <stdio.h>
#include <stdlib.h>
struct Array
{
    int used_size;
    int total_size;
    int *ptr;
};

void createArray(struct Array *a, int tSize, int uSize)
{
    a->total_size = tSize;
    a->used_size = uSize;
    a->ptr = (int *)malloc(tSize * sizeof(int));
}

void show(struct Array *a)
{
    for (int i = 0; i < a->used_size; i++)
    {
        printf(": %d :", (a->ptr)[i]);
    }
    printf("\n used_size: %d\n", a->used_size);
}

void CheckDuplicate(struct Array *a)
{
    for (int i = 0; i < a->used_size; i++)
    {
        int j = i + 1;
        while (j < a->used_size)
        {
            if ((a->ptr)[i] == (a->ptr)[j])
            {
                for (int k = j; k < a->used_size - 1; k++)
                {
                   (a->ptr)[k]  = (a->ptr)[k+1];
                }
                a->used_size -= 1;
                if ((a->ptr)[i] != (a->ptr)[j])
                    j++;
            }
            else
            {
                j++;
            }
        }
    }
}

void add(struct Array *a)
{
    int n;
    printf("Enter element to add: \n");
    scanf("%d", &n);
    a->used_size += 1;
    (a->ptr)[a->used_size - 1] = n;
    CheckDuplicate(a);
}

void delete(struct Array *a){
     printf("element %d deleted ",(a->ptr)[a->used_size -1]);
     a->used_size -= 1;
     
}

void setVal(struct Array *a)
{
    int n;
    for (int i = 0; i < a->used_size; i++)
    {
        printf("Enter element %d: ", i);
        scanf("%d", &n);
        (a->ptr)[i] = n;
    }
    CheckDuplicate(a);
}

int main()
{
    struct Array a1;
    int c;
    int ts, us;
    while (1)
    {
        printf("\n 1.Create Array \n 2. Display \n 3. add \n 4. delete");
        scanf("%d",&c);
        switch (c)
        {
        case 1:
            printf("Enter total size: \n");
            scanf("%d", &ts);
            printf("Enter used size: \n");
            scanf("%d", &us);
            createArray(&a1, ts, us);
            printf("Set Value \n");
            setVal(&a1);
            break;
        case 2:
            printf("Display : \n");
            show(&a1);
            break;
        case 3:
            add(&a1);
            break;
        case 4:
            delete(&a1);
            break;
        }
    }
}