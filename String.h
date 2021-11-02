#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include <iostream>


class String
{
public:

	/*ERR : operators keep breaking in delete_scaler.cpp
	when in debug but not when ran in cmd*/
	friend std::ostream& operator<<(std::ostream& os, const String& _str);

	// >> can't handle whitespace
	friend std::istream& operator>>(std::istream& is, String& _str);
	String& operator=(const String& _str);
	friend String operator+(const String& _str1, const String& _str2);
	friend bool operator==(const String& _str1, const String& _str2);

	//constructors
	String();
	String(const char* _str);
	String(const String& _str);
	String(String&& _str);

	~String() { delete str; };

	int length() { return strlen(str); };
	void clear() { str = nullptr; };

private:
	char* str;
};