// @Author Ethan Fagan
// C00232277
// 15/11/17
//------------------------------------------------------------------------------------------------------------
// Brief: Program that takes in numbers from the user until they input 0,then displays a total
//------------------------------------------------------------------------------------------------------------
// est time: 10 mins
// time taken: 10 mins
// known bugs: no validation on user input

#include<iostream>

int main5()
{
	int numEntered{ 0 };// the number entered by the user
	int numSum{ 0 };// the total of all the numbers entered by the user

	std::cout << "Please enter your first number" << std::endl;
	std::cin >> numEntered;

	// the loop which allows the user to input as many values as they want
	while (numEntered > 0)
	{
		numSum = numSum + numEntered;

		std::cout << "please enter your next number" << std::endl;
		std::cin >> numEntered;
	}
	std::cout << "The combined total is " << numSum << std::endl;

	system("pause");
	return 0;
}