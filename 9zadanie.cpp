#include <iostream>
#include <cstdlib>
#include <ctime>

int findZigzagLength(int* X, int m) {
    if (m < 2) return m;

    int maxLength = 1;
    int currentLength = 1;
    bool expectingUp = true; // Начинаем с ожидания "вверх"

    for (int i = 1; i < m; i++) {
        if (expectingUp && X[i] > X[i - 1]) {
            currentLength++;
            expectingUp = false; // Теперь ожидаем "вниз"
        } else if (!expectingUp && X[i] < X[i - 1]) {
            currentLength++;
            expectingUp = true; // Теперь ожидаем "вверх"
        } else {
            maxLength = std::max(maxLength, currentLength);
            currentLength = 2; // Сбрасываем длину, начинаем новую последовательность
            expectingUp = (X[i] > X[i - 1]); // Устанавливаем новое ожидание
        }
    }
    maxLength = std::max(maxLength, currentLength); // Проверяем в конце

    return maxLength;
}

int main() {
    int m;
    std::cout << "Введите длину массива: ";
    std::cin >> m;

    int* X = new int[m]; // Динамическое выделение памяти для массива

    std::srand(std::time(0)); // Инициализация генератора случайных чисел
    std::cout << "Элементы массива: ";
    for (int i = 0; i < m; i++) {
        X[i] = std::rand() % 100; // Заполнение массива случайными числами от 0 до 99
        std::cout << X[i] << " "; // Вывод элементов массива
    }
    std::cout << std::endl;

    int k = findZigzagLength(X, m);
    std::cout << "Длина самой длинной зигзагообразной последовательности: " << k << std::endl;

    delete[] X; // Освобождение выделенной памяти
    return 0;
}
