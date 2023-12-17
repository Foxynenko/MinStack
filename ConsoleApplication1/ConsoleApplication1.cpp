#include <iostream>
#include <stack>

using namespace std;

class MinStack {
private:
    stack<int> dataStack;
    stack<int> minStack;

public:
    // Конструктор класу
    MinStack() {}

    // Додавання елемента у стек
    void push(int val) {
        dataStack.push(val);

        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        }
    }

    // Видалення елемента зі стеку
    void pop() {
        if (dataStack.top() == minStack.top()) {
            minStack.pop();
        }

        dataStack.pop();
    }

    // Отримання верхнього елемента стеку
    int top() {
        return dataStack.top();
    }

    // Отримання мінімального елемента у стеку
    int getMin() {
        return minStack.top();
    }
};

int main() {
    // Створення об'єкта MinStack
    MinStack minStack;

    // Виклики методів для вказаних операцій
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << "getMin: " << minStack.getMin() << endl;
    minStack.pop();
    cout << "top: " << minStack.top() << endl;
    cout << "getMin: " << minStack.getMin() << endl;

    return 0;
}
