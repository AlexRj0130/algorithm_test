#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

void InsertionSort(vector<int> &array)
{
    for (int i = 1; i < array.size(); i++)
    {
        int tmp = array[i];
        int j = i - 1;
        for (; j > 0; j--)
        {
            if (array[j] < tmp)
            {
                break;
            }
            array[j + 1] = array[j];
        }
        array[j+1] = tmp;
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

    InsertionSort(array);  // expected: 1 2 3 4 5 6 7 8 9

    for (int i = 0; i < array.size(); i++)
    {
        cout << array[i] << ",";
    }
    cout << endl;

    return 0;
}