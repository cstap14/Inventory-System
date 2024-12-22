#pragma once
#include "Paint.h"
//#include <iostream>

class Eggshell : public Paint
{

public:

	Eggshell() : Paint()
	{
		std::cout << "\n\nNow in Eggshell default constructor...\n\n";
	}

	Eggshell(std::string clr, float gl, float numPaint) : Paint(clr, gl, numPaint)
	{
		std::cout << "\n\nNow in Eggshell 3 argument constructor...\n\n";
	}

	~Eggshell()
	{
		std::cout << "\n\nNow in Eggshell destructor...\n\n";
		//std::system("pause");
	}

	void help() override
	{
		std::cout << "Eggshell paint is more durable that flat paint and has slightly more luster.\n";
		std::cout << "This type of paint is great for places that experience low or medium traffic.\n\n";
	}


};
