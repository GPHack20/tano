/****************************************************************************
* Common.h: Basic functions for Tano application
*****************************************************************************
* Copyright (C) 2008-2010 Tadej Novak
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*
* This file may be used under the terms of the
* GNU General Public License version 3.0 as published by the
* Free Software Foundation and appearing in the file LICENSE.GPL
* included in the packaging of this file.
*****************************************************************************/

#ifndef TANO_COMMON_H_
#define TANO_COMMON_H_

#include <QtCore/QString>
#include <QtGui/QWidget>

class Common
{
public:
	// About dialog
	static void about(QWidget *parent = 0 );
	// Resources locators
	static QString locateResource(const QString &file);
	static QString locateTranslation(const QString &file);
	// Backend settings
	static QList<const char *> libvlcArgs();
};

#endif // TANO_COMMON_H_
