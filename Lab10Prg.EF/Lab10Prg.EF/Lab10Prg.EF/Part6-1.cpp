// @Author Ethan Fagan
// C00232277
// 06/12/2017
//---------------------------------------------------------------------------------------------------------
// Brief:A program that assigns values to two arrays and performs minor checks and calculations on their contents
//---------------------------------------------------------------------------------------------------------
// est time: 30 mins
// time taken: 50 mins mins
// known bugs:

#include<iostream>
#include<string>

    // function declarations-------------------------------------
    void initializeArrays();
	void outputForwardsAndBackwards();
	int findSum();
	void findAverage(int sum);
	void findHighestAndLowest();
	//------------------------------------------------------------

	const int MAX_PLAYERS = 8;
	float noOfPlayers = 8.0;

	std::string namesArray[MAX_PLAYERS];
	int healthArray[MAX_PLAYERS];


	int main()
	{
		int sum{ 0 };// the sum of the health values

		// function calls--------------------------------------------
		initializeArrays();

		outputForwardsAndBackwards();

		sum = findSum();

		findAverage(sum);

		findHighestAndLowest();
		//-----------------------------------------------------------

		system("pause");
		return 0;
	}

	// Initialize the two arrays
	void initializeArrays()
		
	{
		namesArray[0] = "Tom";
		namesArray[1] = "Sam";
		namesArray[2] = "Ann";
		namesArray[3] = "Ki";
		namesArray[4] = "Joe";
		namesArray[5] = "Ray";
		namesArray[6] = "Dave";
		namesArray[7] = "Sue";

		healthArray[0] = 3;
		healthArray[1] = 6;
		healthArray[2] = 2;
		healthArray[3] = 1;
		healthArray[4] = 4;
		healthArray[5] = 6;
		healthArray[6] = 1;
		healthArray[7] = 6;
	}

	// outputs the each players name and health in sequence, both forwards and backwards
	void outputForwardsAndBackwards()
	{
		int index{ 0 };// the count that controls the loop

		for (index = 0; index < MAX_PLAYERS; index++)
		{
			std::cout << namesArray[index] << ", " << healthArray[index] << "  " << std::endl;
		}
		std::cout << "Backwards----------------------------------------------------------------" << std::endl;
		for (index = 7; index >= 0; index--)
		{
			std::cout << namesArray[index] << ", " << healthArray[index] << "  " << std::endl;
		}
	}

	// function that finds the sum of the health values
	int findSum()
	{
		int index{ 0 };// count used to control the loop
		int sumOfPlayerHealth{ 0 };// the overall total of players' health

		for (index = 0; index < MAX_PLAYERS; index++)
		{
			sumOfPlayerHealth = sumOfPlayerHealth + healthArray[index];
		}
		return sumOfPlayerHealth;
	}

	// function that finds the average of the health values
	void findAverage(int t_sum)
	{
		float averageOfPlayerHealth{ 0 };// the average

		averageOfPlayerHealth = t_sum / noOfPlayers;
		
		std::cout << "The average of the players' health is " << averageOfPlayerHealth << " and the sum of them is " << t_sum << std::endl;
	}

	// function that calculates the highest and lowest health values
	void findHighestAndLowest()
	{
		int index{ 0 };
		std::string highestPlayer{ "" };
		int highestPlayerCell{ 0 };
		std::string lowestPlayer{ "" };
		int lowestPlayerCell{ 0 };

		// loop that finds the highest and lowest players
		for (index = 0; index < MAX_PLAYERS; index++)
		{
			if (index == 0)
			{
				lowestPlayer = namesArray[index];
				lowestPlayerCell = index;
			}


			if (healthArray[index] < healthArray[lowestPlayerCell])
			{
				lowestPlayer = namesArray[index];
				lowestPlayerCell = index;
			}
			if (healthArray[index] > healthArray[highestPlayerCell])
			{
				highestPlayer = namesArray[index];
				highestPlayerCell = index;
			}
		}
		std::cout << "Player :" << highestPlayer << " has the highest health" << std::endl;
		std::cout << "Player :" << lowestPlayer << " has the lowest health" << std::endl;
	}
	