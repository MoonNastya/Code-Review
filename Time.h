#pragma once
#ifndef TIME_H
#define TIME_H
#include <iostream>
#include <limits>

class Time {
private:
    short int hours;
    short int minutes;

    void normalize(); // нормализация часов и минут

public:
    // Конструкторы
    Time();                         
    Time(short int h, short int m);
    Time(const Time& other);

    // Сеттеры
    void setHours(short int h);
    void setMinutes(short int m);

    // Геттеры
    short int getHours() const;
    short int getMinutes() const;

    // Метод вычитания времени из Варианта 7 (Задание 1)
    Time subtract(const Time& other) const;

    // Перегрузка операторов
    friend std::ostream& operator<<(std::ostream& os, const Time& t);

    // Унарные операции (Задание 2)
    Time& operator++();    // ++t
    Time operator++(int);  // t++
    Time& operator--();    // --t
    Time operator--(int);  // t--

    // Приведение типов (Задание 2)
    operator int() const;             // неявная: общее количество минут
    explicit operator bool() const;   // явная: true, если время не 00:00

    // Бинарные операции сравнения (Задание 2)
    bool operator<(const Time& other) const;
    bool operator>(const Time& other) const;
};

// Функция безопасного ввода
unsigned int inputUInt(const std::string& prompt, unsigned int minVal = 0, unsigned int maxVal = 1000000);

#endif
