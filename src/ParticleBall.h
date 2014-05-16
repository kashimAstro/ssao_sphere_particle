#pragma once

#include "ofMain.h"
#include "Particle.h"

#define NUM_PARTICLES 45

class ParticleBall {
public:
    ofImage img;

    Particle particles[NUM_PARTICLES];
    float colorx;
    ParticleBall() {
        for(int i = 0; i < NUM_PARTICLES; i++) {
            float theta = ofRandom(0,TWO_PI);
            float u = ofRandom(-1,1);
            img.loadImage("texture.jpg");
            particles[i] = Particle(theta,u);
        }
    }

    void update(float m) {
        for(int i = 0; i < NUM_PARTICLES; i++) {
            particles[i].update(m);
        }

    }

    void draw(float mu) {
       ofPushMatrix();
       ofRotateX(ofGetElapsedTimeMillis()*.0005);
       ofSetColor(255,255,255);
       ofDrawSphere(ofPoint(10,10,10),40*(mu*6));
       ofPopMatrix();
       ofPushMatrix();
       ofRotateY(ofGetElapsedTimeMillis()*.0035);
       for(int i = 0; i < NUM_PARTICLES; i++) {
           particles[i].draw(mu);
       }
       ofPopMatrix();
    }
};
