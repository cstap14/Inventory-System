#pragma once
#include "Paint.h"
//#include <iostream>

class Flat : public Paint
{

public:

	Flat() : Paint()
	{
		std::cout << "\n\nNow in Flat default constructor...\n\n";
	}

	Flat(std::string clr, float gl, float numPaint) : Paint(clr, gl, numPaint)
	{
		std::cout << "\n\nNow in Flat 3 argument constructor...\n\n";
	}

	~Flat()
	{
		std::cout << "\n\nNow in Flat destructor...\n\n";
		//std::system("pause");
	}

	void help() override
	{
		std::cout << "Flat paint is less durable with less shine but will provide the most coverage.\n";
		std::cout << "This type of paint is best for low traffic areas.\n\n";
		//system("pause");
	}

};
