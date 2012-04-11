#include "stdafx.h"
#include "HandCoordinates.h"


HandCoordinates::HandCoordinates()
{
	coord.detected=false;
	coord.xl=coord.yl=coord.zl=coord.xr=coord.yr=coord.zr=0;

	

}

HandCoordinates::~HandCoordinates()
{
}

void HandCoordinates::setOnScreen(bool os){
	coord.detected=os;
	if(!os)
	{
		coord.xr=0;
		coord.yr=0;
		coord.zr=0;
		coord.xl=0;
		coord.yl=0;
		coord.zl=0;
	}	
}
	
void HandCoordinates::setHands(Vector4 r, Vector4 l, Vector4 origin)
{
	setHandRight(r);
	setHandLeft(l);
	translate(origin);
}
void HandCoordinates::setHands(Vector4 r, Vector4 originr, Vector4 l, Vector4 originl)
{
	setHandRight(r);
	setHandLeft(l);
	translate(originr,originl);
}
void HandCoordinates::setHandRight(Vector4 v){
	coord.xr=v.x;
	coord.yr=v.y;
	coord.zr=v.z;
}

void HandCoordinates::setHandLeft(Vector4 v){
	coord.xl=v.x;
	coord.yl=v.y;
	coord.zl=v.z;
}

void HandCoordinates::translate(Vector4 origin){

	   
	   coord.xl =(origin.x-coord.xl);
      
       coord.yl =(coord.yl-origin.y);
	 
       coord.zl = (origin.z-coord.zl);

       coord.xr =-(origin.x-coord.xr);
      
       coord.yr =(coord.yr-origin.y);
	 
       coord.zr =(origin.z-coord.zr);

	  
	   
	   coord.xl = (4.4 + coord.xl)*100/8.8;
      
       coord.yl = (3.2 + coord.yl)*100/6.4;
	 
       coord.zl = (4+coord.zl)*100/8;

       coord.xr = (4.4 + coord.xr)*100/8.8;
      
       coord.yr = (3.2 + coord.yr)*100/6.4;
	 
       coord.zr = (4+coord.zr)*100/8;
}
void HandCoordinates::translate(Vector4 originr, Vector4 originl)
{
	   coord.xl =(originl.x-coord.xl);
      
       coord.yl =(coord.yl-originl.y);
	 
       coord.zl = (originl.z-coord.zl);

       coord.xr =-(originr.x-coord.xr);
      
       coord.yr =(coord.yr-originr.y);
	 
       coord.zr =(originr.z-coord.zr);

	   coord.xl = (4.4 + coord.xl)*100/8.8;
      
       coord.yl = (3.2 + coord.yl)*100/6.4;
	 
       coord.zl = (4+coord.zl)*100/8;

       coord.xr = (4.4 + coord.xr)*100/8.8;
      
       coord.yr = (3.2 + coord.yr)*100/6.4;
	 
       coord.zr = (4+coord.zr)*100/8;
}

 void HandCoordinates::setCoord(CoordRLxyz c){
		coord=c;
 }

 CoordRLxyz HandCoordinates::getCoord(){
	return coord;
}

 void HandCoordinates::seti(int i){
	 this->i=i;
 }

 int HandCoordinates::geti(){
	 return this->i;
 } 