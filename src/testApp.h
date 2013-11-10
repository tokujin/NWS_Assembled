#pragma once

#include "ofMain.h"
#include "ofxOpticalFlowFarneback.h"
#include "ofxUI.h"

#include "particle.h"
#include "ParticleN.h"
#include "ParticleJ.h"
#include "vectorField.h"
#include "fft.h"
#include "FFTOctaveAnalyzer.h"

#define BUFFER_SIZE 512

//#define _USE_LIVE_VIDEO

class testApp : public ofBaseApp{
	
public:
	void setup();
	void update();
	void draw();
	
	void keyPressed  (int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
    
	//---------------------------
    //Matt's Animation
	// particle & vector field-related
	void addParticle(float x, float y, float vx, float vy);
	vector <particle> particles;
	vectorField field;
	ofVec2f vectorFieldScale;
	
	// CV or video player-related
	ofVideoGrabber vidGrabber;
	ofVideoPlayer vidPlayer, p1, p2;
	vector <ofVideoPlayer> vidPlayers;
	int videoPlayerIndex;
	int videoWidth;
	int videoHeight;
	void setupGrabber();
	//void setupPlayer(string filename = "topview.mp4");
	void setupPlayer(int index = 0);
	void setupSolverAndField();
	
	// CV images for debug
	ofxCvColorImage colorImage, colorImageBlurred;
	ofxCvGrayscaleImage grayImage, grayImagePrev, grayImageDiff, grayImageDiffHistory;
	ofxCvContourFinder contourFinder;
	
	// optical flow solver & scale
    ofxOpticalFlowLK flowSolver;
	ofVec2f flowSolverScale;
	
	// program related
	bool useLiveVideo;
	bool mirrorVideo;
	bool drawVideo;
	bool drawVideoFullscreen;
	bool drawFlowSolver;
	bool drawFlowSolverFullscreen;
	bool drawVectorField;
	bool drawImageDiff;
	bool drawParticles;
	float particleMaxCount;
	float particleCount;
	bool particleColorBasedOnDirection;
	bool particleFade;
	float particleSaturation;
	float minimumVelocity;
	float videoBlurAmount;
	float backgroundTransparency;
	bool increaseBlurAndDim;
	float imageDiffThreshold;
	float imageDiffBlur;

    //Gui related
	ofxUICanvas *gui;
	void setupGUI();
	void guiEvent(ofxUIEventArgs &e);

	//---------------------------
    //Nori's Animation
    //particle, vector field related
	vector <ParticleN> particlesN;
	vectorField VF;
	
	float prevMouseX;
	float prevMouseY;
    
    //fft related
//    void audioReceived(float* input, int bufferSize, int nChannels);
    FFTOctaveAnalyzer FFTanalyzer;
    float left[BUFFER_SIZE];
    float right[BUFFER_SIZE];
    fft		myfft;
    float magnitude[BUFFER_SIZE];
    float phase[BUFFER_SIZE];
    float power[BUFFER_SIZE];
    float freq[BUFFER_SIZE/2];
    
    //Gui related
    ofxUICanvas *guiN;
    
    //Fbo related
    ofFbo  mFboN;
    ofFbo  pallette;
    
    //program related
    float friction;
    float radius;
    bool resetButton;
    bool clearButton;
    bool randomVF;
    bool startNori;
    
    float soundVol, soundVolMax; //sound volume
    float soundVolL, soundVolLMax;
    float soundVolH, soundVolHMax; //average of magnitude in lower bands, in higher bands
    int alpha;
    float nradius;
    float rotate;
    bool colorchange;
    
    //color palette
    float blue, red;
    float r1,g1,b1, r2,g2,b2, r3,g3,b3;
    

    
    
    
};
