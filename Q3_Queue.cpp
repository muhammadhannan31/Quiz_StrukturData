#include <iostream>
using namespace std;

const int MAX = 5;
int queueArr[MAX];
int frontIdx = -1;
int rearIdx = -1;

// Menambahkan elemen ke bagian belakang queue
void enqueue(int val) {
    if (rearIdx == MAX - 1) {
        cout << "Queue Overflow! Cannot insert " << val << "." << endl;
        return;
    }
    if (frontIdx == -1) {
        frontIdx = 0;
    }
    queueArr[++rearIdx] = val;
    cout << val << " inserted successfully." << endl;
}

// Menghapus elemen dari bagian depan queue
void dequeue() {
    if (frontIdx == -1 || frontIdx > rearIdx) {
        cout << "Queue Underflow! Queue is empty." << endl;
        return;
    }
    cout << queueArr[frontIdx++] << " removed successfully." << endl;

    // Reset indeks jika seluruh elemen sudah dikeluarkan
    if (frontIdx > rearIdx) {
        frontIdx = -1;
        rearIdx = -1;
    }
}

// Melihat elemen paling depan tanpa menghapusnya
void front() {
    if (frontIdx == -1 || frontIdx > rearIdx) {
        cout << "Queue is empty." << endl;
        return;
    }
    cout << "Front element: " << queueArr[frontIdx] << endl;
}

// Menampilkan seluruh isi queue dari front ke rear
void display() {
    if (frontIdx == -1 || frontIdx > rearIdx) {
        cout << "Queue is empty." << endl;
        return;
    }
    cout << "Queue: ";
    for (int i = frontIdx; i <= rearIdx; i++) {
        cout << queueArr[i] << " ";
    }
    cout << endl;
}

int main() {
    int choice, value;

    do {
        cout << "\n===== QUEUE MENU =====" << endl;
        cout << "1. Enqueue 2. Dequeue" << endl;
        cout << "3. Front 4. Display 5. Exit" << endl;
        cout << "Choose operation: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                front();
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