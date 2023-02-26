#include <stdio.h>
#include <string.h>
int data[] = {};
int size;
void getInputs()
{
    int n, i = 0;
    printf("How Many Numbers You Want?");
    scanf("%d", &n);
    size = n;
    printf("\nEnter Numbers By Spacing or Pressing ENTER");
    while (n)
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
    for (int i = 0; i < size; i++)
    {
        printf("%d ", data[i]);
    }
}
void heapify(int arr[], int end, int i)
{
    int max = i;
    int left = i * 2;
    int right = i * 2 + 1;
}
int main()
{
    getInputs();
    show("Prev");
}