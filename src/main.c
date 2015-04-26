#include "graph.h"

int main(int argc, char *argv[]){
    unsigned int i;
	GLfloat  x,y;
	initnodes();
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glutInit( &argc, argv );
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (w, h); 
    glutCreateWindow( "TEST WINDOW" );
    glutDisplayFunc( cb_display);
    font = GLUT_BITMAP_TIMES_ROMAN_24;//GLUT_BITMAP_8_BY_13;
    glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
    glutMainLoop( );

    return 1;
}
