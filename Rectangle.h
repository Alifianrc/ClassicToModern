#pragma once
#include "Object.h"
class rectangle :public object{
	private:
		//tinggi (h) dan lebar objek(w)
		float w;
		float h;

	public:
		//constructor persegi
		rectangle(int X, int Y, int width, int height);

		//override dari fungsi draw
		void draw();

		void UpdateVertices();
		void UpdateIndices();

		//setter getter tinggi dan lebar objek
		void setW(float width);
		void setH(float height);
		float getW();
		float getH();

		//translate
		void translate(float tsx, float tsy);
};

