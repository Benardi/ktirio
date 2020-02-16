#include <math.h>
#include <utils.h>
#include <heap.h>

#define parent(i)(floor((i - 1) / 2))
#define left(i)(2 * i + 1)
#define right(i)(2 * i + 2)

/* int parent(int i)
{
    return floor(i / 2);
} */
/* int left(int i)
{
    return 2 * i;
}
 */

/* int right(int i)
{
    return 2 * i + 1;
}
 */

void max_heapify(int array[], int heap_size, int i)
{
    int left, right, largest;
    left = left(i);
    right = right(i);

    if (left < heap_size && array[left] > array[i])
    {
        largest = left;
    }
    else
    {
        largest = i;
    }
    if (right < heap_size && array[right] > array[largest])
    {
        largest = right;
    }   
    if (largest != i)
    {
        swap(array, i, largest);
        max_heapify(array, heap_size, largest);
    }
}

void build_max_heap(int array[], int length)
{
    int heap_size, i;

    heap_size = length;
    for (i = parent(length - 1); i > -1; i--)
    {
        max_heapify(array, heap_size, i);
    }
}