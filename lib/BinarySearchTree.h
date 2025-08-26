#pragma once

#include <iostream>

#include "Node.h"
#include "Iterator.h"

template<class Key, class Traversal = InOrder, class Compare = std::less<Key>, class Allocator = std::allocator<Key>>
class BinarySearchTree {
public:
    typedef Key key_type;
    typedef Key value_type;
    typedef unsigned long long size_type;
    typedef std::ptrdiff_t difference_type;
    typedef Compare key_compare;
    typedef Compare value_compare;
    typedef Allocator allocator_type;
    typedef value_type& reference;
    typedef const value_type& const_reference;
    typedef std::allocator_traits<Allocator>::pointer pointer;
    typedef std::allocator_traits<Allocator>::const_pointer const_pointer;
    typedef Node<Key, Compare, Allocator> node_type;
    
    typedef const_iterator_<Key, Traversal> iterator;
    typedef const_iterator_<Key, Traversal> const_iterator;
    typedef const_reverse_iterator_<Key, Traversal> reverse_iterator;
    typedef const_reverse_iterator_<Key, Traversal> const_reverse_iterator;

    // member functions

    BinarySearchTree();
    explicit BinarySearchTree(const Compare& comp, const Allocator& alloc = Allocator());
    explicit BinarySearchTree(const Allocator& alloc);
    template<class InputIt>
    BinarySearchTree(InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator());
    template<class InputIt>
    BinarySearchTree(InputIt first, InputIt last, const Allocator& alloc);
    BinarySearchTree(const BinarySearchTree<Key, Traversal, Compare, Allocator>& other);
    BinarySearchTree(const BinarySearchTree<Key, Traversal, Compare, Allocator>& other, const Allocator& alloc);
    BinarySearchTree(std::initializer_list<value_type> init, const Compare& comp = Compare(), const Allocator& alloc = Allocator());
    BinarySearchTree(std::initializer_list<value_type> init, const Allocator& alloc);

    ~BinarySearchTree();

    BinarySearchTree<Key, Traversal, Compare, Allocator>& operator=(const BinarySearchTree<Key, Traversal, Compare, Allocator>& other);
    BinarySearchTree<Key, Traversal, Compare, Allocator>& operator=( std::initializer_list<value_type> ilist);

    allocator_type get_allocator() const noexcept;


    // iterators
    template<class Traversal2=Traversal>
    iterator begin() const noexcept;
    iterator begin(tag<InOrder>) const noexcept;
    iterator begin(tag<PreOrder>) const noexcept;
    iterator begin(tag<PostOrder>) const noexcept;
    template<class Traversal2=Traversal>
    const_iterator cbegin() const noexcept;
    const_iterator cbegin(tag<InOrder>) const noexcept;
    const_iterator cbegin(tag<PreOrder>) const noexcept;
    const_iterator cbegin(tag<PostOrder>) const noexcept;

    template<class Traversal2=Traversal>
    iterator end() const noexcept;
    iterator end(tag<InOrder>) const noexcept;
    iterator end(tag<PreOrder>) const noexcept;
    iterator end(tag<PostOrder>) const noexcept;
    template<class Traversal2=Traversal>
    const_iterator cend() const noexcept;
    const_iterator cend(tag<InOrder>) const noexcept;
    const_iterator cend(tag<PreOrder>) const noexcept;
    const_iterator cend(tag<PostOrder>) const noexcept;

    template<class Traversal2=Traversal>
    reverse_iterator rbegin() const noexcept;
    reverse_iterator rbegin(tag<InOrder>) const noexcept;
    reverse_iterator rbegin(tag<PreOrder>) const noexcept;
    reverse_iterator rbegin(tag<PostOrder>) const noexcept;
    template<class Traversal2=Traversal>
    const_reverse_iterator crbegin() const noexcept;
    const_reverse_iterator crbegin(tag<InOrder>) const noexcept;
    const_reverse_iterator crbegin(tag<PreOrder>) const noexcept;
    const_reverse_iterator crbegin(tag<PostOrder>) const noexcept;

    template<class Traversal2=Traversal>
    reverse_iterator rend() const noexcept;
    reverse_iterator rend(tag<InOrder>) const noexcept;
    reverse_iterator rend(tag<PreOrder>) const noexcept;
    reverse_iterator rend(tag<PostOrder>) const noexcept;
    template<class Traversal2=Traversal>
    const_reverse_iterator crend() const noexcept;
    const_reverse_iterator crend(tag<InOrder>) const noexcept;
    const_reverse_iterator crend(tag<PreOrder>) const noexcept;
    const_reverse_iterator crend(tag<PostOrder>) const noexcept;


    // Capacity

    [[nodiscard]] bool empty() const noexcept;
    [[nodiscard]] size_type size() const noexcept;
    [[nodiscard]] size_type max_size() const noexcept;


    // Modifiers

    void clear() noexcept;

    iterator insert(const value_type& value);
    iterator insert(const_iterator pos, const value_type& value);
    template<class InputIt>
    void insert(InputIt first, InputIt last);
    void insert(std::initializer_list<value_type> ilist);

    iterator erase(const_iterator pos);
    iterator erase(const_iterator first, const_iterator last);
    size_type erase(const Key& key);

    void swap(BinarySearchTree<Key, Traversal, Compare, Allocator>& other) noexcept;

    node_type extract(const_iterator position);
    node_type extract(const Key& k);

    template<class C2>
    void merge(BinarySearchTree<Key, C2, Allocator>& source);

    // Lookup

    size_type count(const Key& key) const;

    const_iterator find(const Key& key) const;

    bool contains(const Key& key) const;

    std::pair<const_iterator, const_iterator> equal_range(const Key& key) const;

    const_iterator lower_bound(const Key& key) const;

    const_iterator upper_bound(const Key& key) const;


    // Observers
    key_compare key_comp() const;
    value_compare value_comp() const;

    // Non-member functions
    template<class K, class C, class A>
    friend bool operator==(const BinarySearchTree<K, C, A>& lhs, const BinarySearchTree<Key, Traversal, Compare, Allocator>& rhs);
    template<class K, class C, class A>
    friend bool operator!=(const BinarySearchTree<K, C, A>& lhs, const BinarySearchTree<Key, Traversal, Compare, Allocator>& rhs);

    bool operator==(const BinarySearchTree<Key, Traversal, Compare, Allocator>& rhs);
    bool operator!=(const BinarySearchTree<Key, Traversal, Compare, Allocator>& rhs);
private:
    node_type* root_ = nullptr;
    unsigned long long size_ = 0;

    node_type* find_node(const Key& key) const;

    void erase(node_type*& root, node_type*& erased_node);

    void swap(node_type* node_1, node_type* node_2);

    void delete_children(node_type* node);

    iterator insert(const value_type &value, const Compare &comp, const Allocator &allocator);
};

template<class Key, class Traversal, class Compare, class Allocator>
std::pair<typename BinarySearchTree<Key, Traversal, Compare, Allocator>::const_iterator, typename BinarySearchTree<Key, Traversal, Compare, Allocator>::const_iterator> BinarySearchTree<Key, Traversal, Compare, Allocator>::equal_range(const Key &key) const {
    return std::make_pair(this->lower_bound(key), this->upper_bound(key));
}

template<class Key>
BinarySearchTree<Key>::node_type* minimum(typename BinarySearchTree<Key>::node_type* subtree_root);
template<class Key>
BinarySearchTree<Key>::node_type* maximum(typename BinarySearchTree<Key>::node_type* subtree_root);
template<class Key>
BinarySearchTree<Key>::node_type* next_node(typename BinarySearchTree<Key>::node_type* node);
template<class Key>
BinarySearchTree<Key>::node_type* prev_node(typename BinarySearchTree<Key>::node_type* node);

template<class Key, class Traversal, class Compare, class Allocator>
bool BinarySearchTree<Key, Traversal, Compare, Allocator>::operator==(const BinarySearchTree<Key, Traversal, Compare, Allocator>& rhs) {
    if (this->size_ != rhs.size_ || (this->root_ == nullptr ^ rhs.root_ == nullptr)) {
        return false;
    }
    return (*this->root_ == *rhs.root_);
}

template<class Key, class Traversal, class Compare, class Allocator>
bool BinarySearchTree<Key, Traversal, Compare, Allocator>::operator!=(const BinarySearchTree<Key, Traversal, Compare, Allocator>& rhs) {
    if (this->size_ != rhs.size_ || (this->root_ == nullptr ^ rhs.root_ == nullptr)) {
        return true;
    }
    return (*this->root_ != *rhs.root_);
}

// Non-member functions

template<class Key, class Traversal, class Compare, class Allocator>
void swap(BinarySearchTree<Key, Traversal, Compare, Allocator>& lhs, BinarySearchTree<Key, Traversal, Compare, Allocator>& rhs) noexcept {
    lhs.swap(rhs);
}

template<class Key, class Traversal, class Compare, class Allocator>
bool operator==(const BinarySearchTree<Key, Traversal, Compare, Allocator>& lhs, const BinarySearchTree<Key, Traversal, Compare, Allocator>& rhs) {
    if (lhs.size_ != rhs.size_ || (lhs.root_ == nullptr ^ rhs.root_ == nullptr)) {
        return false;
    }
    return (*lhs.root_ == *rhs.root_);
}

template<class Key, class Traversal, class Compare, class Allocator>
bool operator!=(const BinarySearchTree<Key, Traversal, Compare, Allocator>& lhs, const BinarySearchTree<Key, Traversal, Compare, Allocator>& rhs) {
    if (lhs.size_ != rhs.size_ || (lhs.root_ == nullptr ^ rhs.root_ == nullptr)) {
        return true;
    }
    return (*lhs.root_ != *rhs.root_);
}

template<class Key, class Traversal, class Compare, class Allocator, class Predicate>
typename BinarySearchTree<Key, Traversal, Compare, Allocator>::size_type erase_if(BinarySearchTree<Key, Traversal, Compare, Allocator>& c, Predicate predicate) {
    auto old_size = c.size();
    for (auto first = c.begin(), last = c.end(); first != last;) {
        if (predicate(*first)) {
            first = c.erase(first);
        } else {
            ++first;
        }
    }
    return old_size - c.size();
}


// Implementation of member functions

template<class Key, class Traversal, class Compare, class Allocator>
BinarySearchTree<Key, Traversal, Compare, Allocator>::BinarySearchTree() : BinarySearchTree<Key, Traversal, Compare, Allocator>::BinarySearchTree(Compare()) {}

template<class Key, class Traversal, class Compare, class Allocator>
BinarySearchTree<Key, Traversal, Compare, Allocator>::BinarySearchTree(const Compare& comp, const Allocator& alloc) {
    this->~BinarySearchTree<Key, Traversal, Compare, Allocator>();
    root_ = nullptr;
    size_ = 0;
}

template<class Key, class Traversal, class Compare, class Allocator>
BinarySearchTree<Key, Traversal, Compare, Allocator>::BinarySearchTree(const Allocator& alloc) : BinarySearchTree<Key, Traversal, Compare, Allocator>(Compare(), alloc) {}

template<class Key, class Traversal, class Compare, class Allocator>
template<class InputIt>
BinarySearchTree<Key, Traversal, Compare, Allocator>::BinarySearchTree(InputIt first, InputIt last, const Compare& comp, const Allocator& alloc) {
    for (InputIt it = first; it != last; ++it) {
        insert(*it, comp, alloc);
    }
}

template<class Key, class Traversal, class Compare, class Allocator>
template<class InputIt>
BinarySearchTree<Key, Traversal, Compare, Allocator>::BinarySearchTree(InputIt first, InputIt last, const Allocator& alloc) : BinarySearchTree<Key, Traversal, Compare, Allocator>(first, last, Compare(), alloc) {}

template<class Key, class Traversal, class Compare, class Allocator>
BinarySearchTree<Key, Traversal, Compare, Allocator>::BinarySearchTree(const BinarySearchTree<Key, Traversal, Compare, Allocator>& other) : BinarySearchTree<Key, Traversal, Compare, Allocator>(other, std::allocator_traits<allocator_type>::select_on_container_copy_construction(other.get_allocator())) {}

template<class Key, class Traversal, class Compare, class Allocator>
BinarySearchTree<Key, Traversal, Compare, Allocator>::BinarySearchTree(const BinarySearchTree<Key, Traversal, Compare, Allocator>& other, const Allocator& alloc) {
    this->~BinarySearchTree<Key, Traversal, Compare, Allocator>();
    root_ = new Node<Key, Compare, Allocator>(*other.root_, alloc);
    size_ = other.size_;
}

template<class Key, class Traversal, class Compare, class Allocator>
BinarySearchTree<Key, Traversal, Compare, Allocator>::BinarySearchTree(std::initializer_list<value_type> init, const Compare& comp, const Allocator& alloc) : BinarySearchTree<Key, Traversal, Compare, Allocator>(init.begin(), init.end(), comp, alloc) {}

template<class Key, class Traversal, class Compare, class Allocator>
BinarySearchTree<Key, Traversal, Compare, Allocator>::BinarySearchTree(std::initializer_list<value_type> init, const Allocator& alloc) : BinarySearchTree<Key, Traversal, Compare, Allocator>(init, Compare(), alloc) {}


template<class Key, class Traversal, class Compare, class Allocator>
BinarySearchTree<Key, Traversal, Compare, Allocator>::~BinarySearchTree() {
    if (this->empty()) {
        return;
    }
    delete_children(root_);
    root_ = nullptr;
    size_ = 0;
}


template<class Key, class Traversal, class Compare, class Allocator>
BinarySearchTree<Key, Traversal, Compare, Allocator>& BinarySearchTree<Key, Traversal, Compare, Allocator>::operator=(const BinarySearchTree<Key, Traversal, Compare, Allocator>& other) {
    if (this !=& other) {
        this->~BinarySearchTree<Key, Traversal, Compare, Allocator>();
        root_ = new Node<Key, Compare, Allocator>(*other.root_);
        size_ = other.size_;
    }
    return *this;
}

template<class Key, class Traversal, class Compare, class Allocator>
BinarySearchTree<Key, Traversal, Compare, Allocator>& BinarySearchTree<Key, Traversal, Compare, Allocator>::operator=(std::initializer_list<value_type> ilist) {
    for (auto it = ilist.begin(); it != ilist.end(); ++it) {
        insert(*it);
    }
    return *this;
}


template<class Key, class Traversal, class Compare, class Allocator>
BinarySearchTree<Key, Traversal, Compare, Allocator>::allocator_type BinarySearchTree<Key, Traversal, Compare, Allocator>::get_allocator() const noexcept {
    return Allocator();
}


// Iterator

template<class Key, class Traversal, class Compare, class Allocator>
template<class Traversal2>
BinarySearchTree<Key, Traversal, Compare, Allocator>::iterator BinarySearchTree<Key, Traversal, Compare, Allocator>::begin() const noexcept {
    if (root_ == nullptr) {
        return end();
    }
    return begin(tag<Traversal2>{});
}
template<class Key, class Traversal, class Compare, class Allocator>
BinarySearchTree<Key, Traversal, Compare, Allocator>::iterator BinarySearchTree<Key, Traversal, Compare, Allocator>::begin(tag<InOrder>) const noexcept {
    return iterator(minimum<Key>(root_));
}
template<class Key, class Traversal, class Compare, class Allocator>
BinarySearchTree<Key, Traversal, Compare, Allocator>::iterator BinarySearchTree<Key, Traversal, Compare, Allocator>::begin(tag<PreOrder>) const noexcept {
    return iterator(root_);
}
template<class Key, class Traversal, class Compare, class Allocator>
BinarySearchTree<Key, Traversal, Compare, Allocator>::iterator BinarySearchTree<Key, Traversal, Compare, Allocator>::begin(tag<PostOrder>) const noexcept {
    return iterator(minimum<Key>(root_));
}


template<class Key, class Traversal, class Compare, class Allocator>
template<class Traversal2>
BinarySearchTree<Key, Traversal, Compare, Allocator>::const_iterator BinarySearchTree<Key, Traversal, Compare, Allocator>::cbegin() const noexcept {
    if (root_ == nullptr) {
        return cend();
    }
    return cbegin(tag<Traversal2>{});
}
template<class Key, class Traversal, class Compare, class Allocator>
BinarySearchTree<Key, Traversal, Compare, Allocator>::const_iterator BinarySearchTree<Key, Traversal, Compare, Allocator>::cbegin(tag<InOrder>) const noexcept {
    return const_iterator(minimum<Key>(root_));
}
template<class Key, class Traversal, class Compare, class Allocator>
BinarySearchTree<Key, Traversal, Compare, Allocator>::const_iterator BinarySearchTree<Key, Traversal, Compare, Allocator>::cbegin(tag<PreOrder>) const noexcept {
    return const_iterator(root_);
}
template<class Key, class Traversal, class Compare, class Allocator>
BinarySearchTree<Key, Traversal, Compare, Allocator>::const_iterator BinarySearchTree<Key, Traversal, Compare, Allocator>::cbegin(tag<PostOrder>) const noexcept {
    return const_iterator(minimum<Key>(root_));
}


template<class Key, class Traversal, class Compare, class Allocator>
template<class Traversal2>
BinarySearchTree<Key, Traversal, Compare, Allocator>::iterator BinarySearchTree<Key, Traversal, Compare, Allocator>::end() const noexcept {
    if (root_ == nullptr) {
        return iterator(new Node<Key, Compare, Allocator>(nullptr));
    }
    return end(tag<Traversal2>{});
}
template<class Key, class Traversal, class Compare, class Allocator>
BinarySearchTree<Key, Traversal, Compare, Allocator>::iterator BinarySearchTree<Key, Traversal, Compare, Allocator>::end(tag<InOrder>) const noexcept {
    return iterator(new Node<Key, Compare, Allocator>(maximum<Key>(root_)));
}
template<class Key, class Traversal, class Compare, class Allocator>
BinarySearchTree<Key, Traversal, Compare, Allocator>::iterator BinarySearchTree<Key, Traversal, Compare, Allocator>::end(tag<PreOrder>) const noexcept {
    return iterator(new Node<Key, Compare, Allocator>(maximum<Key>(root_)));
}
template<class Key, class Traversal, class Compare, class Allocator>
BinarySearchTree<Key, Traversal, Compare, Allocator>::iterator BinarySearchTree<Key, Traversal, Compare, Allocator>::end(tag<PostOrder>) const noexcept {
    return iterator(new Node<Key, Compare, Allocator>(root_));
}


template<class Key, class Traversal, class Compare, class Allocator>
template<class Traversal2>
BinarySearchTree<Key, Traversal, Compare, Allocator>::const_iterator BinarySearchTree<Key, Traversal, Compare, Allocator>::cend() const noexcept {
    if (root_ == nullptr) {
        return const_iterator(new Node<Key, Compare, Allocator>(nullptr));
    }
    return cend(tag<Traversal2>{});
}
template<class Key, class Traversal, class Compare, class Allocator>
BinarySearchTree<Key, Traversal, Compare, Allocator>::const_iterator BinarySearchTree<Key, Traversal, Compare, Allocator>::cend(tag<InOrder>) const noexcept {
    return const_iterator(new Node<Key, Compare, Allocator>(maximum<Key>(root_)));
}
template<class Key, class Traversal, class Compare, class Allocator>
BinarySearchTree<Key, Traversal, Compare, Allocator>::const_iterator BinarySearchTree<Key, Traversal, Compare, Allocator>::cend(tag<PreOrder>) const noexcept {
    return const_iterator(new Node<Key, Compare, Allocator>(maximum<Key>(root_)));
}
template<class Key, class Traversal, class Compare, class Allocator>
BinarySearchTree<Key, Traversal, Compare, Allocator>::const_iterator BinarySearchTree<Key, Traversal, Compare, Allocator>::cend(tag<PostOrder>) const noexcept {
    return const_iterator(new Node<Key, Compare, Allocator>(root_));
}


template<class Key, class Traversal, class Compare, class Allocator>
template<class Traversal2>
BinarySearchTree<Key, Traversal, Compare, Allocator>::reverse_iterator BinarySearchTree<Key, Traversal, Compare, Allocator>::rbegin() const noexcept {
    if (root_ == nullptr) {
        return rend();
    }
    return rbegin(tag<Traversal2>{});
}
template<class Key, class Traversal, class Compare, class Allocator>
BinarySearchTree<Key, Traversal, Compare, Allocator>::reverse_iterator BinarySearchTree<Key, Traversal, Compare, Allocator>::rbegin(tag<InOrder>) const noexcept {
    return reverse_iterator(maximum<Key>(root_));
}
template<class Key, class Traversal, class Compare, class Allocator>
BinarySearchTree<Key, Traversal, Compare, Allocator>::reverse_iterator BinarySearchTree<Key, Traversal, Compare, Allocator>::rbegin(tag<PreOrder>) const noexcept {
    return reverse_iterator(maximum<Key>(root_));
}
template<class Key, class Traversal, class Compare, class Allocator>
BinarySearchTree<Key, Traversal, Compare, Allocator>::reverse_iterator BinarySearchTree<Key, Traversal, Compare, Allocator>::rbegin(tag<PostOrder>) const noexcept {
    return reverse_iterator(root_);
}


template<class Key, class Traversal, class Compare, class Allocator>
template<class Traversal2>
BinarySearchTree<Key, Traversal, Compare, Allocator>::const_reverse_iterator BinarySearchTree<Key, Traversal, Compare, Allocator>::crbegin() const noexcept {
    if (root_ == nullptr) {
        return crend();
    }
    return crbegin(tag<Traversal2>{});
}
template<class Key, class Traversal, class Compare, class Allocator>
BinarySearchTree<Key, Traversal, Compare, Allocator>::const_reverse_iterator BinarySearchTree<Key, Traversal, Compare, Allocator>::crbegin(tag<InOrder>) const noexcept {
    return const_reverse_iterator(maximum<Key>(root_));
}
template<class Key, class Traversal, class Compare, class Allocator>
BinarySearchTree<Key, Traversal, Compare, Allocator>::const_reverse_iterator BinarySearchTree<Key, Traversal, Compare, Allocator>::crbegin(tag<PreOrder>) const noexcept {
    return const_reverse_iterator(maximum<Key>(root_));
}
template<class Key, class Traversal, class Compare, class Allocator>
BinarySearchTree<Key, Traversal, Compare, Allocator>::const_reverse_iterator BinarySearchTree<Key, Traversal, Compare, Allocator>::crbegin(tag<PostOrder>) const noexcept {
    return const_reverse_iterator(root_);
}


template<class Key, class Traversal, class Compare, class Allocator>
template<class Traversal2>
BinarySearchTree<Key, Traversal, Compare, Allocator>::reverse_iterator BinarySearchTree<Key, Traversal, Compare, Allocator>::rend() const noexcept {
    if (root_ == nullptr) {
        return reverse_iterator(new Node<Key, Compare, Allocator>(nullptr));
    }
    return rend(tag<Traversal2>{});
}
template<class Key, class Traversal, class Compare, class Allocator>
BinarySearchTree<Key, Traversal, Compare, Allocator>::reverse_iterator BinarySearchTree<Key, Traversal, Compare, Allocator>::rend(tag<InOrder>) const noexcept {
    return reverse_iterator(new Node<Key, Compare, Allocator>(minimum<Key>(root_)));
}
template<class Key, class Traversal, class Compare, class Allocator>
BinarySearchTree<Key, Traversal, Compare, Allocator>::reverse_iterator BinarySearchTree<Key, Traversal, Compare, Allocator>::rend(tag<PreOrder>) const noexcept {
    return reverse_iterator(new Node<Key, Compare, Allocator>(root_));
}
template<class Key, class Traversal, class Compare, class Allocator>
BinarySearchTree<Key, Traversal, Compare, Allocator>::reverse_iterator BinarySearchTree<Key, Traversal, Compare, Allocator>::rend(tag<PostOrder>) const noexcept {
    return reverse_iterator(new Node<Key, Compare, Allocator>(minimum<Key>(root_)));
}


template<class Key, class Traversal, class Compare, class Allocator>
template<class Traversal2>
BinarySearchTree<Key, Traversal, Compare, Allocator>::const_reverse_iterator BinarySearchTree<Key, Traversal, Compare, Allocator>::crend() const noexcept {
    if (root_ == nullptr) {
        return const_reverse_iterator(new Node<Key, Compare, Allocator>(nullptr));
    }
    return crend(tag<Traversal2>{});
}
template<class Key, class Traversal, class Compare, class Allocator>
BinarySearchTree<Key, Traversal, Compare, Allocator>::const_reverse_iterator BinarySearchTree<Key, Traversal, Compare, Allocator>::crend(tag<InOrder>) const noexcept {
    return const_reverse_iterator(new Node<Key, Compare, Allocator>(minimum<Key>(root_)));
}
template<class Key, class Traversal, class Compare, class Allocator>
BinarySearchTree<Key, Traversal, Compare, Allocator>::const_reverse_iterator BinarySearchTree<Key, Traversal, Compare, Allocator>::crend(tag<PreOrder>) const noexcept {
    return const_reverse_iterator(new Node<Key, Compare, Allocator>(root_));
}
template<class Key, class Traversal, class Compare, class Allocator>
BinarySearchTree<Key, Traversal, Compare, Allocator>::const_reverse_iterator BinarySearchTree<Key, Traversal, Compare, Allocator>::crend(tag<PostOrder>) const noexcept {
    return const_reverse_iterator(new Node<Key, Compare, Allocator>(minimum<Key>(root_)));
}


// Implementation of capacity

template<class Key, class Traversal, class Compare, class Allocator>
bool BinarySearchTree<Key, Traversal, Compare, Allocator>::empty() const noexcept {
    return size_ == 0;
}

template<class Key, class Traversal, class Compare, class Allocator>
BinarySearchTree<Key, Traversal, Compare, Allocator>::size_type BinarySearchTree<Key, Traversal, Compare, Allocator>::size() const noexcept {
    return size_;
}

template<class Key, class Traversal, class Compare, class Allocator>
BinarySearchTree<Key, Traversal, Compare, Allocator>::size_type BinarySearchTree<Key, Traversal, Compare, Allocator>::max_size() const noexcept {
    return static_cast<size_type>(-1);
}


// Implementation of modifiers

template<class Key, class Traversal, class Compare, class Allocator>
void BinarySearchTree<Key, Traversal, Compare, Allocator>::clear() noexcept {
    this->~BinarySearchTree<Key, Traversal, Compare, Allocator>();
}

template<class Key, class Traversal, class Compare, class Allocator>
BinarySearchTree<Key, Traversal, Compare, Allocator>::iterator BinarySearchTree<Key, Traversal, Compare, Allocator>::insert(const value_type& value) {
    ++size_;
    if (root_ == nullptr) {
        root_ = new node_type(value, nullptr);
        return iterator(root_);
    }
    node_type* current_node = root_;
    while (current_node != nullptr) {
        if (Compare()(current_node->data_, value)) {
            if (current_node->right_ != nullptr) {
                current_node = current_node->right_;
            } else {
                current_node->right_ = new node_type(value, current_node);
                return iterator(current_node->right_);
            }
        } else {
            if (current_node->left_ != nullptr) {
                current_node = current_node->left_;
            } else {
                current_node->left_ = new node_type(value, current_node);
                return iterator(current_node->left_);
            }
        }
    }
    return end();
}

template<class Key, class Traversal, class Compare, class Allocator>
BinarySearchTree<Key, Traversal, Compare, Allocator>::iterator BinarySearchTree<Key, Traversal, Compare, Allocator>::insert(const value_type& value, const Compare& comp, const Allocator& allocator) {
    ++size_;
    if (root_ == nullptr) {
        root_ = new node_type(value, nullptr);
        return iterator(root_);
    }
    node_type* current_node = root_;
    while (current_node != nullptr) {
        if (comp(current_node->data_, value)) {
            if (current_node->right_ != nullptr) {
                current_node = current_node->right_;
            } else {
                current_node->right_ = new node_type(value, current_node);
                return iterator(current_node->right_);
            }
        } else {
            if (current_node->left_ != nullptr) {
                current_node = current_node->left_;
            } else {
                current_node->left_ = new node_type(value, current_node);
                return iterator(current_node->left_);
            }
        }
    }
    return end();
}

template<class Key, class Traversal, class Compare, class Allocator>
BinarySearchTree<Key, Traversal, Compare, Allocator>::iterator BinarySearchTree<Key, Traversal, Compare, Allocator>::insert(BinarySearchTree::const_iterator pos, const value_type& value) {
    return insert(value);
}

template<class Key, class Traversal, class Compare, class Allocator>
template<class InputIt>
void BinarySearchTree<Key, Traversal, Compare, Allocator>::insert(InputIt first, InputIt last) {
    for (; first != last; ++first) {
        insert(*first);
    }
}

template<class Key, class Traversal, class Compare, class Allocator>
void BinarySearchTree<Key, Traversal, Compare, Allocator>::insert(std::initializer_list<value_type> ilist) {
    insert(ilist.begin(), ilist.end());
}

template<class Key, class Traversal, class Compare, class Allocator>
BinarySearchTree<Key, Traversal, Compare, Allocator>::iterator BinarySearchTree<Key, Traversal, Compare, Allocator>::erase(BinarySearchTree::const_iterator pos) {
    const_iterator tmp(pos);
    tmp++;
    node_type* erased_node = pos.get_node();
    erase(root_, erased_node);
    return tmp;
}

template<class Key, class Traversal, class Compare, class Allocator>
BinarySearchTree<Key, Traversal, Compare, Allocator>::iterator BinarySearchTree<Key, Traversal, Compare, Allocator>::erase(BinarySearchTree::const_iterator first, BinarySearchTree::const_iterator last) {
    node_type* erased_node;
    for (; first != last; ++first) {
        erased_node = first.get_node();
        erase(root_, erased_node);
    }
    return last;
}

template<class Key, class Traversal, class Compare, class Allocator>
BinarySearchTree<Key, Traversal, Compare, Allocator>::size_type BinarySearchTree<Key, Traversal, Compare, Allocator>::erase(const Key& key) {
    node_type* erased_node = find_node(key);
    size_type counter = 0;
    while (erased_node != nullptr) {
        erase(root_, erased_node);
        ++counter;
        erased_node = find_node(key);
    }
    return counter;
}

template<class Key, class Traversal, class Compare, class Allocator>
void BinarySearchTree<Key, Traversal, Compare, Allocator>::swap(BinarySearchTree<Key, Traversal, Compare, Allocator>& other) noexcept {
    node_type* temp_root = this->root_;
    this->root_ = other.root_;
    other.root_ = temp_root;
    size_type temp_size = this->size_;
    this->size_ = other.size_;
    other.size_ = temp_size;
}

template<class Key, class Traversal, class Compare, class Allocator>
BinarySearchTree<Key, Traversal, Compare, Allocator>::node_type BinarySearchTree<Key, Traversal, Compare, Allocator>::extract(BinarySearchTree::const_iterator position) {
    node_type* erased_node = position.get_node();
    erase(root_, erased_node);
    return *erased_node;
}

template<class Key, class Traversal, class Compare, class Allocator>
BinarySearchTree<Key, Traversal, Compare, Allocator>::node_type BinarySearchTree<Key, Traversal, Compare, Allocator>::extract(const Key& k) {
    node_type* erased_node = find_node(k);
    erase(root_, erased_node);
    return *erased_node;
}

template<class Key, class Traversal, class Compare, class Allocator>
template<class C2>
void BinarySearchTree<Key, Traversal, Compare, Allocator>::merge(BinarySearchTree<Key, C2, Allocator>& source) {
    insert(source.begin(), source.end());
}


// Implementation of lookup

template<class Key, class Traversal, class Compare, class Allocator>
BinarySearchTree<Key, Traversal, Compare, Allocator>::size_type BinarySearchTree<Key, Traversal, Compare, Allocator>::count(const Key& key) const {
    if (root_ == nullptr) {
        return 0;
    }

    size_type count = 0;
    node_type* current_node = root_;
    while (current_node != nullptr) {
        if (!Compare()(current_node->data_, key) && !Compare()(key, current_node->data_)) {
            ++count;
        }
        if (Compare(current_node->data_, key)) {
            current_node = current_node->right_;
        } else {
            current_node = current_node->left_;
        }
    }

    return count;
}

template<class Key, class Traversal, class Compare, class Allocator>
BinarySearchTree<Key, Traversal, Compare, Allocator>::const_iterator BinarySearchTree<Key, Traversal, Compare, Allocator>::find(const Key& key) const {
    return const_iterator(find_node(key));
}

template<class Key, class Traversal, class Compare, class Allocator>
bool BinarySearchTree<Key, Traversal, Compare, Allocator>::contains(const Key& key) const {
    return find_node(key) != nullptr;
}

template<class Key, class Traversal, class Compare, class Allocator>
BinarySearchTree<Key, Traversal, Compare, Allocator>::const_iterator BinarySearchTree<Key, Traversal, Compare, Allocator>::lower_bound(const Key& key) const {
    if (root_ == nullptr) {
        return this->cend();
    }
    node_type* current_node = root_;
    while (current_node->left_ != nullptr && !Compare()(current_node->data_, key)) {
        current_node = current_node->left_;
    }
    while (next_node<Key>(current_node) != nullptr && Compare()(current_node->data_, key)) {
        current_node = next_node<Key>(current_node);
    }
    if (next_node<Key>(current_node) == nullptr && Compare()(current_node->data_, key)) {
        return this->cend();
    }
    return const_iterator(current_node);
}

template<class Key, class Traversal, class Compare, class Allocator>
BinarySearchTree<Key, Traversal, Compare, Allocator>::const_iterator BinarySearchTree<Key, Traversal, Compare, Allocator>::upper_bound(const Key& key) const {
    if (root_ == nullptr) {
        return this->cend();
    }
    node_type* current_node = root_;
    while (current_node->left_ != nullptr && Compare()(key, current_node->data_)) {
        current_node = current_node->left_;
    }
    while (next_node<Key>(current_node) != nullptr && !Compare()(key, current_node->data_)) {
        current_node = next_node<Key>(current_node);
    }
    if (next_node<Key>(current_node) == nullptr && !Compare()(key, current_node->data_)) {
        return this->cend();
    }
    return const_iterator(current_node);
}

// Implementation of observes

template<class Key, class Traversal, class Compare, class Allocator>
BinarySearchTree<Key, Traversal, Compare, Allocator>::key_compare BinarySearchTree<Key, Traversal, Compare, Allocator>::key_comp() const {
    return key_compare();
}

template<class Key, class Traversal, class Compare, class Allocator>
BinarySearchTree<Key, Traversal, Compare, Allocator>::value_compare BinarySearchTree<Key, Traversal, Compare, Allocator>::value_comp() const {
    return value_compare();
}


// Implementation of private functions

template<class Key, class Traversal, class Compare, class Allocator>
BinarySearchTree<Key, Traversal, Compare, Allocator>::node_type* BinarySearchTree<Key, Traversal, Compare, Allocator>::find_node(const Key& key) const {
    if (root_ == nullptr) {
        return nullptr;
    }

    node_type* current_node = root_;
    while (current_node != nullptr && current_node->data_ != key) {
        if (Compare()(current_node->data_,key)) {
            current_node = current_node->right_;
        } else {
            current_node = current_node->left_;
        }
    }

    return current_node;
}

template<class Key, class Traversal, class Compare, class Allocator>
void BinarySearchTree<Key, Traversal, Compare, Allocator>::erase(node_type*& root, node_type*& erased_node) {
    if (erased_node == nullptr || root == nullptr) {
        return;
    }

    if (erased_node->left_ == nullptr && erased_node->right_ == nullptr) {
        if (erased_node == root) {
            root = nullptr;
            --size_;
            return;
        }
        node_type* parent = erased_node->parent_;
        if (parent->left_ == erased_node) {
            parent->left_ = nullptr;
        } else {
            parent->right_ = nullptr;
        }
        --size_;
        return;
    }

    if (erased_node->left_ != nullptr && erased_node->right_ != nullptr) {
        node_type* successor = minimum<Key>(erased_node->right_);
        swap(successor, erased_node);
        erase(root, erased_node);
        return;
    }

    node_type* erased_node_child;
    if (erased_node->left_ != nullptr) {
        erased_node_child = erased_node->left_;
    } else if (erased_node->right_ != nullptr) {
        erased_node_child = erased_node->right_;
    }

    if (erased_node == root) {
        erased_node_child->parent_ = nullptr;
        root = erased_node_child;
        --size_;
        return;
    }

    node_type* parent = erased_node->parent_;
    erased_node_child->parent_ = parent;
    if (erased_node == parent->left_) {
        parent->left_ = erased_node_child;
    } else {
        parent->right_ = erased_node_child;
    }
    --size_;
}

template<class Key, class Traversal, class Compare, class Allocator>
void BinarySearchTree<Key, Traversal, Compare, Allocator>::swap(BinarySearchTree::node_type *node_1, BinarySearchTree::node_type *node_2) {
    node_type* left_node_1 = node_1->left_;
    node_type* right_node_1 = node_1->right_;
    node_type* parent_node_1 = node_1->parent_;

    node_type* left_node_2 = node_2->left_;
    node_type* right_node_2 = node_2->right_;
    node_type* parent_node_2 = node_2->parent_;

    if (parent_node_1 == node_2) {
        if (parent_node_2 == nullptr) {
            root_ = node_1;
        } else {
            if (parent_node_2->left_ == node_2) {
                parent_node_2->left_ = node_1;
            } else {
                parent_node_2->right_ = node_1;
            }
        }
        if (left_node_1 != nullptr) {
            left_node_1->parent_ = node_2;
        }
        if (right_node_1 != nullptr) {
            right_node_1->parent_ = node_2;
        }
        node_2->parent_ = node_1;
        node_2->left_ = left_node_1;
        node_2->right_ = right_node_1;
        node_1->parent_ = parent_node_2;
        if (left_node_2 == node_1) {
            if (right_node_2 != nullptr) {
                right_node_2->parent_ = node_1;
            }
            node_1->left_ = node_2;
            node_1->right_ = right_node_2;
            return;
        }
        if (left_node_2 != nullptr) {
            left_node_2->parent_ = node_1;
        }
        node_1->left_ = left_node_2;
        node_1->right_ = node_2;
        return;
    }
    if (parent_node_2 == node_1) {
        if (parent_node_1 == nullptr) {
            root_ = node_2;
        } else {
            if (parent_node_1->left_ == node_1) {
                parent_node_1->left_ = node_2;
            } else {
                parent_node_1->right_ = node_2;
            }
        }
        if (left_node_2 != nullptr) {
            left_node_2->parent_ = node_1;
        }
        if (right_node_2 != nullptr) {
            right_node_2->parent_ = node_1;
        }
        node_1->parent_ = node_2;
        node_1->left_ = left_node_2;
        node_1->right_ = right_node_2;
        node_2->parent_ = parent_node_1;
        if (left_node_1 == node_2) {
            if (right_node_1 != nullptr) {
                right_node_1->parent_ = node_2;
            }
            node_2->left_ = node_1;
            node_2->right_ = right_node_1;
            return;
        }
        if (left_node_1 != nullptr) {
            left_node_1->parent_ = node_2;
        }
        node_2->left_ = left_node_1;
        node_2->right_ = node_1;
        return;
    }

    if (parent_node_1 == nullptr) {
        root_ = node_2;
    } else {
        if (parent_node_1->left_ == node_1) {
            parent_node_1->left_ = node_2;
        } else {
            parent_node_1->right_ = node_2;
        }
    }
    if (left_node_1 != nullptr) {
        left_node_1->parent_ = node_2;
    }
    if (right_node_1 != nullptr) {
        right_node_1->parent_ = node_2;
    }
    node_2->parent_ = parent_node_1;
    node_2->left_ = left_node_1;
    node_2->right_ = right_node_1;

    if (parent_node_2 == nullptr) {
        root_ = node_1;
    } else {
        if (parent_node_2->left_ == node_2) {
            parent_node_2->left_ = node_1;
        } else {
            parent_node_2->right_ = node_1;
        }
    }
    if (left_node_2 != nullptr) {
        left_node_2->parent_ = node_1;
    }
    if (right_node_2 != nullptr) {
        right_node_2->parent_ = node_1;
    }
    node_1->parent_ = parent_node_2;
    node_1->left_ = left_node_2;
    node_1->right_ = right_node_2;
}

template<class Key>
BinarySearchTree<Key>::node_type* minimum(typename BinarySearchTree<Key>::node_type* subtree_root) {
    if (subtree_root == nullptr) {
        return nullptr;
    }
    if (subtree_root->left_ == nullptr) {
        return subtree_root;
    }
    return minimum<Key>(subtree_root->left_);
}

template<class Key>
BinarySearchTree<Key>::node_type* maximum(typename BinarySearchTree<Key>::node_type* subtree_root) {
    if (subtree_root == nullptr) {
        return nullptr;
    }
    if (subtree_root->right_ == nullptr) {
        return subtree_root;
    }
    return maximum<Key>(subtree_root->right_);
}

template<class Key>
BinarySearchTree<Key>::node_type* next_node(typename BinarySearchTree<Key>::node_type* node) {
    if (node == nullptr) {
        return nullptr;
    }
    if (node->right_ != nullptr) {
        return minimum<Key>(node->right_);
    }
    typename BinarySearchTree<Key>::node_type* parent = node->parent_;
    while (parent != nullptr && node == parent->right_) {
        node = parent;
        parent = node->parent_;
    }
    return parent;
}

template<class Key>
BinarySearchTree<Key>::node_type* prev_node(typename BinarySearchTree<Key>::node_type* node) {
    if (node == nullptr) {
        return nullptr;
    }
    if (node->left_ != nullptr) {
        return maximum<Key>(node->left_);
    }
    typename BinarySearchTree<Key>::node_type* parent = node->parent_;
    while (parent != nullptr && node == parent->left_) {
        node = parent;
        parent = parent->parent_;
    }
    return parent;
}

template<class Key, class Traversal, class Compare, class Allocator>
void BinarySearchTree<Key, Traversal, Compare, Allocator>::delete_children(node_type* node) {
    if (node->left_ != nullptr) {
        delete_children(node->left_);
    }
    if (node->right_ != nullptr) {
        delete_children(node->right_);
    }

    delete node;
}