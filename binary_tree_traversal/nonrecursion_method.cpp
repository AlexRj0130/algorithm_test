#include <iostream>

#include <stack>

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
    stack<BinTree *> stk;
    stk.push(root);
    while (! stk.empty()) {
        BinTree * p = stk.top();
        stk.pop();
        cout << p->val << ",";
        
        if (p->right != NULL) {
            stk.push(p->right);
        }
        if (p->left != NULL) {
            stk.push(p->left);
        }
    }
};

void FirstOrder2(BinTree * root)
{
    BinTree * p = root;
    stack<BinTree *> stk;
    while (p != NULL || ! stk.empty()) {
        if (p != NULL) 
        {
            cout << p->val << ",";
            stk.push(p);
            p = p -> left;
        }
        else 
        {
            p = stk.top();
            stk.pop();
            p = p ->right;
        }
    }
}

void LastOrder(BinTree * root)
{
    if (root == NULL)
    {
        return;
    }   
    stack<BinTree *> stk;
    BinTree * p = root;
    BinTree * last = root;

    stk.push(p);
    while (! stk.empty())
    {
        p = stk.top();
        if ((p->left == NULL && p->right == NULL) || (p->right == NULL && p->left == last) || (p->right == last))
        {
            cout << p->val << ",";
            last = p;
            stk.pop();
        }
        else
        {
            if (p->right != NULL)
            {
                stk.push(p->right);
            }
            if (p->left != NULL)
            {
                stk.push(p->left);
            }
        }
    }
};

void MidOrder(BinTree * root)
{
    stack<BinTree *> stk;
    BinTree * p = root;
    while(p != NULL || !stk.empty()) 
    {
        if (p != NULL)
        {
            stk.push(p);
            p = p->left;
        }
        else
        {
            p = stk.top();
            stk.pop();
            cout << p->val << ",";
            p = p->right;
        }
    }
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
    FirstOrder2(root);
    cout << endl;

    LastOrder(root);  // expected: 4, 8, 5, 2, 9, 6, 7, 3, 1
    cout << endl;
    MidOrder(root);  // expected: 4, 2, 8, 5, 1, 6, 9, 3, 7
    cout << endl;
    return 0;
}