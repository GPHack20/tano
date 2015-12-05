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

#ifndef TANO_TIMER_H_
#define TANO_TIMER_H_

#include <QtCore/QDate>
#include <QtCore/QString>
#include <QtCore/QTime>

#include "common/ListItem.h"

class Timer : public ListItem
{
Q_OBJECT
public:
    enum Roles {
        DisplayRole = Qt::DisplayRole,
        DecorationRole = Qt::DecorationRole,
        NameRole = Qt::UserRole + 1,
        ChannelIdRole,
        FileRole,
        DateRole,
        StartTimeRole,
        EndTimeRole,
        StartDateTimeRole,
        EndDateTimeRole,
        TypeRole,
        StateRole
    };

    // Timer states
    enum State
    {
        Enabled,
        Disabled,
        Recording,
        Finished,
        Expired
    };

    // Timer types
    enum Type
    {
        Once,
        Daily,
        Weekly,
        Weekdays,
        Instant
    };

    explicit Timer(const QString &name,
                   const QString &channelId,
                   const Type &type = Once,
                   QObject *parent = 0);
    explicit Timer(Timer *timer);
    explicit Timer(QObject *parent = 0);
    ~Timer();

    inline QString id() const { return _startTime.toString(); }
    QVariant data(int role) const;
    QString display() const;
    QPixmap decoration() const;
    QHash<int, QByteArray> roleNames() const;

    inline QString name() const { return _name; }
    void setName(const QString &name);
    inline QString channelId() const { return _channelId; }
    void setChannelId(const QString &channelId);
    inline QString file() const { return _file; }
    void setFile(const QString &file);
    inline QDate date() const { return _date; }
    void setDate(const QDate &date);
    inline QTime startTime() const { return _startTime; }
    void setStartTime(const QTime &startTime);
    inline QTime endTime() const { return _endTime; }
    void setEndTime(const QTime &endTime);
    QDateTime startDateTime() const;
    QDateTime endDateTime() const;
    inline Type type() const { return _type; }
    void setType(const Type &type);
    inline State state() const { return _state; }
    void setState(const State &state);

    static QStringList states();
    static QStringList types();
    static QStringList typesLong();

private:
    QString _name;
    QString _channelId;
    QString _file;
    QDate _date;
    QTime _startTime;
    QTime _endTime;
    Type _type;
    State _state;
};

#endif // TANO_TIMER_H_
