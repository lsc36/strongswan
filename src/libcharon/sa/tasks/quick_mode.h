/*
 * Copyright (C) 2011 Martin Willi
 * Copyright (C) 2011 revosec AG
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.  See <http://www.fsf.org/copyleft/gpl.txt>.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * for more details.
 */

/**
 * @defgroup quick_mode quick_mode
 * @{ @ingroup tasks
 */

#ifndef QUICK_MODE_H_
#define QUICK_MODE_H_

typedef struct quick_mode_t quick_mode_t;

#include <library.h>
#include <sa/ike_sa.h>
#include <sa/tasks/task.h>

/**
 * IKEv1 quick mode, establishes a CHILD_SA in IKEv1.
 */
struct quick_mode_t {

	/**
	 * Implements the task_t interface
	 */
	task_t task;
};

/**
 * Create a new quick_mode task.
 *
 * @param ike_sa		IKE_SA this task works for
 * @param config		child_cfg if task initiator, NULL if responder
 * @param tsi			source of triggering packet, or NULL
 * @param tsr			destination of triggering packet, or NULL
 * @return				task to handle by the task_manager
 */
quick_mode_t *quick_mode_create(ike_sa_t *ike_sa, child_cfg_t *config,
							traffic_selector_t *tsi, traffic_selector_t *tsr);

#endif /** QUICK_MODE_H_ @}*/
