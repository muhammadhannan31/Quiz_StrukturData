#include <iostream>
using namespace std;

const int MAX = 5;
int stackArr[MAX];
int top = -1;

// Menambahkan elemen ke posisi paling atas stack
void push(int val) {
    if (top == MAX - 1) {
        cout << "Stack Overflow! Cannot insert " << val << "." << endl;
        return;
    }
    stackArr[++top] = val;
    cout << val << " inserted successfully." << endl;
}

// Menghapus elemen paling atas dari stack
void pop() {
    if (top == -1) {
        cout << "Stack Underflow! Stack is empty." << endl;
        return;
    }
    cout << stackArr[top--] << " removed successfully." << endl;
}

// Melihat elemen paling atas tanpa menghapusnya
void peek() {
    if (top == -1) {
        cout << "Stack is empty." << endl;
        return;
    }
    cout << "Top element: " << stackArr[top] << endl;
}

// Menampilkan seluruh isi stack dari atas ke bawah
void display() {
    if (top == -1) {
        cout << "Stack is empty." << endl;
        return;
    }
    cout << "Stack (top to bottom): ";
    for (int i = top; i >= 0; i--) {
        cout << stackArr[i] << " ";
    }
    cout << endl;
}

int main() {
    int choice, value;

    do {
        cout << "\n===== STACK MENU =====" << endl;
        cout << "1. Push 2. Pop 3. Peek" << endl;
        cout << "4. Display 5. Exit" << endl;
        cout << "Choose operation: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice. Please select 1-5." << endl;
        }
    } while (choice != 5);

    return 0;
}