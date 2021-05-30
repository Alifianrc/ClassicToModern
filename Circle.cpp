#include "circle.h"
#include <GL/glew.h>
#include <GL/freeglut.h> 
#include <cstdlib>
#include <cmath>
#include <iostream>
#pragma once

#define PI 3.14159265358979324

	circle::circle() {
		R = 20;
		x = 50;
		y = 50;

		red = 0.5;
		green = 0.5;
		blue = 0.5;
	}

	void circle::draw() {
		float t = 0;
		glPushMatrix();
			//handling translasi
			glTranslatef(tx, ty, 0);

			//handle drawing objek sekaligus perhitungan scaling objek
			glBegin(GL_LINE_LOOP);
				for (int i = 0; i < 30; ++i) {
				glColor3f(red, green, blue);
				glVertex3f(x + sx*R * cos(t), y+ sy* R * sin(t), 0.0);
				t += 2 * PI /30;
			}
			glEnd();
		glPopMatrix();
	}

	void circle::setR(int r){
		R = r;
	}

	float circle::getR() {
		return R;
	}

	//tsx menunjukkan sejauh apa lingkaran kita akan digeser pada sumbu x
	//tsy menunjukkan sejauh apa lingkaran akan digeser pada sumbu y

	//kita main game, objek digeser lebih dari sekali. Total pergeseran objek, disimpan dalam tx dan ty
	//tekan tombol 3x
	//menggeser lingkaran sejauh (10, 10) -> translate (10,10)
		//tx = 10 ty = 10
	//menggeser lingkaran sejauh (20,30) --> translate (20,30)
		//tx = 30, ty = 40
	//menggeser lingkaran sejauh (5,5) --> translate(5,5)
		//tx = 35, ty = 45

	//tsx>0 ---> lingkaran bergeser ke kanan. tsx<0 ---> lingkaran geser ke kiri
	//tsy> 0 ---> atas.		//tsy<0 ---> bawah

	void circle::translate(float tsx, float tsy) {
		//Batas atas : y + sy.R		//batas atas' = ty + (y+sy.R)
		//Batas bawah : y -sy.R		//batas bawah' = ty + (y-sy.R)
		//Batas kiri : x-sx.R			//batas kiri' = tx + x -sx.R
		//Batas kanan : x+s.R			//batas kanan' = tx + x + sx.R
		//kALAU kita menggeser lingkaran sejauh tx dan ty, maka titik koordinat origin/pusat lingkaran, juga bergeser
		//sejauh tx dan ty.
		float batas_atas = ty + y + (sy*R);
		float batas_bawah = ty + y - (sy*R);
		float batas_kiri = tx + x - (sx*R);
		float batas_kanan = tx + x + (sx*R);
		
		if ((batas_atas == 100 && tsy>0) || (batas_bawah == 0 && tsy<0))
			tsy = 0;
		else
			if ((batas_kiri == 0 && tsx<0)|| (batas_kanan == 100 && tsx>0))
				tsx = 0;
		tx += tsx;
		ty += tsy;
	}

