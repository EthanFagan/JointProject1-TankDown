// @Author Ethan Fagan
// C00232277
// 15/11/17
//------------------------------------------------------------------------------------------------------------
// Brief: a program which asks the user for 10 numbers, then outputs the sum, average and the highest and lowest values
//------------------------------------------------------------------------------------------------------------
// est time: 20 mins
// time taken: 22 mins
// known bugs: no validation on user input

#include <iostream>

int main6()
{
	int numCount{ 0 };// the count that controls the loop
	int numTotal{ 0 };// the total of all the numbers entered
	double numAverage{ 0.0 };// the average of all the numbers entered
 	int numHighest{ 0 };// the highest of all the numbers entered
	int numLowest{ 0 };// the lowest of all the numbers entered
	int numEntered{ 0 };// a number, entered by the user
	double divider{ 10.0 }; // divider for the average calc

	// loop
	for (numCount = 1; numCount <= 10; numCount++)
	{
		std::cout << "Please enter a number between 1 and 100" << std::endl;
		std::cin >> numEntered;
		numTotal = numTotal + numEntered;
		
		// prevents values not inbetween 1 - 100 being entered
		if (numEntered < 0 || numEntered > 100)
		{
			std::cout << "ERROR, values are invlaid" << std::endl;
			break;
		}
		
		// assigns the first lowest value
		if (numCount == 1)
		{
			numLowest = numEntered;
		}

		// finds the lowest value
		if (numEntered < numLowest)
		{
			numLowest = numEntered;
		}
		
		// finds the highest value
		if (numEntered > numHighest)
		{
			numHighest = numEntered;
		}
	}

	// outputs the results
	numAverage =  numTotal / divider;
	std::cout << "The sum of these numbers was - " << numTotal << std::endl;
	std::cout << "The average was - " << numAverage << std::endl;
	std::cout << "The highest value entered was " << numHighest << " and the lowest was " << numLowest << std::endl;
	
	
	system("pause");
	return 0;
}