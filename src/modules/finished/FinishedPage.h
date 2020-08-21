/* === This file is part of Calamares - <https://github.com/calamares> ===
 *
 *   SPDX-FileCopyrightText: 2014-2015 Teo Mrnjavac <teo@kde.org>
 *   SPDX-FileCopyrightText: 2017 Adriaan de Groot <groot@kde.org>
 *   SPDX-License-Identifier: GPL-3.0-or-later
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

#ifndef FINISHEDPAGE_H
#define FINISHEDPAGE_H

#include <QWidget>

#include "FinishedViewStep.h"

namespace Ui
{
class FinishedPage;
}

class FinishedPage : public QWidget
{
    Q_OBJECT
public:
    explicit FinishedPage( QWidget* parent = nullptr );

    void setRestart( FinishedViewStep::RestartMode mode );
    void setRestartNowCommand( const QString& command );

    void setUpRestart();

public slots:
    void onInstallationFailed( const QString& message, const QString& details );

protected:
    void focusInEvent( QFocusEvent* e ) override;  //choose the child widget to focus

private:
    Ui::FinishedPage* ui;

    FinishedViewStep::RestartMode m_mode;
    QString m_restartNowCommand;
};

#endif  // FINISHEDPAGE_H
