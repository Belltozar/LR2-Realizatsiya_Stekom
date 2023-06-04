#ifndef STACK_H
#define STACK_H

class Stack {
private:
    int* data;    // Динамічний масив для зберігання елементів стека
    int capacity; // Поточна ємність стека
    int top;      // Індекс вершини стека

public:
    // Конструктор
    Stack();

    // Конструктор копіювання
    Stack(const Stack& other);

    // Оператор присваювання
    Stack& operator=(const Stack& other);

    // Деструктор
    ~Stack();

    // Додавання елемента в вершину стека
    void push(int elem);

    // Видалення елемента з вершини стека і повернення його значення
    int pop();

    // Перевірка, чи порожній стек
    bool isEmpty();

    // Виштовхнути N елементів
    void multiPop(int N);

    // Показ всіх елементів стека
    void show();
};

#endif // STACK_H
