#include <QApplication>
#include "mainwindow.hpp"

#include "static_tests/test_parameter_traits.hpp"

#include "entitymanager.hpp"
#include "systems/systemmanager.hpp"
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    cerr << EntityManager::geTkey(0) << endl;
    cerr << SystemManager::count() << endl;

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    
    return a.exec();
}
