/*
 *  libwatchfish - library with common functionality for SailfishOS smartwatch connector programs.
 *  Copyright (C) 2016 Javier S. Pedro <dev.git@javispedro.com>
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

#ifndef WATCHFISH_CALENDARSOURCE_P_H
#define WATCHFISH_CALENDARSOURCE_P_H

#ifdef MER_EDITION_SAILFISH // it seems cmake automoc is trying to compile anyway

#include <extendedstorage.h>
#include "calendarsource.h"

namespace watchfish
{

class CalendarSourcePrivate : public QObject, public mKCal::ExtendedStorageObserver
{
	Q_OBJECT

public:
	explicit CalendarSourcePrivate(CalendarSource *q);
	~CalendarSourcePrivate();

	mKCal::ExtendedCalendar::Ptr calendar;
	mKCal::ExtendedStorage::Ptr calendarStorage;

    virtual void storageModified(mKCal::ExtendedStorage *storage, const QString &info);
    virtual void storageProgress(mKCal::ExtendedStorage *storage, const QString &info);
    virtual void storageFinished(mKCal::ExtendedStorage *storage, bool error, const QString &info);

    static CalendarEvent convertToEvent(
        #ifdef KF5CALENDARCORE
            const KCalendarCore::Incidence::Ptr &incidence
        #else
            const KCalCore::Incidence::Ptr &incidence
        #endif
        , const QDateTime &startDate, const QDateTime &endDate);

private:
	CalendarSource * const q_ptr;
	Q_DECLARE_PUBLIC(CalendarSource)
};

}

#endif // MER_EDITION_SAILFISH

#endif // WATCHFISH_CALENDARSOURCE_P_H
