#include <stdio.h>

int data[50];
int n;
int outerLoop = 0;
int innerLoop = 0;

void show()
{
    printf("\nNumbers are: ");
    for (int i = 0; i < n; i++)
        printf("%d ", data[i]);
}
void getInput()
{
    printf("\nHow Many Numbers You Want? ");
    scanf("%d", &n);
    if (n > 50)
        n = 50;
    printf("\nprovide %d numbers by pressing ENTER key", n);
    for (int i = 0; i < n; i++)
    {
        printf("\nInput %d : ", i + 1);
        scanf("%d", &data[i]);
    }
    show();
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[], int start, int end)
{
    int pivot = start;
    //  i=start+1 not used if pivot is smaller than all like 1 1 2 then loop always be tru, never stop
    int i = start;
    int j = end;
    while (i < j)
    {
        outerLoop++;
        // If i < end missed then inner loop will be 989 times; as i will be continute to incremented
        while (arr[i] <= arr[pivot] && i < end)
        {
            innerLoop++;
            i++;
        }
        while (arr[pivot] < arr[j])
        {
            innerLoop++;
            j--;
        }
        if (i < j)
            swap(&arr[i], &arr[j]);
    }
    swap(&arr[j], &arr[pivot]);
    return j;
}
void quickSort(int arr[], int start, int end)
{
    if (start < end)
    {
        int loc = partition(arr, start, end);
        quickSort(arr, start, loc - 1);
        quickSort(arr, loc + 1, end);
    }
}

int main()
{
    getInput();
    quickSort(data, 0, n - 1);
    show();
    printf("\nouter %d and inner %d", outerLoop, innerLoop);
}