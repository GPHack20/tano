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

#ifndef TANO_SETTINGSBACKEND_H_
#define TANO_SETTINGSBACKEND_H_

#include <QtWidgets/QWidget>

namespace Ui
{
    class SettingsBackend;
}

class SettingsBackend : public QWidget
{
Q_OBJECT
public:
    SettingsBackend(QWidget *parent = 0);
    ~SettingsBackend();

    int vout() const;
    void setVout(int id);
    int aout() const;
    void setAout(int id);
#if defined(Q_OS_WIN32)
    bool yuvToRgb() const;
    void setYuvToRgb(bool enabled);
#endif
    bool spdif() const;
    void setSpdif(bool enabled);

    bool rememberChannelSettings() const;
    void setRememberChannelSettings(bool remember);
    bool rememberPerChannel() const;
    void setRememberPerChannel(bool remember);
    int aspectRatio() const;
    void setAspectRatio(int id);
    int cropRatio() const;
    void setCropRatio(int id);
    int deinterlacing() const;
    void setDeinterlacing(int id);
    QString audio() const;
    void setAudio(const QString &audio);
    QString sub() const;
    void setSub(const QString &sub);

    bool mute() const;
    void setMute(bool enabled);
    bool teletext() const;
    void setTeletext(bool enabled);

protected:
    void changeEvent(QEvent *e);

private:
    Ui::SettingsBackend *ui;
};

#endif // TANO_SETTINGSBACKEND_H_
