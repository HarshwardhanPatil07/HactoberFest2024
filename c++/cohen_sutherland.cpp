//cohen sutherland line clipping algorithm
#include <GL/glut.h>
#include <stdio.h>
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

typedef struct {
    GLfloat x, y;
} Point;
int  xd1,yd1,xd2,yd2;
const GLint WIN_LEFT_BIT = 0x01;
const GLint WIN_RIGHT_BIT = 0x02;
const GLint WIN_BOTTOM_BIT = 0x04;
const GLint WIN_TOP_BIT = 0x08;

void init_graph(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
    glutCreateWindow(argv[0]);
   // glClearColor(1.0, 1.0, 1.0, 0.0);
    glPointSize(1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT);
}

void close_graph() {
    glutMainLoop();
}

void swap_points(Point *p1, Point *p2) {
    Point t = *p1;
    *p1 = *p2;
    *p2 = t;
}

void swap_codes(GLint *x, GLint *y) {
    GLint t = *x;
    *x = *y;
    *y = t;
}

GLint inside(GLint code) {
    return !code;
}

GLint accept(GLint code1, GLint code2) {
    return !(code1 | code2);
}

GLint reject(GLint code1, GLint code2) {
    return code1 & code2;
}

GLint encode(Point p1, Point win_min, Point win_max) {
    GLint code = 0x00;

    if (p1.x < win_min.x) code |= WIN_LEFT_BIT;
    if (p1.x > win_max.x) code |= WIN_RIGHT_BIT;
    if (p1.y < win_min.y) code |= WIN_BOTTOM_BIT;
    if (p1.y > win_max.y) code |= WIN_TOP_BIT;
    return code;
}

GLint round(GLfloat a) {
    return (GLint) (a + 0.5f);
}

void line_clip(Point p1, Point p2, Point win_min, Point win_max) {
    GLint code1, code2;
    GLint done = 0, plot_line = 0;
    GLfloat m = 0;
    if (p1.x != p2.x) {
        m = (p2.y - p1.y) / (p2.x - p1.x);
    }
    while (!done) {
        code1 = encode(p1, win_min, win_max);
        code2 = encode(p2, win_min, win_max);
        if (accept(code1, code2)) {
            done = 1;
            plot_line = 1;
        } else if (reject(code1, code2)) {
            done = 1;
        } else {
            if (inside(code1)) {
                swap_points(&p1, &p2);
                swap_codes(&code1, &code2);
            }


            if (code1 & WIN_LEFT_BIT) {
                p1.y += (win_min.x - p1.x) * m;
                p1.x = win_min.x;
            } else if (code1 & WIN_RIGHT_BIT) {
                p1.y += (win_max.x - p1.x) * m;
                p1.x = win_max.x;
            } else if (code1 & WIN_BOTTOM_BIT) {
                if (p1.x != p2.x)
                    p1.x += (win_min.y - p1.y) / m;
                p1.y = win_min.y;
            } else if (code1 & WIN_TOP_BIT) {
                if (p1.x != p2.x)
                    p1.x += (win_max.y - p1.y) / m;
                p1.y = win_max.y;
            }
        }
    }

    if (plot_line) {
        glColor3f(1, 2,2);
        glLineWidth(2);
        glBegin(GL_LINES);
        glVertex2i(round(p1.x), round(p1.y));
        glVertex2i(round(p2.x), round(p2.y));
        glEnd();
        glFlush();
    }
}

void draw_window(Point win_min, Point win_max) {

    glColor3f(1, 0, 1);
    glBegin(GL_LINE_LOOP);
    glVertex2i(round(win_min.x), round(win_min.y));
    glVertex2i(round(win_min.x), round(win_max.y));
    glVertex2i(round(win_max.x), round(win_max.y));
    glVertex2i(round(win_max.x), round(win_min.y));
    glEnd();
    glFlush();
}

void init_clip() {
    glClear(GL_COLOR_BUFFER_BIT);
  
    Point win_min = {60, 60};
    Point win_max = {470, 290};
    draw_window(win_min, win_max);
    Point p1 = {50, 50};
    Point p2 = {490, 310};
    
    glBegin(GL_LINES);
    glVertex2i(round(p1.x), round(p1.y));
    glVertex2i(round(p2.x), round(p2.y));
    glEnd();
    line_clip(p1, p2, win_min, win_max);
}

int main(int argc, char **argv) {

    init_graph(argc, argv);
  
    glutDisplayFunc(init_clip);
    close_graph();
    return EXIT_SUCCESS;
}
