
/**
 * PyOtherSide: Asynchronous Python 3 Bindings for Qt 5
 * Copyright (c) 2011, 2013, Thomas Perl <m@thp.io>
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH
 * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND
 * FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT,
 * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM
 * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR
 * OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 **/

#ifndef PYOTHERSIDE_QPYTHON_PRIV_H
#define PYOTHERSIDE_QPYTHON_PRIV_H

#include "Python.h"

#include <QObject>
#include <QVariant>
#include <QString>
#include <QMutex>

class QPythonPriv : public QObject {
    Q_OBJECT

    public:
        QPythonPriv();
        ~QPythonPriv();

        PyObject *eval(QString expr);

        void enter();
        void leave();

        void receiveObject(PyObject *o);
        static void closing();
        static QPythonPriv *instance();

        QString formatExc();

        PyObject *locals;
        PyObject *globals;
        PyThreadState *state;
        PyObject *atexit_callback;
        PyObject *image_provider;
        PyObject *traceback_mod;

        QMutex mutex;

    signals:
        void receive(QVariant data);
};

#endif /* PYOTHERSIDE_QPYTHON_PRIV_H */
