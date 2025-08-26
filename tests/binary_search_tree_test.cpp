#include <lib/BinarySearchTree.h>
#include <gtest/gtest.h>
#include <string>
#include <vector>
#include <set>

TEST(BinarySearchTreeTestSuite, CreatingDifferentTypesTest) {
    BinarySearchTree<int> int_bst;
    BinarySearchTree<double> double_bst;
    BinarySearchTree<std::string> string_bst;
    BinarySearchTree<std::vector<int>> vector_bst;
    BinarySearchTree<std::set<int>> set_bst;

    ASSERT_EQ(int_bst.size(), 0);
    ASSERT_EQ(double_bst.size(), 0);
    ASSERT_EQ(string_bst.size(), 0);
    ASSERT_EQ(vector_bst.size(), 0);
    ASSERT_EQ(set_bst.size(), 0);
}

TEST(BinarySearchTreeTestSuite, CreatingEmptyContainerTest) {
    BinarySearchTree<int> bst = BinarySearchTree<int>();

    ASSERT_EQ(bst.size(), 0);
    ASSERT_EQ(BinarySearchTree<int>().size(), 0);
}

TEST(BinarySearchTreeTestSuite, CreatingCopyOfContainerTest) {
    BinarySearchTree<int> bst;
    bst.insert(1);
    bst.insert(5);
    bst.insert(3);
    bst.insert(-8);
    bst.insert(-4);

    BinarySearchTree<int> bst_copy(bst);
    ASSERT_TRUE(bst == bst_copy);
    ASSERT_TRUE(bst == BinarySearchTree<int>(bst));
    bst_copy.insert(-5);
    ASSERT_FALSE(bst == bst_copy);

    ASSERT_EQ(bst_copy.size(), 6);
    ASSERT_TRUE(bst_copy.contains(1));
    ASSERT_TRUE(bst_copy.contains(5));
    ASSERT_TRUE(bst_copy.contains(3));
    ASSERT_TRUE(bst_copy.contains(-8));
    ASSERT_TRUE(bst_copy.contains(-4));
    ASSERT_TRUE(bst_copy.contains(-5));

    ASSERT_EQ(bst.size(), 5);
    ASSERT_TRUE(bst.contains(1));
    ASSERT_TRUE(bst.contains(5));
    ASSERT_TRUE(bst.contains(3));
    ASSERT_TRUE(bst.contains(-8));
    ASSERT_TRUE(bst.contains(-4));
    ASSERT_FALSE(bst.contains(-5));



    BinarySearchTree<int> bst_copy_2 = BinarySearchTree<int>(bst_copy);
    ASSERT_TRUE(bst_copy == bst_copy_2);
    ASSERT_TRUE(bst_copy == BinarySearchTree<int>(bst_copy));
    bst_copy_2.erase(5);
    bst_copy_2.erase(-4);
    bst_copy_2.erase(1);
    bst_copy_2.insert(-2);

    bst_copy.erase(3);

    ASSERT_FALSE(bst_copy == bst_copy_2);

    ASSERT_EQ(bst_copy.size(), 5);
    ASSERT_TRUE(bst_copy.contains(1));
    ASSERT_TRUE(bst_copy.contains(5));
    ASSERT_FALSE(bst_copy.contains(3));
    ASSERT_TRUE(bst_copy.contains(-8));
    ASSERT_TRUE(bst_copy.contains(-4));
    ASSERT_TRUE(bst_copy.contains(-5));
    ASSERT_FALSE(bst_copy.contains(-2));

    ASSERT_EQ(bst_copy_2.size(), 4);
    ASSERT_FALSE(bst_copy_2.contains(1));
    ASSERT_FALSE(bst_copy_2.contains(5));
    ASSERT_TRUE(bst_copy_2.contains(3));
    ASSERT_TRUE(bst_copy_2.contains(-8));
    ASSERT_FALSE(bst_copy_2.contains(-4));
    ASSERT_TRUE(bst_copy_2.contains(-5));
    ASSERT_TRUE(bst_copy_2.contains(-2));
}

TEST(BinarySearchTreeTestSuite, CreatingCopyByAssignmentOfContainerTest) {
    BinarySearchTree<int> bst;
    bst.insert(1);
    bst.insert(5);
    bst.insert(3);
    bst.insert(-8);
    bst.insert(-4);

    BinarySearchTree<int> bst_copy = bst;
    ASSERT_TRUE(bst == bst_copy);
    bst_copy.insert(-5);
    ASSERT_FALSE(bst == bst_copy);

    ASSERT_EQ(bst_copy.size(), 6);
    ASSERT_TRUE(bst_copy.contains(1));
    ASSERT_TRUE(bst_copy.contains(5));
    ASSERT_TRUE(bst_copy.contains(3));
    ASSERT_TRUE(bst_copy.contains(-8));
    ASSERT_TRUE(bst_copy.contains(-4));
    ASSERT_TRUE(bst_copy.contains(-5));

    ASSERT_EQ(bst.size(), 5);
    ASSERT_TRUE(bst.contains(1));
    ASSERT_TRUE(bst.contains(5));
    ASSERT_TRUE(bst.contains(3));
    ASSERT_TRUE(bst.contains(-8));
    ASSERT_TRUE(bst.contains(-4));
    ASSERT_FALSE(bst.contains(-5));



    auto bst_copy_2 = bst_copy;
    ASSERT_TRUE(bst_copy == bst_copy_2);
    bst_copy_2.erase(5);
    bst_copy_2.erase(-4);
    bst_copy_2.erase(1);
    bst_copy_2.insert(-2);

    bst_copy.erase(3);

    ASSERT_FALSE(bst_copy == bst_copy_2);

    ASSERT_EQ(bst_copy.size(), 5);
    ASSERT_TRUE(bst_copy.contains(1));
    ASSERT_TRUE(bst_copy.contains(5));
    ASSERT_FALSE(bst_copy.contains(3));
    ASSERT_TRUE(bst_copy.contains(-8));
    ASSERT_TRUE(bst_copy.contains(-4));
    ASSERT_TRUE(bst_copy.contains(-5));
    ASSERT_FALSE(bst_copy.contains(-2));

    ASSERT_EQ(bst_copy_2.size(), 4);
    ASSERT_FALSE(bst_copy_2.contains(1));
    ASSERT_FALSE(bst_copy_2.contains(5));
    ASSERT_TRUE(bst_copy_2.contains(3));
    ASSERT_TRUE(bst_copy_2.contains(-8));
    ASSERT_FALSE(bst_copy_2.contains(-4));
    ASSERT_TRUE(bst_copy_2.contains(-5));
    ASSERT_TRUE(bst_copy_2.contains(-2));

    bst_copy_2 = bst_copy_2;

    ASSERT_EQ(bst_copy_2.size(), 4);
    ASSERT_FALSE(bst_copy_2.contains(1));
    ASSERT_FALSE(bst_copy_2.contains(5));
    ASSERT_TRUE(bst_copy_2.contains(3));
    ASSERT_TRUE(bst_copy_2.contains(-8));
    ASSERT_FALSE(bst_copy_2.contains(-4));
    ASSERT_TRUE(bst_copy_2.contains(-5));
    ASSERT_TRUE(bst_copy_2.contains(-2));
}

TEST(BinarySearchTreeTestSuite, MaxSizeTest) {
    BinarySearchTree<int> bst;
    ASSERT_EQ(bst.max_size(), static_cast<unsigned long long>(-1));

    bst.insert(1);
    bst.insert(5);
    bst.insert(3);
    bst.insert(-8);
    bst.insert(-4);
    bst.erase(5);
    bst.erase(-4);

    ASSERT_EQ(bst.max_size(), static_cast<unsigned long long>(-1));
}

TEST(BinarySearchTreeTestSuite, FreeMemoryTest) {
    BinarySearchTree<int> bst;

    bst.insert(1);
    bst.insert(5);
    bst.insert(3);
    bst.insert(-8);
    bst.insert(-4);
    bst.erase(5);
    bst.erase(-4);

    ASSERT_EQ(bst.size(), 3);

    bst.~BinarySearchTree();

    ASSERT_TRUE(bst.empty());
}

TEST(BinarySearchTreeTestSuite, SwapTest) {
    BinarySearchTree<int> bst;
    bst.insert(1);
    bst.insert(5);
    bst.insert(3);
    bst.insert(-8);
    bst.insert(-4);

    BinarySearchTree<int> bst_copy = bst;
    ASSERT_TRUE(bst == bst_copy);
    bst_copy.insert(-5);
    ASSERT_FALSE(bst == bst_copy);

    bst.swap(bst_copy);

    ASSERT_EQ(bst.size(), 6);
    ASSERT_TRUE(bst.contains(1));
    ASSERT_TRUE(bst.contains(5));
    ASSERT_TRUE(bst.contains(3));
    ASSERT_TRUE(bst.contains(-8));
    ASSERT_TRUE(bst.contains(-4));
    ASSERT_TRUE(bst.contains(-5));

    ASSERT_EQ(bst_copy.size(), 5);
    ASSERT_TRUE(bst_copy.contains(1));
    ASSERT_TRUE(bst_copy.contains(5));
    ASSERT_TRUE(bst_copy.contains(3));
    ASSERT_TRUE(bst_copy.contains(-8));
    ASSERT_TRUE(bst_copy.contains(-4));
    ASSERT_FALSE(bst_copy.contains(-5));

    bst_copy.swap(bst);

    auto bst_copy_2 = bst_copy;
    ASSERT_TRUE(bst_copy == bst_copy_2);
    bst_copy_2.erase(5);
    bst_copy_2.erase(-4);
    bst_copy_2.erase(1);
    bst_copy_2.insert(-2);

    bst_copy.erase(3);

    ASSERT_FALSE(bst_copy == bst_copy_2);

    ASSERT_EQ(bst_copy.size(), 5);
    ASSERT_TRUE(bst_copy.contains(1));
    ASSERT_TRUE(bst_copy.contains(5));
    ASSERT_FALSE(bst_copy.contains(3));
    ASSERT_TRUE(bst_copy.contains(-8));
    ASSERT_TRUE(bst_copy.contains(-4));
    ASSERT_TRUE(bst_copy.contains(-5));
    ASSERT_FALSE(bst_copy.contains(-2));

    ASSERT_EQ(bst_copy_2.size(), 4);
    ASSERT_FALSE(bst_copy_2.contains(1));
    ASSERT_FALSE(bst_copy_2.contains(5));
    ASSERT_TRUE(bst_copy_2.contains(3));
    ASSERT_TRUE(bst_copy_2.contains(-8));
    ASSERT_FALSE(bst_copy_2.contains(-4));
    ASSERT_TRUE(bst_copy_2.contains(-5));
    ASSERT_TRUE(bst_copy_2.contains(-2));

    bst_copy.swap(bst_copy_2);

    ASSERT_FALSE(bst_copy == bst_copy_2);

    ASSERT_EQ(bst_copy_2.size(), 5);
    ASSERT_TRUE(bst_copy_2.contains(1));
    ASSERT_TRUE(bst_copy_2.contains(5));
    ASSERT_FALSE(bst_copy_2.contains(3));
    ASSERT_TRUE(bst_copy_2.contains(-8));
    ASSERT_TRUE(bst_copy_2.contains(-4));
    ASSERT_TRUE(bst_copy_2.contains(-5));
    ASSERT_FALSE(bst_copy_2.contains(-2));

    ASSERT_EQ(bst_copy.size(), 4);
    ASSERT_FALSE(bst_copy.contains(1));
    ASSERT_FALSE(bst_copy.contains(5));
    ASSERT_TRUE(bst_copy.contains(3));
    ASSERT_TRUE(bst_copy.contains(-8));
    ASSERT_FALSE(bst_copy.contains(-4));
    ASSERT_TRUE(bst_copy.contains(-5));
    ASSERT_TRUE(bst_copy.contains(-2));
}

TEST(BinarySearchTreeTestSuite, AnotherSwapTest) {
    BinarySearchTree<int> bst;
    bst.insert(1);
    bst.insert(5);
    bst.insert(3);
    bst.insert(-8);
    bst.insert(-4);

    BinarySearchTree<int> bst_copy = bst;
    ASSERT_TRUE(bst == bst_copy);
    bst_copy.insert(-5);
    ASSERT_FALSE(bst == bst_copy);

    swap(bst, bst_copy);

    ASSERT_EQ(bst.size(), 6);
    ASSERT_TRUE(bst.contains(1));
    ASSERT_TRUE(bst.contains(5));
    ASSERT_TRUE(bst.contains(3));
    ASSERT_TRUE(bst.contains(-8));
    ASSERT_TRUE(bst.contains(-4));
    ASSERT_TRUE(bst.contains(-5));

    ASSERT_EQ(bst_copy.size(), 5);
    ASSERT_TRUE(bst_copy.contains(1));
    ASSERT_TRUE(bst_copy.contains(5));
    ASSERT_TRUE(bst_copy.contains(3));
    ASSERT_TRUE(bst_copy.contains(-8));
    ASSERT_TRUE(bst_copy.contains(-4));
    ASSERT_FALSE(bst_copy.contains(-5));

    swap(bst_copy, bst);

    auto bst_copy_2 = bst_copy;
    ASSERT_TRUE(bst_copy == bst_copy_2);
    bst_copy_2.erase(5);
    bst_copy_2.erase(-4);
    bst_copy_2.erase(1);
    bst_copy_2.insert(-2);

    bst_copy.erase(3);

    ASSERT_FALSE(bst_copy == bst_copy_2);

    ASSERT_EQ(bst_copy.size(), 5);
    ASSERT_TRUE(bst_copy.contains(1));
    ASSERT_TRUE(bst_copy.contains(5));
    ASSERT_FALSE(bst_copy.contains(3));
    ASSERT_TRUE(bst_copy.contains(-8));
    ASSERT_TRUE(bst_copy.contains(-4));
    ASSERT_TRUE(bst_copy.contains(-5));
    ASSERT_FALSE(bst_copy.contains(-2));

    ASSERT_EQ(bst_copy_2.size(), 4);
    ASSERT_FALSE(bst_copy_2.contains(1));
    ASSERT_FALSE(bst_copy_2.contains(5));
    ASSERT_TRUE(bst_copy_2.contains(3));
    ASSERT_TRUE(bst_copy_2.contains(-8));
    ASSERT_FALSE(bst_copy_2.contains(-4));
    ASSERT_TRUE(bst_copy_2.contains(-5));
    ASSERT_TRUE(bst_copy_2.contains(-2));

    swap(bst_copy, bst_copy_2);

    ASSERT_FALSE(bst_copy == bst_copy_2);

    ASSERT_EQ(bst_copy_2.size(), 5);
    ASSERT_TRUE(bst_copy_2.contains(1));
    ASSERT_TRUE(bst_copy_2.contains(5));
    ASSERT_FALSE(bst_copy_2.contains(3));
    ASSERT_TRUE(bst_copy_2.contains(-8));
    ASSERT_TRUE(bst_copy_2.contains(-4));
    ASSERT_TRUE(bst_copy_2.contains(-5));
    ASSERT_FALSE(bst_copy_2.contains(-2));

    ASSERT_EQ(bst_copy.size(), 4);
    ASSERT_FALSE(bst_copy.contains(1));
    ASSERT_FALSE(bst_copy.contains(5));
    ASSERT_TRUE(bst_copy.contains(3));
    ASSERT_TRUE(bst_copy.contains(-8));
    ASSERT_FALSE(bst_copy.contains(-4));
    ASSERT_TRUE(bst_copy.contains(-5));
    ASSERT_TRUE(bst_copy.contains(-2));
}

TEST(BinarySearchTreeTestSuite, VectorIteratorInitializationTest) {
    BinarySearchTree<int> bst_1;
    bst_1.insert(1);
    bst_1.insert(5);
    bst_1.insert(3);
    bst_1.insert(-8);
    bst_1.insert(-4);

    std::vector<int> vec {1, 5, 3, -8, -4};

    BinarySearchTree<int> bst_2(vec.begin(), vec.end());

    ASSERT_TRUE(bst_1 == bst_2);

    std::vector<int> vec_2 {-4, -8, 3, 5, 1};
    BinarySearchTree<int> bst_3(vec_2.begin(), vec_2.end());

    ASSERT_FALSE(bst_1 == bst_3);
    ASSERT_FALSE(bst_2 == bst_3);
}

TEST(BinarySearchTreeTestSuite, InitializerListInitializationTest) {
    BinarySearchTree<int> bst_1;
    bst_1.insert(1);
    bst_1.insert(5);
    bst_1.insert(3);
    bst_1.insert(-8);
    bst_1.insert(-4);

    BinarySearchTree<int> bst_2({1, 5, 3, -8, -4});

    ASSERT_TRUE(bst_1 == bst_2);

    BinarySearchTree<int> bst_3({-4, -8, 3, 5, 1});

    ASSERT_FALSE(bst_1 == bst_3);
    ASSERT_FALSE(bst_2 == bst_3);

    BinarySearchTree<int> bst_4{1, 5, 3, -8, -4};

    ASSERT_TRUE(bst_1 == bst_4);
    ASSERT_TRUE(bst_2 == bst_4);

    BinarySearchTree<int> bst_5{-4, -8, 3, 5, 1};

    ASSERT_FALSE(bst_1 == bst_5);
    ASSERT_FALSE(bst_2 == bst_5);
    ASSERT_FALSE(bst_4 == bst_5);
}

TEST(BinarySearchTreeTestSuite, InitializerListInitializationByAssignmentTest) {
    BinarySearchTree<int> bst_1;
    bst_1.insert(1);
    bst_1.insert(5);
    bst_1.insert(3);
    bst_1.insert(-8);
    bst_1.insert(-4);

    BinarySearchTree<int> bst_2 = {1, 5, 3, -8, -4};

    ASSERT_TRUE(bst_1 == bst_2);

    BinarySearchTree<int> bst_3 = {-4, -8, 3, 5, 1};

    ASSERT_FALSE(bst_1 == bst_3);
    ASSERT_FALSE(bst_2 == bst_3);
}

TEST(BinarySearchTreeTestSuite, GetAllocatorTest) {
    BinarySearchTree<int> bst;
    bool is_same = (bst.get_allocator() == std::allocator<int>());
    ASSERT_TRUE(is_same);
}

TEST(BinarySearchTreeTestSuite, InOrderIteratorTest) {
    BinarySearchTree<int> bst;
    bst.insert(5);
    bst.insert(3);
    bst.insert(7);
    bst.insert(1);
    bst.insert(4);
    bst.insert(6);
    bst.insert(9);

    BinarySearchTree<int>::iterator it = bst.begin();
    ASSERT_EQ(*it, 1);
    ++it;
    ASSERT_EQ(*it, 3);
    ++it;
    ASSERT_EQ(*it, 4);
    ++it;
    ASSERT_EQ(*it, 5);
    ++it;
    ASSERT_EQ(*it, 6);
    ++it;
    ASSERT_EQ(*it, 7);
    ++it;
    ASSERT_EQ(*it, 9);
    ++it;
    ASSERT_TRUE(it.get_node()->is_end_);
    --it;
    ASSERT_EQ(*it, 9);
    --it;
    ASSERT_EQ(*it, 7);
    --it;
    ASSERT_EQ(*it, 6);
    --it;
    ASSERT_EQ(*it, 5);
    --it;
    ASSERT_EQ(*it, 4);
    --it;
    ASSERT_EQ(*it, 3);
    --it;
    ASSERT_EQ(*it, 1);
    --it;
    ASSERT_TRUE(it.get_node()->is_end_);
    ++it;
    ASSERT_EQ(*it, 1);
    BinarySearchTree<int>::iterator it_ = it;
    ASSERT_EQ(*it_, 1);
    it_ = ++it;
    ASSERT_EQ(*it_, 3);
    it_ = ++it;
    ASSERT_EQ(*it_, 4);
    it_ = ++it;
    ASSERT_EQ(*it_, 5);
    it_ = ++it;
    ASSERT_EQ(*it_, 6);
    it_ = ++it;
    ASSERT_EQ(*it_, 7);
    it_ = ++it;
    ASSERT_EQ(*it_, 9);
    it_ = ++it;
    ASSERT_TRUE(it_.get_node()->is_end_);
    it_ = --it;
    ASSERT_EQ(*it_, 9);
    it_ = --it;
    ASSERT_EQ(*it_, 7);
    it_ = --it;
    ASSERT_EQ(*it_, 6);
    it_ = --it;
    ASSERT_EQ(*it_, 5);
    it_ = --it;
    ASSERT_EQ(*it_, 4);
    it_ = --it;
    ASSERT_EQ(*it_, 3);
    it_ = --it;
    ASSERT_EQ(*it_, 1);
    it_ = --it;
    ASSERT_TRUE(it_.get_node()->is_end_);
    it_ = ++it;
    ASSERT_EQ(*it_, 1);
    it_ = it++;
    ASSERT_EQ(*it_, 1);
    ASSERT_EQ(*it, 3);
    it_ = it++;
    ASSERT_EQ(*it_, 3);
    ASSERT_EQ(*it, 4);
    it_ = it++;
    ASSERT_EQ(*it_, 4);
    ASSERT_EQ(*it, 5);
    it_ = it++;
    ASSERT_EQ(*it_, 5);
    ASSERT_EQ(*it, 6);
    it_ = it++;
    ASSERT_EQ(*it_, 6);
    ASSERT_EQ(*it, 7);
    it_ = it++;
    ASSERT_EQ(*it_, 7);
    ASSERT_EQ(*it, 9);
    it_ = it++;
    ASSERT_EQ(*it_, 9);
    ASSERT_TRUE(it.get_node()->is_end_);
    it_ = it--;
    ASSERT_TRUE(it_.get_node()->is_end_);
    ASSERT_EQ(*it, 9);
    it_ = it--;
    ASSERT_EQ(*it_, 9);
    ASSERT_EQ(*it, 7);
    it_ = it--;
    ASSERT_EQ(*it_, 7);
    ASSERT_EQ(*it, 6);
    it_ = it--;
    ASSERT_EQ(*it_, 6);
    ASSERT_EQ(*it, 5);
    it_ = it--;
    ASSERT_EQ(*it_, 5);
    ASSERT_EQ(*it, 4);
    it_ = it--;
    ASSERT_EQ(*it_, 4);
    ASSERT_EQ(*it, 3);
    it_ = it--;
    ASSERT_EQ(*it_, 3);
    ASSERT_EQ(*it, 1);
    it_ = it--;
    ASSERT_EQ(*it_, 1);
    ASSERT_TRUE(it.get_node()->is_end_);
    it_ = it++;
    ASSERT_TRUE(it_.get_node()->is_end_);
    ASSERT_EQ(*it, 1);
}

TEST(BinarySearchTreeTestSuite, PreOrderIteratorTest) {
    BinarySearchTree<int, PreOrder> bst;
    bst.insert(5);
    bst.insert(3);
    bst.insert(7);
    bst.insert(1);
    bst.insert(4);
    bst.insert(6);
    bst.insert(9);

    BinarySearchTree<int, PreOrder>::iterator it = bst.begin<PreOrder>();
    ASSERT_EQ(*it, 5);
    ++it;
    ASSERT_EQ(*it, 3);
    ++it;
    ASSERT_EQ(*it, 1);
    ++it;
    ASSERT_EQ(*it, 4);
    ++it;
    ASSERT_EQ(*it, 7);
    ++it;
    ASSERT_EQ(*it, 6);
    ++it;
    ASSERT_EQ(*it, 9);
    ++it;
    ASSERT_TRUE(it.get_node()->is_end_);
    --it;
    ASSERT_EQ(*it, 9);
    --it;
    ASSERT_EQ(*it, 6);
    --it;
    ASSERT_EQ(*it, 7);
    --it;
    ASSERT_EQ(*it, 4);
    --it;
    ASSERT_EQ(*it, 1);
    --it;
    ASSERT_EQ(*it, 3);
    --it;
    ASSERT_EQ(*it, 5);
    --it;
    ASSERT_TRUE(it.get_node()->is_end_);
    ++it;
    ASSERT_EQ(*it, 5);
    BinarySearchTree<int, PreOrder>::iterator it_ = it;
    ASSERT_EQ(*it_, 5);
    it_ = ++it;
    ASSERT_EQ(*it_, 3);
    it_ = ++it;
    ASSERT_EQ(*it_, 1);
    it_ = ++it;
    ASSERT_EQ(*it_, 4);
    it_ = ++it;
    ASSERT_EQ(*it_, 7);
    it_ = ++it;
    ASSERT_EQ(*it_, 6);
    it_ = ++it;
    ASSERT_EQ(*it_, 9);
    it_ = ++it;
    ASSERT_TRUE(it_.get_node()->is_end_);
    it_ = --it;
    ASSERT_EQ(*it_, 9);
    it_ = --it;
    ASSERT_EQ(*it_, 6);
    it_ = --it;
    ASSERT_EQ(*it_, 7);
    it_ = --it;
    ASSERT_EQ(*it_, 4);
    it_ = --it;
    ASSERT_EQ(*it_, 1);
    it_ = --it;
    ASSERT_EQ(*it_, 3);
    it_ = --it;
    ASSERT_EQ(*it_, 5);
    it_ = --it;
    ASSERT_TRUE(it_.get_node()->is_end_);
    it_ = ++it;
    ASSERT_EQ(*it_, 5);
    it_ = it++;
    ASSERT_EQ(*it_, 5);
    ASSERT_EQ(*it, 3);
    it_ = it++;
    ASSERT_EQ(*it_, 3);
    ASSERT_EQ(*it, 1);
    it_ = it++;
    ASSERT_EQ(*it_, 1);
    ASSERT_EQ(*it, 4);
    it_ = it++;
    ASSERT_EQ(*it_, 4);
    ASSERT_EQ(*it, 7);
    it_ = it++;
    ASSERT_EQ(*it_, 7);
    ASSERT_EQ(*it, 6);
    it_ = it++;
    ASSERT_EQ(*it_, 6);
    ASSERT_EQ(*it, 9);
    it_ = it++;
    ASSERT_EQ(*it_, 9);
    ASSERT_TRUE(it.get_node()->is_end_);
    it_ = it--;
    ASSERT_TRUE(it_.get_node()->is_end_);
    ASSERT_EQ(*it, 9);
    it_ = it--;
    ASSERT_EQ(*it_, 9);
    ASSERT_EQ(*it, 6);
    it_ = it--;
    ASSERT_EQ(*it_, 6);
    ASSERT_EQ(*it, 7);
    it_ = it--;
    ASSERT_EQ(*it_, 7);
    ASSERT_EQ(*it, 4);
    it_ = it--;
    ASSERT_EQ(*it_, 4);
    ASSERT_EQ(*it, 1);
    it_ = it--;
    ASSERT_EQ(*it_, 1);
    ASSERT_EQ(*it, 3);
    it_ = it--;
    ASSERT_EQ(*it_, 3);
    ASSERT_EQ(*it, 5);
    it_ = it--;
    ASSERT_EQ(*it_, 5);
    ASSERT_TRUE(it.get_node()->is_end_);
    it_ = it++;
    ASSERT_TRUE(it_.get_node()->is_end_);
    ASSERT_EQ(*it, 5);
}

TEST(BinarySearchTreeTestSuite, PostOrderIteratorTest) {
    BinarySearchTree<int, PostOrder> bst;
    bst.insert(5);
    bst.insert(3);
    bst.insert(7);
    bst.insert(1);
    bst.insert(4);
    bst.insert(6);
    bst.insert(9);

    BinarySearchTree<int, PostOrder>::iterator it = bst.begin<PostOrder>();
    ASSERT_EQ(*it, 1);
    ++it;
    ASSERT_EQ(*it, 4);
    ++it;
    ASSERT_EQ(*it, 3);
    ++it;
    ASSERT_EQ(*it, 6);
    ++it;
    ASSERT_EQ(*it, 9);
    ++it;
    ASSERT_EQ(*it, 7);
    ++it;
    ASSERT_EQ(*it, 5);
    ++it;
    ASSERT_TRUE(it.get_node()->is_end_);
    --it;
    ASSERT_EQ(*it, 5);
    --it;
    ASSERT_EQ(*it, 7);
    --it;
    ASSERT_EQ(*it, 9);
    --it;
    ASSERT_EQ(*it, 6);
    --it;
    ASSERT_EQ(*it, 3);
    --it;
    ASSERT_EQ(*it, 4);
    --it;
    ASSERT_EQ(*it, 1);
    --it;
    ASSERT_TRUE(it.get_node()->is_end_);
    ++it;
    ASSERT_EQ(*it, 1);
    BinarySearchTree<int, PostOrder>::iterator it_ = it;
    ASSERT_EQ(*it_, 1);
    it_ = ++it;
    ASSERT_EQ(*it_, 4);
    it_ = ++it;
    ASSERT_EQ(*it_, 3);
    it_ = ++it;
    ASSERT_EQ(*it_, 6);
    it_ = ++it;
    ASSERT_EQ(*it_, 9);
    it_ = ++it;
    ASSERT_EQ(*it_, 7);
    it_ = ++it;
    ASSERT_EQ(*it_, 5);
    it_ = ++it;
    ASSERT_TRUE(it_.get_node()->is_end_);
    it_ = --it;
    ASSERT_EQ(*it_, 5);
    it_ = --it;
    ASSERT_EQ(*it_, 7);
    it_ = --it;
    ASSERT_EQ(*it_, 9);
    it_ = --it;
    ASSERT_EQ(*it_, 6);
    it_ = --it;
    ASSERT_EQ(*it_, 3);
    it_ = --it;
    ASSERT_EQ(*it_, 4);
    it_ = --it;
    ASSERT_EQ(*it_, 1);
    it_ = --it;
    ASSERT_TRUE(it_.get_node()->is_end_);
    it_ = ++it;
    ASSERT_EQ(*it_, 1);
    it_ = it++;
    ASSERT_EQ(*it_, 1);
    ASSERT_EQ(*it, 4);
    it_ = it++;
    ASSERT_EQ(*it_, 4);
    ASSERT_EQ(*it, 3);
    it_ = it++;
    ASSERT_EQ(*it_, 3);
    ASSERT_EQ(*it, 6);
    it_ = it++;
    ASSERT_EQ(*it_, 6);
    ASSERT_EQ(*it, 9);
    it_ = it++;
    ASSERT_EQ(*it_, 9);
    ASSERT_EQ(*it, 7);
    it_ = it++;
    ASSERT_EQ(*it_, 7);
    ASSERT_EQ(*it, 5);
    it_ = it++;
    ASSERT_EQ(*it_, 5);
    ASSERT_TRUE(it.get_node()->is_end_);
    it_ = it--;
    ASSERT_TRUE(it_.get_node()->is_end_);
    ASSERT_EQ(*it, 5);
    it_ = it--;
    ASSERT_EQ(*it_, 5);
    ASSERT_EQ(*it, 7);
    it_ = it--;
    ASSERT_EQ(*it_, 7);
    ASSERT_EQ(*it, 9);
    it_ = it--;
    ASSERT_EQ(*it_, 9);
    ASSERT_EQ(*it, 6);
    it_ = it--;
    ASSERT_EQ(*it_, 6);
    ASSERT_EQ(*it, 3);
    it_ = it--;
    ASSERT_EQ(*it_, 3);
    ASSERT_EQ(*it, 4);
    it_ = it--;
    ASSERT_EQ(*it_, 4);
    ASSERT_EQ(*it, 1);
    it_ = it--;
    ASSERT_EQ(*it_, 1);
    ASSERT_TRUE(it.get_node()->is_end_);
    it_ = it++;
    ASSERT_TRUE(it_.get_node()->is_end_);
    ASSERT_EQ(*it, 1);
}

TEST(BinarySearchTreeTestSuite, ReverseInOrderIteratorTest) {
    BinarySearchTree<int> bst;
    bst.insert(5);
    bst.insert(3);
    bst.insert(7);
    bst.insert(1);
    bst.insert(4);
    bst.insert(6);
    bst.insert(9);

    BinarySearchTree<int>::reverse_iterator it = bst.rend();
    --it;
    ASSERT_EQ(*it, 1);
    --it;
    ASSERT_EQ(*it, 3);
    --it;
    ASSERT_EQ(*it, 4);
    --it;
    ASSERT_EQ(*it, 5);
    --it;
    ASSERT_EQ(*it, 6);
    --it;
    ASSERT_EQ(*it, 7);
    --it;
    ASSERT_EQ(*it, 9);
    --it;
    ASSERT_TRUE(it.get_node()->is_end_);
    ++it;
    ASSERT_EQ(*it, 9);
    ++it;
    ASSERT_EQ(*it, 7);
    ++it;
    ASSERT_EQ(*it, 6);
    ++it;
    ASSERT_EQ(*it, 5);
    ++it;
    ASSERT_EQ(*it, 4);
    ++it;
    ASSERT_EQ(*it, 3);
    ++it;
    ASSERT_EQ(*it, 1);
    ++it;
    ASSERT_TRUE(it.get_node()->is_end_);
    --it;
    ASSERT_EQ(*it, 1);
    BinarySearchTree<int>::reverse_iterator it_ = it;
    ASSERT_EQ(*it_, 1);
    it_ = --it;
    ASSERT_EQ(*it_, 3);
    it_ = --it;
    ASSERT_EQ(*it_, 4);
    it_ = --it;
    ASSERT_EQ(*it_, 5);
    it_ = --it;
    ASSERT_EQ(*it_, 6);
    it_ = --it;
    ASSERT_EQ(*it_, 7);
    it_ = --it;
    ASSERT_EQ(*it_, 9);
    it_ = --it;
    ASSERT_TRUE(it_.get_node()->is_end_);
    it_ = ++it;
    ASSERT_EQ(*it_, 9);
    it_ = ++it;
    ASSERT_EQ(*it_, 7);
    it_ = ++it;
    ASSERT_EQ(*it_, 6);
    it_ = ++it;
    ASSERT_EQ(*it_, 5);
    it_ = ++it;
    ASSERT_EQ(*it_, 4);
    it_ = ++it;
    ASSERT_EQ(*it_, 3);
    it_ = ++it;
    ASSERT_EQ(*it_, 1);
    it_ = ++it;
    ASSERT_TRUE(it_.get_node()->is_end_);
    it_ = --it;
    ASSERT_EQ(*it_, 1);
    it_ = it--;
    ASSERT_EQ(*it_, 1);
    ASSERT_EQ(*it, 3);
    it_ = it--;
    ASSERT_EQ(*it_, 3);
    ASSERT_EQ(*it, 4);
    it_ = it--;
    ASSERT_EQ(*it_, 4);
    ASSERT_EQ(*it, 5);
    it_ = it--;
    ASSERT_EQ(*it_, 5);
    ASSERT_EQ(*it, 6);
    it_ = it--;
    ASSERT_EQ(*it_, 6);
    ASSERT_EQ(*it, 7);
    it_ = it--;
    ASSERT_EQ(*it_, 7);
    ASSERT_EQ(*it, 9);
    it_ = it--;
    ASSERT_EQ(*it_, 9);
    ASSERT_TRUE(it.get_node()->is_end_);
    it_ = it++;
    ASSERT_TRUE(it_.get_node()->is_end_);
    ASSERT_EQ(*it, 9);
    it_ = it++;
    ASSERT_EQ(*it_, 9);
    ASSERT_EQ(*it, 7);
    it_ = it++;
    ASSERT_EQ(*it_, 7);
    ASSERT_EQ(*it, 6);
    it_ = it++;
    ASSERT_EQ(*it_, 6);
    ASSERT_EQ(*it, 5);
    it_ = it++;
    ASSERT_EQ(*it_, 5);
    ASSERT_EQ(*it, 4);
    it_ = it++;
    ASSERT_EQ(*it_, 4);
    ASSERT_EQ(*it, 3);
    it_ = it++;
    ASSERT_EQ(*it_, 3);
    ASSERT_EQ(*it, 1);
    it_ = it++;
    ASSERT_EQ(*it_, 1);
    ASSERT_TRUE(it.get_node()->is_end_);
    it_ = it--;
    ASSERT_TRUE(it_.get_node()->is_end_);
    ASSERT_EQ(*it, 1);
}

TEST(BinarySearchTreeTestSuite, ReversePreOrderIteratorTest) {
    BinarySearchTree<int, PreOrder> bst;
    bst.insert(5);
    bst.insert(3);
    bst.insert(7);
    bst.insert(1);
    bst.insert(4);
    bst.insert(6);
    bst.insert(9);

    BinarySearchTree<int, PreOrder>::reverse_iterator it = bst.rend<PreOrder>();
    --it;
    ASSERT_EQ(*it, 5);
    --it;
    ASSERT_EQ(*it, 3);
    --it;
    ASSERT_EQ(*it, 1);
    --it;
    ASSERT_EQ(*it, 4);
    --it;
    ASSERT_EQ(*it, 7);
    --it;
    ASSERT_EQ(*it, 6);
    --it;
    ASSERT_EQ(*it, 9);
    --it;
    ASSERT_TRUE(it.get_node()->is_end_);
    ++it;
    ASSERT_EQ(*it, 9);
    ++it;
    ASSERT_EQ(*it, 6);
    ++it;
    ASSERT_EQ(*it, 7);
    ++it;
    ASSERT_EQ(*it, 4);
    ++it;
    ASSERT_EQ(*it, 1);
    ++it;
    ASSERT_EQ(*it, 3);
    ++it;
    ASSERT_EQ(*it, 5);
    ++it;
    ASSERT_TRUE(it.get_node()->is_end_);
    --it;
    ASSERT_EQ(*it, 5);
    BinarySearchTree<int, PreOrder>::reverse_iterator it_ = it;
    ASSERT_EQ(*it_, 5);
    it_ = --it;
    ASSERT_EQ(*it_, 3);
    it_ = --it;
    ASSERT_EQ(*it_, 1);
    it_ = --it;
    ASSERT_EQ(*it_, 4);
    it_ = --it;
    ASSERT_EQ(*it_, 7);
    it_ = --it;
    ASSERT_EQ(*it_, 6);
    it_ = --it;
    ASSERT_EQ(*it_, 9);
    it_ = --it;
    ASSERT_TRUE(it_.get_node()->is_end_);
    it_ = ++it;
    ASSERT_EQ(*it_, 9);
    it_ = ++it;
    ASSERT_EQ(*it_, 6);
    it_ = ++it;
    ASSERT_EQ(*it_, 7);
    it_ = ++it;
    ASSERT_EQ(*it_, 4);
    it_ = ++it;
    ASSERT_EQ(*it_, 1);
    it_ = ++it;
    ASSERT_EQ(*it_, 3);
    it_ = ++it;
    ASSERT_EQ(*it_, 5);
    it_ = ++it;
    ASSERT_TRUE(it_.get_node()->is_end_);
    it_ = --it;
    ASSERT_EQ(*it_, 5);
    it_ = it--;
    ASSERT_EQ(*it_, 5);
    ASSERT_EQ(*it, 3);
    it_ = it--;
    ASSERT_EQ(*it_, 3);
    ASSERT_EQ(*it, 1);
    it_ = it--;
    ASSERT_EQ(*it_, 1);
    ASSERT_EQ(*it, 4);
    it_ = it--;
    ASSERT_EQ(*it_, 4);
    ASSERT_EQ(*it, 7);
    it_ = it--;
    ASSERT_EQ(*it_, 7);
    ASSERT_EQ(*it, 6);
    it_ = it--;
    ASSERT_EQ(*it_, 6);
    ASSERT_EQ(*it, 9);
    it_ = it--;
    ASSERT_EQ(*it_, 9);
    ASSERT_TRUE(it.get_node()->is_end_);
    it_ = it++;
    ASSERT_TRUE(it_.get_node()->is_end_);
    ASSERT_EQ(*it, 9);
    it_ = it++;
    ASSERT_EQ(*it_, 9);
    ASSERT_EQ(*it, 6);
    it_ = it++;
    ASSERT_EQ(*it_, 6);
    ASSERT_EQ(*it, 7);
    it_ = it++;
    ASSERT_EQ(*it_, 7);
    ASSERT_EQ(*it, 4);
    it_ = it++;
    ASSERT_EQ(*it_, 4);
    ASSERT_EQ(*it, 1);
    it_ = it++;
    ASSERT_EQ(*it_, 1);
    ASSERT_EQ(*it, 3);
    it_ = it++;
    ASSERT_EQ(*it_, 3);
    ASSERT_EQ(*it, 5);
    it_ = it++;
    ASSERT_EQ(*it_, 5);
    ASSERT_TRUE(it.get_node()->is_end_);
    it_ = it--;
    ASSERT_TRUE(it_.get_node()->is_end_);
    ASSERT_EQ(*it, 5);
}

TEST(BinarySearchTreeTestSuite, ReversePostOrderIteratorTest) {
    BinarySearchTree<int, PostOrder> bst;
    bst.insert(5);
    bst.insert(3);
    bst.insert(7);
    bst.insert(1);
    bst.insert(4);
    bst.insert(6);
    bst.insert(9);

    BinarySearchTree<int, PostOrder>::reverse_iterator it = bst.rend<PostOrder>();
    --it;
    ASSERT_EQ(*it, 1);
    --it;
    ASSERT_EQ(*it, 4);
    --it;
    ASSERT_EQ(*it, 3);
    --it;
    ASSERT_EQ(*it, 6);
    --it;
    ASSERT_EQ(*it, 9);
    --it;
    ASSERT_EQ(*it, 7);
    --it;
    ASSERT_EQ(*it, 5);
    --it;
    ASSERT_TRUE(it.get_node()->is_end_);
    ++it;
    ASSERT_EQ(*it, 5);
    ++it;
    ASSERT_EQ(*it, 7);
    ++it;
    ASSERT_EQ(*it, 9);
    ++it;
    ASSERT_EQ(*it, 6);
    ++it;
    ASSERT_EQ(*it, 3);
    ++it;
    ASSERT_EQ(*it, 4);
    ++it;
    ASSERT_EQ(*it, 1);
    ++it;
    ASSERT_TRUE(it.get_node()->is_end_);
    --it;
    ASSERT_EQ(*it, 1);
    BinarySearchTree<int, PostOrder>::reverse_iterator it_ = it;
    ASSERT_EQ(*it_, 1);
    it_ = --it;
    ASSERT_EQ(*it_, 4);
    it_ = --it;
    ASSERT_EQ(*it_, 3);
    it_ = --it;
    ASSERT_EQ(*it_, 6);
    it_ = --it;
    ASSERT_EQ(*it_, 9);
    it_ = --it;
    ASSERT_EQ(*it_, 7);
    it_ = --it;
    ASSERT_EQ(*it_, 5);
    it_ = --it;
    ASSERT_TRUE(it_.get_node()->is_end_);
    it_ = ++it;
    ASSERT_EQ(*it_, 5);
    it_ = ++it;
    ASSERT_EQ(*it_, 7);
    it_ = ++it;
    ASSERT_EQ(*it_, 9);
    it_ = ++it;
    ASSERT_EQ(*it_, 6);
    it_ = ++it;
    ASSERT_EQ(*it_, 3);
    it_ = ++it;
    ASSERT_EQ(*it_, 4);
    it_ = ++it;
    ASSERT_EQ(*it_, 1);
    it_ = ++it;
    ASSERT_TRUE(it_.get_node()->is_end_);
    it_ = --it;
    ASSERT_EQ(*it_, 1);
    it_ = it--;
    ASSERT_EQ(*it_, 1);
    ASSERT_EQ(*it, 4);
    it_ = it--;
    ASSERT_EQ(*it_, 4);
    ASSERT_EQ(*it, 3);
    it_ = it--;
    ASSERT_EQ(*it_, 3);
    ASSERT_EQ(*it, 6);
    it_ = it--;
    ASSERT_EQ(*it_, 6);
    ASSERT_EQ(*it, 9);
    it_ = it--;
    ASSERT_EQ(*it_, 9);
    ASSERT_EQ(*it, 7);
    it_ = it--;
    ASSERT_EQ(*it_, 7);
    ASSERT_EQ(*it, 5);
    it_ = it--;
    ASSERT_EQ(*it_, 5);
    ASSERT_TRUE(it.get_node()->is_end_);
    it_ = it++;
    ASSERT_TRUE(it_.get_node()->is_end_);
    ASSERT_EQ(*it, 5);
    it_ = it++;
    ASSERT_EQ(*it_, 5);
    ASSERT_EQ(*it, 7);
    it_ = it++;
    ASSERT_EQ(*it_, 7);
    ASSERT_EQ(*it, 9);
    it_ = it++;
    ASSERT_EQ(*it_, 9);
    ASSERT_EQ(*it, 6);
    it_ = it++;
    ASSERT_EQ(*it_, 6);
    ASSERT_EQ(*it, 3);
    it_ = it++;
    ASSERT_EQ(*it_, 3);
    ASSERT_EQ(*it, 4);
    it_ = it++;
    ASSERT_EQ(*it_, 4);
    ASSERT_EQ(*it, 1);
    it_ = it++;
    ASSERT_EQ(*it_, 1);
    ASSERT_TRUE(it.get_node()->is_end_);
    it_ = it--;
    ASSERT_TRUE(it_.get_node()->is_end_);
    ASSERT_EQ(*it, 1);
}

TEST(BinarySearchTreeTestSuite, InsertWithReturnIteratorTest) {
    BinarySearchTree<int> bst;
    BinarySearchTree<int>::iterator it;

    it = bst.insert(5);
    ASSERT_EQ(*it, 5);
    it++;
    ASSERT_TRUE(it.get_node()->is_end_);
    it--;
    ASSERT_EQ(*it, 5);
    it--;
    ASSERT_TRUE(it.get_node()->is_end_);

    it = bst.insert(3);
    ASSERT_EQ(*it, 3);
    it++;
    ASSERT_EQ(*it, 5);
    it--;
    ASSERT_EQ(*it, 3);
    it--;
    ASSERT_TRUE(it.get_node()->is_end_);

    it = bst.insert(7);
    ASSERT_EQ(*it, 7);
    it++;
    ASSERT_TRUE(it.get_node()->is_end_);
    it--;
    ASSERT_EQ(*it, 7);
    it--;
    ASSERT_EQ(*it, 5);

    it = bst.insert(1);
    ASSERT_EQ(*it, 1);
    it++;
    ASSERT_EQ(*it, 3);
    it--;
    ASSERT_EQ(*it, 1);
    it--;
    ASSERT_TRUE(it.get_node()->is_end_);

    it = bst.insert(4);
    ASSERT_EQ(*it, 4);
    it++;
    ASSERT_EQ(*it, 5);
    it--;
    ASSERT_EQ(*it, 4);
    it--;
    ASSERT_EQ(*it, 3);

    it = bst.insert(6);
    ASSERT_EQ(*it, 6);
    it++;
    ASSERT_EQ(*it, 7);
    it--;
    ASSERT_EQ(*it, 6);
    it--;
    ASSERT_EQ(*it, 5);

    it = bst.insert(9);
    ASSERT_EQ(*it, 9);
    it++;
    ASSERT_TRUE(it.get_node()->is_end_);
    it--;
    ASSERT_EQ(*it, 9);
    it--;
    ASSERT_EQ(*it, 7);
}

TEST(BinarySearchTreeTestSuite, EraseWithReturnIteratorTest) {
    BinarySearchTree<int> bst;
    bst.insert(5);
    bst.insert(3);
    bst.insert(7);
    bst.insert(1);
    bst.insert(4);
    bst.insert(6);
    bst.insert(9);
    BinarySearchTree<int>::iterator it;

    it = bst.erase(bst.find(5));
    ASSERT_EQ(*it, 6);
    it--;
    ASSERT_EQ(*it, 4);

    it = bst.erase(bst.find(3));
    ASSERT_EQ(*it, 4);
    it--;
    ASSERT_EQ(*it, 1);

    it = bst.erase(bst.find(7));
    ASSERT_EQ(*it, 9);
    it--;
    ASSERT_EQ(*it, 6);

    it = bst.erase(bst.find(1));
    ASSERT_EQ(*it, 4);
    it--;
    ASSERT_TRUE(it.get_node()->is_end_);

    it = bst.erase(bst.find(4));
    ASSERT_EQ(*it, 6);
    it--;
    ASSERT_TRUE(it.get_node()->is_end_);

    it = bst.erase(bst.find(6));
    ASSERT_EQ(*it, 9);
    it--;
    ASSERT_TRUE(it.get_node()->is_end_);

    it = bst.erase(bst.find(9));
    ASSERT_TRUE(it.get_node()->is_end_);
}

TEST(BinarySearchTreeTestSuite, ClearTest) {
    BinarySearchTree<int> bst;
    bst.insert(5);
    bst.insert(7);
    bst.insert(4);
    bst.insert(9);
    ASSERT_EQ(bst.size(), 4);
    bst.clear();
    ASSERT_EQ(bst.size(), 0);
    ASSERT_TRUE(bst.empty());
}

TEST(BinarySearchTreeTestSuite, LowerUpperBoundTest) {
    BinarySearchTree<int> bst;
    bst.insert(3);
    bst.insert(1);
    bst.insert(4);
    ASSERT_EQ(*bst.lower_bound(2), 3);
    ASSERT_EQ(*bst.lower_bound(3), 3);
    ASSERT_EQ(*bst.upper_bound(2), 3);
    ASSERT_EQ(*bst.upper_bound(3), 4);
    ASSERT_EQ(*bst.lower_bound(4), 4);
    ASSERT_TRUE(bst.upper_bound(4) == bst.cend());
}

TEST(BinarySearchTreeTestSuite, EqualRangeTest) {
    BinarySearchTree<int> bst;
    bst.insert(3);
    bst.insert(1);
    bst.insert(4);
    ASSERT_EQ(*bst.equal_range(2).first, 3);
    ASSERT_EQ(*bst.equal_range(2).second, 3);
    ASSERT_EQ(*bst.equal_range(3).first, 3);
    ASSERT_EQ(*bst.equal_range(3).second, 4);
    ASSERT_EQ(*bst.equal_range(4).first, 4);
    ASSERT_TRUE(bst.equal_range(3).second == bst.cend());
}

TEST(BinarySearchTreeTestSuite, ExtractTest) {
    BinarySearchTree<int> bst;
    bst.insert(5);
    bst.insert(3);
    bst.insert(7);
    bst.insert(1);
    bst.insert(4);
    bst.insert(6);
    bst.insert(9);

    ASSERT_EQ(bst.extract(7).data_, 7);
    ASSERT_FALSE(bst.contains(7));
    ASSERT_EQ(bst.extract(1).data_, 1);
    ASSERT_FALSE(bst.contains(1));
}