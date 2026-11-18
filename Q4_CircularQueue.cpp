#include <iostream>
using namespace std;

const int MAX = 5;
int cq[MAX];
int frontIdx = -1;
int rearIdx = -1;

bool isEmpty() {
    return frontIdx == -1;
}

bool isFull() {
    return (rearIdx + 1) % MAX == frontIdx;
}

// Menambahkan elemen dengan perputaran indeks modulo 5
void enqueue(int val) {
    if (isFull()) {
        cout << "Circular Queue Overflow! Cannot insert " << val << "." << endl;
        return;
    }
    if (isEmpty()) {
        frontIdx = 0;
        rearIdx = 0;
    } else {
        rearIdx = (rearIdx + 1) % MAX;
    }
    cq[rearIdx] = val;
    cout << "Enqueued: " << val << " (at index " << rearIdx << ")" << endl;
}

// Menghapus elemen dari posisi front tanpa menggeser elemen lain
void dequeue() {
    if (isEmpty()) {
        cout << "Circular Queue Underflow! Queue is empty." << endl;
        return;
    }
    int removed = cq[frontIdx];
    if (frontIdx == rearIdx) {
        // Hanya tersisa satu elemen, reset ke kondisi kosong
        frontIdx = -1;
        rearIdx = -1;
    } else {
        frontIdx = (frontIdx + 1) % MAX;
    }
    cout << "Dequeued: " << removed << endl;
}

// Menampilkan elemen dari frontIdx hingga rearIdx mengikuti alur melingkar
void display() {
    if (isEmpty()) {
        cout << "Queue is empty." << endl;
        return;
    }
    cout << "Queue: ";
    int i = frontIdx;
    while (true) {
        cout << cq[i] << " ";
        if (i == rearIdx) {
            break;
        }
        i = (i + 1) % MAX;
    }
    cout << endl;
}

int main() {
    cout << "=== 10-STEP CIRCULAR QUEUE TEST ===" << endl;

    // Langkah 1-5: Enqueue 10, 20, 30, 40, 50
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    // Langkah 6-7: Dequeue dua kali (menghapus 10 dan 20)
    dequeue();
    dequeue();

    // Langkah 8-9: Enqueue 60, 70 (indeks rear berputar ke 0 dan 1)
    enqueue(60);
    enqueue(70);

    // Langkah 10: Tampilkan isi queue
    display();

    return 0;
}