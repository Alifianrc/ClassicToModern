#pragma once
class object{
	protected:
		//titik origin objek
		int x;
		int y;

		// Vertices object
		float* vertices;
		
		// Indices object
		unsigned int* indices;
		
		//parameter skala objek
		float sx; //besar scaling di sumbu x
		float sy; //besar scaling di sumbu y

		//parameter translasi objek
		float tx; //digeser seberapa jauh di sumbu x
		float ty; //digeser seberapa jauh di sumbu y

		//parameter rotasi objek
		float angle;//diputar sebesar apa

		//parameter warna objek
		float red;
		float green;
		float blue;

	public:
		//constructor
		object();

		//gambar
		//void draw();

		float* GetVertices();

		unsigned int* GetIndices();

		//setter getter origin objek
		void setX(float ix);
		void setY(float iy);
		float getX();
		float getY();

		//setter getter parameter translasi objek
		void translate(float tsx, float tsy); //setter tx sama ty
		float getTX(); 
		float getTY();


		//setter getter parameter scaling objek
		void scale(float ssx, float ssy);//setter sx sama sy
		float getSx();
		float getSy();

		//setter getter parameter rotasi objek
		void rotate(float Angle);//setter angle
		float getAngle();

		//setter warna objek
		void setColor(float r, float g, float b);

};

