#include "MyGLWidget.h"

#include <iostream>

MyGLWidget::MyGLWidget (QWidget* parent) : QOpenGLWidget(parent)
{
  setFocusPolicy(Qt::ClickFocus);  // per rebre events de teclat
  scale = 1.0f;
}

MyGLWidget::~MyGLWidget ()
{
  if (program != NULL)
    delete program;
}

void MyGLWidget::initializeGL ()
{
  // Cal inicialitzar l'ús de les funcions d'OpenGL
  initializeOpenGLFunctions();  
  
  x = glm::vec3(1,0,0);
  y = glm::vec3(0,1,0);
  z = glm::vec3(0,0,1);
  
  glClearColor(0.5, 0.7, 1.0, 1.0); // defineix color de fons (d'esborrat)
  carregaShaders();
  createBuffers();
  glEnable(GL_DEPTH_TEST);
  ini_camera();
}

void MyGLWidget::paintGL () 
{
  // Esborrem el frame-buffer
  glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // Carreguem la transformació de model
  modelTransform ();
  pinta_homer();
  
  modelTransform2 ();
  pinta_floor();
  
  glBindVertexArray (0);
}


void MyGLWidget::resizeGL (int w, int h) 
{
  glViewport(0, 0, w, h);
}

void MyGLWidget::createBuffers () 
{
 
    carregaModelHomer();
    carregaModelFloor();
  
    glBindVertexArray (0);
}

void MyGLWidget::carregaShaders()
{
  // Creem els shaders per al fragment shader i el vertex shader
  QOpenGLShader fs (QOpenGLShader::Fragment, this);
  QOpenGLShader vs (QOpenGLShader::Vertex, this);
  // Carreguem el codi dels fitxers i els compilem
  fs.compileSourceFile("shaders/fragshad.frag");
  vs.compileSourceFile("shaders/vertshad.vert");
  // Creem el program
  program = new QOpenGLShaderProgram(this);
  // Li afegim els shaders corresponents
  program->addShader(&fs);
  program->addShader(&vs);
  // Linkem el program
  program->link();
  // Indiquem que aquest és el program que volem usar
  program->bind();

  // Obtenim identificador per a l'atribut “vertex” del vertex shader
  vertexLoc = glGetAttribLocation (program->programId(), "vertex");
  // Obtenim identificador per a l'atribut “color” del vertex shader
  colorLoc = glGetAttribLocation (program->programId(), "color");
  // Uniform locations
  transLoc = glGetUniformLocation(program->programId(), "TG");
  projLoc = glGetUniformLocation(program->programId(), "PM");
  viewLoc = glGetUniformLocation(program->programId(), "VM");
}


/*
        ***********************
        *                     *
        *    MIS FUNCIONES    *
        *                     *
        ***********************

*/

/*
 ************************************
 *                                  *
 *   FUNCIONES DE CARREGA DE VAOs   *
 *                                  *
 ************************************
*/
void MyGLWidget::carregaModelHomer()
{
    //carrega el model  
  homer.load("../../models/HomerProves.obj");
  
  // Creació del Vertex Array Object per pintar
  glGenVertexArrays(1, &VAO_Homer);
  glBindVertexArray(VAO_Homer);

  glGenBuffers(1, &VBO_HomerPos);
  glBindBuffer(GL_ARRAY_BUFFER, VBO_HomerPos);
  glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*homer.faces().size()*3*3, homer.VBO_vertices(), GL_STATIC_DRAW);

  // Activem l'atribut vertexLoc
  glVertexAttribPointer(vertexLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(vertexLoc);

  glGenBuffers(1, &VBO_HomerCol);
  glBindBuffer(GL_ARRAY_BUFFER, VBO_HomerCol);
  glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*homer.faces().size()*3*3, homer.VBO_matdiff(), GL_STATIC_DRAW);

  // Activem l'atribut colorLoc
  glVertexAttribPointer(colorLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(colorLoc);
}

void MyGLWidget::carregaModelFloor()
{
    //carrega el model
  floor.load("../../models/Cobblestones2/Files/CobbleStones2.obj");  
  
  //Creació del Vertex Array Object
  glGenVertexArrays(1, &VAO_Floor);
  glBindVertexArray(VAO_Floor);
  
  glGenBuffers(1,&VBO_FloorPos);
  glBindBuffer(GL_ARRAY_BUFFER, VBO_FloorPos);
  glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*floor.faces().size()*3*3, floor.VBO_vertices(),GL_STATIC_DRAW);
  
  //Activem l'atribut vertexLoc
  glVertexAttribPointer(vertexLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(vertexLoc);
  
  glGenBuffers(1, &VBO_FloorCol);
  glBindBuffer(GL_ARRAY_BUFFER, VBO_FloorCol);
  glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*floor.faces().size()*3*3, floor.VBO_matdiff(), GL_STATIC_DRAW);
  
  glVertexAttribPointer(colorLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(colorLoc);
}


/*
 ********************************
 *                              *
 *   FUNCIONES DE PINTAR VAOs   *
 *                              *
 ********************************
*/

void MyGLWidget::pinta_homer()
{
    // Activem el VAO per a pintar el homer
  glBindVertexArray (VAO_Homer);

  // pintem
  glDrawArrays(GL_TRIANGLES, 0, homer.faces().size()*3);
    
}

void MyGLWidget::pinta_floor()
{
        // Activem el VAO per a pintar el floor
    glBindVertexArray(VAO_Floor);
    
    //pintem
    glDrawArrays(GL_TRIANGLES, 0, floor.faces().size()*3);
}


/*
 ********************************
 *                              *
 *   FUNCIONES DE INTERACCIÓN   *
 *                              *
 ********************************
*/

void MyGLWidget::keyPressEvent(QKeyEvent* event) 
{
  makeCurrent();
  switch (event->key()) {
    case Qt::Key_S: { // escalar a més gran
      scale += 0.05;
      break;
    }
    case Qt::Key_D: { // escalar a més petit
      scale -= 0.05;
      break;
    }
    
    case Qt::Key_R: {
        degrees += 0.1;//(float)M_PI/2;
        break;
    }
    
    default: event->ignore(); break;
  }
  update();
}

void MyGLWidget::mousePressEvent(QMouseEvent *e)
{
    
    position = e->pos();
    
}

void MyGLWidget::mouseMoveEvent(QMouseEvent *e)
{
    makeCurrent(); 
    if(e->buttons() & Qt::LeftButton){
        if(e->x() > position.x()) degrees +=0.1;
        else degrees -=0.1;
    }
    position = e->pos();
    update();
}

/*
 *****************************
 *                           *
 *   FUNCIONES DE "VISIÓN"   *
 *                           *
 *****************************
*/

void MyGLWidget::projectTransform(){
    //FOV, ra, znear, zfar
    glm::mat4 Proj = glm::perspective(FOV,ra,znear,zfar);
    glUniformMatrix4fv(projLoc,1,GL_FALSE,&Proj[0][0]);
}

void MyGLWidget::viewTransform(){
    glm::mat4 ViewMat = glm::lookAt(OBS,VRP,UP);
    glUniformMatrix4fv(viewLoc,1,GL_FALSE,&ViewMat[0][0]);
}

void MyGLWidget::ini_camera(){
    FOV = (float)M_PI/2.0f;
    ra = 1.0f;
    znear = 0.4f;
    zfar = 3.0f;
    projectTransform();
    
    OBS = glm::vec3(0,0,1);
    VRP = glm::vec3(0,0,0);
    UP = glm::vec3(0,1,0);
    viewTransform();
}


/*
 *****************************
 *                           *
 *   FUNCIONES DE "VISIÓN"   *
 *                           *
 *****************************
*/

void MyGLWidget::modelTransform () 
{
  // Matriu de transformació de model
  glm::mat4 transform (1.0f);
  transform = glm::scale(transform, glm::vec3(scale));
  transform = glm::translate(transform,glm::vec3(0.0,0.5,0.0));
  transform = glm::rotate(transform,degrees,y);
  glUniformMatrix4fv(transLoc, 1, GL_FALSE, &transform[0][0]);
}

void MyGLWidget::modelTransform2 () 
{
  // Matriu de transformació de model
  glm::mat4 transform (1.0f);
  transform = glm::scale(transform, glm::vec3(scale));
  transform = glm::translate(transform,glm::vec3(0.0,-1.0,0.0));
  glUniformMatrix4fv(transLoc, 1, GL_FALSE, &transform[0][0]);
}