/****************************************************************************
* Tano - An Open IP TV Player
* Copyright (C) 2011 Tadej Novak <tadej@tano.si>
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

#ifndef TANO_TVHEADENDGENERATOR_H_
#define TANO_TVHEADENDGENERATOR_H_

#include <QtCore/QMap>
#include <QtCore/QString>

class Channel;
class PlaylistModel;

class TvheadendGenerator
{
public:
    TvheadendGenerator(const QString &location,
                       const QString &interface);
	~TvheadendGenerator();

    bool write(PlaylistModel *model);

private:
    void clean();
    QString fileChannel(int number) const;
    QString fileIpService(int number) const;
    QString fileTag(int number) const;
    QString fileXmltv(const QString &name) const;
	void generateItem(Channel *channel);
    void generateTag(int id,
                     const QString &name);
    QString indent(int indentLevel) const;
    void processTags(PlaylistModel *model);
    int tag(const QString &name) const;

    QMap<QString, int> _tags;
    QMap<int, QString> _tagsName;

	QString _location;
	QString _interface;
};

#endif // TANO_TVHEADENDGENERATOR_H_
