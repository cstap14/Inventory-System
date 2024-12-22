#pragma once
#include <iostream>
#include <random>
#include <fstream>
#include <iomanip>
#include <string>

class Paint
{

public:

	Paint() 
	{
	
		gloss_level = 0;
		color = "";
		std::cout << "\n\nNow in Paint default constructor...\n\n";
	
	}
	Paint(std::string clr, float GL, float numPaint)
	{
		gloss_level = GL;
		color = clr;
		this->numPaint = numPaint;
		std::cout << "\n\nNow in Paint 3 argument constructor...\n\n";
	}

	virtual ~Paint()
	{
		std::cout << "\n\nNow in Paint destructor...\n\n";
		//system("pause");
	}

	void setColor(std::string clr)
	{
		color = clr;
	}

	void setGlossLevel(float GL)
	{
		gloss_level = GL;
	}

	void setNumPaint(float np)
	{
		numPaint = np;
	}

	std::string getColor() const
	{
		return color;
	}

	float getGlossLevel() const
	{
		return gloss_level;
	}

	float getNumPaint() const
	{
		return numPaint;
	}

	virtual void help() = 0;


private:

	std::string color;
	float gloss_level;
	float numPaint;

};
