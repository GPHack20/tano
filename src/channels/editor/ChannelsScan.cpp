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

#include <QtCore/QDebug>
#include <QtCore/QDir>
#include <QtCore/QFile>

#include <VLCQtCore/Instance.h>
#include <VLCQtCore/Media.h>
#include <VLCQtCore/MediaPlayer.h>

#include "network/NetworkUdpxy.h"
#include "channels/containers/Channel.h"
#include "channels/models/ChannelsModel.h"

#include "ChannelsScan.h"
#include "ui_ChannelsScan.h"

ChannelsScan::ChannelsScan(QWidget *parent)
    : QWidget(parent),
      ui(new Ui::ChannelsScan)
{
    ui->setupUi(this);

    _media = 0;
    _player = 0;
    _udpxy = new NetworkUdpxy();
    _timer = new QTimer();
    connect(_timer, SIGNAL(timeout()), this, SLOT(checkCurrentIp()));
    connect(ui->buttonUpdate, SIGNAL(toggled(bool)), this, SLOT(refreshChannels(bool)));
}

ChannelsScan::~ChannelsScan()
{
    if (_media)
        delete _media;
    if (_player)
        delete _player;
    delete _timer;

    delete ui;
}

void ChannelsScan::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type())
    {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void ChannelsScan::refreshChannels(bool refresh)
{
    emit scan(refresh);

    if (!refresh) {
        _timer->stop();
        ui->progressBar->setValue(1);

        QFile::remove(QDir::tempPath() + "/tano-test.ts");
    } else {
        qDebug() << "Scanning:" << ui->ipFrom->text() << ui->ipPort->value() << ui->ipTimeout->value();

        QStringList ipFrom = ui->ipFrom->text().split(".");
        _currentIp[0] = ipFrom[0].toInt();
        _currentIp[1] = ipFrom[1].toInt();
        _currentIp[2] = ipFrom[2].toInt();
        _currentIp[3] = 1;

        _currentPort = ui->ipPort->value();
        _currentTimeout = ui->ipTimeout->value();

        checkIp();
    }
}

void ChannelsScan::checkIp()
{
    ui->progressBar->setValue(_currentIp[3]);
    if (_media) {
        disconnect(_media, SIGNAL(stateChanged(Vlc::State)), this, SLOT(setState(Vlc::State)));
        delete _media;
    }

    _media = new VlcMedia(_udpxy->processUrl(currentIp()), _instance);
    _media->record("test", QDir::tempPath(), Vlc::TS);
    connect(_media, SIGNAL(stateChanged(Vlc::State)), this, SLOT(setState(Vlc::State)));
    _player->open(_media);

    _timer->start(_currentTimeout);
}

void ChannelsScan::checkCurrentIp()
{
    if (_currentIpPlaying) {
        _player->stop();

        bool newChannel = true;
        for (int i = 0; i < _model->rowCount(); i++) {
            if (_model->row(i)->url() == currentIp()) {
                newChannel = false;
                break;
            }
        }

        if (newChannel) {
            qDebug() << "Scanning:" << "Channel Found";
            addItem(tr("New channel from scan %1").arg(currentIp()), currentIp());
        }
    }

    if (_currentIp[3] != 255) {
        _currentIp[3]++;
        checkIp();
    } else {
        ui->buttonUpdate->setChecked(false);
    }
}

QString ChannelsScan::currentIp()
{
    QString ip = "udp://@";
    ip.append(QString().number(_currentIp[0])+".");
    ip.append(QString().number(_currentIp[1])+".");
    ip.append(QString().number(_currentIp[2])+".");
    ip.append(QString().number(_currentIp[3])+":");
    ip.append(QString().number(_currentPort));

    return ip;
}

void ChannelsScan::setMediaInstance(VlcInstance *instance)
{
    _instance = instance;

    if (_player)
        delete _player;
    _player = new VlcMediaPlayer(_instance);
}

void ChannelsScan::setChannelsModel(ChannelsModel *model)
{
    _model = model;
}

void ChannelsScan::setState(const Vlc::State &state)
{
    if (state == Vlc::Playing)
        _currentIpPlaying = true;
    else
        _currentIpPlaying = false;
}
