//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#ifndef __PROJETO_ZIGZAGPROTOCOL_H_
#define __PROJETO_ZIGZAGPROTOCOL_H_

#include <omnetpp.h>
#include "base/CommunicationProtocolBase.h"
#include "../messages/network/MobileNodeMessage_m.h"

using namespace omnetpp;

namespace projeto {

enum CommunicationStatus { FREE=0, REQUESTING=1, PAIRED=2, COLLECTING=3, PAIRED_FINISHED=4 };

class ZigzagProtocol : public CommunicationProtocolBase
{
    protected:
        simtime_t timeoutDuration;

        // Communication status variable
        CommunicationStatus communicationStatus = FREE;

        // Current target
        int tentativeTarget = -1;
        // Previous target
        int lastTarget = -1;
        // Name of the current target (for addressing purposes)
        std::string tentativeTargetName;

        // Current imaginary data being carried
        int currentDataLoad=0;
        // Stable data load to prevent data loss during pairing
        int stableDataLoad=currentDataLoad;

        // Last telemetry package recieved
        Telemetry currentTelemetry = Telemetry();
        Telemetry lastStableTelemetry = Telemetry();

        MobileNodeMessage lastPayload = MobileNodeMessage();

    protected:
        virtual void initialize(int stage) override;
        virtual void handleTelemetry(projeto::Telemetry *telemetry) override;
        virtual void handlePacket(Packet *pk) override;
        virtual bool isTimedout() override;
        virtual void resetParameters();
    private:
        virtual void sendReverseOrder();
        virtual void updatePayload();
        virtual void setTarget(const char *target);
    public:
        simsignal_t dataLoadSignalID;
};

} //namespace

#endif