# include <iostream>
#include"Functor.hpp"

int main() {	
	// Переменные для хранения операндов, введённые пользователем
	double num1, num2;
	// Переменная для хранения символа оператора, выбранного пользователем
	char sym;	
	// Переменная для хранения точности расчётов (кол-во знаков после запятой)
	int accuracy; 
	std::cout << "\033[93mEnter the first number -> \033[0m";
	std::cin >> num1;
	std::cout << "\033[93mEnter the type of mathematical operation -> \033[0m";
	std::cin >> sym;
	// Обработка исключения, если пользователь выбрал неизвестную калькулятору операцию
	try {
		if (sym != '+' && sym != '-' && sym != '/' && sym != '*' && sym != '^')
			throw std::exception("\033[91mInput error! There is no such operation in the calculator\033[0m");
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
		while (sym != '+' && sym != '-' && sym != '/' && sym != '*' && sym != '^') {
			std::cout << "\033[93mEnter the type of mathematical operation one more time -> \033[0m";
			std::cin >> sym;
		}
	}
	if (sym == '^') { // Если пользователь хочет возвести num1 в степень
		std::cout << "\033[93mEnter degree -> \033[0m";
		std::cin >> num2;
	}
	else {
		std::cout << "\033[93mEnter the second number -> \033[0m";
		std::cin >> num2;
	}
	// Переменная для хранения анонимной функции, содержащей правила обработки данных
	auto result = [](double num1, double num2, char sym)->double {
		switch (sym) {
		case '+': return (num1 + num2);
		case '-': return (num1 - num2);
		case '/': return (num1 / num2);
		case '*': return (num1 * num2);
		case '^': return pow(num1, num2);
		}
	};
	Functor calculator(result(num1, num2, sym)); // Создаём функтор c результатом анонимной функции
	char choice;
	do { // Цикл для лемонстрации того, что функтор хранит неизменный результат расчёта, а в консоль каждый раз выводит то, что \
		просит пользователь
		std::cout << "\033[93mEnter the number of decimal places -> \033[0m";
		std::cin >> accuracy;
		try {
			if (accuracy < 0)
				throw std::exception("\033[91mInput error! The quantity of decimal places cannot be negative!\033[0m");
		}
		catch (const std::exception& ex) {
			std::cout << ex.what() << std::endl;
			while (accuracy < 0) {
				std::cout << "\033[93mEnter the number of decimal places one more time -> \033[0m";
				std::cin >> accuracy;
			
		}
		// Выводим результат в соответствии с заданной пользователем точностью
		std::cout << std::endl << "\033[92mThe result is \033[0m" << calculator(accuracy) << std::endl << std::endl << \
			"\033[93mDo you want to change the accuracy?\033[0m" << std::endl << \
			"Press \033[91m'1'\033[0m if you want \033[4mor\033[0m press \033[91many other key\033[0m if everything suits you -> ";
		std::cin >> choice;
	} while (choice=='1');
	
	return 0;
}