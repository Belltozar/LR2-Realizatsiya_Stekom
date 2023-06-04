#include "stack.h"
#include <iostream>

// Конструктор
Stack::Stack() {
    capacity = 1;
    top = -1;
    data = new int[capacity];
}

// Конструктор копіювання
Stack::Stack(const Stack& other) {
    capacity = other.capacity;
    top = other.top;
    data = new int[capacity];
    for (int i = 0; i <= top; i++) {
        data[i] = other.data[i];
    }
}

// Оператор присваювання
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

// Деструктор
Stack::~Stack() {
    delete[] data;
}

// Додавання елемента в вершину стека
void Stack::push(int elem) {
    // Збільшуємо ємність стека, якщо він заповнений
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
    // Додаємо елемент в вершину стека
    data[++top] = elem;
}

// Видалення елемента з вершини стека і повернення його значення
int Stack::pop() {
    if (isEmpty()) {
        std::cout << "Стек порожній." << std::endl;
        return -1; // Повертаємо значення за замовчуванням, наприклад, -1
    }
    return data[top--];
}

// Перевірка, чи порожній стек
bool Stack::isEmpty() {
    return (top == -1);
}

// Виштовхнути N елементів
void Stack::multiPop(int N) {
    if (N >= capacity) {
        // Видаляємо всі елементи
        delete[] data;
        capacity = 1;
        top = -1;
        data = new int[capacity];
    } else if (N > top + 1) {
        // Видаляємо всі елементи, окрім останнього
        top = 0;
    } else {
        // Видаляємо N елементів
        top -= N;
    }
}

// Показ всіх елементів стека
void Stack::show() {
    if (isEmpty()) {
        std::cout << "Стек порожній." << std::endl;
        return;
    }
    for (int i = 0; i <= top-1; i++) {
        std::cout << data[i] << " " ;
    }
        std::cout << data[top];
    std::cout << std::endl;

}
