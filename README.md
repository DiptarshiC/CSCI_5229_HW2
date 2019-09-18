# About this Project

## Author : Diptarshi Chakraborty

## Objective
 
The objective of this file is to simulate the lorenz attractor graphically and to understand the
physical concept behind it to illustrate a real-world phenomenon.For this I ultilize the openGL
graphics libraries and a linux environment.

## Program Flow
The flow of the program is as follows

1. First the main function is started with the commandline arguments
2. The mode of display is the initialized
3. The size window that will display my project my projects is set
4. The window is named with a particular name
5. Using the function pointed by the api glutDisplayFunc() the main function that displays my project is called
6. After this, all the functions flow around in a sort of a while loop
	glutReshapeFunc() : 	handles the reshaping of the Window and the corresponding image
	glutKeyboardFunc() : 	supports an event driven utlity that handles keyboard presses
	glutMainLoop(): 	Allows us to loop through the main function.


## What this repository contains

1. source file 
2. Makefile
3. README.md file

## Platform information

#### Operating system 		: Linux (Ubuntu)
#### Processor Architecture	: Intel X86/64

## Software Requirements

#### 1. GNU (Make), Compiler toolchain
#### 2. OpenGL graphics library

## Steps to install OpenGL and build this project

**The steps to install OpenGL on linux (ubuntu) are as follows**

1. run "sudo apt install freeglut3-dev"
2. run "sudo apt install binutils-gold g++ cmakelibglew-dev g++ mesa-common-dev build-essential libglew1.5-dev libglm-dev"
3. run "sudo apt install mesa-utils"

**The steps to build this project are as follows**

1. run "git clone https://github.com/DiptarshiC/CSCI_5229_HW2"
2. run "cd CSCI_5229_HW2"
3. run "make"

## Key Bindings to interact with the Animation



# References

1. [link] http://www.prinmath.com/csci5229/misc/lorenz.c
2. [link] http://www.opengl-tutorial.org
3. [link] http://mathworld.wolfram.com/LorenzAttractor.html


