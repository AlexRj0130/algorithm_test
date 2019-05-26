#include <iostream>

using namespace std;

class BinTree {
public:
    BinTree(int val, BinTree *left, BinTree *right)
    {
        this->val = val;
        this->left = left;
        this->right = right;
    }

public:
    int val;
    BinTree *left, *right;
};

void FirstOrder(BinTree * root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->val << ", ";
    FirstOrder(root->left);
    FirstOrder(root->right);
};

void LastOrder(BinTree * root)
{
    if (root == NULL)
    {
        return;
    }
    LastOrder(root->left);
    LastOrder(root->right);
    cout << root->val << ", ";
};

void MidOrder(BinTree * root)
{
    if (root == NULL)
    {
        return;
    }
    MidOrder(root->left);
    cout << root->val << ", ";
    MidOrder(root->right);
};

int main()
{
    BinTree * root = 
        new BinTree(1, 
            new BinTree(2, 
                new BinTree(4, NULL, NULL),
                new BinTree(5, 
                    new BinTree(8, NULL, NULL), 
                    NULL)),  
            new BinTree(3, 
                new BinTree(6, 
                    NULL,
                    new BinTree(9, NULL, NULL)),
                new BinTree(7, NULL, NULL)));

    FirstOrder(root); // expected: 1, 2, 4, 5, 8, 3, 6, 9, 7
    cout << endl;
    LastOrder(root);  // expected: 4, 8, 5, 2, 9, 6, 7, 3, 1
    cout << endl;
    MidOrder(root);  // expected: 4, 2, 8, 5, 1, 6, 9, 3, 7
    cout << endl;
    return 0;
}