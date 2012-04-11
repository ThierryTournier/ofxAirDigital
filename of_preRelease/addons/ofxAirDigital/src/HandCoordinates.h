//this class is use to translate the kinect coordinates to our ofAHandcoordinates shared data
#include "StdAfx.h"
#include "NuiApi.h"

//structur use to easely store the hand coordinates
typedef struct _CoordRLxyz
{
	double xr, yr, zr;
	double xl, yl, zl;
	bool detected;
} CoordRLxyz;

class HandCoordinates
{
	
	CoordRLxyz coord;
public:
	HandCoordinates();
	~HandCoordinates();
		
	void setHands(Vector4 r, Vector4 l, Vector4 origin);
	void setHands(Vector4 r, Vector4 l, Vector4 originr,Vector4 originl);
	void setOnScreen(bool os);
	void setHandRight(Vector4 v);
	void setHandLeft(Vector4 v);
	void translate(Vector4 origin);
	//The hand coordinates are calculate from the coordinates of the shoulder of the user
	void translate(Vector4 originr,Vector4 originl);
	void seti(int i);
	int geti();

	CoordRLxyz getCoord();
	void setCoord(CoordRLxyz c);
	

private:
	int i;
};

