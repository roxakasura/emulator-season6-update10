#include "stdafx.h"
#include "Defines.h"
#include "Import.h"
#include "Object.h"
#include "PostItem.h"
#include "Interface.h"
#include "Protocol.h"
#include "Util.h"
#include "User.h"
#include <string>
#include "Protect.h"
#include "BankUpgrade.h"
#include "InfoLog.h"
#include "NewInfo.h"
//#include "TMemory.h"
// -----------------------------------------------------------------------------

PostItem gPostItem;
//#define pCurrentViewingItemName (*(DWORD *) (0x007E4528 + 2))
//#define CharacterHeadChatTextFirst(x) ((char *) ((x) + 0x194))
//#define CharacterHeadChatTextLast(x) ((char *) ((x) + 0x194 - 0x100))
// -----------------------------------------------------------------------------

PostItem::PostItem () 
{
    list_counter_ = 0;
    last_tickcount_post_ = 0;
    current_item_post_ = &gInterface.item_post_;
    last_tickcount_view_ = &gInterface.last_tickcount_view_;
    draw_character_head_chat_text_ = false;
    PostItemColor =  GetPrivateProfileInt ( "Oth123er", "PostC412olor", 9, ".\\Settin3gs.in1i" );
    if ( PostItemColor < 1 || PostItemColor > 9 ){PostItemColor = 9;}

    Hook();

	last_tickcount_moveitem_ = 0;
}
// -----------------------------------------------------------------------------

PostItem::~PostItem() {
}
// -----------------------------------------------------------------------------

void PostItem::Hook() 
{
	/* usada para o PostItem e também para o Right click - verificar as obs dentro da função */
	SetCompleteHook(0xE9,0x007DCFD0,&PostItemToWorldChatChannel);//1.04D-> 0x007DCE80
	/* usada para o PostItem 100% */
	SetCompleteHook(0xE9,0x007897C7,&BuildChatDataLong);//1.04D-> 0x00789677
	SetCompleteHook(0xE9,0x0078AAA6,&ViewPostItem);//1.04D->0x0078A956
	SetJmp(0x00599183,6,ProcessCharacterHeadChatText);
	/* usada para o right click 100% - influencia no equipar no personagem */
	SetCompleteHook(0xE9, 0x0083B7E4 + 0x150, &Equipments);//1.04D->0x0083B7E4
}

void __declspec ( naked ) PostItem::PostItemToWorldChatChannel() 
{
    static DWORD register_ecx = 0;
    static DWORD register_edx = 0;
    static DWORD mem = 0;

    _asm 
	{
        MOV register_ecx, ECX;
        MOV register_edx, EDX;
        MOV ECX, DWORD PTR SS : [EBP - 0x10];
        MOV EDX, DWORD PTR DS : [ECX + 0x54];
        MOV mem, EDX;
    }

    PostItemToWorldChatChannelImp ( ( void * ) mem );

    _asm 
	{
        MOV ECX, register_ecx;
        MOV EDX, register_edx;
		MOV mem, 0x007DD09D; //1.04D-> 0x007DCF4D;
        JMP mem;
    }
}

// -----------------------------------------------------------------------------
void PostItem::PostItemToWorldChatChannelImp ( void * item_data )
{
    // check window, not allow for shop, inventory, warehouse, etc
    if ( gInterface.CheckWindow ( Trade ) ||
            gInterface.CheckWindow ( Warehouse ) ||
            gInterface.CheckWindow ( Shop ) ||
            gInterface.CheckWindow ( Store ) ||
            gInterface.CheckWindow ( OtherStore ) ||
            gInterface.CheckWindow ( CashShop ) ||
            gInterface.CheckWindow ( ExpandWarehouse ) ) 
	{
        return;
    }

	if ( GetKeyState ( VK_RBUTTON ) & 0x8000 && GetKeyState ( VK_SHIFT ) & 0x8000)
	{
		if ( GetTickCount() <= gPostItem.last_tickcount_post_ + 3000 ) 
		{
			return; 
		}

		if (!gInterface.Data[eJEWELBANK_MAIN].OnShow)
		{
			return;
		}

		ObjectItem * lItem = (ObjectItem*)item_data;

		if (lItem->ItemID < 0) { return; }

		PMSG_JEWEL_BANK pMsg;
		pMsg.h.set(0xF3, 0xDF, sizeof(pMsg));

		int JCWinWidth;

		JCWinWidth = pWinWidth / pWinHeightReal;

		pMsg.Target = -1;

		if (gInterface.CheckWindow(ChaosBox) && gInterface.CheckWindow(Inventory)) 
		{
			if ((pCursorX > 460))
			{
				pMsg.sFlag = 0;
				pMsg.tFlag = 3;
				pMsg.Target = 0;
				pMsg.Source = lItem->PosX + lItem->PosY * 8 + 12;
			}
			else if (gInterface.CheckWindow(ExpandInventory) && pCursorX > 260)
			{
				pMsg.sFlag = 0;
				pMsg.tFlag = 3;
				pMsg.Target = 0;
				pMsg.Source = lItem->PosX + lItem->PosY * 8 + 12 + 64;
				if (pCursorY > 130)
					pMsg.Source += 32;
			}
			else 
			{
				pMsg.sFlag = 3;
				pMsg.tFlag = 0;
				pMsg.Target = 0;
				pMsg.Source = lItem->PosX + lItem->PosY * 8;
			}
		}
		else 
		{
			float v1 = 0;
			if (gInterface.CheckWindow(Character))
				v1 = *(float*)(0x00D24E88);
			if ((pCursorX > 460 - v1))
			{
				pMsg.sFlag = 0;
				pMsg.tFlag = 0;
				pMsg.Source = lItem->PosX + lItem->PosY * 8 + 12;

			}
			else if (gInterface.CheckWindow(ExpandInventory) && pCursorX > 260 - v1)
			{
				pMsg.sFlag = 0;
				pMsg.tFlag = 0;
				pMsg.Source = lItem->PosX + lItem->PosY * 8 + 12 + 64;
				if (pCursorY > 130)
					pMsg.Source += 32;
			}
			pMsg.Target = 0;
		}

		DataSend((LPBYTE)&pMsg, pMsg.h.size);
	}
	else if ( GetKeyState ( VK_RBUTTON ) & 0x8000 && GetKeyState ( VK_CONTROL ) & 0x8000 ) 
	{
		if ( GetTickCount() <= gPostItem.last_tickcount_post_ + 3000 ) { return; }

		PMSG_POSTITEM iMsg = { '\0' };
		strcpy_s ( iMsg.chatmsg, ( char* ) pCurrentViewingItemName );
		memcpy_s ( &iMsg.chatid[0], 10, ( char* ) oUserObjectStruct_, 10 );
		memcpy_s ( &iMsg.item_data[0], 107, item_data, 107 );
		iMsg.h.set (0x78, sizeof ( iMsg ) );
		DataSend ( ( LPBYTE ) &iMsg, iMsg.h.size );
		gPostItem.last_tickcount_post_ = GetTickCount();
	}
	else if (GetKeyState(VK_RBUTTON) & 0x8000 && GetTickCount() >= gPostItem.last_tickcount_moveitem_ + 300)
	{
		ObjectItem * lItem = (ObjectItem*)item_data;

		if (lItem->ItemID < 0) 
		{ 
			return; 
		}

		PMSG_ITEM_MOVE_RECV pMsg = { 0 };

		pMsg.h.set(0x79, 0x01, sizeof(pMsg));
		pMsg.Target = -1;

		if (gInterface.CheckWindow(ChaosBox) && gInterface.CheckWindow(Inventory)) 
		{
			if ((pCursorX > 460))
			{
				pMsg.sFlag = 0;
				pMsg.tFlag = 3;
				pMsg.Target = 0;
				pMsg.Source = lItem->PosX + lItem->PosY * 8 + 12;
			}
			else if (gInterface.CheckWindow(ExpandInventory) && pCursorX > 260)
			{
				pMsg.sFlag = 0;
				pMsg.tFlag = 3;
				pMsg.Target = 0;
				pMsg.Source = lItem->PosX + lItem->PosY * 8 + 12 + 64;
				if (pCursorY > 130)
					pMsg.Source += 32;
			}
			else 
			{
				pMsg.sFlag = 3;
				pMsg.tFlag = 0;
				pMsg.Target = 0;
				pMsg.Source = lItem->PosX + lItem->PosY * 8;
			}
		}
		else 
		{
			float v1 = 0;
			if (gInterface.CheckWindow(Character))
				v1 = *(float*)(0x00D24E88);
			if ((pCursorX > 460 - v1))
			{
				pMsg.sFlag = 0;
				pMsg.tFlag = 0;
				pMsg.Source = lItem->PosX + lItem->PosY * 8 + 12;

			}
			else if (gInterface.CheckWindow(ExpandInventory) && pCursorX > 260 - v1)
			{
				pMsg.sFlag = 0;
				pMsg.tFlag = 0;
				pMsg.Source = lItem->PosX + lItem->PosY * 8 + 12 + 64;
				if (pCursorY > 130)
					pMsg.Source += 32;
			}
			pMsg.Target = 0;
		}

		DataSend((BYTE*)&pMsg, pMsg.h.size);
		gPostItem.last_tickcount_moveitem_ = GetTickCount();
	}
}
// -----------------------------------------------------------------------------

void * PostItem::AddItem ( void * item_data ) 
{
    LinkNode<ItemPost> * item = new ItemPost ( item_data );
    gPostItem.list_.Append ( item );

    if ( gPostItem.list_counter_ >= MAX_CHAT_MESSAGE ) 
	{
        LinkNode<ItemPost> * node = gPostItem.list_.head();
        node->Free();
    }
    else 
	{
        gPostItem.list_counter_++;
    }

    return item;
}
// -----------------------------------------------------------------------------

void __declspec ( naked ) PostItem::BuildChatDataLong()
{
    static void * chat_data_pointer = nullptr;
    static DWORD mem = 0;

    _asm 
	{
        MOV chat_data_pointer, ECX;
		MOV mem, 0x0078BFE0; //1.04D-> 0x0078BE90;
        CALL mem;
    }

    BuildChatData ( chat_data_pointer );
   
	_asm
	{
		MOV mem, 0x007897CC; //1.04D-> 0x0078967C;
        JMP mem;
    }
}
// -----------------------------------------------------------------------------

void __declspec ( naked ) PostItem::BuildChatDataShort() 
{
    static void * chat_data_pointer = nullptr;
    static DWORD mem = 0;
   
	_asm 
	{
        MOV chat_data_pointer, ECX;
		MOV mem, 0x0078BFE0; //1.04D-> 0x0078BE90;
        CALL mem;
    }

    BuildChatData ( chat_data_pointer );

    _asm 
	{
		MOV mem, 0x00789E17; //1.04D-> 0x00789CC7;
        JMP mem;
    }
}
// -----------------------------------------------------------------------------

void PostItem::BuildChatData ( void * chat_data_pointer ) 
{
    MuObjectChatData * chat = ( MuObjectChatData * ) chat_data_pointer;

    if ( !chat->is_external_message() || !gPostItem.list_counter_ ) 
	{
        return;
    }

    char * message = chat->message();
    unsigned long message_len = chat->message_len();

    // _APIxxXXXXxxAPI
    if ( message[message_len - 1 - 8 - 2] != '_' ||
            message[message_len - 1 - 8 - 1] != '[' ||
            message[message_len - 1] != ']' ) 
	{
        return;
    }

    LinkNode<ItemPost> * item_node = nullptr;
    sscanf_s ( &message[message_len - 1 - 8], "%08X", ( DWORD * ) &item_node );
    ItemPost * item_post = item_node->value();
    item_post->chat_ = chat;
    message[message_len - 1 - 8 - 2] = '\0';
    message[message_len - 1 - 8 + 0] = '_';
    message[message_len - 1 - 8 + 1] = '_';
    message[message_len - 1 - 8 + 6] = '_';
    message[message_len - 1 - 8 + 7] = '_';
    * ( unsigned long * ) &message[message_len - 1 - 8 + 2] = ( unsigned long ) item_node;
}
// -----------------------------------------------------------------------------

void __declspec ( naked ) PostItem::ProcessCharacterHeadChatText()
{
    static DWORD mem = 0;
    static DWORD base_address;
    static DWORD chat_text;
    
	_asm 
	{
        MOV mem, EAX;
        MOV EAX, DWORD PTR SS : [EBP + 0x08];
        MOV base_address, EAX;
        MOV EAX, DWORD PTR SS : [EBP + 0x0C];
        MOV chat_text, EAX;
        MOV EAX, mem;
    }

    PostItem::ProcessCharacterHeadChatTextImp ( ( char * ) base_address, ( char * ) chat_text );
   
	_asm 
	{
        PUSH -1;
		PUSH 0x00CD3143; //1.04D-> 0x00CD2FC3;
        MOV mem, 0x0059918A;
        JMP mem;
    }
}
// -----------------------------------------------------------------------------

void PostItem::ProcessCharacterHeadChatTextImp ( char * base_address, char * chat_text ) 
{
    if ( gPostItem.draw_character_head_chat_text_ )
	{
        // xử lý đoạn chat trên đầu nhân vật
        unsigned long len = strlen ( chat_text );

        if ( chat_text[len - 1 - 8 - 2] != '_' ||
                chat_text[len - 1 - 8 - 1] != '[' ||
                chat_text[len - 1] != ']' ) {
            // do nothing
        }
        else 
		{
            gPostItem.draw_character_head_chat_text_base_address_ = base_address;
        }

        gPostItem.draw_character_head_chat_text_ = false;
    }
}
// -----------------------------------------------------------------------------

void __declspec ( naked ) PostItem::ViewPostItem() 
{
    static void * chat_data_pointer = nullptr;
    static DWORD mem = 0;
    
	_asm 
	{
		MOV mem, 0x0078C020; //1.04D-> 0x0078BED0;
        CALL mem;
        MOV chat_data_pointer, EAX;
    }

    ViewPostItemImp ( chat_data_pointer );

    _asm 
	{
        MOV EAX, chat_data_pointer;
		MOV mem, 0x0078AAAB; //1.04D-> 0x0078A95B;
        JMP mem;
    }
}
// -----------------------------------------------------------------------------

void PostItem::ViewPostItemImp ( void * chat_data_pointer ) 
{
    MuObjectChatData * chat = ( MuObjectChatData * ) chat_data_pointer;

    if ( !chat->is_external_message() || !gPostItem.list_counter_ ) 
	{
        *gPostItem.current_item_post_ = nullptr;
        return;
    }

    char * message = chat->message();
    unsigned long message_len = chat->message_len();
    unsigned long real_len = strlen ( message );

    if ( message_len == real_len ) 
	{
        *gPostItem.current_item_post_ = nullptr;
        return;
    }

    // _API__XXXX__API
    if ( message[message_len - 1 - 8 - 2] != '\0' ||
            message[message_len - 1 - 8 - 1] != '[' ||
            message[message_len - 1] != ']' ) 
	{
        *gPostItem.current_item_post_ = nullptr;
        return;
    }

    LinkNode<ItemPost> * item_node = ( LinkNode<ItemPost> * ) * ( unsigned long * ) &message[message_len - 1 - 8 + 2];
    ItemPost * item_post = item_node->value();
    ObjectItem * item_data = ( ObjectItem * ) &item_post->item_;
    // set show item tool tip
    *gPostItem.last_tickcount_view_ = GetTickCount();
    *gPostItem.current_item_post_ = item_data;

	gObjUser.PostItemID = item_data->ItemID;
	gObjUser.PostItemLV = item_data->Level;
	gObjUser.PostItemExc = item_data->ExcellentOption;
	gObjUser.PostItemX = item_data->PosX;
	gObjUser.PostItemY = item_data->PosY;


}

// -----------------------------------------------------------------------------
//Right Click
void __declspec (naked) PostItem::Equipments() 
{
	static DWORD mem = 0;

	_asm
	{
		mov eax, dword ptr ds : [ebp - 04]
		mov mem, eax
	}

	RemoveEquipment((void *)mem);

	_asm 
	{
		mov esp, ebp
		pop ebp
		ret 0004
	}
}

void PostItem::RemoveEquipment(void * item_data) 
{
	/* checagem de janelas */
	if (gInterface.CheckWindow(Trade) ||
		gInterface.CheckWindow(Warehouse) ||
		gInterface.CheckWindow(Shop) ||
		gInterface.CheckWindow(Store) ||
		gInterface.CheckWindow(OtherStore) ||
		gInterface.CheckWindow(CashShop) ||
		gInterface.CheckWindow(ExpandWarehouse)) 
	{
		return;
	}

	/*  nessa verificação, ela não deixa remover o item ao passar o mouse por cima do mesmo   */
	if (GetKeyState(VK_RBUTTON) & 0x8000 && GetTickCount() >= gPostItem.last_tickcount_moveitem_ + 250)
	{
		ObjectItem * lItem = (ObjectItem*)item_data;

		if (lItem->ItemID < 0) { return; }

		PMSG_ITEM_MOVE_RECV pMsg = { 0 };

		pMsg.h.set(0x79, 0x01, sizeof(pMsg));

		pMsg.sFlag = 0;
		pMsg.tFlag = 0;
		pMsg.Source = lItem->PosX;
		pMsg.Target = 0;

		DataSend((BYTE*)&pMsg, pMsg.h.size);

		gPostItem.last_tickcount_moveitem_ = GetTickCount();
	}
}