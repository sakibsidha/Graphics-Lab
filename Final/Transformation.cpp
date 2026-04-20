#include <cmath>

struct Point {
    float x, y;
};

// TRANSLATION
// Formula:
// x' = x + tx
// y' = y + ty
Point translate(Point p, float tx, float ty) {
    Point r;
    r.x = p.x + tx;
    r.y = p.y + ty;
    return r;
}

// SCALING
// Formula:
// x' = x * sx
// y' = y * sy
Point scale(Point p, float sx, float sy) {
    Point r;
    r.x = p.x * sx;
    r.y = p.y * sy;
    return r;
}

// ROTATION (about origin)
// Formula:
// x' = x cosθ - y sinθ
// y' = x sinθ + y cosθ
Point rotate(Point p, float angle) {
    Point r;
    r.x = p.x * cos(angle) - p.y * sin(angle);
    r.y = p.x * sin(angle) + p.y * cos(angle);
    return r;
}

Point rotateAboutPoint(Point p, float cx, float cy, float angle) {
    Point r;

    float x = p.x - cx;
    float y = p.y - cy;

    r.x = cx + x * cos(angle) - y * sin(angle);
    r.y = cy + x * sin(angle) + y * cos(angle);

    return r;
}

Point tri[3] = {
    {-100, -100},
    {100, -100},
    {0, 100}
};

// applying
void drawTriangle(float tx, float ty, float angle, float sx, float sy) {
    glBegin(GL_TRIANGLES);

    for(int i = 0; i < 3; i++) {

        Point p = tri[i];

        // 🔥 Transformation pipeline (ORDER MATTERS)
        p = scale(p, sx, sy);        // 1. scale
        p = rotate(p, angle);        // 2. rotate
        p = translate(p, tx, ty);    // 3. move

        glVertex2f(p.x, p.y);
    }

    glEnd();
}
