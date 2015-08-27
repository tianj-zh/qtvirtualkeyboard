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

#include "declarativeinputmethod.h"
#include "declarativetrace.h"
#include <QVariant>

/*!
    \qmltype InputMethod
    \instantiates DeclarativeInputMethod
    \inqmlmodule QtQuick.Enterprise.VirtualKeyboard
    \ingroup qtvirtualkeyboard-qml
    \brief Base type for creating input method in QML.

    The InputMethod type lets you create a custom input method
    which can be assigned to InputEngine.
*/

/*!
    \qmlproperty InputContext InputMethod::inputContext

    The input context.
*/

/*!
    \qmlproperty InputEngine InputMethod::inputEngine

    The input engine.
*/

/*!
    \qmlmethod list<int> InputMethod::inputModes(string locale)

    Returns a list of input modes for \a locale.
*/

/*!
    \qmlmethod bool InputMethod::setInputMode(string locale, int inputMode)

    Changes \a inputMode and \a locale for this input method. The method returns
    \c true if successful.
*/

/*!
    \qmlmethod bool InputMethod::setTextCase(int textCase)

    Updates \a textCase for this input method. The method returns \c true if
    successful.

    The possible values for the text case are:

    \list
        \li \c InputEngine.Lower Lower case text.
        \li \c InputEngine.Upper Upper case text.
    \endlist
*/

/*!
    \qmlmethod bool InputMethod::keyEvent(int key, string text, int modifiers)

    The purpose of this method is to handle the key events generated by the the
    input engine.

    The \a key parameter specifies the code of the key to handle. The key code
    does not distinguish between capital and non-capital letters. The \a
    text parameter contains the Unicode text for the key. The \a modifiers
    parameter contains the key modifiers that apply to \a key.

    This method returns \c true if the key event was successfully handled.
    If the return value is \c false, the key event is redirected to the default
    input method for futher processing.
*/

/*!
    \qmlmethod InputMethod::reset()

    This method is called by the input engine when this input method needs to be
    reset. The input method must reset its internal state only. The main
    difference to the update() method is that reset() modifies only
    the input method state; it must not modify the input context.
*/

/*!
    \qmlmethod InputMethod::update()

    This method is called by the input engine when the input method needs to be
    updated. The input method must close the current pre-edit text and
    restore the internal state to the default.
*/

/*!
    \qmlmethod list<int> InputMethod::selectionLists()

    Returns the list of selection types used for this input method.

    This method is called by the input engine when the input method is being
    activated. The input method can reserve the selection lists for its use
    by returning a list of selection list types required.
*/

/*!
    \qmlmethod int InputMethod::selectionListItemCount(int type)

    Returns the number of items in the selection list identified by \a type.
*/

/*!
    \qmlmethod var InputMethod::selectionListData(int type, int index, int role)

    Returns item data for a selection list identified by \a type. The \a role
    parameter specifies which data is requested. The \a index parameter is a
    zero based index into the selecteion list.
*/

/*!
    \qmlmethod void InputMethod::selectionListItemSelected(int type, int index)

    This method is called when an item at \a index has been selected by the
    user. The selection list is identified by the \a type parameter.
*/

/*!
    \qmlsignal InputMethod::selectionListChanged(int type)

    The input method emits this signal when the contents of the selection list
    are changed. The \a type parameter specifies which selection list has
    changed.
*/

/*!
    \qmlsignal InputMethod::selectionListActiveItemChanged(int type, int index)

    The input method emits this signal when the current \a index has changed
    in the selection list identified by \a type.
*/

/*!
    \qmlmethod list<int> InputMethod::patternRecognitionModes()
    \since QtQuick.Enterprise.VirtualKeyboard 2.0

    Returns list of supported pattern recognition modes.

    This method is invoked by the input engine to query the list of
    supported pattern recognition modes.
*/

/*!
    \qmlmethod Trace InputMethod::traceBegin(var traceCaptureDeviceInfo, var traceScreenInfo)
    \since QtQuick.Enterprise.VirtualKeyboard 2.0

    This method is called when a trace interaction starts. The \a traceCaptureDeviceInfo provides
    information about the source device and the \a traceScreenInfo provides information about the screen
    context.

    If the input method accepts the event and wants to capture the trace input, it must return
    a new Trace object. This object must remain valid until the \l {InputMethod::traceEnd()}
    {InputMethod.traceEnd()} method is called. If the Trace is rendered on screen, it remains there
    until the Trace object is destroyed.
*/

/*!
    \qmlmethod bool InputMethod::traceEnd(Trace trace)
    \since QtQuick.Enterprise.VirtualKeyboard 2.0

    This method is called when the trace interaction ends. The input method should destroy the \a trace object
    at some point after this function is called. See the \l Trace API how to access the gathered
    data.
*/

DeclarativeInputMethod::DeclarativeInputMethod(QObject *parent) :
    AbstractInputMethod(parent)
{
}

DeclarativeInputMethod::~DeclarativeInputMethod()
{
}

QList<DeclarativeInputEngine::InputMode> DeclarativeInputMethod::inputModes(const QString &locale)
{
    QVariant result;
    QMetaObject::invokeMethod(this, "inputModes",
                              Q_RETURN_ARG(QVariant, result),
                              Q_ARG(QVariant, locale));
    QList<DeclarativeInputEngine::InputMode> inputModeList;
    foreach (const QVariant &inputMode, result.toList()) {
        inputModeList.append(static_cast<DeclarativeInputEngine::InputMode>(inputMode.toInt()));
    }
    return inputModeList;
}

bool DeclarativeInputMethod::setInputMode(const QString &locale, DeclarativeInputEngine::InputMode inputMode)
{
    QVariant result;
    QMetaObject::invokeMethod(this, "setInputMode",
                              Q_RETURN_ARG(QVariant, result),
                              Q_ARG(QVariant, locale),
                              Q_ARG(QVariant, static_cast<int>(inputMode)));
    return result.toBool();
}

bool DeclarativeInputMethod::setTextCase(DeclarativeInputEngine::TextCase textCase)
{
    QVariant result;
    QMetaObject::invokeMethod(this, "setTextCase",
                              Q_RETURN_ARG(QVariant, result),
                              Q_ARG(QVariant, static_cast<int>(textCase)));
    return result.toBool();
}

bool DeclarativeInputMethod::keyEvent(Qt::Key key, const QString &text, Qt::KeyboardModifiers modifiers)
{
    QVariant result;
    QMetaObject::invokeMethod(this, "keyEvent",
                              Q_RETURN_ARG(QVariant, result),
                              Q_ARG(QVariant, key),
                              Q_ARG(QVariant, text),
                              Q_ARG(QVariant, (int)modifiers));
    return result.toBool();
}

QList<DeclarativeSelectionListModel::Type> DeclarativeInputMethod::selectionLists()
{
    QVariant result;
    QMetaObject::invokeMethod(this, "selectionLists",
                              Q_RETURN_ARG(QVariant, result));
    QList<DeclarativeSelectionListModel::Type> selectionListsList;
    foreach (const QVariant &selectionListType, result.toList()) {
        selectionListsList.append(static_cast<DeclarativeSelectionListModel::Type>(selectionListType.toInt()));
    }
    return selectionListsList;
}

int DeclarativeInputMethod::selectionListItemCount(DeclarativeSelectionListModel::Type type)
{
    QVariant result;
    QMetaObject::invokeMethod(this, "selectionListItemCount",
                              Q_RETURN_ARG(QVariant, result),
                              Q_ARG(QVariant, static_cast<int>(type)));
    return result.toInt();
}

QVariant DeclarativeInputMethod::selectionListData(DeclarativeSelectionListModel::Type type, int index, int role)
{
    QVariant result;
    QMetaObject::invokeMethod(this, "selectionListData",
                              Q_RETURN_ARG(QVariant, result),
                              Q_ARG(QVariant, static_cast<int>(type)),
                              Q_ARG(QVariant, index),
                              Q_ARG(QVariant, role));
    if (result.isNull()) {
        result = AbstractInputMethod::selectionListData(type, index, role);
    }
    return result;
}

void DeclarativeInputMethod::selectionListItemSelected(DeclarativeSelectionListModel::Type type, int index)
{
    QMetaObject::invokeMethod(this, "selectionListItemSelected",
                              Q_ARG(QVariant, static_cast<int>(type)),
                              Q_ARG(QVariant, index));
}

QList<DeclarativeInputEngine::PatternRecognitionMode> DeclarativeInputMethod::patternRecognitionModes() const
{
    QVariant result;
    QMetaObject::invokeMethod(const_cast<DeclarativeInputMethod *>(this), "patternRecognitionModes",
                              Q_RETURN_ARG(QVariant, result));
    QList<DeclarativeInputEngine::PatternRecognitionMode> patterRecognitionModeList;
    foreach (const QVariant &patterRecognitionMode, result.toList()) {
        patterRecognitionModeList.append(static_cast<DeclarativeInputEngine::PatternRecognitionMode>(patterRecognitionMode.toInt()));
    }
    return patterRecognitionModeList;
}

DeclarativeTrace *DeclarativeInputMethod::traceBegin(DeclarativeInputEngine::PatternRecognitionMode patternRecognitionMode,
                                                     const QVariantMap &traceCaptureDeviceInfo, const QVariantMap &traceScreenInfo)
{
    Q_UNUSED(patternRecognitionMode)
    QVariant result;
    QMetaObject::invokeMethod(this, "traceBegin",
                              Q_RETURN_ARG(QVariant, result),
                              Q_ARG(QVariant, traceCaptureDeviceInfo),
                              Q_ARG(QVariant, traceScreenInfo));
    return result.value<DeclarativeTrace *>();
}

bool DeclarativeInputMethod::traceEnd(DeclarativeTrace *trace)
{
    QVariant result;
    QMetaObject::invokeMethod(this, "traceEnd",
                              Q_RETURN_ARG(QVariant, result),
                              Q_ARG(QVariant, QVariant::fromValue(trace)));
    return result.toBool();
}

void DeclarativeInputMethod::reset()
{
    QMetaObject::invokeMethod(this, "reset");
}

void DeclarativeInputMethod::update()
{
    QMetaObject::invokeMethod(this, "update");
}
