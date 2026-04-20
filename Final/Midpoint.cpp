#include <bits/stdc++.h>
#include <windows.h>
#include <GL/glut.h>
using namespace std;

void init() {
  glClearColor(1, 1, 1, 1);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  gluOrtho2D(-500, 500, -500, 500);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void drawCircleMidpoint(float cx, float cy, float r) {
  float pk = 1 - r;
  float x = 0, y = r;

  glBegin(GL_POINTS);
  glColor3f(1.0f, 0.0f, 0.0f);

  while (x <= y) {
    glVertex2f(x + cx, y + cy);
    glVertex2f(y + cx, x + cy);
    glVertex2f(y + cx, -x + cy);
    glVertex2f(x + cx, -y + cy);
    glVertex2f(-x + cx, -y + cy);
    glVertex2f(-y + cx, -x + cy);
    glVertex2f(-y + cx, x + cy);
    glVertex2f(-x + cx, y + cy);

    if (pk < 0) {
      pk = pk + 2 * x + 3;
      x = x + 1;
    }
    else {
      pk = pk + 2 * x - 2 * y + 5;
      x = x + 1;
      y = y - 1;
    }
  }

  glEnd();
}

// here used lines, can alt use polygon if feel like not changing the original order duhh

void drawCircleMidpointFilled(float cx, float cy, float r) {
  float pk = 1 - r;
  float x = 0, y = r;

  glColor3f(1.0f, 0.0f, 0.0f);

  while (x <= y) {
    glBegin(GL_LINES);
    glVertex2f(-x + cx, y + cy);
    glVertex2f(x + cx, y + cy);
    glVertex2f(-x + cx, -y + cy);
    glVertex2f(x + cx, -y + cy);
    glVertex2f(-y + cx, x + cy);
    glVertex2f(y + cx, x + cy);
    glVertex2f(-y + cx, -x + cy);
    glVertex2f(y + cx, -x + cy);
    glEnd();

    if (pk < 0) {
      pk = pk + 2 * x + 3;
      x++;
    }
    else {
      pk = pk + 2 * x - 2 * y + 5;
      x++;
      y--;
    }
  }
}

void display() {
  glClear(GL_COLOR_BUFFER_BIT);

  drawCircleMidpointFilled(0, 0, 100);

  glutSwapBuffers();
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(500, 500);
  glutCreateWindow("Basic Shapes");
  init();
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}
