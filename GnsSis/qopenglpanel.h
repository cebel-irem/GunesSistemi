#ifndef QOPENGLPANEL_H
#define QOPENGLPANEL_H

#include <QObject>
#include <QOpenGLFunctions>
#include <QOpenGLExtraFunctions>
#include <QtOpenGLWidgets/QOpenGLWidget>
#include <QtOpenGL/QOpenGLVertexArrayObject>
#include <QtOpenGL/QOpenGLBuffer>
#include <QFile>
#include <QMatrix4x4>
#include <QtMath>

#include <QImage>
#include <QOpenGLTexture>

#include <QFileInfo>

class QOpenGLPanel : public QOpenGLWidget
{
public:
    QOpenGLPanel(QWidget *parent = nullptr);
    ~QOpenGLPanel();
    void setCameraMatrix();
    void setProjectionMatrix();
    void translate(GLfloat x, GLfloat y, GLfloat z);
    void rotate(GLfloat degree, GLfloat x, GLfloat y, GLfloat z);
    void scale(GLfloat x, GLfloat y, GLfloat z);
    void lookAt(GLfloat ex, GLfloat ey, GLfloat ez, GLfloat cx, GLfloat cy, GLfloat cz, GLfloat ux, GLfloat uy, GLfloat uz);
    void perspective(GLfloat angle, GLfloat ratio, GLfloat near, GLfloat far);
    void resetScene();
    void mousePressEvent(QMouseEvent* event) override;

    GLuint createSphere(GLuint X_SEGMENTS, GLuint Y_SEGMENT, GLfloat x_offset, GLfloat y_offset, GLfloat z_offset);
    unsigned char* getObjectTextureData();
    GLuint loadTexture(QString fileName);

private:

    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int width, int height) override;
    const char* readShaderSource(QString filename);
    QOpenGLFunctions* getGLFunctions();
    QOpenGLExtraFunctions* getGLExtraFunctions();
    bool initializeShaderProgram(QString vertex, QString fragment, QOpenGLFunctions *f);
    bool checkGLError(QOpenGLFunctions *f, QString functionCall);

    GLuint progID, vertID, fragID;
    GLuint arrays, triangleData;
    GLuint position, color, normal, texture;

    GLuint translateMatrixID, rotateMatrixID, scaleMatrixID;
    QMatrix4x4 translateMatrix, rotateMatrix, scaleMatrix;
    GLfloat tX, tY, tZ;
    float rDegree;
    GLfloat rX, rY, rZ;
    GLfloat sX, sY, sZ;
    GLfloat reX, reY, reZ;


    GLuint projectionMatrixID, cameraMatrixID;
    QMatrix4x4 projectionMatrix, cameraMatrix;
    GLfloat camEyeX, camEyeY, camEyeZ;
    QVector3D cameraEye;
    GLfloat camCenterX, camCenterY, camCenterZ;
    QVector3D cameraCenter;
    GLfloat camUpX, camUpY, camUpZ;
    QVector3D cameraUp;
    GLfloat verticalAngle, aspectRatio, nearPlane, farPlane;

    std::vector<float> vert;
    GLuint sphereVAO[2], vbo[2], ebo[2];
    GLuint indexCount;

    QList<QVector3D> positions;
    QList<QVector2D> uv;
    QList<QVector3D> normals;

    std::vector<unsigned int> indices;

    QMatrix4x4 sunScaleMatrix;
    QMatrix4x4 sunRotateMatrix;

    QMatrix4x4 earthScaleMatrix, moonScaleMatrix, merkurScaleMatrix, venusScaleMatrix, marsScaleMatrix, jupiterScaleMatrix, saturnScaleMatrix, uranusScaleMatrix, neptuneScaleMatrix;
    QMatrix4x4 earthOrbitMatrix, moonOrbitMatrix, merkurOrbitMatrix, jupiterOrbitMatrix, venusOrbitMatrix, marsOrbitMatrix, saturnOrbitMatrix, uranusOrbitMatrix, neptuneOrbitMatrix;

    QMatrix4x4 earthSelfRotateMatrix, moonSelfRotateMatrix, merkurSelfRotateMatrix, jupiterSelfRotateMatrix, venusSelfRotateMatrix, marsSelfRotateMatrix, saturnSelfRotateMatrix, uranusSelfRotateMatrix, neptuneSelfRotateMatrix;
    QMatrix4x4 plutoScaleMatrix, plutoOrbitMatrix, plutoSelfRotateMatrix;

    // 🌑 Mars'ın Uyduları
    QMatrix4x4 phobosScaleMatrix, deimosScaleMatrix;
    QMatrix4x4 phobosOrbitMatrix, phobosSelfRotateMatrix, deimosOrbitMatrix, deimosSelfRotateMatrix;

    // 🟠 Jüpiter'in Uyduları
    QMatrix4x4 ioScaleMatrix, europaScaleMatrix, ganymedeScaleMatrix, callistoScaleMatrix;
    QMatrix4x4 ioOrbitMatrix, ioSelfRotateMatrix, europaOrbitMatrix, europaSelfRotateMatrix;
    QMatrix4x4 ganymedeOrbitMatrix, ganymedeSelfRotateMatrix, callistoOrbitMatrix, callistoSelfRotateMatrix;

    // 🟡 Satürn'ün Uyduları
    QMatrix4x4 titanScaleMatrix, enceladusScaleMatrix;
    QMatrix4x4 titanOrbitMatrix, titanSelfRotateMatrix, enceladusOrbitMatrix, enceladusSelfRotateMatrix;

    // 🔵 Uranüs ve Neptün'ün Uyduları
    QMatrix4x4 mirandaScaleMatrix, titaniaScaleMatrix, tritonScaleMatrix;
    QMatrix4x4 mirandaOrbitMatrix, mirandaSelfRotateMatrix, titaniaOrbitMatrix, titaniaSelfRotateMatrix;
    QMatrix4x4 tritonOrbitMatrix, tritonSelfRotateMatrix;

    // 🟤 Plüton'un Uydusu
    QMatrix4x4 charonScaleMatrix;
    QMatrix4x4 charonOrbitMatrix, charonSelfRotateMatrix;

    float sunScaleMultp;
    float earthOrbitAngle, moonOrbitAngle, merkurOrbitAngle, jupiterOrbitAngle, venusOrbitAngle, marsOrbitAngle, saturnOrbitAngle, uranusOrbitAngle, neptuneOrbitAngle;
    float sunSelfRotateAngle, earthSelfRotateAngle, moonSelfRotateAngle, merkurSelfRotateAngle, jupiterSelfRotateAngle, venusSelfRotateAngle, marsSelfRotateAngle, saturnSelfRotateAngle, uranusSelfRotateAngle, neptuneSelfRotateAngle;
    float plutoOrbitAngle, plutoSelfRotateAngle;
    float phobosOrbitAngle, phobosSelfRotateAngle, deimosOrbitAngle, deimosSelfRotateAngle;
    float ioOrbitAngle, ioSelfRotateAngle, europaOrbitAngle, europaSelfRotateAngle;
    float ganymedeOrbitAngle, ganymedeSelfRotateAngle, callistoOrbitAngle, callistoSelfRotateAngle;
    float titanOrbitAngle, titanSelfRotateAngle, enceladusOrbitAngle, enceladusSelfRotateAngle;
    float mirandaOrbitAngle, mirandaSelfRotateAngle, titaniaOrbitAngle, titaniaSelfRotateAngle;
    float tritonOrbitAngle, tritonSelfRotateAngle;
    float charonOrbitAngle, charonSelfRotateAngle;

    GLuint sunSize;
    GLuint moonSize;
    GLuint earthSize, merkurSize, jupiterSize, venusSize, marsSize, saturnSize, uranusSize, neptuneSize;
    GLuint plutoSize;
    GLuint plutoTexture;
    GLuint phobosSize, deimosSize;
    GLuint phobosTexture, deimosTexture;
    GLuint ioSize, europaSize, ganymedeSize, callistoSize;
    GLuint ioTexture, europaTexture, ganymedeTexture, callistoTexture;
    GLuint titanSize, enceladusSize;
    GLuint titanTexture, enceladusTexture;
    GLuint mirandaSize, titaniaSize, tritonSize;
    GLuint mirandaTexture, titaniaTexture, tritonTexture;
    GLuint charonSize;
    GLuint charonTexture;

    // QOpenGLTexture *texture;
    GLuint textureID;

    QImage Texture;
    GLuint sunTexture, earthTexture, moonTexture, mercuryTexture, jupiterTexture, venusTexture, marsTexture, saturnTexture, uranusTexture, neptuneTexture;
};

#endif // QOPENGLPANEL_H
