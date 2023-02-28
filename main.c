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
void sort(int arr[], int num)
{
    printf("\nHello %d %d", num, arr[0]);
}

int main()
{
    getInput();
    sort(data, n);
}