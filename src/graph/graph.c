#include "graph.h"

void initnodes(){
	int i;
    array = malloc(sizeof(gnode)*nodes);
    double e=2*w/5;
    double f=2*h/5;
	for(i=0;i<nodes;i++){
   		array[i].x=(w/2)+e*sin(i*2*PI/nodes);
   		array[i].y=(h/2)+f*cos(i*2*PI/nodes);   	   		   	
   		}
	
	}
	
void keyboard(unsigned char key, int x, int y)
{
   switch (key) {
      case 27:
         exit(0);
         break;
   }
}

// String Plotting Function 
void write_string( const unsigned char *s, GLfloat  x,  GLfloat  y )
{
    glColor3d( 2, 2, 2 );
    glRasterPos3f(x-9,y-9, 0 );
    glutBitmapString( font, s );
}
//String Plotting Function - S => smaller font
void write_strings( const unsigned char *s,GLfloat  x,  GLfloat  y )
{
    glColor3d( 2, 2, 2 );
    glRasterPos3f(x-9,y-9, 0 );
    glutBitmapString( GLUT_BITMAP_HELVETICA_10 , s );
}

/// Graph plotting function
void goplot(){
	int j,k;
	const unsigned char buffer[24];
	gedge matrix[20][20];
/*	matrix[0][1].weight=2;
	matrix[1][2].weight=1;
	matrix[1][3].weight=12;
	matrix[1][5].weight=-2;
	matrix[5][4].weight=-1;
	matrix[6][3].weight=-12;
*/	for(j=0;j<nodes;j++){
		for(k=0;k<nodes;k++){
			if(j!=k&&j!=k-1&&k!=j-1&&j!=k-3&&k!=j-3){
				matrix[j][k].weight=j+k+j;
				matrix[j][k].visited=0;
				}
			else{
				matrix[j][k].weight=0;
				matrix[j][k].visited=0;
				}
			}
		}
	for(j=0;j<nodes;j++){
		for(k=0;k<nodes;k++){
			if(matrix[j][k].weight!=0){
	   			if(matrix[j][k].weight==matrix[k][j].weight){
	   				if(j<k){
	   					sprintf(buffer, "<->%.3f",matrix[j][k].weight);
   						write_strings( buffer ,(((array[j].x)+(array[k].x))/2)+10,(((array[k].y)+(array[j].y))/2)+10);
						drawOneLine (array[j].x,array[j].y,array[k].x,array[k].y);
	   					}
	   				}
				else{
					if(j>k){
						sprintf(buffer, "->%.3f",matrix[j][k].weight);
	   					write_strings( buffer ,(((array[j].x)+(array[k].x))/2)+10,(((array[k].y)+(array[j].y))/2)+10);
						drawOneLine (array[j].x,array[j].y,array[k].x,array[k].y);
						}
					else{
						sprintf(buffer, "<-%.3f",matrix[j][k].weight);
	   					write_strings( buffer ,(((array[j].x)+(array[k].x))/2)-10,(((array[k].y)+(array[j].y))/2)-10);
						drawOneLine (array[j].x,array[j].y,array[k].x,array[k].y);
						}
					}
				}
			}
		}
	}
	
/*
 * The main display rendering function 
 */
void cb_display( void )
{
    int i;
    double j;
    const unsigned char buffer[24];
    glPointSize(1.0f);
    glClear (GL_COLOR_BUFFER_BIT);
	//plot lines between nodes
	goplot();
	
	// draw nodes
	for(i=0;i<nodes;i++){
   		sprintf(buffer, "%d",i+1);
   		write_string( buffer ,array[i].x,array[i].y);	
		drawCircle(array[i].x,array[i].y,20);
		/*for(j=0;j<2*PI;j+=0.001){
			glBegin(GL_POINTS); 
    		glVertex3f((array[i].x+20*cos(j)),(array[i].y+20*sin(j)),0);
    		glEnd();
   		  	}*/    	   		   	
   		}
	
    glFlush();
    glutSwapBuffers( );    
	
}

/// Helper function to reshape the window
void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   gluOrtho2D (0.0, (GLdouble) w, 0.0, (GLdouble) h);
}

