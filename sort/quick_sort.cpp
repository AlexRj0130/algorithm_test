#include <iostream>

#include <vector>

using namespace std;

int division(vector<int> &array, int left, int right) {
    int base = array[left];
    while(left < right)
    {
        while(left < right && array[right] >= base)
        {
            right --;
        }
        array[left] = array[right];
        
        while(left < right && array[left] <= base)
        {
            left ++;
        }
        array[right] = array[left];
    }
    array[left] = base;
    return left;
}

void QuickSort(vector<int> &array, int sta, int end)
{
    if (sta >= end)
    {
        return;
    }
    int mid = division(array, sta, end);
    QuickSort(array, sta, mid - 1);
    QuickSort(array, mid + 1, end);
}

int main()
{
    vector<int> array;
    
    array.push_back(1);
    array.push_back(3);
    array.push_back(5);
    array.push_back(6);
    array.push_back(2);
    array.push_back(4);
    array.push_back(9);
    array.push_back(7);
    array.push_back(8);

    QuickSort(array, 0, array.size() - 1);  // expected: 1 2 3 4 5 6 7 8 9

    for (int i = 0; i < array.size(); i++)
    {
        cout << array[i] << ",";
    }
    cout << endl;

    return 0;
}