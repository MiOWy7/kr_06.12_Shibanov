#include <iostream>

int evaluateHand(int* hand) {
    int counts[11] = {0}; // Массив для подсчета количества каждой карты (от 0 до 10)

    // Подсчет количества каждой карты
    for (int i = 0; i < 5; i++) {
        counts[hand[i]]++;
    }

    // Проверка условий
    bool hasFour = false;
    bool hasThree = false;
    int pairs = 0;

    for (int i = 0; i < 11; i++) {
        if (counts[i] == 5) {
            return 1; // Все 5 одинаковые
        }
        if (counts[i] == 4) {
            hasFour = true; // Есть 4 одинаковые
        }
        if (counts[i] == 3) {
            hasThree = true; // Есть 3 одинаковые
        }
        if (counts[i] == 2) {
            pairs++; // Считаем количество пар
        }
    }

    if (hasFour) {
        return 2; // Есть 4 одинаковые
    }
    if (hasThree && pairs > 0) {
        return 3; // Есть 3 одинаковые и хотя бы одна пара
    }
    if (hasThree) {
        return 4; // Есть 3 одинаковые
    }
    if (pairs == 2) {
        return 5; // Две пары
    }
    if (pairs == 1) {
        return 6; // Одна пара
    }

    return 7; // Нет совпадений
}

int main() {
    int hand[5];

    std::cout << "Введите 5 чисел (от 0 до 10): ";
    for (int i = 0; i < 5; i++) {
        std::cin >> hand[i];
    }

    int result = evaluateHand(hand);
    std::cout << "Результат: " << result << std::endl;

    return 0;
}
