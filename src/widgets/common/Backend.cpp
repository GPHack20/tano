/****************************************************************************
* Tano - An Open IP TV Player
* Copyright (C) 2012 Tadej Novak <tadej@tano.si>
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program. If not, see <http://www.gnu.org/licenses/>.
*****************************************************************************/

#include <QtCore/QDebug>

#include <VLCQtCore/Common.h>
#include <VLCQtCore/Enums.h>
#include <VLCQtCore/Instance.h>

#include "settings/Settings.h"

#include "Backend.h"

QStringList Tano::Backend::args()
{
    QStringList args = VlcCommon::args();

    QScopedPointer<Settings> settings(new Settings());
    if (settings->aout() != -1) {
        args << QString("--aout=" + Vlc::audioOutput()[settings->aout()]);
        qDebug() << "Using aout:" << Vlc::audioOutput()[settings->aout()];
    }

    if (settings->vout() != -1) {
        args << QString("--vout=" + Vlc::videoOutput()[settings->vout()]);
        qDebug() << "Using vout:" << Vlc::videoOutput()[settings->vout()];
    }

#if defined(Q_OS_WIN32)
    if (settings->yuvToRgb())
        args << "--directx-hw-yuv";
    else
        args << "--no-directx-hw-yuv";
#endif

    if (settings->spdif())
        args << "--spdif";

    return args;
}

QString Tano::Backend::versionCore()
{
    QString version = VlcInstance::version();

    return version;
}

QString Tano::Backend::versionLibrary()
{
    QString version = VlcInstance::libVersion();

    return version;
}
