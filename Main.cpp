#include <iostream>
#include <algorithm>
#include <GL/glew.h>
#include <GL/freeglut.h> 
#include "Rectangle.h";
#include "Shader.h"
#include "Buffer.h"

using namespace std;

//circle circ;
rectangle rect1(50, 50, 10, 10);
rectangle rect2(70, 70, 10, 10);

//collision detection circle vs rectangle
/*
bool collisionDetection(circle Circle, rectangle Rectangle) {
	float deltaX = Circle.getX() + Circle.getTX() - max(Rectangle.getX() + Rectangle.getTX(), min(Circle.getX() + Circle.getTX(), Rectangle.getX() + (Rectangle.getSx()* Rectangle.getW()) + Rectangle.getTX()));
	float deltaY = Circle.getY() + Circle.getTY() - max(Rectangle.getY() + Rectangle.getTY(), min(Circle.getY()+Circle.getTY(), Rectangle.getY() + (Rectangle.getSy()*Rectangle.getH()+ Rectangle.getTY())));
	return (deltaX * deltaX + deltaY * deltaY) < (Circle.getR() * Circle.getR());
}
*/
void drawScene(void){
	glClear(GL_COLOR_BUFFER_BIT);

	rect1.UpdateVertices();
	rect2.UpdateVertices();

	Shader ourShader("vertexShader.txt", "fragmentShader.txt");

	Buffer ourBuffer;
	ourBuffer.SetTotalBuffer(2);
	ourBuffer.SetBufferData(0, rect1.GetVertices(), rect1.GetIndices());
	ourBuffer.SetBufferData(1, rect2.GetVertices(), rect2.GetIndices());

	ourShader.use();
	ourBuffer.Draw(0, 0, 6);
	ourBuffer.Draw(1, 0, 6);

	//logic
	/*
	if (collisionDetection(circ, rect)) {
		rect2.setColor(1, 0, 0);
		glutPostRedisplay();
	}
	else {
		rect2.setColor(0, 1, 0);
		glutPostRedisplay();
	}
	*/
	//glFlush();
}

void setup(void){
	glClearColor(1.0, 1.0, 1.0, 0.0);
}


void resize(int w, int h){
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 100.0, 0.0, 100.0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void TransKey(unsigned char key, int x, int y) {
	switch (key) {
	case 27:
		exit(0);
		break;
	case 's':
		rect1.translate(0, 0);
		glutPostRedisplay();
		break;
	case 'a':
		rect1.translate(-10, 0);
		glutPostRedisplay();
		break;
	case 'w':
		rect1.translate(0, 10);
		glutPostRedisplay();
		break;
	case 'z':
		rect1.translate(0, -10);
		glutPostRedisplay();
		break;
	default:
		break;
	}
}
/*
void ScalKey(unsigned char key, int x, int y) {
	switch (key) {
	case 27:
		exit(0);
		break;
	case 's':
		circ.scale(2, 1);
		cout << "x :" << rect.getX() * rect.getSx() << " sx :" << rect.getSx() << " tx :" << rect.getTX() << endl;
		glutPostRedisplay();
		break;
	case 'a':
		circ.scale(0.5, 1);
		cout << "x :" <<rect.getX()*rect.getSx()<<" sx :" << rect.getSx() << " tx :" << rect.getTX() << endl;
		glutPostRedisplay();
		break;
	case 'w':
		circ.scale(1, 2);
		cout << "sx :" << rect.getSy() << " tx :" << rect.getTY() << endl;
		glutPostRedisplay();
		break;
	case 'z':
		circ.scale(1,0.5);
		cout << "sx :" << rect.getSy() << " tx :" << rect.getTY() << endl;
		glutPostRedisplay();
		break;
	default:
		break;
	}
}
*/
void RotateKey(unsigned char key, int x, int y) {
	switch (key) {
	case 27:
		exit(0);
		break;
	case 's':
		rect1.rotate(0.2);
		rect2.rotate(-0.2);
		glutPostRedisplay();
		break;
	case 'a':
		rect1.rotate(-0.2);
		rect2.rotate(0.2);
		glutPostRedisplay();
		break;
	default:
		break;
	}
}

int main(int argc, char** argv){
	glutInit(&argc, argv);

	glutInitContextVersion(4, 3);
	glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("test.cpp");
	glutDisplayFunc(drawScene);
	glutReshapeFunc(resize);
	glutKeyboardFunc(RotateKey);

	glewExperimental = GL_TRUE;
	glewInit();

	setup();

	glutMainLoop();
}