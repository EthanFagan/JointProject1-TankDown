// @Author Ethan Fagan
// C00232277
// 13/11/17
//---------------------------------------------------------------------------------------------------------
// Brief: a program that generates 10 numbers, adds them, finds the largest and smallest and finds their average
//---------------------------------------------------------------------------------------------------------
// est time: 35 mins
// time taken: 45 mins
// known bugs: no known errors

#include <iostream>
#include <time.H>

int main3()
{
	srand(static_cast<unsigned>(time(NULL)));

	int numCount{ 0 };// the count that controls the loop
	int numGenerated{ 0 };// the randomly generated number
	int numTotal{ 0 };// a total of all the numbers generated added together
	double numAverage{ 0.0 };// the average of all the numbers generated
	int numHighest{ 0 };// the highest number that was generated
	int numLowest{ 0 };// the lowest number that was generated

	// the first number is generated
	numLowest = rand() % 100 + 1;
	numTotal = numTotal + numLowest;

	// the loop which controls the ouputting of the values needed
	 while (numCount <= 9)
	{
		numGenerated = rand() % 100 + 1;
		std::cout << numGenerated << " ,";
		numCount = numCount + 1;
		numTotal = numTotal + numGenerated;
		// checks for the lowest number
		if (numGenerated < numLowest)
		{
			numLowest = numGenerated;
		}
		// checks for the highest number
		if (numGenerated > numHighest)
		{
			numHighest = numGenerated;
		}
	}
	 // finds the average
	numAverage = numTotal / 10.0;

	std::cout << "The total is... " << numTotal << std::endl;
	std::cout << "The average is..." << numAverage << std::endl;
	std::cout << "The lowest number was..." << numLowest << " and the highest was..." << numHighest << std::endl;
	system("pause");
	return 0;
}