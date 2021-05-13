#include <stdexcept>
#include <iostream>

#include <cstdint>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>    
#include "integer.h"

// проверка на переполнение
// проверка на несоответствующие символы
// проверка на 
// num_str.fill(begin(),begin()+  , '0');
// convert string to int
//int64_t *bigN, const int64_t div
int64_t to_int(std::string num_str, float div_size);


void Integer::pull_str(std::vector<int64_t>& bigN)
{
    //if (!this->div) this->div = std::ceil(this->num_str.length() / this->div_size);
    //std::fill(this->num_str.begin(),this->num_str.begin()+(this->div*this->div_size), '0');
    this->num_str.clear();
    std::string va(static_cast<size_t>(this->div * this->div_size), '0');
    std::string val(std::to_string(bigN[0]));
    int len = 0;
    for (int i = 1; i < this->div + 1; ++i)
    {
        if (len > this->div * this->div_size) throw "pull_str error";

        va.replace(va.end() - len - val.length(), va.end() - len, val);

        len += std::to_string(bigN[i - 1]).length();
        if (val.length() < static_cast<size_t>(this->div_size))
        {
            val = std::to_string(bigN[i]);
            for (int j = std::to_string(bigN[i - 1]).length(); j < this->div_size; ++j) val += "0";
        }
        else val = std::to_string(bigN[i]);
    }
    int i = 0;
    while (va[i] == '0') va.erase(va.begin(), va.begin() + 1); ++i;

    this->num_str = va;
}

void Integer::division(std::vector<int64_t>& bigN) const
{
    //if (!this->div) this->div = std::ceil(this->num_str.length() / this->div_size);
    //if (bigN != nullptr) delete [] bigN;
    //this->bigN = new int64_t[this->div];std::ceil(this->num_str.length() / this->div_size)
    //std::cout << "sub = " << this->num_str.substr(0,i) << '\n';
    for (int i = this->num_str.length() - 1, j = 0; i > 0; i -= this->div_size - 1)
    {
       
        if (i - this->div_size < 0)
        {
            if (j) { bigN[j] = to_int(this->num_str.substr(0, i), 0); }
            else { bigN[j] = to_int(this->num_str, 0); return; }
        }
        else bigN[j] = to_int(this->num_str.substr(i - static_cast<size_t>(this->div_size) + 1, i), this->div_size);
        //if (j && std::to_string(bigN[j-1]).length() <  std::pow(10,this->div_size-2)) 
        //    { bigN[j] *= std::pow(10,this->div_size-std::to_string(bigN[j-1]).length()); }
        ++j;
    }
    return;
}
int64_t to_int(std::string num_str, float div_size) // , int &null_flg
{
    int64_t num = 0;
    int64_t k = 1;
    if (num_str[0] != '-')
    {
        for (auto i = num_str.end() - 1; i >= num_str.begin(); --i)
        {
            if (*i > 47 && *i < 58) {
                num += (*i - '0') * k;
                //if (num == 0 &&i == num_str.begin()) num += k; null_flg = true;
                k *= 10;

            }
            else
            {
                throw std::runtime_error("Doesn't a number\n");
                exit(1);
            }
        }
    }
    else
    {
        for (auto i = num_str.end() - 1; i >= num_str.begin() + 1; --i)
        {
            if (*i > 47 && *i < 58)
            {
                num -= (*i - '0') * k;
                k *= 10;
            }
            else
            {
                throw std::runtime_error("Doesn't a number\n");
                exit(1);
            }
        }
    }
    int i = static_cast<int>(div_size);
    while (i > num_str.length()) { num *= 10; --i; }
    return num;
}

Integer& Integer::operator=(const Integer& right)
{
    //if (this->bigN != nullptr) delete [] this->bigN;
    this->num_str = right.num_str;
    this->div = right.div;
    //this->bigN = new int64_t[this->div];
    return *this;
}
static boolean isDelim(char c) { // тру если пробел
    return c == ' ';
}
static boolean isOperator(char c) { // возвращяем тру если один из символов ниже
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '%';
}
static int priority(char op) {
    switch (op) { // при + или - возврат 1, при * / % 2 иначе -1
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
    case '%':
        return 2;
    default:
        return -1;
    }
}

    for (auto ){

}

const Integer& Integer::operator+(const Integer& right)
{
    if (this->num_str[0] == '-' || right.num_str[0] == '-')
    {
        return this->operator-(right);
    }
    if (!this->div) this->div = std::ceil(this->num_str.length() / this->div_size);
    if (this->div < right.div) this->div = right.div;
    //std::cout << this->div << '\n';
    std::vector<int64_t> bigN_this(this->div, 0);
    std::vector<int64_t> bigN_right(this->div, 0);
    this->division(bigN_this);
    right.division(bigN_right);
    if ((this->num_str[0] == '-' && right.num_str[0] == '-'))
    {
        for (auto i = 0; i < this->div; ++i)
        {
            bigN_this[i] += 2 * bigN_this[i];
            bigN_right[i] += 2 * bigN_right[i];
        }
    }
    //if ( this->div > 1 && bigN_this[this->div] < '0' && bigN_right[this->div] < 0 ) { }
    for (auto i = 0; i < this->div; ++i)
    {
        if (bigN_this[i] + bigN_right[i] > std::pow(10, this->div_size))
        {
            bigN_this[i] = bigN_this[i] + bigN_right[i] - std::pow(10, this->div_size - 1);
            ++bigN_this[i + 1];
        }
        else bigN_this[i] = bigN_this[i] + bigN_right[i];
    }
    if ((this->num_str[0] != '-' && right.num_str[0] != '-'))
    {
        this->pull_str(bigN_this);
        return *this;
    }
    else if ((this->num_str[0] == '-' && right.num_str[0] == '-'))
    {
        this->pull_str(bigN_this);
        this->num_str.insert(this->num_str.begin(), '-');
        return *this;
    }
    else
    {
        throw std::runtime_error("Doesn't a number\n");
        exit(1);
    }

}


const Integer& Integer::operator-(const Integer& right)
{
    if (!this->div) this->div = std::ceil(this->num_str.length() / this->div_size);
    if (this->div < right.div) this->div = right.div;
    std::vector<int64_t> bigN_this(this->div, 0);
    std::vector<int64_t> bigN_right(this->div, 0);
    //this->div = right.div;
/*
    if (this->num_str[0] == '-' && right.num_str[0] != '-')
    {
        return this->operator+(right);
    }
    else if ( this->num_str[0] == '-' || right.num_str[0] == '-' )
    {
        //
    }
*/
    if (this->num_str.length() < right.num_str.length()
        || (this->num_str.length() == right.num_str.length()
            && this->num_str[0] < right.num_str[0]))
    {
        this->division(bigN_right); // from bigger num
        right.division(bigN_this);  // subtract lower num
    }
    else
    {
        this->division(bigN_this);
        right.division(bigN_right);
    }

    for (auto i = 0; i < this->div; ++i)
    {
        if (bigN_this[i] < bigN_right[i] && i)
        {
            bigN_this[i] = bigN_this[i] - bigN_right[i] + std::pow(10, this->div_size - 1);
            if (bigN_this[i + 1] == 0) // UB
            {
                for (int j = i; ; ++j) // bigN_this[j+1] == 0
                {
                    if (bigN_this[j + 1] != 0) { --bigN_this[j + 1]; break; }
                    else bigN_this[j + 1] = 999999999;
                }
            }
            else --bigN_this[i + 1];
        }
        else bigN_this[i] = bigN_this[i] - bigN_right[i];
    }
    if (this->num_str.length() < right.num_str.length()
        || (this->num_str.length() == right.num_str.length()
            && this->num_str[0] < right.num_str[0]))
    {

        this->pull_str(bigN_this);
        this->num_str.insert(this->num_str.begin(), '-');
    }
    else
    {
        this->pull_str(bigN_this);
    }
    //this->num_str.insert(this->num_str.begin(), '-');

    return *this;
}
const Integer& Integer::operator++()
{
    if (!this->div) this->div = std::ceil(this->num_str.length() / this->div_size);
    std::vector<int64_t> bigN_this(this->div + 1, 0);
    this->division(bigN_this);
    for (auto i = 0; i < this->div; ++i)
    {
        if (bigN_this[i] == 999999999)
        {
            bigN_this[i] = 0;
            bigN_this[i + 1] += 1;
            break;
        }
        else
        {
            ++bigN_this[i];
            break;
        }
    }
    return *this;
}
/*
const Integer &Integer::operator*(const Integer &right)
{
    this->num = this->num * right.num;
    this->num_str = std::to_string(num);
    return *this;
}
const Integer &Integer::operator/(const Integer &right)
{
    this->num = this->num / right.num;
    this->num_str = std::to_string(num);
    return *this;
}
const Integer &Integer::operator%(const Integer &right)
{
    this->num = this->num % right.num;
    this->num_str = std::to_string(num);
    return *this;
}

Integer &Integer::operator--()
{
    --num;
    num_str = std::to_string(num);
    return *this;
}
const Integer operator++(Integer &thi, int)
{
    Integer var;
    var.num = thi.num;
    var.num_str = thi.num_str;
    ++(thi.num);
    thi.num_str = std::to_string(thi.num);
    return var;
}
const Integer operator--(Integer &thi, int)
{
    Integer var;
    var.num = thi.num;
    var.num_str = thi.num_str;
    --(thi.num);
    thi.num_str = std::to_string(thi.num);
    return var;
}
*/
std::ostream& operator<<(std::ostream& out, const Integer& right)
{
    return (out << right.num_str);
}
std::istream& operator>>(std::istream& in, Integer& right)
{
    in >> right.num_str;
    //right.division();
    //right.num = right.to_int(right.num_str);
    return in;
}
/*
Integer::operator std::string() const
{
    return this->num_str;
}
Integer::operator int64_t() const
{
    return this->num;
}
*/
/*
std::string Integer::to_string(int64_t num)
{
    // convert int to string
    std::string str = std::to_string(num);
    return str;
}
*/