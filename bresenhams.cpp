#include <windows.h>
#include <GL/glut.h>
#include <stdio.h>


void plotPixelGreen(int x, int y) {
    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void plotPixelWhite(int x, int y) {
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void plotPixelCyan(int x, int y) {
    glColor3f(0.0f, 1.0f, 1.0f);
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void plotPixelBlue(int x, int y) {
    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void bresenhams(int x1, int y1, int x2, int y2) {
    int x = x1, y = y1;
    int dx = x2 - x1;
    int dy = y2 - y1;

    double m = double(dy) / double(dx);

    // Case 01
    if (0 <= m and m <= 1) {
        plotPixelGreen(x, y);
        int pk = 2 * dy - dx;
        for (int i = 0; i < (x2 - x1); ++i) {
            if (pk < 0) {
                x += 1;
                pk = pk + 2 * dy;
            }
            else {
                x += 1;
                y += 1;
                pk = pk + 2 * dy - 2 * dx;
            }
            plotPixelGreen(x, y);
        }
    }

    // Case 2
    if (m > 1) {
        plotPixelCyan(x, y);
        int pk = 2 * dx - dy;
        for (int i = 0; i < (y2 - y1); ++i) {
            if (pk < 0) {
                y += 1;
                pk = pk + 2 * dx;
            }
            else {
                x += 1;
                y += 1;
                pk = pk + 2 * dx - 2 * dy;
            }
            plotPixelCyan(x, y);
        }
    }

    // Case 3
    if (m < 0 && m >= -1) {
        plotPixelBlue(x, y);
        int pk = 2 * dy - dx;
        for (int i = 0; i < (x2 - x1); ++i) {
            if (pk < 0) {
                x += 1;
                pk = pk + 2 * (y1 - y2);
            }
            else {
                x += 1;
                y -= 1;
                pk = pk + 2 * (y1 - y2) - 2 * dx;
            }
            plotPixelBlue(x, y);
        }
    }

    // Case 4
    if (m < -1) {
        plotPixelWhite(x, y);
        int pk = 2 * dx - dy;
        for (int i = 0; i < (y1 - y2); ++i) {
            if (pk < 0) {
                y -= 1;
                pk = pk + 2 * dx;
            }
            else {
                x += 1;
                y -= 1;
                pk = pk + 2 * dx - 2 * (y1 - y2);
            }
            plotPixelWhite(x, y);
        }
    }

}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    bresenhams(20, 20, 380, 280);
    bresenhams(20, 20, 280, 380);
    bresenhams(20, 20, 380, -280);
    bresenhams(20, 20, 280, -380);
    glFlush();
}



int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Bresenhams Line Algo");
    glOrtho(-500, 500, -500, 500, -500, 500);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
