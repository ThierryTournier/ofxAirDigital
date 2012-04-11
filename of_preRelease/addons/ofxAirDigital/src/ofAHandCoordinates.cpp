#include "StdAfx.h"
#include "ofAHandCoordinates.h"


ofAHandCoordinates::ofAHandCoordinates(void)
{
	xr=yr=zr=xl=yl=zl=0;
	
	m_hMutex = CreateMutex( NULL,false,convert("MessageBufferMutex"));

	if ( m_hMutex == NULL )
	{
		cout<< "CreateMutex() failed in MessageBuffer ctor."<<endl ;
	}

	// Create the auto-reset event.
	m_hEvent = CreateEvent( NULL,     // no security attributes
		FALSE,    // auto-reset event
		FALSE,    // initial state is non-signaled
		convert("MessageBufferEvent"));    // lpName

	if (m_hEvent == NULL) 
	{
		cout<< "CreateEvent() failed in MessageBuffer ctor."<<endl;
	}
}


ofAHandCoordinates::~ofAHandCoordinates(void)
{

}

LPCWSTR ofAHandCoordinates::convert(char *a){
	BSTR r;
	int l = lstrlenA(a);
	r = SysAllocStringLen(NULL, l);
	::MultiByteToWideChar(CP_ACP, 0, a, l, r, l);
	return r;
}

void ofAHandCoordinates::setCoord(double Xr,double Yr,double Zr,double Xl,double Yl,double Zl)
{
	 DWORD   dwWaitResult = WaitForSingleObject( m_hMutex, INFINITE ); // Jaeschke's Monitor::Enter(this)
             
	if ( dwWaitResult != WAIT_OBJECT_0 )
        {
            cout<< "WaitForSingleObject() failed in MessageBuffer::SetMessage()."<<endl;
            return;
        } 
        

		xr=Xr;
		yr=Yr;
		zr=Zr;
		xl=Xl;
		yl=Yl;
		zl=Zl;
		
        if ( ! SetEvent( m_hEvent ) )   // Jaeschke's Monitor::Pulse(this)
        {
            cout<< "SetEvent() failed in SetMessage()"<<endl;
        }

      
        if ( ! ReleaseMutex( m_hMutex ))   // Jaeschke's Monitor::Exit(this)
        { 
            cout<<"ReleaseMutex() failed in MessageBuffer::SetMessage()."<<endl;
        }


}

double ofAHandCoordinates::getXr(){
	return xr;
}
double ofAHandCoordinates::getYr(){
	return yr;
}
double ofAHandCoordinates::getZr(){
	return zr;
}
double ofAHandCoordinates::getXl(){
	return xl;
}
double ofAHandCoordinates::getYl(){
	return yl;
}
double ofAHandCoordinates::getZl(){
	return zl;
}