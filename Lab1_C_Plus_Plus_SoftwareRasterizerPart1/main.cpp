/** @file main.cpp
 *  @brief Entry point into our program.
 *  
 *  Welcome to the Great Looking Software Render 
 *  code base (Yes, I needed something with a gl prefix).
 *
 *  This is where you will implement your graphics API.
 *
 *  Compile on the terminal with: 
 *
 *  clang++ -std=c++11 main.cpp -o main
 *
 *  @author Mike Shah
 *  @bug No known bugs.
 */

// Load our libraries
#include <iostream>
#include <algorithm>
#include <vector>

// Some define values
#define WINDOW_HEIGHT 320
#define WINDOW_WIDTH 320

// C++ Standard Libraries
#include <iostream>

// User libraries
#include "GL.h"
#include "Color.h"
#include "TGA.h"
#include "Maths.h"

// Create a canvas to draw on.
TGA canvas(WINDOW_WIDTH,WINDOW_HEIGHT);

bool sortVertices(Vec2 v0, Vec2 v1) {
    return (v0.y < v1.y);
}

// Implementation of Bresenham's Line Algorithm
// The input to this algorithm is two points and a color
// This algorithm will then modify a canvas (i.e. image)
// filling in the appropriate colors.
void drawLine(Vec2 v0, Vec2 v1, TGA& image, ColorRGB c){
    bool steep = false;
    if(std::abs(v0.x-v1.x)<std::abs(v0.y-v1.y)){
        // If the line is steep we want to transpose the image.
        std::swap(v0.x,v0.y);
        std::swap(v1.x,v1.y);
        steep = true;
    }
    if(v0.x>v1.x){  // make it left-to-right
        std::swap(v0.x, v1.x);
        std::swap(v0.y, v1.y);
    }
    for(int x = v0.x; x <= v1.x; ++x){
        float t = (x-v0.x)/(float)(v1.x-v0.x);
        int y = v0.y*(1.0f-t) + v1.y*t;
        if(steep){
            canvas.setPixelColor(y,x,c);
        }else{
            canvas.setPixelColor(x,y,c);
        }
    }
}

void fillBottomFlatTriangle(Vec2 v1, Vec2 v2, Vec2 v3, TGA& image, ColorRGB c)
{   
    float rise1 = v2.x - v1.x;
    float run1 = v2.y - v1.y;
    float rise2 = v3.x - v1.x;
    float run2 = v3.y - v1.y;
    float invslope1 = rise1 / run1;
    float invslope2 = rise2 / run2;

    float curx1 = v1.x;
    float curx2 = v1.x;

    for (int scanlineY = v1.y; scanlineY <= v2.y; scanlineY++)
    {
        Vec2 currV1(curx1, scanlineY);
        Vec2 currV2(curx2, scanlineY);
        drawLine(currV1, currV2, image, c);
        curx1 += invslope1;
        curx2 += invslope2;
    }
}

void fillTopFlatTriangle(Vec2 v1, Vec2 v2, Vec2 v3, TGA& image, ColorRGB c)
{
    float rise1 = v3.x - v1.x;
    float run1 = v3.y - v1.y;
    float rise2 = v3.x - v2.x;
    float run2 = v3.y - v2.y;
    float invslope1 = rise1 / run1;
    float invslope2 = rise2 / run2;  

    float curx1 = v3.x;
    float curx2 = v3.x;

    for (int scanlineY = v3.y; scanlineY > v1.y; scanlineY--) {
        Vec2 currV1(curx1, scanlineY);
        Vec2 currV2(curx2, scanlineY);
        drawLine(currV1, currV2, image, c);
        curx1 -= invslope1;
        curx2 -= invslope2;
    }
}


// Draw a triangle
void triangle(Vec2 v0, Vec2 v1, Vec2 v2, TGA& image, ColorRGB c){
    if(glFillMode==LINE){
        drawLine(v0,v1,image,c);
        drawLine(v1,v2,image,c);
        drawLine(v2,v0,image,c);
    }

    if(glFillMode==FILL) {
        //sortVerticesAscendingByY();
        std::vector<Vec2> vertexVector;
        vertexVector.push_back(v0);
        vertexVector.push_back(v1);
        vertexVector.push_back(v2);
        std::sort(vertexVector.begin(), vertexVector.end(), sortVertices);

        Vec2 sortedV0 = vertexVector.at(0);
        Vec2 sortedV1 = vertexVector.at(1);
        Vec2 sortedV2 = vertexVector.at(2);

    /* check for bottom-flat triangle */
        if (sortedV1.y == sortedV2.y)
        {
            fillBottomFlatTriangle(sortedV0, sortedV1, sortedV2, image, c);
        }
    /* check for top-flat triangle */
        else if (sortedV0.y == sortedV1.y)
        {
            fillTopFlatTriangle(sortedV0, sortedV1, sortedV2, image, c);
        }
        else
        {
    /* general case - split the triangle in a topflat and bottom-flat one */
            Vec2 v3((int)(sortedV0.x + ((float)(sortedV1.y - sortedV0.y) / (float)(sortedV2.y - sortedV0.y)) * (v2.x - sortedV0.x)), sortedV1.y);
            fillBottomFlatTriangle(sortedV0, sortedV1, v3, image, c);
            fillTopFlatTriangle(sortedV1, v3, sortedV2, image, c);
        }
    }
}

// Main
int main(){
    // A sample of color(s) to play with
    ColorRGB color1;
    color1.r = 0; color1.g = 200; color1.b = 200;

    ColorRGB color2;
    color2.r = 255;  color2.g = 115; color2.b = 0;

    ColorRGB color3;
    color3.r = 128; color3.g = 0; color3.b = 128;

    // Points for our Line
    Vec2 line[2] = {Vec2(0,0), Vec2(100,100)};

    // Set the fill mode
    glPolygonMode(FILL);

    // Data for our triangle
    Vec2 tri[3] = {Vec2(30,60),Vec2(240,60),Vec2(160,10)};
    triangle(tri[0],tri[1],tri[2],canvas,color1);

    Vec2 tri1[3] = {Vec2(100,100),Vec2(200,70),Vec2(300,300)};
    triangle(tri1[0],tri1[1],tri1[2],canvas,color2);

    Vec2 tri2[3] = {Vec2(10,200),Vec2(100,290),Vec2(170,200)};
    triangle(tri2[0],tri2[1],tri2[2],canvas,color3);

    // Output the final image
    canvas.outputTGAImage("graphics_lab2.ppm");

    return 0;
}
