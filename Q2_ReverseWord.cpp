#include <iostream>
using namespace std;

const int MAX = 100;
char charStack[MAX];
int top = -1;

// Memasukkan satu karakter ke dalam stack
void pushChar(char c) {
    if (top == MAX - 1) {
        cout << "Stack Overflow!" << endl;
        return;
    }
    charStack[++top] = c;
}

// Mengeluarkan satu karakter dari posisi paling atas stack
char popChar() {
    if (top == -1) {
        return '\0';
    }
    return charStack[top--];
}

int main() {
    char word[MAX];
    char reversed[MAX];

    cout << "Enter a word: ";
    cin >> word;

    // 1. Push setiap karakter dari kiri ke kanan
    for (int i = 0; word[i] != '\0'; i++) {
        pushChar(word[i]);
    }

    // 2. Pop seluruh karakter untuk membalikkan urutan
    int idx = 0;
    while (top != -1) {
        reversed[idx++] = popChar();
    }
    reversed[idx] = '\0';

    cout << "Original word: " << word << endl;
    cout << "Reversed word: " << reversed << endl;

    return 0;
}