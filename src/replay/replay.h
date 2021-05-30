/*
 * This software is licensed under the terms of the MIT License.
 * See COPYING for further information.
 * ---
 * Copyright (c) 2011-2019, Lukas Weber <laochailan@web.de>.
 * Copyright (c) 2012-2019, Andrei Alexeyev <akari@taisei-project.org>.
*/

#ifndef IGUARD_replay_replay_h
#define IGUARD_replay_replay_h

#include "taisei.h"

#include <SDL.h>

#define REPLAY_EXTENSION "tsr"

#define REPLAY_WRITE_DESYNC_CHECKS

#ifdef DEBUG
// #define REPLAY_LOAD_DEBUG
#endif

typedef struct Replay Replay;
typedef struct ReplayStage ReplayStage;

typedef enum ReplayReadMode {
	// bitflags
	REPLAY_READ_META = (1 << 0),
	REPLAY_READ_EVENTS = (1 << 1),

	REPLAY_READ_ALL = REPLAY_READ_META | REPLAY_READ_EVENTS,
} ReplayReadMode;

void replay_init(Replay *rpy);
void replay_destroy(Replay *rpy);
void replay_destroy_events(Replay *rpy);

bool replay_write(Replay *rpy, SDL_RWops *file, uint16_t version);
bool replay_read(Replay *rpy, SDL_RWops *file, ReplayReadMode mode, const char *source);

bool replay_save(Replay *rpy, const char *name);
bool replay_load(Replay *rpy, const char *name, ReplayReadMode mode);
bool replay_load_syspath(Replay *rpy, const char *path, ReplayReadMode mode);

void replay_copy(Replay *dst, Replay *src, bool steal_events);

int replay_find_stage_idx(Replay *rpy, uint8_t stageid);

#endif // IGUARD_replay_replay_h
