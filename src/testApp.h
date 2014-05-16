#ifndef _TEST_APP
#define _TEST_APP

#include "ofMain.h"
#include "ParticleBall.h"
#include "ofxSSAO.h"

class testApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();
    void keyPressed(int key);

    ParticleBall ball;
    ofxSSAO ssao;
    ofEasyCam cam;
    ofMaterial mat;
    ofLight light;
    void audioIn(float * input, int bufferSize, int nChannels);

    vector <float> left;
    vector <float> right;
    vector <float> volHistory;
    int     bufferCounter;
    int     drawCounter;
    float smoothedVol;
    float scaledVol;
    ofSoundStream soundStream;
};

#endif
