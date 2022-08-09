#include <iostream>
#include "TreeNode.h"

TreeNode* fillTree(int arr[], int start, int end)
{
    if (start > end)
        return nullptr;
    int mid = (start + end) / 2;
    TreeNode* root = new TreeNode(arr[mid]);
    root->left = fillTree(arr, start, mid - 1);
    root->right = fillTree(arr, mid + 1, end);
    return root;
}

bool findInTree(int value, TreeNode &mainNode) {

    std::cout << mainNode.data << ">>";
    if (mainNode.data == value)
        return true;
    else {
        if (value < mainNode.data && mainNode.left != nullptr)
            return findInTree(value, *mainNode.left);
        else if (value > mainNode.data && mainNode.right != nullptr)
            return findInTree(value, *mainNode.right);
        else
            return false;
    }
}

void addElement(int value, TreeNode &mainNode) {

    if (value < mainNode.data)
        if (mainNode.left == nullptr)
            mainNode.left = new TreeNode(value);
        else
            addElement(value, *mainNode.left);
            
    else if (value > mainNode.data)
        if (mainNode.right == nullptr)
            mainNode.right = new TreeNode(value);
            
        else
            addElement(value, *mainNode.right);
}

int main() {
    int arr[] = { 1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25 };
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    TreeNode root = *fillTree(arr, 0, arrSize-1);
    addElement(22, root);
    std::cout<<std::endl<<findInTree(22, root);

}