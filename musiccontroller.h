/*
 *  libwatchfish - library with common functionality for SailfishOS smartwatch connector programs.
 *  Copyright (C) 2015 Javier S. Pedro <dev.git@javispedro.com>
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef WATCHFISH_MUSICCONTROLLER_H
#define WATCHFISH_MUSICCONTROLLER_H

#include <QtCore/QObject>

namespace watchfish
{

class MusicControllerPrivate;

class MusicController : public QObject
{
	Q_OBJECT
	Q_DECLARE_PRIVATE(MusicController)

public:
	explicit MusicController(QObject *parent = 0);
	~MusicController();

private:
	MusicControllerPrivate * const d_ptr;
};

}

#endif // WATCHFISH_MUSICCONTROLLER_H
