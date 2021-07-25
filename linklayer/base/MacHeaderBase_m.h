//
// Generated file, do not edit! Created by nedtool 5.6 from inet/linklayer/base/MacHeaderBase.msg.
//

#ifndef __INET_MACHEADERBASE_M_H
#define __INET_MACHEADERBASE_M_H

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0506
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif

// dll export symbol
#ifndef INET_API
#  if defined(INET_EXPORT)
#    define INET_API  OPP_DLLEXPORT
#  elif defined(INET_IMPORT)
#    define INET_API  OPP_DLLIMPORT
#  else
#    define INET_API
#  endif
#endif


namespace inet {

class MacHeaderBase;
} // namespace inet

#include "inet/common/INETDefs_m.h" // import inet.common.INETDefs

#include "inet/common/packet/chunk/Chunk_m.h" // import inet.common.packet.chunk.Chunk

#include "inet/linklayer/common/MacAddress_m.h" // import inet.linklayer.common.MacAddress


namespace inet {

/**
 * Class generated from <tt>inet/linklayer/base/MacHeaderBase.msg:25</tt> by nedtool.
 * <pre>
 * class MacHeaderBase extends FieldsChunk
 * {
 *     MacAddress srcAddr;
 *     MacAddress destAddr;
 *     int networkProtocol = -1;
 * }
 * </pre>
 */
class INET_API MacHeaderBase : public ::inet::FieldsChunk
{
  protected:
    MacAddress srcAddr;
    MacAddress destAddr;
    int networkProtocol = -1;

  private:
    void copy(const MacHeaderBase& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const MacHeaderBase&);

  public:
    MacHeaderBase();
    MacHeaderBase(const MacHeaderBase& other);
    virtual ~MacHeaderBase();
    MacHeaderBase& operator=(const MacHeaderBase& other);
    virtual MacHeaderBase *dup() const override {return new MacHeaderBase(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual const MacAddress& getSrcAddr() const;
    virtual MacAddress& getSrcAddrForUpdate() { handleChange();return const_cast<MacAddress&>(const_cast<MacHeaderBase*>(this)->getSrcAddr());}
    virtual void setSrcAddr(const MacAddress& srcAddr);
    virtual const MacAddress& getDestAddr() const;
    virtual MacAddress& getDestAddrForUpdate() { handleChange();return const_cast<MacAddress&>(const_cast<MacHeaderBase*>(this)->getDestAddr());}
    virtual void setDestAddr(const MacAddress& destAddr);
    virtual int getNetworkProtocol() const;
    virtual void setNetworkProtocol(int networkProtocol);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const MacHeaderBase& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, MacHeaderBase& obj) {obj.parsimUnpack(b);}

} // namespace inet

#endif // ifndef __INET_MACHEADERBASE_M_H

