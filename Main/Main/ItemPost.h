#pragma once
// -----------------------------------------------------------------------------

#include "macro.h"
#include "LinkedList.h"
#include "MuObjChatData.h"
#include "MuObjItemData.h"
// -----------------------------------------------------------------------------

struct ItemPost : public LinkNode<ItemPost> {
  public:
    ItemPost ( void * item_data ) {
        memcpy_s ( &item_, sizeof ( item_ ), item_data, sizeof ( MuObjectItemData ) );
        chat_ = nullptr;
    }
    virtual ~ItemPost() {}

  public:
    MuObjectChatData * chat_;
    MuObjectItemData item_;

  private:
    DISALLOW_COPY_AND_ASSIGN ( ItemPost );
};