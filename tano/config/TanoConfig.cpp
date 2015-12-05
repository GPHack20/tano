/****************************************************************************
* Tano - An Open IP TV Player
* Copyright (C) 2013 Tadej Novak <tadej@tano.si>
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

#include "core/Common.h"

#include "TanoConfigGenerated.h"
#include "TanoConfig.h"

QString TanoConfig::applicationDataDir() const
{
    return QString(APP_DATA_DIR);
}

QString TanoConfig::name() const
{
    return "Tano";
}

QString TanoConfig::version() const
{
    return Tano::versionCore();
}

QString TanoConfig::email() const
{
    return "info@tano.si";
}

QString TanoConfig::projectUrl() const
{
    return "http://projects.tano.si";
}

QString TanoConfig::updateUrl() const
{
    return "http://update.tano.si";
}

QString TanoConfig::downloadUrl() const
{
    return "http://update.tano.si";
}

bool TanoConfig::requiresAuthentication() const
{
    return false;
}

bool TanoConfig::recorderIdUrl() const
{
    return true;
}

bool TanoConfig::editorEnabled() const
{
    return true;
}
