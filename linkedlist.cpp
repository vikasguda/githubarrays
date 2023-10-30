#include <iostream>
using namespace std;

class Node {
public:
    int row;
    int col;
    int value;
    Node* next;

    Node(int r, int c, int val) {
        row = r;
        col = c;
        value = val;
        next = nullptr;
    }
};

class SparseMatrix {
private:
    int rows, cols;
    Node* head;

public:
    SparseMatrix(int m, int n) {
        rows = m;
        cols = n;
        head = nullptr;
    }

    // Set a non-zero value at a specific position
    void setValue(int row, int col, int value) {
        if (row < 0 || row >= rows || col < 0 || col >= cols) {
            cout << "Invalid row or column index" << endl;
            return;
        }
        if (value == 0) {
            // Don't store zero values in the linked list
            return;
        }
        Node* newNode = new Node(row, col, value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Get the value at a specific position
    int getValue(int row, int col) {
        if (row < 0 || row >= rows || col < 0 || col >= cols) {
            cout << "Invalid row or column index" << endl;
            return 0;
        }
        Node* current = head;
        while (current != nullptr) {
            if (current->row == row && current->col == col) {
                return current->value;
            }
            current = current->next;
        }
        return 0; // Return 0 for zero values or if the element is not found
    }

    // Display the sparse matrix
    void display() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << getValue(i, j) << " ";
            }
            cout << endl;
        }
    }

    ~SparseMatrix() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
};

int main() {
    int m, n;
    cout << "Enter the number of rows: ";
    cin >> m;
    cout << "Enter the number of columns: ";
    cin >> n;

    SparseMatrix sparse(m, n);

    cout << "Enter non-zero values (row, column, value):" << endl;
    int row, col, value;
    for (int i = 0; i < m; i++) {
        cin >> row >> col >> value;
        sparse.setValue(row, col, value);
    }

    cout << "Sparse Matrix:" << endl;
    sparse.display();

    return 0;
}
