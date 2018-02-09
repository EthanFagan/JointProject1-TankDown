//@Author Ethan Fagan
//@29/09/17
//@Brief: a program to calculate the angle between two points(player character to enemy?)
//est time:2 hours
//completion time:1:45
//no known issues
//

#include <iostream>


int main()
{
	int xValue{ 0 };
	int yValue{ 0 };
	double angleDegrees{ 0.0 };
	double angleRadians{ 0.0 };
	double PI = { 3.141592653 };



	std::cout << "                                    Ethans mildly impressive bearing calculator                                     " << std::endl;
	std::cout << "Please input the x co-ordinate " << std::endl;
	std::cin >> xValue;
	std::cout << "Now, input the y co-ordinate" << std::endl;
	std::cin >> yValue;
	angleRadians = atan2(xValue, yValue);
	angleDegrees = angleRadians * 180 / PI;

	if (angleDegrees <0)
	{
		angleDegrees = angleDegrees + 360;
	}
	std::cout << "The angle to the enemy is " << angleDegrees << " degrees" << std::endl;
	std::cout << "You mildly impressed?" << std::endl;
	


	std::system("pause");
}