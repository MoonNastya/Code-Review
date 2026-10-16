#ifndef LABORATORY_4_TIME_H_
#define LABORATORY_4_TIME_H_
// # ИЗМЕНЕНО: Защитный макрос include guard приведен к требуемому формату PROJECT_PATH_FILE_H_.

#include <iostream>
#include <string>

/**
 * @brief Класс для представления и управления временем в формате Часы:Минуты.
 * @details Реализует инкапсуляцию, автоматическую нормализацию в рамках суток,
 * а также перегрузку унарных и бинарных операторов под Вариант 7.
 */
class Time {
 public:
  // # ИЗМЕНЕНО: Секция public смещена на 1 пробел от края.
  // # ИЗМЕНЕНО: Все отступы переведены строго на 2 пробела.

  /**
   * @brief Конструктор по умолчанию. Инициализирует время как 00:00.
   */
  Time();                         

  /**
   * @brief Конструктор с параметрами.
   * @param h Количество часов.
   * @param m Количество минут.
   */
  Time(short int h, short int m);

  /**
   * @brief Копирующий конструктор.
   * @param other Копируемый объект класса Time.
   */
  Time(const Time& other);

  /**
   * @brief Устанавливает значение часов.
   * @param h Новое значение часов.
   */
  void SetHours(short int h);
  // # ИЗМЕНЕНО: Имя метода переписано в UpperCamelCase (SetHours вместо setHours).

  /**
   * @brief Устанавливает значение минут.
   * @param m Новое значение минут.
   */
  void SetMinutes(short int m);
  // # ИЗМЕНЕНО: Имя метода переписано в UpperCamelCase (SetMinutes вместо setMinutes).

  /**
   * @brief Возвращает количество часов.
   * @return Значение поля hours_.
   */
  short int GetHours() const;
  // # ИЗМЕНЕНО: Имя метода переписано в UpperCamelCase (GetHours вместо getHours).

  /**
   * @brief Возвращает количество минут.
   * @return Значение поля minutes_.
   */
  short int GetMinutes() const;
  // # ИЗМЕНЕНО: Имя метода переписано в UpperCamelCase (GetMinutes вместо getMinutes).

  /**
   * @brief Вычитает объект времени из текущего (Задание 1, Вариант 7).
   * @param other Объект времени, который нужно вычесть.
   * @return Новый объект Time с результатом разности (с учетом перехода на прошлые сутки).
   */
  Time Subtract(const Time& other) const;
  // # ИЗМЕНЕНО: Имя метода переписано в UpperCamelCase (Subtract вместо subtract).

  /**
   * @brief Перегруженный оператор вывода времени в формате ЧЧ:ММ.
   */
  friend std::ostream& operator<<(std::ostream& os, const Time& t);

  /**
   * @brief Префиксный инкремент (++t). Увеличивает время на 1 минуту.
   */
  Time& operator++();

  /**
   * @brief Постфиксный инкремент (t++). Увеличивает время на 1 минуту.
   */
  Time operator++(int);

  /**
   * @brief Префиксный декремент (--t). Уменьшает время на 1 минуту.
   */
  Time& operator--();

  /**
   * @brief Постфиксный декремент (t--). Уменьшает время на 1 минуту.
   */
  Time operator--(int);

  /**
   * @brief Неявное приведение типа к int (Задание 2, Вариант 7).
   * @return Переводит текущее время в общее количество минут.
   */
  operator int() const;             

  /**
   * @brief Явное приведение типа к bool (Задание 2, Вариант 7).
   * @return true, если время отличное от 00:00, иначе false.
   */
  explicit operator bool() const;   
  // # ИЗМЕНЕНО: Добавлено ключевое слово explicit в соответствии с требованиями явного приведения.

  /**
   * @brief Бинарный оператор "меньше" (<) для сравнения двух временных точек (Задание 2, Вариант 7).
   */
  bool operator<(const Time& other) const;

  /**
   * @brief Бинарный оператор "больше" (>) для сравнения двух временных точек (Задание 2, Вариант 7).
   */
  bool operator>(const Time& other) const;

 private:
  // # ИЗМЕНЕНО: Секция private смещена на 1 пробел от края.

  short int hours_;   
  // # ИЗМЕНЕНО: Добавлен замыкающий символ подчеркивания hours_ для нестатического поля класса.

  short int minutes_; 
  // # ИЗМЕНЕНО: Добавлен замыкающий символ подчеркивания minutes_ для нестатического поля класса.

  /**
   * @brief Внутренний метод циклической нормализации времени в пределах одних суток.
   */
  void Normalize();
  // # ИЗМЕНЕНО: Имя приватного метода переписано в UpperCamelCase (Normalize вместо normalize).
};

/**
 * @brief Функция контролируемого безопасного ввода беззнаковых целых чисел с клавиатуры.
 */
unsigned int InputUInt(const std::string& prompt, 
                       unsigned int min_val = 0, 
                       unsigned int max_val = 1000000);
// # ИЗМЕНЕНО: Имя функции изменено на UpperCamelCase (InputUInt вместо inputUInt).
// # ИЗМЕНЕНО: Имена параметров приведены к стилю lower_snake_case (min_val, max_val вместо camelCase).
// # ИЗМЕНЕНО: Длинная строка разбита на несколько строк для соблюдения лимита ширины.

#endif  // LABORATORY_4_TIME_H_
