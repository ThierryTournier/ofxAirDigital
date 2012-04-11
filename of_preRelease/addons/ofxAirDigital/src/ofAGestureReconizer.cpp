#include "StdAfx.h"
#include "ofAGestureReconizer.h"



ofAGestureReconizer::ofAGestureReconizer(void)
{
}

ofAGestureReconizer::ofAGestureReconizer(ofAHandCoordinates *hc, ofAUserAction *ua)
{
	handCoordinates=hc;
	userAction=ua;
}


ofAGestureReconizer::~ofAGestureReconizer(void)
{
}

void ofAGestureReconizer::process()
{
	int cpt;
	while (true)
	{
		//process
		cpt=0;
		Sleep(30);
		testStartRecording();
		while(userAction->getIsRecording())
		{
			
			cpt++;
			record();

			if (cpt%50==0)
				testStopRecording();

		}
		//Ca a été enregistré
		if(vectorPoints3D.size()!=0)
		{
			//toncode
			if (verifyLine())
			{
				//userAction->setMovementName("droite");
			}
			else
			{
				//userAction->setMovementName("non reconnu");
			}
			vectorPoints3D.clear();
		}
	}
}

void ofAGestureReconizer::testStartRecording()
{
	
	int seconds=1;
	time_t timerstart= time(NULL);
	//si xr compris entre 50+m et 50-m
	
	while(handCoordinates->getXr()<51.5 && handCoordinates->getXr()>48.5 
		&& handCoordinates->getYr()<52.5 && handCoordinates->getYr()>48.5
		&& handCoordinates->getZr()<54.5 && handCoordinates->getZr()>52.5)
	{
		userAction->setIsOnZone(true);
		Sleep(15);
		if((time(NULL)-timerstart) > seconds)
			userAction->setIsReady(true);
	}
	
	
	if (  (time(NULL)-timerstart) > seconds && userAction->getIsOnZone())
	{
		
			userAction->setIsReady(false);
			userAction->setIsRecording(true);

	}
	
	userAction->setIsOnZone(false);

	
}
void ofAGestureReconizer::testStopRecording()
{
	int cpt=0;
	int nframes =21;
	double m=1.5;
	for (int i=1;i<nframes;i++)
	{
		if (vectorPoints3D[vectorPoints3D.size()-i].getX() > (vectorPoints3D[vectorPoints3D.size()-i-1].getX()-m) && vectorPoints3D[vectorPoints3D.size()-i].getX() < (vectorPoints3D[vectorPoints3D.size()-i-1].getX()+m) &&
			vectorPoints3D[vectorPoints3D.size()-i].getY() > (vectorPoints3D[vectorPoints3D.size()-i-1].getY()-m) && vectorPoints3D[vectorPoints3D.size()-i].getY() < (vectorPoints3D[vectorPoints3D.size()-i-1].getY()+m) &&
			vectorPoints3D[vectorPoints3D.size()-i].getZ() > (vectorPoints3D[vectorPoints3D.size()-i-1].getZ()-m) && vectorPoints3D[vectorPoints3D.size()-i].getZ() < (vectorPoints3D[vectorPoints3D.size()-i-1].getZ()+m) )
			cpt++;
		
	}
	if (cpt==(nframes-1) ||vectorPoints3D.size()>200)
	{
		userAction->setIsRecording(false);
		for(int i=0;i<5;i++)
			vectorPoints3D.pop_back();
	}

}

void ofAGestureReconizer::record()
{
	Sleep(14);		
	Point3D p (handCoordinates->getXr(),handCoordinates->getYr(),handCoordinates->getZr());
	vectorPoints3D.push_back(p);

}

bool ofAGestureReconizer::verifyLine()
{
	double m=1.5;
	int dnord,dsud,dest,douest,dpush,dpull;
	dnord=dsud=dest=douest=dpush=dpull=0;
	for (int i=15; i < vectorPoints3D.size(); i++)
	{
		if (vectorPoints3D[i].getX() > vectorPoints3D[0].getX()-m && vectorPoints3D[i].getX() <vectorPoints3D[0].getX()+m 
			&& vectorPoints3D[i].getY() > vectorPoints3D[0].getY()-m && vectorPoints3D[i].getY() <vectorPoints3D[0].getY()+m)
		{
			if ((vectorPoints3D[vectorPoints3D.size()-1].getZ()) > (vectorPoints3D[0].getZ()))
			{
				
				dpush++;
			}
			else if((vectorPoints3D[vectorPoints3D.size()-1].getZ()) < (vectorPoints3D[0].getZ()))
			{
				
				dpull++;
			}
		}
		else if (vectorPoints3D[i].getX() > vectorPoints3D[0].getX()-m && vectorPoints3D[i].getX() <vectorPoints3D[0].getX()+m) 
		{
			if ((vectorPoints3D[vectorPoints3D.size()-1].getY()) > (vectorPoints3D[0].getY()))
			{
				
				dnord++;
			}
			else if ((vectorPoints3D[vectorPoints3D.size()-1].getY()) < (vectorPoints3D[0].getY()))
			{
				
				dsud++;
			}
		}
		else if (vectorPoints3D[i].getY() > vectorPoints3D[0].getY()-m && vectorPoints3D[i].getY() <vectorPoints3D[0].getY()+m)
		{
			if ((vectorPoints3D[vectorPoints3D.size()-1].getX()) > (vectorPoints3D[0].getX()))
			{
				
				dest++;
			}
			else if((vectorPoints3D[vectorPoints3D.size()-1].getX()) < (vectorPoints3D[0].getX()))
			{
				
				douest++;
			}
		}
		
		
	}

	if (dnord==vectorPoints3D.size()-15) 
	{
		userAction->setMovementName("Haut");
		return true;
	}
	else if (dsud==vectorPoints3D.size()-15) 
	{
		userAction->setMovementName("Bas");
		return true;
	}
	else if (dest==vectorPoints3D.size()-15) 
	{
		userAction->setMovementName("Droite");
		return true;
	}
	else if (douest==vectorPoints3D.size()-15) 
	{
		userAction->setMovementName("Gauche");
		return true;
	}
	else if (dpull==vectorPoints3D.size()-15) 
	{
		userAction->setMovementName("Tire");
		return true;
	}
	else if (dpush==vectorPoints3D.size()-15) 
	{
		userAction->setMovementName("Pousse");
		return true;
	}
	return false;
}