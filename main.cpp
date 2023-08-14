#include <QApplication>
#include <QPushButton>
#include "GraphicsView.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    GraphicsView view(nullptr);
    view.setFixedSize(600, 600);
    view.show();
    return QApplication::exec();
}
