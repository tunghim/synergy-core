/*
 * synergy -- mouse and keyboard sharing utility
 * Copyright (C) 2002 Chris Schoeneman
 * 
 * This package is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * found in the file COPYING that should have accompanied this file.
 * 
 * This package is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef XTHREAD_H
#define XTHREAD_H

//! Generic thread exception
class XThread { };

//! Thread exception to exit
/*!
Thrown by CThread::exit() to exit a thread.  Clients of CThread
must not throw this type but must rethrow it if caught (by
XThreadExit, XThread, or ...).
*/
class XThreadExit : public XThread {
public:
	//! \c result is the result of the thread
	XThreadExit(void* result) : m_result(result) { }
	~XThreadExit() { }

public:
	void*				m_result;
};

//! Thread exception to cancel
/*!
Thrown to cancel a thread.  Clients must not throw this type, but
must rethrow it if caught (by XThreadCancel, XThread, or ...).
*/
class XThreadCancel : public XThread { };

//! Thread creation exception
/*!
Thrown when a thread cannot be created.
*/
class XThreadUnavailable { };

/*!
\def RETHROW_XTHREAD
Convenience macro to rethrow an XThread exception but ignore other
exceptions.  Put this in your catch (...) handler after necessary
cleanup but before leaving or returning from the handler.
*/
#define RETHROW_XTHREAD \
	try { throw; } catch (XThread&) { throw; } catch (...) { }

#endif
