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

void drawLineDDA(float x1, float y1, float x2, float y2) {
  float dx = x2 - x1;
  float dy = y2 - y1;

  float steps = (abs(dx) > abs(dy)) ? abs(dx) : abs(dy);

  float inc_x = dx / steps;
  float inc_y = dy / steps;

  float x = x1;
  float y = y1;

  glBegin(GL_POINTS);
  glColor3f(1, 0, 0);
  for (int i = 0; i <= steps; i++) {
    glVertex2i(round(x), round(y));
    x += inc_x;
    y += inc_y;
  }
  glEnd();
}


void display() {
  glClear(GL_COLOR_BUFFER_BIT);

  drawLineDDA(-100, 24, 100, 100);

  glutSwapBuffers();
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(500, 500);
  glutCreateWindow("DDA");
  init();
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}
