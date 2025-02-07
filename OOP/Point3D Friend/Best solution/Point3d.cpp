#include <iostream>
#include "Vector3d.h"

class Point3d
{
private:
	double m_x{};
	double m_y{};
	double m_z{};

public:
	Point3d(double x = 0.0, double y = 0.0, double z = 0.0)
		: m_x{x}, m_y{y}, m_z{z}
	{

	}

	void print() const
	{
		std::cout << "Point(" << m_x << " , " << m_y << " , " << m_z << ")\n";
	}

    void moveByVector(const Vector3d& v); 
};

// using "::" can add a member function to an existing class OUTSIDE the class :)
void Point3d::moveByVector(const Vector3d& v)
{
		// implement this function as a friend of class Vector3d
        this->m_x = this->m_x + v.m_x;
        this->m_y = this->m_y + v.m_y;
        this->m_z = this->m_z + v.m_z;
}