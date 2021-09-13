#include <iostream>
#include <cstring>

//Вариант 3

class FooString {
	char* buf;
public:
	FooString(char* tbuf);
	~FooString();
	void show();
	bool compare(char* str);
};

FooString::FooString(char* tbuf) {
	int size = strlen(tbuf) + 1;
	buf = new char[size];
	for (size_t i = 0; i < size; i++) {
		buf[i] = tbuf[i];
	}
}

FooString::~FooString() {
	delete[] buf;
}

void FooString::show() {
	for (int i = 0; buf[i] != '\0'; i++) {
		std::cout << buf[i];
	}
	std::cout << std::endl;
}

bool FooString::compare (char* str) {
	int i = 0;
	while (str[i] != '\0' || buf[i] != '\0') {
		if (str[i] != buf[i])
			return false;
		i++;
	}
	return true;
}

int main() {
	char r[7] = "React";
	FooString str(&r[0]);
	std::cout << "Test method \"compare\": ";
	if (str.compare(r)) {
		r[3] = 's';
		if (!str.compare(r)) {
			r[6] = 'r';
			if (!str.compare(r)) {
				std::cout << "OK" << std::endl;
			}
			else {
				std::cout << "FALSE" << std::endl;
			}
		}
		else {
			std::cout << "FALSE" << std::endl;
		}
	}
	else {
		std::cout << "FALSE" << std::endl;
	}
	return 0;
}