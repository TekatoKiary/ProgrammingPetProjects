#include <iostream>
#include <vector>

using namespace std;

void swapValues(int array[], int firstIndex, int secondIndex)
{
    int x = array[firstIndex];
    array[firstIndex] = array[secondIndex];
    array[secondIndex] = x;
}

void insertionSort(int array[], int length)
{
    for (int i = 1; i < length; i++)
        for (int j = i; j > 0; j--)
            if (array[j] < array[j - 1])
                swapValues(array, j, j - 1);
            else
                break;
}

int binareSearch(int array[], int length, int findNumber)
{
    int left = 0;
    int right = length - 1;
    while (left <= right)
    {
        int middle = (right + left) / 2;
        if (array[middle] > findNumber)
            right = middle - 1;
        else if (array[middle] < findNumber)
            left = middle + 1;
        else
            return middle + 1;
    }
    return -1;
}

int recurse(int array[], int left, int right, int findNumber)
{
    if (left > right)
        return -1;
    int middle = (right + left) / 2;
    if (array[middle] > findNumber)
        return recurse(array, left, middle - 1, findNumber);
    else if (array[middle] < findNumber)
        return recurse(array, middle + 1, right, findNumber);
    else
        return middle + 1;
}

int main() {
    setlocale(LC_ALL, "Rus");
    int array[]{ 2, 1, 7, 8, 9, 6, 5, 120 };
    int length = sizeof(array) / sizeof(array[0]);
    insertionSort(array, length);
    for (int i = 0; i < length; i++)
        cout << array[i] << ' ';
    int findNumber;
    cout << endl << "Введите искомое число: ";
    cin >> findNumber;
    //cout << endl << recurse(array, 0, length - 1, findNumber); // Вариант с рекурскией
    cout << endl << binareSearch(array, length, findNumber); // Вариант через цикл while
}