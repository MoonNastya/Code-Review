#include "Time.h"
#include <iostream>

int main() {
    setlocale(LC_ALL, "ru");

    std::cout << "=== Конструктор по умолчанию ===\n";
    Time t1;
    std::cout << "t1: " << t1 << "\n";

    std::cout << "=== Конструктор с параметрами ===\n";
    unsigned int h1 = inputUInt("Введите часы для t2 (0-23): ", 0, 23);
    unsigned int m1 = inputUInt("Введите минуты для t2 (0-59): ", 0, 59);
    Time t2(static_cast<short int>(h1), static_cast<short int>(m1));
    std::cout << "t2: " << t2 << "\n";

    std::cout << "=== Копирующий конструктор ===\n";
    Time t3(t2);
    std::cout << "t3 (копия t2): " << t3 << "\n";

    std::cout << "\n=== Задание 1: Вычитание времени с переходом через сутки ===\n";
    unsigned int h2 = inputUInt("Введите часы для вычитаемого времени (0-23): ", 0, 23);
    unsigned int m2 = inputUInt("Введите минуты для вычитаемого времени (0-59): ", 0, 59);
    Time subTime(static_cast<short int>(h2), static_cast<short int>(m2));
    
    Time resultSub = t2.subtract(subTime);
    std::cout << "Результат вычитания (" << t2 << " - " << subTime << ") = " << resultSub << "\n";

    std::cout << "\n=== Унарные операции ++ и -- (на примере t2) ===\n";
    ++t2;
    std::cout << "++t2: " << t2 << "\n";
    t2++;
    std::cout << "t2++: " << t2 << "\n";
    --t2;
    std::cout << "--t2: " << t2 << "\n";
    t2--;
    std::cout << "t2--: " << t2 << "\n";

    std::cout << "\n=== Неявное и явное приведение типов ===\n";
    int totalMinutes = t2;
    std::cout << "Неявное приведение к int (общее число минут в t2): " << totalMinutes << "\n";
    std::cout << "t2 содержит ненулевое время? " << (static_cast<bool>(t2) ? "Да" : "Нет") << "\n";

    std::cout << "\n=== Бинарные операторы сравнения ===\n";
    std::cout << "Сравнение t2 (" << t2 << ") и результата вычитания (" << resultSub << "):\n";
    if (t2 < resultSub) {
        std::cout << "t2 меньше, чем результат вычитания\n";
    } else if (t2 > resultSub) {
        std::cout << "t2 больше, чем результат вычитания\n";
    } else {
        std::cout << "Время совпадает\n";
    }

    return 0;
}
