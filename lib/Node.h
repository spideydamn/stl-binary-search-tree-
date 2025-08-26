#pragma once

template<typename T, class Compare = std::less<T>, class Allocator = std::allocator<T>>
struct Node {
    Node(T data, Node<T, Compare, Allocator> *parent);
    explicit Node(Node<T, Compare, Allocator>* parent, bool is_end=true);
    Node(const Node<T, Compare, Allocator>& node, const Allocator& alloc=Allocator(), Node<T, Compare, Allocator>* parent=nullptr);

    bool operator==(Node<T, Compare, Allocator> const& node);
    bool operator!=(Node<T, Compare, Allocator> const& node);

    bool is_end_ = false;
    T data_;
    Node<T, Compare, Allocator>* left_= nullptr;
    Node<T, Compare, Allocator>* right_= nullptr;
    Node<T, Compare, Allocator>* parent_= nullptr;
};

template<typename T, class Compare, class Allocator>
Node<T, Compare, Allocator>::Node(Node* parent, bool is_end) : parent_(parent), is_end_(is_end) {}

template<typename T, class Compare, class Allocator>
Node<T, Compare, Allocator>::Node(T data, Node* parent) : data_(data), left_(nullptr), right_(nullptr), parent_(parent) {}

template<typename T, class Compare, class Allocator>
Node<T, Compare, Allocator>::Node(const Node<T, Compare, Allocator>& node, const Allocator& alloc, Node<T, Compare, Allocator>* parent) {
    data_ = node.data_;
    parent_ = parent;
    if (node.left_ != nullptr) {
        left_ = new Node(*node.left_, alloc, this);
    } else {
        left_ = nullptr;
    }
    if (node.right_ != nullptr) {
        right_= new Node(*node.right_, alloc, this);
    } else {
        right_ = nullptr;
    }
}

template<typename T, class Compare, class Allocator>
bool Node<T, Compare, Allocator>::operator==(Node<T, Compare, Allocator> const& node) {
    bool is_equal = !Compare()(data_, node.data_) && !Compare()(node.data_, data_);
    if ((node.left_ == nullptr) ^ (left_ == nullptr)) {
        return false;
    }
    if ((node.right_ == nullptr) ^ (right_ == nullptr)) {
        return false;
    }
    if ((node.left_ != nullptr) && (left_ != nullptr)) {
        is_equal = is_equal && (*node.left_ == *left_);
    }
    if ((node.right_ != nullptr) && (right_ != nullptr)) {
        is_equal = is_equal && (*node.right_ == *right_);
    }
    return is_equal;
}

template<typename T, class Compare, class Allocator>
bool Node<T, Compare, Allocator>::operator!=(const Node<T, Compare, Allocator>& node) {
    bool is_not_equal = Compare()(data_, node.data_) || Compare()(node.data_, data_);
    if ((node.left_ == nullptr) ^ (left_ == nullptr)) {
        return true;
    }
    if ((node.right_ == nullptr) ^ (right_ == nullptr)) {
        return true;
    }
    if ((node.left_ != nullptr) && (left_ != nullptr)) {
        is_not_equal = is_not_equal || (*node.left_ != *left_);
    }
    if ((node.right_ != nullptr) && (right_ != nullptr)) {
        is_not_equal = is_not_equal || (*node.right_ != *right_);
    }
    return is_not_equal;
}