
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "LblShape.h"
#include <cstring>
using namespace std;
namespace sdds {
	const char* LblShape::label()const {
		return m_label;
	}
	LblShape::LblShape() {
		m_label = nullptr;
	}
	LblShape::LblShape(const char* label) {
		delete[]m_label;
		m_label = nullptr;
		int allocate = strlen(label);
		m_label = new char[(allocate)+1];
		strcpy(m_label, label);
	}
	LblShape::~LblShape() {
		delete[]m_label;
		m_label = nullptr;
	}
	void LblShape::setLabel(const char* label) {
		delete[]m_label;
		m_label = nullptr;
		int allocate = strlen(label);
		m_label = new char[(allocate) + 1];
		strcpy(m_label, label);
	}

	void LblShape::getSpecs(std::istream& is) {
		char a[100];
		is.getline(a, 99, ',');
		const char* b;
		b = a;
		setLabel(b);
	}
}
