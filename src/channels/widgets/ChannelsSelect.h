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

#ifndef TANO_CHANNELSSELECT_H_
#define TANO_CHANNELSSELECT_H_

#include <QtCore/QTimer>

class QLCDNumber;
class QShortcut;

class ChannelsSelect : public QObject
{
    Q_OBJECT
public:
    ChannelsSelect(QWidget *parent,
                  QLCDNumber *number,
                  const QList<int> &list);
    ~ChannelsSelect();

public slots:
    inline void back() { channel(false); }
    void channel(bool direction);
    inline void next() { channel(true); }

private slots:
    void display();
    void keyPressed();

signals:
    void channelSelect(const int);

private:
    void process(int key);

    QList<int> _channels;
    QList<QShortcut *> _key;
    QLCDNumber *_lcd;
    QTimer *_timer;

    int _digit;
    int _full;
    int _number[3];
    int _old;
};

#endif // TANO_CHANNELSSELECT_H_
