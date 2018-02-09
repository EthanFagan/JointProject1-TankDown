// @Author Ethan Fagan
// C00232277
// 27/11/17
//----------------------------------------------------------------------------------------------------------
// Brief: a program that asks the user for 10 interger values, and outputs the number of odd and even numbers
//----------------------------------------------------------------------------------------------------------
// est time:30 mins
// time taken:25 mins
// known bugs: no knon errors

#include<iostream>

int main2()
{
	const int maxNumbers{ 9 };
	int userValues[10];// the array which stores the users inputs
	int count;// the count which controls the loop
	int remainder{ 0 };// the remainder of division by 2
	int evenCount{ 0 };// the amount of even numbers entered
	int oddCount{ 0 };// the amount of odd numbers entered

	// loop
	for (count = 0; count < maxNumbers; count++)
	{
		std::cout << "Please enter a whole number" << std::endl;
		std::cin >> userValues[count];

		// stops the user from entering invalid numbers
		while (userValues[count] <= 0)
		{
			std::cout << "Number entered is invalid, please enter a new one" << std::endl;
			std::cin >> userValues[count];
		}

		// finds all the evn numbers entered
		remainder = userValues[count] % 2;
		if (remainder == 0 )
		{
			evenCount = evenCount++;
		}

		// finds all of the odd numbers entered
		else 
		{
			oddCount = oddCount++;
		}
	}
	std::cout << "You entered " << evenCount << " even numbers and " << oddCount << " odd numbers" << std::endl;
	system("pause");
	return 0;
}