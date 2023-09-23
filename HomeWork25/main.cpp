#include <iostream>
#include <string>

bool palindrom(std::string str);

int count_sign(std::string str);

std::string func(std::string str, char sym);

int main() {
	setlocale(LC_ALL, "Russian");
	int n;
	std::string str = "Hello world!";
	char sym;
	std::string new_str;


	std::cout << "Задача 1.\n";
	std::cout << "str = \"" << str << "\"" << std::endl;
	std::cout << "Введите символ -> ";
	std::cin >> sym;
	int count = 0;
	int index = -1;
	for (int i = 0; i < str.length(); i++) {
		index = str.find(sym,i);
		if (index != -1) {
			new_str += sym;
			i= index;
		}
			
	}
	std::cout << "new_str = \"" << new_str << "\"" << std::endl;

	std::cout << "Задача 2.\n";
	std::cout << "Введите строку -> ";
	std::cin >> str;

	bool flag = palindrom(str);

	if (flag == true)
		std::cout << "Слово является палиндромом!\n\n";
	else
		std::cout << "Слово не является палиндромом!\n\n";

	std::cout << "Задача 3.\n";
	
	std::cin.ignore();

	std::cout << "Введите строку -> ";
	std::getline(std::cin, str);

	std::cout << "Количество знаков в строке " << count_sign(str) << "\n\n";

	std::cout << "Задача 4.\n";

	std::cout << "Введите строку -> ";

	std::getline(std::cin, str);

	std::cout << "Введите символ -> ";
	std::cin >> sym;

	std::cout << func(str, sym) << "\n\n";


	return 0;
}


bool palindrom(std::string str) {
	for (int i = 0; i < str.length(); i++)
		str[i] = std::tolower(str[i]);
	bool flag = true;
	for (int i = 0; i < str.length() / 2; i++) {
		if (str[i] != str[str.length() - 1 - i]) {
			flag = false;
			return flag;
		}
	}
	return flag;
}

int count_sign(std::string str) {
	int count = 0;
	for (int i = 0; i < str.length(); i++) {
		switch (str[i]) {
		case '.': count++;
			break;
		case ' ': count++;
			break;
		case ',': count++;
			break;
		case '!': count++;
			break;
		case '?': count++;
		default:
			break;
		}
	}

	return count;
}

std::string func(std::string str, char sym) {
	int index = -1;
	std::string tmp;
	index = str.rfind(sym);
	if (index == -1) {
		str = "";
		return str;
	}
	for (int i = index; i < str.length(); i++) {
		tmp += str[i];
	}
	str = tmp;
	return str;
}