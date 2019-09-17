/**
*@file:         main.c
*
*@description:  main C file
*
*
*@reference:
*
*@author:       Diptarshi Chakraborty
*
*@date:         05-09-2019
*
*/

/*C STL header files for standard I/0 operations that print to the terminal */

#include <stdio.h>
#include <stdlib.h>

#define GL_GLEXT_PROTOTYPES

#ifdef __APPLE__
#include <GLUT/glut.h>

#else
#include <GL/glut.h>
#endif




#define		Global_N	(50000)

double array[Global_N][3];

double s = 10;
double b = 2.6;
double r = 28;



/**
*@func:         gen
*
*@description:  a function that simply generates the lorenz co-ordinates and stores$
*               in an array. You have to provide array and the number of elements n
*
*
*@param:        int array[][], int n
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
        double x = 1;
        double y = 1;
        double z = 1;

        double delta_x;
        double delta_y;
        double delta_z;

        /*Time Step*/

        double delta_t = 0.001;

        for(int i = 0; i < Global_N; i++)
        {

                delta_x = s*(y - x);
                delta_y = x*(r - z) -y;
                delta_z = x*y - b*z;

                x = x + delta_t * delta_x;
                y = y + delta_t * delta_y;
                z = z + delta_t * delta_z;

                array[i][0] = x * 0.02;
                array[i][1] = y * 0.02;
                array[i][2] = z * 0.02;
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
*@todo:
*/

void lorenz_curve()
{

	gen();

	glPointSize(5);
	glBegin(GL_LINE_STRIP);

	for (int i=0;i<Global_N;i++)
  	{

		glColor3ub(i % 255,i % 128,  i % 64);
		glVertex3d(array[i][0]/2,array[i][1]/2,array[i][2]/2);
		glVertex3dv(array[i]);;

  	}

	glEnd();

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
*reference:     
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

	glRotated(30,1,0,0);
  	glRotated(30,0,1,0);

        /*calling function lorenz_curve to draw the curve*/
        lorenz_curve();



        /*This will help flush out the old pixels and bring new ones*/
        glFlush();
        glutSwapBuffers();


}

/**
*@func:		display
*
*@description:
*
*@void:		void
*
*@return:	void
*
*/

void display()
{

	mydisplay();
	glutPostRedisplay();
	s=s+1;
        b+=0.5;
        r+=1;

}

/**
*@func: 	draw_x_y_z
*
*@description:	Helps draw the X Y and Z access
*
*@param:	void
*
*@return:	void
*
*@reference:	void
*/
void draw_x_y_z()
{




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
   	double w2h = (height>0) ? (double)width/height : 1;

	/*  Set viewport as entire window */
   	glViewport(0,0, width,height);

	/* Select projection matrix */
   	glMatrixMode(GL_PROJECTION);

	/*  Set projection to identity */
   	glLoadIdentity();

	/*  Orthogonal projection:  unit cube adjusted for aspect ratio*/
   	glOrtho(-w2h*dimension,+w2h*dimension, -dimension,+dimension, -dimension,+dimension);

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
*@return:       void
*
*@reference:    N/A
*
*@todo:		add interaction API calls
*/

int main(int argc, char *argv[])
{



	glutInit(&argc, argv);

	/*Initializing display modes*/

	glutInitDisplayMode(GLUT_RGB |  GLUT_DOUBLE);

	/*Initializing window position*/

	glutInitWindowPosition(100,100);

	/*Now I am fixing the window size to 720 * 640*/
	glutInitWindowSize(720,640);

	/*Naming the window*/
	glutCreateWindow("Lorentz Attractor by Diptarshi ");

	/*Now Display the figure*/
	glutDisplayFunc(display);

	/*Reshape function*/
	glutReshapeFunc(reshape);


	/*glutMainLoop enters the GLUT event processing loop*/
	glutMainLoop();

	return 0;


}

