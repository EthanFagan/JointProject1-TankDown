// @Author Ethan Fagan
// C00232277
// 29/11/17
//---------------------------------------------------------------------------------------------------------
// Brief: assigns random ints(1-15) to an array, then display the largest, smallest, the sum and the average of these numbers
//---------------------------------------------------------------------------------------------------------
// est time: 25 mins
// time taken: 30 mins
// known bugs: no known errors

#include<iostream>
#include<time.h>

int main3()
{
	srand(static_cast<unsigned>(time(NULL)));// allows numbers to be generated at complete random
	const int maxNumbers{ 8 };// the maximum amount of loops
	int randomNumbers[8];// the array for storing values
	double numTotal{ 0.0 };// the sum of all the values entered
	int numHighest{ 0 };// the highest of the values entered
	int numLowest{ 0 };// the lowest of the values entered
	double numAverage{ 0 };// the average of the values entered
	int count{ 0 };// count which controls the loop

	// loop
	for (count = 0; count < maxNumbers; count++)
	{
		randomNumbers[count] = rand() % 15 + 1;
		numTotal = numTotal + randomNumbers[count];
		std::cout << randomNumbers[count] << std::endl;
		
		// assigns the first lowest value
		if (count == 0)
		{
			numLowest = randomNumbers[count];
		}

		// finds the lowest value entered
		if (randomNumbers[count] < numLowest)
		{
			numLowest = randomNumbers[count];
		}

		// finds the highest value entered
		if (randomNumbers[count] > numHighest)
		{
			numHighest = randomNumbers[count];
		}

	}
	// finds the average
	numAverage = numTotal / (count + 1);

	std::cout << "Highest num = " << numHighest << std::endl;
	std::cout << "Lowest num = " << numLowest << std::endl;
	std::cout << "Average of nums = " << numAverage << std::endl;

	system("pause");
	return 0;
}