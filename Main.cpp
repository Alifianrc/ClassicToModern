#include <iostream>
#include <algorithm>
//#include <GL/glew.h>
//#include <GL/freeglut.h>
#include "Shader.h"
#include "Rectangle.h";
#include "Buffer.h"

using namespace std;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

// settings
const unsigned int SCR_WIDTH = 700;
const unsigned int SCR_HEIGHT = 700;
//circle circ;


//collision detection circle vs rectangle
/*
bool collisionDetection(circle Circle, rectangle Rectangle) {
	float deltaX = Circle.getX() + Circle.getTX() - max(Rectangle.getX() + Rectangle.getTX(), min(Circle.getX() + Circle.getTX(), Rectangle.getX() + (Rectangle.getSx()* Rectangle.getW()) + Rectangle.getTX()));
	float deltaY = Circle.getY() + Circle.getTY() - max(Rectangle.getY() + Rectangle.getTY(), min(Circle.getY()+Circle.getTY(), Rectangle.getY() + (Rectangle.getSy()*Rectangle.getH()+ Rectangle.getTY())));
	return (deltaX * deltaX + deltaY * deltaY) < (Circle.getR() * Circle.getR());
}
*/
/*
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

	if (collisionDetection(circ, rect)) {
		rect2.setColor(1, 0, 0);
		glutPostRedisplay();
	}
	else {
		rect2.setColor(0, 1, 0);
		glutPostRedisplay();
	}
	
	//glFlush();
}
*/

void setup(void){
	glClearColor(1.0, 1.0, 1.0, 0.0);
}

/*
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
*/
int main(){
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// glfw window creation
	// --------------------
	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Modern OpenGL", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	// build and compile our shader zprogram
	// ------------------------------------
	Shader ourShader("vertexShader.txt", "fragmentShader.txt");

	rectangle rect1(0.5, 0.5, 0.5, 0.5);
	//rectangle rect2(-0.5, -0.5, 0.2, 0.2);

	Buffer ourBuffer;
	ourBuffer.SetTotalBuffer(1);
	ourBuffer.SetBufferData(0, rect1.GetVertices(), rect1.GetIndices());
	//ourBuffer.SetBufferData(1, rect2.GetVertices(), rect2.GetIndices());

	while (!glfwWindowShouldClose(window))
	{
		processInput(window);

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// render container
		ourShader.use();
		ourBuffer.Draw(0, 0, 6);
		//ourBuffer.Draw(1, 0, 6);

		// glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
		// -------------------------------------------------------------------------------
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	ourBuffer.DeleteBuffer();

	glfwTerminate();
	return 0;
}


// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	// make sure the viewport matches the new window dimensions; note that width and 
	// height will be significantly larger than specified on retina displays.
	glViewport(0, 0, width, height);
}