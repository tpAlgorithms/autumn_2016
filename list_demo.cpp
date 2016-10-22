#include <iostream>

struct node_t {
    int data;
    node_t *next;

    node_t(): data(0), next(nullptr) {}
};

void print_list(const node_t *node) {
    for(const node_t* curr=node; curr != nullptr; curr = curr->next) {
        std::cout << curr->data << std::endl;
        if (curr->next == node) break;
    }
}

// first == nullptr
//
node_t* insert_list(node_t *last, int value) {
    node_t *new_node = new node_t();
    new_node->data = value;
    if (!last) {
        new_node->next = new_node;
    } else {
        new_node->next = last->next;
        last->next = new_node;
    }
    return new_node;
}

node_t* remove_next_list(node_t *node) {
    if (node == node->next) {
        delete node;
        return nullptr;
    }
    node_t *tmp = node->next;
    node->next = node->next->next;
    delete tmp;
    return node;
}

int main() {
    node_t *list = nullptr;

    int size;
    std::cin >> size;
    for (int i = 0; i < size; ++i) {
       list = insert_list(list, i); 
    }

    std::cout << "list: " << list->data << std::endl;
    for (node_t *curr = list; curr != nullptr;) {
        if (curr->next->data % 2) {
            if (list == curr->next) {
                list = curr;
            }
            std::cout << "remove: " << curr->next->data << std::endl;
            remove_next_list(curr);
        } else {
            std::cout << "skip: " << curr->next->data << std::endl;
            curr=curr->next;
        }
        if (curr == list) {
            break;
        }
    }
    print_list(list->next);

    delete list;
    
    return 0;
}
