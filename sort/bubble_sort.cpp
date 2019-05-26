#include <iostream>

#include <vector>

using namespace std;

void BubbleSort(vector<int> &array)
{
    for (int i = 0; i < array.size(); i++)
    {
        int count = 0;
        int value = array[0];
        for (int j = 1; j < array.size() - i; j++)
        {
            if (value <= array[j])
            {
                value = array[j];
            } 
            else 
            {
                int tmp = array[j];
                array[j] = array[j - 1];
                array[j - 1] = tmp;
                count++;
            }
        }
        if (0 == count)
        {
            break;
        }
    }

    for (int i = 0; i < array.size(); i++)
    {
        cout << array[i] << ",";
    }
    cout << endl;
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

    BubbleSort(array);  // expected: 1 2 3 4 5 6 7 8 9

    return 0;
}