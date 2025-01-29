#include "SphereWidget.h"
#include <QVector3D>
#include <math.h>

SphereWidget::SphereWidget(QWidget *parent) : QOpenGLWidget(parent) {
    setFocusPolicy(Qt::StrongFocus);
}

void SphereWidget::initializeGL() {
    initializeOpenGLFunctions();

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

    shaderProgram.addShaderFromSourceFile(QOpenGLShader::Vertex, ":/shaders/vertex.glsl");
    shaderProgram.addShaderFromSourceFile(QOpenGLShader::Fragment, ":/shaders/fragment.glsl");
    shaderProgram.link();
    shaderProgram.bind();
}

void SphereWidget::resizeGL(int w, int h) {
    glViewport(0, 0, w, h);
    projection.setToIdentity();
    projection.perspective(45.0f, float(w) / float(h), 0.01f, 100.0f);
}

void SphereWidget::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    QMatrix4x4 model;
    model.translate(0.0f, 0.0f, -3.0f);

    shaderProgram.bind();
    shaderProgram.setUniformValue("mvp_matrix", projection * model);

    drawSphere(1.0f, 50, 50);
}

void SphereWidget::drawSphere(float radius, int latDivisions, int lonDivisions) {
    for (int i = 0; i <= latDivisions; ++i) {
        float theta = i * M_PI / latDivisions;
        float sinTheta = sin(theta);
        float cosTheta = cos(theta);

        for (int j = 0; j <= lonDivisions; ++j) {
            float phi = j * 2 * M_PI / lonDivisions;
            float sinPhi = sin(phi);
            float cosPhi = cos(phi);

            QVector3D vertex(
                radius * cosPhi * sinTheta,
                radius * cosTheta,
                radius * sinPhi * sinTheta
                );

            glVertex3f(vertex.x(), vertex.y(), vertex.z());
        }
    }
}
