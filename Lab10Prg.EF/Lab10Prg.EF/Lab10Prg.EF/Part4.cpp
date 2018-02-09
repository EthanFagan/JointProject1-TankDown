// @Author Ethan Fagan
// C00232277
// 29/11/17
//---------------------------------------------------------------------------------------------------------
// Brief: assigns random ints(1-15) to an array, then display the largest, smallest, the sum and the average of these numbers
//---------------------------------------------------------------------------------------------------------
// est time: 10 mins
// time taken: 10 mins
// known bugs: no known errors

#include<iostream>
#include<time.h>

int main4()
{
	srand(static_cast<unsigned>(time(NULL)));// allows numbers to be generated at complete random
	const int MAX_NUMBERS{ 8 };// the maximum amount of loops
	int randomNumbers[8];// the array for storing values
	double numTotal{ 0.0 };// the sum of all the values entered
	int numHighest{ 0 };// the highest of the values entered
	int numLowest{ 0 };// the lowest of the values entered
	double numAverage{ 0 };// the average of the values entered
	int count{ 0 };// count which controls the loop
	int amountOfHighest{ 0 };// amount of the highest value in the array
	int amountOfLowest{ 0 };// amount of the lowest value in the array

	// loop
	for (count = 0; count < MAX_NUMBERS; count++)
	{
		randomNumbers[count] = rand() % 15 + 1;
		numTotal = numTotal + randomNumbers[count];
		std::cout << randomNumbers[count] << std::endl;

		// assigns the first lowest value
		if (count == 0)
		{
			numLowest = randomNumbers[count];
		}

		// checks for repeats of the lowest number
		if (randomNumbers[count] == numLowest)
		{
			amountOfLowest = amountOfLowest++;
		}

		// checks for repeats of the highest number
		if (randomNumbers[count] == numHighest)
		{
			amountOfHighest = amountOfHighest++;
		}

		// finds the lowest value entered
		if (randomNumbers[count] < numLowest)
		{
			numLowest = randomNumbers[count];
			amountOfLowest = 1;
		}

		// finds the highest value entered
		if (randomNumbers[count] > numHighest)
		{
			numHighest = randomNumbers[count];
			amountOfHighest = 1;
		}
		

	}

	// finds the average
	numAverage = numTotal / MAX_NUMBERS;

	// outputs the values found
	std::cout << "Highest num = " << numHighest << std::endl;
	std::cout << "Amount of highest num = " << amountOfHighest << std::endl;
	std::cout << "Lowest num = " << numLowest << std::endl;
	std::cout << "Amount of lowest num = " << amountOfLowest << std::endl;
	std::cout << "Average of nums = " << numAverage << std::endl;

	system("pause");
	return 0;
}