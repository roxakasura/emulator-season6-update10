#include "stdafx.h"
#include "ItemPosition.h"
#include "Defines.h"
#include "Util.h"
#include "offset.h"
#include "Import.h"
#include "Item.h"
#include "CustomGloves.h"
#include "CustomBow.h"
#include "CustomPet.h"
#include "CustomItemPosition.h"

cItemPosition gItemPosition;

void cItemPosition::Load()
{
	SetCompleteHook(0xE8, 0x5CF310+0x1884,&this->SetPosition);
}

void cItemPosition::SetPosition(int a1, int a2, int a3, int a4, VAngle* a5, int a6, char a7)
{
	signed int v7; // ST30_4@567
	int v8; // eax@567
	int v9; // edx@568
	bool v10; // al@570
	float v11; // ST30_4@1089
	float v12; // ST2C_4@1089
	void *v13; // eax@1089
	void *v14; // eax@1090
	int v15; // eax@1090
	double v16; // st7@1090
	float v17; // [sp+30h] [bp-618h]@595
	int v18; // [sp+58h] [bp-5F0h]@1089
	ObjectPreview v19;//char v19; // [sp+5Ch] [bp-5ECh]@1089
	char v20; // [sp+6Fh] [bp-5D9h]@1089
	char v21; // [sp+364h] [bp-2E4h]@1089
	int v22; // [sp+36Dh] [bp-2DBh]@1089
	signed int v23; // [sp+394h] [bp-2B4h]@1089
	float v24; // [sp+3C4h] [bp-284h]@1090
	float v25; // [sp+3FCh] [bp-24Ch]@1092
	float v26; // [sp+460h] [bp-1E8h]@1092
	int v27; // [sp+5F8h] [bp-50h]@567
	VAngle v28; // [sp+5FCh] [bp-4Ch]@2
	int v29; // [sp+608h] [bp-40h]@1089
	int v30; // [sp+60Ch] [bp-3Ch]@1092
	VAngle v31; // [sp+610h] [bp-38h]@1
	float v32; // [sp+61Ch] [bp-2Ch]@588
	float v33; // [sp+620h] [bp-28h]@1092
	int v34; // [sp+624h] [bp-24h]@1092
	int v35; // [sp+628h] [bp-20h]@1092
	int v36; // [sp+62Ch] [bp-1Ch]@1
	VAngle v37; // [sp+630h] [bp-18h]@1092
	int v38; // [sp+644h] [bp-4h]@1089

	v36 = (a2 >> 3) & 0xF;
	v31.X = a5->X - *(float*)0x8793394;
	v31.Y = a5->Y - *(float*)0x8793398;
	v31.Z = a5->Z - *(float*)0x879339C;

	int X = 0;
	int Y = 0;
	pGetPosFromAngle(a5, &X, &Y);

	if ( a7 )
	{
		sub_959A60_Addr(0x8793394, 0.07f, (int)&v31, (int)&v28);
	}	
	else
	{
		sub_959A60_Addr(0x8793394, 0.1f, (int)&v31, (int)&v28);
	}
		
	CUSTOM_POSITION_INFO* posicionGlobal = gCustomPosition.GetInfoByItem(a1-ITEM_BASE_MODEL);

	if(gCustomPet2.CheckCustomPetByItem(a1 - 1171))
	{
		a1 = gCustomPet2.GetInfoByItemInventory(a1 - 1171);
	}

/*	if(a1 == 1171)
	{
		a1 = 1193;
	}*/

	if ( a1 == ITEM_BASE_MODEL )
	{
		v28.X += 0.0199999955296516;
		v28.Y -= 0.080999999932944775;

		*(float*) 0x82C6320 = 180.0;
		*(float*) 0x82C6324 = 270.0;
		*(float*) 0x82C6328 = 20.0;
	}

	if ( a1 == 0 + ITEM_BASE_MODEL )
	{
		v28.X += 0.0729999955296516;
		v28.Y -= 0.018999999932944775;

		*(float*) 0x82C6320 = 180.0;
		*(float*) 0x82C6324 = 270.0;
		*(float*) 0x82C6328 = 20.0;
	}

	else if ( a1 != 3226 && a1 != 3234 )
	{
		switch ( a1 )
		{
		case 2707:
			v28.Y = v28.Y + 0.05000000074505806;
			*(float*)0x82C6320 = 0.0;
			*(float*)0x82C6324 = 90.0;
			*(float*)0x82C6328 = 20.0;
			break;
		case 3236:
			*(float*)0x82C6320 = 0.0;
			*(float*)0x82C6324 = 90.0;
			*(float*)0x82C6328 = 15.0;
			break;
		case 4786:
			v28.Y = v28.Y - 0.05999999865889549;
			v28.X = v28.X + 0.02999999932944775;
			*(float*)0x82C6320 = -90.0;
			*(float*)0x82C6324 = 0.0;
			*(float*)0x82C6328 = 0.0;
			break;
		case 4785:
			v28.Y = v28.Y + 0.07000000029802322;
			v28.X = v28.X - 0.02999999932944775;
			*(float*)0x82C6320 = -90.0;
			*(float*)0x82C6324 = 0.0;
			*(float*)0x82C6328 = 0.0;
			break;
		case 5297:
			v28.Y = v28.Y + 0.1000000014901161;
			*(float*)0x82C6320 = -90.0;
			*(float*)0x82C6324 = 0.0;
			*(float*)0x82C6328 = 0.0;
			break;
		case 5296:
			v28.Y = v28.Y + 0.07000000029802322;
			*(float*)0x82C6320 = -90.0;
			*(float*)0x82C6324 = 0.0;
			*(float*)0x82C6328 = 0.0;
			break;
		case 3240:
			v28.Y = v28.Y + 0.119999997317791;
			*(float*)0x82C6320 = 180.0;
			*(float*)0x82C6324 = -90.0;
			*(float*)0x82C6328 = 15.0;
			break;
		case 3743:
			v28.Y = v28.Y - 0.1000000014901161;
			v28.X = v28.X + 0.02500000037252903;
			*(float*)0x82C6320 = 180.0;
			*(float*)0x82C6324 = 0.0;
			*(float*)0x82C6328 = 8.0;
			break;
		default:
			if ( (a1 < 3752 || a1 > 3760) && a1 != 3771 )
			{
				switch ( a1 )
				{
				case 2209:
					v28.Y = v28.Y + 0.1000000014901161;
					v28.X = v28.X - 0.01;
					*(float*)0x82C6320 = 180.0;
					*(float*)0x82C6324 = 90.0;
					*(float*)0x82C6328 = 13.0;
					break;
				case 5301:
					v28.Y = v28.Y + 0.02999999932944775;
					*(float*)0x82C6320 = -90.0;
					*(float*)0x82C6324 = 0.0;
					*(float*)0x82C6328 = 0.0;
					break;
				case 4790:
					v28.X = v28.X - 0.01999999955296516;
					v28.Y = v28.Y + 0.05000000074505806;
					*(float*)0x82C6320 = -90.0;
					*(float*)0x82C6324 = 0.0;
					*(float*)0x82C6328 = 0.0;
					break;
				case 5302:
					v28.Y = v28.Y + 0.05000000074505806;
					*(float*)0x82C6320 = -90.0;
					*(float*)0x82C6324 = 0.0;
					*(float*)0x82C6328 = 0.0;
					break;
				case 5303:
					v28.Y = v28.Y - 0.05000000074505806;
					*(float*)0x82C6320 = -90.0;
					*(float*)0x82C6324 = 0.0;
					*(float*)0x82C6328 = 0.0;
					break;
				case 5304:
					v28.Y = v28.Y - 0.05000000074505806;
					*(float*)0x82C6320 = -90.0;
					*(float*)0x82C6324 = 0.0;
					*(float*)0x82C6328 = 0.0;
					break;
				default:
					if ( (a1 < 4794 || a1 > 4799) && a1 != 4837 )
					{
						if ( (a1 < 5306 || a1 > 5311) && a1 != 5349 )
						{
							if ( a1 == 1195 )
							{
								v28.X = v28.X - 0.01999999955296516;
								v28.Y = v28.Y + 0.02999999932944775;
								*(float*)0x82C6320 = 180.0;
								*(float*)0x82C6324 = 90.0;
								*(float*)0x82C6328 = 15.0;
							}
							else if ( a1 == 2210 )
							{
								v28.Y = v28.Y + 0.05000000074505806;
								*(float*)0x82C6320 = 180.0;
								*(float*)0x82C6324 = 90.0;
								*(float*)0x82C6328 = 13.0;
							}
							else if ( a1 != 3241 && a1 != 3242 )
							{
								switch ( a1 )
								{
								case 3744:
									v28.X = v28.X + 0.01999999955296516;
									v28.Y = v28.Y + 0.01999999955296516;
									*(float*)0x82C6320 = 180.0;
									*(float*)0x82C6324 = 90.0;
									*(float*)0x82C6328 = 8.0;
									break;
								case 3239:
									*(float*)0x82C6320 = 180.0;
									*(float*)0x82C6324 = -90.0;
									*(float*)0x82C6328 = 15.0;
									break;
								case 3246:
									*(float*)0x82C6320 = 180.0;
									*(float*)0x82C6324 = -90.0;
									*(float*)0x82C6328 = 25.0;
									break;
								default:
									//-- customBow
									if (gCustomBow.CheckCustomBow(a1-ITEM_BASE_MODEL))
									{
										*(float*)0x82C6320 = 180.0;
										*(float*)0x82C6324 = -90.0;
										*(float*)0x82C6328 = 15.0;
									}
									else if (gCustomBow.CheckCustomCross(a1-ITEM_BASE_MODEL))
									{
										*(float*)0x82C6320 = 90.0;
										*(float*)0x82C6324 = 180.0;
										*(float*)0x82C6328 = 20.0;
									}
									else if(gCustomPet2.CheckCustomPetByItem(a1 - ITEM_BASE_MODEL))
									{
										v28.Y -= 0.01999999955296516;
										*(float*)0x82C6320 = 270.0; //ângulo de rotação Z
										*(float*)0x82C6324 = gCustomPet2.GetScaleAngle(a1 - ITEM_BASE_MODEL);  //ângulo de rotação X
										*(float*)0x82C6328 = 0.0; //ângulo de rotação Y
									}
									else if ( a1 < 3227 || a1 >= 3731 )
									{
										if ( a1 == 2717 )
										{
											*(float*)0x82C6320 = 180.0;
											*(float*)0x82C6324 = 270.0;
											*(float*)0x82C6328 = 20.0;
										}
										else if ( a1 < ITEM_BASE_MODEL || a1 >= 4243 )
										{
											if ( a1 < 4243 || a1 >= 4755 )
											{
												switch ( a1 )
												{
												case 7830:
													*(float*)0x82C6320 = -90.0;
													*(float*)0x82C6324 = -90.0;
													*(float*)0x82C6328 = 0.0;
													break;
												case 7831:
													*(float*)0x82C6320 = -90.0;
													*(float*)0x82C6324 = -90.0;
													*(float*)0x82C6328 = 0.0;
													break;
												case 7832:
													*(float*)0x82C6320 = -90.0;
													*(float*)0x82C6324 = -35.0;
													*(float*)0x82C6328 = 0.0;
													break;
												case 7858:
													*(float*)0x82C6320 = -90.0;
													*(float*)0x82C6324 = -90.0;
													*(float*)0x82C6328 = 0.0;
													break;
												case 7857:
													*(float*)0x82C6320 = -90.0;
													*(float*)0x82C6324 = 0.0;
													*(float*)0x82C6328 = 0.0;
													break;
												case 9525:
													*(float*)0x82C6320 = -90.0;
													*(float*)0x82C6324 = 0.0;
													*(float*)0x82C6328 = 0.0;
													break;
												default:
													if ( a1 != 7843 && a1 != 7844 )
													{
														switch ( a1 )
														{
														case 7845:
															*(float*)0x82C6320 = 290.0;
															*(float*)0x82C6324 = 0.0;
															*(float*)0x82C6328 = 0.0;
															break;
														case 9520:
															if ( v36 == 2 )
															{
																*(float*)0x82C6320 = 270.0;
																*(float*)0x82C6324 = 0.0;
																*(float*)0x82C6328 = 0.0;
															}
															else
															{
																*(float*)0x82C6320 = -90.0;
																*(float*)0x82C6324 = -20.0;
																*(float*)0x82C6328 = -20.0;
															}
															break;
														case 9521:
															*(float*)0x82C6320 = 250.0;
															*(float*)0x82C6324 = 140.0;
															*(float*)0x82C6328 = 0.0;
															break;
														case 9523:
															*(float*)0x82C6320 = 255.0;
															*(float*)0x82C6324 = 160.0;
															*(float*)0x82C6328 = 0.0;
															break;
														case 9524:
															*(float*)0x82C6320 = 270.0;
															*(float*)0x82C6324 = 0.0;
															*(float*)0x82C6328 = 0.0;
															break;
														default:
															if ( a1 < 7848 || a1 > 7851 )
															{
																switch ( a1 )
																{
																case 7856:
																	*(float*)0x82C6320 = 290.0;
																	*(float*)0x82C6324 = 0.0;
																	*(float*)0x82C6328 = 0.0;
																	break;
																case 7859:
																	v28.X = v28.X + 0.009999999776482582;
																	v28.Y = v28.Y - 0.02999999932944775;
																	*(float*)0x82C6320 = 270.0;
																	*(float*)0x82C6324 = 0.0;
																	*(float*)0x82C6328 = 0.0;
																	break;
																case 7860:
																	v28.Y = v28.Y + 0.01999999955296516;
																	*(float*)0x82C6320 = 270.0;
																	*(float*)0x82C6324 = 0.0;
																	*(float*)0x82C6328 = 0.0;
																	break;
																case 7861:
																	v28.X = v28.X + 0.009999999776482582;
																	v28.Y = v28.Y + 0.01999999955296516;
																	*(float*)0x82C6320 = 270.0;
																	*(float*)0x82C6324 = 0.0;
																	*(float*)0x82C6328 = 0.0;
																	break;
																case 7862:
																	v28.X = v28.X + 0.009999999776482582;
																	v28.Y = v28.Y + 0.01999999955296516;
																	*(float*)0x82C6320 = 270.0;
																	*(float*)0x82C6324 = 0.0;
																	*(float*)0x82C6328 = 0.0;
																	break;
																case 7863:
																	v28.X = v28.X + 0.009999999776482582;
																	v28.Y = v28.Y + 0.05000000074505806;
																	*(float*)0x82C6320 = 270.0;
																	*(float*)0x82C6324 = 0.0;
																	*(float*)0x82C6328 = 0.0;
																	break;
																case 7864:
																	v28.X = v28.X + 0.009999999776482582;
																	v28.Y = v28.Y + 0.03999999910593033;
																	*(float*)0x82C6320 = 270.0;
																	*(float*)0x82C6324 = 0.0;
																	*(float*)0x82C6328 = 0.0;
																	break;
																default:
																	if ( (a1 < 8394 || a1 > 8396) && (a1 < 8496 || a1 > 8498) )
																	{
																		switch ( a1 )
																		{
																		case 7876:
																			v28.Y = v28.Y - 0.03999999910593033;
																			*(float*)0x82C6320 = 270.0;
																			*(float*)0x82C6324 = 0.0;
																			*(float*)0x82C6328 = 0.0;
																			break;
																		case 7877:
																			v28.Y = v28.Y - 0.02999999932944775;
																			*(float*)0x82C6320 = 270.0;
																			*(float*)0x82C6324 = 0.0;
																			*(float*)0x82C6328 = 0.0;
																			break;
																		case 7878:
																			v28.Y = v28.Y - 0.01999999955296516;
																			*(float*)0x82C6320 = 270.0;
																			*(float*)0x82C6324 = 0.0;
																			*(float*)0x82C6328 = 0.0;
																			break;
																		default:
																			if ( a1 != 8403 && a1 != 8492 )
																			{
																				switch ( a1 )
																				{
																				case 7879:
																					v28.Y = v28.Y + 0.04500000178813934;
																					*(float*)0x82C6320 = 270.0;
																					*(float*)0x82C6324 = 0.0;
																					*(float*)0x82C6328 = 0.0;
																					break;
																				case 7880:
																					v28.Y = v28.Y + 0.03999999910593033;
																					*(float*)0x82C6320 = 270.0;
																					*(float*)0x82C6324 = 120.0;
																					*(float*)0x82C6328 = 0.0;
																					break;
																				case ITEM2(12,36):
																					v28.Y -= 0.05000000074505806;
																					*(float*)0x82C6320 = 270.0;
																					*(float*)0x82C6324 = -10.0;
																					*(float*)0x82C6328 = 0.0;
																					break;
																				case 7352:
																				case 7353:
																					v28.Y += 0.05000000074505806;
																					*(float*)0x82C6320 = 270.0;
																					*(float*)0x82C6324 = -10.0;
																					*(float*)0x82C6328 = 0.0;
																					break;
																				case 7354:
																					v28.Y = v28.Y + 0.07999999821186066;
																					*(float*)0x82C6320 = 270.0;
																					*(float*)0x82C6324 = -10.0;
																					*(float*)0x82C6328 = 0.0;
																					break;
																				case 7355:
																					v28.Y = v28.Y + 0.05000000074505806;
																					*(float*)0x82C6320 = 270.0;
																					*(float*)0x82C6324 = -10.0;
																					*(float*)0x82C6328 = 0.0;
																					break;
																				case 7357:
																					v28.Y = v28.Y + 0.05000000074505806;
																					*(float*)0x82C6320 = 270.0;
																					*(float*)0x82C6324 = 0.0;
																					*(float*)0x82C6328 = 2.0;
																					break;
																				case 7873:
																					v28.Y = v28.Y - 0.03999999910593033;
																					*(float*)0x82C6320 = 270.0;
																					*(float*)0x82C6324 = 0.0;
																					*(float*)0x82C6328 = 0.0;
																					break;
																				case 7874:
																					v28.Y = v28.Y - 0.03999999910593033;
																					*(float*)0x82C6320 = 270.0;
																					*(float*)0x82C6324 = 0.0;
																					*(float*)0x82C6328 = 0.0;
																					break;
																				case 7875:
																					v28.Y = v28.Y - 0.03999999910593033;
																					*(float*)0x82C6320 = 270.0;
																					*(float*)0x82C6324 = 0.0;
																					*(float*)0x82C6328 = 0.0;
																					break;
																				case 8393:
																					*(float*)0x82C6320 = 270.0;
																					*(float*)0x82C6324 = 0.0;
																					*(float*)0x82C6328 = 0.0;
																					break;
																				case 8397:
																					v28.Y = v28.Y + 0.07000000029802322;
																					*(float*)0x82C6320 = 270.0;
																					*(float*)0x82C6324 = 0.0;
																					*(float*)0x82C6328 = 0.0;
																					break;
																				default:
																					if ( a1 != 8398 && a1 != 8399 )
																					{
																						if ( a1 != 8400 && a1 != 8401 )
																						{
																							switch ( a1 )
																							{
																							case 8392:
																								v28.Y = v28.Y + 0.04199999943375587;
																								*(float*)0x82C6320 = 180.0;
																								*(float*)0x82C6324 = 0.0;
																								*(float*)0x82C6328 = 0.0;
																								break;
																							case 7870:
																								v28.Y = v28.Y - 0.02700000070035458;
																								v28.X = v28.X + 0.004999999888241291;
																								*(float*)0x82C6320 = 270.0;
																								*(float*)0x82C6324 = 0.0;
																								*(float*)0x82C6328 = 0.0;
																								break;
																							case 7871:
																								v28.Y = v28.Y - 0.02999999932944775;
																								v28.X = v28.X + 0.004999999888241291;
																								*(float*)0x82C6320 = 270.0;
																								*(float*)0x82C6324 = 0.0;
																								*(float*)0x82C6328 = 0.0;
																								break;
																							case 7872:
																								v28.Y = v28.Y - 0.01999999955296516;
																								v28.X = v28.X + 0.004999999888241291;
																								*(float*)0x82C6320 = 270.0;
																								*(float*)0x82C6324 = 0.0;
																								*(float*)0x82C6328 = 0.0;
																								break;
																							default:
																								if ( a1 < 8409 || a1 > 8410 )
																								{
																									if ( a1 < 8411 || a1 > 8416 )
																									{
																										if ( a1 == 7886 )
																										{
																											v28.X = v28.X + 0.009999999776482582;
																											v28.Y = v28.Y + 0.01999999955296516;
																											*(float*)0x82C6320 = 90.0;
																											*(float*)0x82C6324 = 0.0;
																											*(float*)0x82C6328 = 0.0;
																										}
																										else if ( a1 < 7881 || a1 > 7885 )
																										{
																											if ( a1 < 8417 || a1 > 8421 )
																											{
																												switch ( a1 )
																												{
																												case 7887:
																													v28.Y = v28.Y - 0.05999999865889549;
																													*(float*)0x82C6320 = 270.0;
																													*(float*)0x82C6324 = 0.0;
																													*(float*)0x82C6328 = 0.0;
																													break;
																												case 7888:
																													v28.Y = v28.Y - 0.03999999910593033;
																													*(float*)0x82C6320 = 270.0;
																													*(float*)0x82C6324 = 0.0;
																													*(float*)0x82C6328 = 0.0;
																													break;
																												case 8422:
																													v28.Y = v28.Y + 0.05999999865889549;
																													*(float*)0x82C6320 = 270.0;
																													*(float*)0x82C6324 = 0.0;
																													*(float*)0x82C6328 = 0.0;
																													break;
																												case 8431:
																													*(float*)0x82C6320 = 270.0;
																													*(float*)0x82C6324 = 0.0;
																													*(float*)0x82C6328 = 0.0;
																													break;
																												case 8432:
																													*(float*)0x82C6320 = 270.0;
																													*(float*)0x82C6324 = 0.0;
																													*(float*)0x82C6328 = 0.0;
																													break;
																												case 8434:
																													*(float*)0x82C6320 = 270.0;
																													*(float*)0x82C6324 = 0.0;
																													*(float*)0x82C6328 = 0.0;
																													break;
																												case 8433:
																													v28.X = v28.X + 0.009999999776482582;
																													*(float*)0x82C6320 = 270.0;
																													*(float*)0x82C6324 = 0.0;
																													*(float*)0x82C6328 = 0.0;
																													break;
																												default:
																													if ( a1 < 8423 || a1 > 8429 )
																													{
																														if ( a1 == 7889 )
																														{
																															v28.X = v28.X + 0.009999999776482582;
																															v28.Y = v28.Y - 0.02999999932944775;
																															*(float*)0x82C6320 = 270.0;
																															*(float*)0x82C6324 = 0.0;
																															*(float*)0x82C6328 = 0.0;
																														}
																														else if ( a1 == 7890 )
																														{
																															v28.X = v28.X + 0.009999999776482582;
																															v28.Y = v28.Y + 0.0820000022649765;
																															*(float*)0x82C6320 = 90.0;
																															*(float*)0x82C6324 = 0.0;
																															*(float*)0x82C6328 = 0.0;
																														}
																														else if ( a1 < 8436 || a1 > 8437 )
																														{
																															if ( a1 == 8435 )
																															{
																																v28.Y = v28.Y - 0.0130000002682209;
																																v28.X = v28.X + 0.003000000026077032;
																																*(float*)0x82C6320 = 270.0;
																																*(float*)0x82C6324 = 0.0;
																																*(float*)0x82C6328 = 0.0;
																															}
																															else if ( a1 < 7891 || a1 > 7892 )
																															{
																																switch ( a1 )
																																{
																																case 8404:
																																	v28.Y = v28.Y + 0.05000000074505806;
																																	*(float*)0x82C6320 = 270.0;
																																	*(float*)0x82C6324 = 0.0;
																																	*(float*)0x82C6328 = 0.0;
																																	break;
																																case 8405:
																																	v28.Y = v28.Y + 0.1099999994039536;
																																	*(float*)0x82C6320 = 270.0;
																																	*(float*)0x82C6324 = 0.0;
																																	*(float*)0x82C6328 = 0.0;
																																	break;
																																case 8406:
																																	v28.Y = v28.Y + 0.1099999994039536;
																																	*(float*)0x82C6320 = 270.0;
																																	*(float*)0x82C6324 = 0.0;
																																	*(float*)0x82C6328 = 0.0;
																																	break;
																																case 7866:
																																	*(float*)0x82C6320 = 270.0;
																																	*(float*)0x82C6324 = 0.0;
																																	*(float*)0x82C6328 = 0.0;
																																	break;
																																case 7870:
																																	v28.Y = v28.Y - 0.02999999932944775;
																																	*(float*)0x82C6320 = 90.0;
																																	*(float*)0x82C6324 = 0.0;
																																	*(float*)0x82C6328 = 180.0;
																																	break;
																																case 7871:
																																	v28.Y = v28.Y + 0.07999999821186066;
																																	*(float*)0x82C6320 = 90.0;
																																	*(float*)0x82C6324 = 0.0;
																																	*(float*)0x82C6328 = 0.0;
																																	break;
																																case 7872:
																																	v28.Y = v28.Y + 0.07000000029802322;
																																	*(float*)0x82C6320 = 90.0;
																																	*(float*)0x82C6324 = 0.0;
																																	*(float*)0x82C6328 = 0.0;
																																	break;
																																case 7867:
																																	*(float*)0x82C6320 = 270.0;
																																	*(float*)0x82C6324 = 0.0;
																																	*(float*)0x82C6328 = 0.0;
																																	break;
																																case 7868:
																																	*(float*)0x82C6320 = 270.0;
																																	*(float*)0x82C6324 = 0.0;
																																	*(float*)0x82C6328 = 0.0;
																																	break;
																																case 7878:
																																	*(float*)0x82C6320 = 270.0;
																																	*(float*)0x82C6324 = 0.0;
																																	*(float*)0x82C6328 = 0.0;
																																	break;
																																case 7869:
																																	*(float*)0x82C6320 = 270.0;
																																	*(float*)0x82C6324 = 0.0;
																																	*(float*)0x82C6328 = 0.0;
																																	break;
																																case 7865:
																																	v28.X = v28.X + 0.0;
																																	v28.Y = v28.Y + 0.01999999955296516;
																																	*(float*)0x82C6320 = -198.0;
																																	*(float*)0x82C6324 = 0.0;
																																	*(float*)0x82C6328 = 0.0;
																																	break;
																																case 8380:
																																	v28.Y = v28.Y
																																		+ 0.01999999955296516;
																																	*(float*)0x82C6320 = 270.0;
																																	*(float*)0x82C6324 = 90.0;
																																	*(float*)0x82C6328 = 0.0;
																																	break;
																																case 8381:
																																	v28.Y = v28.Y
																																		+ 0.01999999955296516;
																																	*(float*)0x82C6320 = 270.0;
																																	*(float*)0x82C6324 = -10.0;
																																	*(float*)0x82C6328 = 0.0;
																																	break;
																																default:
																																	if ( a1 != 8382 && a1 != 8383 )
																																	{
																																		if ( a1 < 7839
																																			|| a1 >= 8339
																																			|| a1 == 7841
																																			|| a1 == 7842 )
																																		{
																																			switch ( a1 )
																																			{
																																			case 8351:
																																				if ( v36 )
																																				{
																																					if ( v36 == 1 )
																																					{
																																						*(float*)0x82C6320 = 270.0;
																																						*(float*)0x82C6324 = 90.0;
																																						*(float*)0x82C6328 = 0.0;
																																					}
																																					else if ( v36 == 2 )
																																					{
																																						*(float*)0x82C6320 = 90.0;
																																						*(float*)0x82C6324 = 0.0;
																																						*(float*)0x82C6328 = 0.0;
																																					}
																																				}
																																				else
																																				{
																																					*(float*)0x82C6320 = 180.0;
																																					*(float*)0x82C6324 = 0.0;
																																					*(float*)0x82C6328 = 0.0;
																																				}
																																				break;
																																			case 9514:
																																				*(float*)0x82C6320 = 270.0;
																																				*(float*)0x82C6324 = 180.0;
																																				*(float*)0x82C6328 = 0.0;
																																				break;
																																			case 9515:
																																				*(float*)0x82C6320 = 270.0;
																																				*(float*)0x82C6324 = 90.0;
																																				*(float*)0x82C6328 = 0.0;
																																				break;
																																			case 9516:
																																				*(float*)0x82C6320 = 270.0;
																																				*(float*)0x82C6324 = 0.0;
																																				*(float*)0x82C6328 = 0.0;
																																				break;
																																			case 8359:
																																				*(float*)0x82C6320 = 270.0;
																																				*(float*)0x82C6324 = 0.0;
																																				*(float*)0x82C6328 = 0.0;
																																				break;
																																			case 8366:
																																				*(float*)0x82C6320 = 270.0;
																																				*(float*)0x82C6324 = 0.0;
																																				*(float*)0x82C6328 = 0.0;
																																				break;
																																			case 8402:
																																				v28.Y = v28.Y + 0.07999999821186066;
																																				*(float*)0x82C6320 = -50.0;
																																				*(float*)0x82C6324 = -60.0;
																																				*(float*)0x82C6328 = 0.0;
																																				break;
																																			case 8391:
																																				*(float*)0x82C6320 = 270.0;
																																				*(float*)0x82C6324 = -25.0;
																																				*(float*)0x82C6328 = 0.0;
																																				break;
																																			default:
																																				if ( a1 < 8870 || a1 > 8878 )
																																				{
																																					switch ( a1 )
																																					{
																																					case 7322:
																																						v28.X = v28.X + 0.004999999888241291;
																																						v28.Y = v28.Y - 0.01499999966472387;
																																						*(float*)0x82C6320 = 270.0;
																																						*(float*)0x82C6324 = 0.0;
																																						*(float*)0x82C6328 = 0.0;
																																						break;
																																					case 5277:
																																						v28.Y = v28.Y - 0.1000000014901161;
																																						*(float*)0x82C6320 = 270.0;
																																						*(float*)0x82C6324 = 0.0;
																																						*(float*)0x82C6328 = 0.0;
																																						break;
																																					case 5789:
																																						v28.Y = v28.Y - 0.07999999821186066;
																																						*(float*)0x82C6320 = 270.0;
																																						*(float*)0x82C6324 = 0.0;
																																						*(float*)0x82C6328 = 0.0;
																																						break;
																																					case 5278:
																																						v28.Y = v28.Y - 0.1000000014901161;
																																						*(float*)0x82C6320 = 270.0;
																																						*(float*)0x82C6324 = 0.0;
																																						*(float*)0x82C6328 = 0.0;
																																						break;
																																					case 5790:
																																						v28.Y = v28.Y - 0.07999999821186066;
																																						*(float*)0x82C6320 = 270.0;
																																						*(float*)0x82C6324 = 0.0;
																																						*(float*)0x82C6328 = 0.0;
																																						break;
																																					case 7359:
																																						v28.X = v28.X + 0.004999999888241291;
																																						v28.Y = v28.Y - 0.01499999966472387;
																																						*(float*)0x82C6320 = 270.0;
																																						*(float*)0x82C6324 = 0.0;
																																						*(float*)0x82C6328 = 0.0;
																																						break;
																																					default:
																																						if ( a1 != 7361 && a1 != 7360 )
																																						{
																																							*(float*)0x82C6320 = 270.0;
																																							*(float*)0x82C6324 = -10.0;
																																							*(float*)0x82C6328 = 0.0;
																																						}
																																						else
																																						{
																																							v28.X = v28.X + 0.004999999888241291;
																																							v28.Y = v28.Y - 0.01499999966472387;
																																							*(float*)0x82C6320 = 270.0;
																																							*(float*)0x82C6324 = 0.0;
																																							*(float*)0x82C6328 = 0.0;
																																						}
																																						break;
																																					}
																																				}
																																				else
																																				{
																																					v28.X = v28.X + 0.02999999932944775;
																																					v28.Y = v28.Y + 0.02999999932944775;
																																					*(float*)0x82C6320 = 270.0;
																																					*(float*)0x82C6324 = 0.0;
																																					*(float*)0x82C6328 = 0.0;
																																				}
																																				break;
																																			}
																																		}
																																		else
																																		{
																																			*(float*)0x82C6320 = 360.0;
																																			*(float*)0x82C6324 = 0.0;
																																			*(float*)0x82C6328 = 0.0;
																																		}
																																	}
																																	else
																																	{
																																		v28.X = v28.X- 0.03999999910593033;
																																		v28.Y = v28.Y+ 0.01999999955296516;
																																		v28.Z = v28.Z
																																			+ 0.01999999955296516;
																																		*(float*)0x82C6320 = 270.0;
																																		*(float*)0x82C6324 = -10.0;
																																		*(float*)0x82C6328 = -45.0;
																																	}
																																	break;
																																}
																															}
																															else
																															{
																																if ( a1 == 7891 )
																																{
																																	v28.Y = v28.Y
																																		- 0.05000000074505806;
																																}
																																else if ( a1 == 7892 )
																																{
																																	v28.Y = v28.Y
																																		- 0.01999999955296516;
																																}
																																*(float*)0x82C6320 = 270.0;
																																*(float*)0x82C6324 = -10.0;
																																*(float*)0x82C6328 = 0.0;
																															}
																														}
																														else
																														{
																															v28.Y = v28.Y + 0.09000000357627869;
																															*(float*)0x82C6320 = 0.0;
																															*(float*)0x82C6324 = 0.0;
																															*(float*)0x82C6328 = 0.0;
																														}
																													}
																													else
																													{
																														switch ( a1 )
																														{
																														case 8423:
																															v28.Y = v28.Y + 0.009999999776482582;
																															*(float*)0x82C6320 = 270.0;
																															*(float*)0x82C6324 = 0.0;
																															*(float*)0x82C6328 = 0.0;
																															break;
																														case 8424:
																															v28.Y = v28.Y - 0.009999999776482582;
																															*(float*)0x82C6320 = 270.0;
																															*(float*)0x82C6324 = 0.0;
																															*(float*)0x82C6328 = 0.0;
																															break;
																														case 8425:
																															v28.Y = v28.Y + 0.009999999776482582;
																															*(float*)0x82C6320 = 270.0;
																															*(float*)0x82C6324 = 0.0;
																															*(float*)0x82C6328 = 0.0;
																															break;
																														case 8426:
																															v28.Y = v28.Y + 0.009999999776482582;
																															*(float*)0x82C6320 = 270.0;
																															*(float*)0x82C6324 = 0.0;
																															*(float*)0x82C6328 = 0.0;
																															break;
																														case 8427:
																															v28.Y = v28.Y + 0.01499999966472387;
																															*(float*)0x82C6320 = 270.0;
																															*(float*)0x82C6324 = 0.0;
																															*(float*)0x82C6328 = 0.0;
																															break;
																														case 8428:
																															v28.Y = v28.Y + 0.01499999966472387;
																															*(float*)0x82C6320 = 270.0;
																															*(float*)0x82C6324 = 0.0;
																															*(float*)0x82C6328 = 0.0;
																															break;
																														case 8429:
																															v28.Y = v28.Y + 0.01499999966472387;
																															*(float*)0x82C6320 = 270.0;
																															*(float*)0x82C6324 = 0.0;
																															*(float*)0x82C6328 = 0.0;
																															break;
																														}
																													}
																													break;
																												}
																											}
																											else
																											{
																												v28.Y = v28.Y + 0.009999999776482582;
																												*(float*)0x82C6320 = 270.0;
																												*(float*)0x82C6324 = 0.0;
																												*(float*)0x82C6328 = 0.0;
																											}
																										}
																										else
																										{
																											v28.Y = v28.Y - 0.01999999955296516;
																											*(float*)0x82C6320 = 270.0;
																											*(float*)0x82C6324 = 0.0;
																											*(float*)0x82C6328 = 0.0;
																										}
																									}
																									else
																									{
																										v28.Y = v28.Y + 0.07999999821186066;
																										*(float*)0x82C6320 = 0.0;
																										*(float*)0x82C6324 = 0.0;
																										*(float*)0x82C6328 = 0.0;
																									}
																								}
																								else
																								{
																									v28.X = v28.X + 0.009999999776482582;
																									*(float*)0x82C6320 = 270.0;
																									*(float*)0x82C6324 = 0.0;
																									*(float*)0x82C6328 = 0.0;
																								}
																								break;
																							}
																						}
																						else
																						{
																							v28.Y = v28.Y + 0.05999999865889549;
																							*(float*)0x82C6320 = 270.0;
																							*(float*)0x82C6324 = 0.0;
																							*(float*)0x82C6328 = 0.0;
																						}
																					}
																					else
																					{
																						v28.Y = v28.Y + 0.05999999865889549;
																						*(float*)0x82C6320 = 270.0;
																						*(float*)0x82C6324 = 0.0;
																						*(float*)0x82C6328 = 0.0;
																					}
																					break;
																				}
																			}
																			else
																			{
																				v28.Y = v28.Y + 0.01999999955296516;
																				*(float*)0x82C6320 = 270.0;
																				*(float*)0x82C6324 = 0.0;
																				*(float*)0x82C6328 = 0.0;
																			}
																			break;
																		}
																	}
																	else
																	{
																		v28.Y = v28.Y + 0.01999999955296516;
																		*(float*)0x82C6320 = 270.0;
																		*(float*)0x82C6324 = 0.0;
																		*(float*)0x82C6328 = 0.0;
																	}
																	break;
																}
															}
															else
															{
																*(float*)0x82C6320 = 270.0;
																*(float*)0x82C6324 = 160.0;
																*(float*)0x82C6328 = 20.0;
															}
															break;
														}
													}
													else
													{
														*(float*)0x82C6320 = 270.0;
														*(float*)0x82C6324 = -10.0;
														*(float*)0x82C6328 = 0.0;
													}
													break;
												}
											}
											else
											{
												*(float*)0x82C6320 = 270.0;
												*(float*)0x82C6324 = 270.0;
												*(float*)0x82C6328 = 0.0;
											}
										}
										else
										{
											switch ( a1 )
											{
											case 3745:
												v28.Y = v28.Y + 0.03999999910593033;
												break;
											case 3748:
												v28.X = v28.X + 0.01999999955296516;
												v28.Y = v28.Y + 0.02999999932944775;
												break;
											case 3749:
												v28.X = v28.X + 0.01999999955296516;
												break;
											case 3750:
												v28.X = v28.X - 0.01999999955296516;
												v28.Y = v28.Y - 0.01999999955296516;
												break;
											case 3751:
												v28.X = v28.X + 0.009999999776482582;
												v28.Y = v28.Y - 0.009999999776482582;
												break;
											default:
												break;
											}
											if ( *(BYTE*)(*(DWORD*)0x8128AC0 + 84 * (a1 - ITEM_BASE_MODEL) + 30) ) //??
											{
												*(float*)0x82C6320 = 180.0;
												*(float*)0x82C6324 = 270.0;
												*(float*)0x82C6328 = 25.0;
											}
											else
											{
												*(float*)0x82C6320 = 180.0; //RF
												*(float*)0x82C6324 = 270.0;
												*(float*)0x82C6328 = 15.0;
											}
										}
									}
									else
									{
										if(a1 >= ITEM2(4,8) && a1 <= ITEM2(4,10)){
											v28.X -= 0.0300000014901161;
										}
										
										*(float*)0x82C6320 = 90.0;
										*(float*)0x82C6324 = 180.0;
										*(float*)0x82C6328 = 20.0;
									}
									break;
								}
							}
							else
							{
								v28.X = v28.X - 0.1000000014901161;
								v28.Y = v28.Y + 0.07999999821186066;
								*(float*)0x82C6320 = 180.0;
								*(float*)0x82C6324 = -90.0;
								*(float*)0x82C6328 = 15.0;
							}
						}
						else
						{
							v28.Y = v28.Y - 0.07999999821186066;
							*(float*)0x82C6320 = -90.0;
							*(float*)0x82C6324 = 0.0;
							*(float*)0x82C6328 = 0.0;
						}
					}
					else
					{
						v28.Y = v28.Y - 0.05000000074505806;
						*(float*)0x82C6320 = -90.0;
						*(float*)0x82C6324 = 25.0;
						*(float*)0x82C6328 = 0.0;
					}
					break;
				}
			}
			else
			{
				*(float*)0x82C6320 = 0.0;
				*(float*)0x82C6324 = 0.0;
				*(float*)0x82C6328 = 0.0;
			}
			break;
		}
	}
	else
	{
		*(float*)0x82C6320 = 0.0;
		*(float*)0x82C6324 = 270.0;
		*(float*)0x82C6328 = 15.0;
	}
	
	if (a1 > 1171 && ( a1 < 7375 || a1 > 7380) )
	{
		if ( a1 < 7385 || a1 > 7389 )
		{
			if ( a1 < 7415 || a1 > 7444 )
			{
				switch ( a1 )
				{
				case 7894:
					v28.Y = v28.Y - 0.05000000074505806;
					*(float*)0x82C6320 = 270.0;
					*(float*)0x82C6324 = 40.0;
					*(float*)0x82C6328 = 0.0;
					break;
				case 7950:
					v28.Y = v28.Y - 0.05000000074505806;
					*(float*)0x82C6320 = 270.0;
					*(float*)0x82C6324 = 40.0;
					*(float*)0x82C6328 = 0.0;
					break;
				case 8479:
					v28.Y = v28.Y + 0.09000000357627869;
					*(float*)0x82C6320 = 0.0;
					*(float*)0x82C6324 = 0.0;
					*(float*)0x82C6328 = 0.0;
					break;
				default:
					if ( a1 < 8484 || a1 > 8489 )
					{
						if ( a1 != 8490 && a1 != 8491 )
						{
							if ( a1 == 8494 )
							{
								v28.Y = v28.Y + 0.119999997317791;
							}
							else if ( a1 == 8495 )
							{
								v28.X = v28.X + 0.03999999910593033;
								v28.Y = v28.Y + 0.1099999994039536;
								*(float*)0x82C6320 = 180.0;
								*(float*)0x82C6324 = 270.0;
								*(float*)0x82C6328 = 15.0;
							}
							else if ( a1 < 7952 || a1 > 7954 )
							{
								switch ( a1 )
								{
								case 7951:
									v28.Y = v28.Y - 0.03999999910593033;
									*(float*)0x82C6320 = 270.0;
									*(float*)0x82C6324 = 0.0;
									*(float*)0x82C6328 = 0.0;
									break;
								case 7907:
									v28.Y = v28.Y - 0.05000000074505806;
									*(float*)0x82C6320 = 270.0;
									*(float*)0x82C6324 = 40.0;
									*(float*)0x82C6328 = 0.0;
									break;
								case 7933:
									v28.X = v28.X + 0.009999999776482582;
									v28.Y = v28.Y - 0.05000000074505806;
									*(float*)0x82C6320 = 255.0;
									*(float*)0x82C6324 = 45.0;
									*(float*)0x82C6328 = 0.0;
									break;
								case 7895:
									v28.X = v28.X + 0.01999999955296516;
									v28.Y = v28.Y - 0.01999999955296516;
									*(float*)0x82C6320 = 300.0;
									*(float*)0x82C6324 = 10.0;
									*(float*)0x82C6328 = 20.0;
									break;
								case 7903:
									v28.Y = v28.Y - 0.01999999955296516;
									*(float*)0x82C6320 = 270.0;
									*(float*)0x82C6324 = 0.0;
									*(float*)0x82C6328 = 0.0;
									break;
								case 7949:
									v28.X = v28.X + 0.009999999776482582;
									v28.Y = v28.Y - 0.03500000014901161;
									*(float*)0x82C6320 = 290.0;
									*(float*)0x82C6324 = -20.0;
									*(float*)0x82C6328 = 0.0;
									break;
								case 7955:
									v28.X = v28.X + 0.01700000092387199;
									v28.Y = v28.Y - 0.05299999937415123;
									*(float*)0x82C6320 = 270.0;
									*(float*)0x82C6324 = -20.0;
									*(float*)0x82C6328 = 0.0;
									break;
								case 7956:
									v28.X = v28.X + 0.01200000010430813;
									v28.Y = v28.Y - 0.04500000178813934;
									*(float*)0x82C6320 = 270.0;
									*(float*)0x82C6324 = -20.0;
									*(float*)0x82C6328 = 0.0;
									break;
								case 7961:
									v28.X = v28.X + 0.004999999888241291;
									v28.Y = v28.Y - 0.03299999982118607;
									*(float*)0x82C6320 = 270.0;
									*(float*)0x82C6324 = -20.0;
									*(float*)0x82C6328 = 0.0;
									break;
								case 7957:
									v28.X = v28.X + 0.007000000216066837;
									v28.Y = v28.Y + 0.004999999888241291;
									*(float*)0x82C6320 = 270.0;
									*(float*)0x82C6324 = -20.0;
									*(float*)0x82C6328 = 0.0;
									break;
								case 7958:
									v28.X = v28.X + 0.01700000092387199;
									v28.Y = v28.Y - 0.05299999937415123;
									*(float*)0x82C6320 = 270.0;
									*(float*)0x82C6324 = -20.0;
									*(float*)0x82C6328 = 0.0;
									break;
								case 7959:
									v28.X = v28.X + 0.007000000216066837;
									v28.Y = v28.Y + 0.04500000178813934;
									*(float*)0x82C6320 = 270.0;
									*(float*)0x82C6324 = -20.0;
									*(float*)0x82C6328 = 0.0;
									break;
								case 7960:
									v28.X = v28.X + 0.01700000092387199;
									v28.Y = v28.Y - 0.05299999937415123;
									*(float*)0x82C6320 = 270.0;
									*(float*)0x82C6324 = -20.0;
									*(float*)0x82C6328 = 0.0;
									break;
								case 7896:
									v28.X = v28.X + 0.004999999888241291;
									v28.Y = v28.Y - 0.05000000074505806;
									*(float*)0x82C6320 = 270.0;
									*(float*)0x82C6324 = -30.0;
									*(float*)0x82C6328 = 0.0;
									break;
								case 7897:
									v28.X = v28.X + 0.03999999910593033;
									v28.Y = v28.Y - 0.0;
									*(float*)0x82C6320 = 270.0;
									*(float*)0x82C6324 = -0.0;
									*(float*)0x82C6328 = 70.0;
									break;
								case 7908:
									v28.X = v28.X + 0.004999999888241291;
									v28.Y = v28.Y + 0.03500000014901161;
									*(float*)0x82C6320 = -90.0;
									*(float*)0x82C6324 = 0.0;
									*(float*)0x82C6328 = 0.0;
									break;
								case 7909:
									v28.X = v28.X + 0.004999999888241291;
									v28.Y = v28.Y + 0.03500000014901161;
									*(float*)0x82C6320 = -90.0;
									*(float*)0x82C6324 = 0.0;
									*(float*)0x82C6328 = 0.0;
									break;
								case ITEM2(13,93):
								case ITEM2(13,94):
									v28.X += 0.004999999888241291;
									v28.Y -= 0.03500000014901161;
									*(float*)0x82C6320 = -90.0;
									*(float*)0x82C6324 = 0.0;
									*(float*)0x82C6328 = 0.0;
									break;
								case 7893:
									v28.X = v28.X + 0.009999999776482582;
									v28.Y = v28.Y - 0.05000000074505806;
									*(float*)0x82C6320 = 270.0;
									*(float*)0x82C6324 = 0.0;
									*(float*)0x82C6328 = 0.0;
									break;
								case 8439:
									v28.X = v28.X + 0.009999999776482582;
									v28.Y = v28.Y - 0.05000000074505806;
									*(float*)0x82C6320 = 0.0;
									*(float*)0x82C6324 = 0.0;
									*(float*)0x82C6328 = 0.0;
									break;
								case 8438:
									v28.X = v28.X + 0.01999999955296516;
									v28.Y = v28.Y - 0.02999999932944775;
									*(float*)0x82C6320 = 290.0;
									*(float*)0x82C6324 = -40.0;
									*(float*)0x82C6328 = 0.0;
									break;
								case 3764:
									v28.X = v28.X + 0.01999999955296516;
									v28.Y = v28.Y - 0.05999999865889549;
									*(float*)0x82C6320 = 180.0;
									*(float*)0x82C6324 = 90.0;
									*(float*)0x82C6328 = 10.0;
									break;
								case 3765:
									v28.Y = v28.Y - 0.05000000074505806;
									*(float*)0x82C6320 = 180.0;
									*(float*)0x82C6324 = 90.0;
									*(float*)0x82C6328 = 10.0;
									break;
								case 2718:
									v28.Y = v28.Y + 0.01999999955296516;
									*(float*)0x82C6320 = 180.0;
									*(float*)0x82C6324 = 90.0;
									*(float*)0x82C6328 = 15.0;
									break;
								case 2213:
									v28.X = v28.X - 0.02999999932944775;
									v28.Y = v28.Y + 0.05999999865889549;
									*(float*)0x82C6320 = 180.0;
									*(float*)0x82C6324 = 90.0;
									*(float*)0x82C6328 = 2.0;
									break;
								case 3243:
									v28.X = v28.X - 0.07000000029802322;
									v28.Y = v28.Y + 0.07000000029802322;
									*(float*)0x82C6320 = 180.0;
									*(float*)0x82C6324 = -90.0;
									*(float*)0x82C6328 = 15.0;
									break;
								case 7362:
									v28.X = v28.X + 0.004999999888241291;
									v28.Y = v28.Y - 0.01499999966472387;
									*(float*)0x82C6320 = 270.0;
									*(float*)0x82C6324 = 0.0;
									*(float*)0x82C6328 = 0.0;
									break;
								default:
									if ( a1 != 7898 && a1 != 7899 && a1 != 7900 && a1 != 7901 && a1 != 7902 )
									{
										if ( a1 < 7910 || a1 > 7920 )
										{
											if ( a1 != 7924 && a1 != 7925 && a1 != 8430 )
											{
												switch ( a1 )
												{
												case 8449:
													v28.X = v28.X + 0.004999999888241291;
													v28.Y = v28.Y - 0.01999999955296516;
													break;
												case 8450:
													v28.X = v28.X + 0.009999999776482582;
													v28.Y = v28.Y - 0.01999999955296516;
													break;
												case 7934:
													v28.X = v28.X - 0.0;
													v28.Y = v28.Y + 0.0;
													*(float*)0x82C6320 = 90.0;
													*(float*)0x82C6324 = 225.0;
													*(float*)0x82C6328 = 45.0;
													break;
												case 7931:
													v28.X = v28.X + 0.009999999776482582;
													v28.Y = v28.Y - 0.02999999932944775;
													*(float*)0x82C6320 = 270.0;
													*(float*)0x82C6324 = 0.0;
													*(float*)0x82C6328 = 0.0;
													break;
												case 7932:
													v28.X = v28.X + 0.009999999776482582;
													v28.Y = v28.Y - 0.02999999932944775;
													*(float*)0x82C6320 = 270.0;
													*(float*)0x82C6324 = 0.0;
													*(float*)0x82C6328 = 0.0;
													break;
												case 7930:
													v28.X = v28.X + 0.009999999776482582;
													v28.Y = v28.Y + 0.009999999776482582;
													*(float*)0x82C6320 = 0.0;
													*(float*)0x82C6324 = 0.0;
													*(float*)0x82C6328 = 0.0;
													break;
												case 8472:
													v28.X = v28.X + 0.009999999776482582;
													v28.Y = v28.Y - 0.0;
													*(float*)0x82C6320 = 270.0;
													*(float*)0x82C6324 = 0.0;
													*(float*)0x82C6328 = 0.0;
													break;
												default:
													if ( a1 < 8440 || a1 > 8448 )
													{
														if ( a1 < 7936 || a1 > 7939 )
														{
															if ( a1 < 7940 || a1 > 7942 )
															{
																if ( a1 < 8451 || a1 > 8452 )
																{
																	if ( a1 == 8459 )
																	{
																		v28.X = v28.X + 0.009999999776482582;
																		v28.Y = v28.Y + 0.05000000074505806;
																		*(float*)0x82C6320 = 270.0;
																		*(float*)0x82C6324 = 0.0;
																		*(float*)0x82C6328 = 0.0;
																	}
																	else if ( a1 < 8473 || a1 > 8478 )
																	{
																		if ( a1 == 7943 )
																		{
																			v28.Y = v28.Y - 0.02999999932944775;
																			v28.X = v28.X + 0.004999999888241291;
																			*(float*)0x82C6320 = 270.0;
																			*(float*)0x82C6324 = 0.0;
																			*(float*)0x82C6328 = 0.0;
																		}
																		else if ( a1 < 8453 || a1 > 8458 )
																		{
																			if ( a1 < 8465 || a1 > 8468 )
																			{
																				if ( a1 < 8469 || a1 > 8471 )
																				{
																					if ( a1 == 7948 )
																					{
																						v28.Y = v28.Y - 0.03999999910593033;
																						*(float*)0x82C6320 = 270.0;
																						*(float*)0x82C6324 = 0.0;
																						*(float*)0x82C6328 = 0.0;
																					}
																					else if ( a1 != 4814 && a1 != 4838 )
																					{
																						if ( a1 != 620 && a1 != 621 && a1 != 622 )
																						{
																							if ( a1 != 1203 && a1 != 1211 )
																							{
																								if ( (a1 < 1204 || a1 > 1205) && !gCustomGloves.CheckGloves(a1-ITEM_BASE_MODEL) ) //RF
																								{
																									if ( a1 == 7364 )
																									{
																										v28.Y = v28.Y + 0.009999999776482582;
																										v28.X = v28.X + 0.01499999966472387;
																										*(float*)0x82C6320 = -90.0;
																										*(float*)0x82C6324 = 0.0;
																										*(float*)0x82C6328 = 0.0;
																									}
																									else if ( a1 == 7365 )
																									{
																										v28.Y = v28.Y + 0.1500000059604645;
																										*(float*)0x82C6320 = 270.0;
																										*(float*)0x82C6324 = -10.0;
																										*(float*)0x82C6328 = 0.0;
																									}
																									else if ( a1 < 8881 || a1 > 8887 )
																									{
																										if ( a1 == 7450 )
																										{
																											v28.Y = v28.Y + 0.05000000074505806;
																											v28.X = v28.X + 0.004999999888241291;
																										}
																										else if ( a1 < 7962 || a1 > 7972 )
																										{
																											if ( a1 != 8499 && a1 != 8500 )
																											{
																												if ( sub_4E1250_Addr(a1 - ITEM_BASE_MODEL, 0) == -1 )
																												{
																													switch ( a1 )
																													{
																													case 8501:
																														v28.X = v28.X + 0.009999999776482582;
																														v28.Y = v28.Y - 0.009999999776482582;
																														break;
																													case 8502:
																														v28.X = v28.X + 0.009999999776482582;
																														v28.Y = v28.Y - 0.07000000029802322;
																														break;
																													case 8503:
																														v28.Y = v28.Y + 0.119999997317791;
																														break;
																													default:
																														if ( a1 < 8504 || a1 > 8507 )
																														{
																															switch ( a1 )
																															{
																															case 3767:
																																v28.X = v28.X + 0.009999999776482582;
																																v28.Y = v28.Y + 0.02999999932944775;
																																break;
																															case 1206:
																																v28.X = v28.X - 0.004999999888241291;
																																v28.Y = v28.Y + 0.01499999966472387;
																																*(float*)0x82C6320 = 0.0;
																																*(float*)0x82C6324 = 0.0;
																																*(float*)0x82C6328 = 0.0;
																																break; //RF
																															case 642:
																																v28.X = v28.X + 0.009999999776482582;
																																v28.Y = v28.Y + 0.05000000074505806;
																																*(float*)0x82C6320 = 90.0;
																																*(float*)0x82C6324 = 0.0;
																																*(float*)0x82C6328 = 0.0;
																																break;
																															}
																														}
																														else
																														{
																															v28.X = v28.X + 0.0;
																															v28.Y = v28.Y + 0.03999999910593033;
																														}
																														break;
																													}
																												}
																												else
																												{
																													*(float*)0x82C6320 = 270.0;
																													*(float*)0x82C6324 = -10.0;
																													*(float*)0x82C6328 = 0.0;
																													switch ( sub_4E1250_Addr(a1 - 1171, 0) )
																													{
																													case 17:
																													case 19:
																														*(float*)0x82C6320 = 270.0;
																														*(float*)0x82C6324 = -10.0;
																														*(float*)0x82C6328 = -45.0;
																														break;
																													case 5:
																													case 7:
																														v28.Y = v28.Y - 0.05000000074505806;
																														break;
																													case 11:
																														v28.Y = v28.Y - 0.05000000074505806;
																														*(float*)0x82C6320 = 270.0;
																														*(float*)0x82C6324 = 90.0;
																														*(float*)0x82C6328 = 0.0;
																														break;
																													default:
																														goto LABEL_516;
																													}
																												}
																											}
																											else
																											{
																												v28.Y = v28.Y + 0.05000000074505806;
																												*(float*)0x82C6320 = 270.0;
																												*(float*)0x82C6324 = 0.0;
																												*(float*)0x82C6328 = 0.0;
																											}
																										}
																										else
																										{
																											v28.Y = v28.Y + 0.01999999955296516;
																											*(float*)0x82C6320 = 270.0;
																											*(float*)0x82C6324 = 0.0;
																											*(float*)0x82C6328 = 0.0;
																										}
																									}
																									else
																									{
																										v28.X = v28.X + 0.02999999932944775;
																										v28.Y = v28.Y + 0.02999999932944775;
																										*(float*)0x82C6320 = 270.0;
																										*(float*)0x82C6324 = 0.0;
																										*(float*)0x82C6328 = 0.0;
																									}
																								}else if(gCustomGloves.CheckGloves(a1-ITEM_BASE_MODEL)){
																									v28.X = v28.X + 0.004999999888241291;
																									v28.Y = v28.Y + 0.01499999966472387;
																									*(float*)0x82C6320 = -90.0;
																									*(float*)0x82C6324 = 0.0;
																									*(float*)0x82C6328 = 0.0;
																								}
																								else
																								{
																									v28.X = v28.X + 0.002000000094994903; //RF
																									v28.Y = v28.Y + 0.01999999955296516;
																									*(float*)0x82C6320 = 0.0;
																									*(float*)0x82C6324 = 0.0;
																									*(float*)0x82C6328 = 0.0;
																								}
																							}
																							else
																							{
																								v28.X = v28.X + 0.004999999888241291;
																								v28.Y = v28.Y + 0.01499999966472387;
																								*(float*)0x82C6320 = -90.0;
																								*(float*)0x82C6324 = 0.0;
																								*(float*)0x82C6328 = 0.0;
																							}
																						}
																						else
																						{
																							v28.X = v28.X + 0.009999999776482582;
																							v28.Y = v28.Y + 0.07999999821186066;
																							*(float*)0x82C6320 = 0.0;
																							*(float*)0x82C6324 = 0.0;
																							*(float*)0x82C6328 = 0.0;
																						}
																					}
																					else
																					{
																						v28.Y = v28.Y + 0.03999999910593033;
																						*(float*)0x82C6320 = -90.0;
																						*(float*)0x82C6324 = 25.0;
																						*(float*)0x82C6328 = 0.0;
																					}
																				}
																				else
																				{
																					v28.X = v28.X + 0.0;
																					v28.Y = v28.Y + 0.05999999865889549;
																					*(float*)0x82C6320 = 270.0;
																					*(float*)0x82C6324 = 0.0;
																					*(float*)0x82C6328 = 0.0;
																				}
																			}
																			else
																			{
																				v28.X = v28.X + 0.0;
																				v28.Y = v28.Y + 0.05999999865889549;
																				*(float*)0x82C6320 = 270.0;
																				*(float*)0x82C6324 = 0.0;
																				*(float*)0x82C6328 = 0.0;
																			}
																		}
																		else
																		{
																			v28.X = v28.X + 0.0;
																			v28.Y = v28.Y + 0.05999999865889549;
																			*(float*)0x82C6320 = 270.0;
																			*(float*)0x82C6324 = 0.0;
																			*(float*)0x82C6328 = 0.0;
																		}
																	}
																	else
																	{
																		v28.X = v28.X + 0.0;
																		v28.Y = v28.Y + 0.05000000074505806;
																		*(float*)0x82C6320 = 270.0;
																		*(float*)0x82C6324 = 0.0;
																		*(float*)0x82C6328 = 0.0;
																	}
																}
																else
																{
																	v28.X = v28.X + 0.05000000074505806;
																	v28.Y = v28.Y + 0.008999999612569809;
																	*(float*)0x82C6320 = 270.0;
																	*(float*)0x82C6324 = 180.0;
																	*(float*)0x82C6328 = 45.0;
																}
															}
															else
															{
																v28.X = v28.X + 0.004999999888241291;
																v28.Y = v28.Y - 0.0;
																*(float*)0x82C6320 = 270.0;
																*(float*)0x82C6324 = 0.0;
																*(float*)0x82C6328 = 0.0;
															}
														}
														else
														{
															v28.X = v28.X + 0.02500000037252903;
															v28.Y = v28.Y - 0.03500000014901161;
															*(float*)0x82C6320 = 270.0;
															*(float*)0x82C6324 = 25.0;
															*(float*)0x82C6328 = 25.0;
														}
													}
													else
													{
														switch ( a1 )
														{
														case 8440:
															v28.X = v28.X + 0.004999999888241291;
															break;
														case 8441:
															v28.X = v28.X + 0.004999999888241291;
															v28.Y = v28.Y + 0.05000000074505806;
															*(float*)0x82C6320 = 0.0;
															*(float*)0x82C6324 = 0.0;
															*(float*)0x82C6328 = 30.0;
															break;
														case 8442:
														case 8443:
														case 8444:
														case 8445:
														case 8446:
														case 8447:
															v28.X = v28.X + 0.004999999888241291;
															v28.Y = v28.Y + 0.05000000074505806;
															*(float*)0x82C6320 = 0.0;
															*(float*)0x82C6324 = 0.0;
															*(float*)0x82C6328 = 30.0;
															break;
														case 8448:
															v28.X = v28.X + 0.004999999888241291;
															v28.Y = v28.Y + 0.05000000074505806;
															*(float*)0x82C6320 = 0.0;
															*(float*)0x82C6324 = 0.0;
															*(float*)0x82C6328 = 0.0;
															break;
														default:
															goto LABEL_516;
														}
													}
													break;
												}
											}
											else
											{
												v28.Y = v28.Y - 0.03999999910593033;
												v28.X = v28.X + 0.002000000094994903;
												*(float*)0x82C6320 = 270.0;
												*(float*)0x82C6324 = 0.0;
												*(float*)0x82C6328 = 0.0;
											}
										}
										else
										{
											v28.Y = v28.Y - 0.02999999932944775;
											*(float*)0x82C6320 = -90.0;
											*(float*)0x82C6324 = 0.0;
											*(float*)0x82C6328 = 0.0;
										}
									}
									else
									{
										v28.Y = v28.Y + 0.07000000029802322;
										*(float*)0x82C6320 = 270.0;
										*(float*)0x82C6324 = 180.0;
										*(float*)0x82C6328 = 0.0;
										if ( a6 != 1 )
											*(float*)0x82C6324 = *(float*)0x5EF5A1C * 0.2000000029802322;
									}
									break;
								}
							}
							else
							{
								v28.X = v28.X + 0.007000000216066837;
								v28.Y = v28.Y - 0.03500000014901161;
								*(float*)0x82C6320 = 270.0;
								*(float*)0x82C6324 = 0.0;
								*(float*)0x82C6328 = 0.0;
							}
						}
						else
						{
							v28.X = v28.X + 0.01999999955296516;
							v28.Y = v28.Y + 0.1299999952316284;
							*(float*)0x82C6320 = 270.0;
							*(float*)0x82C6324 = 0.0;
							*(float*)0x82C6328 = 0.0;
						}
					}
					else
					{
						v28.X = v28.X + 0.009999999776482582;
						v28.Y = v28.Y + 0.03999999910593033;
						*(float*)0x82C6320 = 270.0;
						*(float*)0x82C6324 = 0.0;
						*(float*)0x82C6328 = 0.0;
					}
					break;
				}
			}
			else
			{
				*(float*)0x82C6320 = 0.0;
				*(float*)0x82C6324 = 0.0;
				*(float*)0x82C6328 = 0.0;
			}
		}
		else
		{
			*(float*)0x82C6320 = 0.0;
			*(float*)0x82C6324 = 0.0;
			*(float*)0x82C6328 = 0.0;
		}
	}
	else if(a1 != 1171)
	{
		*(float*)0x82C6320 = 10.0;
		*(float*)0x82C6324 = -10.0;
		*(float*)0x82C6328 = 10.0;
	}
//--- Termina Segunda validación

LABEL_516:
	if ( a1 > 2212 )
	{
		switch ( a1 )
		{
		case 3761:
			*(float*)0x82C6320 = 180.0;
			*(float*)0x82C6324 = 90.0;
			*(float*)0x82C6328 = 10.0;
			break;
		case 3762:
			*(float*)0x82C6320 = 180.0;
			*(float*)0x82C6324 = 90.0;
			*(float*)0x82C6328 = 10.0;
			break;
		case 3763:
			*(float*)0x82C6320 = 180.0;
			*(float*)0x82C6324 = 90.0;
			*(float*)0x82C6328 = 10.0;
			break;
		}
	}
	else if ( a1 == 2212 )
	{
		v28.X = v28.X - 0.01999999955296516;
		v28.Y = v28.Y + 0.03999999910593033;
		*(float*)0x82C6320 = 180.0;
		*(float*)0x82C6324 = 270.0;
		*(float*)0x82C6328 = 15.0;
	}
	else if ( a1 > 1199 )
	{
		if ( a1 == 2211 )
		{
			v28.X = v28.X - 0.01999999955296516;
			*(float*)0x82C6320 = 180.0;
			*(float*)0x82C6324 = 270.0;
			*(float*)0x82C6328 = 15.0;
		}
	}
	else
	{
		switch ( a1 )
		{
		case 1199:
			v28.Y = v28.Y + 0.01999999955296516;
			*(float*)0x82C6320 = 180.0;
			*(float*)0x82C6324 = 270.0;
			*(float*)0x82C6328 = 10.0;
			break;
		case 1197:
			v28.X = v28.X - 0.01999999955296516;
			v28.Y = v28.Y + 0.03999999910593033;
			*(float*)0x82C6320 = 180.0;
			*(float*)0x82C6324 = 270.0;
			*(float*)0x82C6328 = 10.0;
			break;
		case 1198:
			*(float*)0x82C6320 = 180.0;
			*(float*)0x82C6324 = 270.0;
			*(float*)0x82C6328 = 15.0;
			break;
		}
	}
	if ( a1 == 3738 )
	{
		*(float*)0x82C6320 = 0.0;
		*(float*)0x82C6324 = 0.0;
		*(float*)0x82C6328 = 205.0;
	}
	if ( a1 > 8360 )
	{
		if ( a1 != 8361 && a1 != 8493 )
			goto LABEL_553;
		goto LABEL_552;
	}
	if ( a1 == 8360 )
	{
		v28.X = v28.X + 0.004999999888241291;
		v28.Y = v28.Y - 0.004999999888241291;
		goto LABEL_553;
	}
	if ( a1 <= 8353 )
	{
		if ( a1 < 8352 )
		{
			if ( a1 >= 7323 && a1 <= 7326 )
			{
				v28.X = v28.X + 0.004999999888241291;
				v28.Y = v28.Y - 0.01999999955296516;
			}
			goto LABEL_553;
		}
LABEL_552:
		v28.X = v28.X + 0.004999999888241291;
		v28.Y = v28.Y + 0.01499999966472387;
	}
LABEL_553:
	if ( a6 == 1 )
		*(float*)0x82C6324 = *(float*)0x5EF5A1C * 0.449999988079071;
	*(DWORD*)0x82C6248 = a1;
	if ( (a1 < 4755 || *(DWORD*)0x82C6248 >= 7315)
		&& *(DWORD*)0x82C6248 != 620
		&& *(DWORD*)0x82C6248 != 621
		&& *(DWORD*)0x82C6248 != 622
		&& *(DWORD*)0x82C6248 != 642 )
	{
		if ( *(DWORD*)0x82C6248 == 8351 )
		{
			if ( v36 )
			{
				if ( v36 == 2 )
				{
					*(DWORD*)0x82C6248 = 9510;
					a1 = 9510;
				}
			}
			else
			{
				*(DWORD*)0x82C6248 = 9509;
				a1 = 9509;
			}
		}
	}
	else
	{
		*(DWORD*)0x82C6248 = 1163;
	}
	v7 = *(DWORD*)0x82C6248;
	v8 = sub_4CDA10_Addr();
	v27 = sub_969C50_Addr(v8, v7);
	if ( v27 )
	{
		*(WORD*)(v27 + 160) = 0;

		*(float*)0x82C62A4 = 0.0;
		*(float*)0x82C62A8 = 0.0;
		v9 = 0;
		*(WORD*)0x82C622C = 0;

		if ( a1 < 4755 || a1 >= 5267 )
		{
			if ( a1 < 5267 || a1 >= 5779 )
			{
				if ( a1 < 6291 || a1 >= 6803 )
				{
					if ( a1 < 5779 || a1 >= 6291 )
					{
						*(float *)(v27 + 132) = 0.0;
					}
					else
					{
						v9 = v27;
						*(float *)(v27 + 132) = -50.0;
					}
				}
				else
				{
					*(float *)(v27 + 132) = -70.0;
				}
			}
			else
			{
				*(float *)(v27 + 132) = -100.0;
				if ( sub_5C9370_Addr(a1 - 1171, 0) )
				{
					v9 = v27;
					*(float *)(v27 + 132) = *(float *)(v27 + 132) - 13.0;
				}
			}
		}
		else
		{
			*(float *)(v27 + 132) = -160.0;
			v10 = sub_5C9370_Addr(a1 - 1171, 0);
			v9 = v10;
			if ( v10 )
				*(float *)(v27 + 132) = *(float *)(v27 + 132) - 10.0;
			if ( a1 == 4820 || a1 == 4825 )
				v28.X = v28.X + 0.03999999910593033;
		}
		v32 = 0.0;
		if ( a1 < 4755 || a1 >= 7315 )
		{
			if ( a1 == 7321 )
			{
				v32 = 0.0015;
			}
			else if ( sub_4E1250_Addr(a1 - 1171, 0) == -1 )
			{
				if ( a1 < 7347 || a1 > 7349 )
				{
					if ( a1 < 7375 || a1 > 7380 )
					{
						if ( a1 < 7385 || a1 > 7389 )
						{
							if ( a1 < 7415 || a1 > 7444 )
							{
								if ( a1 < 7315 || a1 >= 7827 )
								{
									if ( a1 != 8384 && a1 != 8388 )
									{
										if ( a1 < 8385 || a1 > 8387 )
										{
											if ( a1 == 8389 )
											{
												v32 = 0.001;
											}
											else if ( a1 < 8371 || a1 > 8373 )
											{
												if ( a1 < 9530 || a1 > 9532 )
												{
													switch ( a1 )
													{
													case 8360:
														v32 = 0.0020000001;
														break;
													case 3238:
														v32 = 0.0020000001;
														break;
													case 9520:
														v32 = 0.0015;
														break;
													case 7831:
														v32 = 0.0015;
														break;
													case 7832:
														v32 = 0.0049999999;
														break;
													case 7857:
														v32 = 0.0020000001;
														break;
													case 9525:
														v32 = 0.0020000001;
														break;
													case 7843:
														v32 = 0.0020000001;
														break;
													case 7844:
														v32 = 0.0018;
														break;
													case 7845:
														v32 = 0.0018;
														break;
													case 7873:
														v32 = 0.0018;
														break;
													case 7874:
														v32 = 0.0018;
														break;
													case 7875:
														v32 = 0.0018;
														break;
													case 8393:
														v32 = 0.0024000001;
														break;
													case 8397:
														v32 = 0.0012000001;
														break;
													default:
														if ( a1 != 8398 && a1 != 8399 )
														{
															if ( a1 != 8400 && a1 != 8401 )
															{
																if ( a1 == 8392 )
																{
																	v32 = 0.00078;
																}
																else if ( a1 != 7870 && a1 != 7871 && a1 != 7872 )
																{
																	if ( a1 < 8409 || a1 > 8410 )
																	{
																		if ( a1 < 8411 || a1 > 8416 )
																		{
																			if ( a1 == 7886 )
																			{
																				v32 = 0.00079999998;
																			}
																			else if ( a1 < 7881 || a1 > 7885 )
																			{
																				if ( a1 < 8417 || a1 > 8421 )
																				{
																					switch ( a1 )
																					{
																					case 7887:
																						v32 = 0.0049999999;
																						break;
																					case 7888:
																						v32 = 0.0018;
																						break;
																					case 8422:
																						v32 = 0.00089999998;
																						break;
																					default:
																						if ( a1 != 7870 && a1 != 7871 && a1 != 7872 )
																						{
																							switch ( a1 )
																							{
																							case 8431:
																								v32 = 0.0024000001;
																								break;
																							case 8432:
																								v32 = 0.0024000001;
																								break;
																							case 8434:
																								v32 = 0.0024000001;
																								break;
																							case 8433:
																								v32 = 0.0022;
																								break;
																							case 8423:
																								v32 = 0.0031000001;
																								break;
																							case 8424:
																								v32 = 0.0044;
																								break;
																							case 8425:
																								v32 = 0.0031000001;
																								break;
																							case 8426:
																								v32 = 0.0060999999;
																								break;
																							case 8427:
																								v32 = 0.0035000001;
																								break;
																							case 8428:
																								v32 = 0.0035000001;
																								break;
																							case 8429:
																								v32 = 0.0035000001;
																								break;
																							default:
																								if ( a1 < 7889 || a1 > 7890 )
																								{
																									if ( a1 < 8436 || a1 > 8437 )
																									{
																										if ( a1 == 8435 )
																										{
																											v32 = 0.0027999999;
																										}
																										else if ( a1 != 7891 && a1 != 7892 )
																										{
																											switch ( a1 )
																											{
																											case 7894:
																												v32 = 0.0015;
																												break;
																											case 7907:
																												v32 = 0.0020000001;
																												break;
																											case 7895:
																												v32 = 0.0026;
																												break;
																											case 7903:
																												v32 = 0.0026;
																												break;
																											case 7896:
																												v32 = 0.0023000001;
																												break;
																											case 7897:
																												v32 = 0.0018;
																												break;
																											case 7908:
																												v32 = 0.0012000001;
																												break;
																											case 7909:
																												v32 = 0.0012000001;
																												break;
																											case 7920:
																												v32 = 0.0020999999;
																												break;
																											case 7921:
																												v32 = 0.0020999999;
																												break;
																											case 1190:
																												if ( a2 < 0 )
																												{
																													v32 = 0.001;
																													a2 = 0;
																												}
																												else
																												{
																													v32 = 0.0024999999;
																												}
																												break;
																											case 3741:
																												if ( a2 < 0 )
																												{
																													v32 = 0.001;
																													a2 = 0;
																												}
																												else
																												{
																													v32 = 0.0019;
																												}
																												break;
																											case 3237:
																												if ( a2 < 0 )
																												{
																													v32 = 0.0015;
																													a2 = 0;
																												}
																												else
																												{
																													v32 = 0.0024999999;
																												}
																												break;
																											default:
																												if ( (a1 < 2203 || a1 > 2206) && a1 != 2216 )
																												{
																													switch ( a1 )
																													{
																													case 2207:
																														v32 = 0.0024999999;
																														break;
																													case 2213:
																														v32 = 0.0024000001;
																														break;
																													case 9521:
																														v32 = 0.0012000001;
																														break;
																													case 9522:
																														v32 = 0.0024999999;
																														break;
																													case 9523:
																														v32 = 0.0027999999;
																														break;
																													case 9524:
																														v32 = 0.0023000001;
																														break;
																													default:
																														if ( a1 < 8361 || a1 >= 8364 )
																														{
																															if ( a1 < 8364 || a1 >= 8366 )
																															{
																																switch ( a1 )
																																{
																																case 8402:
																																	v32 = 0.0070000002;
																																	break;
																																case 8438:
																																	v32 = 0.0024999999;
																																	break;
																																case 8391:
																																	v32 = 0.0014;
																																	break;
																																case 7865:
																																	v32 = 0.0024999999;
																																	break;
																																case 8380:
																																	v32 = 0.0035000001;
																																	break;
																																case 8381:
																																	v32 = 0.0049999999;
																																	break;
																																case 8382:
																																	v28.Y = v28.Y + -0.004999999888241291;
																																	v32 = 0.0035000001;
																																	break;
																																case 8383:
																																	v28.Y = v28.Y + -0.004999999888241291;
																																	v32 = 0.0040000002;
																																	break;
																																case 8346:
																																	v32 = 0.0024999999;
																																	break;
																																default:
																																	if ( a1 != 7870
																																		&& a1 != 7871
																																		&& a1 != 7872 )
																																	{
																																		switch ( a1 )
																																		{
																																		case 7834:
																																			v32 = 0.0024999999;
																																			break;
																																		case 7838:
																																			v32 = 0.0024999999;
																																			break;
																																		case 7859:
																																			v32 = 0.0019;
																																			break;
																																		case 7860:
																																			v32 = 0.0040000002;
																																			break;
																																		case 7861:
																																			v32 = 0.0040000002;
																																			break;
																																		case 7862:
																																			v32 = 0.0040000002;
																																			break;
																																		case 7863:
																																			v32 = 0.0070000002;
																																			break;
																																		case 7864:
																																			v32 = 0.0049999999;
																																			break;
																																		case 3240:
																																			v32 = 0.0022;
																																			break;
																																		default:
																																			if ( (a1 < 8394 || a1 > 8396)
																																				&& (a1 < 8496 || a1 > 8498) )
																																			{
																																				switch ( a1 )
																																				{
																																				case 7876:
																																					v32 = 0.0013;
																																					break;
																																				case 7877:
																																					v32 = 0.003;
																																					break;
																																				case 7878:
																																					v32 = 0.003;
																																					break;
																																				default:
																																					if ( a1 != 8403 && a1 != 8492 )
																																					{
																																						switch ( a1 )
																																						{
																																						case 8404:
																																							v32 = 0.003;
																																							break;
																																						case 8405:
																																							v32 = 0.0035000001;
																																							break;
																																						case 8406:
																																							v32 = 0.0035000001;
																																							break;
																																						case 8407:
																																							v32 = 0.003;
																																							break;
																																						case 7879:
																																							v32 = 0.0049999999;
																																							break;
																																						case 7880:
																																							v32 = 0.0049999999;
																																							break;
																																						case 1195:
																																							v32 = 0.0027999999;
																																							break;
																																						case 3241:
																																							v32 = 0.0020000001;
																																							break;
																																						case 3242:
																																							v32 = 0.0031999999;
																																							break;
																																						default:
																																							if ( a1 != 7841 && a1 != 7842 )
																																							{
																																								if ( a1 == 8439 )
																																								{
																																									v32 = 0.0040000002;
																																								}
																																								else if ( a1 == 8495 )
																																								{
																																									v32 = 0.0038999999;
																																								}
																																								else if ( a1 < 8339 || a1 >= 8851 )
																																								{
																																									if ( a1 < 2707 || a1 >= 3219 )
																																									{
																																										if ( a1 < 3731 || a1 >= 4243 )
																																										{
																																											switch ( a1 )
																																											{
																																											case 3234:
																																												v32 = 0.0011;
																																												break;
																																											case 3226:
																																												v32 = 0.0012000001;
																																												break;
																																											case 9515:
																																												v32 = 0.0038999999;
																																												break;
																																											case 9517:
																																												v32 = 0.0015;
																																												break;
																																											case 9518:
																																												v32 = 0.0019;
																																												break;
																																											default:
																																												v32 = 0.0024999999;
																																												break;
																																											}
																																										}
																																										else if ( a1 < 3745 || a1 > 3751 )
																																										{
																																											if ( (a1 < 3752 || a1 > 3760) && a1 != 3771 )
																																											{
																																												switch ( a1 )
																																												{
																																												case 3764:
																																													v32 = 0.0027999999;
																																													break;
																																												case 3765:
																																													v32 = 0.0027999999;
																																													break;
																																												case 3770:
																																													v32 = 0.0027999999;
																																													break;
																																												default:
																																													v32 = 0.0022;
																																													break;
																																												}
																																											}
																																											else
																																											{
																																												v32 = 0.0040000002;
																																											}
																																										}
																																										else
																																										{
																																											v32 = 0.0027999999;
																																										}
																																									}
																																									else if ( a1 == 2717 )
																																									{
																																										v32 = 0.0018;
																																									}
																																									else if ( a1 == 2718 )
																																									{
																																										v32 = 0.0024999999;
																																									}
																																									else
																																									{
																																										v32 = 0.0020999999;
																																									}
																																								}
																																								else
																																								{
																																									v32 = 0.0035000001;
																																								}
																																							}
																																							else
																																							{
																																								v32 = 0.003;
																																							}
																																							break;
																																						}
																																					}
																																					else
																																					{
																																						v32 = 0.003;
																																					}
																																					break;
																																				}
																																			}
																																			else
																																			{
																																				v32 = 0.0014;
																																			}
																																			break;
																																		}
																																	}
																																	else
																																	{
																																		v32 = 0.0020999999;
																																	}
																																	break;
																																}
																															}
																															else
																															{
																																v32 = 0.0027999999;
																															}
																														}
																														else
																														{
																															v32 = 0.0024999999;
																														}
																														break;
																													}
																												}
																												else
																												{
																													v32 = 0.003;
																												}
																												break;
																											}
																										}
																										else if ( a1 == 7891 )
																										{
																											v32 = 0.00050000002;
																										}
																										else if ( a1 == 7892 )
																										{
																											v32 = 0.0016;
																										}
																									}
																									else
																									{
																										v32 = 0.003;
																									}
																								}
																								else
																								{
																									v32 = 0.0020000001;
																								}
																								break;
																							}
																						}
																						else
																						{
																							v32 = 0.0020999999;
																						}
																						break;
																					}
																				}
																				else
																				{
																					v32 = 0.0024999999;
																				}
																			}
																			else
																			{
																				v32 = 0.0040000002;
																			}
																		}
																		else
																		{
																			v32 = 0.0024999999;
																		}
																	}
																	else
																	{
																		v32 = 0.0027999999;
																	}
																}
																else
																{
																	v32 = 0.0020999999;
																}
															}
															else
															{
																v32 = 0.00089999998;
															}
														}
														else
														{
															v32 = 0.001;
														}
														break;
													}
												}
												else
												{
													v32 = 0.0020000001;
													if ( a1 == 9530 )
														v28.Y = v28.Y + 0.07999999821186066;
													else
														v28.Y = v28.Y + 0.05999999865889549;
													*(float*)0x82C6320 = 0.0;
													*(float*)0x82C6328 = 0.0;
												}
											}
											else
											{
												v32 = 0.0020000001;
												v28.Y = v28.Y + 0.05000000074505806;
												*(float*)0x82C6320 = 0.0;
												*(float*)0x82C6328 = 0.0;
											}
										}
										else
										{
											v32 = 0.0024999999;
										}
									}
									else
									{
										v32 = 0.003;
									}
								}
								else
								{
									v32 = 0.0020000001;
								}
							}
							else
							{
								v32 = 0.0017;
							}
						}
						else
						{
							v32 = 0.0017;
						}
					}
					else
					{
						v32 = 0.0022;
					}
				}
				else
				{
					v32 = 0.001;
					v28.Y = v28.Y - 0.05000000074505806;
				}
			}
			else
			{
				v32 = 0.0040000002;
				switch ( sub_4E1250_Addr(a1 - 1171, 0) )
				{
				case 17:
					v28.X = v28.X - 0.05000000074505806;
					v32 = 0.003;
					break;
				case 19:
					v28.X = v28.X - 0.05000000074505806;
					v32 = 0.0040000002;
					break;
				case 7:
					v28.Y = v28.Y + 0.05000000074505806;
					v32 = 0.0024999999;
					break;
				case 15:
					v28.Y = v28.Y + 0.02500000037252903;
					v32 = 0.0020000001;
					break;
				case 9:
					v28.Y = v28.Y + 0.05000000074505806;
					v32 = 0.0035999999;
					break;
				case 5:
					v28.Y = v28.Y + 0.02500000037252903;
					v32 = 0.0035000001;
					break;
				case 11:
					v28.Y = v28.Y + 0.05000000074505806;
					v32 = 0.0035000001;
					break;
				case 13:
					v32 = 0.0049999999;
					break;
				default:
					break;
				}
			}
			if ( a1 >= 7910 && a1 <= 7920 )
				v32 = 0.0020000001;
			if ( a1 == 9519 )
			{
				v32 = 0.001;
			}
			else if ( (a1 < 8870 || a1 > 8878) && a1 != 8490 && a1 != 8491 )
			{
				switch ( a1 )
				{
				case 7893:
					v32 = 0.0020000001;
					break;
				case 8479:
					v32 = 0.0026;
					break;
				case 7949:
					v32 = 0.0033;
					break;
				case 7950:
					v32 = 0.00089999998;
					break;
				default:
					if ( a1 < 8484 || a1 > 8489 )
					{
						if ( a1 < 7952 || a1 > 7954 )
						{
							switch ( a1 )
							{
							case 7955:
								v32 = 0.0035000001;
								break;
							case 7956:
								v32 = 0.0035000001;
								break;
							case 7961:
								v32 = 0.0033;
								break;
							case 7957:
								v32 = 0.0031999999;
								break;
							case 7958:
								v32 = 0.0033;
								break;
							case 7959:
								v32 = 0.0024999999;
								break;
							case 7960:
								v32 = 0.0033;
								break;
							default:
								if ( a1 != 7898 && a1 != 7899 && a1 != 7900 && a1 != 7901 && a1 != 7902 )
								{
									if ( a1 == 3243 )
									{
										v32 = 0.0023000001;
									}
									else if ( a1 != 7924 && a1 != 7925 && a1 != 8430 )
									{
										switch ( a1 )
										{
										case 8449:
											v32 = 0.0040000002;
											break;
										case 7934:
											v32 = 0.0034;
											break;
										case 8472:
											v32 = 0.003;
											break;
										case 7932:
											v32 = 0.0020000001;
											break;
										default:
											if ( a1 < 8440 || a1 > 8448 )
											{
												if ( a1 == 7933 )
												{
													v32 = 0.0015;
												}
												else if ( a1 == 7445 )
												{
													v32 = 0.0012000001;
												}
												else if ( a1 < 8473 || a1 > 8478 )
												{
													if ( a1 < 7936 || a1 > 7939 )
													{
														if ( a1 < 7940 || a1 > 7942 )
														{
															if ( a1 < 8451 || a1 > 8452 )
															{
																if ( a1 == 7943 )
																{
																	v32 = 0.0020999999;
																}
																else if ( a1 < 8453 || a1 > 8458 )
																{
																	if ( a1 < 8465 || a1 > 8468 )
																	{
																		if ( a1 < 8469 || a1 > 8471 )
																		{
																			if ( a1 == 7948 )
																			{
																				v32 = 0.0018;
																			}
																			else if ( a1 == 7951 )
																			{
																				v32 = 0.0018;
																			}
																			else if ( a1 < 7364 || a1 > 7365 )
																			{
																				if ( a1 == 7450 )
																				{
																					v32 = 0.0012000001;
																				}
																				else if ( (a1 < 1203 || a1 > 1205 ) && a1 != 1211 ) //RF
																				{
																					if ( a1 < 8881 || a1 > 8887 )
																					{
																						if ( a1 != 620 && a1 != 622 && a1 != 621 )
																						{
																							if ( a1 == 8495 )
																							{
																								v32 = 0.0024999999;
																							}
																							else if ( a1 < 7962 || a1 > 7972 )
																							{
																								if ( a1 != 8499 && a1 != 8500 )
																								{
																									if ( a1 != 4817 && a1 != 4818 && a1 != 4820 && a1 != 4825 )
																									{
																										if ( a1 == 8501 )
																										{
																											v32 = 0.0040000002;
																										}
																										else if ( a1 < 8502 || a1 > 8507 )
																										{
																											switch ( a1 )
																											{
																											case 3767:
																												v32 = 0.0023000001;
																												break;
																											case 1206:
																												v32 = 0.003; //RF
																												break;
																											case 642:
																												v9 = v27;
																												*(float *)(v27 + 132) = -100.0;
																												v32 = 0.0038999999;
																												break;
																											}
																										}
																										else
																										{
																											v32 = 0.0041999999;
																										}
																									}
																									else
																									{
																										v32 = 0.001;
																									}
																								}
																								else
																								{
																									v32 = 0.001;
																								}
																							}
																							else
																							{
																								v32 = 0.001;
																							}
																						}
																						else
																						{
																							*(float *)(v27 + 132) = -100.0;
																							v32 = 0.0038999999;
																						}
																					}
																					else
																					{
																						v32 = 0.0023000001;
																					}
																				}
																				else
																				{
																					v32 = 0.0035000001;
																				}
																			}
																			else
																			{
																				v32 = 0.0020000001;
																			}
																		}
																		else
																		{
																			v32 = 0.0038000001;
																		}
																	}
																	else
																	{
																		v32 = 0.0038000001;
																	}
																}
																else
																{
																	v32 = 0.0038000001;
																}
															}
															else
															{
																v32 = 0.0031999999;
															}
														}
														else
														{
															v32 = 0.0018;
														}
													}
													else
													{
														v32 = 0.0044999998;
													}
												}
												else
												{
													v32 = 0.0049999999;
												}
											}
											else
											{
												v9 = a1 - 8440;
												switch ( a1 )
												{
												case 8440:
													v32 = 0.0040000002;
													break;
												case 8441:
													v32 = 0.0049999999;
													break;
												case 8442:
												case 8443:
												case 8444:
												case 8445:
												case 8446:
												case 8447:
													v32 = 0.0040000002;
													break;
												case 8448:
													v32 = 0.003;
													break;
												default:
													goto LABEL_1089;
												}
											}
											break;
										}
									}
									else
									{
										v32 = 0.0027999999;
									}
								}
								else
								{
									v32 = 0.0019;
								}
								break;
							}
						}
						else
						{
							v32 = 0.0013;
						}
					}
					else
					{
						v32 = 0.0018;
					}
					break;
				}
			}
			else
			{
				v32 = 0.0023000001;
			}
		}
		else
		{
			if ( a1 < 4755 || a1 >= 5267 )
			{
				if ( a1 < 5267 || a1 >= 5779 )
				{
					if ( a1 < 6291 || a1 >= 6803 )
					{
						if ( a1 < 5779 || a1 >= 6291 )
						{
							if ( a1 < 6803 || a1 >= 7315 )
							{
								switch ( a1 )
								{
								case 5297:
									v32 = 0.0035000001;
									break;
								case 5299:
									v32 = 0.0035000001;
									break;
								case 5296:
									v32 = 0.0033;
									break;
								}
							}
							else
							{
								v32 = 0.0031999999;
							}
						}
						else
						{
							v32 = 0.0033;
						}
					}
					else
					{
						v32 = 0.0038000001;
					}
				}
				else
				{
					v32 = 0.0038999999;
				}
			}
			else
			{
				if ( a1 >= 4794 && a1 <= 4799 || a1 == 4837 )
					v17 = 0.0070000002;
				else
					v17 = 0.0038999999;
				v32 = v17;
				if ( a1 == 4786 )
					v32 = 0.0070000002;
				if ( a1 == 4820 || a1 == 4825 )
					v32 = 0.0070000002;
			}
			switch ( a1 )
			{
			case 5301:
				v32 = 0.0031999999;
				break;
			case 5302:
				v32 = 0.0031999999;
				break;
			case 6329:
				v32 = 0.0031999999;
				break;
			}
		}
LABEL_1089:
		sub_5440B0_Addr(v27, v9, (int)0x7BC08A0,*(float*)0x82C62A4,*(float*)0x82C62A8,*(WORD*)0x82C622C,(int)0x82C6320,(int)0x82C632C,0,0);
		sub_4CC650_Addr((int)&v19);
		v19.m_Model.Unknown48 = a1;
		sub_5F58E0_Addr(&v19.m_Model);
		v19.m_Model.Unknown9 = 0;
		v19.Class = 2;
		v18 = 0;
		v22 = 0;
		pGetPosFromAngle(&v28, &v18, &v22);
		v11 = (double)v22;
		v12 = (double)v18;
		v13 = sub_861110_Addr();

		//g_Console.AddMessage(3,"X = %d, Y = %d", v18,v22);

		sub_861900_Addr((int)v13);

		if ( sub_943A20_Addr(v12, v11) )
		{
			v14 = sub_861110_Addr();
			v15 = sub_861900_Addr((int)v14);
			v16 = sub_5D65E0_Addr(v15);
			v19.m_Model.Scale = v16 * v32;
		}
		else
		{
			v19.m_Model.Scale = v32;
		}

//-- INICIA LO CUSTOM
		

		if(posicionGlobal){
			v28.X += posicionGlobal->translationX;
			v28.Y += posicionGlobal->translationY;

			v19.m_Model.Scale *= posicionGlobal->Scale;

			v19.m_Model.Unknown216.X -= 0.5;
			v19.m_Model.Unknown204.X -= 1.5;

			if ((X == 498 || X == 618) && Y == 139)
			{
				v28.X -= 0.060;
			}
		}else{

			if (gCustomGloves.CheckGloves(a1-ITEM_BASE_MODEL))
			{
				v28.X -= 0.04;
				v28.Y += 0.08;

				v19.m_Model.Scale *= 1.3;

				v19.m_Model.Unknown216.X -= 0.5;
				v19.m_Model.Unknown204.X -= 1.5;

				if ((X == 498 || X == 618) && Y == 139)
				{
					v28.X -= 0.060;
				}
			}
			//-- customBow
			else if(gCustomBow.CheckCustomBow(a1 - ITEM_BASE_MODEL)){
				v28.X += -0.1;
				v28.Y += 0.09;
			}
			else if(gCustomBow.CheckCustomCross(a1 - ITEM_BASE_MODEL)){
				v28.X += 0.0;
				v28.Y += 0.03;
			}
			else if (gCustomPet2.CheckCustomPetByItem(a1 - 1171))
            {
                v28.X += gCustomPet2.GetScalePosX(a1 - 1171);
                v28.Y -= gCustomPet2.GetScalePosY(a1 - 1171);
                v19.m_Model.Scale *= gCustomPet2.GetScaleInv(a1 - 1171);
            }
		}

		*(VAngle *)&v19.m_Model.VecPos = v28;

		v26 = *(float *)&v19.m_Model.Unknown152;

		v37.X = 1.0;
		v37.Y = 1.0;
		v37.Z = 1.0;
		
		int ItemGroup = (a1 - 1171) / 512;
		int ItemID = (a1 - 1171) % 512;

		if ( ItemGroup >= 7 && ItemGroup <= 11 && ItemID >= 62 && ItemID <= 72 )
		{
			sub_60FC70_Addr((int)&v19.m_Model, a1, 0, (int)&v37, v26, a2, a3, 10124, 1, 1, 1, 0, 2);
		}
		else
		{
			sub_60FC70_Addr((int)&v19.m_Model, a1, 0, (int)&v37, v26, a2, a3, a4, 1, 1, 1, 0, 2);
		}

		sub_4CC720_Addr((int)&v19);
	}
}
