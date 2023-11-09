#include <iostream>

struct Node {
    int row;
    int col;
    int value;
    Node* next;
};

class LinkedListSparseMatrix {
private:
    Node* head;
    int rows;
    int cols;

public:
    LinkedListSparseMatrix(int rows, int cols) {
        this->rows = rows;
        this->cols = cols;
        head = nullptr;
    }

    void addElement(int row, int col, int value) {
        Node* newNode = new Node();
        newNode->row = row;
        newNode->col = col;
        newNode->value = value;
        newNode->next = head;
        head = newNode;
    }

    int getElement(int row, int col) {
        Node* currentNode = head;
        while (currentNode != nullptr) {
            if (currentNode->row == row && currentNode->col == col) {
                return currentNode->value;
            }
            currentNode = currentNode->next;
        }
        return 0;
    }

    void printSparseMatrix() {
        Node* currentNode = head;
        while (currentNode != nullptr) {
            std::cout << currentNode->row << " " << currentNode->col << " " << currentNode->value << std::endl;
            currentNode = currentNode->next;
        }
    }
};

int main() {
    LinkedListSparseMatrix sparseMatrix(4, 5);

    sparseMatrix.addElement(0, 2, 3);
    sparseMatrix.addElement(0, 4, 4);
    sparseMatrix.addElement(1, 2, 5);
    sparseMatrix.addElement(1, 3, 7);
    sparseMatrix.addElement(3, 1, 2);
    sparseMatrix.addElement(3, 2, 6);

    sparseMatrix.printSparseMatrix();

    return 0;
}
