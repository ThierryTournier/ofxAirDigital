#include "stdafx.h"
#include "ofMain.h"
#include "testApp.h"
#include "ofAppGlutWindow.h"

//#include "../../../../../of_preRelease_v007_vs2010/libs/openFrameworks/gl/ofTexture.h"


//========================================================================
int main( ){

    ofAppGlutWindow window;
	ofSetupOpenGL(&window, 1024,768, OF_WINDOW);			// <-------- setup the GL context
	ofSetFrameRate(60);
	glShadeModel(GL_SMOOTH);
	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN	
	// pass in width and height too:
	ofRunApp( new testApp());

}
