// task3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cstring>

using namespace std;

int refactoredArray(char abcd[]) {
    int size = strlen(abcd);
    int sizeForDynamicArray = 1;
    int* pointerSizeForDynamicArray;
    pointerSizeForDynamicArray = &sizeForDynamicArray;
    //while (sizeForDynamicArray <= size) {
    //    sizeForDynamicArray *= 2;
    //}
    //int sizeForDynamicArray = (int)ceil((double)(size / 2));
    while (size % 3 != 0)
    {
        size--;
    }
    if (size <= 2)
    {
        return 0;
    }
    if (size % 3 == 0)
    {
        *pointerSizeForDynamicArray = (int)ceil((double)(size / 2));
        int k = 0;
        int f = 0;
        /*char* refactoredArr = new char[(sizeForDynamicArray/2)+1];*/
        char* refactoredArr = new char[sizeForDynamicArray+3];
        if (size < 9)
        {
            for (int j = 0; j < 3; j++)
            {
                refactoredArr[k] = abcd[j];
                k++;
            }
            refactoredArr[k] = '\0';
        }
        else {
            for (int i = 0; i <= size; i = i + 6)
            {
                if (i + 3 <= size) {
                    for (int j = 0; j < 3; j++, k++)
                    {
                        if (abcd[i + j] == '\0') break;
                        refactoredArr[k] = abcd[i + j];
                    }
                }
            }
            refactoredArr[k] = '\0';
        }
        for (int i = 0; i < strlen(refactoredArr); i++) 
        {
            cout << refactoredArr[i];
        }
        delete[] refactoredArr;
        return 1;
    }
}

int main()
{
    char abcd[13]{'a', '\0' };
    //char abcd[13] {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'k', 'l', 'm', '\0'};
    //char abcd[13]{ 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'g', 'i', '\0' };
    //char abcd[13]{ 'a', 'b', 'c', 'd', '\0' };

    refactoredArray(abcd);
}

// указатели
//оба массива динамические, обработка массива ( из исходного в выходной должно происходить в функции), учитывать количество строк и столбцов! должно работать с разными примерами
//двумерные динамические массивы
//по желанию лаба - морской бой m*n клеток, m - размер максимально большого корабля
// лошара.