#pragma once

//linked list

template <typename datatype>

struct linkList {
private: 
    int partition(int low = 0, int high = 0); // partition list for quicksort
public:
    struct node {// node general structure
    public:
        datatype data;      // where the data is stored
        node* next = nullptr;// point to the next node
        node* previous = nullptr;// point to the previous node
    };

    node* last = nullptr;// points to the last node
    node* first = nullptr;// points to the first node
    // CRUD
    void addTofirst(datatype data);// create some node at first
    void addToEnd(datatype data);// create some node at first

    node* get(int index) {// read a node
        if (first != nullptr) {
            if (index == 0) return first;
            else {
                node* current = first;
                while (current != nullptr && index > 0) {
                    index -= 1;
                    current = current->next;
                }
                return current;
            };
        }
        else return nullptr;
    };
    
    int getSize();// get the size of the list

    void updNode(int index, datatype data);// update a node
    void swap(int from, int  to);// swap two nodes 
    void quickSort(int low = 0, int high = 0); // sort data (needs overload operators)
    void delNode(int index);// delete a node
    void purgeAll(); // delete all nodes

    void reverse();// reverse the order of the list

    node* operator[](int index) { // just for [] sintax
        return get(index);
    };
};

    template <typename datatype>
    void linkList<datatype>::addTofirst (datatype data) {
        node* z = new (node);
        z->data = data;
        if (first != nullptr) {
            first->next = z;
            z -> next = first;
        }
        else {
            z -> previous = NULL;
            last = z;
        }
        first = z;
    };

    template <typename datatype>
    void linkList<datatype>::addToEnd(datatype data) {
        node* z = new (node);
        if (first != nullptr) {
            last->next = z;
            z->previous = last;
        }
        else {
            z->previous = nullptr;
            first = z;
        }
        last = z;
        z->data = data;
    };

    template <typename datatype>
    void linkList<datatype>::updNode(int index, datatype data) {
        node* find = get(index);
        if (find != nullptr) {
            find->data = data;
            //cout << "\n Update Succesfull \n";
        }
    };

    template <typename datatype>
    void linkList<datatype>::swap(int from, int to) {
        node* node1 = get(from);
        node* node2 = get(to);
        datatype temp = node1->data;
        node1->data = node2->data;
        node2->data = temp;
    };

    template <typename datatype>
    int linkList<datatype>::partition(int low, int high) {
        datatype pivot = get(high)->data;
        int i = (low - 1);
        for (int j = low; j <= high - 1; j++) {
            if (get(j)->data < pivot) {
                i++;
                swap(i, j);
            }
        }
        swap(i + 1, high);
        return (i + 1);
    };

    template <typename datatype>
    void linkList<datatype>::quickSort(int low, int high) {
        if (low < high) {
            int pivot = partition(low, high);
            quickSort(low, pivot - 1);
            quickSort(pivot + 1, high);
        }
    };

    template <typename datatype>
    void linkList<datatype>::reverse() { // reverse the two way link list
        node* current = first;
        node* next= nullptr;
        node* prev = nullptr;
        last = first;
        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        first = prev;
    };

    template <typename datatype>
    void linkList<datatype>::delNode(int index) {
        node* find = get(index);
        if (find != nullptr) {
            if (find == first) first = find->next;
            if (find == last) last = find->previous;
            if (find->next != nullptr) find->next->previous = find->previous;
            if(find->previous != nullptr) find->previous->next = find->next;
            delete find;
            //cout << "\n Delete Succesfull \n";
        }
    };

    template <typename datatype>
    int linkList<datatype>::getSize() {
        int size = 0;
        node* current = first;
        while (current != nullptr) {
            size += 1;
            current = current->next;
        }
        return size;
    };

    template <typename datatype>
    void linkList<datatype>::purgeAll() {
        node* current = first;
        node* temp;
        while (current != nullptr) {
            temp = current->next;
            delete current;
            current = temp;
        }
        first = nullptr;
        last = nullptr;
        //cout << "\n Purge Succesfull \n";
    };

//end of linked list