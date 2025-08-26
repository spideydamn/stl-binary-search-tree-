#pragma once

#include "Node.h"
#include "tag.cpp"
#include "ReverseIterator.h"

template<class T, class Traversal = InOrder, class Category = std::bidirectional_iterator_tag, class Distance = std::ptrdiff_t, class Pointer = const T*, class Reference = const T&>
class const_iterator_ {
public:
    typedef InOrder traversal_type;
    typedef std::bidirectional_iterator_tag iterator_category;
    typedef T value_type;
    typedef std::ptrdiff_t difference_type;
    typedef const T* pointer;
    typedef const T& reference;
    typedef Node<T> node_type;

    const_iterator_();
    explicit const_iterator_(node_type* node);
    const_iterator_(const const_iterator_& iter);
    ~const_iterator_();

    const_iterator_& operator=(const const_iterator_& iter);

    bool operator==(const const_iterator_& iter) const;
    bool operator!=(const const_iterator_& iter) const;

    template<class Tr2 = Traversal>
    const_iterator_& operator++();
    template<class Tr2 = Traversal>
    const_iterator_ operator++(int);
    template<class Tr2 = Traversal>
    const_iterator_& operator--();
    template<class Tr2 = Traversal>
    const_iterator_ operator--(int);

    reference operator*() const;
    pointer operator->() const;

    node_type* get_node() const;
private:
    node_type* node;

    const_iterator_& pre_increment(tag<InOrder>);
    const_iterator_ post_increment(tag<InOrder>);
    const_iterator_& pre_decrement(tag<InOrder>);
    const_iterator_ post_decrement(tag<InOrder>);

    const_iterator_& pre_increment(tag<PreOrder>);
    const_iterator_ post_increment(tag<PreOrder>);
    const_iterator_& pre_decrement(tag<PreOrder>);
    const_iterator_ post_decrement(tag<PreOrder>);

    const_iterator_& pre_increment(tag<PostOrder>);
    const_iterator_ post_increment(tag<PostOrder>);
    const_iterator_& pre_decrement(tag<PostOrder>);
    const_iterator_ post_decrement(tag<PostOrder>);
};

template<class T, class Traversal, class Category, class Distance, class Pointer, class Reference>
const_iterator_<T, Traversal, Category, Distance, Pointer, Reference>::const_iterator_() {
    node = nullptr;
}

template<class T, class Traversal, class Category, class Distance, class Pointer, class Reference>
const_iterator_<T, Traversal, Category, Distance, Pointer, Reference>::const_iterator_(const_iterator_::node_type* node) {
    this->node = node;
}

template<class T, class Traversal, class Category, class Distance, class Pointer, class Reference>
const_iterator_<T, Traversal, Category, Distance, Pointer, Reference>::const_iterator_(const const_iterator_<T, Traversal, Category, Distance, Pointer, Reference>& iter) {
    node = iter.get_node();
}

template<class T, class Traversal, class Category, class Distance, class Pointer, class Reference>
const_iterator_<T, Traversal, Category, Distance, Pointer, Reference>::~const_iterator_() {
    node = nullptr;
}


template<class T, class Traversal, class Category, class Distance, class Pointer, class Reference>
const_iterator_<T, Traversal, Category, Distance, Pointer, Reference>& const_iterator_<T, Traversal, Category, Distance, Pointer, Reference>::operator=(const const_iterator_<T, Traversal, Category, Distance, Pointer, Reference>& iter) {
    node = iter.get_node();
    return *this;
}


template<class T, class Traversal, class Category, class Distance, class Pointer, class Reference>
bool const_iterator_<T, Traversal, Category, Distance, Pointer, Reference>::operator==(const const_iterator_& iter) const {
    if (node->is_end_ && iter.get_node()->is_end_ && node->parent_ == iter.get_node()->parent_) {
        return true;
    }
    if (node->is_end_ && iter.get_node()->is_end_) {
        return false;
    }
    return node != iter.get_node();
}

template<class T, class Traversal, class Category, class Distance, class Pointer, class Reference>
bool const_iterator_<T, Traversal, Category, Distance, Pointer, Reference>::operator!=(const const_iterator_& iter) const {
    if (node->is_end_ && iter.get_node()->is_end_ && node->parent_ == iter.get_node()->parent_) {
        return false;
    }
    if (node->is_end_ && iter.get_node()->is_end_) {
        return true;
    }
    return node != iter.get_node();
}

template<class T, class Traversal, class Category, class Distance, class Pointer, class Reference>
template<class Tr2>
const_iterator_<T, Traversal, Category, Distance, Pointer, Reference>& const_iterator_<T, Traversal, Category, Distance, Pointer, Reference>::operator++() {
    return pre_increment(tag<Tr2>{});
}

template<class T, class Traversal, class Category, class Distance, class Pointer, class Reference>
template<class Tr2>
const_iterator_<T, Traversal, Category, Distance, Pointer, Reference> const_iterator_<T, Traversal, Category, Distance, Pointer, Reference>::operator++(int) {
    return post_increment(tag<Tr2>{});
}

template<class T, class Traversal, class Category, class Distance, class Pointer, class Reference>
template<class Tr2>
const_iterator_<T, Traversal, Category, Distance, Pointer, Reference>& const_iterator_<T, Traversal, Category, Distance, Pointer, Reference>::operator--() {
    return pre_decrement(tag<Tr2>{});
}

template<class T, class Traversal, class Category, class Distance, class Pointer, class Reference>
template<class Tr2>
const_iterator_<T, Traversal, Category, Distance, Pointer, Reference> const_iterator_<T, Traversal, Category, Distance, Pointer, Reference>::operator--(int) {
    return post_decrement(tag<Tr2>{});
}

template<class T, class Traversal, class Category, class Distance, class Pointer, class Reference>
const_iterator_<T, Traversal, Category, Distance, Pointer, Reference>& const_iterator_<T, Traversal, Category, Distance, Pointer, Reference>::pre_increment(tag<InOrder>) {
    if (node->is_end_) {
        node_type* end_node = node;
        node = node->parent_;
        delete end_node;
        return *this;
    }
    if (next_node<T>(node) == nullptr) {
        node = new Node<T>(node);
        return *this;
    }
    node = next_node<T>(node);
    return *this;
}

template<class T, class Traversal, class Category, class Distance, class Pointer, class Reference>
const_iterator_<T, Traversal, Category, Distance, Pointer, Reference> const_iterator_<T, Traversal, Category, Distance, Pointer, Reference>::post_increment(tag<InOrder>) {
    const_iterator_<T, InOrder> temp = *this;
    if (node->is_end_) {
        node_type* end_node = node;
        node = node->parent_;
        delete end_node;
        return temp;
    }
    if (next_node<T>(node) == nullptr) {
        node = new Node<T>(node);
        return temp;
    }
    node = next_node<T>(node);
    return temp;
}

template<class T, class Traversal, class Category, class Distance, class Pointer, class Reference>
const_iterator_<T, Traversal, Category, Distance, Pointer, Reference>& const_iterator_<T, Traversal, Category, Distance, Pointer, Reference>::pre_decrement(tag<InOrder>) {
    if (node->is_end_) {
        node_type* end_node = node;
        node = node->parent_;
        delete end_node;
        return *this;
    }
    if (prev_node<T>(node) == nullptr) {
        node = new Node<T>(node);
        return *this;
    }
    node = prev_node<T>(node);
    return *this;
}

template<class T, class Traversal, class Category, class Distance, class Pointer, class Reference>
const_iterator_<T, Traversal, Category, Distance, Pointer, Reference> const_iterator_<T, Traversal, Category, Distance, Pointer, Reference>::post_decrement(tag<InOrder>) {
    const_iterator_<T, InOrder> temp = *this;
    if (node->is_end_) {
        node_type* end_node = node;
        node = node->parent_;
        delete end_node;
        return temp;
    }
    if (prev_node<T>(node) == nullptr) {
        node = new Node<T>(node);
        return temp;
    }
    node = prev_node<T>(node);
    return temp;
}


template<class T, class Traversal, class Category, class Distance, class Pointer, class Reference>
const_iterator_<T, Traversal, Category, Distance, Pointer, Reference>& const_iterator_<T, Traversal, Category, Distance, Pointer, Reference>::pre_increment(tag<PreOrder>) {
    if (node->is_end_) {
        node_type* end_node = node;
        node = node->parent_;
        delete end_node;
        return *this;
    }
    if (node->left_ != nullptr) {
        node = node->left_;
        return *this;
    }
    if (node->right_ != nullptr) {
        node = node->right_;
        return *this;
    }
    while ((node->parent_ != nullptr) && ((node->parent_->left_ == nullptr) || (node->parent_->left_ != node) || (node->parent_->right_ == nullptr))) {
        node = node->parent_;
    }
    if (node->parent_ != nullptr) {
        node = node->parent_->right_;
        return *this;
    }
    node = new Node<T>(maximum<T>(node));
    return *this;
}

template<class T, class Traversal, class Category, class Distance, class Pointer, class Reference>
const_iterator_<T, Traversal, Category, Distance, Pointer, Reference> const_iterator_<T, Traversal, Category, Distance, Pointer, Reference>::post_increment(tag<PreOrder>) {
    const_iterator_<T, PreOrder> temp = *this;
    if (node->is_end_) {
        node_type* end_node = node;
        node = node->parent_;
        delete end_node;
        return temp;
    }
    if (node->left_ != nullptr) {
        node = node->left_;
        return temp;
    }
    if (node->right_ != nullptr) {
        node = node->right_;
        return temp;
    }
    while ((node->parent_ != nullptr) && ((node->parent_->left_ == nullptr) || (node->parent_->left_ != node) || (node->parent_->right_ == nullptr))) {
        node = node->parent_;
    }
    if (node->parent_ != nullptr) {
        node = node->parent_->right_;
        return temp;
    }
    node = new Node<T>(maximum<T>(node));
    return temp;
}

template<class T, class Traversal, class Category, class Distance, class Pointer, class Reference>
const_iterator_<T, Traversal, Category, Distance, Pointer, Reference>& const_iterator_<T, Traversal, Category, Distance, Pointer, Reference>::pre_decrement(tag<PreOrder>) {
    if (node->is_end_) {
        node_type* end_node = node;
        node = node->parent_;
        delete end_node;
        return *this;
    }
    if (node->parent_ == nullptr) {
        node = new Node<T>(node);
        return *this;
    }
    if (node->parent_->left_ != nullptr && node->parent_->right_ == node) {
        node = maximum<T>(node->parent_->left_);
        return *this;
    }
    node = node->parent_;
    return *this;
}

template<class T, class Traversal, class Category, class Distance, class Pointer, class Reference>
const_iterator_<T, Traversal, Category, Distance, Pointer, Reference> const_iterator_<T, Traversal, Category, Distance, Pointer, Reference>::post_decrement(tag<PreOrder>) {
    const_iterator_<T, PreOrder> temp = *this;
    if (node->is_end_) {
        node_type* end_node = node;
        node = node->parent_;
        delete end_node;
        return temp;
    }
    if (node->parent_ == nullptr) {
        node = new Node<T>(node);
        return temp;
    }
    if (node->parent_->left_ != nullptr && node->parent_->right_ == node) {
        node = maximum<T>(node->parent_->left_);
        return temp;
    }
    node = node->parent_;
    return temp;
}



template<class T, class Traversal, class Category, class Distance, class Pointer, class Reference>
const_iterator_<T, Traversal, Category, Distance, Pointer, Reference>& const_iterator_<T, Traversal, Category, Distance, Pointer, Reference>::pre_increment(tag<PostOrder>) {
    if (node->is_end_) {
        node_type* end_node = node;
        node = node->parent_;
        delete end_node;
        return *this;
    }
    if (node->parent_ == nullptr) {
        node = new Node<T>(node);
        return *this;
    }
    if (node->parent_->right_ != nullptr && node->parent_->left_ == node) {
        node = minimum<T>(node->parent_->right_);
        return *this;
    }
    node = node->parent_;
    return *this;
}

template<class T, class Traversal, class Category, class Distance, class Pointer, class Reference>
const_iterator_<T, Traversal, Category, Distance, Pointer, Reference> const_iterator_<T, Traversal, Category, Distance, Pointer, Reference>::post_increment(tag<PostOrder>) {
    const_iterator_<T, PostOrder> temp = *this;
    if (node->is_end_) {
        node_type* end_node = node;
        node = node->parent_;
        delete end_node;
        return temp;
    }
    if (node->parent_ == nullptr) {
        node = new Node<T>(node);
        return temp;
    }
    if (node->parent_->right_ != nullptr && node->parent_->left_ == node) {
        node = minimum<T>(node->parent_->right_);
        return temp;
    }
    node = node->parent_;
    return temp;
}

template<class T, class Traversal, class Category, class Distance, class Pointer, class Reference>
const_iterator_<T, Traversal, Category, Distance, Pointer, Reference>& const_iterator_<T, Traversal, Category, Distance, Pointer, Reference>::pre_decrement(tag<PostOrder>) {
    if (node->is_end_) {
        node_type* end_node = node;
        node = node->parent_;
        delete end_node;
        return *this;
    }
    if (node->right_ != nullptr) {
        node = node->right_;
        return *this;
    }
    if (node->left_ != nullptr) {
        node = node->left_;
        return *this;
    }
    while ((node->parent_ != nullptr) && ((node->parent_->left_ == nullptr) || (node->parent_->right_ != node) || (node->parent_->right_ == nullptr))) {
        node = node->parent_;
    }
    if (node->parent_ != nullptr) {
        node = node->parent_->left_;
        return *this;
    }
    node = new Node<T>(minimum<T>(node));
    return *this;
}

template<class T, class Traversal, class Category, class Distance, class Pointer, class Reference>
const_iterator_<T, Traversal, Category, Distance, Pointer, Reference> const_iterator_<T, Traversal, Category, Distance, Pointer, Reference>::post_decrement(tag<PostOrder>) {
    const_iterator_<T, PostOrder> temp = *this;
    if (node->is_end_) {
        node_type* end_node = node;
        node = node->parent_;
        delete end_node;
        return temp;
    }
    if (node->right_ != nullptr) {
        node = node->right_;
        return temp;
    }
    if (node->left_ != nullptr) {
        node = node->left_;
        return temp;
    }
    while ((node->parent_ != nullptr) && ((node->parent_->left_ == nullptr) || (node->parent_->right_ != node) || (node->parent_->right_ == nullptr))) {
        node = node->parent_;
    }
    if (node->parent_ != nullptr) {
        node = node->parent_->left_;
        return temp;
    }
    node = new Node<T>(minimum<T>(node));
    return temp;
}

template<class T, class Traversal, class Category, class Distance, class Pointer, class Reference>
const_iterator_<T, Traversal, Category, Distance, Pointer, Reference>::reference const_iterator_<T, Traversal, Category, Distance, Pointer, Reference>::operator*() const {
    return node->data_;
}

template<class T, class Traversal, class Category, class Distance, class Pointer, class Reference>
const_iterator_<T, Traversal, Category, Distance, Pointer, Reference>::pointer const_iterator_<T, Traversal, Category, Distance, Pointer, Reference>::operator->() const {
    return (*this);
}

template<class T, class Traversal, class Category, class Distance, class Pointer, class Reference>
const_iterator_<T, Traversal, Category, Distance, Pointer, Reference>::node_type* const_iterator_<T, Traversal, Category, Distance, Pointer, Reference>::get_node() const {
    return node;
}