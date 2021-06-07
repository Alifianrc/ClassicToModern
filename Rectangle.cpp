#include "Rectangle.h"
#include <GL/glew.h>
#include <GL/freeglut.h> 
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <cmath>
#pragma once

rectangle::rectangle(float X, float Y, float width, float height) {
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
	// Vertex 0
	vertices[0] = x;
	vertices[1] = y - h;
	vertices[2] = 0;

	// Vertex 1
	vertices[3] = x;
	vertices[4] = y;
	vertices[5] = 0;

	// Vertex 2
	vertices[6] = x + w;
	vertices[7] = y;
	vertices[8] = 0;

	// Vertex 3
	vertices[9] = x + w;
	vertices[10] = y - h;
	vertices[11] = 0;

	for (int i = 0; i < 12; i++) {
		std::cout << vertices[i] << " ";
		if ((i + 1) % 3 == 0) {
			std::cout << "\n";
		}
	} std::cout << "\n\n";
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

/*
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
*/