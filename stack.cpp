#include "stack.h"
#include <iostream>

// �����������
Stack::Stack() {
    capacity = 1;
    top = -1;
    data = new int[capacity];
}

// ����������� ���������
Stack::Stack(const Stack& other) {
    capacity = other.capacity;
    top = other.top;
    data = new int[capacity];
    for (int i = 0; i <= top; i++) {
        data[i] = other.data[i];
    }
}

// �������� ������������
Stack& Stack::operator=(const Stack& other) {
    if (this == &other) {
        return *this;
    }
    delete[] data;
    capacity = other.capacity;
    top = other.top;
    data = new int[capacity];
    for (int i = 0; i <= top; i++) {
        data[i] = other.data[i];
    }
    return *this;
}

// ����������
Stack::~Stack() {
    delete[] data;
}

// ��������� �������� � ������� �����
void Stack::push(int elem) {
    // �������� ������ �����, ���� �� ����������
    if (top == capacity - 1) {
        int newCapacity = capacity * 2;
        int* newData = new int[newCapacity];
        for (int i = 0; i < capacity; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }
    // ������ ������� � ������� �����
    data[++top] = elem;
}

// ��������� �������� � ������� ����� � ���������� ���� ��������
int Stack::pop() {
    if (isEmpty()) {
        std::cout << "���� �������." << std::endl;
        return -1; // ��������� �������� �� �������������, ���������, -1
    }
    return data[top--];
}

// ��������, �� ������� ����
bool Stack::isEmpty() {
    return (top == -1);
}

// ����������� N ��������
void Stack::multiPop(int N) {
    if (N >= capacity) {
        // ��������� �� ��������
        delete[] data;
        capacity = 1;
        top = -1;
        data = new int[capacity];
    } else if (N > top + 1) {
        // ��������� �� ��������, ���� ����������
        top = 0;
    } else {
        // ��������� N ��������
        top -= N;
    }
}

// ����� ��� �������� �����
void Stack::show() {
    if (isEmpty()) {
        std::cout << "���� �������." << std::endl;
        return;
    }
    for (int i = 0; i <= top-1; i++) {
        std::cout << data[i] << " " ;
    }
        std::cout << data[top];
    std::cout << std::endl;

}
