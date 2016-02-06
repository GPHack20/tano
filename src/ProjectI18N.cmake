#############################################################################
# Tano - An Open IP TV Player
# Copyright (C) 2016 Tadej Novak <tadej@tano.si>
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program. If not, see <http://www.gnu.org/licenses/>./
#############################################################################

SET(TEMPLATE ${CMAKE_SOURCE_DIR}/i18n/source.ts)

IF(REFRESH_TRANSLATIONS)
    IF(NOT Qt5_LUPDATE_EXECUTABLE)
        MESSAGE(WARNING "Tano could not find lupdate. You won't be able to update translations.")
    ENDIF()
ENDIF()

IF(NOT Qt5_LRELEASE_EXECUTABLE)
    MESSAGE(WARNING "Tano could not find lrelease. Your build won't contain translations.")
ENDIF()

## Collect all translations files
FILE(GLOB Project_TS ${CMAKE_SOURCE_DIR}/i18n/*.ts)
LIST(REMOVE_ITEM Project_TS ${TEMPLATE})

IF(Qt5_LRELEASE_EXECUTABLE)
    IF(REFRESH_TRANSLATIONS)
        FILE(GLOB_RECURSE translate_SRCS ${CMAKE_SOURCE_DIR}/src/*.cpp)
        FILE(GLOB_RECURSE translate_UIS ${CMAKE_SOURCE_DIR}/src/*.ui)
        SET(translate_SRCS ${translate_SRCS} ${translate_UIS})

        QT5_CREATE_TRANSLATION(Project_QMS ${translate_SRCS} ${Project_TS})
        QT5_CREATE_TRANSLATION(Project_QMS_SRC ${translate_SRCS} ${TEMPLATE})
    ELSE()
        QT5_ADD_TRANSLATION(Project_QMS ${Project_TS})
    ENDIF()

    SET(Project_Srcs
        ${Project_Srcs}
        ${Project_QMS}
        ${Project_QMS_SRC}
    )
ENDIF()

## Installation
IF(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    SET_SOURCE_FILES_PROPERTIES(
        ${Project_QMS}
        PROPERTIES
        MACOSX_PACKAGE_LOCATION Resources/i18n
    )
ELSE()
    INSTALL(FILES ${Project_QMS} DESTINATION "${CMAKE_INSTALL_PREFIX}/${PROJECT_INSTALL_DATA_DIR}/i18n")
ENDIF()
