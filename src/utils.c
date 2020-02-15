#include <limits.h>
#include <stdlib.h>
#include <utils.h>

int max(int array[], int start, int end)
{
    int i, max_idx, max_val;

    max_val = INT_MIN;
    max_idx = -1;

    for (i = start; i <= end; i++)
    {
        if (max_val < array[i])
        {
            max_val = array[i];
            max_idx = i;
        }
    }

    return max_idx;
}

void swap(int array[], int pos1, int pos2)
{
    int temp;

    temp = array[pos1];
    array[pos1] = array[pos2];
    array[pos2] = temp;
}

int sample(int lower, int upper)
{
    int num;

    num = lower + rand() % (upper - lower); 

    return num;
}
