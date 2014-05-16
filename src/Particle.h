#pragma once

#include "ofMain.h"

class Particle {
public:
   //ofShader shader;
   float theta, u, num,numb;
   float vTheta, vU;
   float x,y,z,radius;

    Particle(float _theta=0, float _u=0) {
        radius = 150;
        theta = _theta;
        u = _u;
        vTheta = 0;
        vU = 0;
        num=ofRandom(5,85);
        numb=ofRandom(5,15);
        //shader.load("effect");
    }

    void update(float m) {
        vTheta += ofRandom(-0.001,0.001);
        theta += vTheta;

        if (theta<0||theta>TWO_PI) {
            vTheta*=-1;
        }

        vU += ofRandom(-0.001,0.001);
        u += vU;

        if (u<-1||u>1) vU*=-1;

        vU *= 0.95;
        vTheta *= 0.95;
        x = radius*(m/2)*cos(theta)*sqrt(1-(u*u));
        y = radius*(m/2)*sin(theta)*sqrt(1-(u*u));
        z = radius*u*(m/2);
    }

    void draw(float m) {
        ofPushMatrix();
        ofSetColor(5,100,255);
        ofRotateY(ofGetElapsedTimeMillis()*.0155);
        ofDrawSphere(ofPoint(x+m,y,z),num*(m));
        ofSetColor(255,0,0);
        ofRotateZ(ofGetElapsedTimeMillis()*.1055);
        //shader.begin();
        //shader.setUniform2f("",0,0);
        ofDrawIcoSphere(ofPoint(x,y,z),numb*m);
        //shader.end();
        ofPopMatrix();
    }
};

