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

#ifndef TANO_MAINWINDOW_H_
#define TANO_MAINWINDOW_H_

#include <QtCore/QTimer>
#include <QtGui/QCloseEvent>
#include <QtWidgets/QMainWindow>

#include <VLCQtCore/Enums.h>

class QShortcut;
class QWidgetAction;

class Channel;
class ChannelsSelect;
class NetworkDownload;
class LocaleManager;
class MediaPlayer;
class NetworkUdpxy;
class ScheduleTab;
class SettingsDialog;
class ShowInfoTab;
class OsdFloat;
class ChannelsEditor;
class ChannelsModel;
class ChannelsTab;
class Recorder;
class Timer;
class TrayIcon;
class Updates;
class XmltvManager;
class XmltvProgramme;

class TestMain;

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
Q_OBJECT
public:
    explicit MainWindow();
    ~MainWindow();

public slots:
    void single();
    void dockClicked();

protected:
    void showEvent(QShowEvent *event);
    void changeEvent(QEvent *e);
    void closeEvent(QCloseEvent *event);
    bool eventFilter(QObject *obj,
                     QEvent *event);

signals:
    void windowWasShown();

private slots:
    void initUpdates();
    void exit();
    void aboutTano();
    void support();

    void currentWidget(QWidget *widget);

    void showSchedule();
    void showScheduleCurrent();
    void showRecorder();
    void showChannelsEditor();

    void playChannel(Channel* channel);
    void playRecording(Timer* recording);

    void stop();
    void setState(const Vlc::State &state);

    void openChannelsList();
    void openChannelsListComplete();

    void tooltip(const QString &channelNow = "stop");
    void top();
    void lite();
    void tray();
    void showOsd(const QPoint &pos);
    void showVideo(int count = 0);
    void toggleFullscreen(bool enabled);
    void toggleMouse(bool enabled = false);
    void toggleOsdControls(bool enabled = false);
    void preview(bool enabled = false);

    void recordNow(bool start);
    void recordProgramme(XmltvProgramme *programme);

private:
    Ui::MainWindow *ui;
    Qt::WindowFlags _flags;

    //Initialising functions
    void createBackend();
    void createConnections();
    void createGui();
    void createMenus();
    void createSettings();
    void createDesktopStartup();
    void createShortcuts();

    //Settings
    bool _channelPlayback;
    int _desktopWidth;
    int _desktopHeight;
    bool _hasChannels;
    bool _hideToTray;
    bool _isLite;
    bool _liteMenu;
    bool _muteOnMinimize;
    bool _muteOnMinimizeCurrent;
    bool _recordNow;
    int _posX;
    int _posY;
    bool _udpxyEnabled;
    QString _wheelType;

    //Main
    ChannelsSelect *_select;
    LocaleManager *_locale;
    MediaPlayer *_mediaPlayer;
    ChannelsModel *_model;
    Recorder *_recorder;
    Updates *_updates;

    //Playback and channels
    Channel *_channel;
    XmltvManager *_xmltv;
    QString _channelsListFile;
    QTimer *_previewTimer;
    Timer *_recording;
    NetworkUdpxy *_udpxy;

    //GUI
    ChannelsTab *_channelsTab;
    ScheduleTab *_scheduleTab;
    ShowInfoTab *_showInfoTab;

    SettingsDialog *_settingsDialog;

    OsdFloat *_osdFloat;
    ChannelsEditor *_channelsEditor;
    QTimer *_mouseTimer;

    //Menus and actions
    TrayIcon *_trayIcon;
    QMenu *_rightMenu;
    QList<QAction*> _actions;
    QList<QAction*> _actionsFull;
};

#endif // TANO_MAINWINDOW_H_
