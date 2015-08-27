/****************************************************************************
**
** Copyright (C) 2014 Digia Plc
** All rights reserved.
** For any questions to Digia, please use contact form at http://www.qt.io
**
** This file is part of the Qt Virtual Keyboard add-on for Qt Enterprise.
**
** Licensees holding valid Qt Enterprise licenses may use this file in
** accordance with the Qt Enterprise License Agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.
**
** If you have questions regarding the use of this file, please use
** contact form at http://www.qt.io
**
****************************************************************************/

#include "styles_plugin.h"
#include "svgimageprovider.h"

#include <qqml.h>
#include <QtCore/QLibraryInfo>

/*!
    \qmlmodule QtQuick.Enterprise.VirtualKeyboard.Styles 2.0

    This module provides styling components for the Qt Virtual Keyboard.
*/

void StylesPlugin::registerTypes(const char *uri)
{
    Q_INIT_RESOURCE(styles);
    const QString path(QStringLiteral("qrc:///content/styles/"));
    qmlRegisterType(QUrl(path + QLatin1String("KeyboardStyle.qml")), uri, 1, 0, "KeyboardStyle");
    qmlRegisterType(QUrl(path + QLatin1String("KeyboardStyle.qml")), uri, 1, 1, "KeyboardStyle");
    qmlRegisterType(QUrl(path + QLatin1String("KeyboardStyle.qml")), uri, 1, 2, "KeyboardStyle");
    qmlRegisterType(QUrl(path + QLatin1String("KeyboardStyle.qml")), uri, 1, 3, "KeyboardStyle");
    qmlRegisterType(QUrl(path + QLatin1String("KeyboardStyle.qml")), uri, 2, 0, "KeyboardStyle");
    qmlRegisterType(QUrl(path + QLatin1String("KeyIcon.qml")), uri, 1, 0, "KeyIcon");
    qmlRegisterType(QUrl(path + QLatin1String("KeyIcon.qml")), uri, 2, 0, "KeyIcon");
    qmlRegisterType(QUrl(path + QLatin1String("KeyPanel.qml")), uri, 1, 0, "KeyPanel");
    qmlRegisterType(QUrl(path + QLatin1String("KeyPanel.qml")), uri, 2, 0, "KeyPanel");
    qmlRegisterType(QUrl(path + QLatin1String("SelectionListItem.qml")), uri, 1, 0, "SelectionListItem");
    qmlRegisterType(QUrl(path + QLatin1String("SelectionListItem.qml")), uri, 2, 0, "SelectionListItem");
    qmlRegisterType(QUrl(path + QLatin1String("TraceInputKeyPanel.qml")), uri, 2, 0, "TraceInputKeyPanel");
    qmlRegisterType(QUrl(path + QLatin1String("TraceCanvas.qml")), uri, 2, 0, "TraceCanvas");
}

void StylesPlugin::initializeEngine(QQmlEngine *engine, const char *uri)
{
    Q_UNUSED(uri)
    engine->addImageProvider(QStringLiteral("qtvkbsvg"), new SvgImageProvider());
}
