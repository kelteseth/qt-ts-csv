#include "ConverterGuiProxy.hpp"

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQuickWindow>
#include <QFontDatabase>

int main(int argc, char **argv)
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

#ifdef Q_OS_WINDOWS
    QQuickWindow::setTextRenderType(QQuickWindow::TextRenderType::NativeTextRendering);
#endif

    QGuiApplication app(argc, argv);
    app.setOrganizationName("Federico Guerinoni");
    app.setOrganizationDomain("Federico Guerinoni");
    app.setApplicationName("qt-ts-csv");


    QFontDatabase::addApplicationFont(":/assets/fonts/Roboto-Light.ttf");
    QFontDatabase::addApplicationFont(":/assets/fonts/Roboto-Regular.ttf");

    QQmlApplicationEngine engine;

    ConverterGuiProxy cgp;
    engine.rootContext()->setContextProperty(QStringLiteral("converter"), &cgp);
    engine.rootContext()->setContextProperty(QStringLiteral("version"),
                                             VERSION);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty()) {
        return -1;
    }

    return QGuiApplication::exec();
}
