#include "Time.h"
#include <iomanip>

// --- Нормализация ---
void Time::normalize() {
    long total_minutes = hours * 60 + minutes;

    if (total_minutes < 0) {
        long days = (-total_minutes / 1440) + 1;
        total_minutes += days * 1440;
    }

    total_minutes %= 1440;
    hours = static_cast<short int>(total_minutes / 60);
    minutes = static_cast<short int>(total_minutes % 60);
}

// --- Конструкторы ---
Time::Time() : hours(0), minutes(0) {}

Time::Time(short int h, short int m) : hours(h), minutes(m) { 
    normalize(); 
}

Time::Time(const Time& other) : hours(other.hours), minutes(other.minutes) {}

// --- Сеттеры ---
void Time::setHours(short int h) { 
    hours = h; 
    normalize(); 
}

void Time::setMinutes(short int m) { 
    minutes = m; 
    normalize(); 
}

// --- Геттеры ---
short int Time::getHours() const { return hours; }
short int Time::getMinutes() const { return minutes; }

// --- Метод вычитания времени (Задание 1) ---
Time Time::subtract(const Time& other) const {
    short int res_h = this->hours - other.hours;
    short int res_m = this->minutes - other.minutes;
    return Time(res_h, res_m);
}

// --- Перегрузка вывода ---
std::ostream& operator<<(std::ostream& os, const Time& t) {
    os << std::setfill('0') << std::setw(2) << t.hours << ":"
       << std::setfill('0') << std::setw(2) << t.minutes;
    return os;
}

// --- Унарные операции ---
Time& Time::operator++() { 
    minutes++; 
    normalize(); 
    return *this; 
}

Time Time::operator++(int) { 
    Time temp = *this; 
    ++(*this); 
    return temp; 
}

Time& Time::operator--() {
    minutes--;
    normalize();
    return *this;
}

Time Time::operator--(int) { 
    Time temp = *this; 
    --(*this); 
    return temp; 
}

// --- Приведение типов ---
Time::operator int() const { 
    return hours * 60 + minutes; 
}

Time::explicit operator bool() const { 
    return hours != 0 || minutes != 0; 
}

// --- Бинарные операции ---
bool Time::operator<(const Time& other) const {
    return static_cast<int>(*this) < static_cast<int>(other);
}

bool Time::operator>(const Time& other) const {
    return static_cast<int>(*this) > static_cast<int>(other);
}

// --- Ввод чисел ---
unsigned int inputUInt(const std::string& prompt, unsigned int minVal, unsigned int maxVal) {
    unsigned int value;
    std::cout << prompt;
    while (!(std::cin >> value) || value < minVal || value > maxVal) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Ошибка. Введите число в диапазоне [" << minVal << ", " << maxVal << "]: ";
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return value;
}
