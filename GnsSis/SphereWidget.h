#ifndef SPHEREWIDGET_H
#define SPHEREWIDGET_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QMatrix4x4>

class SphereWidget : public QOpenGLWidget, protected QOpenGLFunctions {
    Q_OBJECT

public:
    SphereWidget(QWidget *parent = nullptr);

protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

private:
    QOpenGLShaderProgram shaderProgram;
    QMatrix4x4 projection;

    void drawSphere(float radius, int latDivisions, int lonDivisions);
};

#endif // SPHEREWIDGET_H
