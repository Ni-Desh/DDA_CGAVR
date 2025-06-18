#include <stdlib.h>
#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>

float x1, x2, y1, y2;

void display(void) {
    float dx, dy, step, x, y, Xin, Yin;
    int i;

    // Calculate dx, dy
    dx = x2 - x1;
    dy = y2 - y1;

    // Determine steps required
    if (abs(dx) > abs(dy)) {
        step = abs(dx);
    } else {
        step = abs(dy);
    }

    // Calculate increments
    Xin = dx / step;
    Yin = dy / step;

    // Set initial point
    x = x1;
    y = y1;

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0); // Line color (White)
    glPointSize(2.0); // Set thickness to 2.0
    glBegin(GL_POINTS);

    // Plot the points step by step
    for (i = 0; i <= step; i++) {
        glVertex2i((int)(x + 0.5), (int)(y + 0.5)); // Round-off for proper plotting
        x += Xin;
        y += Yin;
    }

    glEnd();
    glFlush();
}

void myInit(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0); // Background color (Black)
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0); // Set coordinate system
}

int main(int argc, char **argv) {
    printf("Enter x1, y1: ");
    scanf("%f %f", &x1, &y1);
    printf("Enter x2, y2: ");
    scanf("%f %f", &x2, &y2);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 150);
    glutCreateWindow("DDA Line Algorithm");
    myInit();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}

