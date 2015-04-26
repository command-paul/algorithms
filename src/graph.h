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

#include <stdlib.h>
#include<math.h>
#include<GL/gl.h>
#include <stdio.h>
#include <GL/freeglut.h>
#include "SOIL.h"
#define PI 3.1415926535897932

#define drawOneLine(x1,y1,x2,y2)  glBegin(GL_LINES);  \
   glVertex2f ((x1),(y1)); glVertex2f ((x2),(y2)); glEnd();

#define drawSolidCircle(x,y,r) for(angle=0;angle<2*PI;angle+=0.001){ \
			drawOneLine(x,y,(x+r*cos(angle)),(y+r*sin(angle)));} // solid circle

#define drawHollowCircle(x,y,r) for(angle=0;angle<2*PI;angle+=0.001){ \
			glBegin(GL_POINTS); glVertex3f((x+r*cos(angle)),(y+r*sin(angle)),0); glEnd();}  // empty circle
#define PRINT_ERROR_MACRO printf("Error: %s\n", iluErrorString(Error))

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

typedef struct kruscals{
	int x;
	int y;
	int weight;
	}kruscals;
	
typedef struct ll{
	struct ll*next;
	int current;
	int previous;
	}ll;
	


double h = 768;			///height
double w = 768;			///width
void *font; 			// global font
char buffer[24];		//global text buffer
double nodes = 5;		// nodes definition
gnode* array;			// node daatabase 
int showWeights = 0;
void initnodes();
gedge** Graph;
gedge** output; //Always use this to print graphs
gedge** initialise();

void initgui(int argc, char *argv[]);
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

void setShowWeights(int val);
/*
 * The main display rendering function 
 */
void cb_display( void );

/// Helper function to reshape the window
void reshape (int w, int h);

void makegraph();

/* Function Add Edge on the adjcency matrix  */

void addedge(gedge** holder,int node1,int node2,int directed,int weight);
/* Function Delete Edge  */

void deledge(gedge** holder,int nodes,int node1,int node2,int directed);
// Function Print in list form 
void printmtx(gedge** holder);
// debug print matrix
void printer(gedge** matrix);
// int has been visited
int visited(gedge** matrix,int nodes,int node);

gedge** dijkstras(gedge** matrix,int nodes);
	
//// Kruscals Algorithm
gedge** kruscal(gedge** matrix);

void setNodes();


#endif
