#pragma once
#include "Shader.h"


class Buffer {
private:
	unsigned int* VAO;
	unsigned int* VBO;
	unsigned int* EBO;

	int count;

public:
	Buffer() = default;

	void SetTotalBuffer(int total);

	void SetBufferData(int number, float* vertices, unsigned int* indices);

	void Draw(int number, int mode, int count);

	void DeleteBuffer();

	//void Excecution
};