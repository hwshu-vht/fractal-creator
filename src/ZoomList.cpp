/*
 * ZoomList.cpp
 *
 *  Created on: Aug 27, 2023
 *      Author: thuhv5
 */

#include "ZoomList.h"

namespace fractal_img
{

ZoomList::ZoomList(int width, int height): m_width(width), m_height(height)
{
}

void ZoomList::add(const Zoom &zoom)
{
	zooms.push_back(zoom);
}

std::pair<double, double> ZoomList::doZoom(int x, int y)
{
	return std::pair<double, double>(0, 0);
}

} /* namespace fractal_img */
