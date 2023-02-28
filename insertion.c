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
        // Hole h created after storing ith value in a temp
        int value = arr[i];
        int hole = i;
        // Check value is less than previous element, hole-1 indicates previous element.
        // If true then previous element shifted to hole
        // hole-- used to check next previous element
        /*
        suppose array like 2 3 4 1
        let i is last index(3) so value=array[i]=array[3]=1
        and hole=i=3

        value=1
        hole=3
        arr[hole-1=3-1=2]>value => 4>1 yes so store 4 to hole 3 and decrement hole by 1;
        so, now array like be 2 3 4 4 where value=1 and hole=2

        value=1
        hole=2
        again check arr[hole-1=2-1=1]>value => 3>1 yes so store 3 to hole 2 and decrement hole by 1;
        now array like be 2 3 3 4 where value=1 and hole=1

        value=1
        hole=1
        again check arr[hole-1=1-1=0]>value => 2>1 yes so store 2 to hole 1 and decrement hole by 1;
        now array like be 2 2 3 4 where value=1 and hole=0

        value=1
        hole=0
        Hole>0 but hole now 0 so inner loop end.
        Now store value 1 to hole[0]

        Final array like be 1 2 3 4
        */
        /*
        Why worst complexity o(n^2)?
        for(incrementing i from 0 to n means o(n)){
            for(incrementing j, sometimes named as hole from i to 0 means o(n))
            {

            }
        }
         */
        while (hole > 0 && arr[hole - 1] > value)
        {
            arr[hole] = arr[hole - 1];
            hole--;
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