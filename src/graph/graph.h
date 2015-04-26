/*!
 * \file graph.h
 *
 * \author Paul George(coolkid)
 * \date 17 April 2015
 *
 * This file contains function declarations for various types of sorting functions
 *
 */
#ifndef GRAPH_H_
#define GRAPH_H_

#define PI 3.1415926535897932

#define drawOneLine(x1,y1,x2,y2)  glBegin(GL_LINES);  \
   glVertex2f ((x1),(y1)); glVertex2f ((x2),(y2)); glEnd();

#define drawCircle(x,y,r) double angle;for(angle=0;angle<2*PI;angle+=0.001){ \
			glBegin(GL_POINTS); glVertex3f((x+r*cos(angle)),(y+r*sin(angle)),0); glEnd();} 

#include <stdlib.h>
#include<math.h>
#include<GL/gl.h>
#include <stdio.h>
#include <GL/freeglut.h>

typedef struct gnode{
	double x;
	double y;
	}gnode;
	
typedef struct gedge{
	double weight;
	int visited;
	}gedge;	
	
typedef struct dijkstras{
	int origin;
	int weight;
	}dijk;

/*
 * This structure is used to simplify associating a GLUT font
 * with a GLUT menu item.
 */
struct font_map
{
    void *id;
    const char *const name;
};

double h = 700;			///height
double w = 700;			///width
void *font; 			// global font
const unsigned char buffer[24];		//global text buffer
double nodes = 5;		// nodes definition
gnode* array;			// node daatabase 

void initnodes();




/*
Some Sample Fonts
    {GLUT_BITMAP_8_BY_13,        "Fixed 8x13"},
    {GLUT_BITMAP_9_BY_15,        "Fixed 9x15"},
    {GLUT_BITMAP_TIMES_ROMAN_10, "Times Roman 10"},
    {GLUT_BITMAP_TIMES_ROMAN_24, "Times Roman 24"},
    {GLUT_BITMAP_HELVETICA_10,   "Helvetica 10"},
    {GLUT_BITMAP_HELVETICA_12,   "Helvetica 12"},
    {GLUT_BITMAP_HELVETICA_18,   "Helvetica 18"},
*/

/// waiting for keyboard input to exit key 27 :: ESCAPE 
void keyboard(unsigned char key, int x, int y);

// String Plotting Function 
void write_string( const unsigned char *s,GLfloat  x,  GLfloat  y );

//String Plotting Function - S => smaller font
void write_strings( const unsigned char *s,GLfloat  x,  GLfloat  y );

/// Graph plotting function
void goplot();


/*
 * The main display rendering function 
 */
void cb_display( void );

/// Helper function to reshape the window
void reshape (int w, int h);



#endif
