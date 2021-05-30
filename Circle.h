#pragma once
#include "object.h"
class circle : public object{
	private:
		//radius lingkaran
		float R;

	public:
		//constructor lingkaran
		circle();

		//setter and getter radius
		void setR(int r);
		float getR();
		

		//override fungsi draw
		void draw();

		//translate
		void translate(float tsx, float tsy);

};
