#include <stdio.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(int arr[], int i, int n)
{
    int maxheap = i;
    int left = (i * 2) + 1;
    int right = (i * 2) + 2;
    if (left <= n && arr[maxheap] < arr[left])
        maxheap = left;
    if (right <= n && arr[maxheap] < arr[right])
        maxheap = right;
    if (maxheap != i)
    {
        swap(&arr[maxheap], &arr[i]);
        heapify(arr, maxheap, n);
    }
}
void heapSort(int arr[], int n)
{
    for (int parent = n / 2; parent >= 0; parent--)
    {
        heapify(arr, parent, n);
    }
    // delete by swapping with last element to root
    for (int i = n; i >= 0; i--)
    {
        swap(&arr[i], &arr[0]);
        heapify(arr, 0, i - 1);
    }
}

int main()
{
    int arr[6] = {10, 29, 20, 30, 1, 50};
    heapSort(arr, 5);
    for (int i = 0; i < 6; i++)
    {
        printf("%d ", arr[i]);
    }
}