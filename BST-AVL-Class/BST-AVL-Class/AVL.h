#ifndef AVL_H_
#define AVL_H_
#include "AVL_Functions.h"
#include <cstdlib>

template <typename T>
class avl {
public:
    avl() {
        root = NULL;
    }
    avl(const T* sorted_list, int size = -1) {
        root = tree_from_sorted_list(sorted_list, size);
    }

    //. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

    avl(const avl<T>& copy_me) {
        root = tree_copy(copy_me.root);
    }
    avl<T>& operator =(const avl<T>& rhs) {
        rhs.root = tree_copy(root);
    }
    ~avl() {
        tree_clear(root);
    }

    //. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

    void insert(const T& insert_me) {
        tree_insert(root, insert_me);
    }
    bool erase(const T& target) {
        return tree_erase(root, target);
    }
    bool search(const T& target, tree_node<T>*& found_ptr) {
        return tree_search(root, target, found_ptr);
    }
    void printDebug() {
        tree_print_debug(root);
    }
    void clear() {
        tree_clear(root);
    }

    friend ostream& operator <<(ostream& outs, const avl<T>& tree) {
        tree_print(tree.root);
        return outs;
    }
    avl<T>& operator +=(const avl<T>& rhs) {
        tree_add(root, rhs.root);
        return rhs;
    }
private:
    tree_node<T>* root;
};

#endif // !AVL_H_

