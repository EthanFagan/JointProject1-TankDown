// @Author Ethan Fagan
// C00232277
// 27/11/17
//------------------------------------------------------------------------------------------------------------
// Brief: a program that asks the user for 10 intergers, adds them to an array, then displays them forwards and backwards
//------------------------------------------------------------------------------------------------------------
// est time: 25 mins
// time taken: 30 mins
// known bugs: no known bugs

#include<iostream>

int main1()
{
	int userNumbers[10];// the array which stores the users inputs
	int count{ 0 };// the count which controls the loop

	// loop
    for (count = 0; count <=9; count++)
	{
		std::cout << "Please enter a number" << std::endl;
		std::cin >> userNumbers[count];
	}

	// outputs the values in the array in order
	std::cout << userNumbers[0] << ", ";
	std::cout << userNumbers[1] << ", ";
	std::cout << userNumbers[2] << ", ";
	std::cout << userNumbers[3] << ", ";
	std::cout << userNumbers[4] << ", ";
	std::cout << userNumbers[5] << ", ";
	std::cout << userNumbers[6] << ", ";
	std::cout << userNumbers[7] << ", ";
	std::cout << userNumbers[8] << ", ";
	std::cout << userNumbers[9] << std::endl;;

	// outputs the values in the array in reverse order
	std::cout << userNumbers[9] << ", ";
	std::cout << userNumbers[8] << ", ";
	std::cout << userNumbers[7] << ", ";
	std::cout << userNumbers[6] << ", ";
	std::cout << userNumbers[5] << ", ";
	std::cout << userNumbers[4] << ", ";
	std::cout << userNumbers[3] << ", ";
	std::cout << userNumbers[2] << ", ";
	std::cout << userNumbers[1] << ", ";
	std::cout << userNumbers[0] << ", ";

	system("pause");
	return 0;
}