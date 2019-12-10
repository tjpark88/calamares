/* === This file is part of Calamares - <https://github.com/calamares> ===
 *
 *   Copyright 2014, Teo Mrnjavac <teo@kde.org>
 *   Copyright 2018, Adriaan de Groot <groot@kde.org>
 *
 *   Originally from the Manjaro Installation Framework
 *   by Roland Singer <roland@manjaro.org>
 *   Copyright (C) 2007 Free Software Foundation, Inc.
 *
 *   Calamares is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   Calamares is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with Calamares. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef TIMEZONEWIDGET_H
#define TIMEZONEWIDGET_H

#include "localeglobal.h"

#include "locale/TimeZone.h"

#include <QFile>
#include <QFont>
#include <QFontMetrics>
#include <QImage>
#include <QList>
#include <QMouseEvent>
#include <QPainter>
#include <QStringList>
#include <QTextStream>
#include <QWidget>

class TimeZoneWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TimeZoneWidget( QWidget* parent = nullptr );

    LocaleGlobal::Location getCurrentLocation() { return currentLocation; }
    void setCurrentLocation( QString region, QString zone );
    void setCurrentLocation( const CalamaresUtils::Locale::TZZone* location );

signals:
    void locationChanged( LocaleGlobal::Location location );

private:
    QFont font;
    QImage background, pin, currentZoneImage;
    QList< QImage > timeZoneImages;
    LocaleGlobal::Location currentLocation;

    QPoint getLocationPosition( const LocaleGlobal::Location& l )
    {
        return getLocationPosition( l.longitude, l.latitude );
    }
    QPoint getLocationPosition( double longitude, double latitude );

    void paintEvent( QPaintEvent* event );
    void mousePressEvent( QMouseEvent* event );
};

#endif  // TIMEZONEWIDGET_H
