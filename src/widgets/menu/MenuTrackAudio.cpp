/****************************************************************************
* Tano - An Open IP TV Player
* Copyright (C) 2008-2010 Tadej Novak <ntadej@users.sourceforge.net>
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*****************************************************************************/

#include <QtCore/QEvent>

#include "MenuTrackAudio.h"

MenuTrackAudio::MenuTrackAudio(QWidget *parent)
	: MenuCore(parent)
{
	setTitle(tr("Audio track"));
    setIcon(QIcon(":/icons/mimetypes/16/audio-x-generic.png"));
	actionNext()->setText(tr("Next audio track"));
	setType(Vlc::AudioTrack);
}

MenuTrackAudio::~MenuTrackAudio() { }

void MenuTrackAudio::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type())
    {
    case QEvent::LanguageChange:
        setTitle(tr("Audio track"));
        actionNext()->setText(tr("Next audio track"));
        break;
    default:
        break;
    }
}
