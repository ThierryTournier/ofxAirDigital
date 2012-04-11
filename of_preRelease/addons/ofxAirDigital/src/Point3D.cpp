#include "StdAfx.h"
#include "Point3D.h"


Point3D::Point3D(void)
{
	x=0;
	y=0;
	z=0;
}
Point3D::Point3D(double x, double y, double z)
{
	this->x=x;
	this->y=y;
	this->z=z;
}

Point3D::~Point3D(void)
{
}

double Point3D::getX()
{
	return x;
}
double Point3D::getY()
{
	return y;
}
double Point3D::getZ()
{
	return z;
}