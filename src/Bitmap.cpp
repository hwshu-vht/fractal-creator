/*
 * Bitmap.cpp
 *
 *  Created on: Aug 26, 2023
 *      Author: thuhv5
 */

#include <fstream>
#include "Bitmap.h"
#include "BitmapFileHeader.h"
#include "BitmapInfoHeader.h"
#include "string.h"

using namespace fractal_img;

namespace fractal_img
{

Bitmap::Bitmap(int width, int height)
		: m_width(width),
		  m_height(height),
		  m_pPixels(new uint8_t[width*height*3]{})
{
}

Bitmap::~Bitmap()
{
}

bool Bitmap::write(std::string filename)
{
	BitmapFileHeader fileHeader;
	BitmapInfoHeader infoHeader;

	fileHeader.fileSize = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader) + m_width*m_height*3;
	fileHeader.dataOffset = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader);

	infoHeader.width = m_width;
	infoHeader.height = m_height;

	std::ofstream file;
	file.open(filename, std::ios::out | std::ios::binary);
	if (!file)
		return false;

	file.write((char*)&fileHeader, sizeof(fileHeader));
	file.write((char*)&infoHeader, sizeof(infoHeader));
	file.write((char*)m_pPixels.get(), m_width*m_height*3);

	file.close();

	return true;
}

void Bitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue)
{
	uint8_t* pPixel = m_pPixels.get();
	pPixel += 3*y*m_width + 3*x;
	pPixel[0] = blue;
	pPixel[1] = green;
	pPixel[2] = red;
}


} /* namespace fractal_img */
