#include <iostream>
using namespace std;

class SparseMatrix {
private:
    int rows, cols;
    int** matrix;

public:
    SparseMatrix(int m, int n) {
        rows = m;
        cols = n;
        matrix = new int*[m];
        for (int i = 0; i < m; i++) {
            matrix[i] = new int[n];
            for (int j = 0; j < n; j++) {
                matrix[i][j] = 0;
            }
        }
    }

    // Set a non-zero value at a specific position
    void setValue(int row, int col, int value) {
        if (row < 0 || row >= rows || col < 0 || col >= cols) {
            cout << "Invalid row or column index" << endl;
            return;
        }
        matrix[row][col] = value;
    }

    // Get the value at a specific position
    int getValue(int row, int col) {
        if (row < 0 || row >= rows || col < 0 || col >= cols) {
            cout << "Invalid row or column index" << endl;
            return 0;
        }
        return matrix[row][col];
    }

    // Display the sparse matrix
    void display() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    ~SparseMatrix() {
        for (int i = 0; i < rows; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;
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
