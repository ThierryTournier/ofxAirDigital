#pragma once
class Point3D
{
public:
	Point3D(void);
	Point3D(double x, double y, double z);
	~Point3D(void);
	double getX();
	double getY();
	double getZ();

private:
	double x,y,z;
};

