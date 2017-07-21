/****************************************************************************
**
** Copyright (C) 2012 Denis Shienkov <denis.shienkov@gmail.com>
** Copyright (C) 2012 Laszlo Papp <lpapp@kde.org>
** Contact: https://www.qt.io/licensing/
**
** This file is part of the QtSerialPort module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include <QApplication>
#include <QProcess>
//#include "mainwindow.h"
#include "bvs_wallet.h"
#include <QDebug>


int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    QProcess * process = new QProcess;
    QString cmd = "multichaind BVS_R2@blockachin-voting.org:6733";
    bool daemon = false;

    qDebug() << "Starte BVS-Service... Please be patient while daemon starts!";

    qDebug() << "argc = " << argc;
    for(int i = 0; i < argc; i++) {
        qDebug() << "argv[" << i << "] = " << argv[i];
        QString arg = argv[i];
        if (arg == "--with-multichain") {
            daemon = true;
            // cmdArray[0] = "multichaind ";
        }
        else if (arg.contains("blockchain") == true) {
            // cmdArray[1] += split("=") [1]
        }
        else if (arg.contains("server") == true) {
            // cmdArray[2] =split("=") [1]
        }

        else if (arg.contains("port") == true) {
            // cmdArray[3] = split("=") [1]
        }

        //cmdArray[4] = " -daemon";
        cmd += " -daemon";
    }

    if (daemon == true) {
        process->start(cmd);
        process->waitForFinished();
        qDebug() << "Getting data from blockchain...";
    }

    BVS_Wallet b;
    b.show();

    return a.exec();
}
