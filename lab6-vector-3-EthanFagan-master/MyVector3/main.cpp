/// <summary>
/// Ethan Fagan
/// est time: 10 hours
/// time spent: 8 hours
/// issues : none known
/// 
/// </summary>
#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 

#include <iostream>
#include "MyVector3.h"
#include <SFML\Graphics.hpp>
#include <string>



int main()
{
	//initialsing vectors
	MyVector3 vectorOne{ 1,1,1 };
	MyVector3 vectorTwo{ 2,3,4 };
	MyVector3 vectorThree{};

	std::cout << vectorOne.toString() << std::endl;
	std::cout << "----------------------------" << std::endl;
	std::cout << "Null / default constructor" << std::endl;
	std::cout << "----------------------------" << std::endl;

	// addition of 3d vectors
	std::cout << "----------------------------" << std::endl;
	std::cout << "addition" << std::endl;
	std::cout << "----------------------------" << std::endl;
	vectorThree = vectorOne + vectorTwo;
	std::cout << vectorThree.toString() << std::endl;
	std::cout << MyVector3(3, 4, 5).toString() << std::endl;

	// subtraction of 3d vectors
	std::cout << "----------------------------" << std::endl;
	std::cout << "subtraction" << std::endl;
	std::cout << "----------------------------" << std::endl;
	vectorThree = vectorTwo - vectorOne;
	std::cout << vectorThree.toString() << std::endl;
	std::cout << MyVector3(1, 2, 3).toString() << std::endl;

	// minus equals
	std::cout << "----------------------------" << std::endl;
	std::cout << "minus equals" << std::endl;
	std::cout << "----------------------------" << std::endl;
	vectorTwo -= vectorOne;
	std::cout << vectorTwo.toString() << std::endl;
	std::cout << MyVector3(1, 2, 3).toString() << std::endl;

	//----------------------------------------------------------------------
	vectorOne = MyVector3(1, 1, 1);
	vectorTwo = MyVector3(2, 3, 4);// setting the vectors back to starting values for use in further calculations
								   //----------------------------------------------------------------------

								   // length of a 3d vector
	std::cout << "----------------------------" << std::endl;
	std::cout << "length" << std::endl;
	std::cout << "----------------------------" << std::endl;
	double length = vectorTwo.length();// length found using function
	std::cout << length << std::endl;
	std::cout << "5.38" << std::endl;

	// length of a 3d vector squared
	std::cout << "----------------------------" << std::endl;
	std::cout << "length squared" << std::endl;
	std::cout << "----------------------------" << std::endl;
	double lengthSquared = vectorTwo.lengthSquared();// length found using function
	std::cout << lengthSquared << std::endl;
	std::cout << "29" << std::endl;


	// negative of a vector
	std::cout << "----------------------------" << std::endl;
	std::cout << "negative" << std::endl;
	std::cout << "----------------------------" << std::endl;
	vectorThree = -vectorOne;
	std::cout << vectorThree.toString() << std::endl;
	std::cout << MyVector3(-1, -1, -1).toString() << std::endl;

	// multiplication of 3d vectors
	std::cout << "----------------------------" << std::endl;
	std::cout << "multiplication" << std::endl;
	std::cout << "----------------------------" << std::endl;
	vectorThree = vectorOne * 3;
	std::cout << vectorThree.toString() << std::endl;
	std::cout << MyVector3(3, 3, 3).toString() << std::endl;

	// division of 3d vectors
	std::cout << "----------------------------" << std::endl;
	std::cout << "division" << std::endl;
	std::cout << "----------------------------" << std::endl;
	vectorThree = vectorOne / 2;
	std::cout << vectorThree.toString() << std::endl;
	std::cout << MyVector3(0.5, 0.5, 0.5).toString() << std::endl;

	// angle between two 3d vectors
	std::cout << "----------------------------" << std::endl;
	std::cout << "angle between" << std::endl;
	std::cout << "----------------------------" << std::endl;
	double angleFound = vectorOne.angleBetween(vectorTwo);
	std::cout << angleFound << std::endl;
	std::cout << "64.6" << std::endl;

	// the dot product of 3d vectors
	std::cout << "----------------------------" << std::endl;
	std::cout << "dot product" << std::endl;
	std::cout << "----------------------------" << std::endl;
	double dotProduct = vectorOne.dot(vectorTwo);
	std::cout << dotProduct << std::endl;
	std::cout << "4" << std::endl;

	// one 3d vector projected over another
	std::cout << "----------------------------" << std::endl;
	std::cout << "projection" << std::endl;
	std::cout << "----------------------------" << std::endl;
	vectorThree = vectorTwo.projection(vectorOne);
	std::cout << vectorThree.toString() << std::endl;
	std::cout << MyVector3(0.27, 0.41, 0.55).toString() << std::endl;

	// the cross product
	std::cout << "----------------------------" << std::endl;
	std::cout << "cross product" << std::endl;
	std::cout << "----------------------------" << std::endl;
	vectorThree = vectorOne.crossProduct(vectorTwo);
	std::cout << vectorThree.toString() << std::endl;
	std::cout << MyVector3(1, 2, 1).toString() << std::endl;

	// normalise
	std::cout << "----------------------------" << std::endl;
	std::cout << " normalise" << std::endl;
	std::cout << "----------------------------" << std::endl;
	vectorThree = vectorTwo / vectorTwo.length();
	std::cout << vectorThree.toString() << std::endl;
	std::cout << MyVector3(0.37, 0.55, 0.74).toString() << std::endl;

	// unit
	std::cout << "----------------------------" << std::endl;
	std::cout << " unit " << std::endl;
	std::cout << "----------------------------" << std::endl;
	vectorThree = vectorTwo / vectorTwo.length();
	std::cout << vectorThree.toString() << std::endl;
	std::cout << MyVector3(0.37, 0.55, 0.74).toString() << std::endl;








	std::system("pause");
	return EXIT_SUCCESS;
}


