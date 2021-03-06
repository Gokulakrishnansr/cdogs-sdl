/*
    C-Dogs SDL
    A port of the legendary (and fun) action/arcade cdogs.
    Copyright (c) 2014-2015, Cong Xu
    All rights reserved.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:

    Redistributions of source code must retain the above copyright notice, this
    list of conditions and the following disclaimer.
    Redistributions in binary form must reproduce the above copyright notice,
    this list of conditions and the following disclaimer in the documentation
    and/or other materials provided with the distribution.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
    AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
    ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
    LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
    CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
    SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
    INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
    CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
    ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
    POSSIBILITY OF SUCH DAMAGE.
*/
#pragma once

#include "character.h"

#define MAX_WEAPONS 3
typedef struct
{
	int Id;	// -1 if dead
	bool IsUsed;
	bool IsLocal;	// whether this is a local-machine player
	Character Char;
	char name[20];
	int weaponCount;
	const GunDescription *weapons[MAX_WEAPONS];
	int Lives;

	int score;
	int totalScore;
	int kills;
	int suicides;
	int friendlies;

	// Used for end-of-game score tallying
	int survived;
	int hp;
	int missions;
	int lastMission;
	int allTime, today;
	int RoundsWon;	// for dogfight

	input_device_e inputDevice;
	int deviceIndex;
	int playerIndex;
} PlayerData;

extern CArray gPlayerDatas;	// of PlayerData

#define MAX_LOCAL_PLAYERS 4


void PlayerDataInit(CArray *p);
PlayerData *PlayerDataAdd(CArray *p);
void PlayerDataSetLocalDefaults(PlayerData *d, const int idx);
void PlayerDataTerminate(CArray *p);

void PlayerDataStart(PlayerData *p, const int maxHealth, const int mission);

int GetNumPlayers(const bool alive, const bool human, const bool local);
bool AreAllPlayersDeadAndNoLives(void);
const PlayerData *GetFirstPlayer(
	const bool alive, const bool human, const bool local);
bool IsPlayerAlive(const PlayerData *player);
bool IsPlayerHuman(const PlayerData *player);
bool IsPlayerHumanAndAlive(const PlayerData *player);
Vec2i PlayersGetMidpoint(void);
void PlayersGetBoundingRectangle(Vec2i *min, Vec2i *max);
int PlayersNumUseAmmo(const int ammoId);

void PlayerScore(PlayerData *p, const int points);
void PlayerSetInputDevice(
	PlayerData *p, const input_device_e d, const int idx);
