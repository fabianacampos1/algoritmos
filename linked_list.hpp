#ifndef __LINKED_LIST_IFRN__
#define __LINKED_LIST_IFRN__
#include <iostream>

class linked_list {
private:
    struct Node {
        int data;
        Node* prev;
        Node* next;
        Node(int val) : data(val), prev(nullptr), next(nullptr) {} // Construtor para criar um novo nó com os dados especificados
    };

public:
    Node* head;
    Node* tail;
    int size;
    linked_list() : head(nullptr), tail(nullptr), size(0) {} //Construtor para criar uma ll vazia

    bool insert_at(int index, int data) { // inserir um elemento em um índice especificado na lista
        if (index < 0 || index > size) {
            return false;
        }

        Node* newNode = new Node(data);
        if (size == 0) { // Inserindo em uma lista vazia
            head = newNode;
            tail = newNode;
        } else if (index == 0) { // Inserindo no início
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        } else if (index == size) { // Inserindo no fim
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        } else {    // Inserindo no meio da lista
            Node* curr = head;
            for (int i = 0; i < index; i++) {
                curr = curr->next;
            }
            newNode->prev = curr->prev;
            newNode->next = curr;
            curr->prev->next = newNode;
            curr->prev = newNode;
        }
        size++;
        return true;
    }

    bool remove_at(int index) { //remover um elemento em um índice especificado na lista
        if (index < 0 || index >= size) {
            return false;
        }

        Node* curr = head;
        if (index == 0) {
            head = head->next;
            if (head) {
                head->prev = nullptr;
            } else {
                tail = nullptr;
            }
        } else if (index == size - 1) {
            curr = tail;
            tail = tail->prev;
            if (tail) {
                tail->next = nullptr;
            } else {
                head = nullptr;
            }
        } else {
            for (int i = 0; i < index; i++) {
                curr = curr->next;
            }
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
        }
        delete curr;
        size--;
        return true;
    }

    int find(int data) { // Retorna o índice de value, -1 se inválido
        Node* curr = head;
        int index = 0;
        
        while (curr) {
            if (curr->data == data) {
                return index;
            }
            curr = curr->next;
            index++;
        }
        return -1;
    }

    int Size() {
        return size;
    }

    void clear() { // Remove todos os elementos, deixando o vetor no estado inicial
        Node* curr = head;
        while (curr) {
            Node* temp = curr;
            curr = curr->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    bool empty() {
        return size == 0;
    }

    std::string ToString() {
        std::string result = "[";
        Node* curr = head;
        while (curr) {
            result += std::to_string(curr->data);
            curr = curr->next;
            if (curr) {
                result += ", ";
            }
        }
        result += "]";
        return result;
    }

    int capacity() {
        return -1;
    }

    double percent_occupied() {
        return -1.0;
    }

    int get_at(int index) { // Retorna elemento no índice index
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range.");
        }

        Node* curr = head;
        for (int i = 0; i < index; i++) {
            curr = curr->next;
        }
        return curr->data;
    }

    void push_back(int data) { // Adiciona um elemento no ``final'' do vetor
        insert_at(size, data);
    }

    void push_front(int data) { // Adiciona um elemento no ``início'' do vetor
        insert_at(0, data);
    }

    void pop_back() { // Remove um elemento do ``final'' do vetor
        remove_at(size - 1);
    }

    void pop_front() { // Remove um elemento do ``início'' do vetor
        remove_at(0);
    }

    int back() { // Retorna o elemento do ``final'' do vetor
        if (empty()) {
            throw std::runtime_error("List is empty.");
        }
        return tail->data;
    }

    int front() { // Retorna o elemento do ``início'' do vetor
        if (empty()) {
            throw std::runtime_error("List is empty.");
        }
        return head->data;
    }

    bool remove(int data) { // remove o valor caso esteja presente
        int index = find(data);
        if (index != -1) {
            remove_at(index);
            return true;
        }
        return false;
    }

    int count(int data) {  // Retorna quantas vezes value occorre no vetor
        int count = 0;
        Node* curr = head;
        while (curr) {
            if (curr->data == data) {
                count++;
            }
            curr = curr->next;
        }
        return count;
    }

    int sum() {  // Retorna a soma dos elementos do vetor
        int total = 0;
        Node* curr = head;
        while (curr) {
            total += curr->data;
            curr = curr->next;
        }
        return total;
    }
};

#endif // __LINKED_LIST_IFRN__