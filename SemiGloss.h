#pragma once
#include "Paint.h"
//#include <iostream>

class SemiGloss : public Paint
{

public:
	SemiGloss() : Paint()
	{
		std::cout << "\n\nNow in SemiGloss default constructor...\n\n";
	}

	SemiGloss(std::string clr, float gl, float numPaint) : Paint(clr, gl, numPaint)
	{
		std::cout << "\n\nNow in SemiGloss 3 argument constructor...\n\n";
	}

	~SemiGloss()
	{
		std::cout << "\n\nNow in SemiGloss destructor...\n\n";
		//std::system("pause");
	}

	void help() override
	{
		std::cout << "Semi-gloss is a very shiny and reflective paint.  It is durable and resistant to\n";
		std::cout << "mildew, but will show more imperfections than flat, eggshell, or satin paint.This type of paint is\n";
		std::cout << "great for rooms that have high moisture or high levels of wear and tear.\n\n";
	}

};
