/// <summary>
/// Vector 3 class
/// Ethan Fagan
/// C00232277
/// </summary>
#include "MyVector3.h"
#include <string.h>
#define PI           3.14159265358979323846

/// <summary>
/// Default constructor set all 3 values to zero
/// </summary>
MyVector3::MyVector3() :
	x{ 0.0 },
	y{ 0.0 },
	z{ 0.0 }
{
}

MyVector3::MyVector3(double t_x, double t_y, double t_z) :

	x{ t_x },
	y{ t_y },
	z{ t_z }
{
}

MyVector3::MyVector3(sf::Vector3i t_sfvector) :

	x{ static_cast<double>(t_sfvector.x) },
	y{ static_cast<double>(t_sfvector.y) },
	z{ static_cast<double>(t_sfvector.z) }
{
}

MyVector3::MyVector3(sf::Vector3f t_sfvector) :

	x{ static_cast<double>(t_sfvector.x) },
	y{ static_cast<double>(t_sfvector.y) },
	z{ static_cast<double>(t_sfvector.z) }
{
}


MyVector3::MyVector3(sf::Vector2i t_sfvector) :

	x{static_cast<double>(t_sfvector.x)},
	y{static_cast<double>(t_sfvector.y)},
	z{0.0}
{
}

MyVector3::MyVector3(sf::Vector2f t_sfvector) :

	x{ static_cast<double>(t_sfvector.x) },
	y{ static_cast<double>(t_sfvector.y) },
	z{ 0.0 }
{
}

MyVector3::MyVector3(sf::Vector2u t_sfvector) :

	x{ static_cast<double>(t_sfvector.x) },
	y{ static_cast<double>(t_sfvector.y) },
	z{ 0.0 }
{
}

MyVector3::~MyVector3()
{
}

std::string MyVector3::toString()
{
	const std::string output = "[" + std::to_string(x) + "," + std::to_string(y) + "," + std::to_string(z) + "]";
	return output;
}

// finds the length of a vector
double MyVector3::length() const
{
	const double answer = std::sqrt(x* x + y* y + z* z);
	return answer;
}

// finds the length of a vector squared
double MyVector3::lengthSquared() const
{
	const double result = std::pow(x, 2.0) + std::pow(y, 2.0) + std::pow(z, 2.0);

	return result;
}

// finds the dot product of two 3d vectors
double MyVector3::dot(MyVector3 t_other) const
{
	const double result = x * t_other.x + y * t_other.y + z * t_other.z;
	return result;
}

// finds the angle between two 3d vectors
double MyVector3::angleBetween(MyVector3 t_other) const
{
	double lineOne = dot(t_other);
	double lineTwo = length() * t_other.length();
	double angle;
	if (lineTwo != 0)
	{
		double answer = lineOne / lineTwo;
		if (answer > 1) answer = 1;
		if (answer < -1) answer = -1;
		angle = std::acos(answer);
		const double angleDegrees = angle * 180.0 / PI;
		return angleDegrees;
	}
	return { 0.0 };
}

// normalises 3d vectors
void MyVector3::normalise()
{
	const double length = std::sqrt(x * x + y * y + z * z);
	x = x / length;
	y = y / length;
	z = z / length;
}

// gets the unit vector
MyVector3 MyVector3::unit() const
{
	double newX = { 0.0 };
	double newY = { 0.0 };
	double newZ = { 0.0 };

	double length = std::sqrt(x*x + y*y + z*z);
	if (length != 0.0)
	{
		newX = x / length;
		newY = y / length;
		newZ = z / length;
	}
	return MyVector3(newX, newY, newZ);
}

// projects one 3d vector across another
MyVector3 MyVector3::projection(const MyVector3 t_other) const
{
	double lengthSq = lengthSquared();
	double dotProduct = dot(t_other);
	double scale{ 1.0 };
	if (lengthSq != 0)
	{
		scale = dotProduct / lengthSq;
	}
	return this->operator*(scale);
}

// finds the rejection of a projection
MyVector3 MyVector3::rejection(const MyVector3 t_other) const
{
	return t_other - projection(t_other);
}

// finds the cross product of 3d vectors
MyVector3 MyVector3::crossProduct(const MyVector3 t_other) const
{
	double y_z = y*t_other.z - z*t_other.y;
	double x_z = z *t_other.x - x*t_other.z;
	double x_y = x*t_other.y - y*t_other.x;


	return MyVector3(y_z, x_z, x_y);
}


/// <summary>
/// default destructor
/// nothing to release because we only have
/// primitive type data
/// </summary>
MyVector3::~MyVector3()
{
}

/// <summary>
/// 
/// </summary>
/// <returns>the vector as a string surrounded by square brackets and seperated by commas</returns>
std::string MyVector3::toString()
{
	const std::string output = "[" + std::to_string(x) + "," + std::to_string(y) + "," + std::to_string(z) + "]";
	return output;
}

// checks for equality
bool MyVector3::operator==(const MyVector3 t_right) const
{
	if (x == t_right.x && y == t_right.y && z == t_right.z)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// checks for non-equality
bool MyVector3::operator!=(const MyVector3 t_right) const
{
	return !(this->operator==(t_right));
}

// adds two 3d vectors
MyVector3 MyVector3::operator + (const MyVector3 t_right) const
{
	return MyVector3(x + t_right.x, y + t_right.y, z + t_right.z);
}

// subtracts two 3d vectors
MyVector3 MyVector3::operator - (const MyVector3 t_right) const
{
	return MyVector3{ -x,-y,-z };
}

void MyVector3::reverseX()
{
	x = -x;
}

void MyVector3::reverseX()
{
	y = -y;
}
// divides two 3d vectors
MyVector3 MyVector3::operator / (const double t_divisor) const
{    
	if (t_divisor != 0)
	{
		return MyVector3(x / t_divisor, y / t_divisor, z / t_divisor);
	}
	else
	{
		return MyVector3{};
	}
}

// multiplies two 3d vectors
MyVector3 MyVector3::operator * (const double t_scalar) const
{
	return MyVector3(x * t_scalar, y * t_scalar, z * t_scalar);
}

// 
MyVector3 MyVector3::operator += (const MyVector3 t_right)
{
	x += t_right.x;
	y += t_right.y;
	z += t_right.z;

	return MyVector3{ x,y,z };
}

// 
MyVector3 MyVector3::operator -= (const MyVector3 t_right)
{
	x -= t_right.x;
	y -= t_right.y;
	z -= t_right.z;

	return MyVector3{ x,y,z };
}

// converts vectors into negatives
MyVector3 MyVector3:: operator-()
{
	double answerX = x* -1;
	double answerY = y* -1;
	double answerZ = z* -1;

	return MyVector3(answerX, answerY, answerZ);
}