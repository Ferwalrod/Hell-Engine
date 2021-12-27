#include <iostream>

#define GLEW_STATIC
#define BUFFER_OFFSET(i) ((char*)NULL + (i))
#include <GL/glew.h>
#include <GL/GLU.h>
#include <GL/wglew.h>
#include <iostream>
#include <glut.h>
#include <freeglut.h>
#include <gl/GL.h>
#include <GLFW/glfw3.h>
#include "SOIL2/SOIL2.h"
#include <vector>
#include "Shader.h"
//#include <SDL.h>
using namespace std;

const int WIDTH = 800, HEIGHT = 600;

void changeViewPort(int w, int h)
{
    glViewport(0, 0, w, h);
}

void render()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glutSwapBuffers();
}

void resize(int w, int h) {
    if (h <= 0) {
        h = 1;
    }
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.f, float(w) / float(h), 1.f, 100.f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

bool Initialize() {
    glEnable(GL_DEPTH_TEST);
    resize(WIDTH,HEIGHT);
    return true;
}

void display2() {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.07f, 0.13f, 0.17f, 1.f);//Specifies background color
    glEnableClientState(GL_VERTEX_ARRAY);
    glMatrixMode(GL_MODELVIEW); //Set the current matrix to modelview
    glLoadIdentity(); //reset the modelview to identity matrix
	float m_vertices[] = { 0.f,0.5f,-1.f,   -1.f,-1.5f,-1.f,      1.f,-2.f,-1.f };
	unsigned int m_indices[] = { 0,1,3,1,2,3 };
	////1) Generate buffers
	GLuint bufferID;
	glGenBuffers(1, &bufferID);

	//// 2) Bind buffer (activate it)
	glBindBuffer(GL_ARRAY_BUFFER, bufferID);
	//// 3) Store data on it
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 9, m_vertices, GL_STATIC_DRAW);
	//// 4) Use buffer
	glVertexPointer(3, GL_FLOAT, 0, BUFFER_OFFSET(0));
    glRotatef(0.01f, 4.0f, 1.0f, 1.0f);
    glTranslatef(1.f, 1.f, 1.f); //move to (5,5,5)
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	
	////5) Destroy Buffers
	glDeleteBuffers(1, &bufferID);

    glutSwapBuffers();

}
void display() {
    //Write HERE everything you want to render
    //Begining of each frames
    //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //resize(WIDTH, HEIGHT);
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.07f, 0.13f, 0.17f, 1.f);
    //glLoadIdentity();
    //gluLookAt(0.0, 1.0, 6.0,//Position
    //0.0, 0.0, 0.0, //Where we are looking
    //0.0, 1.0, 0.0);//Up Vector
    //glLoadIdentity();
    //Allows you to use some elements such as vertex arrays(more efficient than using glBegin/glEnd)
    glEnableClientState(GL_VERTEX_ARRAY);
    
    //glBegin(GL_POLYGON);
    //glColor4f(1.f, 0.f, 0.f, 1.f);
    //glVertex3f(0.f, 0.5f, -1.f);
    //glColor4f(0.f, 1.f, 0.f, 1.f);
    //glVertex3f(-1.0f, -1.5f, -1.f);
    //glColor4f(0.f, 0.f, 1.f, 1.f);
    //glVertex3f(1.f, -2.0f, -1.f);
    //glColor4f(0.f, 0.f, 1.f, 1.f);
    //glVertex3f(1.f, 0.5f, 1.f);
    //glEnd();
    //glRotatef(0.01, 1.0, 0.0, 1.0);
    float m_vertices[] = { 0.f,0.5f,-1.f,   -1.f,-1.5f,-1.f,      1.f,-2.f,-1.f,   1.f,0.5f,1.f};
    unsigned int m_indices[] = { 0,1,3,1,2,3 };
    ////1) Generate buffers
    GLuint bufferID;
    glGenBuffers(1, &bufferID);
    
    //// 2) Bind buffer (activate it)
    glBindBuffer(GL_ARRAY_BUFFER, bufferID);
    //// 3) Store data on it
    glBufferData(GL_ARRAY_BUFFER, sizeof(float)*12, m_vertices, GL_STATIC_DRAW);
    //// 4) Use buffer
    glVertexPointer(3, GL_FLOAT, 0, BUFFER_OFFSET(0));
    glDrawArrays(GL_POLYGON, 0, 4);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glRotatef(0.01, 1.0, 0.0, 1.0);
    ////5) Destroy Buffers
    glDeleteBuffers(1, &bufferID);

    //glDrawElements(GL_TRIANGLES, 6,GL_UNSIGNED_INT, m_indices);
    /*glDrawArrays(GL_TRIANGLES, 0, 3);*/
    glDisableClientState(GL_VERTEX_ARRAY);
    //glRotatef(0.01, 1.0, 0.0, 1.0);
    //Show everything coded above
    glutSwapBuffers();

}
void reshape(int w,int h) {

    glViewport(0, 0, w, h);
}
void initOpenGL() {
    glClearColor(0.f, 0.f, 0.f, 1.f);

}
//Displays a tetrahedron
void display3() {
	glClear(GL_COLOR_BUFFER_BIT);

	// Draw a white grid "floor" for the tetrahedron to sit on.
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINES);
	for (GLfloat i = -2.5; i <= 2.5; i += 0.25) {
		glVertex3f(i, 0, 2.5); glVertex3f(i, 0, -2.5);
		glVertex3f(2.5, 0, i); glVertex3f(-2.5, 0, i);
	}
	glEnd();
    //draw all the axis
	glBegin(GL_LINES);
    //X axis
	glColor3f(1, 0, 0); glVertex3f(0, 0, 0); glVertex3f(10, 0, 0);
    //Y axis
	glColor3f(0, 1, 0); glVertex3f(0, 0, 0); glVertex3f(0, 10, 0);
    //Z axis
	glColor3f(0, 0, 1); glVertex3f(0, 0, 0); glVertex3f(0, 0, 10);
	glEnd();

	// Draw the tetrahedron.  It is a four sided figure, so when defining it
	// with a triangle strip we have to repeat the last two vertices.
	//glBegin(GL_TRIANGLE_STRIP);
	//glColor3f(1, 1, 1); glVertex3f(0, 2, 0);
	//glColor3f(1, 0, 0); glVertex3f(-1, 0, 1);
	//glColor3f(0, 1, 0); glVertex3f(1, 0, 1);
	//glColor3f(0, 0, 1); glVertex3f(0, 0, -1.4);
	//glColor3f(1, 1, 1); glVertex3f(0, 2, 0);
	//glColor3f(1, 0, 0); glVertex3f(-1, 0, 1);
	//glEnd();

	glColor3f(0, 0, 0);
    //Inner radius->0.5 ,Outer radius-> 3, stacks-> 15, slices->30
	glutWireTorus(0.25, 1.5, 30, 60);

	glFlush();
}
void init() {

    // Set the current clear color to sky blue and the current drawing color to
    // white.
    glClearColor(0.1, 0.39, 0.88, 1.0);
    glColor3f(1.0, 1.0, 1.0);

    // Tell the rendering engine not to draw backfaces.  Without this code,
    // all four faces of the tetrahedron would be drawn and it is possible
    // that faces farther away could be drawn after nearer to the viewer.
    // Since there is only one closed polyhedron in the whole scene,
    // eliminating the drawing of backfaces gives us the realism we need.
    // THIS DOES NOT WORK IN GENERAL.
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    // Set the camera lens so that we have a perspective viewing volume whose
    // horizontal bounds at the near clipping plane are -2..2 and vertical
    // bounds are -1.5..1.5.  The near clipping plane is 1 unit from the camera
    // and the far clipping plane is 40 units away.
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-2, 2, -1.5, 1.5, 1, 40);

    // Set up transforms so that the tetrahedron which is defined right at
    // the origin will be rotated and moved into the view volume.  First we
    // rotate 70 degrees around y so we can see a lot of the left side.
    // Then we rotate 50 degrees around x to "drop" the top of the pyramid
    // down a bit.  Then we move the object back 3 units "into the screen".
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0, 0, -3);
    glRotatef(50, 1, 0, 0);
    glRotatef(-40, 0, 1, 0);
}
static int shoulderAngle = 0, elbowAngle = 0, yRot = 0, xTras = 0, zTras = 0;
static float cameraXTrans = 0.f,cameraYRot=0.f, cameraXRot=0.f;
void special(int key, int, int) {
	switch (key) {
	case GLUT_KEY_LEFT: (elbowAngle += 5) %= 360; break;
	case GLUT_KEY_RIGHT: (elbowAngle -= 5) %= 360; break;
	case GLUT_KEY_UP: (shoulderAngle += 5) %= 360; break;
	case GLUT_KEY_DOWN: (shoulderAngle -= 5) %= 360; break;
	default: return;
	}
	glutPostRedisplay();
}
void keyNormal(unsigned char key, int, int) {
	switch (key) {
	case 'w': (cameraXRot += 1.0f); break;
	case 's': (cameraXRot -= 1.0f); break;
	case 'd': (cameraYRot += 1.0f); break;
	case 'a': (cameraYRot -= 1.f); break;
	case 'q': cameraXTrans += 10; break;
	case 'e': cameraXTrans -= 10; break;
	case 'z': cameraXTrans += 10; break;
	case 'x': cameraXTrans -= 10; break;
	default: return;
	}
	glutPostRedisplay();

}
void wireBox(GLdouble width, GLdouble height, GLdouble depth) {
	glPushMatrix();
	glScalef(width, height, depth);
	glutSolidCube(1.0);
	glPopMatrix();
}
void display4() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glColor3f(1.0, 1.0, 1.0);
	//Draws the grid in the space
	glBegin(GL_LINES);
	for (GLfloat i = -5.0; i <= 5.0; i += 0.25) {
		glVertex3f(i, 0, 5.0); glVertex3f(i, 0, -5.0);
		glVertex3f(5.0, 0, i); glVertex3f(-5.0, 0, i);
	}
	glEnd();
	//draw all the axis
	glBegin(GL_LINES);
	//X axis
	glColor3f(1, 0, 0); glVertex3f(0, 0, 0); glVertex3f(10, 0, 0);
	//Y axis
	glColor3f(0, 1, 0); glVertex3f(0, 0, 0); glVertex3f(0, 10, 0);
	//Z axis
	glColor3f(0, 0, 1); glVertex3f(0, 0, 0); glVertex3f(0, 0, 10);
	glEnd();

	glPushMatrix();
	glColor3f(1, 1, 0);
	// Draw the upper arm, rotated shoulder degrees about the z-axis.  Note that
	// the thing about glutWireBox is that normally its origin is in the middle
	// of the box, but we want the "origin" of our box to be at the left end of
	// the box, so it needs to first be shifted 1 unit in the x direction, then
	// rotated.
	//glRotatef((GLfloat)yRot, 0.0, 1.0, 0.0);
	glRotatef((GLfloat)shoulderAngle, 0.0, 0.0, 1.0);
	glTranslatef(1.0, 0.0, 0.0);
	wireBox(2.0, 0.4, 1.0);

	// Now we are ready to draw the lower arm.  Since the lower arm is attached
	// to the upper arm we put the code here so that all rotations we do are
	// relative to the rotation that we already made above to orient the upper
	// arm.  So, we want to rotate elbow degrees about the z-axis.  But, like
	// before, the anchor point for the rotation is at the end of the box, so
	// we translate <1,0,0> before rotating.  But after rotating we have to
	// position the lower arm at the end of the upper arm, so we have to
	// translate it <1,0,0> again.
	//glRotatef((GLfloat)yRot, 0.0, 1.0, 0.0);
	glTranslatef(1.0 , 0.0, 0.0);
	glRotatef((GLfloat)elbowAngle, 0.0, 0.0, 1.0);
	glTranslatef(1.0 , 0.0, 0.0 );
	wireBox(2.0, 0.4, 1.0);

	glPopMatrix();

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(cameraXTrans, 2, 8, 0, 0, 0, 0, 1, 0);
	glRotatef(cameraXRot, 1, 0, 0);
	glRotatef(cameraYRot, 0, 1, 0);
	glFlush();
}
void reshape2(GLint w, GLint h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(65.0, GLfloat(w) / GLfloat(h), 1.0, 20.0);
}
void init2() {

	GLfloat black[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat yellow[] = { 1.0, 1.0, 0.0, 1.0 };
	GLfloat cyan[] = { 0.0, 1.0, 1.0, 1.0 };
	GLfloat white[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat direction[] = { 1.0, 1.0, 1.0, 0.0 };

	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, cyan);
	glMaterialfv(GL_FRONT, GL_SPECULAR, white);
	glMaterialf(GL_FRONT, GL_SHININESS, 80);

	glLightfv(GL_LIGHT0, GL_AMBIENT, black);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, yellow);
	glLightfv(GL_LIGHT0, GL_SPECULAR, white);
	glLightfv(GL_LIGHT0, GL_POSITION, direction);

	glEnable(GL_LIGHTING);                // so the renderer considers light
	glEnable(GL_LIGHT0);                  // turn LIGHT0 on
	glEnable(GL_DEPTH_TEST);              // so the renderer considers depth
    glClearColor(0.1, 0.39, 0.88, 1.0);
	glShadeModel(GL_FLAT);
	//glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();
	//1.f, 1.f, 1.f, -1.f, -1.f, -1.f, 0.f, 1.f, 0.f
	//gluLookAt(4, 2, 8, 0, 0, 0, 0, 1, 0);

}
vector<string> getSupportedExtensions() 
{
	PFNGLGETSTRINGIPROC glGetStringi = NULL;
	glGetStringi = (PFNGLGETSTRINGIPROC)wglGetProcAddress("glGetStringi");
	vector<string> extensions;
	if (glGetStringi == NULL) {
		return extensions;
	}
	else {
		GLint numExtensions = 0;
		glGetIntegerv(GL_NUM_EXTENSIONS, &numExtensions);
		for (int i = 0; i < numExtensions; i++) {
			extensions.push_back((const char*)glGetStringi(GL_EXTENSIONS, i));
		}
		return extensions;
	}
}
bool isExtensionSupported(const string& ext)
{
	vector<string> extensions = getSupportedExtensions();
	for (vector<string>::iterator it = extensions.begin(); it != extensions.end(); ++it) {
		if (*it == ext) {
			return true;
		}
	}
	return false;
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(80, 80);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Learning OpenGL");
	glutDisplayFunc(display4);
    glutReshapeFunc(reshape2);
    glutSpecialFunc(special);
	glutKeyboardFunc(keyNormal);
	init2();
	glutMainLoop();
}
//int main(int argc, char* argv[])
//{
//
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
//    glutInitWindowSize(WIDTH, HEIGHT);
//    glutInitWindowPosition(100, 100);
//    glutCreateWindow("OpenGL su primo");
//    glewInit();
//
//    initOpenGL();
//    //calls "display" everyframe
//    glutDisplayFunc(display3);
//
//    //glutIdleFunc(display3);
//    init();
//    //glutReshapeFunc(reshape);
//    glutMainLoop();
//    //Initialize();
//    //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//    //glLoadIdentity();
//    //gluLookAt(0.0, 1.0, 6.0,//Position
//    //    0.0, 0.0, 0.0, //Where we are looking
//    //    0.0, 1.0, 0.0);//Up Vector
//    //glBegin(GL_TRIANGLES);
//    //glColor4f(1.f, 0.f, 0.f, 1.f);
//    //glVertex3f(2.f, 2.5f, -1.f);
//    //glColor4f(0.f, 1.f, 0.f, 1.f);
//    //glVertex3f(-3.5f, -2.5f, -1.f);
//    //glColor4f(0.f, 0.f, 1.f, 1.f);
//    //glVertex3f(2.f, -4.0f, -1.f);
//    //glEnd();
//    // 
//    //// Initialize GLUT
//    //glutInit(&argc, argv);
//    //// Set up some memory buffers for our display
//    //glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
//    //// Set the window size
//    //glutInitWindowSize(800, 600);
//    //// Create the window with the title "Hello,GL"
//    //glutCreateWindow("Hello, GL");
//    //// Bind the two functions (above) to respond when necessary
//    //glutReshapeFunc(changeViewPort);
//    //glutDisplayFunc(render);
//
//    //// Very important!  This initializes the entry points in the OpenGL driver so we can 
//    //// call all the functions in the API.
//    //GLenum err = glewInit();
//    //if (GLEW_OK != err) {
//    //    fprintf(stderr, "GLEW error");
//    //    return 1;
//    //}
//
//
//    //glutMainLoop();
//    //return 0;
//
//
//    ////Initialize GLFW
//    //glfwInit();
//    ///*
//    //* Tell GLFW what version we are using
//    //* In this case we are using 3.3 (major:3 . minor:3)
//    //*/
//    //glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//    //glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//    ////Tell GLFW we are using the CORE profile
//    //glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//    ////Create a window with 800 x 800 dimesions, named "OpenGL"
//    //GLFWwindow* window = glfwCreateWindow(WIDTH,HEIGHT, "OpenGL", NULL, NULL);
//    ////Check if it fails to create the window
//    //if (window == NULL) {
//    //    cout << "Failed to create GLFW window" << endl;
//    //    return EXIT_FAILURE;
//    //}
//    //// Introduce the window into the current context
//    //glfwMakeContextCurrent(window);
//    ////Specifies the viewport of OpenGL  in the window
//    //// in this case goes from x=0,y=0 to WIDTH and HEIGHT
//    //glViewport(0, 0, WIDTH, HEIGHT);
//    ////Specifies the color background
//    //glClearColor(0.07f, 0.13f, 0.17f, 1.f);
//    ////Clear the back buffer and assign a new color to it
//    //glClear(GL_COLOR_BUFFER_BIT);
//    ////Swap the back buffer with the front buffer
//    //glfwSwapBuffers(window);
//    //while (!glfwWindowShouldClose(window)) {
//    //    //Take care of all GLFW events
//    //    glfwPollEvents();
//    //}
//
//    //glfwDestroyWindow(window);
//    //glfwTerminate();
//    //
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//    //glViewport(0, 0, WIDTH, HEIGHT);
//    //glBegin(GL_TRIANGLES);
//    //glColor3f(1.f, 0.f, 0.f); glVertex3f(0.f, 1.f, 0.f);
//    //glColor3f(0.f, 1.f, 0.f); glVertex3f(-1.f, -1.f, 0.f);
//    //glColor3f(0.f, 0.f, 1.f); glVertex3f(1.f, -1.f, 0.f);
//    //glEnd();
//
//
//    ///////////Inicializa openGL
//    //glfwInit();
//    ////Especificamos la versión de OpenGL
//    ////glfwWindowHint especifica las caracteristicas de la ventana
//    //glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//    //glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//    //glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
//    //glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
//    ////^Copia estos glfwWindowHint para tus proyectos
//
//    ////Creamos una ventana
//    //GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Learning OpenGL", nullptr, nullptr);
//
//    //int screenWidth, screenHeight;
//
//    ////partiendo de la ventana, sacamos las medidas
//    //glfwGetFramebufferSize(window, &screenWidth, &screenHeight);
//
//    //if (nullptr == window) {
//
//    //    std::cout << "Failed to create GLFW window" << std::endl;
//    //    //Si falla, termina glfw
//    //    glfwTerminate();
//
//    //    return EXIT_FAILURE;
//    //}
//
//    //glfwMakeContextCurrent(window);
//
//    //glewExperimental = GL_TRUE;
//
//    //if (GLEW_OK != glewInit()) {
//
//    //    std::cout << "Failed to initialize GLEW" << std::endl;
//
//    //    return EXIT_FAILURE;
//    //}
//    ////Crea el viewport y sus dimensiones
//    //glViewport(0, 0, screenWidth, screenHeight);
//
//    //glEnable(GL_BLEND);
//    //glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//
//
//    //Shader ourShader=Shader("core.vs", "core.frag");
//    //GLfloat vertices[] = {
//    //    //position,          //color        //Texture coordinates
//    //    0.5f,0.5f,0.0f,     1.f,0.f,0.f,    1.f,1.f,
//    //    0.5f,-0.5f,0.f,     1.f,1.f,1.f,    1.f,0.f,
//    //    -0.5f,-0.5f,0.f,    1.f,0.f,0.f,    0.f,0.f,
//    //    -0.5f,0.5f,0.f,     1.f,0.f,1.f,    0.f,1.f
//    //};
//    //GLuint indices[] =
//    //{
//    //    0,1,3//First Triangle
//    //    ,1,2,3 //Second Triangle
//    //};
//    //GLuint VBO, VAO,EBO;
//    //glGenVertexArrays(1, &VAO);
//    //glGenBuffers(1, &VBO);
//    //glGenBuffers(1,&EBO);
//
//    //glBindVertexArray(VAO);
//
//    //glBindBuffer(GL_ARRAY_BUFFER, VBO);
//    //glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//    //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//    //glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
//    ////Position attribute
//    //glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);
//    //glEnableVertexAttribArray(0);
//    ////Color attribute
//    //glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3*sizeof(GLfloat)));
//    //glEnableVertexAttribArray(1);
//    ////Texture coordinates attributes
//    //glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
//    //glEnableVertexAttribArray(2);
//
//    //glBindVertexArray(0);//Unbind VAO
//
//    //GLuint texture;
//    //int width, height;
//    //glGenTextures(1, &texture);
//    //glBindTexture(GL_TEXTURE_2D,texture);
//
//    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//    //
//    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//
//    //unsigned char* image = SOIL_load_image("EGC.jpeg",&width,&height,0,SOIL_LOAD_RGBA);
//    //glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,width,height,0,GL_RGBA,GL_UNSIGNED_BYTE,image);
//    //glGenerateMipmap(GL_TEXTURE_2D);
//    //SOIL_free_image_data(image);
//    //glBindTexture(GL_TEXTURE_2D, 0);
//    //while (!glfwWindowShouldClose(window)) {
//
//    //    // esta función chequea si hay events/inputs
//    //    //Handle game logic
//    //    glfwPollEvents();
//
//    //    //Render(color del fondo)
//    //    glClearColor(0.5f, 0.1f, 0.2f, 1.f);
//    //    glClear(GL_COLOR_BUFFER_BIT);
//
//    //    //Dibuja el triángulo
//    //    ourShader.Use();
//
//    //    glActiveTexture(GL_TEXTURE);
//    //    glBindTexture(GL_TEXTURE_2D, texture);
//    //    glUniform1i(glGetUniformLocation(ourShader.Program, "ourTexture"), 0);
//
//
//    //    glBindVertexArray(VAO);
//    //    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
//    //    glBindVertexArray(0);
//
//    //    //draw opengl stuff
//    //    //Necesita que el windows se le haga un glfwmakecontextcurrent
//    //    glfwSwapBuffers(window);
//    //}
//
//    //glDeleteVertexArrays(1, &VAO);
//    //glDeleteBuffers(1, &VBO);
//    //glDeleteBuffers(1, &EBO);
//    //glfwTerminate();
//
//    return EXIT_SUCCESS;
//
//}