#pragma once
//This class is use to share the coordinates of hand between the three threads of the project, a mutex is use to protect data to be read and write at the same time
#include <windows.h>
#include <iostream>
using namespace std;
class ofAHandCoordinates
{
	HANDLE m_hMutex;
	HANDLE m_hEvent;

	double xr,yr,zr;
	double xl,yl,zl;

public:


	ofAHandCoordinates(void);
	~ofAHandCoordinates(void);
	
	LPCWSTR convert(char *a);

	/**getter & setter**/
	void setCoord(double Xr,double Yr,double Zr,double Xl,double Yl,double Zl);
	double getXr();
	double getYr();
	double getZr();
	double getXl();
	double getYl();
	double getZl();


private:
	//Coordonnées des mains
	
};