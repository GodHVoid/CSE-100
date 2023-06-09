#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct MinHeapNode 
{
    char letter;
    unsigned freq;
    MinHeapNode *left, *right;
    MinHeapNode(char letter, unsigned freq)
    {
        left = right = NULL;
        this->letter = letter;
        this->freq = freq; 
    }
};

struct compare 
{
    bool operator()(MinHeapNode* l, MinHeapNode* r)
    {
		return ((l->freq) > (r->freq)); 
 	}

};
void printCodes(struct MinHeapNode* root, char L, string code) 
{ 
    if (root == 0)
	{
        return; // exists/stops the void method
	}
    if (root->letter != '?' && L == root->letter)
	{
        cout << root->letter << ":" << code <<endl; 
	}
    printCodes(root->left,L, code + "0"); 
    printCodes(root->right,L, code + "1"); 

} 

void huffman_codes(char L[], int freq[], int n) 
{ 
    struct MinHeapNode *left, *right, *top; 
    priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> tree; 
    for (int i = 0; i < n; i++) 
	{
	   tree.push(new MinHeapNode(L[i], freq[i])); 
	}
    while (tree.size() != 1) 
	{
        left = tree.top(); 
        tree.pop(); 
        right = tree.top(); 
        tree.pop(); 
        top = new MinHeapNode('?', left->freq + right->freq); 
        top->left = left; 
        top->right = right; 
        tree.push(top); 
    } 
    for(int i=0;i<n;i++)
	{
		printCodes(tree.top(),L[i], "");
	}
} 
int main()
{
	char L[] = {'A','B','C','D','E','F'};
	int n = 6;
    int *freq = new int[n];
    for (int i = 0; i <n; i++)
    {
        cin >> freq[i];
    }
	huffman_codes(L,freq,n);
    return 0;

}
//priority queue https://www.cplusplus.com/reference/queue/priority_queue/
//I used priority queue to correct nodes' location for the huffman codes