// CppDynamicArrayProject.cpp
#include <iostream>

void ArrayInit(int* array, int size);
void ArrayPrint(int* array, int size, bool nl = true);

void ArrayPushBack(int*& array, int& size, int value);

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
    
    delete array;
    array = arrayNew;
    size++;
}