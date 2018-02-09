// @Author Ethan Fagan
// C00232277
// 13/11/17
//---------------------------------------------------------------------------------------------------------
// Brief:a program that asks the user for a starting and ending number, then displays the total of the sum of the numbers between them
//---------------------------------------------------------------------------------------------------------
// est time: 35 mins
// time taken:
// known bugs: no validation on user input

#include<iostream>

void addNumbers(int startNum, int endNum);// function declaration

int main4()
{
	int startNum{ 0 };// the first number entered by the user
	int endNum{ 0 };// the second number entered by the user

	std::cout << "Please enter a starting number" << std::endl;
	std::cin >> startNum;
	std::cout << "Please enter an ending number" << std::endl;
	std::cin >> endNum;

	// function call
	addNumbers(startNum, endNum);


	system("pause");
	return 0;
}

// function definition
void addNumbers(int t_startNum, int t_endNum)
{
	int numTotal{ 0 };// the total of all the numbers added together
	int numCount{ 0 };// the count which controls the loop

	numCount = t_startNum;

	// the loop that controls the addition of the numbers
	while (numCount <= t_endNum)
	{
		numTotal = numTotal + numCount;
	    numCount = numCount + 1;
		
	}
	std::cout << "The sum of the numbers is " << numTotal << std::endl;
}