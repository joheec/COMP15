/*
 * ImageEngine.cpp
 *
 *  Created on: Mar 29, 2015
 *      Author: Chris Gregg
 */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>

#include "ImageEngine.h"

using namespace std;

ImageEngine::ImageEngine()
{
	// Nothing to do
}

ImageEngine::~ImageEngine()
{
	// Nothing to do
}

void ImageEngine::readImage(std::string filename)
{
	// reads in a ppm file into Image
	ifstream inputFile;
	inputFile.open (filename.c_str());
	if (inputFile.is_open()) {
		inputFile >> image.magic_number;
		inputFile >> image.width;
		inputFile >> image.height;
		inputFile >> image.max_color;
		cout << image.width << "," << image.height << "\n";
		// read in the colors
		for (int r = 0; r < image.height; r++) {
			vector<rgb> image_row;
			for (int c = 0; c < image.width; c++) {
				rgb color;
				inputFile >> color.red;
				inputFile >> color.green;
				inputFile >> color.blue;
				image_row.push_back(color);
			}
			image.colors.push_back(image_row);
		}
	} else {
		cout << "Unable to open file.\n";
		exit(0);
	}
}

void ImageEngine::copyMetadata(Image &new_image)
{
	new_image.magic_number = image.magic_number;
	//new_image.comment    = image.comment;
	new_image.max_color    = image.max_color;
	new_image.width        = image.width;
	new_image.height       = image.height;
}

// scale the image up depending on factor
// Process: repeat each character in each
// row and each character in each column
void ImageEngine::scale_up(int factor)
{
	Image new_image;
	copyMetadata(new_image);

	std::vector<std::vector<rgb> >::iterator row;
	std::vector<rgb>::iterator col;

	for(row = image.colors.begin(); row != image.colors.end(); ++row) {
		std::vector<rgb> newRow;
		for(col = row->begin(); col != row->end(); ++col) {
			for(int i = 0; i < factor; i++) {
				newRow.push_back(*col);
			}
		}

		for(int i = 0; i < factor; i++) {
			new_image.colors.push_back(newRow);
		}
	}

	new_image.width = image.width * factor;
	new_image.height = image.height * factor;
	// copy new image to old image (vectors can do this
	// with an assignment overload)
	image = new_image;
}

// scale the image down depending on factor
// where factor means "divide image by factor"
// e.g., a factor of 2 will make the image twice as
// small in each direction
void ImageEngine::scale_down(int factor)
{
	Image new_image;
	copyMetadata(new_image);

	std::vector<std::vector<rgb> >::iterator row;
	std::vector<rgb>::iterator col;

	for(row = image.colors.begin(); row != image.colors.end(); row + factor) {
		std::vector<rgb> newRow;
		for(col = row->begin(); col != row->end(); col + factor) {
			newRow.push_back(*col);
		}

		new_image.colors.push_back(newRow);
	}

	new_image.width = image.width / factor;
	new_image.height = image.height / factor;
	// copy new image to old image (vectors can do this
	// with an assignment overload)
	image = new_image;
}

// mirror the image left/right
void ImageEngine::mirror()
{
	Image new_image;
	copyMetadata(new_image);

	std::vector<std::vector<rgb> >::iterator row;
	std::vector<rgb>::iterator col;

	for(row = image.colors.begin(); row != image.colors.end(); ++row) {
		std::vector<rgb> newRow;
		for(col = row->end(); col != row->begin(); --col) {
			newRow.push_back(*col);
		}

		new_image.colors.push_back(newRow);
	}

	// copy new image to old image (vectors can do this
	// with an assignment overload!)
	image = new_image;
}

// flip the image upside down
void ImageEngine::flip()
{
	Image new_image;
	copyMetadata(new_image);

	std::vector<std::vector<rgb> >::iterator row;
	std::vector<rgb>::iterator col;

	for(row = image.colors.end(); row != image.colors.begin(); --row) {
		new_image.colors.push_back(*row);
	}

	// copy new image to old image (vectors can do this
	// with an assignment overload!)
	image = new_image;
}

// this rotates the color scheme
// as follows: r-g-b becomes b-r-g
void ImageEngine::psychedelic()
{
	Image new_image;
	copyMetadata(new_image);

	std::vector<std::vector<rgb> >::iterator row;
	std::vector<rgb>::iterator col;

	for(row = image.colors.begin(); row != image.colors.end(); ++row) {
		std::vector<rgb> newRow;
		rgb tempColor;
		for(col = row->begin(); col != row->end(); ++col) {
			tempColor.red = (*col).red;
			tempColor.green = (*col).green;
			tempColor.blue = (*col).blue;

			(*col).red = tempColor.blue;
			(*col).green = tempColor.red;
			(*col).blue = tempColor.green;

			newRow.push_back(*col);

		}

		new_image.colors.push_back(newRow);
	}

	// copy new image to old image (vectors can do this
	// with an assignment overload!)
	image = new_image;
}

void ImageEngine::save(string filename)
{
	ofstream outputfile;

	outputfile.open (filename.c_str());
	outputfile << image.magic_number << "\n";
	outputfile << image.width << " " << image.height << "\n";
	outputfile << image.max_color << "\n";
	vector<vector<rgb> >::iterator r;
	vector<rgb>::iterator c;

	for (r = image.colors.begin(); r != image.colors.end(); r++) {
		for (c = r->begin(); c < r->end(); c++) {
			outputfile << c->red   << " ";
			outputfile << c->green << " ";
			outputfile << c->blue  << "  ";
		}
		outputfile << "\n";
	}
	outputfile.close();
}
