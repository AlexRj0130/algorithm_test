#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

void CountSort(vector<int> &array)
{
    vector<int>::iterator minIter = min_element(array.begin(), array.end());
    vector<int>::iterator maxIter = max_element(array.begin(), array.end());
    
    vector<int> count(*maxIter - *minIter + 1, 0);
    for (int i = 0; i < array.size(); i++)
    {
        count[array[i] - *minIter] ++;
    }

    for (int i = 0; i < array.size();)
    {
        for (int j = 0; j < count.size(); j++)
        {
            for (int k = count[j]; k > 0; k--)
            {
                array[i++] = j + *minIter;
            }
        }
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

    CountSort(array);  // expected: 1 2 3 4 5 6 7 8 9

    for (int i = 0; i < array.size(); i++)
    {
        cout << array[i] << ",";
    }
    cout << endl;

    return 0;
}