#pragma once
#include "Paint.h"
//#include <iostream>

class Satin : public Paint
{

public:

	Satin() : Paint()
	{
		std::cout << "\n\nNow in Satin default constructor...\n\n";
	}

	Satin(std::string clr, float gl, float numPaint) : Paint(clr, gl, numPaint)
	{
		std::cout << "\n\nNow in Satin 3 argument constructor...\n\n";
	}

	~Satin()
	{
		std::cout << "\n\nNow in Satin destructor...\n\n";
		//std::system("pause");
	}

	void help() override
	{
		std::cout << "Satin paint is the most common interior paint.  It is easier to clean than flat or \n";
		std::cout << "eggshell, but it can be very tricky to touch - up if errors are made during application.This type of\n";
		std::cout << "paint is great for high - traffic areas.\n\n";
	}

};
