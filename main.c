/**
*@file:         main.c
*
*@description:  main C file
*
*@author:       Diptarshi Chakraborty
*
*@date:         19-09-2019
*
*/

/*C STL header files for standard I/0 operations that print to the terminal */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#define GL_GLEXT_PROTOTYPES

#ifdef __APPLE__
#include <GLUT/glut.h>

#else
#include <GL/glut.h>
#endif




#define		Global_N	(70000)

double array[Global_N][3];

double s = 10;
double b = 2.6;
double r = 50;

int alpha=10;
int theta=10;


/**
*@func:		my_Custom_print
*
*@description:	Helps map characters to the console
*
*@param:	const char* a
*
*@return:	void
*/

void my_Custom_print(const char* a , ...)
{
	char CAP[1024];
	char * cap=CAP;
	va_list arguments;
	va_start(arguments, a);
	vsnprintf(CAP,1024,a,arguments);
	va_end(arguments);

	while(*CAP)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*cap);

	}


}

/**
*@func:         gen
*
*@description:  a function that simply generates the lorenz co-ordinates and stores$
*               in an array. You have to provide array and the number of elements n
*
*
*@param:        void
*
*@return:       void
*
*@reference:    Referenced from code provided by mr William Schreuder for class CSC$
*               URL:http://www.prinmath.com/csci5229/misc/lorenz.c
*
*@todo:
*/

void gen()
{

        /*  Coordinates  */
        double x = -1;
        double y = -1;
        double z = -1;

        double delta_x;
        double delta_y;
        double delta_z;

        /*Time Step*/

        double delta_t = 0.005;

        for(int i = 0; i < Global_N; i++)
        {

                delta_x = s*(y - x);
                delta_y = x*(r - z) -y;
                delta_z = x*y - b*z;

                x = x + delta_t * delta_x;
                y = y + delta_t * delta_y;
                z = z + delta_t * delta_z;

                array[i][0] = x * 0.04;
                array[i][1] = y * 0.04;
                array[i][2] = z * 0.04;
        }

}

/**
*@func:         lorenz_curve
*
*@description
*
*@param:        array[][3]
*
*@return:       void
*
*@references:	http://www.prinmath.com/csci5229/F19/handouts/20190926a.pdf
*/

void lorenz_curve()
{

	gen();

	glPointSize(5);
	glBegin(GL_LINE_STRIP);

	for (int i=0;i<Global_N;i++)
  	{

		/*For adding shades of color*/
		glColor3ub(i % 200,i % 100,  i % 75);
		glVertex3d(array[i][0]/3,array[i][1]/3,array[i][2]/2);
		glVertex3dv(array[i]);;

  	}

	glEnd();

}

/**
*@func:         draw_x_y_z
*
*@description:  Helps draw the X Y and Z access. This actually uses
		the concept of lines to draw the X Y and Z axes on 
		the screen and then display axes labels
*
*@param:        void
*
*@return:       void
*/

void draw_x_y_z()
{

	glPointSize(2);
        glColor3f(1,1,1);
        glBegin(GL_LINES);

        /*X Axis*/
        glVertex3d(-1,-1,-1);
        glVertex3d(15,-1,-1);

        /*Y Axis*/
        glVertex3d(-1,-1,-1);
        glVertex3d(-1,15,-1);

        /*Z Axis*/
        glVertex3d(-1,-1,-1);
        glVertex3d(-1,-1,15);

	//glRasterPos3d(-1,0,0);
    	//my_Custom_print("X");

	//glRasterPos3d(0,-1,0);
    	//my_Custom_print("Y");

	//glRasterPos3d(0,0,-1);
    	//my_Custom_print("Z");

        glEnd();
}


/**
*@func:		change_Param
*
*@description:	Helps map keyboard keys for interaction with the image
*		The project needed me to allow myself to interact with
*		the behaviour of the lorentz attractor. So for that,I
*		have bound a few keys that would change s, b, and r
*		and allow us to witness changes in the lorenz attractor.
*
*@param:	unsigned char key, int x, int y
*
*@return:	void
*
*/

void change_Param(unsigned char key, int x, int y)
{
	switch(key)

	{
		case('s'):
		s = s + 3;
		break;

		case('x'):
		s = s - 3;
		break;

		case('d'):
		b = b + 3;
		break;

		case('c'):
                b = b - 3;
                break;

		case('f'):
                r = r + 3;
                break;

		case('v'):
                r = r - 3;
                break;
	}

	 glutPostRedisplay();

}

/**
*@func:		arrow_key_move
*
*
*@description:	this function allows me to use arrow keys 
*		The Up arrow key gives you the top view of the graphic
*		The Down arrow key gives you the bottom view of the graphic
*
*@param:	int key, int x, int y
*
*@return:	void
*
*@reference:	
*
*/

void arrow_keys_move(int key, int x, int y)
{
	switch(key)
	{
		case GLUT_KEY_UP:
		alpha++;
		theta %= 360; /*Helps angles be within the margin of 360*/
   		alpha %= 360; /*Helps angles be within the margin of 360*/
		glutPostRedisplay();
		break;

		case GLUT_KEY_DOWN:
		alpha--;
		theta %= 360;/*Helps angles be within the margin of 360*/
   		alpha %= 360;/*Helps angles be within the margin of 360*/
		glutPostRedisplay();
		break;

		case GLUT_KEY_LEFT:
                theta++;
		theta %= 360;/*Helps angles be within the margin of 360*/
   		alpha %= 360;/*Helps angles be within the margin of 360*/
		glutPostRedisplay();
                break;

                case GLUT_KEY_RIGHT:
                theta--;
		theta %= 360;/*Helps angles be within the margin of 360*/
   		alpha %= 360;/*Helps angles be within the margin of 360*/
		glutPostRedisplay();
                break;

	}
}

/**
*@func:         mydisplay
*
*@description:  main display function that renders the image called by GLUT
*
*@param:        void
*
*@return:       void
*
*todo:		add variable angle functionality
*/

void mydisplay()
{

        /*This function helps clear the color buffer bit. The screen then clears*/
        glClear(GL_COLOR_BUFFER_BIT);

        /*This helps reset the previous changes that were made and
         clears the slate*/
        glLoadIdentity();

	glRotated(alpha,1,0,0);
  	glRotated(theta,0,1,0);


	/*Calling the draw_x_y_z function*/
	draw_x_y_z();

        /*calling function lorenz_curve to draw the curve*/
        lorenz_curve();



        /*This will help flush out the old pixels and bring new ones*/
        glFlush();
        glutSwapBuffers();


}

/**
*@func:		display
*
*@description:	wrapper around mydisplay
*
*@void:		void
*
*@return:	void
*
*/

void display()
{

	mydisplay();

}


/**
*@func:		reshape
*
*@description:	handles the reshaping of the window
*
*@param:	int width, int height
*
*@return:	void
*
*@reference:
*/

void reshape(int width,int height)
{
    	double dimension = 3.0;

	/* Calculate width to height ratio*/
   	double widht2height = (height>0) ? (double)width/height : 1;

	/*  Set viewport as entire window */
   	glViewport(0,0, width,height);

	/* Select projection matrix */
   	glMatrixMode(GL_PROJECTION);

	/*  Set projection to identity */
   	glLoadIdentity();

	/*  Orthogonal projection:  unit cube adjusted for aspect ratio*/
   	glOrtho(-widht2height*dimension,+widht2height*dimension, -dimension,+dimension, -dimension,+dimension);

	/*  Select model view matrix*/
   	glMatrixMode(GL_MODELVIEW);

	/*  Set model view to identity*/
   	glLoadIdentity();
}




/**
*@func:         main
*
*@description:  main function that is the entry point of the program
*
*
*@param:        int argc, char argv[][]
*
*@return:       int
*
*@todo:		add interaction API calls
*/

int main(int argc, char *argv[])
{


	/*Initialize using command line arguments*/
	glutInit(&argc, argv);

	/*Initializing display modes*/
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH |  GLUT_DOUBLE);

	/*Initializing window position*/
	glutInitWindowPosition(30,30);

	/*Now I am fixing the window size to 720 * 640*/
	glutInitWindowSize(720,640);

	/*Naming the window*/
	glutCreateWindow("Lorenz Attractor by Diptarshi ");

	/*Now Display the figure*/
	glutDisplayFunc(display);

	/*Reshape function*/
	glutReshapeFunc(reshape);

	/*Function for mapping the keyboard params*/
	glutKeyboardFunc(change_Param);

	/*Use arrow keys to change the viewing angles*/
	glutSpecialFunc(arrow_keys_move);

	/*glutMainLoop enters the GLUT event processing loop*/
	glutMainLoop();

	return 0;


}

