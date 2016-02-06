/****************************************************************************
* Tano - An Open IP TV Player
* Copyright (C) 2016 Tadej Novak <tadej@tano.si>
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

#ifndef TANO_CHANNELSFILTERMODEL_H_
#define TANO_CHANNELSFILTERMODEL_H_

#include <QtCore/QSortFilterProxyModel>

#include "channels/containers/Channel.h"

class ChannelsFilterModel : public QSortFilterProxyModel
{
    Q_OBJECT
public:
    ChannelsFilterModel(QObject *parent = 0);
    ~ChannelsFilterModel();

    QString name() const;

    inline QString category() const { return _category; }
    void setCategory(const QString &category);

    inline QString language() const { return _language; }
    void setLanguage(const QString &language);

    inline QList<Channel::Type> types() const { return _types; }
    void setTypes(const QList<Channel::Type> &types);

protected:
    bool filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const;

private:
    QString _category;
    QString _language;
    QList<Channel::Type> _types;
};

#endif // TANO_CHANNELSFILTERMODEL_H_
