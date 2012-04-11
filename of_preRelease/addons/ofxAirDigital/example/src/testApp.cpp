#include "stdafx.h"
#include "testApp.h"
#include "ofAUniverse.h"
#include "ofASpace.h"
#include "ofASpaceClosed.h"
#include "ofARoom.h"
#include "ofAObject.h"
#include "ofAGestureReconizer.h"
#include "ofADisplayManager.h"


#include  <gl\GLU.h>
#include <Windows.h>
#include <gl\GL.h>


GLfloat lightOnePosition[] = {40.0, 40, 100.0, 0.0};
GLfloat lightOneColor[] = {0.99, 0.99, 0.99, 1.0};

GLfloat lightTwoPosition[] = {-40.0, 40, 100.0, 0.0};
GLfloat lightTwoColor[] = {0.99, 0.99, 0.99, 1.0};


//--------------------------------------------------------------
void testApp::setup(){
	
	
	//init opengl
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity(); //Reset the camera
    gluPerspective(70.0,(double)ofGetScreenWidth() /(double)ofGetScreenHeight(),1.0, 1000.0);
	ofBackground(0,0,0);
	ofSetVerticalSync(true);

    //some model / light stuff
    glEnable (GL_DEPTH_TEST);
    glShadeModel (GL_SMOOTH);

    /* initialize lighting */
    glLightfv (GL_LIGHT0, GL_POSITION, lightOnePosition);
    glLightfv (GL_LIGHT0, GL_DIFFUSE, lightOneColor);
    glEnable (GL_LIGHT0);
    glLightfv (GL_LIGHT1, GL_POSITION, lightTwoPosition);
    glLightfv (GL_LIGHT1, GL_DIFFUSE, lightTwoColor);
    glEnable (GL_LIGHT1);
    glEnable (GL_LIGHTING);
    glColorMaterial (GL_FRONT_AND_BACK, GL_DIFFUSE);
    glEnable (GL_COLOR_MATERIAL);

   // glEnable(GL_TEXTURE_2D);

	//basic test of the universe creation
	ofAUniverse test(3);
	test.listUniv();
	

	// set hands
	handr.setHand();
	handl.setHand();
	handr.setRight();
	handl.setLeft();
	handr.EnableShape();
	handr.LoadShape();
	handl.EnableShape();
	handl.LoadShape();


	//shared variables
	handCoordinates=new ofAHandCoordinates();
	userAction=new ofAUserAction();
	
	//thread Kinect
	cout<<"thread kinect"<<endl;
    
	CSkeletalViewerApp* kinect = new CSkeletalViewerApp(handCoordinates);  
	HANDLE hthkinect;
	unsigned  uikinectThreadID;
    hthkinect = (HANDLE)_beginthreadex( NULL,
                                          0,
                                          CSkeletalViewerApp::kinectStaticEntryPoint,
                                          kinect,
                                          CREATE_SUSPENDED,
                                          &uikinectThreadID );
    if ( hthkinect == 0 )
        cout<<"Failed to create producer thread"<<endl;

	//thread gestureReconizer
	cout<<"thread gestureReconizer"<<endl;
	
	ofAGestureReconizer* gr = new ofAGestureReconizer(handCoordinates, userAction);
    HANDLE   hthGestureReconizer;
    unsigned  uiiGestureReconizerThreadID;
    hthGestureReconizer = (HANDLE)_beginthreadex( NULL,
                                          0,
                                          ofAGestureReconizer::ofAGestureReconizerStaticEntryPoint,
                                          gr,
                                          CREATE_SUSPENDED, // so we can later call ResumeThread()
                                          &uiiGestureReconizerThreadID );
    if ( hthGestureReconizer == 0 )
        cout<<"Failed to create ihm thread"<<endl;   

	ResumeThread( hthGestureReconizer);
	 
	  
	ResumeThread( hthkinect );
	
	//font
	ofTrueTypeFont::setGlobalDpi(72);
	verdana14.loadFont("verdana.ttf", 14, true, true);
	verdana14.setLineHeight(18.0f);
	verdana14.setLetterSpacing(1.037);

}

//--------------------------------------------------------------
void testApp::update(){
	
	// connection of the hands positions with Kinect
	handr.setpos_x((handCoordinates->getXr()-43)/13*ofGetWidth());
	handr.setpos_y(ofGetHeight()-((handCoordinates->getYr()-41)/17*ofGetHeight()));
	handr.setpos_z((handCoordinates->getZr()-50)/6*(-1000));

	handl.setpos_x((ofGetWidth()-((handCoordinates->getXl()-43))/13*ofGetWidth()));
	handl.setpos_y(ofGetHeight()-((handCoordinates->getYl()-41)/17*ofGetHeight()));
	handl.setpos_z((handCoordinates->getZl()-50)/6*(-1000));

	//test of an object creation and tests in order to see if we can select it and if we can move it
	/*obj.check(handr, handl,userAction->getMovementName());
	if(obj.selected)
	{
		obj.setpos_x((ofGetWidth()-((handCoordinates->getXl()-43))/13*ofGetWidth()));
		obj.setpos_y(ofGetHeight()-((handCoordinates->getYl()-41)/17*ofGetHeight()));
		obj.setpos_z((handCoordinates->getZl()-50)/6*(-1000));
	}*/
}
	
//--------------------------------------------------------------
void testApp::draw(){

	toto.showMovementIndicator(userAction->getIsOnZone(),userAction->getIsRecording(), userAction->getIsReady());
	toto.showMovementName(userAction->getMovementName(), verdana14);
	toto.showHandCoord((handCoordinates->getXr()-43)/13*ofGetWidth(),ofGetHeight()-((handCoordinates->getYr()-41)/17*ofGetHeight()),(handCoordinates->getZr()-50)/6*(-1000),handCoordinates->getXl(),handCoordinates->getYl(),handCoordinates->getZl(),verdana14);
	toto.draw();
	//draw elements
	handr.draw();
	handl.draw();
	obj.draw();
	
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}