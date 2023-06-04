#ifndef STACK_H
#define STACK_H

class Stack {
private:
    int* data;    // ��������� ����� ��� ��������� �������� �����
    int capacity; // ������� ������ �����
    int top;      // ������ ������� �����

public:
    // �����������
    Stack();

    // ����������� ���������
    Stack(const Stack& other);

    // �������� ������������
    Stack& operator=(const Stack& other);

    // ����������
    ~Stack();

    // ��������� �������� � ������� �����
    void push(int elem);

    // ��������� �������� � ������� ����� � ���������� ���� ��������
    int pop();

    // ��������, �� ������� ����
    bool isEmpty();

    // ����������� N ��������
    void multiPop(int N);

    // ����� ��� �������� �����
    void show();
};

#endif // STACK_H
