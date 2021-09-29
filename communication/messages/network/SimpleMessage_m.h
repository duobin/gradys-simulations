//
// Generated file, do not edit! Created by nedtool 5.6 from communication/messages/network/SimpleMessage.msg.
//

#ifndef __INET_SIMPLEMESSAGE_M_H
#define __INET_SIMPLEMESSAGE_M_H

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0506
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif


namespace inet {

class SimpleMessage;
} // namespace inet

#include "inet/common/packet/chunk/Chunk_m.h" // import inet.common.packet.chunk.Chunk


namespace inet {

/**
 * Enum generated from <tt>communication/messages/network/SimpleMessage.msg:22</tt> by nedtool.
 * <pre>
 * enum SenderType
 * {
 *     DRONE = 0;
 *     SENSOR = 1;
 *     GROUND_STATION = 2;
 * }
 * </pre>
 */
enum SenderType {
    DRONE = 0,
    SENSOR = 1,
    GROUND_STATION = 2
};

/**
 * Class generated from <tt>communication/messages/network/SimpleMessage.msg:29</tt> by nedtool.
 * <pre>
 * class SimpleMessage extends FieldsChunk
 * {
 *     chunkLength = B(7); // Fixed chunk le
 *     SenderType senderType;
 *     int content;
 * }
 * </pre>
 */
class SimpleMessage : public ::inet::FieldsChunk
{
  protected:
    inet::SenderType senderType = static_cast<inet::SenderType>(-1);
    int content = 0;

  private:
    void copy(const SimpleMessage& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const SimpleMessage&);

  public:
    SimpleMessage();
    SimpleMessage(const SimpleMessage& other);
    virtual ~SimpleMessage();
    SimpleMessage& operator=(const SimpleMessage& other);
    virtual SimpleMessage *dup() const override {return new SimpleMessage(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual inet::SenderType getSenderType() const;
    virtual void setSenderType(inet::SenderType senderType);
    virtual int getContent() const;
    virtual void setContent(int content);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const SimpleMessage& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, SimpleMessage& obj) {obj.parsimUnpack(b);}

} // namespace inet

#endif // ifndef __INET_SIMPLEMESSAGE_M_H
