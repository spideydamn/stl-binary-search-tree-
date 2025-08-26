#include <iostream>
#include <lib/BinarySearchTree.h>
#include <vector>
#include <set>

int main() {
    BinarySearchTree<int> bst;
    bst.insert(3);
    bst.insert(1);
    bst.insert(4);
    std::cout << *bst.lower_bound(2) << std::endl; // == bst.find(1));
    std::cout << *bst.lower_bound(3) << std::endl; // == bst.find(3));
    std::cout << *bst.upper_bound(2) << std::endl; // == bst.find(3));
    std::cout << *bst.upper_bound(3) << std::endl; // == bst.find(3));
}