/****************************************************************************
* Tano - An Open IP TV Player
* Copyright (C) 2013 Tadej Novak <tadej@tano.si>
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

#ifndef TANO_FILE_H_
#define TANO_FILE_H_

#include <QtCore/QString>

struct File
{
    // FileTypes
    enum Type
    {
        Unknown = -1,
        CSV = 20,
        Directory = 0,
        Files = 1,
        GoTV = 40,
        JS = 21,
        M3U = 10,
        M3UClean = 11,
        M3UUdpxy = 12,
        Subtitles = 3,
        Url = 2,
        XmltvFile = 30,
        XmltvId = 31
    };

    QString path;
    Type type;
};

#endif // TANO_FILE_H_
