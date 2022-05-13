#include "stdafx.h"
#include "LoadImages803.h"
#include "Interface.h"
#include "CMacroUIEx.h"

CNewUILoadImages gGFxLoadImages;

CNewUILoadImages::CNewUILoadImages()
{

}

CNewUILoadImages::~CNewUILoadImages()
{
}

void CNewUILoadImages::LoadImages()
{
	//chat
	    LoadBitmapA("Interface\\GFx\\ex700\\newui_scrollbar_buttom_up.tga", 51552, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\newui_scrollbar_buttom_down.tga", 51551, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\chat_bg03.tga", 51545, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\newui_scrollbar_up.tga", 31270, 9729, 10496, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\newui_scrollbar_m.tga", 31271, 9729, 10496, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\newui_scrollbar_down.tga", 31272, 9729, 10496, 1, 0);
	    LoadBitmapA("Interface\\GFx\\ex700\\newui_Scrollbar_stretch.tga", 31275, 9729, 10496, 1, 0);
    	LoadBitmapA("Interface\\GFx\\ex700\\Chat_Main01.tga", 51529, GL_LINEAR, GL_CLAMP, 1, 0);
	    LoadBitmapA("Interface\\GFx\\ex700\\Chat_Main02.tga", 51541, GL_LINEAR, GL_CLAMP, 1, 0);
	    for (int i = 51530; i < 51534; ++i){
		    LoadBitmapA("Interface\\GFx\\ex700\\Chat_Button.tga", i, GL_LINEAR, GL_CLAMP, 1, 0);
	    }
	    LoadBitmapA("Interface\\GFx\\ex700\\Chat_ButtonWBack.tga", 51538, GL_LINEAR, GL_CLAMP, 1, 0);
	    LoadBitmapA("Interface\\GFx\\ex700\\Chat_ButtonSize.tga", 51539, GL_LINEAR, GL_CLAMP, 1, 0);
        LoadBitmapA("Interface\\GFx\\ex700\\Chat_ButtonTransparencyA.tga", 51540, GL_LINEAR, GL_CLAMP, 1, 0);
	    LoadBitmapA("Interface\\GFx\\ex700\\Chat_ButtonHide01.tga", 51542, GL_LINEAR, GL_CLAMP, 1, 0);
	    LoadBitmapA("Interface\\GFx\\ex700\\Chat_ButtonHide02.tga", 51543, GL_LINEAR, GL_CLAMP, 1, 0);
	    LoadBitmapA("Interface\\GFx\\ex700\\Chat_ButtonHide03.tga", 51544, GL_LINEAR, GL_CLAMP, 1, 0);
	    //LoadBitmapA("Interface\\GFx\\Chat\\newui_scroll01.tga", 51700, 9729, 10496, 1, 0);

/*	if(gProtect.m_MainInfo.CustomItemToolTip == 1){
	    LoadBitmapA("Interface\\GFx\\Tool\\tooltip_bg01.tga", 61511, 0x2601, 0x2901, 1, 0); //esquina arriba izquierda
        LoadBitmapA("Interface\\GFx\\Tool\\tooltip_bg02.tga", 61512, 0x2601, 0x2901, 1, 0);
        LoadBitmapA("Interface\\GFx\\Tool\\tooltip_bg03.tga", 61513, 0x2601, 0x2901, 1, 0); //esquina arriba derecha
        LoadBitmapA("Interface\\GFx\\Tool\\tooltip_bg04.tga", 61514, 0x2601, 0x2901, 1, 0);
        LoadBitmapA("Interface\\GFx\\Tool\\tooltip_bg06.tga", 61515, 0x2601, 0x2901, 1, 0);
        LoadBitmapA("Interface\\GFx\\Tool\\tooltip_bg07.tga", 61516, 0x2601, 0x2901, 1, 0); //esquina abajo izquierda
        LoadBitmapA("Interface\\GFx\\Tool\\tooltip_bg08.tga", 61517, 0x2601, 0x2901, 1, 0);
        LoadBitmapA("Interface\\GFx\\Tool\\tooltip_bg09.tga", 61518, 0x2601, 0x2901, 1, 0); //esquina abajo derecha
	}*/
	//LoadBitmapA("Interface\\GFx\\winPet_I1.tga", 61545, GL_LINEAR, GL_CLAMP, 1, 0);

	//Interface Ex700
	LoadBitmapA("Interface\\GFx\\none.tga", 31292, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Interface\\GFx\\none.tga", 0x7A48, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Interface\\GFx\\Main_IE.tga", 31293, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Interface\\GFx\\Main_IE_Exp.tga", 59000, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Interface\\GFx\\none.tga", 31294, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Interface\\GFx\\none.tga", 31295, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Interface\\GFx\\none.tga", 31313, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Interface\\GFx\\Main_I3.tga", 31298, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Interface\\GFx\\Main_I2.tga", 31297, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Interface\\GFx\\Main_I1.tga", 31296, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Interface\\GFx\\Main_I5.jpg", 31299, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Interface\\GFx\\Main_I4.jpg", 31300, GL_LINEAR, GL_CLAMP, 1, 0);
	//Interface Skill Ex700
	LoadBitmapA("Interface\\GFx\\newui_skill.tga", 31308, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Interface\\GFx\\newui_skill2.tga", 31309, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Interface\\GFx\\newui_skill3.tga", 31311, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Interface\\GFx\\newui_command.tga", 31310, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Interface\\GFx\\newui_non_skill.tga", 31314, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Interface\\GFx\\newui_non_skill2.tga", 31315, GL_LINEAR, GL_CLAMP, 1, 0); 
	LoadBitmapA("Interface\\GFx\\newui_non_skill3.tga", 31317, GL_LINEAR, GL_CLAMP, 1, 0); 
	LoadBitmapA("Interface\\GFx\\newui_non_command.tga", 31316, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Interface\\GFx\\new_Master_Icon.tga", 31534, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Interface\\GFx\\new_Master_non_Icon.tga", 31535, GL_LINEAR, GL_CLAMP, 1, 0);
	//Interface Botones Ex700
	LoadBitmapA("Interface\\GFx\\Botones\\Shop1.tga",      0x901, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Interface\\GFx\\Botones\\Shop2.tga",      0x902, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Interface\\GFx\\Botones\\Character1.tga", 0x903, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Interface\\GFx\\Botones\\Character2.tga", 0x904, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Interface\\GFx\\Botones\\Inventory1.tga", 0x905, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Interface\\GFx\\Botones\\Inventory2.tga", 0x906, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Interface\\GFx\\Botones\\Quest1.tga",     0x907, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Interface\\GFx\\Botones\\Quest2.tga",     0x908, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Interface\\GFx\\Botones\\Community1.tga", 0x909, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Interface\\GFx\\Botones\\Community2.tga", 0x910, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Interface\\GFx\\Botones\\System1.tga",    0x911, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Interface\\GFx\\Botones\\System2.tga",    0x912, GL_LINEAR, GL_CLAMP, 1, 0);
	//--
	LoadBitmapA("Interface\\GFx\\newui_skillbox2.tga", 31313, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Interface\\GFx\\newui_skillbox.tga", 31312, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Interface\\GFx\\Main_Skillbox.tga", 51500, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Interface\\GFx\\none.tga", 0x7A4A, GL_LINEAR, GL_CLAMP, 1, 0);
	
    LoadBitmapA("Interface\\GFx\\Inventory\\Buttom_empty_small.tga", 61525, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Interface\\GFx\\Inventory\\newui_item_box.tga", 61527, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Interface\\GFx\\Inventory\\Draw_money.tga", 61528, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Interface\\GFx\\Inventory\\newui_item_lower.tga", 61532, GL_LINEAR, GL_CLAMP, 1, 0);      //pantas
	LoadBitmapA("Interface\\GFx\\Inventory\\newui_item_cap.tga", 61533, GL_LINEAR, GL_CLAMP, 1, 0);        //casco
	LoadBitmapA("Interface\\GFx\\Inventory\\newui_item_upper.tga", 61534, GL_LINEAR, GL_CLAMP, 1, 0);      //armor
	LoadBitmapA("Interface\\GFx\\Inventory\\newui_item_gloves.tga", 61535, GL_LINEAR, GL_CLAMP, 1, 0);     //gloves
	LoadBitmapA("Interface\\GFx\\Inventory\\newui_item_weapon(L).tga", 61536, GL_LINEAR, GL_CLAMP, 1, 0);  //weaponL
	LoadBitmapA("Interface\\GFx\\Inventory\\newui_item_fairy.tga", 61537, GL_LINEAR, GL_CLAMP, 1, 0);      //pets
	LoadBitmapA("Interface\\GFx\\Inventory\\newui_item_wing.tga", 61538, GL_LINEAR, GL_CLAMP, 1, 0);       //wings
	LoadBitmapA("Interface\\GFx\\Inventory\\newui_item_weapon(R).tga", 61539, GL_LINEAR, GL_CLAMP, 1, 0);  //weaponR
	LoadBitmapA("Interface\\GFx\\Inventory\\newui_item_boots.tga", 61540, GL_LINEAR, GL_CLAMP, 1, 0);      //boots
	LoadBitmapA("Interface\\GFx\\Inventory\\newui_item_ring.tga", 61541, GL_LINEAR, GL_CLAMP, 1, 0);       //ring
	LoadBitmapA("Interface\\GFx\\Inventory\\newui_item_necklace.tga", 61542, GL_LINEAR, GL_CLAMP, 1, 0);   //necklance
	//pLoadImage("Interface\\GFx\\Upgrade\\btn_arrow001.tga", 0xF1003, 0x2601, 0x2900, 1, 0);
	pLoadImage("Interface\\GFx\\Upgrade\\PetInventoryFrame_I3.tga", 0xF1010, 0x2601, 0x2900, 250, 50);
	pLoadImage("Interface\\GFx\\Upgrade\\PetInventoryFrame_I3.tga", 0xF1003, 0x2601, 0x2900, 1, 0);
	pLoadImage("Interface\\GFx\\Upgrade\\Tooltip_ID.tga", 0xF1004, 0x2601, 0x2900, 1, 0);
	pLoadImage("Interface\\GFx\\Upgrade\\Option_I3.tga", 0xF1005, 0x2601, 0x2900, 1, 0);
	pLoadImage("Interface\\GFx\\Upgrade\\InventoryFrame_I4.tga", 0xF1006, 0x2601, 0x2900, 1, 0);
	pLoadImage("Interface\\GFx\\Upgrade\\popup_bg_big01.tga", 0xF1007, 0x2601, 0x2900, 1, 0);
	pLoadImage("Interface\\GFx\\Upgrade\\HuntRecord_I1.tga", 0xF1008, 0x2601, 0x2900, 1, 0);
	pLoadImage("Interface\\GFx\\Upgrade\\CommandWindow_I1.tga", 0xF1009, 0x2601, 0x2900, 1, 0);
	pLoadImage("Interface\\GFx\\Upgrade\\xulie_flow.tga", 0xF2000, 0x2601, 0x2900, 1, 0);
	pLoadImage("Interface\\GFx\\Upgrade\\shandianCos_red.tga", 0xF2001, 0x2601, 0x2900, 1, 0);
}
