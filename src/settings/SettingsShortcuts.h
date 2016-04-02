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

#ifndef TANO_SETTINGSSHORTCUTS_H_
#define TANO_SETTINGSSHORTCUTS_H_

#include <QtCore/QSettings>
#include <QtCore/QStringList>
#include <QtGui/QKeySequence>

class SettingsShortcuts : public QSettings
{
public:
    explicit SettingsShortcuts(QObject *parent = 0);
    ~SettingsShortcuts();

    static QString fileName();

    QStringList readKeys() const;
    void writeShortcut(const QString &action,
                       const QKeySequence &sequence);

    static const QStringList DEFAULT_SHORTCUTS_ACTIONS;
    static const QStringList DEFAULT_SHORTCUTS_KEYS;
    static const QStringList DEFAULT_SHORTCUTS_STRINGS;
};

#endif // TANO_SETTINGSSHORTCUTS_H_