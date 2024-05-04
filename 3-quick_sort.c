#include "sort.h"
/* Definitions */
void quick_sort_aid(int *array, int left, int right, size_t size);
int partition(int *array, int left, int right, size_t size);

/*
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * 
 * @array: array to be sorted
 * @size: size of the array
 * Return: void
*/
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;
    quick_sort_aid(array, 0, size - 1, size);
}

/*
 * quick_sort_aid - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * 
 * @array: array to be sorted
 * @left: left index
 * @right: right index
 * @size: size of the array
 * Return: void
*/
void quick_sort_aid(int *array, int left, int right, size_t size)
{
    int pivot;

    if (left < right)
    {
        pivot = partition(array, left, right, size);

        quick_sort_aid(array, left, pivot - 1, size);
        quick_sort_aid(array, pivot + 1, right, size);
    }
}

/*
 * partition - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * 
 * @array: array to be sorted
 * @left: left index
 * @right: right index
 * @size: size of the array
 * Return: void
*/
int partition(int *array, int left, int right, size_t size)
{
    int pivot, i, j, tmp;

    pivot = array[right];
    i = left + 1;

    for (j = left; j < right; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            if (i != j)
            {
                tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;

                print_array(array, size);
            }
        }
    }

    if (array[i + 1] > pivot)
    {
        tmp = array[i + 1];
        array[i + 1] = array[right];
        array[right] = tmp;

        print_array(array, size);
    }
    return (i + 1);
}   