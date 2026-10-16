// # ИЗМЕНЕНО: Файл реализации переименован в нижний регистр и получил расширение .cc.
#include "time.h"

#include <iomanip>
#include <limits>

void Time::Normalize() {
  // # Пропускаем полные сутки и корректно перематываем отрицательные значения назад через long.
  long total_minutes = hours_ * 60 + minutes_;

  if (total_minutes < 0) {
    long days = (-total_minutes / 1440) + 1;
    total_minutes += days * 1440;
  }

  total_minutes %= 1440;
  // # ИЗМЕНЕНО: Вместо C-style cast применен безопасный static_cast.
  hours_ = static_cast<short int>(total_minutes / 60);
  minutes_ = static_cast<short int>(total_minutes % 60);
}

Time::Time() : hours_(0), minutes_(0) {}

Time::Time(short int h, short int m) : hours_(h), minutes_(m) { 
  Normalize(); 
}

Time::Time(const Time& other) : hours_(other.hours_), minutes_(other.minutes_) {}

void Time::SetHours(short int h) { 
  hours_ = h; 
  Normalize(); 
}

void Time::SetMinutes(short int m) { 
  minutes_ = m; 
  Normalize(); 
}

short int Time::GetHours() const { 
  return hours_; 
}

short int Time::GetMinutes() const { 
  return minutes_; 
}

Time Time::Subtract(const Time& other) const {
  // # Вычисление разности. Метод Normalize() внутри конструктора автоматически обработает уход в прошлые сутки.
  short int res_h = hours_ - other.hours_;
  short int res_m = minutes_ - other.minutes_;
  return Time(res_h, res_m);
}

std::ostream& operator<<(std::ostream& os, const Time& t) {
  // # Форматирование вывода времени с обязательным заполнением ведущими нулями до 2 позиций.
  os << std::setfill('0') << std::setw(2) << static_cast<int>(t.hours_) << ":"
     << std::setfill('0') << std::setw(2) << static_cast<int>(t.minutes_);
  return os;
}

Time& Time::operator++() { 
  minutes_++; 
  Normalize(); 
  return *this; 
}

Time Time::operator++(int) { 
  Time temp = *this; 
  ++(*this); 
  return temp; 
}

Time& Time::operator--() {
  minutes_--;
  Normalize();
  return *this;
}

Time Time::operator--(int) { 
  Time temp = *this; 
  --(*this); 
  return temp; 
}

Time::operator int() const { 
  return hours_ * 60 + minutes_; 
}

Time::operator bool() const { 
  return hours_ != 0 || minutes_ != 0; 
}

bool Time::operator<(const Time& other) const {
  // # ИЗМЕНЕНО: Используется корректное явное приведение static_cast вместо C-style cast.
  return static_cast<int>(*this) < static_cast<int>(other);
}

bool Time::operator>(const Time& other) const {
  return static_cast<int>(*this) > static_cast<int>(other);
}

unsigned int InputUInt(const std::string& prompt, unsigned int min_val, unsigned int max_val) {
  unsigned int value;
  std::cout << prompt;
  while (!(std::cin >> value) || value < min_val || value > max_val) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Ошибка. Введите число в диапазоне [" << min_val << ", " << max_val << "]: ";
  }
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  return value;
}

