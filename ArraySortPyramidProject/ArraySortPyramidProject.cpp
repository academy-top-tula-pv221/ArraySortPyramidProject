#include <iostream>

void ArrayInit(int* array, int size)
{
    for (int i = 0; i < size; i++)
        array[i] = rand() % 100;
}

void ArrayPrint(int* array, int size)
{
    for (int i = 0; i < size; i++)
        std::cout << array[i] << " ";
    std::cout << "\n";
}

void MySwap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

void Heapify(int* array, int size, int indexParent)
{
    
    int indexLeft = 2 * indexParent + 1;
    int indexRight = 2 * indexParent + 2;

    int indexLargest = indexLeft;
    if (indexRight < size && array[indexLargest] < array[indexRight])
        indexLargest = indexRight;

    if (indexLargest < size && array[indexLargest] > array[indexParent])
    {
        MySwap(array[indexLargest], array[indexParent]);
        Heapify(array, size, indexLargest);
    }
}

void ArraySortHeap(int* array, int size)
{
    for (int i = size / 2 - 1; i >= 0; i--)
        Heapify(array, size, i);
    
    for (int isize = size - 1; isize >= 0; isize--)
    {
        MySwap(array[0], array[isize]);
        Heapify(array, isize, 0);
    }
}

int main()
{
    srand(time(nullptr));

    int size{ 20 };
    int* array = new int[size];
    ArrayInit(array, size);
    ArrayPrint(array, size);
    ArraySortHeap(array, size);
    ArrayPrint(array, size);

    return 0;
}
