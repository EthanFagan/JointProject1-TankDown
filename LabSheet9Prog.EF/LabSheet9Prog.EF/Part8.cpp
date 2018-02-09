// @Author Ethan Fagan
// C00232277
// 15/11/17
//------------------------------------------------------------------------------------------------------------
// Brief:a program that takes in a selected number of numbers(1-10) and gives back the sum, average, highest and lowest
//------------------------------------------------------------------------------------------------------------
// est time: 35 mins
// time taken: 60 minutes
// known bugs: loop is endless

#include<iostream>

int main()
{
	int count{ 0 };// the count that controls the loop
	int numMax{ 0 };// the amount of numbers the user will be entering
	int numTotal{ 0 };// the sum of the numbers entered
	int numEntered{ 0 };// the number just entered
	double numAverage{ 0.0 };// the average of all numbers entered
	int numHighest{ 0 };// the highest number entered
	int numLowest{ 0 };// the lowest number entered
	double divider{ 0.0 };// the divider used to find the average

	// finds the amount for the loop from the user
	std::cout << "Please enter the amount of values you will be using" << std::endl;
	std::cin >> numMax;
	divider = numMax;
	

	// loop
	while(count < numMax)
	{
		std::cout << "Please enter a number between 1 - 10" << std::endl;
		std::cin >> numEntered;
		numTotal = numTotal + numEntered;

		// prevents values not being between 1 - 10
		if (numEntered < 0 || numEntered > 10)
		{
			std::cout << "ERROR, number entered is invalid" << std::endl;
			break;
		}

		// assigns the first lowest value
		if (count == 1)
		{
			numLowest = numEntered;
		}

		// finds the lowest value entered
		if (numEntered < numLowest)
		{
			numLowest = numEntered;
		}

		// finds the highest value
		if (numEntered > numHighest)
		{
			numHighest = numEntered;
		}

	 count++;
	}

	// outputs the results
	numAverage = numTotal / divider;
	std::cout << "The sum of these numbers was - " << numTotal << std::endl;
	std::cout << "The average was - " << numAverage << std::endl;
	std::cout << "The highest value entered was " << numHighest << " and the lowest was " << numLowest << std::endl;

	system("pause");
	return 0;
}