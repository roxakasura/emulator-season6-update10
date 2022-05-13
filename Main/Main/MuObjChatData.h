#pragma once
#include "macro.h"
#include "stdafx.h"
#define MAX_CHAT_MESSAGE 200

SERIALIZED_OBJECT_ON
struct MuObjectChatData {
    char * message() {
        if ( is_external_message() ) {
            return long_message_;
        }
        else {
            return short_message_;
        }
    }

    void set_message ( const char * msg ) {
        if ( is_external_message() ) {
            long_message_ = ( char * ) msg;
        }
        else {
            int len = strlen ( msg );
            len = ( len < 16 ) ? len : 15;
            memcpy_s ( short_message_, sizeof ( short_message_ ), msg, len );
            short_message_[len] = '\0';
        }
    }

    unsigned long message_len() { return message_len_; }

    bool is_external_message() { return external_message_ > 0xF; }

  public:
    char unknow1_[4];
    char account_[11];
    char unknow2_[5];
    unsigned long account_len_;
    char unknow3_[8];
    union {
        char short_message_[16];
        char * long_message_;
    };
    unsigned long message_len_;
    unsigned long external_message_;  // >= 0x10
    unsigned long chat_type_;  // [1..9]
    char unknow4_[36];
};
SERIALIZED_OBJECT_OFF