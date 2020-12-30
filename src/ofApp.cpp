#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    ofBackground(0, 0, 0);
    ofSetFrameRate(60);
    ofEnableSmoothing();
    balls.resize(8);

    for (size_t i = 0; i < balls.size(); i++)
    {
        balls[i].x = ofRandomWidth();
        balls[i].y = ofRandomHeight();
        balls[i].vx = ofRandom(-15, 15);
        balls[i].vy = ofRandom(0.1, 1);
        balls[i].radius = ofRandom(10,40);
        balls[i].weight = ofRandom(10, 20);
        balls[i].color.r = ofRandom(1, 255);
        balls[i].color.g = ofRandom(1, 255);
        balls[i].color.b = ofRandom(1, 255);
    }
}

void ofApp::update()
{
    for (size_t i = 0; i < balls.size(); i++)
    {
        balls[i].vy += ((g * balls[i].weight)-(6 * pi * balls[i].vy * n * balls[i].radius)) * dt;
        balls[i].x += balls[i].vx;
        balls[i].y += balls[i].vy * dt;

        if (balls[i].x + balls[i].radius > ofGetWidth())
        {
            balls[i].x = ofGetWidth() - balls[i].radius;
            balls[i].vx *= friction;
        }
        if (balls[i].x - balls[i].radius < 0)
        {
            balls[i].x = balls[i].radius;
            balls[i].vx *= friction;
        }
        if (balls[i].y + balls[i].radius > ofGetHeight())
        {
            balls[i].y = ofGetHeight() - balls[i].radius;
            balls[i].vy = -balls[i].vy;
        }
        if (balls[i].y - balls[i].radius < 0)
        {
            balls[i].y = balls[i].radius;
            balls[i].vy = -balls[i].vy;
        }
     }
}

void ofApp::draw()
{
    for (size_t i = 0; i < balls.size(); i++)
    {
        ofSetColor(balls[i].color.r, balls[i].color.g ,balls[i].color.b);
        ofCircle(balls[i].x, balls[i].y, balls[i].radius);
    }
}


