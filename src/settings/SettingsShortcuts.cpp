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

#include "application/Common.h"
#include "settings/SettingsShortcuts.h"

SettingsShortcuts::SettingsShortcuts(QObject *parent)
    : QSettings(QSettings::IniFormat,
                QSettings::UserScope,
                Tano::name(),
                "Shortcuts",
                parent) { }

SettingsShortcuts::~SettingsShortcuts() { }

QStringList SettingsShortcuts::readKeys() const
{
    QStringList list;
    for (int i = 0; i < DEFAULT_SHORTCUTS_ACTIONS.size(); i++)
        list << value(DEFAULT_SHORTCUTS_ACTIONS[i], DEFAULT_SHORTCUTS_KEYS[i]).toString();

    return list;
}

void SettingsShortcuts::write(const QStringList &keys)
{
    for (int i = 0; i < DEFAULT_SHORTCUTS_ACTIONS.size(); i++)
        setValue(DEFAULT_SHORTCUTS_ACTIONS[i], keys[i]);

    sync();
}
