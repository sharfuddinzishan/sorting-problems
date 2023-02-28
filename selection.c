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
void selectionSort(int arr[], int num)
{
    for (int i = 0; i < n; i++)
    {
        ++outerLoop;
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            ++innerLoop;
            if (arr[j] < arr[min])
                min = j;
        }
        if (min != i)
            swap(&arr[min], &arr[i]);
    }
}

int main()
{
    getInput();
    selectionSort(data, n);
    show();
    printf("\nouter %d and inner %d", outerLoop, innerLoop);
}