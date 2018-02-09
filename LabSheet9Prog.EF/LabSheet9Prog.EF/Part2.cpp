// @Author Ethan Fagan
// C00232277
// 13/11/17
//---------------------------------------------------------------------------------------------------------
// Brief: program that finds 10 even numbers between 1-100, adds them and displays them on screen
//---------------------------------------------------------------------------------------------------------
// est time: 25 mins
// time taken:  18 mins
// known bugs: no known errors

#include<iostream>
#include<time.H>

int main2()
{
	srand(static_cast<unsigned>(time(NULL)));

	int numCount{ 1 };// the count that controls when the loop will end
	int numGenerated{ 0 };// the randomly generated number
	int numTotal{ 0 };// a total of all the numbers generated added together

	// the loop which controls the outputting of the results
	while (numCount <= 10)
	{
		numGenerated = rand() % 50 + 1;
		numGenerated = numGenerated * 2;
		std::cout << numGenerated << " ,";
		numCount = numCount + 1;
		numTotal = numTotal + numGenerated;
	}

	std::cout << "The total is " << numTotal << std::endl;
	system("pause");
	return 0;
}