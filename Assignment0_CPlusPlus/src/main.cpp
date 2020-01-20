// Include our custom library
#include "PPM.h"

int main(){

    PPM myPPM1("../textures/test.ppm");
	myPPM1.setPixel(0, 0, 0, 255, 0);
	myPPM1.setPixel(10, 40, 255, 0, 0);
	myPPM1.setPixel(250, 470, 0, 0, 255);
	//PPM myPPM2("../textures/test1.ppm");
    myPPM1.darken();
	//myPPM2.darken();
    myPPM1.savePPM("../textures/test_darken.ppm");
	//myPPM2.savePPM("../textures/test1_darken.ppm");

    return 0;
}
