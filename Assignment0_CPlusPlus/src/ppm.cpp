#include "PPM.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>	
#include <algorithm>

// Constructor loads a filename with the .ppm extension
PPM::PPM(std::string fileName){
    // TODO:    Load and parse a ppm to get its pixel
    //          data stored properly.
	std::ifstream inFile(fileName);
	std::string line;
	if (inFile.is_open()) {

		//skip the first line
		std::getline(inFile, line);

		//skip the comments
		do {
			std::getline(inFile, line);
		} while (line[0] == '#');

		//get the width and height
		std::size_t found = line.find(" ");
		std::string width = line.substr(0, found);
		std::string height = line.substr(found + 1, line.size() - found);
		m_width = std::stoi(width);
		m_height = std::stoi(height);

		//get the max color value and scale it to 255
		std::getline(inFile, line);
		unsigned char maxValue = stoi(line);
		float scale = 255.0 / maxValue;

		//store pixel data
		m_PixelData = new unsigned char[m_width * m_height * 3];
		int i = 0;
		while (getline(inFile, line)) {
			char* lineCopy = new char[line.size() + 1];
			char* lineToken;
			std::strcpy(lineCopy, line.c_str());
			lineToken = std::strtok(lineCopy, " ");
			while (lineToken != NULL) {
				//get next RGB value and scale it up to 255
				unsigned char curr = std::stoi(lineToken);
				m_PixelData[i] = curr * scale;
				i++;
				lineToken = std::strtok(NULL, " ");
			}
			delete[] lineCopy;
		}
	}
	inFile.close();
}

// Destructor clears any memory that has been allocated
PPM::~PPM(){
	delete[] m_PixelData;
}

// Saves a PPM Image to a new file.
void PPM::savePPM(std::string outputFileName){
    // TODO: Save a PPM image to disk
	std::ofstream outFile(outputFileName);
	if (outFile.is_open()) {
		outFile << "P3" << std::endl;
		outFile << "# Some image data" << std::endl;
		outFile << m_width << " " << m_height << std::endl;
		outFile << 255 << std::endl;
		for (int i = 0; i < (m_width * m_height * 3); i++) {
			outFile << (int)m_PixelData[i] << std::endl;
		}
	}
	outFile.close();
}

// Darken subtracts 50 from each of the red, green
// and blue color components of all of the pixels
// in the PPM. Note that no values may be less than
// 0 in a ppm.
void PPM::darken(){
    // TODO: Output a 'filtered' PPM image.
	for (int i = 0; i < (m_width * m_height * 3); i++) {
		unsigned char dark = std::max(m_PixelData[i] - 50, 0);
		m_PixelData[i] = dark;
	}
}

// Sets a pixel to a specific R,G,B value 
void PPM::setPixel(int x, int y, int R, int G, int B){
    // TODO: Implement
	int pixel = (3 * x) + (3 * m_width * y);
	m_PixelData[pixel] = R;
	m_PixelData[pixel + 1] = G;
	m_PixelData[pixel + 2] = B;
}
