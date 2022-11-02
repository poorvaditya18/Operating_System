#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid + 1] == x)
            return mid + 1;

        if (arr[mid + 1] > x)
            return binarySearch(arr, l, mid, x);
        return binarySearch(arr, mid + 2, r, x);
    }
}

int main(int argc, char *argv[])
{
    int status, n, x[argc - 1];
    int l, h;
    for (int i = 1; i < argc; i++)
    {
        x[i] = atoi(argv[i]);
    }
    printf("\nEnter number to be searched: ");
    scanf("%d", &n);

    int result = binarySearch(x, 1, argc - 1, n);
    if (result == -1)
    {
        printf("\nElement no found");
    }
    else
    {
        printf("\nElement found at index %d", result);
    }
}
