#include "BasicWidget.h"

//////////////////////////////////////////////////////////////////////
// Publics
BasicWidget::BasicWidget(QWidget* parent) : QOpenGLWidget(parent), logger_(this)
{
  setFocusPolicy(Qt::StrongFocus);
}

BasicWidget::~BasicWidget()
{
    for (auto renderable : renderables_) {
        delete renderable;
    }
    renderables_.clear();
}

//////////////////////////////////////////////////////////////////////
// Privates
///////////////////////////////////////////////////////////////////////
// Protected
void BasicWidget::keyReleaseEvent(QKeyEvent* keyEvent)
{
  // Handle key events here.
  if (keyEvent->key() == Qt::Key_Left) {
    qDebug() << "Left Arrow Pressed";
    update();  // We call update after we handle a key press to trigger a redraw when we are ready
  } else if (keyEvent->key() == Qt::Key_Right) {
    qDebug() << "Right Arrow Pressed";
    update();  // We call update after we handle a key press to trigger a redraw when we are ready
  } else {
    qDebug() << "You Pressed an unsupported Key!";
  }
}
void BasicWidget::initializeGL()
{
  makeCurrent();
  initializeOpenGLFunctions();

  qDebug() << QDir::currentPath();
  QString texFile = "../../cat3.ppm";
  QVector<QVector3D> pos;
  QVector<QVector3D> norm;
  QVector<QVector2D> texCoord;
  QVector<unsigned int> idx;
  QMatrix4x4 translation;
  pos << QVector3D(-1, -1, 0);
  pos << QVector3D(1, -1, 0);
  pos << QVector3D(-1, 1, 0);
  pos << QVector3D(1, 1, 0);

  // We don't actually use the normals right now, but this will be useful later!
  norm << QVector3D(0.0f, 0.0f, 1.0f);
  norm << QVector3D(0.0f, 0.0f, 1.0f);
  norm << QVector3D(0.0f, 0.0f, 1.0f);
  norm << QVector3D(0.0f, 0.0f, 1.0f);

  // TODO:  Make sure to add texture coordinates to pass into the initialization of our renderable
  texCoord << QVector2D(1, 1);
  texCoord << QVector2D(0, 1);
  texCoord << QVector2D(1, 0);
  texCoord << QVector2D(0, 0);

  idx << 0 << 1 << 2 << 2 << 1 << 3;

  Renderable* ren1 = new Renderable();
  Renderable* ren2 = new Renderable();
  ren1->init(pos, norm, texCoord, idx, texFile);
  translation.translate(-pos[0]);
  ren1->setModelMatrix(translation);
  ren2->init(pos, norm, texCoord, idx, texFile);
  translation.translate(pos[0] * 2);
  ren2->setModelMatrix(translation);
  renderables_.push_back(ren1);
  renderables_.push_back(ren2);
  glViewport(0, 0, width(), height());
  frameTimer_.start();
}

void BasicWidget::resizeGL(int w, int h)
{
    if (!logger_.isLogging()) {
        logger_.initialize();
        // Setup the logger for real-time messaging
        connect(&logger_, &QOpenGLDebugLogger::messageLogged, [=]() {
            const QList<QOpenGLDebugMessage> messages = logger_.loggedMessages();
            for (auto msg : messages) {
                qDebug() << msg;
            }
            });
        logger_.startLogging();
    }
  glViewport(0, 0, w, h);
  view_.setToIdentity();
  view_.lookAt(QVector3D(0.0f, 0.0f, 4.0f),
      QVector3D(0.0f, 0.0f, 0.0f),
      QVector3D(0.0f, 1.0f, 0.0f));
  projection_.setToIdentity();
  projection_.perspective(70.f, (float)w/(float)h, 0.001f, 1000.0f);
  glViewport(0, 0, w, h);
}

void BasicWidget::paintGL()
{
  qint64 msSinceRestart = frameTimer_.restart();
  glDisable(GL_DEPTH_TEST);
  glDisable(GL_CULL_FACE);

  glClearColor(0.f, 0.f, 0.f, 1.f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  for (auto renderable : renderables_) {
      renderable->update(msSinceRestart);
      renderable->draw(view_, projection_);
  }
  update();
}