// @Author Ethan Fagan
// C00232277
// 15/11/17
//------------------------------------------------------------------------------------------------------------
// Brief: a menu that offers the user conversion rates for a value that they enter
//------------------------------------------------------------------------------------------------------------
// est time: 30 mins
// time taken:31 mins
// known bugs: no known errors

#include<iostream>
 
void fahToCel();// function definition
void celToFah();// function definition
void incToCent();// function definition

int main7()
{
	int menuSelection{ 0 };// the users choice of which menu to access

	// outputs the menu choices to the user and records their choice
	std::cout << "Please input the value for whichever conversion you want performed" << std::endl;
	std::cout << "Fahrenheit to celcius - 1" << std::endl;
	std::cout << "Celcius to fahrenheit - 2" << std::endl;
	std::cout << "Inches to centimeters - 3" << std::endl;
	std::cout << "Exit program - 4" << std::endl;



	std::cin >> menuSelection;

	// identifies which menu they chose
	if (menuSelection > 4 || menuSelection < 1)
	{
		std::cout << "ERROR, value entered is invalid" << std::endl;
	}
	switch (menuSelection)
	{
	case 1:
			 fahToCel();// function call
    break;

	case 2:
			 celToFah();// function call
    break;

	case 3:
			 incToCent();// function call
	break;

	case 4:
			
	break;

	}

	system("pause");
	return 0;
}

void fahToCel()// takes in fahreneheit and returns it in celsius
{
	double fahrenheit{ 0.0 };// the fahrenheit value inputted 
	double celsius{ 0.0 };// the calsius value to be outputted
	const double converter{ 1.8 };// the converter used in this calculation

	std::cout << "Please enter a value in fahrenheit" << std::endl;
	std::cin >> fahrenheit;
	fahrenheit = fahrenheit - 32;
	celsius = (fahrenheit / converter) ;
	std::cout << "Your answer in celsius is " << celsius << std::endl;
}

void celToFah()// takes in celsius and returns it in fahrenheit
{
	double celsius{ 0.0 };// the celsius value entered 
	double fahrenheit{ 0.0 };// the fahrenheit value to be outputted 
	const double converter{ 1.8 };// the converter used in this calculation

	std::cout << "Please enter a value in celsius" << std::endl;
	std::cin >> celsius;
	fahrenheit = (celsius * converter) + 32;
	std::cout << "Your answer in fahrenheit is " << fahrenheit << std::endl;
}

void incToCent()// takes in inches and returns it in centimeters
{
	double inches{ 0.0 };// the value entered in inches
	double centimeters{ 0.0 };// the centimeter value to be outputted
	const double converter{2.54};// the converter used in this calculation

	std::cout << "Please enter a value in inches" << std::endl;
	std::cin >> inches;
	centimeters = inches * converter;
	std::cout << "Your answer in centimeters is " << centimeters << std::endl;
}