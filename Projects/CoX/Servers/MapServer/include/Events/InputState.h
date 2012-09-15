/*
 * Super Entity Game Server Project
 * http://segs.sf.net/
 * Copyright (c) 2006 Super Entity Game Server Team (see Authors.txt)
 * This software is licensed! (See License.txt for details)
 *
 * $Id$
 */
#pragma once
// if this file is included stand-alone this will pull in common definitions
#include "MapEvents.h"
#include "CommonNetStructures.h"
class InputState : public MapLinkEvent
{
    uint8_t m_csc_deltabits;
    bool m_send_deltas;
    uint16_t controlBits;
    uint16_t someOtherbits;
    void *current_state_P;
    Vector3 camera_pyr;
    int m_t1,m_t2;
    int m_A_ang11_propably,m_B_ang11_propably;

public:
    InputState() : MapLinkEvent(MapEventTypes::evInputState)
    {}
    void serializeto(BitStream &) const;
    void partial_2(BitStream &bs);
    void extended_input(BitStream &bs);
    void serializefrom(BitStream &bs);
    void recv_client_opts(BitStream &bs);
    Vector3 &pyr() {return camera_pyr;}
};
