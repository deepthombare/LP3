/*
 * Problem Statement :- Write a program to implement Huffman Encoding using a greedy
 * 						strategy.
 *
 * Time Complexity  : O(nlogn)   (n => number of unique characters in string)
 * Space Complexity : O(n)
 */

#include <iostream>
#include<bits/stdc++.h>

using namespace std;
struct MinHeapNode {
    char data;
    int freq;
    MinHeapNode *left,*right;
    MinHeapNode(char data, int freq)
    {
 
        left = right = NULL;
        this->data = data;
        this->freq = freq;
    }
};

struct compare{
    bool operator()(MinHeapNode* l,MinHeapNode *r)
    {
        return (l->freq > r->freq);
    }
};

void print(MinHeapNode *root,string s){
    if(!root){
        return;
    }
    if(root->data != '$'){
        cout<<root->data<<" : "<<s<<endl;
    }
    print(root->left,s+'0');
    print(root->right,s+'1');
}

void HuffmanCode(char data[],int freq[],int size){
    struct MinHeapNode* l,*r,*top;
    priority_queue<MinHeapNode*,vector<MinHeapNode*>,compare> minHeap;
    for(int i = 0;i<size;i++){
        minHeap.push(new MinHeapNode(data[i],freq[i]));
    }
    while(minHeap.size()!=1){
        
        l = minHeap.top();
        minHeap.pop();
        r = minHeap.top();
        minHeap.pop();
        top = new MinHeapNode('$',l->freq+r->freq);
        
        top->left = l;
        top->right = r;
        minHeap.push(top);
        
    }
    print(minHeap.top(),"");
}


int main()
{
    char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    int freq[] = { 5, 9, 12, 13, 16, 45 };
 
    int size = sizeof(arr) / sizeof(arr[0]);
 
    HuffmanCode(arr, freq, size);
 
    return 0;
}
