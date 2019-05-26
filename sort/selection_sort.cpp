#include <iostream>

#include <vector>

using namespace std;

void SelectionSort(vector<int> &array)
{
    for (int i = 0; i < array.size(); i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < array.size(); j++)
        {
            if (array[j] < array[minIndex])
            {
                minIndex = j;
            }
        }
        int tmp = array[i];
        array[i] = array[minIndex];
        array[minIndex] = tmp;
    }
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

    SelectionSort(array);

    for (int i = 0; i < array.size(); i++)
    {
        cout << array[i] << ",";
    }
    cout << endl;

    return 0;
}