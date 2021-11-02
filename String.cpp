#include "String.h"

String::String()
	: str{ nullptr }
{
	str = new char[1];
	str[0] = '\0';
}
String::String(const char* _str){
	if (_str == nullptr) {
		str = new char[1];
		str[0] = '\0';
	}
	else {
		int _strLenth = strlen(_str) +1;
		str = new char(_strLenth);
		
		strcpy_s(str, _strLenth, _str);
	}
}
String::String(const String& _str) {
	int _strLength = strlen(_str.str) + 1;
	str = new char[_strLength];
	strcpy_s(str, _strLength, _str.str);
}

String::String(String&& _str) {
	str = _str.str;
	_str.str = nullptr;
}

std::ostream& operator<<(std::ostream& os, const String& _str) {
	os << _str.str;
	return os;
}
std::istream& operator>>(std::istream& is, String& _str) {
	char* buffer = new char[1000];
	is >> buffer;
	_str = String{ buffer };
	delete[] buffer;
	return is;
}

String& String::operator=(const String& _str) {
	if (this == &_str) {
		return *this;
	}
	delete[] str;
	int _strLength = strlen(_str.str) + 1;
	str = new char[_strLength];
	strcpy_s(str, _strLength, _str.str);
	return *this;
}


String operator+(const String& _str1, const String& _str2) {
	int length = strlen(_str1.str) + strlen(_str2.str) + 1;
	char* buffer = new char[length];
	strcpy_s(buffer, length, _str1.str);
	strcat(buffer, _str2.str);

	String temp{ buffer };

	delete[] buffer;

	return temp;

}

bool operator==(const String& _str1, const String& _str2) {
	bool state = true;
	int length = strlen(_str1.str) - 1;
	for (int x = 0; x < length; ++x) {
		if (_str1.str[x] != _str2.str[x]) {
			state = false;
		}
	}
	return state;
}