/*
 * Copyright (C) 2008-2020 TrinityCore <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef __BATTLEGROUNDTTP_H
#define __BATTLEGROUNDTTP_H

#include "Battleground.h"

enum BattlegroundTTPObjectTypes
{
    BG_TTP_OBJECT_DOOR_1         = 0,
    BG_TTP_OBJECT_DOOR_2         = 1,
    BG_TTP_OBJECT_BUFF_1         = 2,
    BG_TTP_OBJECT_BUFF_2         = 3,
    BG_TTP_OBJECT_PORT_1         = 4,
    BG_TTP_OBJECT_PORT_2         = 5,
    BG_TTP_OBJECT_MAX            = 6
};

enum BattlegroundTTPObjects
{
    BG_TTP_OBJECT_TYPE_BUFF_1     = 184664,
    BG_TTP_OBJECT_TYPE_BUFF_2     = 184663,
    BG_TTP_OBJECT_TYPE_DOOR_1     = 210866,     //HACK. ToDo: finde correct entry and positions
    BG_TTP_OBJECT_TYPE_DOOR_2     = 210866,     //HACK.
    BG_TTP_OBJECT_TYPE_PORTAL     = 181621
};

class BattlegroundTTPScore : public BattlegroundScore
{
    public:
        BattlegroundTTPScore() {};
        virtual ~BattlegroundTTPScore() {};
        //TODO fix me
};

class BattlegroundTTP : public Battleground
{
    public:
        BattlegroundTTP();
        ~BattlegroundTTP();

        /* inherited from BattlegroundClass */
        virtual void AddPlayer(Player* player) OVERRIDE;
        virtual void StartingEventCloseDoors() OVERRIDE;
        virtual void StartingEventOpenDoors() OVERRIDE;

        void RemovePlayer(Player* player, uint64 guid, uint32 team) OVERRIDE;
        void HandleAreaTrigger(Player* player, uint32 trigger) OVERRIDE;
        bool SetupBattleground() OVERRIDE;
        void Reset() OVERRIDE;
        void FillInitialWorldStates(WorldStateBuilder& builder) OVERRIDE;
        void HandleKillPlayer(Player* player, Player* killer) OVERRIDE;
        bool HandlePlayerUnderMap(Player* player) OVERRIDE;
};
#endif
