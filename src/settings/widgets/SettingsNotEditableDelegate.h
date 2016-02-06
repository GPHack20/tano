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

#ifndef TANO_SETTINGSNOTEDITABLEDELEGATE_H_
#define TANO_SETTINGSNOTEDITABLEDELEGATE_H_

#include <QtWidgets/QStyledItemDelegate>

class SettingsNotEditableDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    SettingsNotEditableDelegate(QObject *parent = 0);

    QWidget *createEditor(QWidget *parent,
                          const QStyleOptionViewItem &option,
                          const QModelIndex &index) const;
};

#endif // TANO_SETTINGSNOTEDITABLEDELEGATE_H_
