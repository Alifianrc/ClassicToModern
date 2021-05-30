#pragma once
#include <GL/glew.h>
#include <GL/freeglut.h>

class Buffer {
private:
	unsigned int* VAO;
	unsigned int* VBO;
	unsigned int* EBO;

public:
	Buffer() = default;

	void SetTotalBuffer(int total);

	void SetBufferData(int number, float* vertices, unsigned int* indices);

	void Draw(int number, int mode, int count);

	//void Excecution
};