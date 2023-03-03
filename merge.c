#include <stdio.h>

int data[50];
int n;

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
void merge(int arr[], int start, int end, int mid)
{
    int i = 0, j = 0, k = start;
    int n1 = mid - start;
    int n2 = end - mid;
    int A[n1], B[n2];
    for (int i = 0; i <= n1; i++)
        A[i] = arr[start + i];
    for (int i = 0; i < n2; i++)
        B[i] = arr[mid + 1 + i];

    while (i <= n1 && j < n2)
    {
        if (A[i] < B[j])
            arr[k++] = A[i++];
        else
            arr[k++] = B[j++];
    }
    for (; i <= n1; i++)
        arr[k++] = A[i];
    for (; j < n2; j++)
        arr[k++] = B[j];
}
void mergeSort(int arr[], int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, end, mid);
    }
}

int main()
{
    getInput();
    mergeSort(data, 0, n - 1);
    show();
}