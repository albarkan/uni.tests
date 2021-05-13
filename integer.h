#ifndef integer_h
#define integer_h

#include <cstdint>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

/* - класс, реализирующий хранение
*  информации:
*
*  Базовый тип , формат представления:
*
*
*  1. представление в памяти
*  2. конструктор/ы
*  3. деструктор
*  4. конструктор копирования, оператор копирования
*  5. методы для обеспечения отдельных полей объекта
*  6. стандартная арифметика
*  7. сравнение                 //сделать
*  8. оператор присваивания
*  9. ввод/вывод в стандартный поток
*  10. приведение от/к базового типа данных
*  11. метод для ввода из потока
*/

class Integer {

private:
    std::string num_str;

    int div = 0;  // количество разбиений

    const float div_size = 9.0;


public:
    Integer() {}
    Integer(std::string num_str)
    {
        this->num_str = num_str;
        this->div = std::ceil(this->num_str.length() / this->div_size);
        //this->division();
    }
    Integer(int64_t num)
    {
        this->num_str = std::to_string(num);
        this->div = std::ceil(this->num_str.length() / this->div_size);
    }
    Integer(std::istream& in)
    {
        getline(in, num_str);
        this->div = std::ceil(this->num_str.length() / this->div_size);
    }
    Integer(const Integer& copy) : num_str(copy.num_str), div(copy.div) {} // copy constr

    ~Integer() {}

    std::string get_num_str() const { return this->num_str; } // getter

    void set_num_str(std::string num_str)
    {
        this->num_str = num_str;
        this->div = std::ceil(this->num_str.length() / this->div_size);
    } // setter

    void set_num(int64_t num)
    {
        this->num_str = std::to_string(num);
        this->div = std::ceil(this->num_str.length() / this->div_size);
    }


    //int64_t to_int(std::string num_str); // convert string to int
    void division(std::vector<int64_t>& bigN) const;
    void pull_str(std::vector<int64_t>& bigN);
    Integer& operator=(const Integer& right);
    const Integer& operator+(const Integer& right);
    const Integer& operator-(const Integer& right);
    const Integer& operator*(const Integer& right);
    const Integer& operator/(const Integer& right);
    const Integer& operator%(const Integer& right);
    const Integer& operator++();
    Integer& operator--();
    friend const Integer operator++(Integer& thi, int);
    friend const Integer operator--(Integer& thi, int);
    friend std::ostream& operator<<(std::ostream& out, const Integer& right);
    friend std::istream& operator>>(std::istream& in, Integer& right);
    operator std::string() const;
};

#endif //integer_h


