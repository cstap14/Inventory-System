#pragma once
#include "Paint.h"
//#include <iostream>

class HighGloss : public Paint
{

public:

	HighGloss() : Paint()
	{
		std::cout << "\n\nNow in HighGloss default constructor...\n\n";
	}

	HighGloss(std::string clr, float gl, float numPaint) : Paint(clr, gl, numPaint)
	{
		std::cout << "\n\nNow in HighGloss 3 argument constructor...\n\n";
	}

	~HighGloss()
	{
		std::cout << "\n\nNow in HighGloss destructor...\n\n";
		//std::system("pause");
	}

	void help() override
	{
		std::cout << "High-glass is the shiniest type of paint we offer, and also the most durable\n";
		std::cout << "and washable.It can also be used as an outdoor paint!It is best for doors, trim, and cabinetry\n";
		std::cout << "as it can show many imperfections if applied incorrectly.\n\n";
	}

};
