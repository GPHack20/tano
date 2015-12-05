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

#ifndef TANO_CSVGENERATOR_H_
#define TANO_CSVGENERATOR_H_

#include <QtCore/QFile>
#include <QtCore/QTextStream>

class Channel;
class PlaylistModel;

class CSVGenerator
{
public:
    CSVGenerator(const QString &file);
    ~CSVGenerator();

    bool write(PlaylistModel *model);

private:
    void generateItem(Channel *channel);

    QFile *_file;
    QTextStream _out;

    QString _hd;
    QString _radio;
};

#endif // TANO_CSVGENERATOR_H_
