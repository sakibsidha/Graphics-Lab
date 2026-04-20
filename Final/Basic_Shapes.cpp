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

void drawPoint(float x, float y) {
  glPointSize(5);
  glBegin(GL_POINTS);
  glColor3f(1, 0, 0);
  glVertex2i(x, y);
  glEnd();
}

void drawLine(float x1, float y1, float x2, float y2) {
  glBegin(GL_LINES);
  glColor3f(1, 0, 0);
  glVertex2f(x1, y1);
  glVertex2f(x2, y2);
  glEnd();
}

void drawConnectedLines(vector<pair<float, float>> v) {
  glBegin(GL_LINE_STRIP);
  glColor3f(1, 0, 0);
  for (int i = 0; i < v.size(); ++i) {
    glVertex2f(v[i].first, v[i].second);
  }
  glEnd();
}

void drawTriangle(vector<pair<float, float>> v) {
  assert(v.size() == 3);
  glBegin(GL_TRIANGLES);
  glColor3f(1, 0, 0);
  for (int i = 0; i < v.size(); ++i) {
    glVertex2f(v[i].first, v[i].second);
  }
  glEnd();
}

void drawQuads(vector<pair<float, float>> v) {
  assert(v.size() == 4);
  glBegin(GL_QUADS);
  glColor3f(1, 0, 0);
  for (int i = 0; i < v.size(); ++i) {
    glVertex2f(v[i].first, v[i].second);
  }
  glEnd();
}

void drawPolygon(vector<pair<float, float>> v) {
  glBegin(GL_POLYGON);
  glColor3f(1, 0, 0);
  for (int i = 0; i < v.size(); ++i) {
    glVertex2f(v[i].first, v[i].second);
  }
  glEnd();
}

void display() {
  glClear(GL_COLOR_BUFFER_BIT);

  // drawPolygon({ {0, 0}, { 0, 50 }, { 50, 50 }, {50, 40}, {40, 0} });

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
