#include<stdio.h>
void arraycombine(int arr[], int st, int md, int end)
{
    int ls = md - st + 1;
    int rs = end - md;
    int leftPart[ls], rightPart[rs];

    for (int a = 0; a < ls; a++)
    {
        leftPart[a] = arr[st + a];
    }
    for (int b = 0; b < rs; b++)
    {
        rightPart[b] = arr[md + 1 + b];
    }
    int i = 0, j = 0, k = st;
    while (i < ls && j < rs)
    {
        if (leftPart[i] < rightPart[j])
        {
            arr[k++] = leftPart[i++];
        }
        else
        {
            arr[k++] = rightPart[j++];
        }
    }
    while (i < ls)
    {
        arr[k++] = leftPart[i++];
    }
    while (j < rs)
    {
        arr[k++] = rightPart[j++];
    }
}
void mergeSort(int arr[], int st, int end)
{
    if (st >= end)
    return;
    int md = st + (end - st) / 2;
    mergeSort(arr, st, md);
    mergeSort(arr, md + 1, end);
    arraycombine(arr, st, md, end);
}
int main()
{
    int size;
    printf("Enter the number of elements: ");
    scanf("%d", &size);
    int data[size];
    printf("Enter %d numbers: ", size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &data[i]);
    }
    mergeSort(data, 0, size - 1);
    printf("Sorted result: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", data[i]);
    }
    printf("\n");
    return 0;
}