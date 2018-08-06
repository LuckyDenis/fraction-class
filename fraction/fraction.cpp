#include "fraction.h"

// НОД
int gcd(int a, int b)
{
    a = abs(a);
    b = abs(b);
    while(a != b){
        if(a < b){
            b = b - a;
        }
        else{
            a = a - b;
        }
    }
    return a;
}

// Конструктор без параметров
fraction::fraction() {
}

// Конструктор с параметрами
fraction::fraction(int & n, int & d) {
    this->numerator = n;
    this->denominator = d;
    if(this->denominator < 0){
        this->numerator *= -1;
        this->denominator *= -1;
    }
}

// Деструктор
fraction::~fraction(){
}

// Вычитание
fraction operator - (const fraction & f1, const fraction & f2) {
    fraction f;
    int temp_gcd = gcd(f1.denominator, f2.denominator);

    // Первый знаменатель НОД
    if(temp_gcd == f1.denominator){
        f.denominator = f2.denominator;
        f.numerator = f1.numerator * temp_gcd - f2.numerator;
    // Второй знаменатель НОД
    }else if(temp_gcd == f2.denominator){
        f.denominator = f1.denominator;
        f.numerator = f1.numerator - f2.numerator * temp_gcd;
    }
    // НОДа нет
    else{
        f.denominator = f1.denominator * f2.denominator;
        f.numerator = f1.numerator * f2.denominator;
        f.numerator -= f2.numerator * f1.denominator;
    }

    // Переносим знак минуса из знаменателя в числитель
    if(f.denominator < 0){
        f.numerator *= -1;
        f.denominator *= -1;
    }

    // Сокрощаем дробь
    temp_gcd = gcd(f.denominator, f.numerator);
    if(temp_gcd != 1){
        f.denominator /= temp_gcd;
        f.numerator /= temp_gcd;
    }

    return f;
}

// Сложение
fraction operator + (const fraction & f1, const fraction & f2) {
    fraction f;

    int temp_gcd = gcd(f1.denominator, f2.denominator);

    // Первый знаменатель НОД
    if(temp_gcd == f1.denominator){
        f.denominator = f2.denominator;
        f.numerator = f2.numerator + f1.numerator * temp_gcd;
    // Второй знаменатль НОД
    }else if(temp_gcd == f2.denominator) {
        f.denominator = f1.denominator;
        f.numerator = f1.numerator + f2.numerator * temp_gcd;
    // НОДа нет
    }else{
        f.denominator = f1.denominator * f2.denominator;
        f.numerator = f1.denominator * f2.numerator;
        f.numerator += f2.denominator * f1.numerator;
    }

    // Переносим минус от знаменателя в числитель
    if(f.denominator < 0){
        f.numerator *= -1;
        f.denominator *= -1;
    }

    // Сокращенаем дробь
    temp_gcd = gcd(f.numerator, f.denominator);
    if(temp_gcd != 1){
        f.denominator /= temp_gcd;
        f.numerator /= temp_gcd;
    }
    return f;
}

// Умножение
fraction operator * (const fraction & f1, const fraction & f2) {
    fraction f;

    // Перемножаем
    f.numerator = f1.numerator * f2.denominator;
    f.denominator = f1.denominator * f2.numerator;

    // Переносим минус от знаменателя в числитель
    if(f.denominator < 0){
        f.numerator *= -1;
        f.denominator *= -1;
    }

    // Сокрощаем
    int temp_gcd = gcd(f.numerator, f.denominator);
    if(temp_gcd != 1){
        f.numerator /= temp_gcd;
        f.denominator /= temp_gcd;
    }
    return f;
}

// Деление
fraction operator / (const fraction & f1, const fraction & f2) {
    fraction f;

    // Перемножаем
    f.denominator = f1.numerator * f2.denominator;
    f.denominator = f1.denominator * f1.numerator;

    // Переносим минус от знаменателя в числитель
    if(f.denominator < 0){
        f.numerator *= -1;
        f.denominator *= -1;
    }

    // Сокрощаем дробь
    int temp_gcd = gcd(f.numerator, f.denominator);
    if(temp_gcd != 1){
        f.numerator /= temp_gcd;
        f.denominator /= temp_gcd;
    }
    return f;
}

// Копирование
void fraction::operator = (const fraction &f1) {
    this->numerator = f1.numerator;
    this->denominator = f1.denominator;
}

// Вывод из потока
std::istream& operator >> (std::istream & stream, fraction & f){
    std::cin >> f.numerator;
    std::cin >> f.denominator;

    // Переносим знак минус из знаменателя в числитель
    if(f.denominator < 0){
        f.numerator *= -1;
        f.denominator *= -1;
    }
    return stream;
}

// Ввод в поток
std::ostream& operator << (std::ostream & stream,  const fraction & f) {
    std::cout << f.numerator << "/" << f.denominator;
    return stream;
}
