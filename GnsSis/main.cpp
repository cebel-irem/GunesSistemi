#include "mainwindow.h"

#include <QApplication>
#include <QtGui/QSurface>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // OpenGL için gerekli format ayarları
    QSurfaceFormat format;
    format.setDepthBufferSize(24);
    format.setStencilBufferSize(8);
    format.setVersion(4,3);
    format.setProfile(QSurfaceFormat::CoreProfile);
    QSurfaceFormat::setDefaultFormat(format);

    // Ana pencereyi oluştur ve boyutunu ayarla
    MainWindow w;
    w.resize(1280, 720);  // Pencereyi büyüt
    // w.setFixedSize(1280, 720); // Eğer boyut değişmesin istersen bunu kullan

    w.show();
    return a.exec();
}
