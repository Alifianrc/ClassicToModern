#include "Rectangle.h"
#include <GL/glew.h>
#include <GL/freeglut.h> 
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <cmath>
#pragma once

rectangle::rectangle(int X, int Y, int width, int height) {
	x = X;
	y = Y;

	vertices = new float[4 * 3];

	indices = new unsigned int[2 * 3];

	w = width;
	h = height;

	sx = 0.5;
	sy = 0.5;

	red = 0;
	green = 0;
	blue = 1;

	UpdateVertices();
	UpdateIndices();
}

void rectangle::draw(){
	

	
}

void rectangle::UpdateVertices() {
	// Vertex 1
	vertices[0] = x;
	vertices[1] = y;
	vertices[2] = 0;

	// Vertex 2
	vertices[3] = (w * sx) * cos(angle);
	vertices[4] = (w * sx) * sin(angle);
	vertices[5] = 0;

	// Vertex 3
	vertices[6] = ((w * sx) * cos(angle)) + ((sy * h) * (-sin(angle)));
	vertices[7] = ((w * sx) * sin(angle)) + ((sy * h) * cos(angle));
	vertices[8] = 0;

	// Vertex 4
	vertices[9] = (sy * h) * (-sin(angle));
	vertices[10] = (sy * h) * cos(angle);
	vertices[11] = 0;
}
void rectangle::UpdateIndices() {
	// Indices 1
	indices[0] = 3;
	indices[1] = 0;
	indices[2] = 1;
	// Indices 2
	indices[3] = 1;
	indices[4] = 2;
	indices[5] = 3;
}

void rectangle::setW(float width){
	w = width;
}
void rectangle::setH(float height) {
	h = height;
}
float rectangle::getW(){
	return w;
}
float rectangle::getH(){
	return h;
}

void rectangle::translate(float tsx, float tsy) {
	float batas_atas = ty + y + (sy*h);
	float batas_bawah = ty + y;
	float batas_kiri = tx + x;
	float batas_kanan = tx + x + (sx*w);

	if ((batas_atas == 100 && tsy > 0) || (batas_bawah == 0 && tsy < 0))
		tsy = 0;
	else
		if ((batas_kiri == 0 && tsx < 0) || (batas_kanan == 100 && tsx > 0))
			tsx = 0;

	ty += tsy;
	tx += tsx;
}
