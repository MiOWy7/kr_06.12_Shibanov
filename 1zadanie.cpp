#include <iostream>
#include <cstdlib>
#include <ctime>

void binary_digits(int M, int n, int* b) {
    int i = n - 1;

    while (M > 0 && i >= 0) {
        b[i] = M % 2;
        M /= 2;
        i--;
    }
}

int main() {
    std::srand(std::time(0)); // Инициализация генератора случайных чисел

    int n;
    std::cout << "Введите длину массива: ";
    std::cin >> n;

    // Динамическое выделение памяти для массива
    int* a = new int[n];

    // Заполнение массива случайными 0 и 1
    for (int i = 0; i < n; i++) {
        a[i] = std::rand() % 2;
    }

    std::cout << "Массив двоичных цифр числа M: ";
    for (int i = 0; i < n; i++) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;

    // Вычисление M
    int M = 0;
    for (int i = 0; i < n; i++) {
        M += a[i] * (1 << i); // 2^i
    }
    std::cout << "Число M: " << M << std::endl;

    // Вычисление M + 1
    M += 1;
    std::cout << "Число M + 1: " << M << std::endl;

    // Получение массива двоичных цифр M + 1
    int* b = new int[n](); // Динамическое выделение памяти для двоичных цифр и инициализация нулями
    двоичные_цифры(M, n, b);
    
    std::cout << "Массив двоичных цифр M + 1: ";
    for (int i = 0; i < n; i++) {
        std::cout << b[i] << " ";
    }
    std::cout << std::endl;

    // Освобождение выделенной памяти
    delete[] a;
    delete[] b;

    return 0;
}
