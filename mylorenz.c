/**
*@file: 	mylorenz.c
*
*@description:  A C file that contains all the functions that are neccessary to generate a Lorenz
*		attractor
*
*@reference:
*
*@author: 	Diptarshi Chakraborty
*
*@date: 	05-09-2019
*
*/


/**
*@func: 	gen
*
*@description:  a function that simply generates the lorenz co-ordinates and stores them
*		in an array. You have to provide array and the number of elements n
*
*
*@param:	int array[][], int n
*
*@return:	void
*
*@reference:	Referenced from code provided by mr William Schreuder for class CSCI 5229
*		URL:http://www.prinmath.com/csci5229/misc/lorenz.c
*
*@todo:
*/

void gen(int arr[][],int n, double s, double b, double r)
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

	for(int i = 0; i < n; i++)
	{

		delta_x = s*(y - x);
		delta_y = x*(r - z) -y;
		delta_z = x*y - b*z;

		x = x + delta_t * delta_x;
		y = y + delta_t * delta_y;
		z = z + delta_t * delta_z;

		arr[i][0] = x;
		arr[i][1] = y;
		arr[i][2] = z;

	}



}


