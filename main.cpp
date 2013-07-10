#include <QApplication>
#include "mainwindow.hpp"

#include "utils/factory.hpp"

#include "static_tests/test_parameter_traits.hpp"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    
    return a.exec();
}
