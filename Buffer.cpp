#include "Buffer.h"

void Buffer::SetTotalBuffer(int total) {
	VAO = new unsigned int[total];
	glGenVertexArrays(total, VAO);

	VBO = new unsigned int[total];
	glGenBuffers(total, VBO);

	EBO = new unsigned int[total];
	glGenBuffers(total, EBO);

	count = total;
}

void Buffer::SetBufferData(int number, float* vertices, unsigned int* indices) {
	glBindVertexArray(VAO[number]);

	glBindBuffer(GL_ARRAY_BUFFER, VBO[number]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO[number]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
}

void Buffer::Draw(int number, int mode, int count) {
	if (mode == 0 || mode != 1) {
		glBindVertexArray(VAO[number]);
		glDrawElements(GL_TRIANGLES, count, GL_UNSIGNED_INT, 0);
	}
	else if (mode == 1) {
		glBindVertexArray(VAO[number]);
		glDrawElements(GL_LINE_LOOP, count, GL_UNSIGNED_INT, 0);
	}
}

void Buffer::DeleteBuffer() {
	for (int i = 0; i < count; i++) {
		glDeleteVertexArrays(1, &VAO[i]);
		glDeleteBuffers(1, &VBO[i]);
		glDeleteBuffers(1, &EBO[i]);
	}
}