// @Author Ethan Fagan
// C00232277
// 13/11/17
//-----------------------------------------------------------------------------------------------------------
// Brief: program that uses loops to generate and display 10 random numbers
//-----------------------------------------------------------------------------------------------------------
// est time: 10 mins
// time taken: 12 mins
// known bugs: no known errors

#include<iostream>
#include<time.H>

int main1()
{
	srand(static_cast<unsigned>(time(NULL)));

	int numCount{ 1 };// the count that controls when the loop will finish
	int numGenerated{ 0 };// the randomly generated number
	
	std::cout << "Your 10 numbers are...";

	// the loop which controls the outputting of the numbers
	while (numCount <= 10)
	{
		numGenerated = rand() % 100 + 1;
		std::cout << numGenerated << " ,";
		numCount = numCount++;
	}


	system("pause");
	return 0;
}