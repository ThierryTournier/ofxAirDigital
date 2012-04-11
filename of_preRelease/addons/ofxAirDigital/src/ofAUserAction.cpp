#include "StdAfx.h"
#include "ofAUserAction.h"


ofAUserAction::ofAUserAction(void)
{
	isRecording = false;
	isOnZone = false;
	isReady=false;
	movementName="";
	m_hMutex = CreateMutex( NULL,false,convert("MessageBufferMutex"));

	if ( m_hMutex == NULL )
	{
		cout<<"CreateMutex() failed in MessageBuffer ctor."<<endl;
	}

	// Create the auto-reset event.
	m_hEvent = CreateEvent( NULL,     // no security attributes
		FALSE,    // auto-reset event
		FALSE,    // initial state is non-signaled
		convert("MessageBufferEvent"));    // lpName

	if (m_hEvent == NULL) 
	{
		cout<<"CreateEvent() failed in MessageBuffer ctor."<<endl ;
	}
}

LPCWSTR ofAUserAction::convert(char *a){
	BSTR r;
	int l = lstrlenA(a);
	r = SysAllocStringLen(NULL, l);
	::MultiByteToWideChar(CP_ACP, 0, a, l, r, l);
	return r;
}

ofAUserAction::~ofAUserAction(void)
{
}

void ofAUserAction::setIsRecording(bool b){
	 DWORD   dwWaitResult = WaitForSingleObject( m_hMutex, INFINITE ); // Jaeschke's Monitor::Enter(this)
             
	if ( dwWaitResult != WAIT_OBJECT_0 )
        {
            cout<< "WaitForSingleObject() failed in MessageBuffer::SetMessage()."<<endl;
            return;
        } 
	isRecording=b;
	 if ( ! SetEvent( m_hEvent ) )   // Jaeschke's Monitor::Pulse(this)
        {
            cout<< "SetEvent() failed in SetMessage()"<<endl;
        }

      
        if ( ! ReleaseMutex( m_hMutex ))   // Jaeschke's Monitor::Exit(this)
        { 
            cout<<"ReleaseMutex() failed in MessageBuffer::SetMessage()."<<endl;
        }

}
	
void ofAUserAction::setIsOnZone(bool b){
	 DWORD   dwWaitResult = WaitForSingleObject( m_hMutex, INFINITE ); // Jaeschke's Monitor::Enter(this)
             
	if ( dwWaitResult != WAIT_OBJECT_0 )
        {
            cout<< "WaitForSingleObject() failed in MessageBuffer::SetMessage()."<<endl;
            return;
        } 
	isOnZone=b;
	 if ( ! SetEvent( m_hEvent ) )   // Jaeschke's Monitor::Pulse(this)
        {
            cout<< "SetEvent() failed in SetMessage()"<<endl;
        }

      
        if ( ! ReleaseMutex( m_hMutex ))   // Jaeschke's Monitor::Exit(this)
        { 
            cout<<"ReleaseMutex() failed in MessageBuffer::SetMessage()."<<endl;
        }

	
}

void ofAUserAction::setIsReady(bool b){
	 DWORD   dwWaitResult = WaitForSingleObject( m_hMutex, INFINITE ); // Jaeschke's Monitor::Enter(this)
             
	if ( dwWaitResult != WAIT_OBJECT_0 )
        {
            cout<< "WaitForSingleObject() failed in MessageBuffer::SetMessage()."<<endl;
            return;
        } 
	isReady=b;
	 if ( ! SetEvent( m_hEvent ) )   // Jaeschke's Monitor::Pulse(this)
        {
            cout<< "SetEvent() failed in SetMessage()"<<endl;
        }

      
        if ( ! ReleaseMutex( m_hMutex ))   // Jaeschke's Monitor::Exit(this)
        { 
            cout<<"ReleaseMutex() failed in MessageBuffer::SetMessage()."<<endl;
        }

	
}
	
void ofAUserAction::setMovementName(string s){
	 DWORD   dwWaitResult = WaitForSingleObject( m_hMutex, INFINITE ); // Jaeschke's Monitor::Enter(this)
             
	if ( dwWaitResult != WAIT_OBJECT_0 )
        {
            cout<< "WaitForSingleObject() failed in MessageBuffer::SetMessage()."<<endl;
            return;
        } 
	movementName=s;
	 if ( ! SetEvent( m_hEvent ) )   // Jaeschke's Monitor::Pulse(this)
        {
            cout<< "SetEvent() failed in SetMessage()"<<endl;
        }

      
        if ( ! ReleaseMutex( m_hMutex ))   // Jaeschke's Monitor::Exit(this)
        { 
            cout<<"ReleaseMutex() failed in MessageBuffer::SetMessage()."<<endl;
        }
	
}
bool ofAUserAction::getIsRecording(){
	return isRecording;
}
bool ofAUserAction::getIsOnZone(){
	return isOnZone;
}
bool ofAUserAction::getIsReady(){
	return isReady;
}
string ofAUserAction::getMovementName(){
	return movementName;
}