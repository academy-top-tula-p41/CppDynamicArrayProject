// CppDynamicArrayProject.cpp
#include <iostream>

template <typename T> 
struct DArray
{
    T* items{ nullptr };
    int size{};
};

template <typename T>
void ArrayInit(T* array, int size);

template <typename T>
void ArrayPrint(DArray<T>, bool nl = true);

template <typename T>
void ArrayPushBack(DArray<T>& array, T value);

template <typename T>
void ArrayInsert(T*& array, int& size, int index, T value);

template <typename T>
T ArrayPopBack(T*& array, int& size);

template <typename T>
T ArrayRemove(T*& array, int& size, int index);

template <typename T>
T* ArrayCreate(int size)
{
    return new T[size];
}


int main()
{
    /*int size{};
    int* array = ArrayCreate<int>(10);

    ArrayPrint<int>(array, size);
    
    ArrayPushBack<int>(array, size, 40);
    
    ArrayPrint<int>(array, size);

    int fsize{};
    float* farray = nullptr;

    ArrayPushBack(farray, fsize, 1.5F);*/
    
    DArray<int> iarray;
    ArrayPushBack<int>(iarray, 100);
    ArrayPushBack(iarray, 200);
    ArrayPushBack(iarray, 300);

    ArrayPrint<int>(iarray);

    DArray<double> darray;
    ArrayPushBack(darray, 100.5);

    std::cout << iarray.size << " " << darray.size << "\n";
}





template <typename T>
void ArrayInit(T* array, int size)
{
    srand(time(nullptr));
    for (int i{}; i < size; i++)
        array[i] = rand() % 100;
}

template <typename T>
void ArrayPrint(DArray<T> array, bool nl)
{
    for (int i{}; i < array.size; i++)
        std::cout << array.items[i] << " ";
    
    if (nl) std::cout << "\n";
}

template <typename T>
void ArrayPushBack(DArray<T>& array, T value)
{
    T* arrayNew = new T[array.size + 1];
    
    for (int i{}; i < array.size; i++)
        arrayNew[i] = array.items[i];

    arrayNew[array.size] = value;
    
    delete[] array.items;
    array.items = arrayNew;
    array.size++;
}

template <typename T>
void ArrayInsert(T*& array, int& size, int index, T value)
{
    T* arrayNew = new T[size + 1];

    for (int i{}; i < index; i++)
        arrayNew[i] = array[i];
    
    arrayNew[index] = value;

    for (int i{ index }; i < size; i++)
        arrayNew[i + 1] = array[i];

    delete[] array;
    array = arrayNew;
    size++;
}

template <typename T>
T ArrayPopBack(T*& array, int& size)
{
    T value{ array[size - 1] };

    T* arrayNew = new T[size - 1];
    for (int i{}; i < size - 1; i++)
        arrayNew[i] = array[i];

    delete[] array;
    array = arrayNew;
    size--;

    return value;
}

template <typename T>
T ArrayRemove(T*& array, int& size, int index)
{
    T value{ array[index] };

    T* arrayNew = new T[size - 1];

    for(int i{}; i < index; i++)
        arrayNew[i] = array[i];
    for (int i{ index + 1 }; i < size; i++)
        arrayNew[i - 1] = array[i];

    delete[] array;
    array = arrayNew;
    size--;

    return value;
}
