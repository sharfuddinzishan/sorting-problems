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
void insertionSort(int arr[], int num)
{
    for (int i = 1; i < n; i++)
    {
        int value = arr[i];
        int hole = i;

        while (hole > 0)
        {
            if (arr[hole - 1] > value)
            {
                arr[hole] = arr[hole - 1];
                hole--;
            }
            else
                break;
        }
        arr[hole] = value;
    }
}

int main()
{
    getInput();
    insertionSort(data, n);
    show();
}