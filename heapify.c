#include <stdio.h>
#include <string.h>
int data[50] = {};
int size;
int outerLoop = 0;
int innerLoop = 0;

void getInputs()
{
    int n, i = 1;
    printf("How Many Numbers You Want?");
    scanf("%d", &n);
    size = n;
    printf("\nEnter Numbers By Spacing or Pressing ENTER");
    while (n > 0)
    {
        printf("\nEnter Numbers[%d]: ", i);
        scanf("%d", &data[i]);
        i++;
        --n;
    }
}
void show(char action[])
{
    int dispatch;
    dispatch = strcmp(action, "Prev") ? 0 : 1;
    if (dispatch)
    {
        printf("\nBefore Sorting: ");
    }
    else
    {
        printf("\nAfter Sorting: ");
    }
    for (int i = 1; i <= size; i++)
    {
        printf("%d ", data[i]);
    }
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(int arr[], int end, int index)
{
    int max = index;
    int left = index * 2;
    int right = (index * 2) + 1;
    while (left <= end & arr[max] < arr[left])
    {
        ++innerLoop;
        max = left;
    }
    while (right <= end & arr[max] < arr[right])
    {
        ++innerLoop;
        max = right;
    }
    if (max != index)
    {
        swap(&arr[index], &arr[max]);
        heapify(arr, end, max);
    }
}
void heapSort(int arr[], int n)
{
    for (int i = n / 2; i >= 1; i--)
    {
        ++outerLoop;
        heapify(arr, n, i);
    }
    for (int i = n; i >= 1; i--)
    {
        ++outerLoop;
        swap(&arr[1], &arr[i]);
        heapify(arr, i - 1, 1);
    }
}
int main()
{
    getInputs();
    show("Prev");
    heapSort(data, size);
    show("Next");
    printf("\nouter %d and inner %d", outerLoop, innerLoop);
}