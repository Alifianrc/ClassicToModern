#include "Object.h"

object::object(){
	sx = 1; 
	sy = 1;

	tx = 0;
	ty = 0;

	angle = 0;
}

float* object::GetVertices() {
	return vertices;
}

unsigned int* object::GetIndices() {
	return indices;
}

//setter getter origin
void object::setX(float ix) {
	x = ix;

}
void object::setY(float iy) {
	y = iy;
}
float object::getX() {
	return x;

}
float object::getY() {
	return y;
}

//setter getter parameter translasi
void object:: translate(float tsx, float tsy) {
	tx += tsx;
	ty += tsy;
}

float object::getTX() {
	return tx;

}
float object::getTY() {
	return ty;
}

//setter getter parametet scale
void object::scale(float ssx, float ssy) {
	sx *= ssx;
	sy *= ssy;
}


float object::getSx() {
	return sx;

}
float object::getSy() {
	return sy;
}

//setter getter parameter rotate
void object::rotate(float Angle){
	angle += Angle;
}


float object::getAngle() {
	return angle;
}

//setter color
void object::setColor(float r, float g, float b) {
	red = r;
	green = g;
	blue = b;
}