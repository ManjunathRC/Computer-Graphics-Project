#include<stdio.h>
#include<stdlib.h>
#include<GL/gl.h>
#include <math.h> 
#include<GL/glut.h>
GLfloat vertices1[][3]={{0.0,9,0.0},
{0.0,0.0,-4.5}, 
{4,0.0,4.5},
{-4.0,0.0,4.5}};
GLfloat normals1[][3]={{0.0,9,0.0},
{0.0,0.0,-4.5}, 
{4,0.0,4.5},
{-4.0,0.0,4.5}};
GLfloat colors1[][3]={{1.0,0.0,0.0}, 
{1.0,0.0,0.0}, 
{1.0,1.0,0.0},
{0.0,1.0,0.0}, 
{0.0,0.0,1.0}, 
{1.0,0.0,1.0}, 
{1.0,1.0,1.0},
{0.0,1.0,1.0}};
GLfloat vertices2[][3]={{-5.0,8.5,0.0},
{-5.0,0.0,3.0}, 
{-5.0,0.0,-3.0},
{5.0,8.5,0.0},
{5.0,0.0,3.0}, 
{5.0,0.0,-3.0}}; 
GLfloat normals2[][3]={{-5.0,8.5,0.0},
{-5.0,0.0,3.0}, 
{-5.0,0.0,-3.0},
{5.0,8.5,0.0},
{5.0,0.0,3.0}, 
{5.0,0.0,-3.0}};
GLfloat colors2[][3]={{0.0,0.0,0.0}, 
{1.0,0.0,0.0}, 
{1.0,1.0,0.0},
{0.0,1.0,0.0}, 
{0.0,0.0,1.0}, 
{1.0,0.0,1.0}, 
{1.0,1.0,1.0},
{0.0,1.0,1.0}};
void polygonprism1(int a, int b, int c, int d);
void polygonprism2(int a, int b, int c);
void colorprism(void);
void display3(void);
void polygontetra(int a, int b, int c);
void colortetra(void);
void reshapetetra(int w, int h);
void init3();
void resize(int width, int height);
void drtorus();
void cone_func( int);
void init4();
void ball(int,int,int);
void dispaly1(void);
void myreshape(int,int);
void house(void);
void keys(unsigned char c, int x, int y);
void keyboard(unsigned char key,int x,int y);
void processMenuRot(int option);
void dummy(int option);
float scale=1;
int angley=-0.5;
int anglex;
int n=1;
int tranx,trany;
int rotationx,rotationy,scaling,translation,bak=1;
GLfloat colors[][3]={{0.5,1,0.7},{0.7,0.5,0.9},{0.2,0,0.3},{0.6,0.8,0},{0.5,0.5,0.5},{0.2,0.3,0.7},{0.1,0.5,0.3},{0.4,0,0},{0.2,0.7,0.2}};
GLUquadricObj *sphere,*cone,*base;
int back=0;
static GLfloat wood_mat[]={0.4,0.2,0,1};
void processMenuSymbol(int num)
{
	n = num;
	glutPostRedisplay();
}
void processMenuMain1()
{
	
}
void createGLUTMenus1()
{
	int menu = glutCreateMenu(processMenuSymbol);
	glutAddMenuEntry("HOUSE",1);
	glutAddMenuEntry("INTERTWINED TORUSES",3);
	glutAddMenuEntry("TETRAHEDRON",4);
	glutAddMenuEntry("PRISM",5);
	glutCreateMenu(processMenuMain1);
	glutAddSubMenu("CHOOSE LOGO",menu);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}
void init2()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-100.0,100,-100.0,100.0,-100,100);
	glMatrixMode(GL_MODELVIEW);
}
void myinit()
{
	glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0,1000,0,1000,-10,10); 
     glMatrixMode(GL_MODELVIEW);
}
int myrandom(int m) {

	return rand()%m;

}
void polygontetra(int a, int b, int c)
{
	glBegin(GL_POLYGON);
		glColor3fv(colors1[c]);
		glNormal3fv(normals1[a]);
		glVertex3fv(vertices1[a]);
		
		glColor3fv(colors1[c]);
		glNormal3fv(normals1[b]);
		glVertex3fv(vertices1[b]);
		
		glColor3fv(colors1[c]);
		glNormal3fv(normals1[c]);
		glVertex3fv(vertices1[c]);
		
	glEnd();
}
void colortetra(void)
{
	polygontetra(0,1,2);
	polygontetra(0,3,2);
	polygontetra(0,3,1);
	polygontetra(1,2,3);
}
void reshapetetra(int w, int h)
{
	glViewport(0,0,w,h);
	glClearColor(1.0,1.0,1.0,1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(w<=h)
		glOrtho(-7.0,7.0,-7.0*((GLfloat)h/(GLfloat)w),7.0*((GLfloat)h/(GLfloat)w),-10.0,10.0);
	else
		glOrtho(-7.0*((GLfloat)w/(GLfloat)h),7.0*((GLfloat)w/(GLfloat)h),-7.0,7.0,-10.0,10.0);
	glMatrixMode(GL_MODELVIEW);
}
void strokeString(float x,float y,float sx,float sy,char *string,int width)
{
	char *c;
	glLineWidth(width);
	glPushMatrix();
	glTranslatef(x,y,0);
	glScalef(sx,sy,0);
	for (c=string; *c != '\0'; c++) 
	{
		glutStrokeCharacter(GLUT_STROKE_ROMAN, *c);
	}
	glPopMatrix();
}
void polygonprism1(int a, int b, int c, int d)
{
	glBegin(GL_POLYGON);
		glColor3fv(colors2[b]);
		glNormal3fv(normals2[a]);
		glVertex3fv(vertices2[a]);
		
		glColor3fv(colors2[b]);
		glNormal3fv(normals2[b]);
		glVertex3fv(vertices2[b]);
		
		glColor3fv(colors2[b]);
		glNormal3fv(normals2[c]);
		glVertex3fv(vertices2[c]);
		
		glColor3fv(colors2[b]);
		glNormal3fv(normals2[d]);
		glVertex3fv(vertices2[d]);
	
	glEnd();
}
void polygonprism2(int a, int b, int c)
{
	glBegin(GL_POLYGON);
		glColor3fv(colors2[b]);
		glNormal3fv(normals2[a]);
		glVertex3fv(vertices2[a]);
		
		glColor3fv(colors2[b]);
		glNormal3fv(normals2[b]);
		glVertex3fv(vertices2[b]);
		
		glColor3fv(colors2[b]);
		glNormal3fv(normals2[c]);
		glVertex3fv(vertices2[c]);
		
	glEnd();
}
void colorprism(void)
{
	polygonprism2(0,1,2);
	polygonprism1(0,1,4,3);
	polygonprism2(3,4,5);
	polygonprism1(3,5,2,0);
	polygonprism1(1,2,5,4);
}
void menu()
{
	int menurot=glutCreateMenu(processMenuRot);
	glutAddMenuEntry("X",1);
	glutAddMenuEntry("Y",2);
	glutCreateMenu(dummy);
	glutAddSubMenu("Rotation",menurot);
	glutAddMenuEntry("Scaling",2);
	glutAddMenuEntry("Translation",3);
	glutAddMenuEntry("Change BAckground colour",4);
	glutAddMenuEntry("Exit",5);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}
void display1(void)
{ 
 	if(bak!=-1)
	{
		glClearColor((double)myrandom(255)/255, (double)myrandom(255)/255, (double)myrandom(255)/255, (double)myrandom(255)/255);
		bak=-1;
	}
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
    if(translation)
    glTranslatef(tranx,trany,0);
    if(rotationx)
    glRotatef(anglex++,1,0,0);
     if(rotationy)
    glRotatef(angley++,0,1,0);
    if(scaling)
    glScalef(scale,scale,scale);
    house();
    glPopMatrix();
 
    glutSwapBuffers();
} 
void display3(void)
{ 
 	if(bak!=-1)
	{
		glClearColor((double)myrandom(255)/255, (double)myrandom(255)/255, (double)myrandom(255)/255, (double)myrandom(255)/255);
		bak=-1;
	}
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
    if(translation)
    glTranslatef(tranx,trany,0);
    if(rotationx)
    glRotatef(anglex++,1,0,0);
     if(rotationy)
    glRotatef(angley++,0,1,0);
    if(scaling)
    glScalef(scale,scale,scale);
    drtorus();
    glPopMatrix();
 	glutSwapBuffers();
} 
void display4(void)
{ 
 	if(bak!=-1)
	{
		glClearColor((double)myrandom(255)/255, (double)myrandom(255)/255, (double)myrandom(255)/255, (double)myrandom(255)/255);
		bak=-1;
	}
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
    if(translation)
    glTranslatef(tranx,trany,0);
    if(rotationx)
    glRotatef(anglex++,1,0,0);
     if(rotationy)
    glRotatef(angley++,0,1,0);
    if(scaling)
    glScalef(scale,scale,scale);
    colortetra();
    glPopMatrix();
 	glutSwapBuffers();
} 
void display5(void)
{ 
 	if(bak!=-1)
	{
		glClearColor((double)myrandom(255)/255, (double)myrandom(255)/255, (double)myrandom(255)/255, (double)myrandom(255)/255);
		bak=-1;
	}
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
    if(translation)
    glTranslatef(tranx,trany,0);
    if(rotationx)
    glRotatef(anglex++,1,0,0);
     if(rotationy)
    glRotatef(angley++,0,1,0);
    if(scaling)
    glScalef(scale,scale,scale);
    colorprism();
    glPopMatrix();
 
    glutSwapBuffers();
} 
void keys(unsigned char c, int x, int y)
{
	switch(c)
	{
		case 13:
			
			if(n==1)
			{
			init2();
			glutDisplayFunc(display1);
			glutIdleFunc(display1);
			glutReshapeFunc(myreshape);
			}
		    if(n==3)
			{
			init3();
			glutDisplayFunc(display3);
			glutIdleFunc(display3);
			glutReshapeFunc(resize);
			}
			if(n==4)
			{
			init4();
			glutDisplayFunc(display4);
			glutIdleFunc(display4);
			glutReshapeFunc(reshapetetra);
			}
			if(n==5)
			{
			init4();
			glutDisplayFunc(display5);
			glutIdleFunc(display5);
			glutReshapeFunc(reshapetetra);
			}
			glEnable(GL_DEPTH_TEST);
			menu();
			glutKeyboardFunc(keyboard);
			break;
	}
	glutPostRedisplay();
}
void first()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0,1,0);
	strokeString(50,850,0.15,0.15,"BANGALORE INSTITUTE OF TECHNOLOGY",2);
	strokeString(100,750,0.3,0.3,"DEPARTMENT OF COMPUTER SCIENCE",4);
	strokeString(300,670,0.3,0.3,"AND ENGINEERING",4);
	strokeString(200,500,0.3,0.3,"AN OPENGL MINI PROJECT ON",2);
	glColor3f(0.5,0.5,1);
	strokeString(170,420,0.4,0.4,"TRANSFORMATION OF OBJECTS",6);
	glColor3f(0.5,0.5,1);
	strokeString(200,220,0.2,0.2,"OBJECT SELECTED :",3);
	glColor3f(0,0.5,1);
	if(n==1)
	strokeString(450,220,0.2,0.2," HOUSE",3);
	if(n==3)
	strokeString(450,220,0.2,0.2," INTERTWINED TORUSES",3);
	if(n==4)
	strokeString(450,220,0.2,0.2," TETRAHEDRON",3);
	if(n==5)
	strokeString(450,220,0.2,0.2," PRISM",3);
	strokeString(50,100,0.17,0.17,"1 . SELECT THE LOGO TO BE DISPLAYED ",2);
	strokeString(50,50,0.17,0.17,"2 . Press (Enter) to start the simulation",2);
	strokeString(650,200,0.15,0.15,"By:",2);
	glColor3f(0,0.5,1);
	strokeString(650,160,0.18,0.18,"MANJUNATH R C",2);
	strokeString(650,35,0.18,0.18,"Prof Gunavathi H S",2);
	strokeString(650,10,0.18,0.18,"Prof Shruthibha A",2);
	glColor3f(1,0,0);
	strokeString(650,120,0.18,0.18,"1BI14CS080",2);
	strokeString(650,90,0.14,0.14,"Under the guidance of.",2);	
	glutSwapBuffers();
}
void myreshape(int w,int h)
{
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-100.0,100,-100.0,100,-100,100);
	glMatrixMode(GL_MODELVIEW);
	glutPostRedisplay();
}
void keyboard(unsigned char key,int x,int y)
{
switch(key)
  {
	case 'x': scale+=.1; break;
	case 'y': scale-=.1; break;
	case 'w': trany+=10; break;
	case 's': trany-=10;break;
	case 'a':tranx-=10;break;
	case 'd':tranx+=10;break;
  }
}
void init4()
{
	 glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-10,10,-10,10,-10,10); 
     glMatrixMode(GL_MODELVIEW);
     glClearColor(0.2,.20,0.2,0); 
 }
void init3()
{
	 glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-50,50,-50,50,-50,50); 
     glMatrixMode(GL_MODELVIEW);
     glClearColor(0.2,.20,0.2,0); 
 }
void drtorus()
{
	glColor3d(1,0,0); 
	    
        glPushMatrix();
        glTranslated(-12,0,0);
        glRotated(-10, 1.0, 0.0, 0.0);
        glutSolidTorus(2, 8, 10, 50);
        glPopMatrix(); 
        
        glPushMatrix();
        glTranslated(0.0,0,0);
        glRotated(-10, 1.0, 0.0, 0.0);
        glutSolidTorus(2, 8, 10, 50);
        glPopMatrix(); 
}
void resize(int width, int height)
{ 
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-100,100,-100,100,-100,100); 
     glMatrixMode(GL_MODELVIEW);
}  	
void ball(int radius,int slice,int stack)
{	
	sphere = gluNewQuadric();
  	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 0.6*128.0);
	gluSphere(sphere, radius, slice, stack);
    gluDeleteQuadric(sphere);
}
void cone_func(int slice)
{
	cone = gluNewQuadric();
    base = gluNewQuadric();
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 0.6*128.0);
    gluDisk(base, 0., 30, slice, 1);
    gluCylinder(cone, 30, 0, 80, slice,30);
    gluDeleteQuadric(cone);
    gluDeleteQuadric(base);
}
void window(void)
{
	base = gluNewQuadric();
	glPushMatrix();
	glColor3f(.8,.8,.8);
	glRotated(45,0,0,1);
	gluDisk(base, 0, 14, 4, 1);
	glPopMatrix();
	glPushMatrix();
	glColor3fv(wood_mat);
	glTranslated(0,0,.5);
	glScaled(10,1,1);
	glutSolidCube(2);
	glTranslated(0,10,0);
	glutSolidCube(2);
	glTranslated(0,-20,0);
	glutSolidCube(2);
	glPopMatrix();
	glPushMatrix();
	glTranslated(0,0,.5);
	glScaled(1,10,1);
	glutSolidCube(2);
	glTranslated(-9,0,0);
	glutSolidCube(2);
	glTranslated(18,0,0);
	glutSolidCube(2);
	glPopMatrix();
	glEnable(GL_COLOR_MATERIAL);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 0.6*128.0);
}
void house(void)
{
	glLineWidth(1);
	glPushMatrix();
	glColor3fv(colors[0]);
	glutSolidCube(80);
    glEnable(GL_COLOR_MATERIAL);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 0.6*128.0);
	glColor3fv(colors[8]);
	glTranslated(0,37,0);
	glRotated(-90,1,0,0);
	glRotated(45,0,0,1);
	glScaled(2.1,2.1,.6);
	cone_func(4);
	glPopMatrix();
	glPushMatrix();
	glTranslated(26,56,0);
	glScaled(3,5,3);
	glutSolidCube(5);
	glTranslated(0,2.5,0);
	glRotated(-90,1,0,0);
	glRotated(45,0,0,1);
	glScaled(.13,.13,.03);
	cone_func(4);
	glPopMatrix();
	glPushMatrix();
	glTranslated(-25,10,41);
	window();
	glTranslated(50,0,0);
	window();
	glTranslated(-25,-25,0);
	glScaled(2.5,3.2,.2);
	glutSolidCube(10);
	glColor3fv(colors[8]);
	glTranslated(0,-6,20);
	glScaled(1.5,.37,5);
	glutSolidCube(10);
	glTranslated(0,-2,5);
	glScaled(1,.6,2);
	glutSolidCube(10);
	glPopMatrix();
	glPushMatrix();
	glTranslated(-10,-15,42);
	glScaled(0.05,0.05,.05);
	ball(30,30,30);
	glPopMatrix();
}
void processMenuRot(int option)
 {
	 if(option==1)
	 {
		 rotationx=1;
		 anglex=0;
		 rotationy=translation=scaling=0;
	 }
	 if(option==2)
	 {
		 rotationy=1;
		 angley=0;
		 rotationx=translation=scaling=0;
	 }
}
void dummy(int option)
{
	switch(option)
	{
		case 2: scaling=1;
		scale=1;
		rotationx=translation=rotationy=0;
		break;
		case 3: translation=1;
		tranx=trany=0;
		rotationx=scaling=rotationy=0;
		break;
		case 4: bak=1;
		break;
		case 5 : exit(0);
	}
		
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(1024,600);
    glutInitWindowPosition(0,0);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); 
 	glutCreateWindow("PROJECT"); 
     myinit();
     glutDisplayFunc(first);
     createGLUTMenus1();
     glutKeyboardFunc(keys);
    glutMainLoop(); 
 	return 0;
}

/*   cc realproject.c -lGL -lGLU -lglut
	./a.out
*/
