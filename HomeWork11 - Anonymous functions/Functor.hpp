#pragma once
#include<string>

/*!
*	\brief Класс для созддания объекта-функтора, хранящего результат вычисления калькулятора
*/
class Functor {
public:
	Functor(double num) :value_(num) {}
	double operator ()(int accuracy) {						
		std::cout.precision(accuracy); // Задаём на вывод в консоль число с accuracy-значащими знаками
		std::cout.setf(std::ios::fixed); // после точки
		return value_;
	}
private:
	double value_;
};