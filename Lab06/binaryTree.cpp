#include<iostream>
#include <sstream> 
#include <cstdlib> 
#include<stdio.h>
using namespace std;

// Structure definition for binary tree
struct BinaryTreeNode
{
    int value;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
};

BinaryTreeNode* FindMin(BinaryTreeNode *tnode)
{
    if(tnode == NULL)
    {
        return NULL;
    }
    // Go to the left sub tree to find the min element
    if(tnode -> left)
    { 
        return FindMin(tnode -> left);// Recursively call the function to find min
    }
    else
    {
        return tnode;
    }
}

BinaryTreeNode *Insert(BinaryTreeNode *tnode, int value)
{
    if(tnode == NULL)
    {
        BinaryTreeNode *x;
        x = new BinaryTreeNode;
        x -> value = value;
        x -> left = x -> right = NULL;// Initializes left and right node to null
        return x;
    }
    if(value > tnode -> value)
    {
        tnode -> right = Insert(tnode -> right, value);// Insert the node right
    }
    else if(value < tnode -> value)
    {
        tnode -> left = Insert(tnode -> left, value);// Insert the node left
    }

    return tnode;
}

BinaryTreeNode * Delete(BinaryTreeNode *tnode, int value)
{
    BinaryTreeNode *y;
    if(tnode == NULL)
    {
    cout<<"\n Not Found";
    }
    else if(value < tnode -> value)
    {
        tnode -> left = Delete(tnode -> left, value);// calls left child
    }
    else if(value > tnode -> value)
    {
        tnode -> right = Delete(tnode -> right, value);//call right child
    }
    else
    {
        if(tnode -> right && tnode -> left)
        {
            y = FindMin(tnode -> right);//replace with minimum element in the right sub tree
            tnode -> value = y -> value;
            tnode -> right = Delete(tnode -> right, y -> value);//to replaced node,  delete that node
        }
        else
        {
            y = tnode;
            if(tnode -> left == NULL)
            {
                tnode = tnode -> right;
            }
            else if(tnode -> right == NULL)
            {
                tnode = tnode -> left;
            }
            free(y);
        }
    }

    return tnode;
}

void Inor(BinaryTreeNode *tnode)
{
    if(tnode == NULL)
    {
        return;
    }
    Inor(tnode -> left);//calls the left child
    cout<<tnode -> value<<endl;
    Inor(tnode -> right);//calls the right child
}


void Preor(BinaryTreeNode *tnode)
{
    if(tnode == NULL)
    {
        return;
    }
    cout<<tnode -> value<<endl;
    Preor(tnode -> left);
    Preor(tnode -> right);
}


void Postor(BinaryTreeNode *tnode)
{
    if(tnode == NULL)
    {
        return;
    }
    Postor(tnode -> left);
    Postor(tnode -> right);
    cout<<tnode -> value<<endl;
}

int main()
{
    BinaryTreeNode *root = NULL,*x;
    int val;
    string choice;
    while(1)
    {
        cin>>choice;
        string value = choice.substr(1);
        stringstream convert(value);
        convert >> val;
        if(choice[0] == 'i')
            root = Insert(root, val);
        else if(choice[0] == 'd')
            root = Delete(root,val);
        else if(choice == "opre")
            Preor(root);
        else if(choice == "opost")
            Postor(root);
        else if(choice == "oin")
            Inor(root);
        else if(choice[0] == 'e')
        {
            exit(0);
        }

    }
    return 0;
}