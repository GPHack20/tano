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

#ifndef TANO_BROWSEWIDGET_H_
#define TANO_BROWSEWIDGET_H_

#include <QtWidgets/QWidget>

#include "common/File.h"

class QLineEdit;
class QPushButton;

class BrowseWidget : public QWidget
{
Q_OBJECT
public:
    BrowseWidget(QWidget *parent = 0);
    ~BrowseWidget();

    QLineEdit *edit() { return _edit; }
    void setType(const File::Type &type) { _type = type; }
    void setValue(const QString &value);
    QString value() const;

signals:
    void valueChanged(const QString &);

private slots:
    void browse();

private:
    QLineEdit *_edit;
    QPushButton *_browse;

    File::Type _type;
};

#endif // TANO_BROWSEWIDGET_H_
