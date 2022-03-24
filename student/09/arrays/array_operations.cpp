#include "array_operations.hh"

int greatest_v1(int *itemptr, int size)
{
    int greatest = *itemptr;
    int *item = itemptr;
    while (item < itemptr + size)
    {
        if (*item > greatest)
        {
            greatest = *item;
        }
        ++item;
    }
    return greatest;
}

int greatest_v2(int *itemptr, int *endptr)
{
    int greatest = *itemptr;
    while (itemptr != endptr)
    {
        if (greatest < *itemptr)
        {
            greatest = *itemptr;
        }
        ++itemptr;
    }
    return greatest;
}

void copy(int *itemptr, int *endptr, int *targetptr)
{
    while (itemptr != endptr)
    {
        *targetptr = *itemptr;

        ++itemptr;
        ++targetptr;
    }
}

void reverse(int *leftptr, int *rightptr)
{
    int temp;
    --rightptr;
    while (leftptr < rightptr)
    {
        temp = *leftptr;
        *leftptr = *rightptr;
        *rightptr = temp;

        ++leftptr;
        --rightptr;
    }
}
