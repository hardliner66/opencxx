#ifndef guard_opencxx_GenericMsg_h
#define guard_opencxx_GenericMsg_h

#include <opencxx/parser/Msg.h>
#include <opencxx/parser/SourceLocation.h>

#include <string>
#include <ostream>

//@beginlicenses@
//@license{contributors}{}@
//
//  Permission to use, copy, distribute and modify this software and its  
//  documentation for any purpose is hereby granted without fee, provided that
//  the above copyright notice appears in all copies and that both that copyright
//  notice and this permission notice appear in supporting documentation.
// 
//  Other Contributors (see file AUTHORS) make(s) no representations about the suitability of this
//  software for any purpose. It is provided "as is" without express or implied
//  warranty.
//  
//  Copyright (C)  Other Contributors (see file AUTHORS)
//
//@endlicenses@

namespace Opencxx
{

class GenericMsg : public Msg
{
public:
    GenericMsg(
        Severity severity
      , const SourceLocation& location
      , const std::string& msg
    )
      : severity_(severity)
      , location_(location)
      , msg_(msg)
    {
    }

    virtual ~GenericMsg() {}

    Severity GetSeverity() const 
    { 
        return severity_; 
    }
    
    void PrintOn(std::ostream& os) const
    {
        if (location_)
        {
            os << location_.GetFilename() << ":" << location_.GetLineNo()
               << ": " << msg_ << std::endl;
        }
        else
        {
            os << "occ: " << msg_ << std::endl;
        }
    }
    
private:
    Severity       severity_;
    SourceLocation location_;
    std::string    msg_;
};

}

#endif /* ! guard_opencxx_GenericMsg_h */
