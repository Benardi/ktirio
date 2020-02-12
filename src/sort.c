#include <malloc.h>
#include <limits.h>
#include <time.h>
#include <math.h>
#include <sort.h>
#include <stdlib.h>

# define INFINITY INT_MAX

void insertion_sort(int array[], int length)
{
    int j, i, key;

    for (j = 1; j < length; j++)
    {
        key = array[j];
        i = j - 1; /* last element of sorted deck */
        while (i > -1 && array[i] > key)
        {
            array[i + 1] = array[i];
            i = i - 1;
        }
        array[i + 1] = key;
    }
}

void merge(int array[], int start, int middle, int end)
{
    int* left;
    int* right;
    int n1, n2;
    int i, j, k;

    n1 = middle - start + 1;
    n2 = end - middle;

    left = malloc((n1 + 1)  * sizeof(int));
    right = malloc((n2 + 1) * sizeof(int));

    /* populate left array */
    for (i = 0; i < n1; i++)
    {
        left[i] = array[start + i];
    }

    /* populate right array */
    for (j = 0; j < n2; j++)
    {
        right[j] = array[middle + j + 1];
    }

    left[n1] = INFINITY;
    right[n2] = INFINITY;

    i = j = 0;

    /* transfer values to array in correct order */
    for (k = start; k <= end; k++)
    {
        if (left[i] <= right[j])
        {
            array[k] =  left[i];
            i++;    
        }
        else
        {
            array[k] = right[j];
            j++;
        }
    }

    free(left);
    free(right);
}

void merge_sort(int array[], int start, int end)
{
    int middle;

    if (start < end)
    {
        middle = floor((start + end) / 2);
        merge_sort(array, start, middle);
        merge_sort(array, middle + 1, end);
        merge(array, start, middle, end);
    }
}

static void shift_right_array(int array[], int start, int end)
{
    int i;
       
    for (i = end; i > start; i--)
    {
        array[i] = array[i-1];
    }
}

void inplace_merge(int array[], int start, int middle, int end)
{
    int start1, start2, moved;

    start1 = start;
    start2 = middle + 1;

    while (start1 <= middle && start2 <= end)
    {
        if (array[start1] < array[start2])
        {
            start1++;
        }
        else
        {
            moved = array[start2];
            shift_right_array(array, start1, start2);
            array[start1] = moved;
            start2++;
            start1++;
            middle++;
        }
    }
}

void inplace_merge_sort(int array[], int start, int end)
{
    int middle;

    if (start < end)
    {
        middle = floor((start + end) / 2);
        inplace_merge_sort(array, start, middle);
        inplace_merge_sort(array, middle + 1, end);
        inplace_merge(array, start, middle, end);
    }
}

static void swap(int array[], int pos1, int pos2)
{
    int temp;

    temp = array[pos1];
    array[pos1] = array[pos2];
    array[pos2] = temp;
}

int partition(int array[], int start, int end)
{
    int i, j, pivot;

    pivot = array[end];
    i = start - 1;

    for (j = start; j < end; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            swap(array, i, j);
        }
    }
    swap(array, i + 1, end);

    return i + 1;
}

void quick_sort(int array[], int start, int end)
{
    int middle;

    if (start < end)
    {
        middle = partition(array, start, end);
        quick_sort(array, start, middle - 1);
        quick_sort(array, middle + 1, end);
    }
}

static int sample(int lower, int upper)
{
    int num;

    num = lower + rand() % (upper - lower); 

    return num;
}

int rand_partition(int array[], int start, int end)
{
    int i;
    i = sample(start, end);
    swap(array, end, i);
    return partition(array, start, end);
}

static void random_quick_sort(int array[], int start, int end)
{
    int middle;

    if (start < end)
    {
        middle = rand_partition(array, start, end);
        random_quick_sort(array, start, middle - 1);
        random_quick_sort(array, middle + 1, end);
    }
}

void rand_quick_sort(int array[], int start, int end, unsigned int seed)
{
    srand(seed);
    random_quick_sort(array, start, end);
}

static int max(int array[], int start, int end)
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

void selection_sort(int array[], int start, int end)
{
    int i;
    int max_idx;

    for (i = 0; i < (end - start); i++)
    {
        max_idx = max(array, start, end - i);
        swap(array, max_idx, end - i);
    }
}

void bubble_sort(int array[], int start, int end)
{
    int i, j;

    for (i = start; i < end; i++)
    {
        for (j = end; j > i;  j--)
        {
            if (array[j] < array[j - 1])
            {
                swap(array, j, j - 1);
            }
        }
    }
}