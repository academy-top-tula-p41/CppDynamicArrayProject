// CppDynamicArrayProject.cpp
#include <iostream>

void ArrayInit(int* array, int size);
void ArrayPrint(int* array, int size, bool nl = true);

void ArrayPushBack(int*& array, int& size, int value);
void ArrayInsert(int*& array, int& size, int index, int value);
int ArrayPopBack(int*& array, int& size);
int ArrayRemove(int*& array, int& size, int index);

int main()
{
    int size{};
    int* array = nullptr;

    ArrayPrint(array, size);
    
    ArrayPushBack(array, size, 40);
    
    ArrayPrint(array, size);
}

void ArrayInit(int* array, int size)
{
    srand(time(nullptr));
    for (int i{}; i < size; i++)
        array[i] = rand() % 100;
}

void ArrayPrint(int* array, int size, bool nl)
{
    for (int i{}; i < size; i++)
        std::cout << array[i] << " ";
    
    if (nl) std::cout << "\n";
}

void ArrayPushBack(int*& array, int& size, int value)
{
    int* arrayNew = new int[size + 1];
    
    for (int i{}; i < size; i++)
        arrayNew[i] = array[i];

    arrayNew[size] = value;
    
    delete[] array;
    array = arrayNew;
    size++;
}

void ArrayInsert(int*& array, int& size, int index, int value)
{
    int* arrayNew = new int[size + 1];

    for (int i{}; i < index; i++)
        arrayNew[i] = array[i];
    
    arrayNew[index] = value;

    for (int i{ index }; i < size; i++)
        arrayNew[i + 1] = array[i];

    delete[] array;
    array = arrayNew;
    size++;
}

int ArrayPopBack(int*& array, int& size)
{
    int value{ array[size - 1] };

    int* arrayNew = new int[size - 1];
    for (int i{}; i < size - 1; i++)
        arrayNew[i] = array[i];

    delete[] array;
    array = arrayNew;
    size--;

    return value;
}

int ArrayRemove(int*& array, int& size, int index)
{
    int value{ array[index] };

    int* arrayNew = new int[size - 1];

    for(int i{}; i < index; i++)
        arrayNew[i] = array[i];
    for (int i{ index + 1 }; i < size; i++)
        arrayNew[i - 1] = array[i];

    delete[] array;
    array = arrayNew;
    size--;

    return value;
}
