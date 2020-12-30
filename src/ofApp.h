#pragma once

#include "ofMain.h"
#include <vector>
#include <iostream>



struct Ball {
    double x;
    double y;
    double vx;
    double vy;
    double radius;
    double weight;
    ofColor color;
};


class ofApp : public ofBaseApp{

	public:
		void setup();
        void update();
		void draw();
    private:
        double friction = -0.5;
        double n = 0.0000176;
        double dt = 0.1;
        double pi = 3.14;
        double g = 9.81;
        std::vector<Ball> balls;
		
};
