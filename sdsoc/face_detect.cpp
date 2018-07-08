/*===============================================================*/
/*                                                               */
/*                      face_detect.cpp                          */
/*                                                               */
/*     Hardware function for the Face Detection application.     */
/*                                                               */
/*===============================================================*/

#include "../host/typedefs.h"

#include "haar_mapping.h"
#include "stdio.h"


uint5_t get_bank(uint10_t addr)
{
  #pragma HLS inline
  return bank_mapping[addr];
}

uint5_t get_offset(uint10_t addr)
{
  #pragma HLS inline
  return offset_mapping[addr];
}

uint18_t get_data0(int offset, uint18_t aa[ROWS*COLS])
{
  #pragma HLS inline
  uint18_t a;
  switch (offset)
  {
    case 0: a = aa[19 ]; break;
    case 1: a = aa[29 ]; break;
    case 2: a = aa[52 ]; break;
    case 3: a = aa[100]; break;
    case 4: a = aa[132]; break;
    case 5: a = aa[161]; break;
    case 6: a = aa[193]; break;
    case 7: a = aa[220]; break;
    case 8: a = aa[239]; break;
    case 9: a = aa[253]; break;
    case 10:a = aa[284]; break;
    case 11:a = aa[309]; break;
    case 12:a = aa[362]; break;
    case 13:a = aa[385]; break;
    case 14:a = aa[396]; break;
    case 15:a = aa[447]; break;
    case 16:a = aa[448]; break;
    case 17:a = aa[449]; break;
    case 18:a = aa[451]; break;
    case 19:a = aa[466]; break;
    case 20:a = aa[492]; break;
    case 21:a = aa[531]; break;
    case 22:a = aa[562]; break;
    default: a = 0; break;
  }; 

  return a;
}

uint18_t get_data1(int offset, uint18_t aa[ROWS*COLS])
{
  #pragma HLS inline
  uint18_t a;
  switch (offset)
  {
    case 0: a = aa[7  ]; break;
    case 1: a = aa[18 ]; break;
    case 2: a = aa[65 ]; break;
    case 3: a = aa[72 ]; break;
    case 4: a = aa[148]; break;
    case 5: a = aa[149]; break;
    case 6: a = aa[153]; break;
    case 7: a = aa[164]; break;
    case 8: a = aa[191]; break;
    case 9: a = aa[208]; break;
    case 10:a = aa[229]; break;
    case 11:a = aa[240]; break;
    case 12:a = aa[251]; break;
    case 13:a = aa[256]; break;
    case 14:a = aa[280]; break;
    case 15:a = aa[384]; break;
    case 16:a = aa[450]; break;
    case 17:a = aa[478]; break;
    case 18:a = aa[506]; break;
    case 19:a = aa[517]; break;
    case 20:a = aa[527]; break;
    case 21:a = aa[542]; break;
    case 22:a = aa[554]; break;
    case 23:a = aa[573]; break;
    case 24:a = aa[576]; break;
    case 25:a = aa[621]; break;
    default: a = 0; break;
  }; 
  return a;
}

uint18_t get_data2(int offset, uint18_t aa[ROWS*COLS])
{
  #pragma HLS inline
  uint18_t a;
  switch (offset)
  {
    case 0: a = aa[9  ]; break;
    case 1: a = aa[20 ]; break;
    case 2: a = aa[28 ]; break;
    case 3: a = aa[48 ]; break;
    case 4: a = aa[74 ]; break;
    case 5: a = aa[97 ]; break;
    case 6: a = aa[168]; break;
    case 7: a = aa[187]; break;
    case 8: a = aa[188]; break;
    case 9: a = aa[213]; break;
    case 10:a = aa[233]; break;
    case 11:a = aa[260]; break;
    case 12:a = aa[261]; break;
    case 13:a = aa[277]; break;
    case 14:a = aa[303]; break;
    case 15:a = aa[314]; break;
    case 16:a = aa[329]; break;
    case 17:a = aa[356]; break;
    case 18:a = aa[375]; break;
    case 19:a = aa[376]; break;
    case 20:a = aa[452]; break;
    case 21:a = aa[499]; break;
    case 22:a = aa[519]; break;
    case 23:a = aa[529]; break;
    case 24:a = aa[536]; break;
    case 25:a = aa[551]; break;
    case 26:a = aa[567]; break;
    case 27:a = aa[597]; break;
    case 28:a = aa[615]; break;
    default: a = 0; break;
  };
  return a;
}

uint18_t get_data3(int offset, uint18_t aa[ROWS*COLS])
{
  #pragma HLS inline
  uint18_t a;
  switch (offset)
  {
    case 0: a = aa[41 ]; break;
    case 1: a = aa[56 ]; break;
    case 2: a = aa[79 ]; break;
    case 3: a = aa[96 ]; break;
    case 4: a = aa[109]; break;
    case 5: a = aa[141]; break;
    case 6: a = aa[155]; break;
    case 7: a = aa[201]; break;
    case 8: a = aa[249]; break;
    case 9: a = aa[263]; break;
    case 10:a = aa[293]; break;
    case 11:a = aa[322]; break;
    case 12:a = aa[383]; break;
    case 13:a = aa[394]; break;
    case 14:a = aa[408]; break;
    case 15:a = aa[415]; break;
    case 16:a = aa[428]; break;
    case 17:a = aa[445]; break;
    case 18:a = aa[459]; break;
    case 19:a = aa[479]; break;
    case 20:a = aa[532]; break;
    case 21:a = aa[564]; break;
    case 22:a = aa[575]; break;
    case 23:a = aa[598]; break;
    case 24:a = aa[611]; break;
    default: a = 0; break;
  };
  return a;
}

uint18_t get_data4(int offset, uint18_t aa[ROWS*COLS])
{
  #pragma HLS inline
  uint18_t a;

  switch (offset)
  {
    case 0: a = aa[24 ]; break;
    case 1: a = aa[34 ]; break;
    case 2: a = aa[47 ]; break;
    case 3: a = aa[58 ]; break;
    case 4: a = aa[105]; break;
    case 5: a = aa[128]; break;
    case 6: a = aa[162]; break;
    case 7: a = aa[179]; break;
    case 8: a = aa[218]; break;
    case 9: a = aa[226]; break;
    case 10:a = aa[346]; break;
    case 11:a = aa[364]; break;
    case 12:a = aa[369]; break;
    case 13:a = aa[388]; break;
    case 14:a = aa[406]; break;
    case 15:a = aa[425]; break;
    case 16:a = aa[440]; break;
    case 17:a = aa[453]; break;
    case 18:a = aa[458]; break;
    case 19:a = aa[486]; break;
    case 20:a = aa[510]; break;
    case 21:a = aa[552]; break;
    case 22:a = aa[594]; break;
    default: a = 0; break;
  }; 
  return a;
}

uint18_t get_data5(int offset, uint18_t aa[ROWS*COLS])
{
  #pragma HLS inline
  uint18_t a;

  switch (offset)
  {
    case 0: a = aa[23 ]; break;
    case 1: a = aa[53 ]; break;
    case 2: a = aa[94 ]; break;
    case 3: a = aa[95 ]; break;
    case 4: a = aa[101]; break;
    case 5: a = aa[139]; break;
    case 6: a = aa[171]; break;
    case 7: a = aa[180]; break;
    case 8: a = aa[222]; break;
    case 9: a = aa[267]; break;
    case 10:a = aa[275]; break;
    case 11:a = aa[311]; break;
    case 12:a = aa[312]; break;
    case 13:a = aa[333]; break;
    case 14:a = aa[365]; break;
    case 15:a = aa[390]; break;
    case 16:a = aa[397]; break;
    case 17:a = aa[409]; break;
    case 18:a = aa[410]; break;
    case 19:a = aa[426]; break;
    case 20:a = aa[443]; break;
    case 21:a = aa[463]; break;
    case 22:a = aa[537]; break;
    case 23:a = aa[571]; break;
    case 24:a = aa[599]; break;
    case 25:a = aa[608]; break;
    default: a = 0; break;
  }; 
  return a;
}

uint18_t get_data6(int offset, uint18_t aa[ROWS*COLS])
{
  #pragma HLS inline
  uint18_t a;
  switch (offset)
  {
    case 0: a = aa[15 ]; break;
    case 1: a = aa[42 ]; break;
    case 2: a = aa[55 ]; break;
    case 3: a = aa[122]; break;
    case 4: a = aa[138]; break;
    case 5: a = aa[177]; break;
    case 6: a = aa[204]; break;
    case 7: a = aa[215]; break;
    case 8: a = aa[228]; break;
    case 9: a = aa[231]; break;
    case 10:a = aa[250]; break;
    case 11:a = aa[287]; break;
    case 12:a = aa[307]; break;
    case 13:a = aa[308]; break;
    case 14:a = aa[366]; break;
    case 15:a = aa[391]; break;
    case 16:a = aa[411]; break;
    case 17:a = aa[424]; break;
    case 18:a = aa[435]; break;
    case 19:a = aa[468]; break;
    case 20:a = aa[497]; break;
    case 21:a = aa[539]; break;
    case 22:a = aa[555]; break;
    case 23:a = aa[609]; break;
    default: a = 0; break;
  }; 
  return a;
}

uint18_t get_data7(int offset, uint18_t aa[ROWS*COLS])
{
  #pragma HLS inline
  uint18_t a;

  switch (offset)
  {
    case 0: a = aa[38 ]; break;
    case 1: a = aa[82 ]; break;
    case 2: a = aa[93 ]; break;
    case 3: a = aa[135]; break;
    case 4: a = aa[159]; break;
    case 5: a = aa[195]; break;
    case 6: a = aa[212]; break;
    case 7: a = aa[237]; break;
    case 8: a = aa[238]; break;
    case 9: a = aa[258]; break;
    case 10:a = aa[269]; break;
    case 11:a = aa[283]; break;
    case 12:a = aa[310]; break;
    case 13:a = aa[328]; break;
    case 14:a = aa[355]; break;
    case 15:a = aa[421]; break;
    case 16:a = aa[427]; break;
    case 17:a = aa[465]; break;
    case 18:a = aa[523]; break;
    case 19:a = aa[547]; break;
    case 20:a = aa[557]; break;
    case 21:a = aa[570]; break;
    case 22:a = aa[593]; break;
    case 23:a = aa[606]; break;
    default: a = 0; break;
  }; 
  return a;
}

uint18_t get_data8(int offset, uint18_t aa[ROWS*COLS])
{
  #pragma HLS inline
  uint18_t a;

  switch (offset)
  {
    case 0:a = aa[0]; break;
    default: a = 0; break;
  }; 
  return a;
}

uint18_t get_data9(int offset, uint18_t aa[ROWS*COLS])
{
  #pragma HLS inline
  uint18_t a;

  switch (offset)
  {
    case 0: a = aa[14 ]; break;
    case 1: a = aa[46 ]; break;
    case 2: a = aa[119]; break;
    case 3: a = aa[147]; break;
    case 4: a = aa[150]; break;
    case 5: a = aa[151]; break;
    case 6: a = aa[163]; break;
    case 7: a = aa[185]; break;
    case 8: a = aa[198]; break;
    case 9: a = aa[242]; break;
    case 10:a = aa[262]; break;
    case 11:a = aa[286]; break;
    case 12:a = aa[302]; break;
    case 13:a = aa[315]; break;
    case 14:a = aa[340]; break;
    case 15:a = aa[343]; break;
    case 16:a = aa[358]; break;
    case 17:a = aa[359]; break;
    case 18:a = aa[429]; break;
    case 19:a = aa[481]; break;
    case 20:a = aa[489]; break;
    case 21:a = aa[507]; break;
    case 22:a = aa[520]; break;
    case 23:a = aa[525]; break;
    case 24:a = aa[572]; break;
    case 25:a = aa[577]; break;
    case 26:a = aa[591]; break;
    default: a = 0; break;
  }; 
  return a;
}

uint18_t get_data10(int offset, uint18_t aa[ROWS*COLS])
{
  #pragma HLS inline
  uint18_t a;

  switch (offset)
  {
    case 0: a = aa[6  ]; break;
    case 1: a = aa[40 ]; break;
    case 2: a = aa[103]; break;
    case 3: a = aa[146]; break;
    case 4: a = aa[173]; break;
    case 5: a = aa[174]; break;
    case 6: a = aa[232]; break;
    case 7: a = aa[268]; break;
    case 8: a = aa[279]; break;
    case 9: a = aa[341]; break;
    case 10:a = aa[374]; break;
    case 11:a = aa[386]; break;
    case 12:a = aa[405]; break;
    case 13:a = aa[420]; break;
    case 14:a = aa[439]; break;
    case 15:a = aa[471]; break;
    case 16:a = aa[488]; break;
    case 17:a = aa[509]; break;
    case 18:a = aa[526]; break;
    case 19:a = aa[612]; break;
    default: a = 0; break;
  }; 
  return a;
}

uint18_t get_data11(int offset, uint18_t aa[ROWS*COLS])
{
  #pragma HLS inline
  uint18_t a;

  switch (offset)
  {
    case 0: a = aa[22 ]; break;
    case 1: a = aa[45 ]; break;
    case 2: a = aa[102]; break;
    case 3: a = aa[136]; break;
    case 4: a = aa[137]; break;
    case 5: a = aa[156]; break;
    case 6: a = aa[157]; break;
    case 7: a = aa[183]; break;
    case 8: a = aa[184]; break;
    case 9: a = aa[210]; break;
    case 10:a = aa[221]; break;
    case 11:a = aa[235]; break;
    case 12:a = aa[291]; break;
    case 13:a = aa[324]; break;
    case 14:a = aa[344]; break;
    case 15:a = aa[353]; break;
    case 16:a = aa[377]; break;
    case 17:a = aa[398]; break;
    case 18:a = aa[417]; break;
    case 19:a = aa[418]; break;
    case 20:a = aa[454]; break;
    case 21:a = aa[511]; break;
    case 22:a = aa[524]; break;
    case 23:a = aa[540]; break;
    case 24:a = aa[559]; break;
    case 25:a = aa[584]; break;
    case 26:a = aa[613]; break;
    default: a = 0; break;
  }; 
  return a;
}

uint18_t get_data12(int offset, uint18_t aa[ROWS*COLS])
{
  #pragma HLS inline
  uint18_t a;

  switch (offset)
  {
    case 0: a = aa[5  ]; break;
    case 1: a = aa[39 ]; break;
    case 2: a = aa[54 ]; break;
    case 3: a = aa[61 ]; break;
    case 4: a = aa[75 ]; break;
    case 5: a = aa[76 ]; break;
    case 6: a = aa[106]; break;
    case 7: a = aa[140]; break;
    case 8: a = aa[165]; break;
    case 9: a = aa[209]; break;
    case 10:a = aa[245]; break;
    case 11:a = aa[246]; break;
    case 12:a = aa[316]; break;
    case 13:a = aa[347]; break;
    case 14:a = aa[412]; break;
    case 15:a = aa[413]; break;
    case 16:a = aa[444]; break;
    case 17:a = aa[464]; break;
    case 18:a = aa[490]; break;
    case 19:a = aa[530]; break;
    case 20:a = aa[534]; break;
    case 21:a = aa[535]; break;
    case 22:a = aa[560]; break;
    case 23:a = aa[586]; break;
    case 24:a = aa[618]; break;
    default: a = 0; break;
  }; 
  return a;
}

uint18_t get_data13(int offset, uint18_t aa[ROWS*COLS])
{
  #pragma HLS inline
  uint18_t a;

  switch (offset)
  {
    case 0: a = aa[1  ]; break;
    case 1: a = aa[27 ]; break;
    case 2: a = aa[59 ]; break;
    case 3: a = aa[87 ]; break;
    case 4: a = aa[118]; break;
    case 5: a = aa[131]; break;
    case 6: a = aa[167]; break;
    case 7: a = aa[175]; break;
    case 8: a = aa[247]; break;
    case 9: a = aa[319]; break;
    case 10:a = aa[334]; break;
    case 11:a = aa[335]; break;
    case 12:a = aa[371]; break;
    case 13:a = aa[387]; break;
    case 14:a = aa[395]; break;
    case 15:a = aa[414]; break;
    case 16:a = aa[442]; break;
    case 17:a = aa[501]; break;
    case 18:a = aa[544]; break;
    case 19:a = aa[548]; break;
    case 20:a = aa[565]; break;
    case 21:a = aa[603]; break;
    case 22:a = aa[604]; break;
    default: a = 0; break;
  }; 
  return a;
}

uint18_t get_data14(int offset, uint18_t aa[ROWS*COLS])
{
  #pragma HLS inline
  uint18_t a;

  switch (offset)
  {
    case 0: a = aa[3  ]; break;
    case 1: a = aa[10 ]; break;
    case 2: a = aa[17 ]; break;
    case 3: a = aa[35 ]; break;
    case 4: a = aa[66 ]; break;
    case 5: a = aa[99 ]; break;
    case 6: a = aa[152]; break;
    case 7: a = aa[178]; break;
    case 8: a = aa[248]; break;
    case 9: a = aa[259]; break;
    case 10:a = aa[270]; break;
    case 11:a = aa[290]; break;
    case 12:a = aa[321]; break;
    case 13:a = aa[336]; break;
    case 14:a = aa[337]; break;
    case 15:a = aa[361]; break;
    case 16:a = aa[382]; break;
    case 17:a = aa[393]; break;
    case 18:a = aa[416]; break;
    case 19:a = aa[473]; break;
    case 20:a = aa[502]; break;
    case 21:a = aa[545]; break;
    case 22:a = aa[600]; break;
    default: a = 0; break;
  }; 
  return a;
}

uint18_t get_data15(int offset, uint18_t aa[ROWS*COLS])
{
  #pragma HLS inline
  uint18_t a;

  switch (offset)
  {
    case 0: a = aa[8  ]; break;
    case 1: a = aa[25 ]; break;
    case 2: a = aa[30 ]; break;
    case 3: a = aa[57 ]; break;
    case 4: a = aa[120]; break;
    case 5: a = aa[123]; break;
    case 6: a = aa[169]; break;
    case 7: a = aa[192]; break;
    case 8: a = aa[217]; break;
    case 9: a = aa[241]; break;
    case 10:a = aa[271]; break;
    case 11:a = aa[274]; break;
    case 12:a = aa[285]; break;
    case 13:a = aa[306]; break;
    case 14:a = aa[327]; break;
    case 15:a = aa[368]; break;
    case 16:a = aa[403]; break;
    case 17:a = aa[434]; break;
    case 18:a = aa[474]; break;
    case 19:a = aa[476]; break;
    case 20:a = aa[504]; break;
    case 21:a = aa[538]; break;
    case 22:a = aa[563]; break;
    case 23:a = aa[568]; break;
    case 24:a = aa[596]; break;
    default: a = 0; break;
  }; 
  return a;
}

uint18_t get_data16(int offset, uint18_t aa[ROWS*COLS])
{
  #pragma HLS inline
  uint18_t a;

  switch (offset)
  {
    case 0: a = aa[12 ]; break;
    case 1: a = aa[26 ]; break;
    case 2: a = aa[49 ]; break;
    case 3: a = aa[68 ]; break;
    case 4: a = aa[83 ]; break;
    case 5: a = aa[121]; break;
    case 6: a = aa[219]; break;
    case 7: a = aa[234]; break;
    case 8: a = aa[252]; break;
    case 9: a = aa[265]; break;
    case 10:a = aa[281]; break;
    case 11:a = aa[282]; break;
    case 12:a = aa[300]; break;
    case 13:a = aa[313]; break;
    case 14:a = aa[342]; break;
    case 15:a = aa[378]; break;
    case 16:a = aa[389]; break;
    case 17:a = aa[483]; break;
    case 18:a = aa[496]; break;
    case 19:a = aa[516]; break;
    case 20:a = aa[578]; break;
    case 21:a = aa[582]; break;
    case 22:a = aa[595]; break;
    default: a = 0; break;
  }; 
  return a;
}

uint18_t get_data17(int offset, uint18_t aa[ROWS*COLS])
{
  #pragma HLS inline
  uint18_t a;

  switch (offset)
  {
    case 0: a = aa[11 ]; break;
    case 1: a = aa[67 ]; break;
    case 2: a = aa[77 ]; break;
    case 3: a = aa[104]; break;
    case 4: a = aa[125]; break;
    case 5: a = aa[160]; break;
    case 6: a = aa[203]; break;
    case 7: a = aa[207]; break;
    case 8: a = aa[243]; break;
    case 9: a = aa[244]; break;
    case 10:a = aa[264]; break;
    case 11:a = aa[299]; break;
    case 12:a = aa[323]; break;
    case 13:a = aa[367]; break;
    case 14:a = aa[400]; break;
    case 15:a = aa[401]; break;
    case 16:a = aa[441]; break;
    case 17:a = aa[456]; break;
    case 18:a = aa[480]; break;
    case 19:a = aa[528]; break;
    case 20:a = aa[579]; break;
    case 21:a = aa[589]; break;
    case 22:a = aa[619]; break;
    default: a = 0; break;
  }; 
  return a;
}


uint18_t get_data18(int offset, uint18_t aa[ROWS*COLS])
{
  #pragma HLS inline
  uint18_t a;
  switch (offset)
  {
    case 0: a = aa[21 ]; break;
    case 1: a = aa[43 ]; break;
    case 2: a = aa[62 ]; break;
    case 3: a = aa[144]; break;
    case 4: a = aa[145]; break;
    case 5: a = aa[196]; break;
    case 6: a = aa[197]; break;
    case 7: a = aa[199]; break;
    case 8: a = aa[292]; break;
    case 9: a = aa[301]; break;
    case 10:a = aa[317]; break;
    case 11:a = aa[330]; break;
    case 12:a = aa[331]; break;
    case 13:a = aa[332]; break;
    case 14:a = aa[350]; break;
    case 15:a = aa[363]; break;
    case 16:a = aa[381]; break;
    case 17:a = aa[433]; break;
    case 18:a = aa[469]; break;
    case 19:a = aa[484]; break;
    case 20:a = aa[522]; break;
    case 21:a = aa[561]; break;
    case 22:a = aa[587]; break;
    case 23:a = aa[623]; break;
    case 24:a = aa[624]; break;
    default: a = 0; break;
  }; 
  return a;
}

uint18_t get_data19(int offset, uint18_t aa[ROWS*COLS])
{
  #pragma HLS inline
  uint18_t a;

  switch (offset)
  {
    case 0: a = aa[16 ]; break;
    case 1: a = aa[60 ]; break;
    case 2: a = aa[69 ]; break;
    case 3: a = aa[80 ]; break;
    case 4: a = aa[112]; break;
    case 5: a = aa[117]; break;
    case 6: a = aa[170]; break;
    case 7: a = aa[186]; break;
    case 8: a = aa[206]; break;
    case 9: a = aa[223]; break;
    case 10:a = aa[255]; break;
    case 11:a = aa[288]; break;
    case 12:a = aa[289]; break;
    case 13:a = aa[325]; break;
    case 14:a = aa[326]; break;
    case 15:a = aa[345]; break;
    case 16:a = aa[357]; break;
    case 17:a = aa[372]; break;
    case 18:a = aa[487]; break;
    case 19:a = aa[508]; break;
    case 20:a = aa[521]; break;
    case 21:a = aa[543]; break;
    case 22:a = aa[581]; break;
    default: a = 0; break;
  }; 
  return a;
}

uint18_t get_data20(int offset, uint18_t aa[ROWS*COLS])
{
  #pragma HLS inline
  uint18_t a;

  switch (offset)
  {
    case 0: a = aa[2  ]; break;
    case 1: a = aa[13 ]; break;
    case 2: a = aa[44 ]; break;
    case 3: a = aa[63 ]; break;
    case 4: a = aa[90 ]; break;
    case 5: a = aa[111]; break;
    case 6: a = aa[126]; break;
    case 7: a = aa[154]; break;
    case 8: a = aa[181]; break;
    case 9: a = aa[200]; break;
    case 10:a = aa[230]; break;
    case 11:a = aa[257]; break;
    case 12:a = aa[294]; break;
    case 13:a = aa[295]; break;
    case 14:a = aa[296]; break;
    case 15:a = aa[339]; break;
    case 16:a = aa[373]; break;
    case 17:a = aa[399]; break;
    case 18:a = aa[422]; break;
    case 19:a = aa[436]; break;
    case 20:a = aa[462]; break;
    case 21:a = aa[518]; break;
    case 22:a = aa[533]; break;
    case 23:a = aa[585]; break;
    case 24:a = aa[610]; break;
    default: a = 0; break;
  }; 
  return a;
}

uint18_t get_data21(int offset, uint18_t aa[ROWS*COLS])
{
  #pragma HLS inline
  uint18_t a;

  switch (offset)
  {
    case 0: a = aa[4  ]; break;
    case 1: a = aa[32 ]; break;
    case 2: a = aa[73 ]; break;
    case 3: a = aa[81 ]; break;
    case 4: a = aa[108]; break;
    case 5: a = aa[172]; break;
    case 6: a = aa[190]; break;
    case 7: a = aa[194]; break;
    case 8: a = aa[224]; break;
    case 9: a = aa[266]; break;
    case 10:a = aa[318]; break;
    case 11:a = aa[338]; break;
    case 12:a = aa[360]; break;
    case 13:a = aa[392]; break;
    case 14:a = aa[437]; break;
    case 15:a = aa[475]; break;
    case 16:a = aa[505]; break;
    case 17:a = aa[574]; break;
    case 18:a = aa[601]; break;
    default: a = 0; break;
  }; 
  return a;
}

uint18_t get_data22(int offset, uint18_t aa[ROWS*COLS])
{
  #pragma HLS inline
  uint18_t a;

  switch (offset)
  {
    case 0: a = aa[71 ]; break;
    case 1: a = aa[85 ]; break;
    case 2: a = aa[92 ]; break;
    case 3: a = aa[124]; break;
    case 4: a = aa[133]; break;
    case 5: a = aa[143]; break;
    case 6: a = aa[166]; break;
    case 7: a = aa[211]; break;
    case 8: a = aa[225]; break;
    case 9: a = aa[304]; break;
    case 10:a = aa[305]; break;
    case 11:a = aa[351]; break;
    case 12:a = aa[352]; break;
    case 13:a = aa[407]; break;
    case 14:a = aa[423]; break;
    case 15:a = aa[431]; break;
    case 16:a = aa[472]; break;
    case 17:a = aa[495]; break;
    case 18:a = aa[515]; break;
    case 19:a = aa[549]; break;
    case 20:a = aa[553]; break;
    case 21:a = aa[558]; break;
    case 22:a = aa[588]; break;
    case 23:a = aa[614]; break;
    default: a = 0; break;
  }; 
  return a;
}

uint18_t get_data23(int offset, uint18_t aa[ROWS*COLS])
{
  #pragma HLS inline
  uint18_t a;

  switch (offset)
  {
    case 0: a = aa[37 ]; break;
    case 1: a = aa[50 ]; break;
    case 2: a = aa[88 ]; break;
    case 3: a = aa[114]; break;
    case 4: a = aa[134]; break;
    case 5: a = aa[189]; break;
    case 6: a = aa[205]; break;
    case 7: a = aa[214]; break;
    case 8: a = aa[236]; break;
    case 9: a = aa[273]; break;
    case 10:a = aa[297]; break;
    case 11:a = aa[349]; break;
    case 12:a = aa[354]; break;
    case 13:a = aa[432]; break;
    case 14:a = aa[457]; break;
    case 15:a = aa[477]; break;
    case 16:a = aa[498]; break;
    case 17:a = aa[512]; break;
    case 18:a = aa[605]; break;
    case 19:a = aa[616]; break;
    default: a = 0; break;
  }; 
  return a;
}

uint18_t get_data24(int offset, uint18_t aa[ROWS*COLS])
{
  #pragma HLS inline
  uint18_t a;

  switch (offset)
  {
    case 0: a = aa[31 ]; break;
    case 1: a = aa[84 ]; break;
    case 2: a = aa[113]; break;
    case 3: a = aa[116]; break;
    case 4: a = aa[129]; break;
    case 5: a = aa[158]; break;
    case 6: a = aa[182]; break;
    case 7: a = aa[227]; break;
    case 8: a = aa[276]; break;
    case 9: a = aa[380]; break;
    case 10:a = aa[404]; break;
    case 11:a = aa[460]; break;
    case 12:a = aa[470]; break;
    case 13:a = aa[493]; break;
    case 14:a = aa[494]; break;
    case 15:a = aa[503]; break;
    case 16:a = aa[514]; break;
    case 17:a = aa[566]; break;
    case 18:a = aa[580]; break;
    case 19:a = aa[602]; break;
    case 20:a = aa[617]; break;
    default: a = 0; break;
  }; 
  return a;
}

uint18_t get_data25(int offset, uint18_t aa[ROWS*COLS])
{
  #pragma HLS inline
  uint18_t a;

  switch (offset)
  {
    case 0: a = aa[33 ]; break;
    case 1: a = aa[51 ]; break;
    case 2: a = aa[64 ]; break;
    case 3: a = aa[78 ]; break;
    case 4: a = aa[86 ]; break;
    case 5: a = aa[110]; break;
    case 6: a = aa[130]; break;
    case 7: a = aa[216]; break;
    case 8: a = aa[254]; break;
    case 9: a = aa[298]; break;
    case 10:a = aa[320]; break;
    case 11:a = aa[402]; break;
    case 12:a = aa[419]; break;
    case 13:a = aa[438]; break;
    case 14:a = aa[446]; break;
    case 15:a = aa[455]; break;
    case 16:a = aa[491]; break;
    case 17:a = aa[500]; break;
    case 18:a = aa[590]; break;
    case 19:a = aa[622]; break;
    default: a = 0; break;
  }; 
  return a;
}

uint18_t get_data26(int offset, uint18_t aa[ROWS*COLS])
{
  #pragma HLS inline
  uint18_t a;

  switch (offset)
  {
    case 0: a = aa[70 ]; break;
    case 1: a = aa[89 ]; break;
    case 2: a = aa[115]; break;
    case 3: a = aa[127]; break;
    case 4: a = aa[142]; break;
    case 5: a = aa[272]; break;
    case 6: a = aa[348]; break;
    case 7: a = aa[370]; break;
    case 8: a = aa[379]; break;
    case 9: a = aa[430]; break;
    case 10:a = aa[461]; break;
    case 11:a = aa[485]; break;
    case 12:a = aa[513]; break;
    case 13:a = aa[541]; break;
    case 14:a = aa[550]; break;
    case 15:a = aa[583]; break;
    case 16:a = aa[607]; break;
    default: a = 0; break;
  }; 
  return a;
}

uint18_t get_data27(int offset, uint18_t aa[ROWS*COLS])
{
  #pragma HLS inline
  uint18_t a;

  switch (offset)
  {
    case 0: a = aa[36 ]; break;
    case 1: a = aa[91 ]; break;
    case 2: a = aa[98 ]; break;
    case 3: a = aa[107]; break;
    case 4: a = aa[176]; break;
    case 5: a = aa[202]; break;
    case 6: a = aa[278]; break;
    case 7: a = aa[467]; break;
    case 8: a = aa[482]; break;
    case 9: a = aa[546]; break;
    case 10:a = aa[556]; break;
    case 11:a = aa[569]; break;
    case 12:a = aa[592]; break;
    case 13:a = aa[620]; break;
    default: a = 0; break;
  }; return a;
}

void get_all_data(uint18_t output[12], uint10_t addr_list[12], uint18_t aa[ROWS*COLS])
{
  
  #pragma HLS inline
  #pragma HLS interface ap_stable port=aa

  uint5_t bank[12];
  #pragma HLS array_partition variable=bank complete dim=0
  uint5_t offset[12];
  #pragma HLS array_partition variable=offset complete dim=0
  uint5_t offset_for_banks[28];
  #pragma HLS array_partition variable=offset_for_banks complete dim=0
  uint18_t data_from_banks[28];
  #pragma HLS array_partition variable=data_from_banks complete dim=0
  
COMPUTE_BANK_AND_OFFSET:
  for (int i = 0; i < 12; i ++ )
  {
    #pragma HLS unroll   
    bank[i] = get_bank(addr_list[i]);
    offset[i] = get_offset(addr_list[i]);
  }

ASSIGN_OFFSET_FOR_BANKS:
  for (int i = 0; i < 28; i ++ )
  {
    #pragma HLS unroll
    offset_for_banks[i] = (bank[ 0] == i) ? offset[ 0] :
                          (bank[ 1] == i) ? offset[ 1] :
                          (bank[ 2] == i) ? offset[ 2] :
                          (bank[ 3] == i) ? offset[ 3] :
                          (bank[ 4] == i) ? offset[ 4] :
                          (bank[ 5] == i) ? offset[ 5] :
                          (bank[ 6] == i) ? offset[ 6] :
                          (bank[ 7] == i) ? offset[ 7] :
                          (bank[ 8] == i) ? offset[ 8] :
                          (bank[ 9] == i) ? offset[ 9] :
                          (bank[10] == i) ? offset[10] :
                          (bank[11] == i) ? offset[11] :
                          uint5_t("0",10);

  }

READ_ALL_BANKS:
  data_from_banks[ 0] =  get_data0 (offset_for_banks[ 0], aa);
  data_from_banks[ 1] =  get_data1 (offset_for_banks[ 1], aa);
  data_from_banks[ 2] =  get_data2 (offset_for_banks[ 2], aa);
  data_from_banks[ 3] =  get_data3 (offset_for_banks[ 3], aa);
  data_from_banks[ 4] =  get_data4 (offset_for_banks[ 4], aa);
  data_from_banks[ 5] =  get_data5 (offset_for_banks[ 5], aa);
  data_from_banks[ 6] =  get_data6 (offset_for_banks[ 6], aa);
  data_from_banks[ 7] =  get_data7 (offset_for_banks[ 7], aa);
  data_from_banks[ 8] =  get_data8 (offset_for_banks[ 8], aa);
  data_from_banks[ 9] =  get_data9 (offset_for_banks[ 9], aa);
  data_from_banks[10] =  get_data10(offset_for_banks[10], aa);
  data_from_banks[11] =  get_data11(offset_for_banks[11], aa);
  data_from_banks[12] =  get_data12(offset_for_banks[12], aa);
  data_from_banks[13] =  get_data13(offset_for_banks[13], aa);
  data_from_banks[14] =  get_data14(offset_for_banks[14], aa);
  data_from_banks[15] =  get_data15(offset_for_banks[15], aa);
  data_from_banks[16] =  get_data16(offset_for_banks[16], aa);
  data_from_banks[17] =  get_data17(offset_for_banks[17], aa);
  data_from_banks[18] =  get_data18(offset_for_banks[18], aa);
  data_from_banks[19] =  get_data19(offset_for_banks[19], aa);
  data_from_banks[20] =  get_data20(offset_for_banks[20], aa);
  data_from_banks[21] =  get_data21(offset_for_banks[21], aa);
  data_from_banks[22] =  get_data22(offset_for_banks[22], aa);
  data_from_banks[23] =  get_data23(offset_for_banks[23], aa);
  data_from_banks[24] =  get_data24(offset_for_banks[24], aa);
  data_from_banks[25] =  get_data25(offset_for_banks[25], aa);
  data_from_banks[26] =  get_data26(offset_for_banks[26], aa);
  data_from_banks[27] =  get_data27(offset_for_banks[27], aa);

CHOOSE_DATA:
  for (int i = 0; i < 12; i ++ )
  {
    #pragma HLS unroll
    output[i] = data_from_banks[bank[i]];
  }

}

int classifier0( int_II II[WINDOW_SIZE][WINDOW_SIZE], int stddev ){
  static int coord[12];
  #pragma HLS array_partition variable=coord complete dim=0

  int sum0, sum1, sum2, final_sum;
  int return_value;
  coord[0] = II[4][6];
  coord[1] = II[4][18];
  coord[2] = II[13][6];
  coord[3] = II[13][18];

  coord[4] = II[7][6];
  coord[5] = II[7][18];
  coord[6] = II[10][6];
  coord[7] = II[10][18];

  coord[8] = 0;
  coord[9] = 0;
  coord[10] = 0;
  coord[11] = 0;

  sum0 = (coord[0] - coord[1] - coord[2] + coord[3]) * -4096;
  sum1 = (coord[4] - coord[5] - coord[6] + coord[7]) * 12288;
  sum2 = (coord[8] - coord[9] - coord[10] + coord[11]) * 0;
  final_sum = sum0 + sum1 + sum2;

  if(final_sum >= (-129 * stddev))
     return_value = -567;
  else
     return_value = 534;
  return return_value;
}
int classifier1( int_II II[WINDOW_SIZE][WINDOW_SIZE], int stddev ){
  static int coord[12];
  #pragma HLS array_partition variable=coord complete dim=0

  int sum0, sum1, sum2, final_sum;
  int return_value;
  coord[0] = II[4][6];
  coord[1] = II[4][18];
  coord[2] = II[11][6];
  coord[3] = II[11][18];

  coord[4] = II[4][10];
  coord[5] = II[4][14];
  coord[6] = II[11][10];
  coord[7] = II[11][14];

  coord[8] = 0;
  coord[9] = 0;
  coord[10] = 0;
  coord[11] = 0;

  sum0 = (coord[0] - coord[1] - coord[2] + coord[3]) * -4096;
  sum1 = (coord[4] - coord[5] - coord[6] + coord[7]) * 12288;
  sum2 = (coord[8] - coord[9] - coord[10] + coord[11]) * 0;
  final_sum = sum0 + sum1 + sum2;

  if(final_sum >= (50 * stddev))
     return_value = 339;
  else
     return_value = -477;
  return return_value;
}
int classifier2( int_II II[WINDOW_SIZE][WINDOW_SIZE], int stddev ){
  static int coord[12];
  #pragma HLS array_partition variable=coord complete dim=0

  int sum0, sum1, sum2, final_sum;
  int return_value;
  coord[0] = II[9][3];
  coord[1] = II[9][21];
  coord[2] = II[18][3];
  coord[3] = II[18][21];

  coord[4] = II[12][3];
  coord[5] = II[12][21];
  coord[6] = II[15][3];
  coord[7] = II[15][21];

  coord[8] = 0;
  coord[9] = 0;
  coord[10] = 0;
  coord[11] = 0;

  sum0 = (coord[0] - coord[1] - coord[2] + coord[3]) * -4096;
  sum1 = (coord[4] - coord[5] - coord[6] + coord[7]) * 12288;
  sum2 = (coord[8] - coord[9] - coord[10] + coord[11]) * 0;
  final_sum = sum0 + sum1 + sum2;

  if(final_sum >= (89 * stddev))
     return_value = 272;
  else
     return_value = -386;
  return return_value;
}
int classifier3( int_II II[WINDOW_SIZE][WINDOW_SIZE], int stddev ){
  static int coord[12];
  #pragma HLS array_partition variable=coord complete dim=0

  int sum0, sum1, sum2, final_sum;
  int return_value;
  coord[0] = II[18][8];
  coord[1] = II[18][17];
  coord[2] = II[24][8];
  coord[3] = II[24][17];

  coord[4] = II[20][8];
  coord[5] = II[20][17];
  coord[6] = II[22][8];
  coord[7] = II[22][17];

  coord[8] = 0;
  coord[9] = 0;
  coord[10] = 0;
  coord[11] = 0;

  sum0 = (coord[0] - coord[1] - coord[2] + coord[3]) * -4096;
  sum1 = (coord[4] - coord[5] - coord[6] + coord[7]) * 12288;
  sum2 = (coord[8] - coord[9] - coord[10] + coord[11]) * 0;
  final_sum = sum0 + sum1 + sum2;

  if(final_sum >= (23 * stddev))
     return_value = 301;
  else
     return_value = -223;
  return return_value;
}
int classifier4( int_II II[WINDOW_SIZE][WINDOW_SIZE], int stddev ){
  static int coord[12];
  #pragma HLS array_partition variable=coord complete dim=0

  int sum0, sum1, sum2, final_sum;
  int return_value;
  coord[0] = II[5][3];
  coord[1] = II[5][7];
  coord[2] = II[24][3];
  coord[3] = II[24][7];

  coord[4] = II[5][5];
  coord[5] = II[5][7];
  coord[6] = II[24][5];
  coord[7] = II[24][7];

  coord[8] = 0;
  coord[9] = 0;
  coord[10] = 0;
  coord[11] = 0;

  sum0 = (coord[0] - coord[1] - coord[2] + coord[3]) * -4096;
  sum1 = (coord[4] - coord[5] - coord[6] + coord[7]) * 8192;
  sum2 = (coord[8] - coord[9] - coord[10] + coord[11]) * 0;
  final_sum = sum0 + sum1 + sum2;

  if(final_sum >= (61 * stddev))
     return_value = 322;
  else
     return_value = -199;
  return return_value;
}
int classifier5( int_II II[WINDOW_SIZE][WINDOW_SIZE], int stddev ){
  static int coord[12];
  #pragma HLS array_partition variable=coord complete dim=0

  int sum0, sum1, sum2, final_sum;
  int return_value;
  coord[0] = II[5][6];
  coord[1] = II[5][18];
  coord[2] = II[21][6];
  coord[3] = II[21][18];

  coord[4] = II[13][6];
  coord[5] = II[13][18];
  coord[6] = II[21][6];
  coord[7] = II[21][18];

  coord[8] = 0;
  coord[9] = 0;
  coord[10] = 0;
  coord[11] = 0;

  sum0 = (coord[0] - coord[1] - coord[2] + coord[3]) * -4096;
  sum1 = (coord[4] - coord[5] - coord[6] + coord[7]) * 8192;
  sum2 = (coord[8] - coord[9] - coord[10] + coord[11]) * 0;
  final_sum = sum0 + sum1 + sum2;

  if(final_sum >= (407 * stddev))
     return_value = -479;
  else
     return_value = 142;
  return return_value;
}
int classifier6( int_II II[WINDOW_SIZE][WINDOW_SIZE], int stddev ){
  static int coord[12];
  #pragma HLS array_partition variable=coord complete dim=0

  int sum0, sum1, sum2, final_sum;
  int return_value;
  coord[0] = II[8][5];
  coord[1] = II[8][17];
  coord[2] = II[14][5];
  coord[3] = II[14][17];

  coord[4] = II[11][5];
  coord[5] = II[11][17];
  coord[6] = II[14][5];
  coord[7] = II[14][17];

  coord[8] = 0;
  coord[9] = 0;
  coord[10] = 0;
  coord[11] = 0;

  sum0 = (coord[0] - coord[1] - coord[2] + coord[3]) * -4096;
  sum1 = (coord[4] - coord[5] - coord[6] + coord[7]) * 8192;
  sum2 = (coord[8] - coord[9] - coord[10] + coord[11]) * 0;
  final_sum = sum0 + sum1 + sum2;

  if(final_sum >= (11 * stddev))
     return_value = 112;
  else
     return_value = -432;
  return return_value;
}
int classifier7( int_II II[WINDOW_SIZE][WINDOW_SIZE], int stddev ){
  static int coord[12];
  #pragma HLS array_partition variable=coord complete dim=0

  int sum0, sum1, sum2, final_sum;
  int return_value;
  coord[0] = II[14][11];
  coord[1] = II[14][15];
  coord[2] = II[24][11];
  coord[3] = II[24][15];

  coord[4] = II[19][11];
  coord[5] = II[19][15];
  coord[6] = II[24][11];
  coord[7] = II[24][15];

  coord[8] = 0;
  coord[9] = 0;
  coord[10] = 0;
  coord[11] = 0;

  sum0 = (coord[0] - coord[1] - coord[2] + coord[3]) * -4096;
  sum1 = (coord[4] - coord[5] - coord[6] + coord[7]) * 8192;
  sum2 = (coord[8] - coord[9] - coord[10] + coord[11]) * 0;
  final_sum = sum0 + sum1 + sum2;

  if(final_sum >= (-77 * stddev))
     return_value = 113;
  else
     return_value = -378;
  return return_value;
}
int classifier8( int_II II[WINDOW_SIZE][WINDOW_SIZE], int stddev ){
  static int coord[12];
  #pragma HLS array_partition variable=coord complete dim=0

  int sum0, sum1, sum2, final_sum;
  int return_value;
  coord[0] = II[0][4];
  coord[1] = II[0][11];
  coord[2] = II[6][4];
  coord[3] = II[6][11];

  coord[4] = II[3][4];
  coord[5] = II[3][11];
  coord[6] = II[6][4];
  coord[7] = II[6][11];

  coord[8] = 0;
  coord[9] = 0;
  coord[10] = 0;
  coord[11] = 0;

  sum0 = (coord[0] - coord[1] - coord[2] + coord[3]) * -4096;
  sum1 = (coord[4] - coord[5] - coord[6] + coord[7]) * 8192;
  sum2 = (coord[8] - coord[9] - coord[10] + coord[11]) * 0;
  final_sum = sum0 + sum1 + sum2;

  if(final_sum >= (24 * stddev))
     return_value = 218;
  else
     return_value = -219;
  return return_value;
}

int classifier9( int_II II[WINDOW_SIZE][WINDOW_SIZE], int stddev ){
  static int coord[12];
  #pragma HLS array_partition variable=coord complete dim=0

  int sum0, sum1, sum2, final_sum;
  int return_value;
  coord[0] = II[6][6];
  coord[1] = II[6][18];
  coord[2] = II[12][6];
  coord[3] = II[12][18];

  coord[4] = II[8][6];
  coord[5] = II[8][18];
  coord[6] = II[10][6];
  coord[7] = II[10][18];

  coord[8] = 0;
  coord[9] = 0;
  coord[10] = 0;
  coord[11] = 0;

  sum0 = (coord[0] - coord[1] - coord[2] + coord[3]) * -4096;
  sum1 = (coord[4] - coord[5] - coord[6] + coord[7]) * 12288;
  sum2 = (coord[8] - coord[9] - coord[10] + coord[11]) * 0;
  final_sum = sum0 + sum1 + sum2;

  if(final_sum >= (-86 * stddev))
     return_value = -402;
  else
     return_value = 318;
  return return_value;
}
int classifier10( int_II II[WINDOW_SIZE][WINDOW_SIZE], int stddev ){
  static int coord[12];
  #pragma HLS array_partition variable=coord complete dim=0

  int sum0, sum1, sum2, final_sum;
  int return_value;
  coord[0] = II[4][6];
  coord[1] = II[4][18];
  coord[2] = II[11][6];
  coord[3] = II[11][18];

  coord[4] = II[4][10];
  coord[5] = II[4][14];
  coord[6] = II[11][10];
  coord[7] = II[11][14];

  coord[8] = 0;
  coord[9] = 0;
  coord[10] = 0;
  coord[11] = 0;

  sum0 = (coord[0] - coord[1] - coord[2] + coord[3]) * -4096;
  sum1 = (coord[4] - coord[5] - coord[6] + coord[7]) * 12288;
  sum2 = (coord[8] - coord[9] - coord[10] + coord[11]) * 0;
  final_sum = sum0 + sum1 + sum2;

  if(final_sum >= (83 * stddev))
     return_value = 302;
  else
     return_value = -414;
  return return_value;
}
int classifier11( int_II II[WINDOW_SIZE][WINDOW_SIZE], int stddev ){
  static int coord[12];
  #pragma HLS array_partition variable=coord complete dim=0

  int sum0, sum1, sum2, final_sum;
  int return_value;
  coord[0] = II[8][1];
  coord[1] = II[8][20];
  coord[2] = II[20][1];
  coord[3] = II[20][20];

  coord[4] = II[12][1];
  coord[5] = II[12][20];
  coord[6] = II[16][1];
  coord[7] = II[16][20];

  coord[8] = 0;
  coord[9] = 0;
  coord[10] = 0;
  coord[11] = 0;

  sum0 = (coord[0] - coord[1] - coord[2] + coord[3]) * -4096;
  sum1 = (coord[4] - coord[5] - coord[6] + coord[7]) * 12288;
  sum2 = (coord[8] - coord[9] - coord[10] + coord[11]) * 0;
  final_sum = sum0 + sum1 + sum2;

  if(final_sum >= (87 * stddev))
     return_value = 179;
  else
     return_value = -497;
  return return_value;
}
int classifier12( int_II II[WINDOW_SIZE][WINDOW_SIZE], int stddev ){
  static int coord[12];
  #pragma HLS array_partition variable=coord complete dim=0

  int sum0, sum1, sum2, final_sum;
  int return_value;
  coord[0] = II[2][0];
  coord[1] = II[2][24];
  coord[2] = II[5][0];
  coord[3] = II[5][24];

  coord[4] = II[2][8];
  coord[5] = II[2][16];
  coord[6] = II[5][8];
  coord[7] = II[5][16];

  coord[8] = 0;
  coord[9] = 0;
  coord[10] = 0;
  coord[11] = 0;

  sum0 = (coord[0] - coord[1] - coord[2] + coord[3]) * -4096;
  sum1 = (coord[4] - coord[5] - coord[6] + coord[7]) * 12288;
  sum2 = (coord[8] - coord[9] - coord[10] + coord[11]) * 0;
  final_sum = sum0 + sum1 + sum2;

  if(final_sum >= (375 * stddev))
     return_value = 442;
  else
     return_value = -142;
  return return_value;
}
int classifier13( int_II II[WINDOW_SIZE][WINDOW_SIZE], int stddev ){
  static int coord[12];
  #pragma HLS array_partition variable=coord complete dim=0

  int sum0, sum1, sum2, final_sum;
  int return_value;
  coord[0] = II[9][9];
  coord[1] = II[9][15];
  coord[2] = II[24][9];
  coord[3] = II[24][15];

  coord[4] = II[14][9];
  coord[5] = II[14][15];
  coord[6] = II[19][9];
  coord[7] = II[19][15];

  coord[8] = 0;
  coord[9] = 0;
  coord[10] = 0;
  coord[11] = 0;

  sum0 = (coord[0] - coord[1] - coord[2] + coord[3]) * -4096;
  sum1 = (coord[4] - coord[5] - coord[6] + coord[7]) * 12288;
  sum2 = (coord[8] - coord[9] - coord[10] + coord[11]) * 0;
  final_sum = sum0 + sum1 + sum2;

  if(final_sum >= (148 * stddev))
     return_value = -558;
  else
     return_value = 68;
  return return_value;
}
int classifier14( int_II II[WINDOW_SIZE][WINDOW_SIZE], int stddev ){
  static int coord[12];
  #pragma HLS array_partition variable=coord complete dim=0

  int sum0, sum1, sum2, final_sum;
  int return_value;
  coord[0] = II[6][5];
  coord[1] = II[6][19];
  coord[2] = II[16][5];
  coord[3] = II[16][19];

  coord[4] = II[11][5];
  coord[5] = II[11][19];
  coord[6] = II[16][5];
  coord[7] = II[16][19];

  coord[8] = 0;
  coord[9] = 0;
  coord[10] = 0;
  coord[11] = 0;

  sum0 = (coord[0] - coord[1] - coord[2] + coord[3]) * -4096;
  sum1 = (coord[4] - coord[5] - coord[6] + coord[7]) * 8192;
  sum2 = (coord[8] - coord[9] - coord[10] + coord[11]) * 0;
  final_sum = sum0 + sum1 + sum2;

  if(final_sum >= (-78 * stddev))
     return_value = 116;
  else
     return_value = -684;
  return return_value;
}
int classifier15( int_II II[WINDOW_SIZE][WINDOW_SIZE], int stddev ){
  static int coord[12];
  #pragma HLS array_partition variable=coord complete dim=0

  int sum0, sum1, sum2, final_sum;
  int return_value;
  coord[0] = II[0][5];
  coord[1] = II[0][19];
  coord[2] = II[9][5];
  coord[3] = II[9][19];

  coord[4] = II[3][5];
  coord[5] = II[3][19];
  coord[6] = II[6][5];
  coord[7] = II[6][19];

  coord[8] = 0;
  coord[9] = 0;
  coord[10] = 0;
  coord[11] = 0;

  sum0 = (coord[0] - coord[1] - coord[2] + coord[3]) * -4096;
  sum1 = (coord[4] - coord[5] - coord[6] + coord[7]) * 12288;
  sum2 = (coord[8] - coord[9] - coord[10] + coord[11]) * 0;
  final_sum = sum0 + sum1 + sum2;

  if(final_sum >= (33 * stddev))
     return_value = 137;
  else
     return_value = -277;
  return return_value;
}
int classifier16( int_II II[WINDOW_SIZE][WINDOW_SIZE], int stddev ){
  static int coord[12];
  #pragma HLS array_partition variable=coord complete dim=0

  int sum0, sum1, sum2, final_sum;
  int return_value;
  coord[0] = II[11][13];
  coord[1] = II[11][22];
  coord[2] = II[17][13];
  coord[3] = II[17][22];

  coord[4] = II[11][16];
  coord[5] = II[11][19];
  coord[6] = II[17][16];
  coord[7] = II[17][19];

  coord[8] = 0;
  coord[9] = 0;
  coord[10] = 0;
  coord[11] = 0;

  sum0 = (coord[0] - coord[1] - coord[2] + coord[3]) * -4096;
  sum1 = (coord[4] - coord[5] - coord[6] + coord[7]) * 12288;
  sum2 = (coord[8] - coord[9] - coord[10] + coord[11]) * 0;
  final_sum = sum0 + sum1 + sum2;

  if(final_sum >= (75 * stddev))
     return_value = 238;
  else
     return_value = -90;
  return return_value;
}
int classifier17( int_II II[WINDOW_SIZE][WINDOW_SIZE], int stddev ){
  static int coord[12];
  #pragma HLS array_partition variable=coord complete dim=0

  int sum0, sum1, sum2, final_sum;
  int return_value;
  coord[0] = II[5][7];
  coord[1] = II[5][13];
  coord[2] = II[15][7];
  coord[3] = II[15][13];

  coord[4] = II[5][9];
  coord[5] = II[5][11];
  coord[6] = II[15][9];
  coord[7] = II[15][11];

  coord[8] = 0;
  coord[9] = 0;
  coord[10] = 0;
  coord[11] = 0;

  sum0 = (coord[0] - coord[1] - coord[2] + coord[3]) * -4096;
  sum1 = (coord[4] - coord[5] - coord[6] + coord[7]) * 12288;
  sum2 = (coord[8] - coord[9] - coord[10] + coord[11]) * 0;
  final_sum = sum0 + sum1 + sum2;

  if(final_sum >= (-28 * stddev))
     return_value = -169;
  else
     return_value = 237;
  return return_value;
}
int classifier18( int_II II[WINDOW_SIZE][WINDOW_SIZE], int stddev ){
  static int coord[12];
  #pragma HLS array_partition variable=coord complete dim=0

  int sum0, sum1, sum2, final_sum;
  int return_value;
  coord[0] = II[8][10];
  coord[1] = II[8][16];
  coord[2] = II[18][10];
  coord[3] = II[18][16];

  coord[4] = II[8][12];
  coord[5] = II[8][14];
  coord[6] = II[18][12];
  coord[7] = II[18][14];

  coord[8] = 0;
  coord[9] = 0;
  coord[10] = 0;
  coord[11] = 0;

  sum0 = (coord[0] - coord[1] - coord[2] + coord[3]) * -4096;
  sum1 = (coord[4] - coord[5] - coord[6] + coord[7]) * 12288;
  sum2 = (coord[8] - coord[9] - coord[10] + coord[11]) * 0;
  final_sum = sum0 + sum1 + sum2;

  if(final_sum >= (-40 * stddev))
     return_value = -76;
  else
     return_value = 296;
  return return_value;
}
int classifier19( int_II II[WINDOW_SIZE][WINDOW_SIZE], int stddev ){
  static int coord[12];
  #pragma HLS array_partition variable=coord complete dim=0

  int sum0, sum1, sum2, final_sum;
  int return_value;
  coord[0] = II[5][2];
  coord[1] = II[5][6];
  coord[2] = II[14][2];
  coord[3] = II[14][6];

  coord[4] = II[5][4];
  coord[5] = II[5][6];
  coord[6] = II[14][4];
  coord[7] = II[14][6];

  coord[8] = 0;
  coord[9] = 0;
  coord[10] = 0;
  coord[11] = 0;

  sum0 = (coord[0] - coord[1] - coord[2] + coord[3]) * -4096;
  sum1 = (coord[4] - coord[5] - coord[6] + coord[7]) * 8192;
  sum2 = (coord[8] - coord[9] - coord[10] + coord[11]) * 0;
  final_sum = sum0 + sum1 + sum2;

  if(final_sum >= (64 * stddev))
     return_value = 347;
  else
     return_value = -107;
  return return_value;
}
int classifier20( int_II II[WINDOW_SIZE][WINDOW_SIZE], int stddev ){
  static int coord[12];
  #pragma HLS array_partition variable=coord complete dim=0

  int sum0, sum1, sum2, final_sum;
  int return_value;
  coord[0] = II[0][18];
  coord[1] = II[0][24];
  coord[2] = II[11][18];
  coord[3] = II[11][24];

  coord[4] = II[0][20];
  coord[5] = II[0][22];
  coord[6] = II[11][20];
  coord[7] = II[11][22];

  coord[8] = 0;
  coord[9] = 0;
  coord[10] = 0;
  coord[11] = 0;

  sum0 = (coord[0] - coord[1] - coord[2] + coord[3]) * -4096;
  sum1 = (coord[4] - coord[5] - coord[6] + coord[7]) * 12288;
  sum2 = (coord[8] - coord[9] - coord[10] + coord[11]) * 0;
  final_sum = sum0 + sum1 + sum2;

  if(final_sum >= (-84 * stddev))
     return_value = -50;
  else
     return_value = 373;
  return return_value;
}
int classifier21( int_II II[WINDOW_SIZE][WINDOW_SIZE], int stddev ){
  static int coord[12];
  #pragma HLS array_partition variable=coord complete dim=0

  int sum0, sum1, sum2, final_sum;
  int return_value;
  coord[0] = II[6][0];
  coord[1] = II[6][24];
  coord[2] = II[19][0];
  coord[3] = II[19][24];

  coord[4] = II[6][8];
  coord[5] = II[6][16];
  coord[6] = II[19][8];
  coord[7] = II[19][16];

  coord[8] = 0;
  coord[9] = 0;
  coord[10] = 0;
  coord[11] = 0;

  sum0 = (coord[0] - coord[1] - coord[2] + coord[3]) * -4096;
  sum1 = (coord[4] - coord[5] - coord[6] + coord[7]) * 12288;
  sum2 = (coord[8] - coord[9] - coord[10] + coord[11]) * 0;
  final_sum = sum0 + sum1 + sum2;

  if(final_sum >= (-563 * stddev))
     return_value = -135;
  else
     return_value = 286;
  return return_value;
}
int classifier22( int_II II[WINDOW_SIZE][WINDOW_SIZE], int stddev ){
  static int coord[12];
  #pragma HLS array_partition variable=coord complete dim=0

  int sum0, sum1, sum2, final_sum;
  int return_value;
  coord[0] = II[6][9];
  coord[1] = II[6][15];
  coord[2] = II[15][9];
  coord[3] = II[15][15];

  coord[4] = II[6][11];
  coord[5] = II[6][13];
  coord[6] = II[15][11];
  coord[7] = II[15][13];

  coord[8] = 0;
  coord[9] = 0;
  coord[10] = 0;
  coord[11] = 0;

  sum0 = (coord[0] - coord[1] - coord[2] + coord[3]) * -4096;
  sum1 = (coord[4] - coord[5] - coord[6] + coord[7]) * 12288;
  sum2 = (coord[8] - coord[9] - coord[10] + coord[11]) * 0;
  final_sum = sum0 + sum1 + sum2;

  if(final_sum >= (58 * stddev))
     return_value = 292;
  else
     return_value = -89;
  return return_value;
}
int classifier23( int_II II[WINDOW_SIZE][WINDOW_SIZE], int stddev ){
  static int coord[12];
  #pragma HLS array_partition variable=coord complete dim=0

  int sum0, sum1, sum2, final_sum;
  int return_value;
  coord[0] = II[18][7];
  coord[1] = II[18][17];
  coord[2] = II[24][7];
  coord[3] = II[24][17];

  coord[4] = II[20][7];
  coord[5] = II[20][17];
  coord[6] = II[22][7];
  coord[7] = II[22][17];

  coord[8] = 0;
  coord[9] = 0;
  coord[10] = 0;
  coord[11] = 0;

  sum0 = (coord[0] - coord[1] - coord[2] + coord[3]) * -4096;
  sum1 = (coord[4] - coord[5] - coord[6] + coord[7]) * 12288;
  sum2 = (coord[8] - coord[9] - coord[10] + coord[11]) * 0;
  final_sum = sum0 + sum1 + sum2;

  if(final_sum >= (41 * stddev))
     return_value = 197;
  else
     return_value = -155;
  return return_value;
}
int classifier24( int_II II[WINDOW_SIZE][WINDOW_SIZE], int stddev ){
  static int coord[12];
  #pragma HLS array_partition variable=coord complete dim=0

  int sum0, sum1, sum2, final_sum;
  int return_value;
  coord[0] = II[7][5];
  coord[1] = II[7][19];
  coord[2] = II[19][5];
  coord[3] = II[19][19];

  coord[4] = II[13][5];
  coord[5] = II[13][19];
  coord[6] = II[19][5];
  coord[7] = II[19][19];

  coord[8] = 0;
  coord[9] = 0;
  coord[10] = 0;
  coord[11] = 0;

  sum0 = (coord[0] - coord[1] - coord[2] + coord[3]) * -4096;
  sum1 = (coord[4] - coord[5] - coord[6] + coord[7]) * 8192;
  sum2 = (coord[8] - coord[9] - coord[10] + coord[11]) * 0;
  final_sum = sum0 + sum1 + sum2;

  if(final_sum >= (374 * stddev))
     return_value = -387;
  else
     return_value = 99;
  return return_value;
}
int classifier25( int_II II[WINDOW_SIZE][WINDOW_SIZE], int stddev ){
  static int coord[12];
  #pragma HLS array_partition variable=coord complete dim=0

  int sum0, sum1, sum2, final_sum;
  int return_value;
  coord[0] = II[3][0];
  coord[1] = II[3][24];
  coord[2] = II[6][0];
  coord[3] = II[6][24];

  coord[4] = II[3][8];
  coord[5] = II[3][16];
  coord[6] = II[6][8];
  coord[7] = II[6][16];

  coord[8] = 0;
  coord[9] = 0;
  coord[10] = 0;
  coord[11] = 0;

  sum0 = (coord[0] - coord[1] - coord[2] + coord[3]) * -4096;
  sum1 = (coord[4] - coord[5] - coord[6] + coord[7]) * 12288;
  sum2 = (coord[8] - coord[9] - coord[10] + coord[11]) * 0;
  final_sum = sum0 + sum1 + sum2;

  if(final_sum >= (285 * stddev))
     return_value = 375;
  else
     return_value = -259;
  return return_value;
}
int classifier26( int_II II[WINDOW_SIZE][WINDOW_SIZE], int stddev ){
  static int coord[12];
  #pragma HLS array_partition variable=coord complete dim=0

  int sum0, sum1, sum2, final_sum;
  int return_value;
  coord[0] = II[8][5];
  coord[1] = II[8][20];
  coord[2] = II[14][5];
  coord[3] = II[14][20];

  coord[4] = II[11][5];
  coord[5] = II[11][20];
  coord[6] = II[14][5];
  coord[7] = II[14][20];

  coord[8] = 0;
  coord[9] = 0;
  coord[10] = 0;
  coord[11] = 0;

  sum0 = (coord[0] - coord[1] - coord[2] + coord[3]) * -4096;
  sum1 = (coord[4] - coord[5] - coord[6] + coord[7]) * 8192;
  sum2 = (coord[8] - coord[9] - coord[10] + coord[11]) * 0;
  final_sum = sum0 + sum1 + sum2;

  if(final_sum >= (129 * stddev))
     return_value = 256;
  else
     return_value = -421;
  return return_value;
}
int classifier27( int_II II[WINDOW_SIZE][WINDOW_SIZE], int stddev ){
  static int coord[12];
  #pragma HLS array_partition variable=coord complete dim=0

  int sum0, sum1, sum2, final_sum;
  int return_value;
  coord[0] = II[6][9];
  coord[1] = II[6][14];
  coord[2] = II[20][9];
  coord[3] = II[20][14];

  coord[4] = II[13][9];
  coord[5] = II[13][14];
  coord[6] = II[20][9];
  coord[7] = II[20][14];

  coord[8] = 0;
  coord[9] = 0;
  coord[10] = 0;
  coord[11] = 0;

  sum0 = (coord[0] - coord[1] - coord[2] + coord[3]) * -4096;
  sum1 = (coord[4] - coord[5] - coord[6] + coord[7]) * 8192;
  sum2 = (coord[8] - coord[9] - coord[10] + coord[11]) * 0;
  final_sum = sum0 + sum1 + sum2;

  if(final_sum >= (58 * stddev))
     return_value = -408;
  else
     return_value = 118;
  return return_value;
}
int classifier28( int_II II[WINDOW_SIZE][WINDOW_SIZE], int stddev ){
  static int coord[12];
  #pragma HLS array_partition variable=coord complete dim=0

  int sum0, sum1, sum2, final_sum;
  int return_value;
  coord[0] = II[5][9];
  coord[1] = II[5][15];
  coord[2] = II[15][9];
  coord[3] = II[15][15];

  coord[4] = II[5][11];
  coord[5] = II[5][13];
  coord[6] = II[15][11];
  coord[7] = II[15][13];

  coord[8] = 0;
  coord[9] = 0;
  coord[10] = 0;
  coord[11] = 0;

  sum0 = (coord[0] - coord[1] - coord[2] + coord[3]) * -4096;
  sum1 = (coord[4] - coord[5] - coord[6] + coord[7]) * 12288;
  sum2 = (coord[8] - coord[9] - coord[10] + coord[11]) * 0;
  final_sum = sum0 + sum1 + sum2;

  if(final_sum >= (59 * stddev))
     return_value = 212;
  else
     return_value = -167;
  return return_value;
}
int classifier29( int_II II[WINDOW_SIZE][WINDOW_SIZE], int stddev ){
  static int coord[12];
  #pragma HLS array_partition variable=coord complete dim=0

  int sum0, sum1, sum2, final_sum;
  int return_value;
  coord[0] = II[6][6];
  coord[1] = II[6][9];
  coord[2] = II[18][6];
  coord[3] = II[18][9];

  coord[4] = II[12][6];
  coord[5] = II[12][9];
  coord[6] = II[18][6];
  coord[7] = II[18][9];

  coord[8] = 0;
  coord[9] = 0;
  coord[10] = 0;
  coord[11] = 0;

  sum0 = (coord[0] - coord[1] - coord[2] + coord[3]) * -4096;
  sum1 = (coord[4] - coord[5] - coord[6] + coord[7]) * 8192;
  sum2 = (coord[8] - coord[9] - coord[10] + coord[11]) * 0;
  final_sum = sum0 + sum1 + sum2;

  if(final_sum >= (-12 * stddev))
     return_value = 108;
  else
     return_value = -357;
  return return_value;
}
int classifier30( int_II II[WINDOW_SIZE][WINDOW_SIZE], int stddev ){
  static int coord[12];
  #pragma HLS array_partition variable=coord complete dim=0

  int sum0, sum1, sum2, final_sum;
  int return_value;
  coord[0] = II[21][3];
  coord[1] = II[21][21];
  coord[2] = II[24][3];
  coord[3] = II[24][21];

  coord[4] = II[21][9];
  coord[5] = II[21][15];
  coord[6] = II[24][9];
  coord[7] = II[24][15];

  coord[8] = 0;
  coord[9] = 0;
  coord[10] = 0;
  coord[11] = 0;

  sum0 = (coord[0] - coord[1] - coord[2] + coord[3]) * -4096;
  sum1 = (coord[4] - coord[5] - coord[6] + coord[7]) * 12288;
  sum2 = (coord[8] - coord[9] - coord[10] + coord[11]) * 0;
  final_sum = sum0 + sum1 + sum2;

  if(final_sum >= (134 * stddev))
     return_value = 269;
  else
     return_value = -129;
  return return_value;
}
int classifier31( int_II II[WINDOW_SIZE][WINDOW_SIZE], int stddev ){
  static int coord[12];
  #pragma HLS array_partition variable=coord complete dim=0

  int sum0, sum1, sum2, final_sum;
  int return_value;
  coord[0] = II[6][5];
  coord[1] = II[6][18];
  coord[2] = II[12][5];
  coord[3] = II[12][18];

  coord[4] = II[8][5];
  coord[5] = II[8][18];
  coord[6] = II[10][5];
  coord[7] = II[10][18];

  coord[8] = 0;
  coord[9] = 0;
  coord[10] = 0;
  coord[11] = 0;

  sum0 = (coord[0] - coord[1] - coord[2] + coord[3]) * -4096;
  sum1 = (coord[4] - coord[5] - coord[6] + coord[7]) * 12288;
  sum2 = (coord[8] - coord[9] - coord[10] + coord[11]) * 0;
  final_sum = sum0 + sum1 + sum2;

  if(final_sum >= (-29 * stddev))
     return_value = -344;
  else
     return_value = 93;
  return return_value;
}
int classifier32( int_II II[WINDOW_SIZE][WINDOW_SIZE], int stddev ){
  static int coord[12];
  #pragma HLS array_partition variable=coord complete dim=0

  int sum0, sum1, sum2, final_sum;
  int return_value;
  coord[0] = II[1][18];
  coord[1] = II[1][24];
  coord[2] = II[16][18];
  coord[3] = II[16][24];

  coord[4] = II[1][18];
  coord[5] = II[1][21];
  coord[6] = II[16][18];
  coord[7] = II[16][21];

  coord[8] = 0;
  coord[9] = 0;
  coord[10] = 0;
  coord[11] = 0;

  sum0 = (coord[0] - coord[1] - coord[2] + coord[3]) * -4096;
  sum1 = (coord[4] - coord[5] - coord[6] + coord[7]) * 8192;
  sum2 = (coord[8] - coord[9] - coord[10] + coord[11]) * 0;
  final_sum = sum0 + sum1 + sum2;

  if(final_sum >= (206 * stddev))
     return_value = 371;
  else
     return_value = -77;
  return return_value;
}
int classifier33( int_II II[WINDOW_SIZE][WINDOW_SIZE], int stddev ){
  static int coord[12];
  #pragma HLS array_partition variable=coord complete dim=0

  int sum0, sum1, sum2, final_sum;
  int return_value;
  coord[0] = II[1][1];
  coord[1] = II[1][7];
  coord[2] = II[16][1];
  coord[3] = II[16][7];

  coord[4] = II[1][4];
  coord[5] = II[1][7];
  coord[6] = II[16][4];
  coord[7] = II[16][7];

  coord[8] = 0;
  coord[9] = 0;
  coord[10] = 0;
  coord[11] = 0;

  sum0 = (coord[0] - coord[1] - coord[2] + coord[3]) * -4096;
  sum1 = (coord[4] - coord[5] - coord[6] + coord[7]) * 8192;
  sum2 = (coord[8] - coord[9] - coord[10] + coord[11]) * 0;
  final_sum = sum0 + sum1 + sum2;

  if(final_sum >= (192 * stddev))
     return_value = 310;
  else
     return_value = -103;
  return return_value;
}
int classifier34( int_II II[WINDOW_SIZE][WINDOW_SIZE], int stddev ){
  static int coord[12];
  #pragma HLS array_partition variable=coord complete dim=0

  int sum0, sum1, sum2, final_sum;
  int return_value;
  coord[0] = II[8][0];
  coord[1] = II[8][24];
  coord[2] = II[23][0];
  coord[3] = II[23][24];

  coord[4] = II[8][8];
  coord[5] = II[8][16];
  coord[6] = II[23][8];
  coord[7] = II[23][16];

  coord[8] = 0;
  coord[9] = 0;
  coord[10] = 0;
  coord[11] = 0;

  sum0 = (coord[0] - coord[1] - coord[2] + coord[3]) * -4096;
  sum1 = (coord[4] - coord[5] - coord[6] + coord[7]) * 12288;
  sum2 = (coord[8] - coord[9] - coord[10] + coord[11]) * 0;
  final_sum = sum0 + sum1 + sum2;

  if(final_sum >= (-284 * stddev))
     return_value = -117;
  else
     return_value = 269;
  return return_value;
}
int classifier35( int_II II[WINDOW_SIZE][WINDOW_SIZE], int stddev ){
  static int coord[12];
  #pragma HLS array_partition variable=coord complete dim=0

  int sum0, sum1, sum2, final_sum;
  int return_value;
  coord[0] = II[6][5];
  coord[1] = II[6][19];
  coord[2] = II[18][5];
  coord[3] = II[18][19];

  coord[4] = II[6][5];
  coord[5] = II[6][12];
  coord[6] = II[12][5];
  coord[7] = II[12][12];

  coord[8] = II[12][12];
  coord[9] = II[12][19];
  coord[10] = II[18][12];
  coord[11] = II[18][19];

  sum0 = (coord[0] - coord[1] - coord[2] + coord[3]) * -4096;
  sum1 = (coord[4] - coord[5] - coord[6] + coord[7]) * 8192;
  sum2 = (coord[8] - coord[9] - coord[10] + coord[11]) * 8192;
  final_sum = sum0 + sum1 + sum2;

  if(final_sum >= (-200 * stddev))
     return_value = 39;
  else
     return_value = -416;
  return return_value;
}
int classifier36( int_II II[WINDOW_SIZE][WINDOW_SIZE], int stddev ){
  static int coord[12];
  #pragma HLS array_partition variable=coord complete dim=0

  int sum0, sum1, sum2, final_sum;
  int return_value;
  coord[0] = II[12][2];
  coord[1] = II[12][23];
  coord[2] = II[24][2];
  coord[3] = II[24][23];

  coord[4] = II[16][2];
  coord[5] = II[16][23];
  coord[6] = II[20][2];
  coord[7] = II[20][23];

  coord[8] = 0;
  coord[9] = 0;
  coord[10] = 0;
  coord[11] = 0;

  sum0 = (coord[0] - coord[1] - coord[2] + coord[3]) * -4096;
  sum1 = (coord[4] - coord[5] - coord[6] + coord[7]) * 12288;
  sum2 = (coord[8] - coord[9] - coord[10] + coord[11]) * 0;
  final_sum = sum0 + sum1 + sum2;

  if(final_sum >= (347 * stddev))
     return_value = -400;
  else
     return_value = 72;
  return return_value;
}
int classifier37( int_II II[WINDOW_SIZE][WINDOW_SIZE], int stddev ){
  static int coord[12];
  #pragma HLS array_partition variable=coord complete dim=0

  int sum0, sum1, sum2, final_sum;
  int return_value;
  coord[0] = II[1][8];
  coord[1] = II[1][12];
  coord[2] = II[11][8];
  coord[3] = II[11][12];

  coord[4] = II[1][10];
  coord[5] = II[1][12];
  coord[6] = II[11][10];
  coord[7] = II[11][12];

  coord[8] = 0;
  coord[9] = 0;
  coord[10] = 0;
  coord[11] = 0;

  sum0 = (coord[0] - coord[1] - coord[2] + coord[3]) * -4096;
  sum1 = (coord[4] - coord[5] - coord[6] + coord[7]) * 8192;
  sum2 = (coord[8] - coord[9] - coord[10] + coord[11]) * 0;
  final_sum = sum0 + sum1 + sum2;

  if(final_sum >= (-7 * stddev))
     return_value = 59;
  else
     return_value = -259;
  return return_value;
}
int classifier38( int_II II[WINDOW_SIZE][WINDOW_SIZE], int stddev ){
  static int coord[12];
  #pragma HLS array_partition variable=coord complete dim=0

  int sum0, sum1, sum2, final_sum;
  int return_value;
  coord[0] = II[13][2];
  coord[1] = II[13][22];
  coord[2] = II[23][2];
  coord[3] = II[23][22];

  coord[4] = II[13][2];
  coord[5] = II[13][12];
  coord[6] = II[23][2];
  coord[7] = II[23][12];

  coord[8] = 0;
  coord[9] = 0;
  coord[10] = 0;
  coord[11] = 0;

  sum0 = (coord[0] - coord[1] - coord[2] + coord[3]) * -4096;
  sum1 = (coord[4] - coord[5] - coord[6] + coord[7]) * 8192;
  sum2 = (coord[8] - coord[9] - coord[10] + coord[11]) * 0;
  final_sum = sum0 + sum1 + sum2;

  if(final_sum >= (473 * stddev))
     return_value = 327;
  else
     return_value = -42;
  return return_value;
}
int classifier39( int_II II[WINDOW_SIZE][WINDOW_SIZE], int stddev ){
  static int coord[12];
  #pragma HLS array_partition variable=coord complete dim=0

  int sum0, sum1, sum2, final_sum;
  int return_value;
  coord[0] = II[1][0];
  coord[1] = II[1][6];
  coord[2] = II[14][0];
  coord[3] = II[14][6];

  coord[4] = II[1][2];
  coord[5] = II[1][4];
  coord[6] = II[14][2];
  coord[7] = II[14][4];

  coord[8] = 0;
  coord[9] = 0;
  coord[10] = 0;
  coord[11] = 0;

  sum0 = (coord[0] - coord[1] - coord[2] + coord[3]) * -4096;
  sum1 = (coord[4] - coord[5] - coord[6] + coord[7]) * 12288;
  sum2 = (coord[8] - coord[9] - coord[10] + coord[11]) * 0;
  final_sum = sum0 + sum1 + sum2;

  if(final_sum >= (-210 * stddev))
     return_value = -77;
  else
     return_value = 388;
  return return_value;
}
int classifier40( int_II II[WINDOW_SIZE][WINDOW_SIZE], int stddev ){
  static int coord[12];
  #pragma HLS array_partition variable=coord complete dim=0

  int sum0, sum1, sum2, final_sum;
  int return_value;
  coord[0] = II[2][20];
  coord[1] = II[2][24];
  coord[2] = II[15][20];
  coord[3] = II[15][24];

  coord[4] = II[2][20];
  coord[5] = II[2][22];
  coord[6] = II[15][20];
  coord[7] = II[15][22];

  coord[8] = 0;
  coord[9] = 0;
  coord[10] = 0;
  coord[11] = 0;

  sum0 = (coord[0] - coord[1] - coord[2] + coord[3]) * -4096;
  sum1 = (coord[4] - coord[5] - coord[6] + coord[7]) * 8192;
  sum2 = (coord[8] - coord[9] - coord[10] + coord[11]) * 0;
  final_sum = sum0 + sum1 + sum2;

  if(final_sum >= (-174 * stddev))
     return_value = -13;
  else
     return_value = 451;
  return return_value;
}
int classifier41( int_II II[WINDOW_SIZE][WINDOW_SIZE], int stddev ){
  static int coord[12];
  #pragma HLS array_partition variable=coord complete dim=0

  int sum0, sum1, sum2, final_sum;
  int return_value;
  coord[0] = II[5][0];
  coord[1] = II[5][22];
  coord[2] = II[24][0];
  coord[3] = II[24][22];

  coord[4] = II[5][11];
  coord[5] = II[5][22];
  coord[6] = II[24][11];
  coord[7] = II[24][22];

  coord[8] = 0;
  coord[9] = 0;
  coord[10] = 0;
  coord[11] = 0;

  sum0 = (coord[0] - coord[1] - coord[2] + coord[3]) * -4096;
  sum1 = (coord[4] - coord[5] - coord[6] + coord[7]) * 8192;
  sum2 = (coord[8] - coord[9] - coord[10] + coord[11]) * 0;
  final_sum = sum0 + sum1 + sum2;

  if(final_sum >= (1522 * stddev))
     return_value = 393;
  else
     return_value = -80;
  return return_value;
}
int classifier42( int_II II[WINDOW_SIZE][WINDOW_SIZE], int stddev ){
  static int coord[12];
  #pragma HLS array_partition variable=coord complete dim=0

  int sum0, sum1, sum2, final_sum;
  int return_value;
  coord[0] = II[4][18];
  coord[1] = II[4][24];
  coord[2] = II[13][18];
  coord[3] = II[13][24];

  coord[4] = II[4][20];
  coord[5] = II[4][22];
  coord[6] = II[13][20];
  coord[7] = II[13][22];

  coord[8] = 0;
  coord[9] = 0;
  coord[10] = 0;
  coord[11] = 0;

  sum0 = (coord[0] - coord[1] - coord[2] + coord[3]) * -4096;
  sum1 = (coord[4] - coord[5] - coord[6] + coord[7]) * 12288;
  sum2 = (coord[8] - coord[9] - coord[10] + coord[11]) * 0;
  final_sum = sum0 + sum1 + sum2;

  if(final_sum >= (79 * stddev))
     return_value = 239;
  else
     return_value = -25;
  return return_value;
}
int classifier43( int_II II[WINDOW_SIZE][WINDOW_SIZE], int stddev ){
  static int coord[12];
  #pragma HLS array_partition variable=coord complete dim=0

  int sum0, sum1, sum2, final_sum;
  int return_value;
  coord[0] = II[3][0];
  coord[1] = II[3][6];
  coord[2] = II[14][0];
  coord[3] = II[14][6];

  coord[4] = II[3][2];
  coord[5] = II[3][4];
  coord[6] = II[14][2];
  coord[7] = II[14][4];

  coord[8] = 0;
  coord[9] = 0;
  coord[10] = 0;
  coord[11] = 0;

  sum0 = (coord[0] - coord[1] - coord[2] + coord[3]) * -4096;
  sum1 = (coord[4] - coord[5] - coord[6] + coord[7]) * 12288;
  sum2 = (coord[8] - coord[9] - coord[10] + coord[11]) * 0;
  final_sum = sum0 + sum1 + sum2;

  if(final_sum >= (71 * stddev))
     return_value = 246;
  else
     return_value = -103;
  return return_value;
}
int classifier44( int_II II[WINDOW_SIZE][WINDOW_SIZE], int stddev ){
  static int coord[12];
  #pragma HLS array_partition variable=coord complete dim=0

  int sum0, sum1, sum2, final_sum;
  int return_value;
  coord[0] = II[1][12];
  coord[1] = II[1][16];
  coord[2] = II[10][12];
  coord[3] = II[10][16];

  coord[4] = II[1][12];
  coord[5] = II[1][14];
  coord[6] = II[10][12];
  coord[7] = II[10][14];

  coord[8] = 0;
  coord[9] = 0;
  coord[10] = 0;
  coord[11] = 0;

  sum0 = (coord[0] - coord[1] - coord[2] + coord[3]) * -4096;
  sum1 = (coord[4] - coord[5] - coord[6] + coord[7]) * 8192;
  sum2 = (coord[8] - coord[9] - coord[10] + coord[11]) * 0;
  final_sum = sum0 + sum1 + sum2;

  if(final_sum >= (162 * stddev))
     return_value = -757;
  else
     return_value = 43;
  return return_value;
}
int classifier45( int_II II[WINDOW_SIZE][WINDOW_SIZE], int stddev ){
  static int coord[12];
  #pragma HLS array_partition variable=coord complete dim=0

  int sum0, sum1, sum2, final_sum;
  int return_value;
  coord[0] = II[6][0];
  coord[1] = II[6][19];
  coord[2] = II[9][0];
  coord[3] = II[9][19];

  coord[4] = II[7][0];
  coord[5] = II[7][19];
  coord[6] = II[8][0];
  coord[7] = II[8][19];

  coord[8] = 0;
  coord[9] = 0;
  coord[10] = 0;
  coord[11] = 0;

  sum0 = (coord[0] - coord[1] - coord[2] + coord[3]) * -4096;
  sum1 = (coord[4] - coord[5] - coord[6] + coord[7]) * 12288;
  sum2 = (coord[8] - coord[9] - coord[10] + coord[11]) * 0;
  final_sum = sum0 + sum1 + sum2;

  if(final_sum >= (-37 * stddev))
     return_value = -112;
  else
     return_value = 227;
  return return_value;
}
int classifier46( int_II II[WINDOW_SIZE][WINDOW_SIZE], int stddev ){
  static int coord[12];
  #pragma HLS array_partition variable=coord complete dim=0

  int sum0, sum1, sum2, final_sum;
  int return_value;
  coord[0] = II[1][12];
  coord[1] = II[1][16];
  coord[2] = II[10][12];
  coord[3] = II[10][16];

  coord[4] = II[1][12];
  coord[5] = II[1][14];
  coord[6] = II[10][12];
  coord[7] = II[10][14];

  coord[8] = 0;
  coord[9] = 0;
  coord[10] = 0;
  coord[11] = 0;

  sum0 = (coord[0] - coord[1] - coord[2] + coord[3]) * -4096;
  sum1 = (coord[4] - coord[5] - coord[6] + coord[7]) * 8192;
  sum2 = (coord[8] - coord[9] - coord[10] + coord[11]) * 0;
  final_sum = sum0 + sum1 + sum2;

  if(final_sum >= (7 * stddev))
     return_value = 102;
  else
     return_value = -95;
  return return_value;
}
int classifier47( int_II II[WINDOW_SIZE][WINDOW_SIZE], int stddev ){
  static int coord[12];
  #pragma HLS array_partition variable=coord complete dim=0

  int sum0, sum1, sum2, final_sum;
  int return_value;
  coord[0] = II[1][8];
  coord[1] = II[1][12];
  coord[2] = II[10][8];
  coord[3] = II[10][12];

  coord[4] = II[1][10];
  coord[5] = II[1][12];
  coord[6] = II[10][10];
  coord[7] = II[10][12];

  coord[8] = 0;
  coord[9] = 0;
  coord[10] = 0;
  coord[11] = 0;

  sum0 = (coord[0] - coord[1] - coord[2] + coord[3]) * -4096;
  sum1 = (coord[4] - coord[5] - coord[6] + coord[7]) * 8192;
  sum2 = (coord[8] - coord[9] - coord[10] + coord[11]) * 0;
  final_sum = sum0 + sum1 + sum2;

  if(final_sum >= (123 * stddev))
     return_value = -677;
  else
     return_value = 16;
  return return_value;
}
int classifier48( int_II II[WINDOW_SIZE][WINDOW_SIZE], int stddev ){
  static int coord[12];
  #pragma HLS array_partition variable=coord complete dim=0

  int sum0, sum1, sum2, final_sum;
  int return_value;
  coord[0] = II[5][5];
  coord[1] = II[5][19];
  coord[2] = II[19][5];
  coord[3] = II[19][19];

  coord[4] = II[5][12];
  coord[5] = II[5][19];
  coord[6] = II[12][12];
  coord[7] = II[12][19];

  coord[8] = II[12][5];
  coord[9] = II[12][12];
  coord[10] = II[19][5];
  coord[11] = II[19][12];

  sum0 = (coord[0] - coord[1] - coord[2] + coord[3]) * -4096;
  sum1 = (coord[4] - coord[5] - coord[6] + coord[7]) * 8192;
  sum2 = (coord[8] - coord[9] - coord[10] + coord[11]) * 8192;
  final_sum = sum0 + sum1 + sum2;

  if(final_sum >= (-322 * stddev))
     return_value = 72;
  else
     return_value = -447;
  return return_value;
}
int classifier49( int_II II[WINDOW_SIZE][WINDOW_SIZE], int stddev ){
  static int coord[12];
  #pragma HLS array_partition variable=coord complete dim=0

  int sum0, sum1, sum2, final_sum;
  int return_value;
  coord[0] = II[10][1];
  coord[1] = II[10][19];
  coord[2] = II[12][1];
  coord[3] = II[12][19];

  coord[4] = II[11][1];
  coord[5] = II[11][19];
  coord[6] = II[12][1];
  coord[7] = II[12][19];

  coord[8] = 0;
  coord[9] = 0;
  coord[10] = 0;
  coord[11] = 0;

  sum0 = (coord[0] - coord[1] - coord[2] + coord[3]) * -4096;
  sum1 = (coord[4] - coord[5] - coord[6] + coord[7]) * 8192;
  sum2 = (coord[8] - coord[9] - coord[10] + coord[11]) * 0;
  final_sum = sum0 + sum1 + sum2;

  if(final_sum >= (8 * stddev))
     return_value = 59;
  else
     return_value = -240;
  return return_value;
}
int classifier50( int_II II[WINDOW_SIZE][WINDOW_SIZE], int stddev ){
  static int coord[12];
  #pragma HLS array_partition variable=coord complete dim=0

  int sum0, sum1, sum2, final_sum;
  int return_value;
  coord[0] = II[13][17];
  coord[1] = II[13][21];
  coord[2] = II[24][17];
  coord[3] = II[24][21];

  coord[4] = II[13][17];
  coord[5] = II[13][19];
  coord[6] = II[24][17];
  coord[7] = II[24][19];

  coord[8] = 0;
  coord[9] = 0;
  coord[10] = 0;
  coord[11] = 0;

  sum0 = (coord[0] - coord[1] - coord[2] + coord[3]) * -4096;
  sum1 = (coord[4] - coord[5] - coord[6] + coord[7]) * 8192;
  sum2 = (coord[8] - coord[9] - coord[10] + coord[11]) * 0;
  final_sum = sum0 + sum1 + sum2;

  if(final_sum >= (110 * stddev))
     return_value = 275;
  else
     return_value = -13;
  return return_value;
}
int classifier51( int_II II[WINDOW_SIZE][WINDOW_SIZE], int stddev ){
  static int coord[12];
  #pragma HLS array_partition variable=coord complete dim=0

  int sum0, sum1, sum2, final_sum;
  int return_value;
  coord[0] = II[4][0];
  coord[1] = II[4][6];
  coord[2] = II[13][0];
  coord[3] = II[13][6];

  coord[4] = II[7][0];
  coord[5] = II[7][6];
  coord[6] = II[10][0];
  coord[7] = II[10][6];

  coord[8] = 0;
  coord[9] = 0;
  coord[10] = 0;
  coord[11] = 0;

  sum0 = (coord[0] - coord[1] - coord[2] + coord[3]) * -4096;
  sum1 = (coord[4] - coord[5] - coord[6] + coord[7]) * 12288;
  sum2 = (coord[8] - coord[9] - coord[10] + coord[11]) * 0;
  final_sum = sum0 + sum1 + sum2;

  if(final_sum >= (-184 * stddev))
     return_value = 25;
  else
     return_value = -468;
  return return_value;
}

/****************************************************************************************/
/* FUNCTION DECLARATIONS
****************************************************************************************/
void imageScaler        ( unsigned char Data[IMAGE_HEIGHT*IMAGE_WIDTH+1],
                          unsigned char IMG1_data[IMAGE_HEIGHT][IMAGE_WIDTH] 
                        );

void processImage       (
                          int *AllCandidates_x,
                          int *AllCandidates_y,
                          int *AllCandidates_w,
                          int *AllCandidates_h,
                          int *AllCandidates_size,
                          unsigned char IMG1_data[IMAGE_HEIGHT][IMAGE_WIDTH]
                        );

void cascadeClassifier   (
                          int_II II[WINDOW_SIZE][WINDOW_SIZE],
                          int_SII SII[SQ_SIZE][SQ_SIZE],
						  int *result
                        );

void cascadeClassifier_1   (
                          int data_in[629],
						  int data_out[631]
                        );


void cascadeClassifier_2   (
						  int data_in[631],
						  int *result
                        );






int weakClassifier      ( int stddev,
                          uint18_t coord[12],
                          int haar_counter,
                          int w_id                      
                        );

void groupRectangles    ( MyRect *rectList, 
                          int *rectList_size, 
                          int groupThreshold, 
                          float eps
                        );

unsigned int int_sqrt   ( ap_uint<32> value
                        );

void IntegralImageCal(
						unsigned char data_in[3],
						int data_out[629]
						);

inline  int  myRound ( float value )
{
  return (int)(value + (value >= 0 ? 0.5 : -0.5));
}

//========================================================================================
// TOP LEVEL MODULE OR DUT (DEVICE UNDER TEST) 
//========================================================================================

void face_detect

( 
  unsigned char inData[IMAGE_HEIGHT][IMAGE_WIDTH],
  int result_x[RESULT_SIZE],
  int result_y[RESULT_SIZE],
  int result_w[RESULT_SIZE],
  int result_h[RESULT_SIZE],
  int *result_size
)

{

 MyPoint p;
 int result;

  int x,y,i,j,k;
  static int sum_row=0;
  static int sum_col=0;

  /** Integral Image Window buffer ( 625 registers )*/
  static int_II II[WINDOW_SIZE][WINDOW_SIZE];
  #pragma HLS array_partition variable=II complete dim=0


  /** Square Integral Image Window buffer ( 625 registers )*/
  static int_SII SII[SQ_SIZE][SQ_SIZE];
  #pragma HLS array_partition variable=SII complete dim=0




  int result_x_Scale[RESULT_SIZE];
  int result_y_Scale[RESULT_SIZE];
  int result_w_Scale[RESULT_SIZE];
  int result_h_Scale[RESULT_SIZE];
  int res_size_Scale = 0;
  int *result_size_Scale = &res_size_Scale;

  for ( i = 0; i < RESULT_SIZE; i++){
	result_x[i] = 0;
	result_y[i] = 0;
	result_w[i] = 0;
	result_h[i] = 0;
  }

  *result_size = 0;
    
  float  scaleFactor = 1.2;

  unsigned char IMG1_data[IMAGE_HEIGHT][IMAGE_WIDTH];  

  int height, width;   
  float factor;

  MySize winSize0;
  winSize0.width = 24;
  winSize0.height= 24;

  factor = scaleFactor ;
  static int LoadOrScale = 1;
  unsigned char data_tmp_1[IMAGE_HEIGHT*IMAGE_WIDTH+1];
  data_tmp_1[0] = LoadOrScale;
  for( i = 0; i < IMAGE_HEIGHT; i++){
    for( j = 0; j < IMAGE_WIDTH; j++){
    	data_tmp_1[i*IMAGE_WIDTH+j+1] = inData[i][j];
    }
  }


  imageScaler(data_tmp_1, IMG1_data);

  LoadOrScale = 0;

  int times = 0;
  L1: 
  while ( IMAGE_WIDTH/factor > WINDOW_SIZE && IMAGE_HEIGHT/factor > WINDOW_SIZE )
  {


    /* size of the image scaled up */
    MySize winSize = { myRound(winSize0.width*factor), myRound(winSize0.height*factor) };
    /* size of the image scaled down (from bigger to smaller) */
    MySize sz = { (int)( IMAGE_WIDTH/factor ), (int)( IMAGE_HEIGHT/factor ) };

    height = sz.height;
    width  = sz.width;
    data_tmp_1[0] = LoadOrScale;
    imageScaler(data_tmp_1, IMG1_data);

    sum_row=height;
    sum_col=width;
    printf("times = %d\n", times);
    times += 1;

    unsigned char data_tmp_2[3];
    data_tmp_2[0] = 1;
    data_tmp_2[1] = 0;
    data_tmp_2[2] = 0;
    int data_tmp_3[629];
    int data_tmp_4[631];
    IntegralImageCal(data_tmp_2, data_tmp_3);

    int element_counter = 0;
    int x_index = 0;
    int y_index = 0;


    /** Loop over each point in the Image ( scaled ) **/
    Pixely: for( y = 0; y < sum_row; y++ ){
      Pixelx : for ( x = 0; x < sum_col; x++ ){
    	data_tmp_2[0] = 0;
    	data_tmp_2[1] = x;
    	data_tmp_2[2] = IMG1_data[y][x];

        IntegralImageCal(data_tmp_2, data_tmp_3);

        if ( element_counter >= ( ( (WINDOW_SIZE-1)*sum_col + WINDOW_SIZE ) + WINDOW_SIZE -1 ) ) {
           if ( x_index < ( sum_col - (WINDOW_SIZE-1) ) && y_index < ( sum_row - (WINDOW_SIZE-1) ) ){
              p.x = x_index;
              p.y = y_index;
              int stddev_tmp_1;
              int stddev_tmp_2;
              int stddev_tmp_3;
              int result_tmp_1;
              int result_tmp_2;
              int result_tmp_3;
              //cascadeClassifier (II, SII, &result);
              cascadeClassifier_1 (data_tmp_3, data_tmp_4);
              stddev_tmp_1 = data_tmp_4[0];
              result_tmp_1 = data_tmp_4[1];
          	for (int u = 0; u < WINDOW_SIZE; u++){
          	  for (int v = 0; v < WINDOW_SIZE; v++ ){
          		  II[u][v] = data_tmp_4[u*WINDOW_SIZE+v+2];
          	  }
          	}
          	SII[0][0] = data_tmp_4[WINDOW_SIZE*WINDOW_SIZE+2];
          	SII[0][1] = data_tmp_4[WINDOW_SIZE*WINDOW_SIZE+3];
          	SII[1][0] = data_tmp_4[WINDOW_SIZE*WINDOW_SIZE+4];
          	SII[1][1] = data_tmp_4[WINDOW_SIZE*WINDOW_SIZE+5];
              cascadeClassifier_2 (data_tmp_4, &result_tmp_2);

              result = result_tmp_2;

             if ( result > 0 )
             {
               MyRect r = {myRound(p.x*factor), myRound(p.y*factor), winSize.width, winSize.height};
               result_x_Scale[*result_size_Scale]=r.x;
               result_y_Scale[*result_size_Scale]=r.y;
               result_w_Scale[*result_size_Scale]=r.width;
               result_h_Scale[*result_size_Scale]=r.height;
              *result_size_Scale=*result_size_Scale+1;
             }
           }// inner if
           if ( x_index < sum_col-1 )
               x_index = x_index + 1;
           else{
               x_index = 0;
               y_index = y_index + 1;
           }
         } // outer if
         element_counter +=1;
      }
    }


    factor *= scaleFactor;
  } /* end of the factor loop, finish all scales in pyramid*/

   for ( i = 0; i < RESULT_SIZE; i++){
      result_x[i] = result_x_Scale[i];
      result_y[i] = result_y_Scale[i];
      result_w[i] = result_w_Scale[i];
      result_h[i] = result_h_Scale[i];
   }
   *result_size = *result_size_Scale;
}



void IntegralImageCal(
						unsigned char data_in[3],
						int data_out[625]
						)
{
#pragma HLS INTERFACE ap_hs port=SII_out
#pragma HLS INTERFACE ap_hs port=II_out
#pragma HLS INTERFACE ap_hs port=data_in

	int u, v, i, j, k;
	  /** Image Line buffer ( 24 BRAMs ) */
	static unsigned char L[WINDOW_SIZE-1][IMAGE_WIDTH];
	//#pragma HLS ARRAY_PARTITION variable=L block factor=WINDOW_SIZE-1 dim=1

	  /** Image Window buffer ( 1250 registers )*/
	static int_I I[WINDOW_SIZE][2*WINDOW_SIZE];
	//#pragma HLS array_partition variable=I complete dim=0


	/** Square Image Window buffer ( 1250 registers ) **/
	static int_SI SI[WINDOW_SIZE][2*WINDOW_SIZE];
	//#pragma HLS array_partition variable=SI complete dim=0

	static int_II II[WINDOW_SIZE][WINDOW_SIZE];
	static int_SII SII[SQ_SIZE][SQ_SIZE];
	int load;
	int x;
	unsigned char IMG1_data_y_x;
	load = data_in[0];
	x = data_in[1];
	IMG1_data_y_x = data_in[2];

	if(load){
	  Initialize0u :
	  for ( u = 0; u < WINDOW_SIZE; u++ ){
	  //#pragma HLS unroll
	    Initailize0v:
	    for ( v = 0; v < WINDOW_SIZE; v++ ){
	    //#pragma HLS unroll
	      II[u][v] = 0;
	    }
	  }

	  SII[0][0] = 0;
	  SII[0][1] = 0;
	  SII[1][0] = 0;
	  SII[1][1] = 0;


	  Initialize1i:
	  for ( i = 0; i < WINDOW_SIZE ; i++ ){
	  //#pragma HLS unroll
	    Initialize1j:
	    for ( j = 0; j < 2*WINDOW_SIZE; j++ ){
	    //#pragma HLS unroll
	      I[i][j] = 0;
	      SI[i][j] = 0;
	    }
	  }


	  Initialize2y :
	  for ( int L_y = 0; L_y < WINDOW_SIZE-1; L_y++ ){
	  #pragma HLS unroll
	    Initialize2x :
	    for ( int L_x = 0; L_x < IMAGE_WIDTH ; L_x++){//IMAGE_WIDTH; x++ ){
	      L[L_y][L_x] = 0;
	    }
	  }
	  return;
	}


    /* Updates for Integral Image Window Buffer (I) */
    SetIIu: for ( u = 0; u < WINDOW_SIZE; u++){
    //#pragma HLS unroll
      SetIIj: for ( v = 0; v < WINDOW_SIZE; v++ ){
      //#pragma HLS unroll
        II[u][v] = II[u][v] + ( I[u][v+1] - I[u][0] );
      }
    }

    /* Updates for Square Integral Image Window Buffer (SI) */
    SII[0][0] = SII[0][0] + ( SI[0][1] - SI[0][0] );
    SII[0][1] = SII[0][1] + ( SI[0][WINDOW_SIZE] - SI[0][0] );
    SII[1][0] = SII[1][0] + ( SI[WINDOW_SIZE-1][1] - SI[WINDOW_SIZE-1][0] );
    SII[1][1] = SII[1][1] + ( SI[WINDOW_SIZE-1][WINDOW_SIZE] - SI[WINDOW_SIZE-1][0] );

    /* Updates for Image Window Buffer (I) and Square Image Window Bufer (SI) */
    SetIj: for( j = 0; j < 2*WINDOW_SIZE-1; j++){
    //#pragma HLS unroll
      SetIi: for( i = 0; i < WINDOW_SIZE; i++ ){
      //#pragma HLS unroll
        if( i+j != 2*WINDOW_SIZE-1 ){
          I[i][j] = I[i][j+1];
          SI[i][j] = SI[i][j+1];
        }
        else if ( i > 0 ){
          I[i][j] = I[i][j+1] + I[i-1][j+1];
          SI[i][j] = SI[i][j+1] + SI[i-1][j+1];
        }
      }
    }
    /** Last column of the I[][] matrix **/
    Ilast: for( i = 0; i < WINDOW_SIZE-1; i++ ){
    //#pragma HLS unroll
      I[i][2*WINDOW_SIZE-1] = L[i][x];
      SI[i][2*WINDOW_SIZE-1] = L[i][x]*L[i][x];
    }
    I[WINDOW_SIZE-1][2*WINDOW_SIZE-1] = IMG1_data_y_x;
    SI[WINDOW_SIZE-1][2*WINDOW_SIZE-1] = IMG1_data_y_x*IMG1_data_y_x;

    /** Updates for Image Line Buffer (L) **/
    LineBuf: for( k = 0; k < WINDOW_SIZE-2; k++ ){
    #pragma HLS unroll
      L[k][x] = L[k+1][x];
    }
    L[WINDOW_SIZE-2][x] = IMG1_data_y_x;

	for ( u = 0; u < WINDOW_SIZE; u++){
	  for ( v = 0; v < WINDOW_SIZE; v++ ){
		  data_out[u*WINDOW_SIZE+v] = II[u][v];
	  }
	}
	data_out[WINDOW_SIZE*WINDOW_SIZE]   = SII[0][0];
	data_out[WINDOW_SIZE*WINDOW_SIZE+1] = SII[0][1];
	data_out[WINDOW_SIZE*WINDOW_SIZE+2] = SII[1][0];
	data_out[WINDOW_SIZE*WINDOW_SIZE+3] = SII[1][1];

}

void cascadeClassifier
(  
  int_II II_in[WINDOW_SIZE][WINDOW_SIZE],
  int_SII SII_in[SQ_SIZE][SQ_SIZE],
  int *result
) 

{
#pragma HLS INTERFACE ap_hs port=result
#pragma HLS INTERFACE ap_hs port=SII_in
#pragma HLS INTERFACE ap_hs port=II_in
  #pragma HLS INLINE

  int_II II[WINDOW_SIZE][WINDOW_SIZE];
  int_SII SII[SQ_SIZE][SQ_SIZE];
  int i, j, k;

  int mean;
  int stddev = 0;
  int haar_counter = 0;
  int w_index = 0;
  int r_index = 0;
  int stage_sum=0;

  /* The rectangle co-ordinagte values for all the classifiers */
  #include "haar_dataRcc_with_partitioning.h"
 
  static uint18_t coord[12];
  #pragma HLS array_partition variable=coord complete dim=0

  static int s0[9];
  #pragma HLS array_partition variable=s0 complete dim=0

  static int s1[16];
  #pragma HLS array_partition variable=s1 complete dim=0

  static int s2[27];
  #pragma HLS array_partition variable=s2 complete dim=0

  /* Banking */

  /* 12 (x,y,w,h) values corresponding to 3 rectangles that need to be read */
  uint18_t values[12];
  #pragma HLS array_partition variable=values complete dim=0

  /* location/address of those 12 values in the 25 X 25 window */
  uint10_t addr_list[12];
  #pragma HLS array_partition variable=addr_list complete dim=0

  /* among the 12 values which of them are needed to be read from the 25 X 25 window */
  bit enable_list[12] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
  #pragma HLS array_partition variable=enable_list complete dim=0  
  
  uint18_t _II[WINDOW_SIZE*WINDOW_SIZE];
  #pragma HLS array_partition variable=_II complete dim=0

	for ( int u = 0; u < WINDOW_SIZE; u++){
	  for ( int v = 0; v < WINDOW_SIZE; v++ ){
		  II[u][v] = II_in[u][v];
	  }
	}
	SII[0][0] = SII_in[0][0];
	SII[0][1] = SII_in[0][1];
	SII[1][0] = SII_in[1][0];
	SII[1][1] = SII_in[1][1];


  COPY_LOOP1: for (int i = 0; i < WINDOW_SIZE; i ++ ){
    #pragma HLS unroll
    COPY_LOOP2: for (int j = 0; j < WINDOW_SIZE; j ++ ){
      #pragma HLS unroll
      _II[i*25+j] = II[i][j];
    }
  }

  stddev =                    SII[0][0]
                           -  SII[0][SQ_SIZE- 1]
                           -  SII[SQ_SIZE-1][0] 
                           +  SII[SQ_SIZE-1][SQ_SIZE-1]; 

  mean =                      II[0][0]
                           -  II[0][WINDOW_SIZE - 1]
                           -  II[WINDOW_SIZE - 1][0] 
                           +  II[WINDOW_SIZE - 1][WINDOW_SIZE - 1];
      
  stddev = (stddev*(WINDOW_SIZE-1)*(WINDOW_SIZE-1));
  stddev =  stddev - mean*mean; 
  
  if( stddev > 0 )
    stddev = int_sqrt(stddev);  
  else
    stddev = 1;

  MyRect tr0,tr1,tr2;
  
  int r_id;
  int w_id;
  int s;

  /* Hard-Coding Classifier 0 */
  stage_sum = 0;
  s0[0] = classifier0( II, stddev );
  s0[1] = classifier1( II, stddev );
  s0[2] = classifier2( II, stddev );
  s0[3] = classifier3( II, stddev );
  s0[4] = classifier4( II, stddev );
  s0[5] = classifier5( II, stddev );
  s0[6] = classifier6( II, stddev );
  s0[7] = classifier7( II, stddev );
  s0[8] = classifier8( II, stddev );
  stage_sum = s0[0] + s0[1] + s0[2] + s0[3] + s0[4] + s0[5] + s0[6] + s0[7] + s0[8];

  if( stage_sum < 0.4*stages_thresh_array[0] ){
	  *result = -1;
	  return;
  }


  haar_counter += 9;

  /* Hard-Coding Classifier 1 */
  stage_sum = 0;
  s1[0] = classifier9( II, stddev );
  s1[1] = classifier10( II, stddev );
  s1[2] = classifier11( II, stddev );
  s1[3] = classifier12( II, stddev );
  s1[4] = classifier13( II, stddev );
  s1[5] = classifier14( II, stddev );
  s1[6] = classifier15( II, stddev );
  s1[7] = classifier16( II, stddev );
  s1[8] = classifier17( II, stddev );
  s1[9] = classifier18( II, stddev );
  s1[10] = classifier19( II, stddev );
  s1[11] = classifier20( II, stddev );
  s1[12] = classifier21( II, stddev );
  s1[13] = classifier22( II, stddev );
  s1[14] = classifier23( II, stddev );
  s1[15] = classifier24( II, stddev );

  stage_sum = s1[0] + s1[1] + s1[2] + s1[3] + s1[4] + s1[5] + s1[6] + s1[7];
  stage_sum+= s1[8] + s1[9] + s1[10] + s1[11] + s1[12] + s1[13] + s1[14] + s1[15];

  if( stage_sum < 0.4*stages_thresh_array[1] ){
	  *result = -1;
	  return;
  }

  
  haar_counter += 16;

  /* Hard-Coding Classifier 2 */
  stage_sum = 0;
  s2[0] = classifier25( II, stddev );
  s2[1] = classifier26( II, stddev );
  s2[2] = classifier27( II, stddev );
  s2[3] = classifier28( II, stddev );
  s2[4] = classifier29( II, stddev );
  s2[5] = classifier30( II, stddev );
  s2[6] = classifier31( II, stddev );
  s2[7] = classifier32( II, stddev );
  s2[8] = classifier33( II, stddev );
  s2[9] = classifier34( II, stddev );
  s2[10] = classifier35( II, stddev );
  s2[11] = classifier36( II, stddev );
  s2[12] = classifier37( II, stddev );
  s2[13] = classifier38( II, stddev );
  s2[14] = classifier39( II, stddev );
  s2[15] = classifier40( II, stddev );
  s2[16] = classifier41( II, stddev );
  s2[17] = classifier42( II, stddev );
  s2[18] = classifier43( II, stddev );
  s2[19] = classifier44( II, stddev );
  s2[20] = classifier45( II, stddev );
  s2[21] = classifier46( II, stddev );
  s2[22] = classifier47( II, stddev );
  s2[23] = classifier48( II, stddev );
  s2[24] = classifier49( II, stddev );
  s2[25] = classifier50( II, stddev );
  s2[26] = classifier51( II, stddev );

  stage_sum = s2[0] + s2[1] + s2[2] + s2[3] + s2[4] + s2[5] + s2[6] + s2[7];
  stage_sum+= s2[8] + s2[9] + s2[10] + s2[11] + s2[12] + s2[13] + s2[14] + s2[15];
  stage_sum+= s2[16] + s2[17] + s2[18] + s2[19] + s2[20] + s2[21] + s2[22] + s2[23];
  stage_sum+= s2[24] + s2[25] + s2[26];

  if( stage_sum < 0.4*stages_thresh_array[2] ){
	  *result = -1;
	  return;
  }
  
  haar_counter += 27;

 /******************************************/
 // REST 23 STAGES
 /*****************************************/

  Stages: for ( i = 3; i < 25; i++ ){
    Filters: for ( j = 0; j < stages_array[i] ; j++ ){

      #pragma HLS pipeline 
      if ( j == 0 ) {
        stage_sum = 0; s=0;
      } 
    
      r_id = r_index;
      w_id = w_index;

      tr0.x = rectangles_array0[haar_counter];
      tr0.width = rectangles_array2[haar_counter];
      tr0.y = rectangles_array1[haar_counter];
      tr0.height = rectangles_array3[haar_counter];
   
      tr1.x = rectangles_array4[haar_counter];
      tr1.width = rectangles_array6[haar_counter];
      tr1.y = rectangles_array5[haar_counter];
      tr1.height = rectangles_array7[haar_counter];
    
      tr2.x = rectangles_array8[haar_counter];
      tr2.width = rectangles_array10[haar_counter];
      tr2.y = rectangles_array9[haar_counter];
      tr2.height = rectangles_array11[haar_counter];

      /* Calculates addresses/locations of all the 12 co-ordinates */
      addr_list[ 0] =  tr0.y    *25+ tr0.x;
      addr_list[ 1] =  tr0.y    *25+tr0.x+tr0.width;
      addr_list[ 2] = (tr0.y+tr0.height)*25+tr0.x;
      addr_list[ 3] = (tr0.y+tr0.height)*25+tr0.x+tr0.width;
      addr_list[ 4] =  tr1.y    *25+tr1.x;
      addr_list[ 5] =  tr1.y    *25+tr1.x+tr1.width;
      addr_list[ 6] = (tr1.y+tr1.height)*25+tr1.x;
      addr_list[ 7] = (tr1.y+tr1.height)*25+tr1.x+tr1.width;

     
      if (!(tr2.x ==0 && tr2.width==0 && tr2.y==0 && tr2.height==0 ) && tr2.width!=0 && tr2.height!=0)
      {
       
        addr_list[ 8] =  tr2.y    *25+tr2.x;
        addr_list[ 9] =  tr2.y    *25+tr2.x+tr2.width;
        addr_list[10] = (tr2.y+tr2.height)*25+tr2.x;
        addr_list[11] = (tr2.y+tr2.height)*25+tr2.x+tr2.width;
        enable_list[ 8] = 1;
        enable_list[ 9] = 1;
        enable_list[10] = 1;
        enable_list[11] = 1;

        }
        else
        {
          addr_list[ 8] =  addr_list[0];
          addr_list[ 9] =  addr_list[1];
          addr_list[10] =  addr_list[2];
          addr_list[11] =  addr_list[3];
          enable_list[ 8] = 0;
          enable_list[ 9] = 0;         
          enable_list[10] = 0;
          enable_list[11] = 0;
  
        }
        
        /* Read the values corresponding to the 12 locations from _II which is the copy of integral image window */
        get_all_data(values, addr_list, _II);
 
  	for ( k = 0; k < 12; k++ ){
	  if ( enable_list[k] == 0 )
            coord[k] = 0;
 	  else 
	    coord[k] = values[k];
        }

        s = weakClassifier      ( stddev, 
                                  coord,
                                  haar_counter,
                                  w_id				 
                                );
          
        stage_sum = stage_sum + s;
        haar_counter = haar_counter+1;
        w_index = w_index+3;
        r_index = r_index+12;
     
    } /* end of j loop */
    if( stage_sum < 0.4*stages_thresh_array[i] ){
    	*result =  -i;
    	return;
    }
  } /* end of i loop */
 *result = 1;
 return;
}



void cascadeClassifier_1
(
  int data_in[629],
  int data_out[631]
)

{
#pragma HLS INTERFACE ap_hs port=stddev_out
#pragma HLS INTERFACE ap_hs port=SII_in
#pragma HLS INTERFACE ap_hs port=II_in
  #pragma HLS INLINE

  int_II II[WINDOW_SIZE][WINDOW_SIZE];
  int_SII SII[SQ_SIZE][SQ_SIZE];
  int i, j, k;

  int mean;
  int stddev = 0;
  int haar_counter = 0;
  int w_index = 0;
  int r_index = 0;
  int stage_sum=0;

 
  static uint18_t coord[12];
  #pragma HLS array_partition variable=coord complete dim=0

  static int s0[9];
  #pragma HLS array_partition variable=s0 complete dim=0

  static int s1[16];
  #pragma HLS array_partition variable=s1 complete dim=0



  /* Banking */

  /* 12 (x,y,w,h) values corresponding to 3 rectangles that need to be read */
  uint18_t values[12];
  #pragma HLS array_partition variable=values complete dim=0

  /* location/address of those 12 values in the 25 X 25 window */
  uint10_t addr_list[12];
  #pragma HLS array_partition variable=addr_list complete dim=0

  /* among the 12 values which of them are needed to be read from the 25 X 25 window */
  bit enable_list[12] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
  #pragma HLS array_partition variable=enable_list complete dim=0

  uint18_t _II[WINDOW_SIZE*WINDOW_SIZE];
  #pragma HLS array_partition variable=_II complete dim=0


  MyRect tr0,tr1,tr2;

  int r_id;
  int w_id;
  int s;




  static int s2[27];
  #pragma HLS array_partition variable=s2 complete dim=0


  static  int stages_thresh_array[25] = {
    -1290,-1275,-1191,-1140,-1122,-1057,-1029,-994,-983,-933,-990,-951,-912,-947,-877,-899,-920,-868,-829,-821,-839,-849,-833,-862,-766
    };

  static  int stages_array[25] = {
  9,16,27,32,52,53,62,72,83,91,99,115,127,135,136,137,159,155,169,196,197,181,199,211,200
  };


  static  int rectangles_array0[2913] = {
  6,6,3,8,3,6,5,11,4,6,6,1,0,9,5,5,13,7,10,2,18,0,9,7,5,0,5,9,9,6,3,5,18,1,0,5,2,8,2,0,20,0,18,0,12,0,12,8,5,1,17,0,6,6,0,4,2,19,1,0,1,14,3,6,8,15,1,4,0,3,1,5,3,14,1,11,5,6,9,9,7,10,8,3,6,0,4,11,0,11,4,11,9,9,1,10,6,7,0,6,1,6,2,20,0,2,0,12,5,11,0,12,6,8,0,10,3,2,2,3,5,9,4,4,6,3,0,6,6,3,1,8,0,12,0,19,0,6,7,9,0,4,7,18,0,18,0,16,2,9,2,14,5,15,0,8,7,0,1,14,7,10,4,10,1,10,5,8,6,7,0,1,5,12,6,7,0,2,2,14,8,14,8,17,6,13,3,9,0,0,6,7,10,1,5,9,20,2,5,0,5,0,6,0,1,2,2,0,9,7,11,6,18,3,18,1,11,0,13,7,11,8,13,2,3,0,9,4,7,0,7,7,3,0,3,4,13,9,5,1,10,0,1,4,0,2,9,5,17,1,14,3,15,9,17,3,7,1,10,0,15,3,12,6,14,1,13,7,12,6,6,7,7,8,7,0,15,0,15,7,15,0,8,0,3,0,9,10,7,5,14,2,0,4,9,0,18,0,8,8,11,7,12,6,15,5,9,7,14,2,5,9,12,9,3,6,12,1,12,1,10,3,10,0,6,6,5,4,11,7,3,2,3,8,16,7,18,0,18,3,18,0,5,6,10,8,15,3,15,2,8,8,15,4,13,7,18,1,14,1,4,1,10,0,15,3,15,3,15,0,4,2,14,6,17,1,16,7,12,4,10,2,15,0,6,1,6,0,8,9,6,0,16,0,14,1,5,4,16,0,10,9,9,3,6,8,0,14,5,9,0,3,3,20,0,8,6,9,1,9,7,13,7,14,2,18,6,18,7,18,0,9,0,17,1,14,6,3,9,12,6,6,1,10,5,5,0,0,1,6,4,1,5,0,3,2,6,14,0,14,0,0,0,5,3,6,0,13,7,9,1,13,5,16,4,0,5,12,2,15,0,12,11,9,8,12,3,6,7,12,10,16,4,2,5,10,8,6,6,0,1,3,3,0,10,8,5,0,14,9,14,1,15,0,17,2,3,9,18,0,4,2,14,0,18,5,21,6,8,7,21,10,15,0,11,7,12,6,14,6,3,3,0,10,11,6,16,3,16,0,10,0,13,7,5,0,6,3,8,2,15,3,17,1,19,1,4,6,15,0,15,3,8,6,5,10,10,0,15,0,12,9,12,6,15,0,11,6,10,0,3,3,0,0,12,2,7,0,3,6,5,11,0,18,3,9,0,13,0,13,4,13,5,7,6,14,4,11,0,13,2,10,8,14,6,8,7,8,5,3,0,5,0,3,1,5,1,1,3,6,6,14,1,11,10,11,7,12,2,14,6,14,0,5,1,13,7,12,0,7,7,8,1,13,5,14,4,12,9,11,5,8,1,9,3,12,8,2,0,14,2,2,6,5,1,7,3,9,2,18,3,20,2,1,0,19,0,18,0,7,0,10,8,4,2,7,3,16,5,10,4,2,6,1,12,0,15,5,8,1,17,8,17,7,15,2,10,0,20,1,15,0,16,2,10,1,11,3,3,10,3,0,12,8,10,9,4,0,9,8,13,5,0,1,19,0,16,0,12,7,9,0,1,1,13,0,12,4,15,1,3,2,13,1,3,7,12,0,13,0,15,0,13,5,0,2,0,1,15,0,6,8,10,8,12,6,13,1,15,6,13,5,6,0,11,9,10,8,3,10,4,9,5,2,13,8,12,2,7,3,11,0,3,1,11,9,9,1,6,1,8,2,11,7,11,5,11,5,4,2,7,9,2,8,3,8,0,6,0,20,0,0,0,14,0,1,5,4,8,6,2,11,2,5,9,8,6,10,0,18,2,3,2,13,6,9,7,18,9,6,0,13,0,13,5,11,4,6,0,12,0,12,5,5,5,3,7,13,2,19,1,5,0,2,5,1,3,8,6,10,1,8,3,5,4,6,7,0,0,3,2,7,5,10,9,18,4,10,9,11,7,4,2,13,7,3,1,8,3,5,8,9,0,6,0,13,5,1,9,9,5,4,0,16,9,8,8,10,7,5,2,18,1,6,9,10,6,8,1,9,6,17,2,7,1,1,9,3,16,0,16,0,8,5,4,0,6,0,20,8,6,0,6,0,20,0,15,0,13,5,5,3,6,6,10,1,11,5,12,5,13,0,8,1,2,2,17,1,7,0,15,1,9,0,16,4,7,9,12,8,15,3,15,1,15,6,10,6,11,6,11,9,3,2,3,3,4,0,10,0,5,8,11,5,5,10,10,7,1,0,12,2,12,1,12,0,5,6,14,5,9,1,8,3,12,0,8,4,12,9,9,1,8,3,7,10,10,3,12,3,10,5,7,6,12,2,0,0,0,5,1,9,2,5,4,2,7,0,2,3,6,9,15,8,3,2,19,1,14,4,14,6,14,4,0,1,20,0,8,7,16,5,11,10,10,7,14,5,12,6,11,1,15,9,10,3,16,7,15,0,13,2,5,1,5,1,14,4,14,4,18,1,2,0,12,3,16,3,9,9,15,7,17,3,3,0,2,0,13,5,5,5,18,0,3,2,2,5,6,6,13,5,6,0,18,0,12,6,0,3,9,5,4,10,8,2,8,0,18,0,9,1,2,7,8,4,10,2,15,3,15,4,15,0,15,0,10,1,7,10,8,3,7,0,10,7,5,5,6,3,16,0,0,0,10,10,4,0,9,3,6,11,5,4,2,7,1,13,5,11,6,3,0,10,6,6,0,18,0,11,0,2,1,18,0,17,0,0,0,10,7,15,3,15,0,15,0,5,0,9,3,9,5,9,8,10,5,9,7,11,9,6,1,16,0,8,0,3,0,6,0,14,1,13,4,12,2,16,3,14,8,9,0,4,5,15,0,8,1,14,4,16,3,18,1,11,0,15,7,22,0,18,0,3,6,7,2,4,9,4,3,18,2,4,7,7,6,12,0,8,2,13,5,9,5,3,2,11,3,9,1,15,1,9,6,10,7,10,4,0,3,19,0,17,1,18,0,3,2,9,5,10,8,7,9,5,8,8,6,14,6,8,2,2,0,0,7,6,14,4,2,6,9,7,6,5,18,0,18,2,5,11,15,7,7,10,10,2,14,8,14,3,14,1,3,1,18,0,5,6,14,4,15,0,0,3,3,0,1,0,2,2,0,10,10,6,11,9,2,1,13,6,10,6,14,6,9,8,17,1,14,7,3,1,14,0,12,0,10,1,15,6,6,8,14,0,10,6,7,9,10,8,7,4,17,3,10,2,3,4,15,7,15,1,11,5,10,4,0,4,10,0,6,1,18,4,6,1,1,2,12,0,10,7,9,4,6,5,10,8,9,3,4,6,8,0,11,2,8,0,0,2,4,10,7,9,17,0,16,1,12,3,12,3,12,8,10,6,13,1,7,2,0,9,0,9,2,13,4,20,8,0,0,3,3,13,5,13,2,9,8,12,8,8,11,9,0,9,1,12,6,13,1,9,2,15,0,9,2,15,4,17,0,15,0,9,3,16,0,13,0,0,5,8,4,10,8,11,4,14,2,4,8,1,7,13,8,4,3,14,8,3,4,3,9,9,7,12,6,18,3,18,0,13,5,11,3,16,5,7,1,2,3,17,5,13,0,15,1,12,1,3,6,5,9,11,4,6,5,11,5,1,7,6,6,11,5,6,0,2,0,9,9,12,0,1,3,2,5,10,8,5,6,7,5,4,0,9,9,6,9,10,5,14,5,14,0,16,4,8,0,13,0,0,6,10,1,0,2,2,1,10,7,9,7,3,7,3,8,3,6,1,5,8,3,0,2,4,9,9,14,7,14,4,17,1,14,0,9,3,14,4,7,7,14,10,14,5,4,9,3,4,16,4,6,10,9,6,5,3,6,0,6,0,4,0,15,0,6,3,12,6,6,9,10,7,14,2,11,1,15,1,10,4,7,10,13,3,13,5,10,7,15,5,8,7,12,6,7,6,5,3,3,0,14,0,1,1,7,9,10,2,8,0,5,2,14,3,9,4,0,7,11,0,14,2,11,7,6,4,14,4,13,8,17,4,15,3,12,0,16,2,15,0,18,0,16,5,12,0,5,0,8,5,10,6,6,3,12,0,0,5,10,9,8,0,16,3,6,0,14,0,2,4,12,0,6,1,11,3,15,6,9,4,7,5,11,7,8,0,10,0,20,0,12,1,5,1,6,5,11,1,11,0,3,1,0,1,11,4,12,4,13,1,9,0,6,6,10,6,13,2,11,1,1,0,13,5,18,0,11,0,12,1,7,8,6,2,14,3,15,5,11,7,11,9,4,9,17,1,7,6,9,1,19,0,3,1,2,4,6,4,15,3,8,3,15,3,5,1,14,0,15,3,9,1,13,1,6,8,0,0,4,1,14,1,10,6,10,7,14,6,8,3,5,0,9,4,10,8,7,8,11,7,4,0,7,1,11,6,7,7,9,0,7,1,9,0,1,1,9,3,9,9,16,2,13,1,14,3,13,7,4,9,7,0,15,1,14,4,15,3,0,7,1,1,6,1,15,3,4,0,6,4,6,0,3,4,20,0,11,6,11,1,11,1,11,0,3,7,17,5,16,0,6,0,3,2,10,10,11,9,5,6,10,0,6,4,14,0,1,8,13,10,7,8,7,2,11,7,13,0,12,8,12,6,14,0,14,0,4,1,4,0,3,9,0,6,2,18,0,11,9,7,1,18,5,18,0,9,2,10,5,9,7,10,4,6,0,3,9,6,2,19,0,5,5,1,8,6,9,2,5,8,9,14,2,10,1,11,4,6,5,9,7,7,2,5,7,0,0,16,5,5,0,11,0,4,2,3,2,6,0,3,0,5,1,19,3,19,7,9,0,15,1,9,7,9,7,9,7,9,10,5,0,9,2,15,1,6,0,6,0,13,2,13,5,11,7,10,3,14,4,4,5,7,2,10,3,16,0,0,4,10,7,13,3,16,2,3,4,4,3,8,2,14,7,4,0,10,5,0,0,3,9,0,6,8,2,12,5,14,5,6,7,11,7,13,0,1,6,10,3,0,0,3,7,10,8,12,6,16,2,10,8,14,0,11,3,10,0,19,4,4,0,6,19,0,18,0,5,10,9,0,7,1,8,0,13,10,13,7,4,0,0,6,7,0,13,3,12,2,9,6,14,5,10,6,14,4,14,0,13,2,6,0,19,1,15,3,11,7,14,3,20,7,7,2,15,7,13,5,3,5,9,3,19,0,20,0,7,4,10,0,7,0,13,1,7,0,6,8,7,1,16,5,7,4,6,9,15,6,12,7,6,10,10,3,4,2,13,7,1,0,0,3,3,3,13,2,10,6,2,2,10,8,13,3,3,2,14,3,5,2,17,2,0,7,15,5,11,6,11,5,15,4,12,6,5,9,12,4,4,5,14,9,9,9,1,2,12,6,12,8,7,0,4,2,15,0,6,6,8,1,6,7,10,3,15,1,15,10,15,6,15,6,16,2,2,6,9,2,16,0,15,8,15,0,12,3,13,0,10,7,4,0,6,3,9,5,5,3,5,6,0,2,8,18,0,4,6,4,4,7,0,13,5,3,0,14,0,14,0,6,0,14,6,15,8,4,5,7,10,5,1,18,0,13,0,12,7,14,0,14,2,14,1,3,5,5,8,9,6,5,8,6,3,13,3,12,7,13,7,11,7,5,8,4,0,0,0,9,3,12,8,10,5,2,6,8,9,15,1,11,5,6,1,2,7,10,3,7,7,9,1,13,3,8,6,4,0,3,2,16,4,16,1,15,3,18,0,4,2,17,1,8,0,11,0,19,2,3,4,7,3,8,4,10,3,15,0,6,9,12,8,16,8,6,0,17,0,9,1,7,7,7,3,9,3,6,1,16,0,0,3,4,0,20,1,18,0,8,4,7,6,7,9,8,8,8,4,7,0,12,4,8,9,14,7,4,10,12,0,16,5,10,2,2,7,3,2,15,2,10,4,15,0,18,0,15,3,12,0,11,9,12,3,5,0,8,6,14,9,6,6,1,12,3,9,4,11,3,5,4,9,8,16,3,6,8,0,0,5,0,2,9,9,9,5,2,6,5,18,0,10,6,3,5,17,0,9,5,11,0,6,4,9,5,6,7,11,1,18,0,0,0,6,0,19,4,19,1,3,0,12,7,12,2,14,0,15,0,14,0,5,0,3,5,4,3,4,4,16,6,13,3,12,5,10,6,6,0,12,0,12,9,6,0,2,0,6,0,0,4,12,6,15,3,6,5,12,0,11,10,9,1,6,1,7,0,10,9,10,8,9,1,0,6,8,5,4,4,8,1,10,1,0,1,5,0,9,1,8,8,5,9,6,2,10,7,14,8,9,3,5,4,6,9,12,6,9,5,5,9,11,2,15,3,3,5,16,0,13,1,15,5,6,2,14,10,13,3,13,3,11,0,0,6,18,0,15,1,15,0,3,0,15,0,12,3,16,0,9};

  static  int rectangles_array1[2913] = {
  4,4,9,18,5,5,8,14,0,6,4,8,2,9,6,0,11,5,8,5,0,6,6,18,7,3,8,6,5,6,21,6,1,1,8,6,12,1,13,1,2,5,4,3,1,6,1,1,5,10,13,4,4,5,1,10,17,3,3,1,7,7,12,6,7,15,17,4,1,0,5,8,14,15,15,6,5,0,0,6,0,6,6,8,0,0,7,6,20,6,13,6,6,12,22,7,7,6,14,18,1,16,4,4,4,16,12,0,10,8,8,0,0,14,16,8,19,10,9,0,6,5,5,14,13,16,0,6,1,2,8,9,12,16,16,1,2,8,5,17,7,1,5,1,1,0,0,7,10,9,15,7,6,8,8,6,7,14,10,12,0,0,3,0,1,0,0,18,3,3,10,10,11,11,11,10,13,4,0,0,0,1,1,6,14,14,18,4,17,2,8,5,5,4,0,15,0,0,22,0,6,1,5,1,2,8,12,12,7,1,2,4,1,15,5,5,0,4,0,0,6,7,17,18,18,20,15,4,6,14,9,6,6,10,16,6,0,0,7,20,5,2,1,0,0,21,7,7,8,15,15,0,6,1,2,14,6,2,4,17,7,1,13,13,6,12,1,0,2,2,18,6,7,3,4,1,2,3,3,0,8,8,14,14,10,0,1,6,9,0,0,0,11,9,8,12,12,12,7,7,0,0,3,3,2,10,14,13,5,17,18,0,4,4,3,1,16,3,5,2,14,21,14,2,4,6,8,14,6,6,7,3,12,6,6,9,6,6,2,18,2,2,10,0,0,0,12,6,12,5,8,6,12,12,1,1,9,21,13,13,6,0,7,4,0,0,12,12,12,12,14,13,15,0,1,1,14,3,1,0,6,10,15,1,9,0,15,15,7,12,8,14,10,3,17,13,0,3,5,7,6,8,15,1,8,5,2,7,7,6,1,1,18,4,16,7,7,2,20,12,2,0,0,15,8,3,5,4,6,4,4,4,22,14,14,11,11,9,12,0,0,17,17,6,6,4,0,0,15,8,12,2,20,0,13,10,3,5,7,0,0,1,17,15,15,16,13,0,4,5,4,0,0,7,7,5,13,0,7,2,2,2,6,5,6,0,3,7,7,7,6,14,0,2,4,3,4,0,6,0,10,21,6,5,2,7,7,17,18,6,18,18,9,9,3,17,15,17,3,3,0,0,0,0,3,11,0,0,8,12,0,6,0,2,7,6,1,4,3,1,0,0,13,5,1,2,10,4,10,10,14,7,1,1,5,9,16,12,14,13,5,5,5,5,1,1,15,9,2,2,0,0,17,5,2,2,7,7,0,0,6,7,6,6,3,0,9,7,6,0,14,14,12,2,16,16,0,0,8,5,13,14,6,0,1,6,0,11,20,11,12,11,11,4,15,0,0,2,0,18,7,14,2,3,6,8,4,8,2,16,0,2,11,3,16,17,13,9,7,8,2,17,18,3,6,0,0,10,11,5,6,5,3,21,10,4,8,9,6,6,5,4,4,10,10,2,2,4,4,4,4,18,18,2,2,5,8,7,5,14,14,11,9,6,19,5,5,4,6,10,7,2,18,9,2,0,3,2,5,0,3,14,9,11,5,6,6,5,5,10,10,0,3,1,7,12,6,7,18,2,3,2,0,0,5,22,10,1,0,3,15,13,8,8,2,5,8,8,6,0,9,0,5,5,5,4,16,16,9,13,10,9,0,11,5,5,6,6,5,6,13,5,2,15,17,13,10,6,14,12,10,0,11,2,4,0,17,6,10,16,16,16,11,11,3,4,0,16,15,15,17,8,6,8,8,5,6,7,5,9,8,8,11,0,2,0,0,3,10,0,3,4,0,5,0,4,10,10,11,10,12,21,20,15,17,12,6,13,16,5,1,19,1,2,10,11,9,10,7,0,6,0,2,17,0,0,17,7,3,2,2,1,16,13,15,5,13,2,14,12,13,8,12,16,1,2,6,7,0,8,12,21,0,6,4,7,8,8,14,11,12,0,10,2,0,6,6,11,11,16,6,16,7,10,4,18,0,3,0,1,1,16,3,16,3,9,4,7,7,4,12,3,6,6,3,3,6,1,17,18,5,6,2,7,0,8,7,5,9,14,14,8,11,0,0,1,11,18,9,10,6,14,7,4,16,13,8,16,0,5,5,6,7,10,12,10,0,4,10,6,11,8,11,9,12,4,4,9,5,9,0,9,9,4,3,1,6,18,8,19,8,8,12,7,1,12,0,0,3,6,11,8,17,14,3,3,0,0,11,11,11,20,6,0,3,5,12,0,0,5,12,13,1,0,2,2,10,10,6,12,14,1,11,15,14,3,6,6,1,1,15,15,1,3,0,3,5,0,1,7,3,3,7,7,13,5,1,1,15,2,5,15,12,12,0,2,7,9,5,5,17,18,17,17,17,0,0,14,13,20,9,10,8,10,10,15,5,13,17,12,9,9,7,4,8,7,15,8,17,17,1,7,5,4,16,16,0,6,4,0,1,6,9,2,2,3,1,9,10,0,4,1,8,0,22,15,0,7,14,14,5,5,5,5,2,2,0,4,16,0,12,21,5,5,6,5,14,5,8,6,13,10,13,0,1,4,3,13,13,13,16,16,16,16,0,1,2,15,2,2,2,2,0,12,2,10,3,7,11,8,0,0,3,18,18,3,7,3,17,5,6,16,2,2,4,13,1,12,7,5,11,11,4,2,0,0,0,0,2,13,7,8,14,0,15,9,4,10,5,18,18,20,8,8,5,5,6,0,4,4,12,0,12,12,15,15,0,0,6,12,4,22,7,0,1,16,7,10,2,9,2,2,3,13,14,2,4,1,6,21,5,6,6,3,10,15,4,0,0,0,7,0,10,2,5,0,0,2,2,0,0,2,10,7,0,3,7,6,2,6,0,0,0,17,17,14,15,15,14,8,7,8,0,8,5,6,7,8,8,10,5,12,9,14,9,18,6,6,16,16,11,6,7,6,7,10,12,14,12,13,0,1,16,17,2,0,0,2,1,8,8,5,5,4,7,15,2,1,1,1,1,11,11,6,10,9,18,21,12,6,6,4,12,14,7,13,7,12,2,0,9,10,10,15,16,2,5,0,16,12,15,10,9,11,7,15,8,4,6,6,7,8,8,3,3,2,2,3,3,3,3,11,11,8,6,18,4,1,11,12,12,0,12,20,4,2,8,7,0,11,0,7,17,10,5,11,4,0,4,4,18,0,4,4,11,6,0,9,15,7,15,12,12,12,7,7,4,4,11,16,15,15,1,21,20,1,17,16,16,16,10,18,5,2,7,6,0,7,1,18,2,7,1,0,3,15,10,3,0,0,0,4,17,20,3,3,6,6,9,18,0,1,0,10,16,16,12,16,6,6,9,9,4,8,3,3,1,5,6,10,4,2,4,4,8,8,13,13,13,2,2,2,0,2,5,3,21,10,10,8,8,8,15,13,8,13,15,4,15,15,11,6,2,2,1,7,6,11,16,0,11,9,5,2,3,15,0,0,1,0,2,2,2,4,1,1,5,4,5,5,5,0,8,6,3,18,8,2,5,4,6,1,4,6,17,6,6,5,2,2,6,3,3,3,1,2,2,14,8,0,0,6,5,7,16,17,8,13,17,17,0,2,3,17,17,18,15,13,14,18,13,14,2,9,3,2,4,5,5,6,4,4,7,9,0,3,1,22,10,0,0,2,13,21,1,7,0,1,1,2,5,2,2,11,7,9,9,4,6,21,21,5,10,0,2,0,12,13,0,1,13,21,3,10,3,2,1,0,1,18,15,10,9,11,7,2,2,4,5,7,4,0,1,0,0,1,0,5,0,14,14,18,0,4,2,1,8,15,10,17,4,0,6,9,9,11,2,0,15,18,17,11,11,9,16,16,1,2,15,11,18,14,7,8,1,14,7,12,0,0,0,0,8,8,21,0,0,6,6,0,0,16,0,0,1,1,13,0,5,10,7,10,6,2,13,6,13,20,4,6,0,13,16,0,6,5,15,7,6,6,0,0,18,15,3,3,14,14,15,17,0,0,16,0,7,8,9,0,1,4,1,2,1,0,17,14,15,21,15,15,6,3,1,4,1,2,2,2,7,3,6,1,8,0,16,16,19,16,8,15,18,18,3,5,5,6,2,6,2,8,5,8,0,12,12,7,14,6,6,13,10,10,9,3,0,12,0,0,2,2,0,0,6,6,1,1,0,10,9,9,7,15,10,4,2,0,9,2,0,15,14,1,0,3,2,4,16,16,18,0,3,12,3,3,8,15,13,6,9,0,3,3,5,4,7,0,0,0,1,2,13,13,2,9,6,8,7,12,10,6,12,15,14,8,10,10,9,12,12,12,12,12,10,15,10,1,4,5,10,12,0,10,2,20,10,17,0,0,2,2,7,1,14,13,6,2,6,19,15,5,6,6,0,0,5,5,1,13,1,17,13,18,14,1,4,0,5,5,1,1,0,4,6,18,18,15,7,7,9,13,15,15,13,13,5,18,19,19,19,14,0,1,9,15,0,10,10,8,5,5,4,4,7,6,4,0,1,1,14,3,3,2,2,7,22,16,3,10,16,0,5,8,1,6,3,13,12,5,5,6,1,19,14,6,0,0,1,8,7,12,1,1,7,10,7,3,0,0,5,5,0,0,2,1,0,17,18,17,15,15,14,10,18,12,10,10,2,6,14,14,1,21,1,16,1,0,1,1,7,14,1,0,1,1,0,14,7,11,5,6,1,1,9,4,16,0,5,3,12,11,10,9,2,6,8,1,1,14,16,16,4,19,8,1,8,8,5,6,12,12,6,6,0,1,6,6,17,22,12,12,12,14,6,7,3,1,1,2,2,12,2,6,6,0,0,6,1,7,7,20,6,2,3,4,1,0,2,2,15,17,6,0,4,6,12,14,14,18,3,3,6,5,4,16,8,6,5,1,1,10,2,0,1,6,1,4,0,16,16,0,3,7,9,14,14,21,21,4,7,4,15,13,6,16,5,8,8,8,8,8,6,8,5,5,1,10,17,16,10,4,18,18,16,15,15,1,1,5,5,0,4,0,0,5,6,2,2,0,4,0,0,7,7,8,0,10,0,1,1,6,12,9,10,18,16,14,14,10,13,13,0,8,5,0,11,5,18,8,7,0,0,2,8,9,7,2,0,14,12,12,6,0,8,6,11,3,12,16,6,10,10,12,12,15,15,20,20,17,2,1,15,2,12,7,1,8,3,6,0,0,15,7,6,21,3,7,2,10,9,5,9,11,13,0,18,4,8,3,15,18,14,15,6,6,6,14,8,6,9,9,15,20,18,18,16,16,2,2,0,20,6,9,6,6,4,6,0,1,0,0,12,12,5,6,5,16,8,8,4,4,7,19,11,1,2,13,0,11,1,10,19,10,1,1,4,4,6,9,5,2,0,0,7,2,0,6,8,18,14,15,0,0,4,0,0,2,6,1,0,0,2,0,2,11,8,8,8,11,9,4,17,21,4,15,8,12,17,16,1,1,13,1,4,8,7,7,6,6,9,1,6,5,6,4,8,10,5,4,4,7,6,5,7,7,2,1,13,13,15,15,0,6,7,9,6,7,12,14,17,12,17,3,17,1,17,5,7,4,1,5,0,11,7,7,17,6,15,15,10,10,15,1,0,0,1,21,9,4,1,9,1,0,0,6,1,12,17,1,0,6,0,7,12,9,1,11,11,10,2,16,16,13,16,16,18,13,2,8,13,20,8,7,6,20,20,1,1,3,2,9,3,0,9,4,4,13,13,15,13,0,2,1,1,6,2,11,1,0,3,1,7,0,0,9,15,7,9,17,3,1,15,0,3,1,0,6,0,0,11,7,6,14,14,0,0,1,12,8,6,5,9,8,12,19,0,4,16,7,7,6,17,17,4,0,0,0,4,12,9,5,5,7,1,0,6,8,6,12,4,1,1,10,4,13,13,15,14,14,8,10,10,7,10,1,15,6,1,6,18,0,13,6,6,6,7,8,8,8,2,10,10,7,7,9,2,2,1,2,3,8,8,18,6,6,3,6,8,2,14,2,3,6,2,17,7,11,1,0,0,7,2,1,0,0,0,15,18,8,6,2,7,6,2,9,4,8,8,0,0,0,0,2,2,6,0,1,4,5,13,14,2,1,1,4,5,1,12,12,18,13,3,9,3,2,6,6,9,9,6,6,16,20,10,6,1,13,15,12,11,6,0,0,3,3,5,5,2,2,0,0,11,11,6,16,16,6,7,6,1,9,5,11,8,8,6,5,7,0,0,6,6,6,21,19,18,18,16,16,0,0,14,14,14,14,18,18,5,3,0,0,12,3,4,4,14,14,6,11,5,4,8,8,6,14,6,6,14,5,5,0,3,3,12,10,8,14,10,10,12,8,11,11,2,2,12,10,9,8,7,0,0,5,6,0,1,0,3,14,9,2,4,4,5,7,5,5,4,14,17,16,17,20,14,6,4,3,8,6,6,5,5,5,2,1,2,0,9,0,0,0,1,9,8,9,9,0,1,1,20,0,8,8,13,13,8,8,11,11,12,1,11,10,8,8,14,18,16,20,12,12,17,6,17,18,15,13,17,17,17,17,2,13,1};

  static  int rectangles_array2[2913] = {
  12,12,18,9,4,12,12,4,7,12,12,19,24,6,14,14,9,6,6,4,6,24,6,10,14,24,15,5,6,3,18,13,6,6,24,14,21,4,20,6,4,22,6,6,4,19,4,4,14,18,4,6,12,12,24,18,12,4,4,24,8,3,16,12,6,9,18,16,4,18,20,14,7,9,9,8,14,12,6,6,6,6,6,18,12,24,16,6,24,4,15,4,4,6,18,4,8,10,10,18,22,18,6,4,4,20,8,6,6,12,12,6,6,9,9,6,12,20,18,18,14,10,12,18,8,18,6,12,4,19,22,11,15,12,12,5,24,12,9,6,22,17,6,6,6,6,6,8,19,6,17,3,8,9,9,10,3,24,18,6,10,9,16,9,20,9,9,10,6,12,18,22,8,6,6,11,24,22,20,2,2,2,2,3,9,9,18,8,18,12,14,6,6,9,18,5,4,18,19,4,19,6,14,20,22,7,22,22,6,9,4,12,6,18,6,16,6,24,4,4,6,6,9,14,18,15,15,16,10,15,10,6,18,18,18,14,2,2,15,21,5,24,22,15,24,18,10,10,6,20,10,16,7,6,6,12,10,6,5,24,5,6,6,6,3,13,4,9,6,6,12,6,12,8,10,6,2,6,2,2,9,9,9,9,18,24,8,4,10,3,6,6,24,13,6,16,6,6,10,6,6,6,6,6,9,6,6,5,3,18,19,6,3,3,18,6,9,20,6,22,5,18,6,24,12,12,14,8,5,3,18,20,19,6,6,6,6,6,6,15,6,6,18,12,6,6,9,13,9,6,9,3,9,10,4,4,6,18,10,22,16,18,8,6,6,6,6,6,9,9,19,19,10,10,6,6,6,9,4,14,6,18,9,21,17,11,13,9,15,6,18,24,3,24,10,18,18,16,3,18,6,6,6,18,12,6,24,5,5,6,6,19,12,4,10,10,10,9,21,9,9,4,4,9,18,6,11,6,9,6,6,9,19,6,6,4,4,18,6,6,6,18,18,11,14,15,22,24,18,12,7,22,14,24,18,22,11,6,24,10,10,24,18,16,16,18,21,6,6,9,2,6,6,6,4,24,10,6,6,9,6,10,2,15,6,6,9,14,8,7,4,6,6,21,5,4,5,11,12,24,23,18,21,6,4,8,15,10,9,6,9,9,9,9,6,18,21,6,6,6,16,10,10,10,6,12,3,6,9,8,3,4,9,24,6,6,6,12,2,12,18,18,24,4,6,6,8,16,8,8,11,24,4,4,16,6,18,6,9,8,3,18,6,6,4,4,18,12,9,9,6,6,9,3,14,3,14,14,9,9,6,6,6,6,8,9,8,10,4,6,18,8,24,3,10,10,10,24,15,12,14,4,6,6,18,14,6,6,24,6,10,6,6,11,10,6,6,4,20,10,6,10,4,10,12,8,4,9,14,19,10,16,24,18,18,18,9,23,18,12,3,10,10,6,4,6,6,9,6,3,9,3,6,18,18,8,9,9,5,14,3,15,15,6,6,6,6,6,6,8,8,10,21,12,12,12,6,20,12,8,8,20,12,16,9,12,14,9,19,6,18,4,20,22,4,4,6,6,10,12,24,4,4,17,18,14,14,3,3,14,9,18,12,8,7,22,4,7,9,22,6,8,6,6,9,18,12,4,4,6,9,8,6,6,4,19,9,12,18,4,18,4,4,4,6,4,18,20,6,8,3,14,24,18,5,5,8,8,12,6,6,12,23,19,11,8,10,9,9,9,20,9,9,8,21,10,12,23,8,18,9,9,6,6,24,18,24,18,9,9,18,6,6,5,6,6,8,21,3,11,10,12,18,22,6,6,6,6,18,3,16,6,16,18,6,8,10,10,12,8,9,24,18,9,10,4,9,6,12,20,9,9,4,8,9,12,9,6,5,21,10,6,18,8,18,9,18,12,6,4,4,24,9,9,19,22,6,20,6,16,8,6,16,16,4,8,12,6,8,6,6,21,16,7,4,6,6,4,6,12,23,6,12,10,6,9,9,18,18,12,21,12,6,19,14,18,4,11,9,4,4,18,11,20,13,22,14,10,10,6,9,8,16,14,9,18,9,24,10,18,6,11,12,4,4,6,15,6,6,6,6,16,20,4,4,18,6,9,15,19,7,9,8,18,12,9,14,22,6,10,10,16,6,8,6,8,4,8,10,14,20,4,12,12,6,8,8,9,16,6,3,5,5,10,23,21,6,12,8,24,8,8,8,5,19,24,13,24,4,6,12,12,18,9,4,4,9,9,6,6,19,18,16,9,4,15,8,6,6,12,11,21,8,6,21,19,6,6,14,9,8,22,9,18,7,16,12,4,4,4,6,6,3,6,3,12,4,3,3,10,3,6,19,18,18,6,20,20,6,24,18,6,8,8,14,4,5,8,22,6,9,19,9,18,9,24,14,9,6,13,6,21,9,9,10,24,9,6,9,6,14,14,9,6,10,4,6,6,9,9,9,4,12,9,10,10,24,9,24,11,22,6,20,14,16,19,10,4,21,6,14,6,9,4,19,20,4,8,6,6,4,4,6,6,24,6,4,4,9,6,7,14,6,4,6,6,10,14,12,12,6,20,9,6,5,16,8,6,9,9,9,9,18,18,18,19,6,15,6,6,6,22,21,18,6,18,8,18,6,6,2,2,7,9,21,7,22,24,9,12,14,14,6,6,20,9,21,14,12,9,6,6,18,6,6,6,6,6,24,18,10,12,19,4,9,15,12,6,6,16,14,20,20,6,12,12,6,6,6,6,9,15,9,9,9,9,8,4,10,4,10,18,11,12,12,9,15,12,12,12,8,8,24,8,4,4,15,24,5,18,3,4,9,20,18,10,4,6,6,6,9,18,20,4,6,18,18,6,6,6,20,20,18,6,22,6,6,24,6,6,6,6,6,9,18,9,23,18,9,8,15,8,6,8,6,4,12,8,8,6,6,12,18,8,22,12,20,20,10,18,19,6,22,7,11,10,9,6,6,6,6,6,9,18,13,8,8,8,6,6,6,5,5,6,6,12,24,2,2,2,2,6,6,18,7,12,18,20,6,18,18,6,9,18,6,12,12,6,4,9,12,6,6,9,12,20,12,3,15,6,12,8,8,9,12,6,9,8,6,24,6,5,5,6,6,6,6,18,9,10,10,6,6,10,6,18,6,9,6,4,4,12,10,22,2,24,10,8,6,5,20,12,6,10,12,6,4,6,4,4,19,2,2,2,10,4,6,16,6,6,6,12,9,9,18,22,6,6,16,9,6,6,6,24,24,6,18,18,22,9,21,12,24,4,6,6,6,6,20,12,4,12,4,3,10,12,6,4,6,6,6,4,18,22,10,10,12,12,5,21,9,12,12,8,10,10,12,10,12,4,6,6,11,6,4,4,8,16,18,16,8,9,8,8,8,8,5,7,24,8,8,24,12,12,6,8,18,18,22,12,12,12,6,9,7,9,18,4,6,6,12,14,17,12,9,24,9,18,9,9,24,20,16,4,10,6,7,7,6,19,9,9,10,18,4,4,8,12,6,12,10,21,9,6,6,12,20,10,5,4,8,24,4,18,16,6,14,8,20,9,6,4,4,8,2,9,19,9,18,6,6,4,18,14,18,9,12,7,20,9,15,6,6,9,9,12,6,8,24,6,8,24,12,9,16,4,5,9,9,6,20,17,7,23,6,4,6,18,9,2,2,18,15,18,4,10,10,6,6,6,18,6,6,11,10,10,10,6,10,16,16,22,8,6,6,6,7,8,6,3,8,19,4,18,5,4,16,18,10,12,12,22,9,12,10,8,8,18,10,21,22,6,3,12,12,22,18,22,6,6,6,18,6,12,12,18,6,6,6,18,6,6,10,5,5,9,23,8,6,9,18,11,11,24,8,14,21,24,8,21,12,4,4,6,9,19,10,18,6,17,12,6,16,5,18,6,20,15,6,6,6,9,6,6,6,6,6,6,6,9,3,14,12,4,6,4,6,14,16,6,21,6,5,16,14,4,12,12,14,18,18,24,18,9,19,24,9,9,18,18,3,8,18,3,4,10,6,10,5,12,9,8,5,14,10,4,6,18,6,6,4,6,9,14,15,8,6,6,12,12,16,18,18,24,9,24,22,9,10,6,12,12,16,10,18,9,10,18,15,15,24,6,6,6,10,18,10,10,14,9,6,6,8,4,3,16,6,6,12,12,6,6,9,9,6,6,4,12,12,12,14,20,8,13,6,6,12,15,12,18,24,3,4,4,12,17,5,5,18,12,6,6,21,6,12,16,18,15,9,15,3,3,10,16,12,9,6,6,10,18,14,14,3,5,12,20,19,9,14,14,9,18,6,18,20,20,24,20,9,9,8,8,4,20,6,21,13,12,10,5,6,18,9,21,22,18,6,6,6,6,6,4,9,9,15,3,12,20,6,18,4,4,6,6,6,6,16,6,6,18,10,10,9,6,5,8,19,12,21,16,18,10,4,18,12,6,6,6,18,12,10,10,6,6,8,12,10,10,18,4,24,6,20,19,10,21,8,10,4,6,4,4,9,16,16,24,9,14,7,8,12,4,3,9,20,24,12,8,6,10,14,10,9,24,12,22,12,9,23,19,6,18,6,4,6,6,4,8,7,18,4,4,20,6,10,4,8,8,6,6,6,6,24,10,23,19,18,9,6,6,20,6,18,9,18,18,18,10,4,4,4,12,4,10,4,3,4,6,19,9,7,14,8,8,18,9,18,6,6,4,4,4,18,6,8,18,14,15,10,4,22,6,6,4,10,8,12,12,6,6,4,19,6,8,6,6,6,24,10,10,19,19,16,24,6,6,18,18,6,6,6,4,6,10,6,6,6,6,6,15,20,4,12,6,9,6,12,18,18,18,6,12,18,4,19,15,14,22,6,18,3,20,5,12,6,8,8,12,6,3,14,12,4,15,6,10,18,15,8,24,6,8,10,18,24,6,8,18,18,18,20,14,12,21,21,18,18,4,18,4,10,11,4,9,4,8,8,12,9,12,9,12,4,14,11,6,11,9,18,12,18,18,9,9,9,6,6,6,6,6,4,6,6,18,6,15,15,4,6,8,8,24,14,8,10,8,4,6,6,18,16,16,8,16,12,9,9,16,19,9,3,24,5,19,6,24,9,10,20,7,7,2,10,12,3,12,6,9,22,22,9,4,18,24,24,18,4,10,6,6,6,6,6,6,6,10,10,9,14,10,10,3,9,5,24,12,4,9,6,6,19,4,6,18,10,18,9,24,8,4,8,10,18,19,24,8,10,6,7,12,6,15,6,7,6,6,6,4,6,6,9,18,9,9,18,18,4,4,2,16,4,10,6,7,4,6,10,18,2,2,6,6,18,9,9,10,5,5,4,4,10,14,12,24,14,6,4,14,16,21,15,6,16,16,3,3,10,6,12,5,9,11,4,9,13,4,6,10,20,9,4,4,22,9,24,16,18,6,9,9,4,7,20,19,6,6,4,9,18,2,8,18,15,12,6,20,24,9,4,4,8,6,3,12,5,5,6,6,14,3,6,4,16,7,8,6,9,3,22,18,6,9,4,4,10,3,18,18,9,9,18,6,10,18,18,9,6,18,9,10,9,3,9,11,9,11,8,20,21,12,6,8,8,8,9,8,9,9,9,9,10,6,6,10,16,19,18,9,6,6,14,8,7,12,8,22,6,6,6,17,12,18,10,10,24,6,6,19,6,10,10,9,18,18,9,9,6,4,8,18,4,12,4,18,18,6,6,4,6,12,4,6,12,8,8,9,9,18,9,18,6,9,9,14,6,12,18,6,16,3,6,4,4,5,9,18,5,17,18,24,18,6,14,3,6,6,6,21,12,9,6,8,8,8,8,12,18,20,9,8,16,10,10,15,18,10,18,10,10,18,18,18,6,8,8,8,18,9,18,6,6,18,12,6,2,10,20,12,3,3,3,18,10,14,14,9,8,4,5,9,9,12,5,3,6,7,4,14,19,6,15,10,8,12,9,14,14,13,6,17,17,8,8,24,15,18,18,3,3,6,6,11,12,12,9,12,6,9,6,9,16,10,7,11,12,8,4,3,3,18,4,3,18,3,3,5,18,20,9,19,19,9,18,14,6,9,9,6,6,6,6,12,12,4,6,3,18,16,10,9,9,10,3,12,12,8,6,12,12,6,7,18,19,12,6,6,5,5,14,3,24,20,18,6,20,6,6,6,18,15,18,3,6,6,8,8,20,13,7,7,10,10,3,18,18,9,15,12,12,6,13,22,6,6,24,10,18,10,3,12,4,4,18,9,12,9,10,10,10,10,9,9,10,10,18,18,18,7,19,16,16,12,2,2,8,8,3,12,8,12,18,18,3,18,3,3,18,18,22,21,18,18,24,16,6,8,6,6,18,10,9,9,3,3,6,6,16,9,16,18,6,6,4,6,6,18,24,9,8,13,16,14,9,16,13,13,24,10,18,18,9,22,8,8,18,5,12,18,4,6,2,2,10,18,17,12,16,5,6,6,6,13,19,6,4,6,6,6,18,4,8,8,10,10,4,4,16,16,7,3,9,17,8,8,10,22,24,12,6,6,9,22,9,18,19,18,9,9,9,9,3,24,6};

  static  int rectangles_array3[2913] = {
  9,7,9,6,19,16,6,10,6,6,7,12,3,15,10,9,6,10,10,9,11,13,9,6,12,3,6,14,10,12,3,6,15,15,15,12,12,10,10,13,13,19,9,11,9,3,9,9,14,2,11,9,9,6,5,6,6,13,13,23,12,14,6,6,12,6,3,12,20,2,14,12,9,6,6,10,14,5,9,9,9,9,9,4,9,6,12,6,3,9,4,9,9,12,2,10,10,6,4,2,3,3,15,10,10,6,9,9,6,6,6,9,9,6,6,10,3,2,12,24,10,12,12,3,8,6,6,18,14,2,13,4,10,6,6,12,4,4,6,6,15,9,10,8,7,22,22,16,6,12,6,14,10,11,11,18,14,8,14,6,16,6,4,6,4,6,6,6,9,6,3,3,8,6,6,6,4,12,17,24,24,22,22,18,6,4,3,18,3,4,6,6,16,16,9,8,9,3,2,9,18,9,12,2,3,9,4,4,11,6,10,12,15,3,9,6,9,14,13,13,9,9,6,6,4,4,9,4,6,10,14,9,3,3,4,6,18,18,10,4,18,6,8,9,19,3,4,4,16,4,6,9,15,13,14,10,6,14,12,5,12,12,6,6,16,6,9,6,9,9,6,9,3,21,12,9,20,9,21,23,4,4,6,6,4,19,12,10,12,19,10,12,2,4,9,4,9,9,4,9,9,9,15,15,4,7,10,8,16,3,3,9,18,18,9,14,6,16,12,16,10,3,10,4,9,5,12,10,14,16,8,2,6,9,14,12,18,18,9,6,9,9,2,6,9,9,6,6,6,15,6,14,6,4,19,19,9,3,9,4,6,22,14,20,9,9,12,12,6,6,3,3,6,12,12,12,9,12,12,8,9,3,6,23,4,18,6,6,4,9,3,4,12,3,6,3,9,9,12,4,9,10,9,21,7,9,4,12,12,9,17,9,6,19,7,12,12,6,4,6,6,14,14,6,5,11,14,9,6,9,9,4,2,9,9,9,9,7,10,9,9,3,3,12,6,4,2,24,4,9,12,6,3,16,4,2,8,6,6,10,10,4,3,6,6,3,10,24,11,6,20,24,24,14,12,14,6,9,14,15,9,14,18,6,10,9,7,3,6,12,18,9,13,3,12,10,8,9,5,5,6,3,6,12,15,10,12,6,6,16,6,6,6,6,9,3,6,6,9,9,10,16,5,5,10,6,18,9,7,10,18,9,6,3,9,10,12,12,21,8,8,3,4,9,9,22,14,15,14,14,6,9,16,16,8,9,3,9,6,10,18,3,11,11,9,9,9,4,6,6,17,17,4,18,12,12,15,15,6,6,14,9,15,15,9,21,12,12,18,9,3,10,4,20,8,8,9,3,4,6,6,10,7,6,3,18,6,6,3,7,6,6,7,12,4,9,9,15,3,6,11,9,9,4,6,10,16,4,9,8,8,18,11,5,3,3,6,10,3,3,22,6,6,12,9,9,9,6,9,19,6,19,9,3,4,10,6,8,12,6,19,20,20,6,6,14,14,7,9,10,10,6,6,6,6,6,9,6,6,10,10,13,5,6,4,5,12,6,3,9,2,18,3,3,18,23,19,9,6,12,6,10,15,6,8,6,6,18,18,4,4,9,8,5,8,4,15,8,4,4,17,18,12,9,12,2,6,11,10,17,6,9,12,12,15,3,7,9,3,12,14,9,18,18,10,11,3,3,12,8,12,14,10,2,12,12,18,18,12,9,11,12,3,3,4,5,4,9,6,6,8,18,10,5,6,14,4,4,10,3,4,4,6,6,6,3,4,3,6,6,3,10,9,8,8,11,9,6,12,12,8,3,4,22,8,9,9,14,8,14,20,10,4,4,9,5,4,4,5,10,8,3,4,6,4,12,6,9,4,3,9,4,18,12,8,5,6,9,12,6,6,15,2,6,2,6,3,5,9,9,9,4,6,6,3,12,6,3,10,6,9,14,6,8,12,10,6,9,12,9,6,3,6,6,14,9,14,16,10,5,3,12,5,4,12,6,6,13,13,6,3,6,14,2,4,4,9,4,6,23,23,3,4,3,4,15,3,4,4,9,6,10,6,6,6,2,6,3,6,3,16,6,22,10,18,9,10,9,10,10,10,9,3,13,13,7,9,6,6,2,16,6,12,3,6,4,14,6,9,10,10,6,9,14,12,12,9,16,6,14,2,16,10,4,7,16,16,6,12,8,18,14,14,6,18,3,9,6,16,4,16,16,10,8,2,9,8,3,11,9,8,6,3,6,9,9,19,19,8,8,3,4,6,6,14,12,5,9,9,8,6,3,12,12,2,3,14,14,14,6,9,4,6,3,9,4,5,9,10,10,9,9,19,9,19,4,9,19,12,5,18,12,3,3,4,9,4,4,6,8,3,6,5,5,6,15,12,14,6,6,4,3,4,3,4,3,4,6,9,4,12,3,6,7,8,3,6,9,4,6,10,10,17,20,4,9,9,16,4,4,6,10,6,8,8,8,4,6,6,4,4,18,4,14,6,3,4,15,3,6,9,9,9,21,2,3,13,8,9,9,10,10,6,6,21,13,21,20,6,9,9,3,9,10,9,9,4,14,6,12,10,8,6,9,14,6,9,10,6,6,6,6,3,3,3,2,11,6,11,11,9,4,12,3,9,3,9,3,9,9,18,18,9,6,3,9,3,16,4,8,6,6,9,9,10,8,15,8,4,6,6,6,2,11,15,13,9,9,4,4,4,3,3,20,6,4,7,9,9,6,6,4,6,9,8,8,9,16,12,12,6,22,6,6,6,6,10,16,6,10,6,2,6,10,6,4,16,13,6,9,6,6,11,10,10,21,9,6,16,3,12,9,8,2,3,6,18,9,9,9,6,2,4,12,12,22,22,11,11,9,3,2,2,9,9,9,9,6,10,9,9,9,9,6,3,6,6,3,6,10,6,10,12,10,9,18,4,10,10,14,19,6,6,10,8,6,18,12,8,3,3,9,4,12,9,8,7,9,12,6,9,23,6,3,14,12,12,7,9,12,12,15,15,9,15,8,4,19,19,20,20,12,12,14,8,12,5,3,12,3,3,9,6,4,14,6,9,6,10,6,6,9,9,6,6,3,6,24,4,12,8,14,14,10,6,9,7,10,9,12,14,8,8,6,6,9,9,6,6,8,8,12,11,4,7,3,9,7,6,11,11,18,5,3,20,4,4,10,14,8,9,8,6,4,9,8,17,6,17,17,3,18,18,18,8,9,9,8,9,9,9,6,6,6,3,6,6,6,6,4,9,9,23,3,4,23,3,3,4,6,3,6,4,15,12,9,9,9,3,6,13,4,13,18,5,8,9,9,14,14,16,10,6,4,5,5,16,16,15,2,6,4,12,12,8,8,5,8,6,18,14,14,12,16,21,21,18,8,12,12,20,6,20,20,14,14,8,9,10,11,16,6,9,12,9,10,3,2,3,9,6,6,9,6,12,6,4,16,9,9,10,6,8,21,9,3,10,3,4,6,6,6,12,15,4,8,10,10,12,8,4,4,6,2,9,9,10,13,6,3,6,5,9,9,7,6,6,4,18,9,14,6,9,3,6,9,6,10,3,6,9,11,11,10,18,6,3,6,5,9,9,15,3,6,3,6,6,8,3,6,4,6,9,6,6,6,9,10,4,6,10,6,8,6,4,10,8,12,12,9,12,16,6,2,9,9,13,2,6,24,24,10,6,3,11,4,18,16,16,6,2,6,6,6,4,7,7,6,8,3,3,14,10,12,18,9,9,10,12,12,10,2,13,3,12,15,4,3,8,6,3,4,6,5,7,10,10,6,9,6,16,22,12,18,18,4,4,6,9,9,9,3,13,4,6,3,12,9,13,2,9,9,8,8,8,6,15,12,9,4,3,6,6,6,8,6,3,3,5,3,6,10,10,12,6,2,10,12,12,9,11,13,6,12,3,6,3,10,9,9,9,6,9,9,16,16,9,9,6,6,16,12,6,20,9,9,9,4,12,9,4,9,8,16,6,15,8,4,6,10,21,21,3,6,2,2,4,4,2,3,23,6,3,23,10,12,14,9,12,10,4,10,12,24,4,10,9,3,9,9,18,11,4,8,9,10,12,12,4,10,6,9,5,22,6,8,4,6,4,9,6,6,9,6,3,6,9,3,6,6,4,12,9,12,6,9,9,8,6,7,12,12,6,14,18,12,14,14,20,20,17,17,6,6,13,13,9,7,6,6,9,3,10,9,18,9,4,12,5,3,5,18,14,9,6,4,8,8,2,5,12,12,3,12,6,9,5,6,6,11,18,18,8,8,3,13,9,9,9,2,6,6,21,12,6,3,3,6,12,18,7,4,9,4,6,6,2,8,7,7,5,5,10,2,6,3,9,5,6,8,9,6,4,3,2,3,9,9,20,20,14,9,4,4,6,18,6,4,9,14,18,18,9,9,9,6,6,11,12,3,8,6,4,12,12,8,3,6,8,8,3,14,10,3,6,9,8,8,6,6,6,6,9,9,8,6,4,4,3,10,6,9,6,8,6,14,8,4,9,10,13,13,6,6,14,4,6,4,9,10,5,13,19,6,2,4,5,14,6,24,14,8,6,3,5,4,6,6,6,12,21,3,9,12,9,9,22,12,9,4,22,22,4,7,4,15,12,12,16,16,16,16,3,4,8,3,2,6,9,9,6,14,3,7,5,5,9,10,9,9,20,3,20,8,20,19,20,9,4,6,6,8,6,6,4,6,8,9,9,18,20,20,6,9,6,8,12,7,6,10,3,10,12,18,16,12,14,6,6,6,10,3,8,22,8,8,9,4,6,6,3,3,9,5,15,9,3,2,9,9,9,10,16,10,13,13,9,11,11,6,3,9,14,9,6,9,20,3,3,3,9,15,3,18,3,4,5,14,9,3,18,3,12,5,12,10,10,6,9,20,6,13,15,4,14,6,3,8,18,3,13,10,9,3,3,11,10,3,3,10,21,3,6,4,4,3,3,18,3,18,6,9,10,6,18,10,10,5,7,5,7,5,18,12,4,10,6,6,2,13,3,3,6,6,6,16,16,10,10,24,20,9,9,5,9,8,8,9,12,18,18,6,3,15,14,10,9,8,8,12,4,15,10,6,5,4,6,12,6,6,23,6,12,18,12,8,4,6,3,20,20,18,12,8,14,16,9,4,4,6,6,9,7,6,10,21,10,8,9,12,12,12,12,9,9,4,4,6,4,4,4,19,8,12,3,4,10,6,22,22,3,15,9,3,15,3,6,14,10,9,10,10,4,2,6,16,4,9,9,6,9,8,16,12,9,9,9,18,12,12,6,4,6,6,3,3,22,22,24,4,18,14,9,9,20,9,14,6,24,24,7,7,19,6,6,8,15,15,20,20,4,4,3,3,20,9,19,3,20,9,5,6,20,20,12,12,8,6,4,15,6,10,12,4,6,18,9,6,3,6,19,19,2,6,18,8,6,10,6,6,15,10,4,3,9,9,9,9,5,20,6,2,6,6,9,4,6,4,22,22,9,9,18,6,8,8,12,12,8,14,12,18,18,20,12,14,6,18,14,2,12,7,12,12,22,20,4,4,6,6,24,12,4,6,3,8,12,3,7,6,7,19,7,9,7,6,5,19,6,14,9,5,5,5,7,10,9,9,7,7,8,12,12,12,8,3,4,6,15,6,9,20,9,5,14,4,6,7,6,18,6,4,6,12,3,6,6,3,9,6,6,6,3,3,6,6,9,12,8,3,12,3,9,3,3,20,20,18,12,6,18,9,6,20,20,6,6,3,6,3,7,6,6,6,13,6,15,7,6,12,9,24,24,12,6,6,12,6,14,2,3,9,12,12,9,10,9,7,5,8,18,10,10,10,10,5,2,6,7,16,8,4,8,4,9,8,4,12,12,7,3,3,10,24,15,24,9,6,6,9,9,4,20,23,18,6,6,5,19,18,18,3,9,7,7,6,10,10,16,6,6,9,8,12,9,6,22,3,3,24,6,14,10,5,6,14,14,4,12,6,6,9,9,10,8,8,4,18,19,16,16,6,5,5,6,5,7,6,9,6,20,12,12,6,8,10,9,22,22,4,15,12,13,24,24,8,2,3,6,10,3,4,8,4,16,16,16,14,14,22,22,20,20,9,16,12,6,8,6,6,6,8,12,9,6,5,8,6,6,6,18,3,2,6,9,9,15,15,6,14,5,3,2,10,3,11,8,9,2,6,3,18,10,10,9,9,3,4,14,14,6,6,18,3,3,10,4,6,9,12,6,13,6,6,3,6,3,6,19,16,18,18,3,4,6,4,8,8,12,12,6,6,6,6,2,3,12,9,15,4,12,15,19,19,10,10,18,6,10,10,10,10,18,3,18,18,3,3,3,10,17,17,11,6,8,7,14,14,2,6,4,6,18,18,10,9,6,6,6,3,9,6,18,9,9,9,3,4,10,9,9,9,6,6,9,9,6,9,3,3,6,4,6,15,3,10,3,6,18,6,18,18,6,12,22,6,6,18,9,9,12,4,3,8,15,14,14,14,4,20,12,12,8,8,15,15,12,12,9,21,4,9,15,15,8,6,4,3,12,12,6,10,6,2,3,3,6,6,6,6,20,8,22};

  static  int rectangles_array4[2913] = {
  6,10,3,8,5,6,5,11,4,6,10,1,8,9,5,5,16,9,12,4,20,8,11,7,5,8,5,9,11,6,9,5,18,4,8,5,2,10,2,2,20,11,20,2,12,0,12,10,12,1,17,0,6,10,8,4,2,19,3,8,1,14,3,6,8,15,1,4,2,3,1,5,3,14,1,15,5,10,9,11,9,12,10,9,6,8,4,11,8,11,9,11,11,9,1,10,6,7,0,6,1,6,5,20,2,12,4,14,8,17,0,14,8,8,0,12,9,2,2,3,5,14,4,4,6,3,3,10,8,3,12,8,5,16,4,19,8,6,10,9,0,4,9,18,3,18,3,16,2,9,2,14,5,18,3,8,7,8,10,14,7,13,12,13,1,13,8,8,8,7,0,1,9,12,9,7,0,13,12,14,9,14,9,18,6,13,3,13,0,6,6,10,10,4,5,9,20,2,5,2,5,2,13,0,1,2,13,0,11,10,11,6,18,3,18,1,13,0,13,9,13,10,13,2,12,5,14,4,7,5,12,9,3,0,12,4,13,10,10,8,10,0,12,4,8,11,9,10,20,1,14,3,15,11,17,3,7,4,10,8,15,3,12,6,14,1,13,10,12,9,6,9,7,8,7,0,15,0,15,8,15,0,8,0,9,8,9,12,12,6,16,2,0,4,9,0,18,0,8,10,13,9,14,8,15,8,9,7,14,2,5,11,13,10,9,8,12,1,15,1,10,3,12,8,6,10,5,4,11,7,9,2,3,10,16,9,21,0,18,3,18,0,5,6,12,10,15,3,15,5,11,8,15,9,13,9,18,1,14,1,12,1,14,0,17,5,18,3,15,0,4,2,14,6,20,1,16,7,12,4,12,8,15,7,6,1,6,0,13,9,12,8,16,0,14,7,5,4,16,6,12,11,11,12,6,10,8,14,5,11,3,3,3,20,5,13,6,12,8,9,10,13,9,14,8,20,6,18,7,18,0,9,0,17,1,14,8,9,9,14,8,6,1,10,5,5,0,8,10,6,4,12,12,12,3,2,6,14,0,19,0,12,0,13,3,6,0,15,9,12,1,15,7,19,6,8,5,14,2,18,2,17,12,14,10,14,6,6,11,12,10,16,6,9,5,10,8,6,10,8,1,9,3,2,10,8,10,0,14,9,14,1,15,0,19,2,3,9,18,0,12,2,14,5,18,5,22,8,11,7,22,12,15,0,13,9,14,6,14,6,3,3,12,12,13,8,20,3,20,0,10,8,13,9,13,0,6,3,8,2,15,3,19,3,19,3,4,6,15,0,17,5,8,6,5,10,10,0,15,0,14,11,14,8,15,3,11,6,12,0,3,3,12,1,17,2,7,8,3,10,5,11,3,18,3,9,3,13,8,13,4,13,8,7,6,16,6,11,0,13,5,10,10,14,6,12,7,8,5,3,5,5,8,3,1,5,1,1,3,6,7,14,1,13,12,13,9,15,5,15,6,15,0,5,7,17,10,15,0,14,8,13,6,13,8,17,4,12,11,11,9,8,1,9,9,18,8,2,0,18,2,2,12,13,1,11,3,12,2,18,3,22,2,1,0,19,3,20,0,13,0,10,8,4,2,14,3,17,6,10,4,2,10,5,12,0,15,5,8,1,19,8,20,9,15,2,16,2,20,3,15,0,16,2,10,1,14,3,3,10,3,2,12,10,12,11,4,0,9,8,13,5,12,1,19,0,20,0,18,9,11,0,1,1,13,4,12,4,15,1,13,5,16,5,10,7,12,0,17,0,15,0,13,8,12,2,12,1,15,0,6,10,12,8,12,8,13,1,15,6,18,11,12,0,11,11,12,8,9,10,4,11,5,8,15,12,12,7,11,3,14,8,9,1,11,9,12,1,6,1,8,2,11,7,14,9,14,7,4,9,7,11,2,8,3,11,0,10,2,20,2,12,0,14,0,12,8,4,10,14,2,14,2,5,9,12,6,12,0,18,5,10,2,13,6,11,7,18,11,10,0,15,4,13,7,14,7,12,6,16,0,16,5,5,5,9,9,13,5,19,3,5,0,2,5,1,10,8,11,12,4,12,3,5,4,6,10,0,0,3,2,7,5,10,9,18,9,12,11,13,9,4,2,13,9,9,1,8,3,5,8,9,0,6,4,13,5,12,11,14,5,12,0,20,9,12,10,14,7,12,2,18,1,6,12,14,6,11,1,9,7,17,2,7,1,8,11,3,20,8,20,0,8,5,4,8,6,0,20,10,12,0,6,0,20,2,18,3,13,8,5,9,6,9,10,1,11,7,14,5,13,0,12,1,2,2,20,1,14,0,15,1,9,0,16,12,7,11,12,10,15,3,16,3,16,12,10,7,11,11,12,11,3,2,12,5,14,0,10,8,5,11,11,9,5,10,10,7,12,0,12,2,12,1,12,0,5,6,14,5,9,8,11,6,17,8,8,4,12,9,16,1,11,3,7,12,12,3,12,3,13,5,11,9,17,2,12,0,12,5,12,9,2,5,4,2,7,0,2,6,6,11,15,8,3,2,19,1,14,4,14,8,14,4,8,3,20,2,8,9,16,12,11,12,12,10,14,5,18,6,13,1,15,9,10,3,16,9,15,0,13,2,5,1,5,1,16,9,16,6,18,1,9,0,14,3,16,3,11,11,15,8,17,3,3,0,2,0,13,5,12,5,18,0,13,5,9,12,6,9,13,8,6,2,20,2,14,8,8,12,9,11,4,10,8,7,12,0,18,0,16,1,12,9,12,8,12,4,15,3,15,4,15,0,15,0,14,3,7,10,8,12,7,0,16,7,10,11,12,3,16,0,0,0,10,10,4,8,9,9,6,11,8,4,8,7,1,15,7,13,9,3,0,10,6,15,0,20,2,13,0,2,1,18,0,17,0,0,2,12,9,17,5,15,0,15,0,5,0,13,8,13,8,13,10,12,11,13,7,14,12,12,1,20,0,14,0,13,0,6,0,14,1,13,4,17,5,16,3,14,10,11,0,4,5,19,0,8,3,17,4,16,3,18,1,17,0,15,8,22,1,20,2,3,6,7,11,4,9,4,3,18,2,13,7,13,10,12,0,11,2,13,5,9,5,3,6,12,8,9,1,19,1,9,6,12,10,14,4,8,6,19,0,17,1,18,0,3,2,14,5,10,11,7,12,5,10,11,9,14,8,12,7,2,1,8,7,6,17,4,2,6,9,7,10,8,18,3,18,4,5,11,15,7,12,12,12,2,14,10,14,3,14,1,3,1,18,0,5,6,14,4,17,8,8,5,3,0,12,0,9,2,0,10,10,8,13,11,2,1,13,12,10,7,14,10,11,10,20,1,17,9,12,12,14,5,16,4,10,1,15,12,12,8,19,0,14,6,13,9,13,8,7,4,17,3,14,2,3,4,19,10,19,1,15,5,10,4,0,8,14,0,6,1,18,4,6,1,1,2,18,0,12,7,9,7,12,7,12,10,15,3,4,6,8,12,11,2,8,0,0,2,12,10,7,9,17,0,19,1,12,3,12,12,12,10,14,10,13,7,7,9,0,11,3,15,2,13,4,20,8,12,2,3,3,13,5,17,2,12,10,12,10,12,12,12,0,9,7,14,8,13,1,9,2,15,0,9,2,15,4,17,0,15,0,15,3,20,8,13,0,0,5,11,4,10,8,11,4,14,2,4,8,1,9,13,10,4,6,14,9,9,9,9,11,9,12,14,8,18,3,18,0,13,10,11,8,16,5,7,9,13,3,20,7,15,0,19,1,12,1,3,8,5,9,11,4,6,5,17,11,1,10,10,11,11,9,15,0,2,0,9,9,18,0,12,3,2,5,12,10,5,9,7,9,4,0,11,11,6,11,12,5,14,5,14,0,16,4,8,0,13,0,12,6,10,1,0,6,9,1,10,7,9,10,3,7,3,10,3,10,4,5,8,9,3,2,9,11,11,16,7,16,6,19,3,14,0,9,6,14,4,7,9,14,12,14,5,4,11,3,4,16,4,13,10,15,12,12,3,12,8,6,0,4,0,15,0,6,3,13,6,6,10,10,7,17,2,11,1,15,1,10,11,7,10,15,3,15,7,12,9,15,5,8,7,12,9,7,10,13,9,9,0,14,0,12,1,7,11,16,2,8,0,5,2,14,3,9,4,12,9,13,0,14,2,11,7,13,7,17,4,13,10,18,12,17,5,16,4,18,4,15,0,20,2,16,9,12,0,5,0,12,5,10,8,6,3,16,6,8,6,10,11,14,0,16,3,6,4,17,2,2,4,18,8,6,6,14,8,15,6,14,4,7,8,13,9,8,0,17,0,21,0,12,1,5,1,6,5,14,1,11,0,13,1,0,1,14,7,12,8,13,11,9,7,6,10,10,6,15,8,11,8,1,0,15,7,20,2,14,2,12,1,7,8,12,2,14,3,17,5,13,9,13,12,12,11,20,1,7,6,9,1,19,4,3,1,9,4,6,4,15,9,12,6,15,3,14,1,14,0,15,3,9,1,13,1,6,8,0,0,14,1,14,8,10,11,10,9,14,8,11,3,13,0,12,11,10,8,11,10,12,10,4,0,11,1,11,6,14,7,12,12,11,1,9,0,1,1,9,9,11,11,18,4,15,1,14,3,15,7,14,12,7,0,19,1,16,6,17,5,0,7,1,1,6,1,15,3,4,0,6,7,12,6,9,4,20,2,13,12,13,1,13,2,13,2,3,7,17,5,16,0,15,0,9,4,12,10,13,9,14,8,10,0,13,9,14,0,1,10,16,10,12,8,13,2,11,7,13,0,12,8,12,6,14,0,14,0,4,1,4,8,3,11,0,6,2,18,0,11,9,7,3,18,7,18,3,9,2,10,5,11,10,12,4,6,9,9,11,10,2,21,0,5,12,1,10,6,9,2,5,12,9,18,2,16,1,12,4,10,5,14,7,7,2,5,7,0,2,20,5,5,0,13,0,4,2,12,12,6,0,10,7,11,7,21,3,21,7,9,0,15,1,13,7,13,10,13,10,13,10,5,0,11,2,15,1,10,0,6,0,13,2,13,8,13,9,12,3,16,6,10,7,12,7,10,3,16,4,0,11,10,12,17,5,16,5,3,4,4,3,16,6,14,7,4,0,10,6,0,0,3,9,12,6,8,2,12,5,14,10,12,7,17,9,13,0,12,9,10,9,0,8,9,9,15,10,15,6,19,2,12,10,14,5,11,3,10,5,20,7,4,8,6,19,3,20,2,5,10,11,0,7,1,11,0,17,12,17,7,13,0,8,6,7,0,13,3,12,2,9,6,14,5,12,6,17,4,14,0,13,2,6,0,21,1,15,11,13,7,14,3,22,7,12,11,15,8,13,8,9,8,12,3,19,0,22,0,7,11,10,0,14,2,13,8,15,7,11,11,15,1,16,5,12,4,6,9,15,6,12,7,6,10,12,3,4,2,13,9,1,0,0,3,3,5,16,5,10,6,12,2,12,10,13,6,9,2,14,3,10,2,17,2,0,7,17,5,11,8,11,5,15,4,15,6,12,9,12,4,4,5,14,9,12,10,12,2,12,9,12,8,7,1,13,2,15,0,15,6,8,1,6,10,12,3,18,1,18,11,18,6,18,6,16,12,9,6,11,6,16,4,18,8,18,3,15,6,18,0,13,7,4,0,15,3,9,8,5,3,5,10,4,2,8,18,3,4,6,13,4,12,8,13,8,3,0,14,0,14,0,6,0,14,8,15,8,10,7,7,12,11,7,21,0,15,0,18,7,16,0,18,2,14,1,9,5,5,11,12,9,12,10,12,9,13,3,12,9,13,9,11,7,5,8,4,0,0,0,11,3,12,10,12,7,9,10,11,9,19,1,15,5,6,10,12,10,14,3,7,7,14,7,18,9,13,6,10,0,3,4,16,8,16,7,15,3,18,0,13,2,17,1,8,0,15,1,20,3,9,9,7,10,11,4,10,3,15,0,6,9,12,10,16,10,6,0,17,5,14,1,7,10,14,3,9,3,6,1,16,0,12,8,10,0,21,2,20,2,8,8,11,9,7,12,11,8,11,4,12,0,12,4,12,11,15,8,13,10,12,9,17,6,10,2,2,7,3,2,15,8,10,7,18,3,20,2,17,5,16,4,11,12,12,3,13,0,8,9,19,9,6,10,5,12,3,15,4,11,9,5,4,11,10,16,3,13,8,8,10,5,2,2,11,9,9,5,2,6,6,20,2,10,10,3,5,17,0,9,10,11,0,6,4,9,5,6,7,11,12,18,0,0,0,6,0,20,4,21,1,3,0,18,7,17,2,19,0,15,0,14,0,5,0,12,5,4,3,4,10,16,7,17,3,12,5,14,6,15,0,12,0,12,9,6,0,2,7,12,6,8,4,12,10,18,3,6,5,12,0,12,11,11,1,14,1,7,0,12,12,12,10,9,1,0,6,12,5,4,4,8,1,10,1,12,1,5,0,9,1,8,8,5,9,6,2,12,10,14,8,9,12,5,4,14,9,14,8,11,5,5,9,11,2,18,3,12,5,20,0,18,1,15,5,6,2,14,10,13,3,13,3,16,0,0,12,21,0,15,1,15,0,3,0,15,0,12,3,17,0,12};

  static  int rectangles_array5[2913] = {
  7,4,12,20,5,13,11,19,3,8,4,12,2,14,11,3,11,5,8,5,0,6,6,20,13,3,11,13,5,12,21,8,1,1,8,6,16,1,13,1,2,5,4,3,1,7,1,1,5,11,13,7,7,5,1,12,17,3,3,1,11,14,12,8,13,17,18,10,1,1,5,12,17,17,17,6,5,0,3,6,0,6,6,8,3,0,11,6,20,6,13,6,6,18,23,12,12,8,16,19,2,17,4,4,4,16,12,0,10,8,8,0,0,16,18,8,19,11,9,0,6,5,5,15,17,19,0,6,1,3,8,11,12,16,16,5,2,10,5,20,12,4,5,1,1,0,0,7,12,13,17,14,6,8,8,15,14,14,10,15,0,0,3,0,1,0,0,20,3,5,11,11,11,11,11,12,13,4,0,0,0,1,1,6,16,16,19,4,18,2,11,5,13,4,3,19,0,1,23,0,12,1,5,2,3,11,12,12,7,1,7,10,6,16,8,5,0,4,0,0,6,7,19,18,18,20,15,6,8,14,9,6,7,11,16,6,0,0,7,20,14,2,1,3,0,21,7,7,8,15,17,3,11,1,2,14,8,2,8,17,11,1,16,16,14,14,1,0,2,2,20,6,7,10,8,4,2,6,3,0,10,10,16,16,10,0,7,6,9,0,0,0,12,11,11,14,15,15,7,7,0,0,3,3,4,10,19,17,13,18,19,0,4,4,3,1,19,3,5,2,19,22,14,2,7,6,12,14,13,14,7,4,14,6,6,9,6,6,5,20,5,5,11,2,0,0,14,8,14,5,8,13,14,12,1,1,12,22,16,13,6,0,7,4,0,0,12,12,14,14,15,14,17,0,1,1,17,9,7,4,6,10,17,1,11,6,17,17,7,15,8,14,16,4,19,13,3,6,11,7,6,8,15,1,8,5,2,11,11,6,1,4,18,4,16,7,7,2,20,14,2,0,0,17,8,3,12,7,8,7,7,6,23,17,17,11,11,9,17,0,0,18,18,12,6,6,1,0,15,11,16,2,20,0,13,11,7,8,9,0,0,1,18,15,15,17,18,0,4,5,14,0,0,7,7,5,15,0,7,2,2,2,6,5,6,0,3,7,7,13,6,17,0,2,8,8,8,3,6,0,12,21,8,5,7,12,7,19,20,14,20,20,11,11,3,18,17,20,6,6,0,0,0,0,3,11,0,0,8,12,0,6,2,3,7,6,1,10,3,5,4,1,13,5,1,2,10,9,10,10,17,7,1,1,5,12,17,15,16,13,11,6,5,5,1,1,15,11,4,4,0,0,19,11,8,8,12,12,2,2,6,7,6,6,3,0,13,7,6,3,15,14,12,2,16,16,3,0,10,5,16,19,6,0,2,12,0,11,20,11,14,11,11,8,17,0,0,7,1,20,7,17,2,3,6,8,12,10,5,20,0,2,11,3,17,18,15,14,8,8,2,19,20,3,6,0,0,10,11,5,8,5,6,22,10,4,8,9,10,6,5,4,4,10,10,2,2,4,4,4,4,20,20,2,2,5,11,9,5,14,14,11,9,6,21,5,5,4,7,13,8,2,19,10,2,0,3,2,7,0,3,19,14,14,5,6,6,5,5,12,12,3,3,1,11,14,11,11,20,4,3,11,0,0,11,23,10,1,0,3,17,16,12,12,7,6,8,11,7,6,9,0,5,5,5,4,17,17,13,17,16,9,0,12,9,9,6,6,5,6,13,5,3,16,19,13,10,9,16,14,10,0,11,2,4,0,19,8,10,17,18,18,11,11,3,5,0,17,17,17,18,8,6,12,12,5,9,9,11,13,8,8,11,11,6,0,0,3,10,7,13,4,2,5,0,4,10,10,11,10,12,21,20,17,19,18,6,16,18,6,4,21,7,2,10,11,9,10,11,0,8,0,3,20,1,0,18,7,3,2,2,1,18,15,16,5,13,3,14,12,16,8,12,20,7,2,6,7,0,11,12,21,3,9,11,7,8,16,14,11,13,0,10,4,0,6,6,11,11,16,7,16,14,11,6,18,0,5,0,1,1,17,5,17,5,9,4,7,7,4,12,3,6,9,5,4,6,2,19,19,5,8,13,12,6,11,7,5,9,14,14,11,12,0,0,1,14,20,11,11,14,16,11,5,16,15,8,16,0,5,5,6,10,10,18,10,0,4,12,6,12,16,11,11,12,4,4,9,5,9,0,16,16,7,9,1,6,18,8,19,8,8,17,11,2,12,4,1,3,6,11,8,18,16,3,3,0,0,11,11,12,20,8,0,10,11,12,0,0,5,14,14,1,0,3,3,10,10,6,14,17,1,13,16,17,3,6,6,1,1,18,18,1,3,0,3,5,0,7,7,3,3,8,8,13,5,1,1,15,2,6,15,12,12,2,7,11,9,5,8,19,19,19,18,19,1,2,16,16,22,13,10,8,10,10,15,7,16,19,15,9,9,7,4,8,7,15,8,19,19,1,12,5,4,16,16,0,8,4,2,1,15,11,9,5,4,3,14,11,0,7,1,11,7,23,16,0,11,17,17,5,5,8,8,2,2,0,4,18,0,15,21,5,5,6,5,16,5,8,6,13,10,15,3,8,6,6,13,15,15,18,18,17,17,1,2,2,15,2,2,5,2,0,13,2,11,6,8,11,8,0,0,6,20,19,6,8,3,19,5,6,16,5,5,4,13,1,12,7,5,11,11,5,2,0,0,0,0,2,13,7,8,15,10,17,9,4,13,8,18,18,20,8,8,5,5,6,0,8,8,14,11,14,14,17,17,0,0,8,17,6,22,9,0,1,18,7,10,2,12,5,5,3,13,19,9,7,1,14,21,11,6,6,4,10,17,4,0,0,0,7,1,10,8,5,0,0,2,2,0,1,3,11,10,3,6,10,8,2,6,0,0,0,19,18,16,17,16,16,8,7,8,0,8,5,6,7,8,8,10,5,12,9,14,9,18,6,6,16,17,12,9,7,10,10,10,12,17,16,16,0,1,18,18,9,0,0,2,1,8,8,10,10,7,12,15,2,1,1,1,1,11,11,13,14,13,18,22,12,7,7,7,14,14,7,13,7,12,7,0,12,13,13,17,19,3,5,0,16,18,15,10,9,16,9,15,8,4,9,6,7,12,12,6,6,5,5,5,5,3,3,11,11,8,6,19,4,1,11,12,12,0,12,21,4,2,10,7,0,15,3,7,20,12,5,11,4,0,4,4,19,9,13,13,11,6,0,9,18,7,18,14,14,14,8,9,7,7,14,18,18,18,1,21,20,1,18,17,16,18,10,18,7,7,13,6,0,7,2,18,2,7,1,0,3,15,10,3,0,0,0,4,17,20,3,3,6,6,14,19,2,1,0,10,16,16,12,16,6,6,9,9,10,8,10,10,1,5,10,14,4,2,4,4,8,8,17,16,18,2,2,2,3,2,8,3,22,11,11,11,8,8,15,15,14,13,15,4,15,15,11,8,6,9,4,7,11,12,18,2,13,12,5,7,5,19,5,5,1,4,4,4,4,4,1,1,5,4,5,5,7,0,11,6,3,18,8,4,11,4,13,1,4,7,19,9,6,5,3,2,6,3,3,3,1,2,3,16,8,0,0,11,6,9,17,19,8,17,18,19,2,5,6,19,19,18,18,13,14,18,13,17,2,9,5,7,8,9,9,9,8,12,10,10,0,3,1,23,10,0,0,2,13,21,1,7,0,1,1,5,6,5,5,13,7,9,9,4,6,21,21,5,10,0,2,0,15,13,0,7,13,22,3,11,7,7,3,1,1,18,15,10,9,11,7,2,2,4,8,9,4,11,7,0,0,1,2,7,3,14,14,19,0,4,2,2,12,15,10,18,4,0,6,13,13,13,7,6,18,20,18,13,13,9,20,18,2,2,15,11,18,19,12,12,1,15,7,12,0,3,0,0,11,14,21,0,1,6,6,0,0,18,0,0,1,1,16,3,5,10,15,10,8,2,16,6,16,22,10,6,2,16,20,0,6,10,15,7,6,6,0,0,19,17,4,4,16,16,16,18,0,3,17,0,12,12,9,3,7,4,3,2,5,0,19,19,15,22,15,15,6,3,3,8,4,2,2,2,7,3,6,1,8,0,18,20,19,18,8,15,18,18,6,7,6,9,5,7,4,10,5,8,0,12,14,10,17,6,6,13,10,10,9,3,0,12,0,0,2,2,0,0,8,8,1,1,0,10,11,11,10,16,10,7,8,0,11,6,0,15,14,1,0,3,2,6,20,20,19,0,3,12,4,3,8,15,13,6,9,0,9,9,5,4,7,0,0,0,4,3,13,13,2,13,8,9,8,14,14,12,12,17,17,8,10,10,9,12,12,12,12,12,10,15,10,1,7,5,12,16,0,10,4,20,11,18,0,0,2,2,7,1,16,15,8,8,6,19,18,5,6,6,0,0,5,5,1,13,1,18,17,20,16,1,8,0,6,5,1,5,1,11,11,18,18,15,11,11,9,15,17,17,16,16,5,18,21,21,20,19,2,4,9,19,2,10,10,8,5,5,4,4,7,6,4,0,1,1,17,3,3,2,2,7,22,16,3,10,19,0,5,8,1,6,3,13,14,7,7,10,8,19,14,6,0,0,1,14,10,12,1,1,7,10,7,8,0,0,5,5,0,0,3,3,4,18,19,19,18,18,17,10,19,12,10,10,2,6,14,14,1,21,1,16,1,0,1,1,9,16,4,4,4,4,0,16,7,11,5,6,1,1,9,4,16,0,5,3,14,16,11,9,2,6,8,1,1,16,19,19,4,20,12,12,12,12,8,8,14,14,7,7,3,1,11,6,18,23,15,15,15,19,14,12,3,1,1,2,2,14,3,6,6,0,0,6,1,7,7,20,6,2,4,4,2,2,2,2,15,18,12,1,8,6,12,14,14,18,6,3,6,5,9,16,8,8,6,5,10,11,2,0,4,7,2,4,0,17,17,0,3,7,9,14,14,21,21,4,8,4,17,16,11,18,5,8,8,8,8,8,6,8,11,11,3,10,19,18,11,4,19,19,18,17,17,1,1,5,5,0,4,0,0,5,6,2,2,0,4,0,0,9,7,8,0,10,0,1,1,10,14,14,10,18,16,16,16,14,15,15,0,10,9,9,11,5,20,10,8,10,10,11,8,9,14,2,0,16,12,12,6,0,8,8,11,3,12,16,6,10,10,12,12,15,15,20,20,19,4,3,15,2,12,11,1,10,3,6,0,0,16,12,6,22,8,8,2,17,9,5,9,11,13,1,18,12,10,6,18,18,17,19,14,10,9,17,8,6,9,9,17,20,20,20,17,17,2,2,0,20,6,9,9,9,4,9,0,1,0,0,12,12,5,6,5,16,13,13,4,4,7,19,11,2,2,13,0,11,1,10,19,10,1,1,10,10,6,12,7,7,2,5,13,4,2,6,8,20,15,17,0,0,5,2,9,6,8,1,0,0,7,5,2,12,8,8,8,11,9,14,20,22,4,17,11,12,19,18,1,1,16,1,10,8,11,11,6,6,9,8,10,5,12,14,14,10,5,4,4,8,10,5,13,13,13,1,13,13,17,17,0,10,9,9,7,7,12,15,17,14,17,3,17,4,17,8,7,4,1,5,0,11,7,7,17,6,15,15,10,10,15,1,0,0,1,22,9,6,6,9,4,0,3,6,1,14,20,1,0,12,0,7,14,9,1,11,11,11,5,18,18,15,17,17,20,15,2,8,17,20,8,7,6,20,20,1,1,3,6,9,3,0,9,4,4,15,15,15,15,1,2,1,1,6,2,11,1,0,6,7,7,0,0,13,17,9,13,19,3,2,16,0,9,7,0,6,0,0,11,7,6,14,14,0,0,1,12,8,6,5,9,8,12,19,0,4,16,7,7,6,18,18,4,0,0,0,4,14,9,8,8,7,1,0,15,10,6,12,4,1,1,10,4,13,13,15,14,19,16,12,12,10,14,7,15,9,1,6,19,0,13,6,6,6,7,8,8,10,2,13,13,10,10,9,2,2,1,2,3,8,8,20,6,6,3,6,8,2,17,2,3,6,6,19,7,11,1,0,0,7,7,7,0,0,0,19,19,9,8,7,8,8,2,9,4,8,8,0,0,0,0,2,2,6,0,7,4,5,15,16,2,1,7,7,5,1,16,14,18,16,12,9,4,2,6,6,14,14,6,13,16,20,11,6,2,13,19,15,12,8,1,0,3,3,5,5,3,4,7,7,11,11,12,17,17,11,9,6,4,9,7,11,11,11,7,7,8,2,0,6,6,6,22,21,18,20,16,16,0,0,16,16,16,16,19,19,5,6,5,2,12,3,4,4,14,14,12,11,5,4,8,8,12,15,12,12,15,6,6,0,3,3,12,13,12,14,10,10,13,10,13,13,2,2,12,13,9,10,9,1,0,5,6,0,4,3,4,16,9,5,7,7,7,9,8,8,4,17,18,17,19,20,17,11,5,8,8,6,6,5,14,14,2,1,13,2,9,9,0,0,1,11,9,13,14,0,1,1,20,0,8,8,13,13,13,13,15,15,15,8,13,13,13,13,14,18,16,20,12,12,19,6,19,19,16,14,19,19,19,19,2,17,1};

  static  int rectangles_array6[2913] = {
  12,4,18,9,2,12,12,4,7,12,4,19,8,6,14,14,3,2,2,2,2,8,2,10,14,8,15,5,2,3,6,13,3,3,8,7,21,2,10,2,2,11,2,2,2,19,2,2,7,18,2,6,12,4,8,18,6,2,2,8,8,3,8,12,6,9,18,16,2,18,10,14,7,9,9,4,7,4,6,2,2,2,2,6,12,8,16,3,8,2,5,2,2,6,18,4,8,10,10,18,22,18,3,2,2,10,4,2,3,6,6,2,2,9,9,2,6,20,9,9,7,5,6,18,8,18,3,4,2,19,11,11,5,4,4,5,8,12,3,6,22,17,2,3,3,3,3,4,19,6,17,3,4,3,3,10,3,8,9,6,5,3,8,3,10,3,3,10,2,12,18,22,4,3,3,11,12,11,10,1,1,1,1,1,9,9,18,4,18,6,14,3,6,3,18,5,2,18,19,2,19,2,7,20,22,7,11,11,2,3,4,12,6,18,6,8,2,12,2,2,2,2,9,7,9,5,5,16,10,5,5,2,18,18,9,7,1,1,5,7,5,12,11,15,8,9,5,5,3,10,10,16,7,2,3,6,10,3,5,8,5,3,6,6,3,13,2,3,3,3,12,2,6,8,10,6,1,6,1,1,9,9,9,9,6,8,8,2,5,1,2,3,24,13,6,16,6,6,5,2,2,2,2,2,9,3,6,5,3,18,19,2,1,1,6,2,9,10,3,11,5,18,2,8,12,4,14,4,5,3,6,20,19,2,3,2,3,3,6,15,6,6,18,12,2,2,9,13,9,3,3,3,9,5,2,2,6,18,10,11,8,9,4,3,2,2,3,3,9,9,19,19,10,5,3,3,6,9,4,14,2,6,9,7,17,11,13,9,5,6,6,8,3,24,10,6,18,16,3,6,2,2,2,9,6,2,8,5,5,2,3,19,6,2,5,5,5,3,7,9,3,2,2,9,6,2,11,6,9,6,6,9,19,6,6,2,2,6,6,2,2,18,18,11,7,15,22,8,9,12,7,11,7,12,9,22,11,6,24,5,5,12,18,8,8,18,21,2,2,3,2,2,2,3,2,8,10,2,3,3,2,5,1,5,2,2,3,7,4,7,2,6,2,7,5,4,5,11,4,8,23,6,21,2,4,8,5,10,9,6,9,9,9,9,2,18,21,6,6,6,8,5,5,5,3,6,1,2,3,4,1,2,9,24,2,2,2,12,1,12,18,18,12,2,2,2,4,16,4,4,11,8,2,2,8,6,18,6,9,4,3,18,2,2,2,2,9,12,9,9,2,2,9,3,14,3,14,14,9,9,2,2,2,2,4,3,8,5,2,6,18,4,12,1,5,5,10,8,15,4,14,4,3,3,18,14,3,3,8,3,10,3,3,11,10,2,2,4,20,10,3,10,2,5,6,4,4,9,14,19,5,8,8,9,18,18,9,23,18,6,1,10,10,2,2,2,2,3,3,1,9,1,6,18,6,4,3,3,5,7,1,5,5,3,3,3,3,3,2,4,4,10,21,6,6,6,6,20,6,4,4,10,6,8,9,4,7,3,19,6,18,2,20,22,2,2,3,2,10,6,12,4,4,17,9,7,7,1,1,14,9,18,4,4,7,22,4,7,9,22,2,8,3,2,9,18,6,2,2,2,9,8,6,6,4,19,3,12,18,4,9,2,2,2,2,2,18,20,6,8,3,7,12,18,5,5,4,4,6,2,2,6,23,19,11,4,5,9,9,9,10,3,3,4,7,5,12,23,4,18,9,9,3,3,12,18,12,18,9,9,18,2,2,5,6,2,8,21,3,11,5,6,6,22,6,2,2,3,6,3,16,2,16,6,2,4,5,5,4,4,3,8,6,9,10,4,3,6,12,20,9,9,4,4,3,4,3,2,5,7,10,2,18,8,18,3,18,4,2,2,2,12,9,9,19,11,3,20,2,8,8,3,8,16,4,4,6,2,4,6,3,7,16,7,4,2,3,4,2,4,23,2,4,10,2,3,3,6,6,4,21,4,6,19,14,6,2,11,3,2,2,18,11,20,13,11,7,5,5,2,3,4,8,14,9,18,3,24,10,18,3,11,12,4,4,6,5,2,2,2,2,16,20,2,2,6,6,9,15,19,7,9,8,18,4,9,7,11,2,5,5,8,6,4,6,4,2,4,10,7,20,4,6,12,3,4,4,3,8,3,1,5,5,10,23,7,2,6,4,8,4,4,8,5,19,8,13,24,2,2,6,6,18,9,2,2,3,3,3,3,19,6,16,3,4,15,4,2,2,6,11,21,4,3,21,19,3,3,7,9,8,11,9,18,7,8,6,2,2,2,6,6,1,2,1,6,2,1,3,5,1,2,19,18,9,2,10,10,3,8,18,3,4,4,14,4,5,4,11,6,9,19,9,18,9,24,14,9,6,13,6,7,3,3,5,8,9,6,9,6,7,7,3,3,5,2,2,3,9,9,3,4,4,3,5,5,12,9,12,11,11,6,20,14,16,19,10,4,21,3,14,2,9,4,19,20,2,8,6,6,2,2,6,6,8,2,2,2,9,2,7,7,3,2,2,3,10,7,6,6,2,10,9,6,5,16,8,2,9,9,9,9,18,18,18,19,2,5,2,2,6,11,7,18,2,18,8,18,2,2,1,1,7,9,21,7,22,12,9,6,7,7,6,6,10,3,7,7,6,3,3,3,18,2,2,2,2,2,8,9,5,6,19,4,9,5,4,6,6,8,7,10,10,2,4,4,2,2,6,6,9,15,9,9,9,9,4,2,10,4,10,9,11,6,6,9,5,6,6,12,8,8,12,4,4,4,15,8,5,6,3,2,3,20,6,10,2,2,2,2,3,18,10,4,3,9,9,2,2,2,20,20,18,6,22,6,6,24,2,2,2,2,2,9,18,9,23,18,9,4,5,4,3,4,2,2,6,4,4,3,3,6,9,4,11,6,10,10,5,18,19,6,11,7,11,5,3,6,6,6,2,2,9,18,13,4,4,4,2,3,3,5,5,6,6,6,12,1,1,1,1,2,2,18,7,12,9,20,3,18,18,6,9,9,3,6,4,3,4,3,12,6,6,9,12,20,4,1,5,6,6,4,4,9,12,2,3,4,6,8,3,5,5,6,6,6,6,18,9,5,5,3,3,5,3,18,2,3,3,2,2,4,5,22,1,8,10,4,3,5,20,6,6,10,4,3,2,3,2,2,19,2,2,2,5,2,2,8,6,2,6,12,9,9,18,22,6,6,16,9,6,6,2,8,8,2,18,18,11,9,7,6,24,4,6,2,2,2,20,6,2,6,2,1,5,4,2,2,3,3,3,2,9,11,5,5,4,4,5,21,9,6,6,4,5,5,4,5,6,2,3,3,11,3,4,4,4,8,18,16,4,3,4,4,4,4,5,7,24,4,4,12,12,6,6,4,18,18,22,12,6,6,2,9,7,3,6,2,2,2,6,14,17,12,9,12,9,18,9,9,24,20,8,4,10,6,7,7,3,19,9,9,10,9,2,2,4,4,3,6,10,7,9,2,3,6,10,10,5,2,8,12,2,18,16,6,7,4,20,3,2,2,2,4,1,3,19,9,6,2,2,4,18,14,18,9,6,7,20,9,15,6,6,9,9,6,6,4,8,3,4,24,6,3,16,4,5,9,9,6,20,17,7,23,2,2,2,18,3,1,1,6,5,6,2,5,5,2,2,6,18,6,6,11,5,5,5,3,5,8,8,11,4,3,2,2,7,4,3,3,4,19,2,18,5,4,16,18,5,6,6,11,3,4,5,4,4,9,10,21,11,6,3,6,6,11,18,22,6,2,2,18,3,6,4,18,6,2,2,18,2,2,5,5,5,9,23,8,6,9,18,11,11,12,8,14,21,12,4,7,6,4,4,6,3,19,5,9,2,17,4,3,16,5,6,3,20,5,2,2,2,9,2,2,2,2,6,6,3,3,3,7,12,2,6,2,6,14,16,2,21,6,5,8,7,4,6,6,7,9,6,8,18,9,19,24,9,9,18,18,1,8,18,1,4,10,3,10,5,6,9,4,5,7,10,4,2,18,2,2,2,2,9,14,15,4,3,3,6,4,8,6,6,12,9,24,11,9,5,2,6,6,16,10,18,9,10,18,15,15,12,2,2,3,10,18,10,5,7,3,3,3,4,2,1,8,2,2,4,4,2,2,9,9,2,2,2,4,12,12,14,20,4,13,6,2,12,15,4,6,8,1,2,2,6,17,5,5,18,4,3,2,21,3,6,8,9,5,3,5,3,3,5,8,6,3,2,2,10,18,7,7,1,5,12,20,19,9,14,14,3,18,6,9,10,10,12,10,3,3,4,4,2,10,3,7,13,4,10,5,2,6,9,7,22,18,2,2,2,2,3,2,9,9,15,3,6,10,6,9,2,2,2,2,2,3,8,2,3,18,10,10,9,3,5,4,19,6,7,16,18,10,4,6,4,3,6,6,9,12,10,10,6,6,4,6,10,10,18,4,24,6,10,19,10,7,4,5,2,2,2,2,3,8,8,12,3,7,7,4,4,2,1,3,10,12,4,4,6,5,7,5,3,12,4,11,12,9,23,19,6,6,2,2,2,2,2,8,7,9,2,2,10,3,5,4,4,4,2,2,2,2,24,10,23,19,18,9,6,6,20,3,18,3,6,6,6,5,2,2,2,6,2,5,2,1,2,2,19,9,7,14,8,8,9,9,6,2,2,2,2,2,9,2,4,9,7,5,10,4,22,2,3,2,5,4,6,12,6,6,2,19,6,8,6,6,6,24,10,10,19,19,16,8,6,2,18,18,6,6,6,4,6,10,2,3,2,3,3,15,20,2,6,2,3,2,6,9,9,6,2,4,18,2,19,15,7,11,2,18,3,20,5,4,3,4,4,6,6,1,7,4,4,5,3,10,18,15,8,24,2,4,10,18,24,2,4,18,18,9,10,7,6,7,7,6,6,2,18,2,10,11,4,9,2,4,4,4,3,4,3,4,4,14,11,2,11,9,18,4,18,18,9,9,9,3,3,2,2,2,2,2,2,6,2,5,5,2,3,4,4,24,7,4,5,4,2,3,3,18,16,16,4,8,4,9,9,16,19,9,1,24,5,19,3,12,9,10,20,7,7,2,5,6,3,6,2,9,11,11,3,2,6,24,8,6,2,5,2,3,3,3,3,2,2,5,5,9,14,10,5,1,3,5,8,12,2,3,2,2,19,4,2,18,10,18,3,24,4,2,4,5,9,19,8,8,10,6,7,6,6,15,6,7,6,6,2,2,3,3,9,9,9,9,18,18,2,2,1,8,2,5,6,7,2,6,5,9,1,1,3,3,6,3,3,5,5,5,2,2,5,7,6,24,7,2,2,7,8,7,5,3,8,8,3,3,5,6,12,5,9,11,4,9,13,2,2,10,20,9,2,2,22,9,24,16,18,2,3,3,4,7,10,19,2,2,2,3,6,2,8,18,5,12,6,10,24,9,2,2,8,2,3,6,5,5,3,3,7,3,6,2,16,7,8,3,3,1,11,18,6,3,4,4,10,1,9,9,9,9,9,6,10,9,18,3,2,18,3,10,3,1,3,11,3,11,4,10,7,6,2,4,4,4,3,4,3,3,3,3,5,3,3,5,8,19,9,9,6,3,14,4,7,4,4,22,6,3,3,17,6,9,10,5,8,3,3,19,6,10,10,9,18,18,9,9,2,2,8,6,2,6,2,6,6,3,3,2,6,6,2,2,6,4,4,9,9,6,9,18,3,3,3,7,2,6,6,3,16,3,2,2,2,5,9,18,5,17,9,24,18,2,14,3,2,2,2,7,4,3,3,4,4,4,4,6,9,10,3,4,8,5,5,5,6,5,6,5,5,6,18,18,2,4,4,4,6,9,9,6,6,9,6,3,2,10,10,4,1,1,1,6,5,7,7,3,4,4,5,9,9,12,5,3,2,7,2,7,19,3,5,5,4,6,3,7,7,13,3,17,17,8,8,12,5,6,9,1,1,2,2,11,4,4,3,6,3,3,6,3,8,5,7,11,6,4,2,1,1,9,4,3,9,1,1,5,18,20,9,19,19,9,6,7,3,3,3,2,2,2,2,4,4,2,3,3,9,8,10,9,3,5,3,12,4,4,6,12,6,6,7,6,19,6,2,2,5,5,7,3,8,10,18,2,20,2,6,6,18,15,18,1,2,2,4,4,20,13,7,7,5,5,3,18,18,9,15,6,12,3,13,11,6,6,24,10,18,10,1,6,2,2,18,9,6,9,5,5,5,5,9,9,10,10,18,18,9,7,19,16,8,6,1,1,4,4,3,6,4,6,9,9,3,18,3,3,18,18,22,7,6,6,8,16,6,4,3,3,18,10,9,9,1,1,2,6,8,9,16,18,2,3,2,2,6,18,24,9,4,13,16,14,9,16,13,13,12,10,18,18,9,11,8,8,18,5,6,9,2,3,2,2,5,9,17,12,8,5,2,2,2,13,19,6,4,3,3,3,9,2,4,4,5,5,4,4,16,16,7,3,9,17,8,8,5,11,12,6,3,3,9,11,9,18,19,18,9,9,9,9,1,24,3};

  static  int rectangles_array7[2913] = {
  3,7,3,2,19,8,3,5,3,2,7,4,3,5,5,3,6,10,10,9,11,13,9,2,6,3,3,7,10,6,3,2,15,15,15,6,4,10,10,13,13,19,9,11,9,1,9,9,7,1,11,3,3,6,5,2,3,13,13,23,4,7,3,2,6,2,1,6,20,1,7,4,3,2,2,5,7,5,3,9,9,9,9,4,3,6,4,6,3,9,4,9,9,6,1,5,5,2,2,1,1,1,15,10,10,3,9,9,6,3,3,9,9,2,2,10,3,1,6,24,5,6,6,1,4,3,6,18,14,1,13,2,10,6,6,4,4,2,6,3,5,3,10,8,7,22,22,16,2,4,2,7,5,11,11,9,7,8,14,3,8,6,4,6,2,6,6,2,9,2,1,1,8,6,6,2,2,6,17,24,24,22,22,18,2,2,1,9,1,4,3,6,8,16,3,4,9,1,1,9,6,9,6,1,1,3,2,2,11,6,5,6,5,1,3,3,9,7,13,13,9,9,2,3,2,4,9,2,2,10,7,9,1,1,2,3,18,18,10,4,9,3,4,3,19,3,4,4,8,2,2,3,5,13,14,5,2,14,4,5,4,6,3,3,8,2,9,6,9,9,2,9,3,7,4,3,20,3,21,23,2,2,2,2,4,19,6,10,6,19,10,6,1,2,3,2,3,3,4,9,9,9,15,15,2,7,5,4,8,1,1,9,18,18,9,14,3,8,6,8,5,1,10,4,3,5,4,5,7,8,8,1,2,9,14,12,9,9,3,2,3,3,1,2,9,9,2,2,2,15,6,7,2,4,19,19,3,1,3,2,3,11,7,10,9,9,6,6,2,2,1,1,2,6,6,6,3,6,6,4,9,3,2,23,2,6,2,2,4,3,3,4,6,1,2,3,3,3,6,4,9,10,9,21,7,9,4,4,4,9,17,3,3,19,7,6,6,6,4,2,6,14,14,2,5,11,7,3,2,3,3,2,1,3,3,9,9,7,5,9,9,1,1,6,3,2,1,24,4,3,4,3,3,8,2,1,4,3,2,5,5,2,1,3,3,1,5,24,11,6,10,24,24,7,12,14,2,9,7,15,9,7,18,6,10,9,7,3,6,6,9,3,13,3,4,5,4,3,5,5,2,3,2,12,5,5,12,2,2,8,2,2,2,2,9,1,2,3,3,3,5,8,5,5,10,3,18,9,7,5,18,9,2,1,9,10,12,6,21,4,4,1,2,9,9,22,7,5,7,7,3,9,16,16,4,3,1,3,2,5,6,1,11,11,9,9,9,2,2,2,17,17,2,6,6,6,5,5,2,2,14,9,15,15,9,21,4,6,9,3,1,5,2,20,4,4,3,3,2,6,3,5,7,6,1,6,6,6,3,7,2,6,7,4,2,9,9,5,1,2,11,3,9,4,3,5,8,2,3,4,8,18,11,5,1,1,2,5,1,3,22,2,2,12,9,9,9,6,9,19,2,19,3,1,4,5,6,8,4,3,19,20,20,6,6,7,7,7,9,10,10,2,2,6,6,3,3,2,3,5,5,13,5,3,2,5,6,6,1,3,1,9,1,1,9,23,19,9,2,6,3,5,5,3,4,3,3,18,18,2,2,3,8,5,4,2,5,4,2,2,17,9,6,9,6,1,3,11,10,17,2,3,4,4,5,1,7,3,1,6,14,9,18,18,10,11,1,1,4,4,6,7,5,1,4,4,9,9,6,9,11,6,1,1,2,5,4,3,2,2,4,18,10,5,6,7,2,2,5,1,2,2,6,6,3,1,2,1,2,2,1,10,9,4,4,11,3,2,6,4,4,3,4,11,4,9,9,7,8,7,10,10,2,4,9,5,4,4,5,5,8,3,4,2,2,6,6,3,2,1,3,2,6,6,8,5,6,9,4,6,2,15,1,3,1,6,1,5,9,9,9,2,2,2,1,6,6,1,10,3,3,7,3,4,6,5,3,9,6,3,6,3,3,3,7,9,7,8,10,5,1,12,5,2,12,6,6,13,13,6,1,6,7,1,2,4,9,2,6,23,23,1,2,1,2,15,3,4,4,9,6,5,3,3,2,1,6,1,2,1,8,2,11,5,6,3,10,9,10,10,10,3,1,13,13,7,3,2,2,1,8,2,4,1,6,2,7,3,9,5,5,3,3,7,6,6,9,8,2,7,1,8,5,2,7,8,8,6,6,8,18,7,7,3,6,3,9,3,8,4,8,8,5,4,1,9,4,1,11,9,4,3,1,2,9,9,19,19,8,8,1,4,2,6,7,6,5,9,9,4,2,1,6,6,1,1,7,7,7,2,3,2,2,1,3,4,5,9,10,10,3,3,19,9,19,4,9,19,6,5,18,12,1,1,2,9,2,2,6,8,1,6,5,5,2,5,4,7,3,3,2,1,2,1,2,1,2,2,3,2,4,3,6,7,4,3,2,3,2,3,5,5,17,10,4,9,9,8,2,2,6,5,6,8,4,4,2,2,3,2,2,9,2,7,3,1,2,5,1,6,3,9,3,7,1,1,13,4,3,3,10,10,3,3,21,13,21,20,2,9,3,3,9,10,9,9,2,7,3,6,10,4,2,3,7,2,3,10,2,2,2,2,1,1,1,1,11,6,11,11,3,2,12,1,9,1,3,1,9,9,18,18,3,2,1,3,1,8,2,4,3,3,3,3,5,8,15,8,4,6,6,6,1,11,15,13,9,9,4,4,4,3,1,10,2,4,7,3,3,3,3,2,3,9,8,8,9,16,4,4,2,11,2,2,2,2,5,16,2,5,2,2,2,5,3,2,16,13,3,3,3,3,11,5,5,7,3,6,8,3,6,9,8,1,3,2,9,9,9,9,6,1,2,6,6,11,11,11,11,9,1,1,1,3,3,3,3,2,10,9,9,9,9,2,1,2,2,1,2,5,6,5,12,5,9,9,4,5,5,7,19,3,3,5,4,3,9,6,4,1,1,3,2,4,3,4,7,3,4,3,9,23,2,1,7,6,6,7,9,6,6,5,5,3,5,4,2,19,19,20,20,12,12,7,4,4,5,1,6,1,1,3,2,2,7,3,9,6,5,6,3,3,3,2,3,1,6,24,4,6,4,7,7,5,2,9,7,5,3,12,14,4,4,3,3,3,3,2,2,4,4,12,11,4,7,1,9,7,6,11,11,18,5,1,20,4,2,5,7,4,3,4,3,2,9,8,17,6,17,17,1,9,9,9,4,9,9,4,3,9,3,2,2,2,1,2,3,3,3,2,3,3,23,3,4,23,1,1,2,2,3,3,2,5,6,9,9,9,1,3,13,4,13,18,5,8,9,9,7,7,8,10,3,4,5,5,16,16,5,1,2,4,6,6,4,4,5,4,3,9,7,7,6,8,7,7,9,4,4,4,10,6,10,10,7,7,4,3,5,11,8,3,3,6,3,5,1,1,1,3,3,3,9,2,6,6,4,16,9,9,5,2,4,7,3,3,5,1,2,2,2,3,6,5,2,4,5,5,6,4,2,2,2,2,9,9,5,13,6,3,2,5,3,9,7,3,3,2,6,9,7,3,9,1,2,3,3,5,1,6,9,11,11,5,18,6,1,2,5,9,9,5,1,2,1,2,3,4,1,2,2,3,3,2,2,3,3,5,4,6,5,3,4,6,2,5,4,4,4,3,4,8,3,1,9,9,13,1,6,24,24,10,6,3,11,4,18,16,16,3,1,3,3,2,4,7,7,6,4,3,3,7,5,6,18,9,3,5,6,6,5,1,13,1,4,5,2,1,4,3,3,4,6,5,7,10,10,3,3,2,8,11,6,9,9,2,2,2,3,9,9,1,13,4,6,1,4,9,13,1,9,9,4,4,4,2,5,6,3,2,1,2,2,3,4,2,1,3,5,3,3,5,5,4,6,1,5,12,12,3,11,13,3,6,3,6,1,10,9,9,9,2,9,9,16,16,3,3,6,6,8,6,2,20,3,9,3,2,6,9,2,3,4,8,3,5,4,4,3,5,21,21,1,2,1,1,2,2,1,1,23,3,1,23,5,4,7,3,6,5,2,5,4,24,2,5,9,1,9,9,9,11,2,4,3,5,12,12,4,10,3,9,5,11,2,4,2,2,4,9,3,3,3,2,1,3,3,1,2,2,2,12,9,6,2,3,3,4,3,7,6,6,6,14,18,12,14,14,20,20,17,17,2,2,13,13,9,7,2,2,3,1,5,3,6,9,2,4,5,3,5,18,14,9,3,2,4,4,1,5,6,12,1,6,3,9,5,6,6,11,6,6,4,4,3,13,9,9,3,1,3,3,21,4,2,1,1,2,4,6,7,2,3,2,3,3,2,4,7,7,5,5,10,2,6,3,3,5,2,4,9,6,2,3,1,1,9,9,20,20,7,9,2,2,2,6,3,2,3,7,9,9,9,9,9,6,3,11,6,1,4,2,2,6,4,8,1,3,8,4,1,7,5,3,6,9,4,4,3,2,2,2,3,3,8,3,2,2,1,5,2,3,3,4,2,14,8,4,9,10,13,13,6,3,7,2,6,4,3,5,5,13,19,6,2,2,5,7,3,12,7,4,6,3,5,2,2,2,2,4,7,3,9,12,9,9,11,6,3,2,11,11,2,7,4,5,6,6,16,16,16,16,1,2,4,1,1,2,3,3,3,7,1,7,5,5,9,5,9,9,10,3,10,4,10,19,10,9,2,2,3,4,3,3,2,2,8,9,9,9,10,10,3,9,6,4,6,7,2,5,1,10,6,9,8,6,7,2,3,3,10,1,4,11,4,4,3,2,2,2,1,1,3,5,5,9,1,1,3,3,3,5,8,5,13,13,9,11,11,2,1,9,7,9,6,9,10,3,3,3,9,15,1,9,1,2,5,14,9,1,6,1,4,5,6,5,5,3,3,20,3,13,5,4,7,2,1,4,9,1,13,5,3,1,1,11,5,1,1,5,21,3,3,4,4,3,3,9,1,9,2,3,5,2,9,5,5,5,7,5,7,5,6,6,2,10,2,2,1,13,1,1,2,2,2,16,16,10,10,24,10,9,9,5,9,8,8,9,6,18,18,2,3,15,14,5,9,8,8,4,2,5,5,3,5,2,2,4,2,2,23,2,4,9,6,4,2,2,1,10,10,9,12,4,7,8,9,2,2,3,6,9,7,2,10,21,10,4,9,6,6,6,6,9,9,4,4,2,2,2,4,19,8,4,3,2,10,6,22,22,1,5,9,1,5,1,6,7,5,9,5,5,2,1,6,8,2,3,3,3,3,4,8,4,3,3,9,9,6,6,2,2,2,2,1,1,11,11,24,4,9,7,3,3,10,3,7,6,24,24,7,7,19,6,6,4,5,5,10,10,4,4,3,1,10,9,19,3,10,9,5,6,10,10,6,6,4,3,2,5,2,5,6,2,2,9,9,2,1,2,19,19,1,2,9,4,2,10,6,6,5,5,2,1,9,9,9,9,5,10,3,1,6,2,3,2,2,2,11,11,3,9,6,3,4,4,6,6,4,7,4,9,6,10,6,7,6,18,7,1,4,7,6,6,11,20,2,2,2,2,12,4,2,3,1,8,12,1,7,2,7,19,7,3,7,3,5,19,6,7,9,5,5,5,7,5,9,9,7,7,4,6,6,6,8,1,2,2,5,6,3,10,3,5,14,2,3,7,6,6,3,2,2,6,3,6,6,1,3,2,2,2,1,1,2,2,9,12,4,3,12,3,9,3,3,10,10,9,4,3,9,9,3,10,10,2,2,3,2,1,7,6,6,3,13,3,15,7,3,6,9,24,24,4,2,2,4,2,7,1,1,9,6,6,9,10,9,7,5,8,9,5,5,5,5,5,2,3,7,8,4,4,4,4,9,4,4,6,6,7,1,1,10,24,15,24,9,2,3,3,3,2,10,23,9,2,3,5,19,18,18,3,9,7,7,6,5,5,8,2,2,3,4,6,9,3,22,3,1,24,6,7,5,5,6,7,7,2,6,3,3,3,3,5,8,8,2,18,19,16,16,2,5,5,6,5,7,6,3,6,10,6,4,2,4,5,9,22,22,2,5,6,13,24,24,4,1,1,2,5,1,2,8,4,16,16,16,14,14,22,22,20,20,9,16,6,3,4,2,2,6,4,6,3,6,5,4,2,3,3,9,3,1,3,9,9,5,5,3,7,5,3,1,10,1,11,4,3,1,2,1,18,10,10,9,9,1,2,7,7,6,6,6,1,1,5,2,3,3,6,2,13,3,3,1,2,1,2,19,8,9,9,1,2,3,2,4,4,6,6,2,2,2,2,1,1,6,3,5,2,12,15,19,19,5,5,6,3,5,5,5,5,6,1,6,6,1,1,1,10,17,17,11,3,4,7,7,7,1,2,2,2,18,18,10,3,3,2,2,1,9,6,9,9,3,3,1,2,5,3,3,3,2,2,3,3,3,3,1,1,2,2,3,5,1,5,3,3,9,6,9,9,6,12,11,2,3,9,9,9,12,2,1,4,5,7,7,7,2,10,6,6,4,4,5,5,4,4,3,7,2,3,5,5,4,3,4,3,6,6,2,5,2,1,1,1,2,2,2,2,20,4,11};

  static  int rectangles_array8[2913] = {
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,12,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,0,8,0,0,0,0,0,11,0,0,0,0,0,0,0,11,0,0,0,0,11,12,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,11,6,0,0,0,0,0,0,0,11,0,12,9,10,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,0,0,0,0,0,0,0,12,0,0,0,11,0,0,0,0,0,0,0,0,0,0,0,12,2,0,0,0,0,0,0,0,0,0,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,2,11,0,0,0,0,0,0,0,9,0,12,0,0,0,0,0,9,3,0,0,0,0,0,7,0,0,0,3,11,0,0,0,0,0,12,1,0,0,0,0,0,17,11,0,0,0,0,0,9,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11,12,12,0,0,0,0,0,0,0,8,0,0,0,0,0,0,0,0,18,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,12,4,10,10,3,0,0,15,6,0,0,0,0,0,11,17,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,0,0,8,11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,12,0,0,0,0,0,0,1,0,0,12,0,0,0,0,14,5,0,0,5,11,0,0,0,0,0,0,0,0,16,0,0,0,0,5,0,0,12,0,0,0,0,0,0,0,0,12,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,7,0,0,0,11,0,0,0,11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,16,0,16,4,0,0,0,0,5,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11,10,0,0,7,0,0,12,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,12,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,13,0,0,0,7,0,0,0,0,0,14,7,0,0,0,0,0,0,0,0,12,0,0,6,14,6,0,0,5,0,0,10,0,0,0,0,20,0,0,2,0,0,0,0,7,12,0,0,0,11,7,10,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,17,0,0,0,10,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,12,0,0,0,0,16,4,12,0,0,6,0,0,0,0,0,0,0,0,3,0,0,0,0,12,0,0,13,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,13,0,0,0,0,0,0,11,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,6,0,11,10,0,0,8,12,0,4,0,0,0,0,0,0,0,10,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,11,0,0,0,0,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,12,1,0,9,10,4,0,16,0,8,0,10,0,5,0,0,7,0,0,10,10,0,9,0,0,0,0,0,0,0,0,9,16,0,16,4,0,0,0,0,0,0,0,0,6,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11,0,0,8,4,0,0,17,4,7,0,0,12,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,4,10,0,0,0,0,0,0,0,0,0,11,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,12,0,0,0,0,0,9,8,0,6,0,0,0,6,0,0,0,0,0,0,12,7,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,12,12,12,0,11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,12,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,12,0,11,5,12,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,9,11,2,0,0,0,0,0,0,0,0,0,0,0,0,0,10,0,0,0,0,0,0,6,10,0,0,0,6,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,10,0,9,6,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,0,9,0,9,0,10,0,9,11,11,0,6,10,16,11,8,10,3,5,0,0,0,12,0,0,12,0,0,0,0,0,0,0,0,0,15,4,0,0,14,7,0,0,0,0,11,12,0,0,0,0,0,0,0,0,0,0,0,12,0,0,0,0,4,10,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,15,5,0,0,0,0,10,0,0,0,0,0,0,0,0,0,0,0,9,10,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,10,14,0,0,12,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,10,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,8,0,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,17,4,14,0,3,0,0,0,0,0,0,0,0,0,6,12,14,5,0,11,7,11,10,11,0,7,0,0,10,10,0,0,15,0,15,5,11,9,0,0,0,0,10,12,0,7,0,8,0,0,0,0,12,6,0,0,0,0,0,0,0,0,9,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,16,0,0,0,0,0,0,0,10,0,0,0,0,0,0,0,0,9,12,0,0,0,0,0,0,0,0,0,12,13,0,0,0,0,0,8,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,9,0,16,0,0,4,0,11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,10,0,0,2,7,17,0,0,0,15,4,0,5,0,0,0,0,0,0,0,10,11,0,0,0,0,0,0,0,6,0,0,11,0,0,12,6,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,10,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,12,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11,0,0,0,0,0,0,0,0,0,0,0,12,6,0,9,0,5,12,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,14,0,0,7,0,5,0,0,0,0,0,0,0,0,10,0,0,0,0,11,0,0,0,0,5,0,0,12,0,0,1,0,0,0,10,8,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,12,6,0,14,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,0,0,0,0,0,0,0,0,0,0,0,8,0,0,0,0,0,14,0,0,7,12,0,0,0,0,0,0,0,9,12,0,0,0,0,0,0,10,7,0,0,0,0,0,0,0,0,0,0,0,9,3,11,0,11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11,0,0,0,0,0,6,12,0,12,15,7,0,0,0,0,4,0,17,0,0,0,0,4,0,0,0,7,0,0,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,7,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,11,5,12,0,0,0,12,0,0,0,0,0,12,0,5,0,11,7,12,0,0,0,12,0,0,0,0,0,0,0,0,0,0,13,0,0,12,13,9,4,0,0,0,15,5,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,9,0,0,11,0,11,6,11,0,11,0,0,0,0,0,0,0,6,0,0,0,0,12,11,11,5,0,0,9,6,0,0,0,0,0,13,12,7,12,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11,0,0,0,10,0,0,0,0,0,0,19,0,0,0,0,0,0,0,0,0,0,12,14,6,10,0,0,11,0,0,0,10,0,0,0,0,0,0,16,0,0,0,0,4,0,0,3,0,0,6,0,0,0,0,19,0,19,0,0,0,0,3,9,11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,0,6,0,0,0,0,0,0,13,0,0,0,0,0,0,7,8,0,0,0,0,0,0,0,0,0,0,12,0,0,0,0,0,0,0,0,6,0,11,0,0,11,1,0,0,0,0,0,0,0,10,0,12,9,16,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,13,0,13,12,4,0,0,0,0,0,0,9,0,0,0,0,0,0,0,8,14,7,0,9,0,0,0,0,19,3,0,0,11,12,0,0,20,0,7,0,0,0,0,0,0,0,0,8,0,0,20,2,0,0,0,0,7,0,0,0,7,0,0,0,7,9,0,0,7,0,0,0,0,0,0,0,0,12,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,12,0,0,15,7,0,0,0,11,0,0,12,9,5,0,0,6,0,0,0,12,0,0,1,0,0,0,0,0,0,0,4,11,0,0,6,0,0,10,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,12,0,0,0,0,0,12,0,0,0,0,13,3,10,12,0,0,6,0,0,0,0,7,0,0,0,0,0,0,0,0,12,4,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,18,3,13,0,12,9,0,6,14,6,0,0,0,0,0,0,0,0,5,0,6,0,0,0,0,0,0,0,0,0,0,0,0,9,0,0,0,0,0,0,0,0,0,0,0,12,15,5,11,9,0,0,2,0,10,11,0,12,0,0,13,0,8,11,0,0,0,0,0,0,0,0,0,12,0,0,4,8,0,0,0,10,0,0,0,0,0,0,0,0,0,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,5,0,0,7,10,0,6,0,0,0,0,0,0,0,9,0,0,0,0,0,0,0,0,0,0,0,0,0,12,7,0,0,10,8,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,12,5,0,0,0,14,0,0,0,0,0,0,9,0,0,0,0,10,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11,0,10,0,0,0,0,0,0,0,0,0,10,19,3,0,0,12,0,12,7,14,5,0,0,0,0,0,0,3,0,0,0,0,0,0,0,13,7,0,11,10,12,6,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,6,0,0,0,0,0,0,0,0,6,0,0,0,0,0,10,0,0,0,0,0,8,0,0,0,0,0,0,0,0,0,0,0,0,12,0,0,0,0,0,11,10,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,5,15,6,3,7,16,4,13,6,0,0,0,0,0,0,0,0,0,0,11,11,0,0,18,3,0,12,0,0,0,0,0,0,0,0,0,0,9};

  static  int rectangles_array9[2913] = {
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,12,0,0,0,0,0,0,0,0,0,0,0,0,12,0,0,0,0,0,0,0,20,0,0,0,0,0,15,0,0,0,0,0,0,0,12,0,0,0,0,11,12,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,19,0,0,0,11,11,0,0,0,0,0,0,0,15,0,11,11,11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11,0,0,0,0,0,0,0,8,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,15,10,0,0,0,0,0,0,0,0,0,13,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11,0,0,0,14,14,0,0,0,0,0,0,0,8,0,11,0,0,0,0,0,21,20,0,0,0,0,0,16,0,0,0,18,9,0,0,0,0,0,5,5,0,0,0,0,0,16,17,0,0,0,0,0,19,0,0,0,0,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11,11,10,0,0,0,0,0,0,0,19,0,0,0,0,0,0,0,0,15,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,9,11,14,14,0,0,18,18,0,0,0,0,0,6,7,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,21,0,0,13,13,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,0,0,0,0,0,0,5,0,8,15,0,0,0,0,5,5,3,0,18,18,0,0,0,0,0,0,0,0,14,0,0,0,0,14,0,0,9,0,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,8,0,0,0,14,0,0,0,17,0,0,0,0,0,0,0,0,0,0,0,0,15,0,0,0,17,0,17,17,0,0,0,0,9,0,0,0,0,18,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,13,15,0,0,19,14,0,20,20,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,13,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,0,0,0,9,0,0,0,0,0,9,9,0,0,0,0,0,0,0,0,8,0,0,8,19,19,0,0,9,0,0,11,0,0,0,0,11,0,0,11,0,0,0,0,6,6,0,0,0,9,9,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,13,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,16,5,0,0,0,15,15,11,0,0,11,0,0,0,0,0,0,0,0,14,0,0,0,0,7,0,0,15,0,0,0,0,0,6,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,12,0,0,0,0,0,0,10,0,0,0,0,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,0,0,0,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,11,0,0,0,15,0,15,15,0,0,7,9,0,6,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,9,0,0,0,0,0,0,0,13,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,19,0,10,10,9,0,17,0,16,0,12,0,13,0,0,16,0,0,12,12,0,11,0,0,0,0,0,0,0,0,21,16,0,16,16,0,0,0,0,0,0,0,0,15,11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,0,0,7,6,0,0,17,17,13,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,0,3,3,0,0,0,0,0,0,0,0,0,16,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,14,0,0,0,0,0,14,14,0,14,0,0,0,16,0,0,0,0,0,0,20,20,2,0,7,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,12,11,12,0,14,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11,0,9,9,19,0,0,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,21,21,22,11,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,5,4,0,0,0,5,0,0,0,0,18,0,0,0,0,0,0,0,0,0,0,0,0,13,0,0,0,0,0,12,0,11,11,11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,13,0,13,0,13,0,15,0,13,13,17,0,15,12,19,13,21,15,12,20,0,0,0,9,0,0,14,0,0,0,0,0,0,0,0,0,6,6,0,0,14,14,0,0,0,0,19,4,0,0,0,0,0,0,0,0,0,0,0,18,0,0,0,0,16,14,16,0,0,0,0,0,0,0,0,0,0,0,0,0,0,19,17,16,0,0,0,0,9,0,0,0,0,0,0,0,0,0,0,0,7,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,12,7,0,0,11,0,0,0,0,0,0,0,0,0,0,0,0,15,0,0,13,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,18,0,0,21,0,0,0,0,0,0,0,21,0,0,0,0,0,0,0,0,7,7,8,0,20,0,0,0,0,0,0,0,0,0,6,16,20,20,0,20,9,15,16,16,0,16,0,0,10,9,0,0,14,0,14,14,15,15,0,0,0,0,10,5,0,8,0,8,0,0,0,0,11,11,0,0,0,0,0,0,0,0,16,0,0,0,0,0,0,0,0,0,0,0,11,0,0,0,0,0,7,0,0,0,0,0,0,0,10,0,0,0,0,0,0,0,0,21,11,0,0,0,0,4,0,0,0,0,9,10,0,0,0,0,0,8,0,0,0,0,0,0,0,0,0,0,0,0,11,0,0,0,0,0,0,0,0,21,0,18,0,0,18,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,10,0,0,12,15,6,0,0,0,18,6,0,18,0,0,0,0,0,0,0,5,21,0,0,0,0,0,0,0,7,0,0,12,0,0,9,9,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,10,0,0,0,0,0,0,0,0,0,0,12,0,0,0,0,0,0,21,0,0,0,0,0,12,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,16,0,0,0,0,0,0,0,0,0,0,0,8,9,0,19,0,9,11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,16,0,0,9,0,7,0,0,0,0,0,0,0,0,15,0,0,0,0,7,0,0,0,0,9,0,0,11,0,0,21,0,0,0,21,21,0,0,0,0,0,0,0,0,7,0,0,18,0,0,0,10,9,0,16,16,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,0,0,9,0,0,9,11,0,0,0,0,0,0,0,9,8,0,0,0,0,0,0,16,16,0,0,0,0,0,0,0,0,0,0,0,10,13,13,0,16,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,14,0,0,0,0,0,9,21,0,12,15,15,0,0,0,0,4,0,7,0,0,0,0,7,0,0,0,8,0,0,0,0,0,0,0,0,0,0,12,0,0,0,0,0,0,21,0,0,0,0,0,0,12,0,0,0,0,0,0,0,0,0,0,9,11,2,0,0,0,8,0,0,0,0,0,18,0,17,0,12,12,12,0,0,0,15,0,0,0,0,0,0,0,0,0,0,12,0,0,14,12,12,9,0,0,0,6,6,0,0,0,0,0,0,0,0,0,0,0,0,0,17,0,0,0,0,0,11,0,0,11,0,11,20,11,0,11,0,0,0,0,0,0,0,2,0,0,0,0,15,11,11,12,0,0,4,11,0,0,0,0,0,8,15,16,7,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,13,0,0,0,11,0,0,0,0,0,0,13,0,0,0,0,0,0,0,0,0,0,18,19,19,21,0,0,9,0,0,0,15,0,0,0,0,0,0,5,0,0,0,0,5,0,0,5,0,0,12,0,0,0,0,13,0,13,0,0,0,0,14,13,13,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,14,0,0,0,0,0,0,0,10,0,0,0,0,0,0,15,0,0,0,0,0,0,15,21,0,0,0,0,0,0,0,0,0,0,17,9,0,0,0,0,0,0,0,13,0,10,0,0,14,15,0,0,0,0,0,0,0,20,0,16,16,18,18,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,14,0,14,16,15,0,0,0,0,0,0,21,0,0,0,0,0,0,0,15,15,15,0,22,0,0,0,0,13,13,0,0,15,16,0,0,14,0,7,0,0,0,0,0,0,0,0,20,0,0,14,14,0,0,0,0,12,0,0,0,11,0,0,0,11,11,0,0,10,0,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,14,0,0,12,12,0,0,0,11,0,0,12,12,13,0,0,14,0,0,0,17,0,0,11,0,0,0,0,0,0,0,15,15,0,0,12,0,0,12,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,12,0,0,0,0,0,11,0,0,0,0,19,7,6,6,0,0,11,0,0,0,0,10,0,0,0,0,0,0,0,0,3,9,0,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11,11,12,0,12,12,0,12,14,14,0,0,0,0,0,0,0,0,9,0,14,0,0,0,0,0,0,0,0,0,0,0,0,10,0,0,0,0,0,0,0,0,0,0,0,15,19,19,5,5,0,0,11,0,13,13,0,16,0,0,8,0,13,13,0,0,0,0,0,0,0,0,0,12,0,0,9,11,0,0,0,9,0,0,0,0,0,0,0,0,0,19,0,0,0,0,0,0,0,0,0,0,0,0,0,0,13,11,0,0,15,15,0,8,0,0,0,0,14,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,13,12,0,0,11,16,0,0,0,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,9,0,0,0,5,0,0,0,0,0,0,21,0,0,0,0,5,0,0,0,0,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,0,15,0,0,0,0,0,0,0,0,0,14,15,15,0,0,21,0,20,20,6,6,0,0,0,0,0,0,11,0,0,0,0,0,0,0,19,19,0,14,10,9,13,13,0,0,0,0,0,0,0,0,0,0,0,0,0,0,17,17,0,0,0,0,0,0,0,0,12,0,0,0,0,0,15,0,0,0,0,0,14,0,0,0,0,0,0,0,7,0,0,0,0,22,0,0,0,0,0,9,15,0,0,0,0,0,0,0,12,0,0,0,0,0,0,0,0,7,8,8,22,10,14,14,17,17,0,0,0,0,0,0,0,0,0,0,18,21,0,0,18,18,0,11,0,0,0,0,0,0,0,0,0,0,12};

  static  int rectangles_array10[2913] = {
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,0,6,0,0,0,0,0,8,0,0,0,0,0,0,0,10,0,0,0,0,4,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,10,0,0,0,6,6,0,0,0,0,0,0,0,9,0,7,5,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,5,0,0,0,10,0,0,0,0,0,0,0,0,0,0,0,12,11,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,11,11,0,0,0,0,0,0,0,8,0,12,0,0,0,0,0,7,9,0,0,0,0,0,5,0,0,0,9,7,0,0,0,0,0,12,11,0,0,0,0,0,3,10,0,0,0,0,0,6,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,10,3,11,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11,8,9,4,3,0,0,3,3,0,0,0,0,0,5,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,5,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,11,0,12,9,0,0,0,0,5,5,12,0,8,8,0,0,0,0,0,0,0,0,3,0,0,0,0,3,0,0,5,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,5,0,0,0,6,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,12,0,0,0,4,0,4,4,0,0,0,0,8,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,2,0,0,4,12,0,5,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,7,0,0,0,0,0,3,3,0,0,0,0,0,0,0,0,6,0,0,6,4,4,0,0,8,0,0,7,0,0,0,0,2,0,0,2,0,0,0,0,6,12,0,0,0,9,7,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,12,0,0,0,4,4,6,0,0,6,0,0,0,0,0,0,0,0,10,0,0,0,0,5,0,0,4,0,0,0,0,0,12,0,12,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,12,0,0,0,11,0,0,0,8,0,3,8,0,0,4,6,0,4,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,8,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,11,0,5,5,8,0,4,0,4,0,4,0,7,0,0,6,0,0,4,4,0,8,0,0,0,0,0,0,0,0,6,4,0,4,4,0,0,0,0,0,0,0,0,6,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,4,3,0,0,3,3,7,0,0,11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,0,10,10,0,0,0,0,0,0,0,0,0,4,11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,0,0,7,7,0,3,0,0,0,3,0,0,0,0,0,0,5,5,12,0,12,0,11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,6,6,0,10,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,12,0,6,7,7,0,0,10,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,7,10,10,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,6,6,0,0,0,6,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,10,0,3,9,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,4,0,4,0,2,0,4,4,3,0,6,9,4,11,6,10,10,5,0,0,0,11,0,0,5,0,0,0,0,0,0,0,0,0,4,4,0,0,3,3,0,0,0,0,6,12,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,9,3,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,4,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,5,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,3,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11,0,0,6,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,3,3,3,0,9,0,0,0,0,0,0,0,0,0,6,4,5,5,0,5,6,2,3,3,0,3,0,0,4,8,0,0,4,0,4,4,4,4,0,0,0,0,4,12,0,6,0,4,0,0,0,0,6,6,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,8,0,0,0,0,0,3,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,6,10,0,0,0,0,12,0,0,0,0,7,4,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,6,0,4,0,0,4,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,11,4,3,0,0,0,4,3,0,4,0,0,0,0,0,0,0,5,6,0,0,0,0,0,0,0,9,0,0,11,0,0,6,6,11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,0,0,0,0,12,0,0,0,0,0,0,6,0,0,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,0,0,0,8,7,0,6,0,7,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,6,0,4,0,0,0,0,0,0,0,0,2,0,0,0,0,4,0,0,0,0,8,0,0,12,0,0,11,0,0,0,6,6,0,0,0,0,0,0,0,0,12,0,0,3,0,0,0,5,7,0,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,3,0,0,3,6,0,0,0,0,0,0,0,5,8,0,0,0,0,0,0,7,7,0,0,0,0,0,0,0,0,0,0,0,9,10,10,0,10,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,6,10,0,9,2,2,0,0,0,0,8,0,3,0,0,0,0,3,0,0,0,6,0,0,0,0,0,0,0,0,0,0,9,0,0,0,0,0,0,6,0,0,0,0,0,0,10,0,0,0,0,0,0,0,0,0,0,8,8,12,0,0,0,4,0,0,0,0,0,12,0,4,0,5,7,5,0,0,0,11,0,0,0,0,0,0,0,0,0,0,2,0,0,9,2,2,10,0,0,0,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,5,0,0,2,0,2,5,2,0,2,0,0,0,0,0,0,0,9,0,0,0,0,2,2,2,9,0,0,9,7,0,0,0,0,0,3,2,5,4,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,6,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,3,4,4,6,0,0,7,0,0,0,3,0,0,0,0,0,0,4,0,0,0,0,4,0,0,9,0,0,6,0,0,0,0,2,0,2,0,0,0,0,2,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,3,0,0,0,0,0,0,4,0,0,0,0,0,0,4,8,0,0,0,0,0,0,0,0,0,0,3,12,0,0,0,0,0,0,0,6,0,6,0,0,11,11,0,0,0,0,0,0,0,5,0,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,4,5,9,0,0,0,0,0,0,6,0,0,0,0,0,0,0,2,3,3,0,9,0,0,0,0,2,2,0,0,2,5,0,0,2,0,5,0,0,0,0,0,0,0,0,5,0,0,2,2,0,0,0,0,7,0,0,0,8,0,0,0,8,8,0,0,5,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,10,0,0,0,0,0,0,0,0,0,0,0,0,10,0,0,2,2,0,0,0,6,0,0,3,3,7,0,0,2,0,0,0,3,0,0,11,0,0,0,0,0,0,0,9,9,0,0,9,0,0,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,4,0,0,0,0,5,3,3,5,0,0,9,0,0,0,0,4,0,0,0,0,0,0,0,0,6,9,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,2,0,6,2,0,6,4,4,0,0,0,0,0,0,0,0,7,0,6,0,0,0,0,0,0,0,0,0,0,0,0,9,0,0,0,0,0,0,0,0,0,0,0,3,4,4,4,4,0,0,10,0,4,8,0,5,0,0,5,0,5,5,0,0,0,0,0,0,0,0,0,9,0,0,9,6,0,0,0,10,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,4,0,0,7,7,0,3,0,0,0,0,12,0,0,9,0,0,0,0,0,0,0,0,0,0,0,0,0,8,5,0,0,6,4,0,0,0,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,8,0,0,0,5,0,0,0,0,0,0,6,0,0,0,0,6,0,0,0,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,3,0,0,0,0,0,0,0,0,0,6,2,2,0,0,6,0,5,5,5,5,0,0,0,0,0,0,9,0,0,0,0,0,0,0,4,4,0,6,4,6,9,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,0,0,0,0,0,0,0,0,8,0,0,0,0,0,2,0,0,0,0,0,4,0,0,0,0,0,0,0,12,0,0,0,0,11,0,0,0,0,0,9,2,0,0,0,0,0,0,0,8,0,0,0,0,0,0,0,0,3,3,3,9,2,4,4,5,5,0,0,0,0,0,0,0,0,0,0,5,11,0,0,3,3,0,11,0,0,0,0,0,0,0,0,0,0,3};

  static  int rectangles_array11[2913] = {
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,0,3,0,0,0,0,0,3,0,0,0,0,0,0,0,7,0,0,0,0,5,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,3,3,0,0,0,0,0,0,0,6,0,5,6,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,0,8,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,2,6,0,0,0,0,0,0,0,0,0,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,2,2,0,0,0,0,0,0,0,3,0,7,0,0,0,0,0,3,2,0,0,0,0,0,7,0,0,0,2,3,0,0,0,0,0,3,4,0,0,0,0,0,8,2,0,0,0,0,0,5,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,6,8,0,0,0,0,0,0,0,5,0,0,0,0,0,0,0,0,9,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,3,11,7,10,0,0,6,6,0,0,0,0,0,6,6,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,6,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,3,0,8,2,0,0,0,0,5,5,2,0,3,3,0,0,0,0,0,0,0,0,7,0,0,0,0,7,0,0,7,0,0,0,0,0,0,0,0,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,8,0,0,0,3,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,7,0,7,7,0,0,0,0,4,0,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,9,0,0,5,2,0,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,3,0,0,0,0,0,7,7,0,0,0,0,0,0,0,0,3,0,0,3,5,5,0,0,3,0,0,6,0,0,0,0,9,0,0,9,0,0,0,0,6,3,0,0,0,4,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,5,0,0,0,9,9,6,0,0,6,0,0,0,0,0,0,0,0,4,0,0,0,0,7,0,0,5,0,0,0,0,0,3,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,6,0,0,0,3,0,7,3,0,0,5,3,0,6,0,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,3,0,0,0,0,0,0,0,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,3,0,5,5,3,0,7,0,6,0,8,0,7,0,0,5,0,0,8,8,0,6,0,0,0,0,0,0,0,0,3,8,0,8,8,0,0,0,0,0,0,0,0,4,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,6,6,0,0,7,7,7,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,2,2,0,0,0,0,0,0,0,0,0,7,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,5,5,0,10,0,0,0,8,0,0,0,0,0,0,4,4,2,0,3,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,3,6,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,0,4,3,3,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,2,3,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,5,3,0,0,0,3,0,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,9,0,0,0,0,0,2,0,6,11,11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,5,0,5,0,9,0,5,5,7,0,3,3,5,4,3,9,6,4,0,0,0,2,0,0,4,0,0,0,0,0,0,0,0,0,6,6,0,0,6,6,0,0,0,0,4,2,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,2,7,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,7,7,0,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,7,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,3,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,7,7,8,0,3,0,0,0,0,0,0,0,0,0,6,6,4,4,0,4,3,9,7,7,0,8,0,0,9,4,0,0,10,0,10,10,7,7,0,0,0,0,8,3,0,6,0,5,0,0,0,0,3,3,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,6,0,0,0,0,0,0,0,5,0,0,0,0,0,0,0,0,3,3,0,0,0,0,3,0,0,0,0,3,5,0,0,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,3,0,5,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,7,5,6,0,0,0,5,6,0,5,0,0,0,0,0,0,0,4,3,0,0,0,0,0,0,0,3,0,0,8,0,0,9,9,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,3,0,0,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,8,3,0,4,0,3,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,5,0,5,0,0,0,0,0,0,0,0,9,0,0,0,0,5,0,0,0,0,3,0,0,11,0,0,2,0,0,0,3,3,0,0,0,0,0,0,0,0,2,0,0,6,0,0,0,4,3,0,6,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,6,0,0,6,3,0,0,0,0,0,0,0,4,4,0,0,0,0,0,0,3,3,0,0,0,0,0,0,0,0,0,0,0,2,3,3,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,3,2,0,7,9,9,0,0,0,0,3,0,6,0,0,0,0,6,0,0,0,3,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,3,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,3,7,2,0,0,0,5,0,0,0,0,0,2,0,7,0,12,7,4,0,0,0,2,0,0,0,0,0,0,0,0,0,0,11,0,0,2,11,11,2,0,0,0,6,6,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,5,0,0,10,0,10,4,10,0,10,0,0,0,0,0,0,0,2,0,0,0,0,9,10,10,3,0,0,4,6,0,0,0,0,0,6,9,8,6,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,10,0,0,0,0,0,0,9,0,0,0,0,0,0,0,0,0,0,6,5,5,3,0,0,3,0,0,0,7,0,0,0,0,0,0,5,0,0,0,0,5,0,0,5,0,0,3,0,0,0,0,9,0,9,0,0,0,0,9,5,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,10,0,0,0,0,0,0,0,6,0,0,0,0,0,0,5,0,0,0,0,0,0,5,3,0,0,0,0,0,0,0,0,0,0,6,4,0,0,0,0,0,0,0,4,0,8,0,0,2,3,0,0,0,0,0,0,0,4,0,6,6,6,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,5,5,2,0,0,0,0,0,0,3,0,0,0,0,0,0,0,9,6,6,0,2,0,0,0,0,11,11,0,0,9,7,0,0,10,0,7,0,0,0,0,0,0,0,0,4,0,0,10,10,0,0,0,0,10,0,0,0,10,0,0,0,10,10,0,0,4,0,0,0,0,0,0,0,0,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,11,11,0,0,0,3,0,0,6,6,4,0,0,9,0,0,0,7,0,0,7,0,0,0,0,0,0,0,2,2,0,0,12,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,5,0,0,0,0,4,6,6,6,0,0,2,0,0,0,0,10,0,0,0,0,0,0,0,0,3,2,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,10,10,9,0,3,9,0,3,10,10,0,0,0,0,0,0,0,0,3,0,3,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,0,0,0,9,5,5,5,5,0,0,3,0,8,4,0,4,0,0,4,0,6,6,0,0,0,0,0,0,0,0,0,3,0,0,2,10,0,0,0,3,0,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,5,0,0,7,7,0,6,0,0,0,0,5,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,10,6,0,0,4,5,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,4,0,0,0,4,0,0,0,0,0,0,3,0,0,0,0,3,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,6,0,0,0,0,0,0,0,0,0,8,9,9,0,0,3,0,4,4,6,6,0,0,0,0,0,0,6,0,0,0,0,0,0,0,5,5,0,3,5,5,5,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,7,0,0,0,0,0,0,0,0,3,0,0,0,0,0,9,0,0,0,0,0,5,0,0,0,0,0,0,0,3,0,0,0,0,2,0,0,0,0,0,3,9,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,7,7,7,2,10,6,6,4,4,0,0,0,0,0,0,0,0,0,0,4,3,0,0,6,6,0,5,0,0,0,0,0,0,0,0,0,0,11};






	for ( int u = 0; u < WINDOW_SIZE; u++){
	  for ( int v = 0; v < WINDOW_SIZE; v++ ){
		  II[u][v] = data_in[u*WINDOW_SIZE+v];
	  }
	}
	SII[0][0] = data_in[WINDOW_SIZE*WINDOW_SIZE+0];
	SII[0][1] = data_in[WINDOW_SIZE*WINDOW_SIZE+1];
	SII[1][0] = data_in[WINDOW_SIZE*WINDOW_SIZE+2];
	SII[1][1] = data_in[WINDOW_SIZE*WINDOW_SIZE+3];


  COPY_LOOP1: for (int i = 0; i < WINDOW_SIZE; i ++ ){
    #pragma HLS unroll
    COPY_LOOP2: for (int j = 0; j < WINDOW_SIZE; j ++ ){
      #pragma HLS unroll
      _II[i*25+j] = II[i][j];
    }
  }


  stddev =                    SII[0][0]
                           -  SII[0][SQ_SIZE- 1]
                           -  SII[SQ_SIZE-1][0]
                           +  SII[SQ_SIZE-1][SQ_SIZE-1];

  mean =                      II[0][0]
                           -  II[0][WINDOW_SIZE - 1]
                           -  II[WINDOW_SIZE - 1][0]
                           +  II[WINDOW_SIZE - 1][WINDOW_SIZE - 1];

  stddev = (stddev*(WINDOW_SIZE-1)*(WINDOW_SIZE-1));
  stddev =  stddev - mean*mean;

  if( stddev > 0 )
    stddev = int_sqrt(stddev);
  else
    stddev = 1;

  data_out[0] =  stddev;

  /* Hard-Coding Classifier 0 */
  stage_sum = 0;
  s0[0] = classifier0( II, stddev );
  s0[1] = classifier1( II, stddev );
  s0[2] = classifier2( II, stddev );
  s0[3] = classifier3( II, stddev );
  s0[4] = classifier4( II, stddev );
  s0[5] = classifier5( II, stddev );
  s0[6] = classifier6( II, stddev );
  s0[7] = classifier7( II, stddev );
  s0[8] = classifier8( II, stddev );
  stage_sum = s0[0] + s0[1] + s0[2] + s0[3] + s0[4] + s0[5] + s0[6] + s0[7] + s0[8];


  if( stage_sum < 0.4*stages_thresh_array[0] ){
	  data_out[1] = -1;
	for ( int u = 0; u < WINDOW_SIZE; u++){
	  for ( int v = 0; v < WINDOW_SIZE; v++ ){
		  data_out[u*WINDOW_SIZE+v+2] = II[u][v];
	  }
	}
	data_out[WINDOW_SIZE*WINDOW_SIZE+2] = SII[0][0];
	data_out[WINDOW_SIZE*WINDOW_SIZE+3] = SII[0][1];
	data_out[WINDOW_SIZE*WINDOW_SIZE+4] = SII[1][0];
	data_out[WINDOW_SIZE*WINDOW_SIZE+5] = SII[1][1];
	  return;
  }




	/* Hard-Coding Classifier 1 */
	stage_sum = 0;
	s1[0] = classifier9( II, stddev );
	s1[1] = classifier10( II, stddev );
	s1[2] = classifier11( II, stddev );
	s1[3] = classifier12( II, stddev );
	s1[4] = classifier13( II, stddev );
	s1[5] = classifier14( II, stddev );
	s1[6] = classifier15( II, stddev );
	s1[7] = classifier16( II, stddev );
	s1[8] = classifier17( II, stddev );
	s1[9] = classifier18( II, stddev );
	s1[10] = classifier19( II, stddev );
	s1[11] = classifier20( II, stddev );
	s1[12] = classifier21( II, stddev );
	s1[13] = classifier22( II, stddev );
	s1[14] = classifier23( II, stddev );
	s1[15] = classifier24( II, stddev );

	stage_sum = s1[0] + s1[1] + s1[2] + s1[3] + s1[4] + s1[5] + s1[6] + s1[7];
	stage_sum+= s1[8] + s1[9] + s1[10] + s1[11] + s1[12] + s1[13] + s1[14] + s1[15];

	if( stage_sum < 0.4*stages_thresh_array[1] ){
		data_out[1] = -1;
		for ( int u = 0; u < WINDOW_SIZE; u++){
		  for ( int v = 0; v < WINDOW_SIZE; v++ ){
			  data_out[u*WINDOW_SIZE+v+2] = II[u][v];
		  }
		}
		data_out[WINDOW_SIZE*WINDOW_SIZE+2] = SII[0][0];
		data_out[WINDOW_SIZE*WINDOW_SIZE+3] = SII[0][1];
		data_out[WINDOW_SIZE*WINDOW_SIZE+4] = SII[1][0];
		data_out[WINDOW_SIZE*WINDOW_SIZE+5] = SII[1][1];
		  return;
	}


	/* Hard-Coding Classifier 2 */
	stage_sum = 0;
	s2[0] = classifier25( II, stddev );
	s2[1] = classifier26( II, stddev );
	s2[2] = classifier27( II, stddev );
	s2[3] = classifier28( II, stddev );
	s2[4] = classifier29( II, stddev );
	s2[5] = classifier30( II, stddev );
	s2[6] = classifier31( II, stddev );
	s2[7] = classifier32( II, stddev );
	s2[8] = classifier33( II, stddev );
	s2[9] = classifier34( II, stddev );
	s2[10] = classifier35( II, stddev );
	s2[11] = classifier36( II, stddev );
	s2[12] = classifier37( II, stddev );
	s2[13] = classifier38( II, stddev );
	s2[14] = classifier39( II, stddev );
	s2[15] = classifier40( II, stddev );
	s2[16] = classifier41( II, stddev );
	s2[17] = classifier42( II, stddev );
	s2[18] = classifier43( II, stddev );
	s2[19] = classifier44( II, stddev );
	s2[20] = classifier45( II, stddev );
	s2[21] = classifier46( II, stddev );
	s2[22] = classifier47( II, stddev );
	s2[23] = classifier48( II, stddev );
	s2[24] = classifier49( II, stddev );
	s2[25] = classifier50( II, stddev );
	s2[26] = classifier51( II, stddev );

	stage_sum = s2[0] + s2[1] + s2[2] + s2[3] + s2[4] + s2[5] + s2[6] + s2[7];
	stage_sum+= s2[8] + s2[9] + s2[10] + s2[11] + s2[12] + s2[13] + s2[14] + s2[15];
	stage_sum+= s2[16] + s2[17] + s2[18] + s2[19] + s2[20] + s2[21] + s2[22] + s2[23];
	stage_sum+= s2[24] + s2[25] + s2[26];


	if( stage_sum < 0.4*stages_thresh_array[2] ){
		data_out[1] = -1;
		for ( int u = 0; u < WINDOW_SIZE; u++){
		  for ( int v = 0; v < WINDOW_SIZE; v++ ){
			  data_out[u*WINDOW_SIZE+v+2] = II[u][v];
		  }
		}
		data_out[WINDOW_SIZE*WINDOW_SIZE+2] = SII[0][0];
		data_out[WINDOW_SIZE*WINDOW_SIZE+3] = SII[0][1];
		data_out[WINDOW_SIZE*WINDOW_SIZE+4] = SII[1][0];
		data_out[WINDOW_SIZE*WINDOW_SIZE+5] = SII[1][1];
		  return;
	}
	data_out[1] = 1;
	for ( int u = 0; u < WINDOW_SIZE; u++){
	  for ( int v = 0; v < WINDOW_SIZE; v++ ){
		  data_out[u*WINDOW_SIZE+v+2] = II[u][v];
	  }
	}
	data_out[WINDOW_SIZE*WINDOW_SIZE+2] = SII[0][0];
	data_out[WINDOW_SIZE*WINDOW_SIZE+3] = SII[0][1];
	data_out[WINDOW_SIZE*WINDOW_SIZE+4] = SII[1][0];
	data_out[WINDOW_SIZE*WINDOW_SIZE+5] = SII[1][1];
	return;
}






void cascadeClassifier_2
(
  int data_in[631],
  int *result
)

{
#pragma HLS INTERFACE ap_hs port=result
#pragma HLS INTERFACE ap_hs port=SII_in
#pragma HLS INTERFACE ap_hs port=II_in

  MyRect tr0,tr1,tr2;
  int result_in;
  int stddev;
  int r_id;
  int w_id;
  int s;
  int stage_sum=0;
  static int s0[9];
  #pragma HLS array_partition variable=s0 complete dim=0

  static int s1[16];
  #pragma HLS array_partition variable=s1 complete dim=0

  static int s2[27];
  #pragma HLS array_partition variable=s2 complete dim=0

  int_II II[WINDOW_SIZE][WINDOW_SIZE];
  int_SII SII[SQ_SIZE][SQ_SIZE];

  static  int stages_thresh_array[25] = {
    -1290,-1275,-1191,-1140,-1122,-1057,-1029,-994,-983,-933,-990,-951,-912,-947,-877,-899,-920,-868,-829,-821,-839,-849,-833,-862,-766
    };
  int haar_counter = 0;
  static  int stages_array[25] = {
  9,16,27,32,52,53,62,72,83,91,99,115,127,135,136,137,159,155,169,196,197,181,199,211,200
  };
  int w_index = 0;
  int r_index = 0;
  int i,j,k;

  static  int rectangles_array0[2913] = {
  6,6,3,8,3,6,5,11,4,6,6,1,0,9,5,5,13,7,10,2,18,0,9,7,5,0,5,9,9,6,3,5,18,1,0,5,2,8,2,0,20,0,18,0,12,0,12,8,5,1,17,0,6,6,0,4,2,19,1,0,1,14,3,6,8,15,1,4,0,3,1,5,3,14,1,11,5,6,9,9,7,10,8,3,6,0,4,11,0,11,4,11,9,9,1,10,6,7,0,6,1,6,2,20,0,2,0,12,5,11,0,12,6,8,0,10,3,2,2,3,5,9,4,4,6,3,0,6,6,3,1,8,0,12,0,19,0,6,7,9,0,4,7,18,0,18,0,16,2,9,2,14,5,15,0,8,7,0,1,14,7,10,4,10,1,10,5,8,6,7,0,1,5,12,6,7,0,2,2,14,8,14,8,17,6,13,3,9,0,0,6,7,10,1,5,9,20,2,5,0,5,0,6,0,1,2,2,0,9,7,11,6,18,3,18,1,11,0,13,7,11,8,13,2,3,0,9,4,7,0,7,7,3,0,3,4,13,9,5,1,10,0,1,4,0,2,9,5,17,1,14,3,15,9,17,3,7,1,10,0,15,3,12,6,14,1,13,7,12,6,6,7,7,8,7,0,15,0,15,7,15,0,8,0,3,0,9,10,7,5,14,2,0,4,9,0,18,0,8,8,11,7,12,6,15,5,9,7,14,2,5,9,12,9,3,6,12,1,12,1,10,3,10,0,6,6,5,4,11,7,3,2,3,8,16,7,18,0,18,3,18,0,5,6,10,8,15,3,15,2,8,8,15,4,13,7,18,1,14,1,4,1,10,0,15,3,15,3,15,0,4,2,14,6,17,1,16,7,12,4,10,2,15,0,6,1,6,0,8,9,6,0,16,0,14,1,5,4,16,0,10,9,9,3,6,8,0,14,5,9,0,3,3,20,0,8,6,9,1,9,7,13,7,14,2,18,6,18,7,18,0,9,0,17,1,14,6,3,9,12,6,6,1,10,5,5,0,0,1,6,4,1,5,0,3,2,6,14,0,14,0,0,0,5,3,6,0,13,7,9,1,13,5,16,4,0,5,12,2,15,0,12,11,9,8,12,3,6,7,12,10,16,4,2,5,10,8,6,6,0,1,3,3,0,10,8,5,0,14,9,14,1,15,0,17,2,3,9,18,0,4,2,14,0,18,5,21,6,8,7,21,10,15,0,11,7,12,6,14,6,3,3,0,10,11,6,16,3,16,0,10,0,13,7,5,0,6,3,8,2,15,3,17,1,19,1,4,6,15,0,15,3,8,6,5,10,10,0,15,0,12,9,12,6,15,0,11,6,10,0,3,3,0,0,12,2,7,0,3,6,5,11,0,18,3,9,0,13,0,13,4,13,5,7,6,14,4,11,0,13,2,10,8,14,6,8,7,8,5,3,0,5,0,3,1,5,1,1,3,6,6,14,1,11,10,11,7,12,2,14,6,14,0,5,1,13,7,12,0,7,7,8,1,13,5,14,4,12,9,11,5,8,1,9,3,12,8,2,0,14,2,2,6,5,1,7,3,9,2,18,3,20,2,1,0,19,0,18,0,7,0,10,8,4,2,7,3,16,5,10,4,2,6,1,12,0,15,5,8,1,17,8,17,7,15,2,10,0,20,1,15,0,16,2,10,1,11,3,3,10,3,0,12,8,10,9,4,0,9,8,13,5,0,1,19,0,16,0,12,7,9,0,1,1,13,0,12,4,15,1,3,2,13,1,3,7,12,0,13,0,15,0,13,5,0,2,0,1,15,0,6,8,10,8,12,6,13,1,15,6,13,5,6,0,11,9,10,8,3,10,4,9,5,2,13,8,12,2,7,3,11,0,3,1,11,9,9,1,6,1,8,2,11,7,11,5,11,5,4,2,7,9,2,8,3,8,0,6,0,20,0,0,0,14,0,1,5,4,8,6,2,11,2,5,9,8,6,10,0,18,2,3,2,13,6,9,7,18,9,6,0,13,0,13,5,11,4,6,0,12,0,12,5,5,5,3,7,13,2,19,1,5,0,2,5,1,3,8,6,10,1,8,3,5,4,6,7,0,0,3,2,7,5,10,9,18,4,10,9,11,7,4,2,13,7,3,1,8,3,5,8,9,0,6,0,13,5,1,9,9,5,4,0,16,9,8,8,10,7,5,2,18,1,6,9,10,6,8,1,9,6,17,2,7,1,1,9,3,16,0,16,0,8,5,4,0,6,0,20,8,6,0,6,0,20,0,15,0,13,5,5,3,6,6,10,1,11,5,12,5,13,0,8,1,2,2,17,1,7,0,15,1,9,0,16,4,7,9,12,8,15,3,15,1,15,6,10,6,11,6,11,9,3,2,3,3,4,0,10,0,5,8,11,5,5,10,10,7,1,0,12,2,12,1,12,0,5,6,14,5,9,1,8,3,12,0,8,4,12,9,9,1,8,3,7,10,10,3,12,3,10,5,7,6,12,2,0,0,0,5,1,9,2,5,4,2,7,0,2,3,6,9,15,8,3,2,19,1,14,4,14,6,14,4,0,1,20,0,8,7,16,5,11,10,10,7,14,5,12,6,11,1,15,9,10,3,16,7,15,0,13,2,5,1,5,1,14,4,14,4,18,1,2,0,12,3,16,3,9,9,15,7,17,3,3,0,2,0,13,5,5,5,18,0,3,2,2,5,6,6,13,5,6,0,18,0,12,6,0,3,9,5,4,10,8,2,8,0,18,0,9,1,2,7,8,4,10,2,15,3,15,4,15,0,15,0,10,1,7,10,8,3,7,0,10,7,5,5,6,3,16,0,0,0,10,10,4,0,9,3,6,11,5,4,2,7,1,13,5,11,6,3,0,10,6,6,0,18,0,11,0,2,1,18,0,17,0,0,0,10,7,15,3,15,0,15,0,5,0,9,3,9,5,9,8,10,5,9,7,11,9,6,1,16,0,8,0,3,0,6,0,14,1,13,4,12,2,16,3,14,8,9,0,4,5,15,0,8,1,14,4,16,3,18,1,11,0,15,7,22,0,18,0,3,6,7,2,4,9,4,3,18,2,4,7,7,6,12,0,8,2,13,5,9,5,3,2,11,3,9,1,15,1,9,6,10,7,10,4,0,3,19,0,17,1,18,0,3,2,9,5,10,8,7,9,5,8,8,6,14,6,8,2,2,0,0,7,6,14,4,2,6,9,7,6,5,18,0,18,2,5,11,15,7,7,10,10,2,14,8,14,3,14,1,3,1,18,0,5,6,14,4,15,0,0,3,3,0,1,0,2,2,0,10,10,6,11,9,2,1,13,6,10,6,14,6,9,8,17,1,14,7,3,1,14,0,12,0,10,1,15,6,6,8,14,0,10,6,7,9,10,8,7,4,17,3,10,2,3,4,15,7,15,1,11,5,10,4,0,4,10,0,6,1,18,4,6,1,1,2,12,0,10,7,9,4,6,5,10,8,9,3,4,6,8,0,11,2,8,0,0,2,4,10,7,9,17,0,16,1,12,3,12,3,12,8,10,6,13,1,7,2,0,9,0,9,2,13,4,20,8,0,0,3,3,13,5,13,2,9,8,12,8,8,11,9,0,9,1,12,6,13,1,9,2,15,0,9,2,15,4,17,0,15,0,9,3,16,0,13,0,0,5,8,4,10,8,11,4,14,2,4,8,1,7,13,8,4,3,14,8,3,4,3,9,9,7,12,6,18,3,18,0,13,5,11,3,16,5,7,1,2,3,17,5,13,0,15,1,12,1,3,6,5,9,11,4,6,5,11,5,1,7,6,6,11,5,6,0,2,0,9,9,12,0,1,3,2,5,10,8,5,6,7,5,4,0,9,9,6,9,10,5,14,5,14,0,16,4,8,0,13,0,0,6,10,1,0,2,2,1,10,7,9,7,3,7,3,8,3,6,1,5,8,3,0,2,4,9,9,14,7,14,4,17,1,14,0,9,3,14,4,7,7,14,10,14,5,4,9,3,4,16,4,6,10,9,6,5,3,6,0,6,0,4,0,15,0,6,3,12,6,6,9,10,7,14,2,11,1,15,1,10,4,7,10,13,3,13,5,10,7,15,5,8,7,12,6,7,6,5,3,3,0,14,0,1,1,7,9,10,2,8,0,5,2,14,3,9,4,0,7,11,0,14,2,11,7,6,4,14,4,13,8,17,4,15,3,12,0,16,2,15,0,18,0,16,5,12,0,5,0,8,5,10,6,6,3,12,0,0,5,10,9,8,0,16,3,6,0,14,0,2,4,12,0,6,1,11,3,15,6,9,4,7,5,11,7,8,0,10,0,20,0,12,1,5,1,6,5,11,1,11,0,3,1,0,1,11,4,12,4,13,1,9,0,6,6,10,6,13,2,11,1,1,0,13,5,18,0,11,0,12,1,7,8,6,2,14,3,15,5,11,7,11,9,4,9,17,1,7,6,9,1,19,0,3,1,2,4,6,4,15,3,8,3,15,3,5,1,14,0,15,3,9,1,13,1,6,8,0,0,4,1,14,1,10,6,10,7,14,6,8,3,5,0,9,4,10,8,7,8,11,7,4,0,7,1,11,6,7,7,9,0,7,1,9,0,1,1,9,3,9,9,16,2,13,1,14,3,13,7,4,9,7,0,15,1,14,4,15,3,0,7,1,1,6,1,15,3,4,0,6,4,6,0,3,4,20,0,11,6,11,1,11,1,11,0,3,7,17,5,16,0,6,0,3,2,10,10,11,9,5,6,10,0,6,4,14,0,1,8,13,10,7,8,7,2,11,7,13,0,12,8,12,6,14,0,14,0,4,1,4,0,3,9,0,6,2,18,0,11,9,7,1,18,5,18,0,9,2,10,5,9,7,10,4,6,0,3,9,6,2,19,0,5,5,1,8,6,9,2,5,8,9,14,2,10,1,11,4,6,5,9,7,7,2,5,7,0,0,16,5,5,0,11,0,4,2,3,2,6,0,3,0,5,1,19,3,19,7,9,0,15,1,9,7,9,7,9,7,9,10,5,0,9,2,15,1,6,0,6,0,13,2,13,5,11,7,10,3,14,4,4,5,7,2,10,3,16,0,0,4,10,7,13,3,16,2,3,4,4,3,8,2,14,7,4,0,10,5,0,0,3,9,0,6,8,2,12,5,14,5,6,7,11,7,13,0,1,6,10,3,0,0,3,7,10,8,12,6,16,2,10,8,14,0,11,3,10,0,19,4,4,0,6,19,0,18,0,5,10,9,0,7,1,8,0,13,10,13,7,4,0,0,6,7,0,13,3,12,2,9,6,14,5,10,6,14,4,14,0,13,2,6,0,19,1,15,3,11,7,14,3,20,7,7,2,15,7,13,5,3,5,9,3,19,0,20,0,7,4,10,0,7,0,13,1,7,0,6,8,7,1,16,5,7,4,6,9,15,6,12,7,6,10,10,3,4,2,13,7,1,0,0,3,3,3,13,2,10,6,2,2,10,8,13,3,3,2,14,3,5,2,17,2,0,7,15,5,11,6,11,5,15,4,12,6,5,9,12,4,4,5,14,9,9,9,1,2,12,6,12,8,7,0,4,2,15,0,6,6,8,1,6,7,10,3,15,1,15,10,15,6,15,6,16,2,2,6,9,2,16,0,15,8,15,0,12,3,13,0,10,7,4,0,6,3,9,5,5,3,5,6,0,2,8,18,0,4,6,4,4,7,0,13,5,3,0,14,0,14,0,6,0,14,6,15,8,4,5,7,10,5,1,18,0,13,0,12,7,14,0,14,2,14,1,3,5,5,8,9,6,5,8,6,3,13,3,12,7,13,7,11,7,5,8,4,0,0,0,9,3,12,8,10,5,2,6,8,9,15,1,11,5,6,1,2,7,10,3,7,7,9,1,13,3,8,6,4,0,3,2,16,4,16,1,15,3,18,0,4,2,17,1,8,0,11,0,19,2,3,4,7,3,8,4,10,3,15,0,6,9,12,8,16,8,6,0,17,0,9,1,7,7,7,3,9,3,6,1,16,0,0,3,4,0,20,1,18,0,8,4,7,6,7,9,8,8,8,4,7,0,12,4,8,9,14,7,4,10,12,0,16,5,10,2,2,7,3,2,15,2,10,4,15,0,18,0,15,3,12,0,11,9,12,3,5,0,8,6,14,9,6,6,1,12,3,9,4,11,3,5,4,9,8,16,3,6,8,0,0,5,0,2,9,9,9,5,2,6,5,18,0,10,6,3,5,17,0,9,5,11,0,6,4,9,5,6,7,11,1,18,0,0,0,6,0,19,4,19,1,3,0,12,7,12,2,14,0,15,0,14,0,5,0,3,5,4,3,4,4,16,6,13,3,12,5,10,6,6,0,12,0,12,9,6,0,2,0,6,0,0,4,12,6,15,3,6,5,12,0,11,10,9,1,6,1,7,0,10,9,10,8,9,1,0,6,8,5,4,4,8,1,10,1,0,1,5,0,9,1,8,8,5,9,6,2,10,7,14,8,9,3,5,4,6,9,12,6,9,5,5,9,11,2,15,3,3,5,16,0,13,1,15,5,6,2,14,10,13,3,13,3,11,0,0,6,18,0,15,1,15,0,3,0,15,0,12,3,16,0,9};

  static  int rectangles_array1[2913] = {
  4,4,9,18,5,5,8,14,0,6,4,8,2,9,6,0,11,5,8,5,0,6,6,18,7,3,8,6,5,6,21,6,1,1,8,6,12,1,13,1,2,5,4,3,1,6,1,1,5,10,13,4,4,5,1,10,17,3,3,1,7,7,12,6,7,15,17,4,1,0,5,8,14,15,15,6,5,0,0,6,0,6,6,8,0,0,7,6,20,6,13,6,6,12,22,7,7,6,14,18,1,16,4,4,4,16,12,0,10,8,8,0,0,14,16,8,19,10,9,0,6,5,5,14,13,16,0,6,1,2,8,9,12,16,16,1,2,8,5,17,7,1,5,1,1,0,0,7,10,9,15,7,6,8,8,6,7,14,10,12,0,0,3,0,1,0,0,18,3,3,10,10,11,11,11,10,13,4,0,0,0,1,1,6,14,14,18,4,17,2,8,5,5,4,0,15,0,0,22,0,6,1,5,1,2,8,12,12,7,1,2,4,1,15,5,5,0,4,0,0,6,7,17,18,18,20,15,4,6,14,9,6,6,10,16,6,0,0,7,20,5,2,1,0,0,21,7,7,8,15,15,0,6,1,2,14,6,2,4,17,7,1,13,13,6,12,1,0,2,2,18,6,7,3,4,1,2,3,3,0,8,8,14,14,10,0,1,6,9,0,0,0,11,9,8,12,12,12,7,7,0,0,3,3,2,10,14,13,5,17,18,0,4,4,3,1,16,3,5,2,14,21,14,2,4,6,8,14,6,6,7,3,12,6,6,9,6,6,2,18,2,2,10,0,0,0,12,6,12,5,8,6,12,12,1,1,9,21,13,13,6,0,7,4,0,0,12,12,12,12,14,13,15,0,1,1,14,3,1,0,6,10,15,1,9,0,15,15,7,12,8,14,10,3,17,13,0,3,5,7,6,8,15,1,8,5,2,7,7,6,1,1,18,4,16,7,7,2,20,12,2,0,0,15,8,3,5,4,6,4,4,4,22,14,14,11,11,9,12,0,0,17,17,6,6,4,0,0,15,8,12,2,20,0,13,10,3,5,7,0,0,1,17,15,15,16,13,0,4,5,4,0,0,7,7,5,13,0,7,2,2,2,6,5,6,0,3,7,7,7,6,14,0,2,4,3,4,0,6,0,10,21,6,5,2,7,7,17,18,6,18,18,9,9,3,17,15,17,3,3,0,0,0,0,3,11,0,0,8,12,0,6,0,2,7,6,1,4,3,1,0,0,13,5,1,2,10,4,10,10,14,7,1,1,5,9,16,12,14,13,5,5,5,5,1,1,15,9,2,2,0,0,17,5,2,2,7,7,0,0,6,7,6,6,3,0,9,7,6,0,14,14,12,2,16,16,0,0,8,5,13,14,6,0,1,6,0,11,20,11,12,11,11,4,15,0,0,2,0,18,7,14,2,3,6,8,4,8,2,16,0,2,11,3,16,17,13,9,7,8,2,17,18,3,6,0,0,10,11,5,6,5,3,21,10,4,8,9,6,6,5,4,4,10,10,2,2,4,4,4,4,18,18,2,2,5,8,7,5,14,14,11,9,6,19,5,5,4,6,10,7,2,18,9,2,0,3,2,5,0,3,14,9,11,5,6,6,5,5,10,10,0,3,1,7,12,6,7,18,2,3,2,0,0,5,22,10,1,0,3,15,13,8,8,2,5,8,8,6,0,9,0,5,5,5,4,16,16,9,13,10,9,0,11,5,5,6,6,5,6,13,5,2,15,17,13,10,6,14,12,10,0,11,2,4,0,17,6,10,16,16,16,11,11,3,4,0,16,15,15,17,8,6,8,8,5,6,7,5,9,8,8,11,0,2,0,0,3,10,0,3,4,0,5,0,4,10,10,11,10,12,21,20,15,17,12,6,13,16,5,1,19,1,2,10,11,9,10,7,0,6,0,2,17,0,0,17,7,3,2,2,1,16,13,15,5,13,2,14,12,13,8,12,16,1,2,6,7,0,8,12,21,0,6,4,7,8,8,14,11,12,0,10,2,0,6,6,11,11,16,6,16,7,10,4,18,0,3,0,1,1,16,3,16,3,9,4,7,7,4,12,3,6,6,3,3,6,1,17,18,5,6,2,7,0,8,7,5,9,14,14,8,11,0,0,1,11,18,9,10,6,14,7,4,16,13,8,16,0,5,5,6,7,10,12,10,0,4,10,6,11,8,11,9,12,4,4,9,5,9,0,9,9,4,3,1,6,18,8,19,8,8,12,7,1,12,0,0,3,6,11,8,17,14,3,3,0,0,11,11,11,20,6,0,3,5,12,0,0,5,12,13,1,0,2,2,10,10,6,12,14,1,11,15,14,3,6,6,1,1,15,15,1,3,0,3,5,0,1,7,3,3,7,7,13,5,1,1,15,2,5,15,12,12,0,2,7,9,5,5,17,18,17,17,17,0,0,14,13,20,9,10,8,10,10,15,5,13,17,12,9,9,7,4,8,7,15,8,17,17,1,7,5,4,16,16,0,6,4,0,1,6,9,2,2,3,1,9,10,0,4,1,8,0,22,15,0,7,14,14,5,5,5,5,2,2,0,4,16,0,12,21,5,5,6,5,14,5,8,6,13,10,13,0,1,4,3,13,13,13,16,16,16,16,0,1,2,15,2,2,2,2,0,12,2,10,3,7,11,8,0,0,3,18,18,3,7,3,17,5,6,16,2,2,4,13,1,12,7,5,11,11,4,2,0,0,0,0,2,13,7,8,14,0,15,9,4,10,5,18,18,20,8,8,5,5,6,0,4,4,12,0,12,12,15,15,0,0,6,12,4,22,7,0,1,16,7,10,2,9,2,2,3,13,14,2,4,1,6,21,5,6,6,3,10,15,4,0,0,0,7,0,10,2,5,0,0,2,2,0,0,2,10,7,0,3,7,6,2,6,0,0,0,17,17,14,15,15,14,8,7,8,0,8,5,6,7,8,8,10,5,12,9,14,9,18,6,6,16,16,11,6,7,6,7,10,12,14,12,13,0,1,16,17,2,0,0,2,1,8,8,5,5,4,7,15,2,1,1,1,1,11,11,6,10,9,18,21,12,6,6,4,12,14,7,13,7,12,2,0,9,10,10,15,16,2,5,0,16,12,15,10,9,11,7,15,8,4,6,6,7,8,8,3,3,2,2,3,3,3,3,11,11,8,6,18,4,1,11,12,12,0,12,20,4,2,8,7,0,11,0,7,17,10,5,11,4,0,4,4,18,0,4,4,11,6,0,9,15,7,15,12,12,12,7,7,4,4,11,16,15,15,1,21,20,1,17,16,16,16,10,18,5,2,7,6,0,7,1,18,2,7,1,0,3,15,10,3,0,0,0,4,17,20,3,3,6,6,9,18,0,1,0,10,16,16,12,16,6,6,9,9,4,8,3,3,1,5,6,10,4,2,4,4,8,8,13,13,13,2,2,2,0,2,5,3,21,10,10,8,8,8,15,13,8,13,15,4,15,15,11,6,2,2,1,7,6,11,16,0,11,9,5,2,3,15,0,0,1,0,2,2,2,4,1,1,5,4,5,5,5,0,8,6,3,18,8,2,5,4,6,1,4,6,17,6,6,5,2,2,6,3,3,3,1,2,2,14,8,0,0,6,5,7,16,17,8,13,17,17,0,2,3,17,17,18,15,13,14,18,13,14,2,9,3,2,4,5,5,6,4,4,7,9,0,3,1,22,10,0,0,2,13,21,1,7,0,1,1,2,5,2,2,11,7,9,9,4,6,21,21,5,10,0,2,0,12,13,0,1,13,21,3,10,3,2,1,0,1,18,15,10,9,11,7,2,2,4,5,7,4,0,1,0,0,1,0,5,0,14,14,18,0,4,2,1,8,15,10,17,4,0,6,9,9,11,2,0,15,18,17,11,11,9,16,16,1,2,15,11,18,14,7,8,1,14,7,12,0,0,0,0,8,8,21,0,0,6,6,0,0,16,0,0,1,1,13,0,5,10,7,10,6,2,13,6,13,20,4,6,0,13,16,0,6,5,15,7,6,6,0,0,18,15,3,3,14,14,15,17,0,0,16,0,7,8,9,0,1,4,1,2,1,0,17,14,15,21,15,15,6,3,1,4,1,2,2,2,7,3,6,1,8,0,16,16,19,16,8,15,18,18,3,5,5,6,2,6,2,8,5,8,0,12,12,7,14,6,6,13,10,10,9,3,0,12,0,0,2,2,0,0,6,6,1,1,0,10,9,9,7,15,10,4,2,0,9,2,0,15,14,1,0,3,2,4,16,16,18,0,3,12,3,3,8,15,13,6,9,0,3,3,5,4,7,0,0,0,1,2,13,13,2,9,6,8,7,12,10,6,12,15,14,8,10,10,9,12,12,12,12,12,10,15,10,1,4,5,10,12,0,10,2,20,10,17,0,0,2,2,7,1,14,13,6,2,6,19,15,5,6,6,0,0,5,5,1,13,1,17,13,18,14,1,4,0,5,5,1,1,0,4,6,18,18,15,7,7,9,13,15,15,13,13,5,18,19,19,19,14,0,1,9,15,0,10,10,8,5,5,4,4,7,6,4,0,1,1,14,3,3,2,2,7,22,16,3,10,16,0,5,8,1,6,3,13,12,5,5,6,1,19,14,6,0,0,1,8,7,12,1,1,7,10,7,3,0,0,5,5,0,0,2,1,0,17,18,17,15,15,14,10,18,12,10,10,2,6,14,14,1,21,1,16,1,0,1,1,7,14,1,0,1,1,0,14,7,11,5,6,1,1,9,4,16,0,5,3,12,11,10,9,2,6,8,1,1,14,16,16,4,19,8,1,8,8,5,6,12,12,6,6,0,1,6,6,17,22,12,12,12,14,6,7,3,1,1,2,2,12,2,6,6,0,0,6,1,7,7,20,6,2,3,4,1,0,2,2,15,17,6,0,4,6,12,14,14,18,3,3,6,5,4,16,8,6,5,1,1,10,2,0,1,6,1,4,0,16,16,0,3,7,9,14,14,21,21,4,7,4,15,13,6,16,5,8,8,8,8,8,6,8,5,5,1,10,17,16,10,4,18,18,16,15,15,1,1,5,5,0,4,0,0,5,6,2,2,0,4,0,0,7,7,8,0,10,0,1,1,6,12,9,10,18,16,14,14,10,13,13,0,8,5,0,11,5,18,8,7,0,0,2,8,9,7,2,0,14,12,12,6,0,8,6,11,3,12,16,6,10,10,12,12,15,15,20,20,17,2,1,15,2,12,7,1,8,3,6,0,0,15,7,6,21,3,7,2,10,9,5,9,11,13,0,18,4,8,3,15,18,14,15,6,6,6,14,8,6,9,9,15,20,18,18,16,16,2,2,0,20,6,9,6,6,4,6,0,1,0,0,12,12,5,6,5,16,8,8,4,4,7,19,11,1,2,13,0,11,1,10,19,10,1,1,4,4,6,9,5,2,0,0,7,2,0,6,8,18,14,15,0,0,4,0,0,2,6,1,0,0,2,0,2,11,8,8,8,11,9,4,17,21,4,15,8,12,17,16,1,1,13,1,4,8,7,7,6,6,9,1,6,5,6,4,8,10,5,4,4,7,6,5,7,7,2,1,13,13,15,15,0,6,7,9,6,7,12,14,17,12,17,3,17,1,17,5,7,4,1,5,0,11,7,7,17,6,15,15,10,10,15,1,0,0,1,21,9,4,1,9,1,0,0,6,1,12,17,1,0,6,0,7,12,9,1,11,11,10,2,16,16,13,16,16,18,13,2,8,13,20,8,7,6,20,20,1,1,3,2,9,3,0,9,4,4,13,13,15,13,0,2,1,1,6,2,11,1,0,3,1,7,0,0,9,15,7,9,17,3,1,15,0,3,1,0,6,0,0,11,7,6,14,14,0,0,1,12,8,6,5,9,8,12,19,0,4,16,7,7,6,17,17,4,0,0,0,4,12,9,5,5,7,1,0,6,8,6,12,4,1,1,10,4,13,13,15,14,14,8,10,10,7,10,1,15,6,1,6,18,0,13,6,6,6,7,8,8,8,2,10,10,7,7,9,2,2,1,2,3,8,8,18,6,6,3,6,8,2,14,2,3,6,2,17,7,11,1,0,0,7,2,1,0,0,0,15,18,8,6,2,7,6,2,9,4,8,8,0,0,0,0,2,2,6,0,1,4,5,13,14,2,1,1,4,5,1,12,12,18,13,3,9,3,2,6,6,9,9,6,6,16,20,10,6,1,13,15,12,11,6,0,0,3,3,5,5,2,2,0,0,11,11,6,16,16,6,7,6,1,9,5,11,8,8,6,5,7,0,0,6,6,6,21,19,18,18,16,16,0,0,14,14,14,14,18,18,5,3,0,0,12,3,4,4,14,14,6,11,5,4,8,8,6,14,6,6,14,5,5,0,3,3,12,10,8,14,10,10,12,8,11,11,2,2,12,10,9,8,7,0,0,5,6,0,1,0,3,14,9,2,4,4,5,7,5,5,4,14,17,16,17,20,14,6,4,3,8,6,6,5,5,5,2,1,2,0,9,0,0,0,1,9,8,9,9,0,1,1,20,0,8,8,13,13,8,8,11,11,12,1,11,10,8,8,14,18,16,20,12,12,17,6,17,18,15,13,17,17,17,17,2,13,1};

  static  int rectangles_array2[2913] = {
  12,12,18,9,4,12,12,4,7,12,12,19,24,6,14,14,9,6,6,4,6,24,6,10,14,24,15,5,6,3,18,13,6,6,24,14,21,4,20,6,4,22,6,6,4,19,4,4,14,18,4,6,12,12,24,18,12,4,4,24,8,3,16,12,6,9,18,16,4,18,20,14,7,9,9,8,14,12,6,6,6,6,6,18,12,24,16,6,24,4,15,4,4,6,18,4,8,10,10,18,22,18,6,4,4,20,8,6,6,12,12,6,6,9,9,6,12,20,18,18,14,10,12,18,8,18,6,12,4,19,22,11,15,12,12,5,24,12,9,6,22,17,6,6,6,6,6,8,19,6,17,3,8,9,9,10,3,24,18,6,10,9,16,9,20,9,9,10,6,12,18,22,8,6,6,11,24,22,20,2,2,2,2,3,9,9,18,8,18,12,14,6,6,9,18,5,4,18,19,4,19,6,14,20,22,7,22,22,6,9,4,12,6,18,6,16,6,24,4,4,6,6,9,14,18,15,15,16,10,15,10,6,18,18,18,14,2,2,15,21,5,24,22,15,24,18,10,10,6,20,10,16,7,6,6,12,10,6,5,24,5,6,6,6,3,13,4,9,6,6,12,6,12,8,10,6,2,6,2,2,9,9,9,9,18,24,8,4,10,3,6,6,24,13,6,16,6,6,10,6,6,6,6,6,9,6,6,5,3,18,19,6,3,3,18,6,9,20,6,22,5,18,6,24,12,12,14,8,5,3,18,20,19,6,6,6,6,6,6,15,6,6,18,12,6,6,9,13,9,6,9,3,9,10,4,4,6,18,10,22,16,18,8,6,6,6,6,6,9,9,19,19,10,10,6,6,6,9,4,14,6,18,9,21,17,11,13,9,15,6,18,24,3,24,10,18,18,16,3,18,6,6,6,18,12,6,24,5,5,6,6,19,12,4,10,10,10,9,21,9,9,4,4,9,18,6,11,6,9,6,6,9,19,6,6,4,4,18,6,6,6,18,18,11,14,15,22,24,18,12,7,22,14,24,18,22,11,6,24,10,10,24,18,16,16,18,21,6,6,9,2,6,6,6,4,24,10,6,6,9,6,10,2,15,6,6,9,14,8,7,4,6,6,21,5,4,5,11,12,24,23,18,21,6,4,8,15,10,9,6,9,9,9,9,6,18,21,6,6,6,16,10,10,10,6,12,3,6,9,8,3,4,9,24,6,6,6,12,2,12,18,18,24,4,6,6,8,16,8,8,11,24,4,4,16,6,18,6,9,8,3,18,6,6,4,4,18,12,9,9,6,6,9,3,14,3,14,14,9,9,6,6,6,6,8,9,8,10,4,6,18,8,24,3,10,10,10,24,15,12,14,4,6,6,18,14,6,6,24,6,10,6,6,11,10,6,6,4,20,10,6,10,4,10,12,8,4,9,14,19,10,16,24,18,18,18,9,23,18,12,3,10,10,6,4,6,6,9,6,3,9,3,6,18,18,8,9,9,5,14,3,15,15,6,6,6,6,6,6,8,8,10,21,12,12,12,6,20,12,8,8,20,12,16,9,12,14,9,19,6,18,4,20,22,4,4,6,6,10,12,24,4,4,17,18,14,14,3,3,14,9,18,12,8,7,22,4,7,9,22,6,8,6,6,9,18,12,4,4,6,9,8,6,6,4,19,9,12,18,4,18,4,4,4,6,4,18,20,6,8,3,14,24,18,5,5,8,8,12,6,6,12,23,19,11,8,10,9,9,9,20,9,9,8,21,10,12,23,8,18,9,9,6,6,24,18,24,18,9,9,18,6,6,5,6,6,8,21,3,11,10,12,18,22,6,6,6,6,18,3,16,6,16,18,6,8,10,10,12,8,9,24,18,9,10,4,9,6,12,20,9,9,4,8,9,12,9,6,5,21,10,6,18,8,18,9,18,12,6,4,4,24,9,9,19,22,6,20,6,16,8,6,16,16,4,8,12,6,8,6,6,21,16,7,4,6,6,4,6,12,23,6,12,10,6,9,9,18,18,12,21,12,6,19,14,18,4,11,9,4,4,18,11,20,13,22,14,10,10,6,9,8,16,14,9,18,9,24,10,18,6,11,12,4,4,6,15,6,6,6,6,16,20,4,4,18,6,9,15,19,7,9,8,18,12,9,14,22,6,10,10,16,6,8,6,8,4,8,10,14,20,4,12,12,6,8,8,9,16,6,3,5,5,10,23,21,6,12,8,24,8,8,8,5,19,24,13,24,4,6,12,12,18,9,4,4,9,9,6,6,19,18,16,9,4,15,8,6,6,12,11,21,8,6,21,19,6,6,14,9,8,22,9,18,7,16,12,4,4,4,6,6,3,6,3,12,4,3,3,10,3,6,19,18,18,6,20,20,6,24,18,6,8,8,14,4,5,8,22,6,9,19,9,18,9,24,14,9,6,13,6,21,9,9,10,24,9,6,9,6,14,14,9,6,10,4,6,6,9,9,9,4,12,9,10,10,24,9,24,11,22,6,20,14,16,19,10,4,21,6,14,6,9,4,19,20,4,8,6,6,4,4,6,6,24,6,4,4,9,6,7,14,6,4,6,6,10,14,12,12,6,20,9,6,5,16,8,6,9,9,9,9,18,18,18,19,6,15,6,6,6,22,21,18,6,18,8,18,6,6,2,2,7,9,21,7,22,24,9,12,14,14,6,6,20,9,21,14,12,9,6,6,18,6,6,6,6,6,24,18,10,12,19,4,9,15,12,6,6,16,14,20,20,6,12,12,6,6,6,6,9,15,9,9,9,9,8,4,10,4,10,18,11,12,12,9,15,12,12,12,8,8,24,8,4,4,15,24,5,18,3,4,9,20,18,10,4,6,6,6,9,18,20,4,6,18,18,6,6,6,20,20,18,6,22,6,6,24,6,6,6,6,6,9,18,9,23,18,9,8,15,8,6,8,6,4,12,8,8,6,6,12,18,8,22,12,20,20,10,18,19,6,22,7,11,10,9,6,6,6,6,6,9,18,13,8,8,8,6,6,6,5,5,6,6,12,24,2,2,2,2,6,6,18,7,12,18,20,6,18,18,6,9,18,6,12,12,6,4,9,12,6,6,9,12,20,12,3,15,6,12,8,8,9,12,6,9,8,6,24,6,5,5,6,6,6,6,18,9,10,10,6,6,10,6,18,6,9,6,4,4,12,10,22,2,24,10,8,6,5,20,12,6,10,12,6,4,6,4,4,19,2,2,2,10,4,6,16,6,6,6,12,9,9,18,22,6,6,16,9,6,6,6,24,24,6,18,18,22,9,21,12,24,4,6,6,6,6,20,12,4,12,4,3,10,12,6,4,6,6,6,4,18,22,10,10,12,12,5,21,9,12,12,8,10,10,12,10,12,4,6,6,11,6,4,4,8,16,18,16,8,9,8,8,8,8,5,7,24,8,8,24,12,12,6,8,18,18,22,12,12,12,6,9,7,9,18,4,6,6,12,14,17,12,9,24,9,18,9,9,24,20,16,4,10,6,7,7,6,19,9,9,10,18,4,4,8,12,6,12,10,21,9,6,6,12,20,10,5,4,8,24,4,18,16,6,14,8,20,9,6,4,4,8,2,9,19,9,18,6,6,4,18,14,18,9,12,7,20,9,15,6,6,9,9,12,6,8,24,6,8,24,12,9,16,4,5,9,9,6,20,17,7,23,6,4,6,18,9,2,2,18,15,18,4,10,10,6,6,6,18,6,6,11,10,10,10,6,10,16,16,22,8,6,6,6,7,8,6,3,8,19,4,18,5,4,16,18,10,12,12,22,9,12,10,8,8,18,10,21,22,6,3,12,12,22,18,22,6,6,6,18,6,12,12,18,6,6,6,18,6,6,10,5,5,9,23,8,6,9,18,11,11,24,8,14,21,24,8,21,12,4,4,6,9,19,10,18,6,17,12,6,16,5,18,6,20,15,6,6,6,9,6,6,6,6,6,6,6,9,3,14,12,4,6,4,6,14,16,6,21,6,5,16,14,4,12,12,14,18,18,24,18,9,19,24,9,9,18,18,3,8,18,3,4,10,6,10,5,12,9,8,5,14,10,4,6,18,6,6,4,6,9,14,15,8,6,6,12,12,16,18,18,24,9,24,22,9,10,6,12,12,16,10,18,9,10,18,15,15,24,6,6,6,10,18,10,10,14,9,6,6,8,4,3,16,6,6,12,12,6,6,9,9,6,6,4,12,12,12,14,20,8,13,6,6,12,15,12,18,24,3,4,4,12,17,5,5,18,12,6,6,21,6,12,16,18,15,9,15,3,3,10,16,12,9,6,6,10,18,14,14,3,5,12,20,19,9,14,14,9,18,6,18,20,20,24,20,9,9,8,8,4,20,6,21,13,12,10,5,6,18,9,21,22,18,6,6,6,6,6,4,9,9,15,3,12,20,6,18,4,4,6,6,6,6,16,6,6,18,10,10,9,6,5,8,19,12,21,16,18,10,4,18,12,6,6,6,18,12,10,10,6,6,8,12,10,10,18,4,24,6,20,19,10,21,8,10,4,6,4,4,9,16,16,24,9,14,7,8,12,4,3,9,20,24,12,8,6,10,14,10,9,24,12,22,12,9,23,19,6,18,6,4,6,6,4,8,7,18,4,4,20,6,10,4,8,8,6,6,6,6,24,10,23,19,18,9,6,6,20,6,18,9,18,18,18,10,4,4,4,12,4,10,4,3,4,6,19,9,7,14,8,8,18,9,18,6,6,4,4,4,18,6,8,18,14,15,10,4,22,6,6,4,10,8,12,12,6,6,4,19,6,8,6,6,6,24,10,10,19,19,16,24,6,6,18,18,6,6,6,4,6,10,6,6,6,6,6,15,20,4,12,6,9,6,12,18,18,18,6,12,18,4,19,15,14,22,6,18,3,20,5,12,6,8,8,12,6,3,14,12,4,15,6,10,18,15,8,24,6,8,10,18,24,6,8,18,18,18,20,14,12,21,21,18,18,4,18,4,10,11,4,9,4,8,8,12,9,12,9,12,4,14,11,6,11,9,18,12,18,18,9,9,9,6,6,6,6,6,4,6,6,18,6,15,15,4,6,8,8,24,14,8,10,8,4,6,6,18,16,16,8,16,12,9,9,16,19,9,3,24,5,19,6,24,9,10,20,7,7,2,10,12,3,12,6,9,22,22,9,4,18,24,24,18,4,10,6,6,6,6,6,6,6,10,10,9,14,10,10,3,9,5,24,12,4,9,6,6,19,4,6,18,10,18,9,24,8,4,8,10,18,19,24,8,10,6,7,12,6,15,6,7,6,6,6,4,6,6,9,18,9,9,18,18,4,4,2,16,4,10,6,7,4,6,10,18,2,2,6,6,18,9,9,10,5,5,4,4,10,14,12,24,14,6,4,14,16,21,15,6,16,16,3,3,10,6,12,5,9,11,4,9,13,4,6,10,20,9,4,4,22,9,24,16,18,6,9,9,4,7,20,19,6,6,4,9,18,2,8,18,15,12,6,20,24,9,4,4,8,6,3,12,5,5,6,6,14,3,6,4,16,7,8,6,9,3,22,18,6,9,4,4,10,3,18,18,9,9,18,6,10,18,18,9,6,18,9,10,9,3,9,11,9,11,8,20,21,12,6,8,8,8,9,8,9,9,9,9,10,6,6,10,16,19,18,9,6,6,14,8,7,12,8,22,6,6,6,17,12,18,10,10,24,6,6,19,6,10,10,9,18,18,9,9,6,4,8,18,4,12,4,18,18,6,6,4,6,12,4,6,12,8,8,9,9,18,9,18,6,9,9,14,6,12,18,6,16,3,6,4,4,5,9,18,5,17,18,24,18,6,14,3,6,6,6,21,12,9,6,8,8,8,8,12,18,20,9,8,16,10,10,15,18,10,18,10,10,18,18,18,6,8,8,8,18,9,18,6,6,18,12,6,2,10,20,12,3,3,3,18,10,14,14,9,8,4,5,9,9,12,5,3,6,7,4,14,19,6,15,10,8,12,9,14,14,13,6,17,17,8,8,24,15,18,18,3,3,6,6,11,12,12,9,12,6,9,6,9,16,10,7,11,12,8,4,3,3,18,4,3,18,3,3,5,18,20,9,19,19,9,18,14,6,9,9,6,6,6,6,12,12,4,6,3,18,16,10,9,9,10,3,12,12,8,6,12,12,6,7,18,19,12,6,6,5,5,14,3,24,20,18,6,20,6,6,6,18,15,18,3,6,6,8,8,20,13,7,7,10,10,3,18,18,9,15,12,12,6,13,22,6,6,24,10,18,10,3,12,4,4,18,9,12,9,10,10,10,10,9,9,10,10,18,18,18,7,19,16,16,12,2,2,8,8,3,12,8,12,18,18,3,18,3,3,18,18,22,21,18,18,24,16,6,8,6,6,18,10,9,9,3,3,6,6,16,9,16,18,6,6,4,6,6,18,24,9,8,13,16,14,9,16,13,13,24,10,18,18,9,22,8,8,18,5,12,18,4,6,2,2,10,18,17,12,16,5,6,6,6,13,19,6,4,6,6,6,18,4,8,8,10,10,4,4,16,16,7,3,9,17,8,8,10,22,24,12,6,6,9,22,9,18,19,18,9,9,9,9,3,24,6};

  static  int rectangles_array3[2913] = {
  9,7,9,6,19,16,6,10,6,6,7,12,3,15,10,9,6,10,10,9,11,13,9,6,12,3,6,14,10,12,3,6,15,15,15,12,12,10,10,13,13,19,9,11,9,3,9,9,14,2,11,9,9,6,5,6,6,13,13,23,12,14,6,6,12,6,3,12,20,2,14,12,9,6,6,10,14,5,9,9,9,9,9,4,9,6,12,6,3,9,4,9,9,12,2,10,10,6,4,2,3,3,15,10,10,6,9,9,6,6,6,9,9,6,6,10,3,2,12,24,10,12,12,3,8,6,6,18,14,2,13,4,10,6,6,12,4,4,6,6,15,9,10,8,7,22,22,16,6,12,6,14,10,11,11,18,14,8,14,6,16,6,4,6,4,6,6,6,9,6,3,3,8,6,6,6,4,12,17,24,24,22,22,18,6,4,3,18,3,4,6,6,16,16,9,8,9,3,2,9,18,9,12,2,3,9,4,4,11,6,10,12,15,3,9,6,9,14,13,13,9,9,6,6,4,4,9,4,6,10,14,9,3,3,4,6,18,18,10,4,18,6,8,9,19,3,4,4,16,4,6,9,15,13,14,10,6,14,12,5,12,12,6,6,16,6,9,6,9,9,6,9,3,21,12,9,20,9,21,23,4,4,6,6,4,19,12,10,12,19,10,12,2,4,9,4,9,9,4,9,9,9,15,15,4,7,10,8,16,3,3,9,18,18,9,14,6,16,12,16,10,3,10,4,9,5,12,10,14,16,8,2,6,9,14,12,18,18,9,6,9,9,2,6,9,9,6,6,6,15,6,14,6,4,19,19,9,3,9,4,6,22,14,20,9,9,12,12,6,6,3,3,6,12,12,12,9,12,12,8,9,3,6,23,4,18,6,6,4,9,3,4,12,3,6,3,9,9,12,4,9,10,9,21,7,9,4,12,12,9,17,9,6,19,7,12,12,6,4,6,6,14,14,6,5,11,14,9,6,9,9,4,2,9,9,9,9,7,10,9,9,3,3,12,6,4,2,24,4,9,12,6,3,16,4,2,8,6,6,10,10,4,3,6,6,3,10,24,11,6,20,24,24,14,12,14,6,9,14,15,9,14,18,6,10,9,7,3,6,12,18,9,13,3,12,10,8,9,5,5,6,3,6,12,15,10,12,6,6,16,6,6,6,6,9,3,6,6,9,9,10,16,5,5,10,6,18,9,7,10,18,9,6,3,9,10,12,12,21,8,8,3,4,9,9,22,14,15,14,14,6,9,16,16,8,9,3,9,6,10,18,3,11,11,9,9,9,4,6,6,17,17,4,18,12,12,15,15,6,6,14,9,15,15,9,21,12,12,18,9,3,10,4,20,8,8,9,3,4,6,6,10,7,6,3,18,6,6,3,7,6,6,7,12,4,9,9,15,3,6,11,9,9,4,6,10,16,4,9,8,8,18,11,5,3,3,6,10,3,3,22,6,6,12,9,9,9,6,9,19,6,19,9,3,4,10,6,8,12,6,19,20,20,6,6,14,14,7,9,10,10,6,6,6,6,6,9,6,6,10,10,13,5,6,4,5,12,6,3,9,2,18,3,3,18,23,19,9,6,12,6,10,15,6,8,6,6,18,18,4,4,9,8,5,8,4,15,8,4,4,17,18,12,9,12,2,6,11,10,17,6,9,12,12,15,3,7,9,3,12,14,9,18,18,10,11,3,3,12,8,12,14,10,2,12,12,18,18,12,9,11,12,3,3,4,5,4,9,6,6,8,18,10,5,6,14,4,4,10,3,4,4,6,6,6,3,4,3,6,6,3,10,9,8,8,11,9,6,12,12,8,3,4,22,8,9,9,14,8,14,20,10,4,4,9,5,4,4,5,10,8,3,4,6,4,12,6,9,4,3,9,4,18,12,8,5,6,9,12,6,6,15,2,6,2,6,3,5,9,9,9,4,6,6,3,12,6,3,10,6,9,14,6,8,12,10,6,9,12,9,6,3,6,6,14,9,14,16,10,5,3,12,5,4,12,6,6,13,13,6,3,6,14,2,4,4,9,4,6,23,23,3,4,3,4,15,3,4,4,9,6,10,6,6,6,2,6,3,6,3,16,6,22,10,18,9,10,9,10,10,10,9,3,13,13,7,9,6,6,2,16,6,12,3,6,4,14,6,9,10,10,6,9,14,12,12,9,16,6,14,2,16,10,4,7,16,16,6,12,8,18,14,14,6,18,3,9,6,16,4,16,16,10,8,2,9,8,3,11,9,8,6,3,6,9,9,19,19,8,8,3,4,6,6,14,12,5,9,9,8,6,3,12,12,2,3,14,14,14,6,9,4,6,3,9,4,5,9,10,10,9,9,19,9,19,4,9,19,12,5,18,12,3,3,4,9,4,4,6,8,3,6,5,5,6,15,12,14,6,6,4,3,4,3,4,3,4,6,9,4,12,3,6,7,8,3,6,9,4,6,10,10,17,20,4,9,9,16,4,4,6,10,6,8,8,8,4,6,6,4,4,18,4,14,6,3,4,15,3,6,9,9,9,21,2,3,13,8,9,9,10,10,6,6,21,13,21,20,6,9,9,3,9,10,9,9,4,14,6,12,10,8,6,9,14,6,9,10,6,6,6,6,3,3,3,2,11,6,11,11,9,4,12,3,9,3,9,3,9,9,18,18,9,6,3,9,3,16,4,8,6,6,9,9,10,8,15,8,4,6,6,6,2,11,15,13,9,9,4,4,4,3,3,20,6,4,7,9,9,6,6,4,6,9,8,8,9,16,12,12,6,22,6,6,6,6,10,16,6,10,6,2,6,10,6,4,16,13,6,9,6,6,11,10,10,21,9,6,16,3,12,9,8,2,3,6,18,9,9,9,6,2,4,12,12,22,22,11,11,9,3,2,2,9,9,9,9,6,10,9,9,9,9,6,3,6,6,3,6,10,6,10,12,10,9,18,4,10,10,14,19,6,6,10,8,6,18,12,8,3,3,9,4,12,9,8,7,9,12,6,9,23,6,3,14,12,12,7,9,12,12,15,15,9,15,8,4,19,19,20,20,12,12,14,8,12,5,3,12,3,3,9,6,4,14,6,9,6,10,6,6,9,9,6,6,3,6,24,4,12,8,14,14,10,6,9,7,10,9,12,14,8,8,6,6,9,9,6,6,8,8,12,11,4,7,3,9,7,6,11,11,18,5,3,20,4,4,10,14,8,9,8,6,4,9,8,17,6,17,17,3,18,18,18,8,9,9,8,9,9,9,6,6,6,3,6,6,6,6,4,9,9,23,3,4,23,3,3,4,6,3,6,4,15,12,9,9,9,3,6,13,4,13,18,5,8,9,9,14,14,16,10,6,4,5,5,16,16,15,2,6,4,12,12,8,8,5,8,6,18,14,14,12,16,21,21,18,8,12,12,20,6,20,20,14,14,8,9,10,11,16,6,9,12,9,10,3,2,3,9,6,6,9,6,12,6,4,16,9,9,10,6,8,21,9,3,10,3,4,6,6,6,12,15,4,8,10,10,12,8,4,4,6,2,9,9,10,13,6,3,6,5,9,9,7,6,6,4,18,9,14,6,9,3,6,9,6,10,3,6,9,11,11,10,18,6,3,6,5,9,9,15,3,6,3,6,6,8,3,6,4,6,9,6,6,6,9,10,4,6,10,6,8,6,4,10,8,12,12,9,12,16,6,2,9,9,13,2,6,24,24,10,6,3,11,4,18,16,16,6,2,6,6,6,4,7,7,6,8,3,3,14,10,12,18,9,9,10,12,12,10,2,13,3,12,15,4,3,8,6,3,4,6,5,7,10,10,6,9,6,16,22,12,18,18,4,4,6,9,9,9,3,13,4,6,3,12,9,13,2,9,9,8,8,8,6,15,12,9,4,3,6,6,6,8,6,3,3,5,3,6,10,10,12,6,2,10,12,12,9,11,13,6,12,3,6,3,10,9,9,9,6,9,9,16,16,9,9,6,6,16,12,6,20,9,9,9,4,12,9,4,9,8,16,6,15,8,4,6,10,21,21,3,6,2,2,4,4,2,3,23,6,3,23,10,12,14,9,12,10,4,10,12,24,4,10,9,3,9,9,18,11,4,8,9,10,12,12,4,10,6,9,5,22,6,8,4,6,4,9,6,6,9,6,3,6,9,3,6,6,4,12,9,12,6,9,9,8,6,7,12,12,6,14,18,12,14,14,20,20,17,17,6,6,13,13,9,7,6,6,9,3,10,9,18,9,4,12,5,3,5,18,14,9,6,4,8,8,2,5,12,12,3,12,6,9,5,6,6,11,18,18,8,8,3,13,9,9,9,2,6,6,21,12,6,3,3,6,12,18,7,4,9,4,6,6,2,8,7,7,5,5,10,2,6,3,9,5,6,8,9,6,4,3,2,3,9,9,20,20,14,9,4,4,6,18,6,4,9,14,18,18,9,9,9,6,6,11,12,3,8,6,4,12,12,8,3,6,8,8,3,14,10,3,6,9,8,8,6,6,6,6,9,9,8,6,4,4,3,10,6,9,6,8,6,14,8,4,9,10,13,13,6,6,14,4,6,4,9,10,5,13,19,6,2,4,5,14,6,24,14,8,6,3,5,4,6,6,6,12,21,3,9,12,9,9,22,12,9,4,22,22,4,7,4,15,12,12,16,16,16,16,3,4,8,3,2,6,9,9,6,14,3,7,5,5,9,10,9,9,20,3,20,8,20,19,20,9,4,6,6,8,6,6,4,6,8,9,9,18,20,20,6,9,6,8,12,7,6,10,3,10,12,18,16,12,14,6,6,6,10,3,8,22,8,8,9,4,6,6,3,3,9,5,15,9,3,2,9,9,9,10,16,10,13,13,9,11,11,6,3,9,14,9,6,9,20,3,3,3,9,15,3,18,3,4,5,14,9,3,18,3,12,5,12,10,10,6,9,20,6,13,15,4,14,6,3,8,18,3,13,10,9,3,3,11,10,3,3,10,21,3,6,4,4,3,3,18,3,18,6,9,10,6,18,10,10,5,7,5,7,5,18,12,4,10,6,6,2,13,3,3,6,6,6,16,16,10,10,24,20,9,9,5,9,8,8,9,12,18,18,6,3,15,14,10,9,8,8,12,4,15,10,6,5,4,6,12,6,6,23,6,12,18,12,8,4,6,3,20,20,18,12,8,14,16,9,4,4,6,6,9,7,6,10,21,10,8,9,12,12,12,12,9,9,4,4,6,4,4,4,19,8,12,3,4,10,6,22,22,3,15,9,3,15,3,6,14,10,9,10,10,4,2,6,16,4,9,9,6,9,8,16,12,9,9,9,18,12,12,6,4,6,6,3,3,22,22,24,4,18,14,9,9,20,9,14,6,24,24,7,7,19,6,6,8,15,15,20,20,4,4,3,3,20,9,19,3,20,9,5,6,20,20,12,12,8,6,4,15,6,10,12,4,6,18,9,6,3,6,19,19,2,6,18,8,6,10,6,6,15,10,4,3,9,9,9,9,5,20,6,2,6,6,9,4,6,4,22,22,9,9,18,6,8,8,12,12,8,14,12,18,18,20,12,14,6,18,14,2,12,7,12,12,22,20,4,4,6,6,24,12,4,6,3,8,12,3,7,6,7,19,7,9,7,6,5,19,6,14,9,5,5,5,7,10,9,9,7,7,8,12,12,12,8,3,4,6,15,6,9,20,9,5,14,4,6,7,6,18,6,4,6,12,3,6,6,3,9,6,6,6,3,3,6,6,9,12,8,3,12,3,9,3,3,20,20,18,12,6,18,9,6,20,20,6,6,3,6,3,7,6,6,6,13,6,15,7,6,12,9,24,24,12,6,6,12,6,14,2,3,9,12,12,9,10,9,7,5,8,18,10,10,10,10,5,2,6,7,16,8,4,8,4,9,8,4,12,12,7,3,3,10,24,15,24,9,6,6,9,9,4,20,23,18,6,6,5,19,18,18,3,9,7,7,6,10,10,16,6,6,9,8,12,9,6,22,3,3,24,6,14,10,5,6,14,14,4,12,6,6,9,9,10,8,8,4,18,19,16,16,6,5,5,6,5,7,6,9,6,20,12,12,6,8,10,9,22,22,4,15,12,13,24,24,8,2,3,6,10,3,4,8,4,16,16,16,14,14,22,22,20,20,9,16,12,6,8,6,6,6,8,12,9,6,5,8,6,6,6,18,3,2,6,9,9,15,15,6,14,5,3,2,10,3,11,8,9,2,6,3,18,10,10,9,9,3,4,14,14,6,6,18,3,3,10,4,6,9,12,6,13,6,6,3,6,3,6,19,16,18,18,3,4,6,4,8,8,12,12,6,6,6,6,2,3,12,9,15,4,12,15,19,19,10,10,18,6,10,10,10,10,18,3,18,18,3,3,3,10,17,17,11,6,8,7,14,14,2,6,4,6,18,18,10,9,6,6,6,3,9,6,18,9,9,9,3,4,10,9,9,9,6,6,9,9,6,9,3,3,6,4,6,15,3,10,3,6,18,6,18,18,6,12,22,6,6,18,9,9,12,4,3,8,15,14,14,14,4,20,12,12,8,8,15,15,12,12,9,21,4,9,15,15,8,6,4,3,12,12,6,10,6,2,3,3,6,6,6,6,20,8,22};

  static  int rectangles_array4[2913] = {
  6,10,3,8,5,6,5,11,4,6,10,1,8,9,5,5,16,9,12,4,20,8,11,7,5,8,5,9,11,6,9,5,18,4,8,5,2,10,2,2,20,11,20,2,12,0,12,10,12,1,17,0,6,10,8,4,2,19,3,8,1,14,3,6,8,15,1,4,2,3,1,5,3,14,1,15,5,10,9,11,9,12,10,9,6,8,4,11,8,11,9,11,11,9,1,10,6,7,0,6,1,6,5,20,2,12,4,14,8,17,0,14,8,8,0,12,9,2,2,3,5,14,4,4,6,3,3,10,8,3,12,8,5,16,4,19,8,6,10,9,0,4,9,18,3,18,3,16,2,9,2,14,5,18,3,8,7,8,10,14,7,13,12,13,1,13,8,8,8,7,0,1,9,12,9,7,0,13,12,14,9,14,9,18,6,13,3,13,0,6,6,10,10,4,5,9,20,2,5,2,5,2,13,0,1,2,13,0,11,10,11,6,18,3,18,1,13,0,13,9,13,10,13,2,12,5,14,4,7,5,12,9,3,0,12,4,13,10,10,8,10,0,12,4,8,11,9,10,20,1,14,3,15,11,17,3,7,4,10,8,15,3,12,6,14,1,13,10,12,9,6,9,7,8,7,0,15,0,15,8,15,0,8,0,9,8,9,12,12,6,16,2,0,4,9,0,18,0,8,10,13,9,14,8,15,8,9,7,14,2,5,11,13,10,9,8,12,1,15,1,10,3,12,8,6,10,5,4,11,7,9,2,3,10,16,9,21,0,18,3,18,0,5,6,12,10,15,3,15,5,11,8,15,9,13,9,18,1,14,1,12,1,14,0,17,5,18,3,15,0,4,2,14,6,20,1,16,7,12,4,12,8,15,7,6,1,6,0,13,9,12,8,16,0,14,7,5,4,16,6,12,11,11,12,6,10,8,14,5,11,3,3,3,20,5,13,6,12,8,9,10,13,9,14,8,20,6,18,7,18,0,9,0,17,1,14,8,9,9,14,8,6,1,10,5,5,0,8,10,6,4,12,12,12,3,2,6,14,0,19,0,12,0,13,3,6,0,15,9,12,1,15,7,19,6,8,5,14,2,18,2,17,12,14,10,14,6,6,11,12,10,16,6,9,5,10,8,6,10,8,1,9,3,2,10,8,10,0,14,9,14,1,15,0,19,2,3,9,18,0,12,2,14,5,18,5,22,8,11,7,22,12,15,0,13,9,14,6,14,6,3,3,12,12,13,8,20,3,20,0,10,8,13,9,13,0,6,3,8,2,15,3,19,3,19,3,4,6,15,0,17,5,8,6,5,10,10,0,15,0,14,11,14,8,15,3,11,6,12,0,3,3,12,1,17,2,7,8,3,10,5,11,3,18,3,9,3,13,8,13,4,13,8,7,6,16,6,11,0,13,5,10,10,14,6,12,7,8,5,3,5,5,8,3,1,5,1,1,3,6,7,14,1,13,12,13,9,15,5,15,6,15,0,5,7,17,10,15,0,14,8,13,6,13,8,17,4,12,11,11,9,8,1,9,9,18,8,2,0,18,2,2,12,13,1,11,3,12,2,18,3,22,2,1,0,19,3,20,0,13,0,10,8,4,2,14,3,17,6,10,4,2,10,5,12,0,15,5,8,1,19,8,20,9,15,2,16,2,20,3,15,0,16,2,10,1,14,3,3,10,3,2,12,10,12,11,4,0,9,8,13,5,12,1,19,0,20,0,18,9,11,0,1,1,13,4,12,4,15,1,13,5,16,5,10,7,12,0,17,0,15,0,13,8,12,2,12,1,15,0,6,10,12,8,12,8,13,1,15,6,18,11,12,0,11,11,12,8,9,10,4,11,5,8,15,12,12,7,11,3,14,8,9,1,11,9,12,1,6,1,8,2,11,7,14,9,14,7,4,9,7,11,2,8,3,11,0,10,2,20,2,12,0,14,0,12,8,4,10,14,2,14,2,5,9,12,6,12,0,18,5,10,2,13,6,11,7,18,11,10,0,15,4,13,7,14,7,12,6,16,0,16,5,5,5,9,9,13,5,19,3,5,0,2,5,1,10,8,11,12,4,12,3,5,4,6,10,0,0,3,2,7,5,10,9,18,9,12,11,13,9,4,2,13,9,9,1,8,3,5,8,9,0,6,4,13,5,12,11,14,5,12,0,20,9,12,10,14,7,12,2,18,1,6,12,14,6,11,1,9,7,17,2,7,1,8,11,3,20,8,20,0,8,5,4,8,6,0,20,10,12,0,6,0,20,2,18,3,13,8,5,9,6,9,10,1,11,7,14,5,13,0,12,1,2,2,20,1,14,0,15,1,9,0,16,12,7,11,12,10,15,3,16,3,16,12,10,7,11,11,12,11,3,2,12,5,14,0,10,8,5,11,11,9,5,10,10,7,12,0,12,2,12,1,12,0,5,6,14,5,9,8,11,6,17,8,8,4,12,9,16,1,11,3,7,12,12,3,12,3,13,5,11,9,17,2,12,0,12,5,12,9,2,5,4,2,7,0,2,6,6,11,15,8,3,2,19,1,14,4,14,8,14,4,8,3,20,2,8,9,16,12,11,12,12,10,14,5,18,6,13,1,15,9,10,3,16,9,15,0,13,2,5,1,5,1,16,9,16,6,18,1,9,0,14,3,16,3,11,11,15,8,17,3,3,0,2,0,13,5,12,5,18,0,13,5,9,12,6,9,13,8,6,2,20,2,14,8,8,12,9,11,4,10,8,7,12,0,18,0,16,1,12,9,12,8,12,4,15,3,15,4,15,0,15,0,14,3,7,10,8,12,7,0,16,7,10,11,12,3,16,0,0,0,10,10,4,8,9,9,6,11,8,4,8,7,1,15,7,13,9,3,0,10,6,15,0,20,2,13,0,2,1,18,0,17,0,0,2,12,9,17,5,15,0,15,0,5,0,13,8,13,8,13,10,12,11,13,7,14,12,12,1,20,0,14,0,13,0,6,0,14,1,13,4,17,5,16,3,14,10,11,0,4,5,19,0,8,3,17,4,16,3,18,1,17,0,15,8,22,1,20,2,3,6,7,11,4,9,4,3,18,2,13,7,13,10,12,0,11,2,13,5,9,5,3,6,12,8,9,1,19,1,9,6,12,10,14,4,8,6,19,0,17,1,18,0,3,2,14,5,10,11,7,12,5,10,11,9,14,8,12,7,2,1,8,7,6,17,4,2,6,9,7,10,8,18,3,18,4,5,11,15,7,12,12,12,2,14,10,14,3,14,1,3,1,18,0,5,6,14,4,17,8,8,5,3,0,12,0,9,2,0,10,10,8,13,11,2,1,13,12,10,7,14,10,11,10,20,1,17,9,12,12,14,5,16,4,10,1,15,12,12,8,19,0,14,6,13,9,13,8,7,4,17,3,14,2,3,4,19,10,19,1,15,5,10,4,0,8,14,0,6,1,18,4,6,1,1,2,18,0,12,7,9,7,12,7,12,10,15,3,4,6,8,12,11,2,8,0,0,2,12,10,7,9,17,0,19,1,12,3,12,12,12,10,14,10,13,7,7,9,0,11,3,15,2,13,4,20,8,12,2,3,3,13,5,17,2,12,10,12,10,12,12,12,0,9,7,14,8,13,1,9,2,15,0,9,2,15,4,17,0,15,0,15,3,20,8,13,0,0,5,11,4,10,8,11,4,14,2,4,8,1,9,13,10,4,6,14,9,9,9,9,11,9,12,14,8,18,3,18,0,13,10,11,8,16,5,7,9,13,3,20,7,15,0,19,1,12,1,3,8,5,9,11,4,6,5,17,11,1,10,10,11,11,9,15,0,2,0,9,9,18,0,12,3,2,5,12,10,5,9,7,9,4,0,11,11,6,11,12,5,14,5,14,0,16,4,8,0,13,0,12,6,10,1,0,6,9,1,10,7,9,10,3,7,3,10,3,10,4,5,8,9,3,2,9,11,11,16,7,16,6,19,3,14,0,9,6,14,4,7,9,14,12,14,5,4,11,3,4,16,4,13,10,15,12,12,3,12,8,6,0,4,0,15,0,6,3,13,6,6,10,10,7,17,2,11,1,15,1,10,11,7,10,15,3,15,7,12,9,15,5,8,7,12,9,7,10,13,9,9,0,14,0,12,1,7,11,16,2,8,0,5,2,14,3,9,4,12,9,13,0,14,2,11,7,13,7,17,4,13,10,18,12,17,5,16,4,18,4,15,0,20,2,16,9,12,0,5,0,12,5,10,8,6,3,16,6,8,6,10,11,14,0,16,3,6,4,17,2,2,4,18,8,6,6,14,8,15,6,14,4,7,8,13,9,8,0,17,0,21,0,12,1,5,1,6,5,14,1,11,0,13,1,0,1,14,7,12,8,13,11,9,7,6,10,10,6,15,8,11,8,1,0,15,7,20,2,14,2,12,1,7,8,12,2,14,3,17,5,13,9,13,12,12,11,20,1,7,6,9,1,19,4,3,1,9,4,6,4,15,9,12,6,15,3,14,1,14,0,15,3,9,1,13,1,6,8,0,0,14,1,14,8,10,11,10,9,14,8,11,3,13,0,12,11,10,8,11,10,12,10,4,0,11,1,11,6,14,7,12,12,11,1,9,0,1,1,9,9,11,11,18,4,15,1,14,3,15,7,14,12,7,0,19,1,16,6,17,5,0,7,1,1,6,1,15,3,4,0,6,7,12,6,9,4,20,2,13,12,13,1,13,2,13,2,3,7,17,5,16,0,15,0,9,4,12,10,13,9,14,8,10,0,13,9,14,0,1,10,16,10,12,8,13,2,11,7,13,0,12,8,12,6,14,0,14,0,4,1,4,8,3,11,0,6,2,18,0,11,9,7,3,18,7,18,3,9,2,10,5,11,10,12,4,6,9,9,11,10,2,21,0,5,12,1,10,6,9,2,5,12,9,18,2,16,1,12,4,10,5,14,7,7,2,5,7,0,2,20,5,5,0,13,0,4,2,12,12,6,0,10,7,11,7,21,3,21,7,9,0,15,1,13,7,13,10,13,10,13,10,5,0,11,2,15,1,10,0,6,0,13,2,13,8,13,9,12,3,16,6,10,7,12,7,10,3,16,4,0,11,10,12,17,5,16,5,3,4,4,3,16,6,14,7,4,0,10,6,0,0,3,9,12,6,8,2,12,5,14,10,12,7,17,9,13,0,12,9,10,9,0,8,9,9,15,10,15,6,19,2,12,10,14,5,11,3,10,5,20,7,4,8,6,19,3,20,2,5,10,11,0,7,1,11,0,17,12,17,7,13,0,8,6,7,0,13,3,12,2,9,6,14,5,12,6,17,4,14,0,13,2,6,0,21,1,15,11,13,7,14,3,22,7,12,11,15,8,13,8,9,8,12,3,19,0,22,0,7,11,10,0,14,2,13,8,15,7,11,11,15,1,16,5,12,4,6,9,15,6,12,7,6,10,12,3,4,2,13,9,1,0,0,3,3,5,16,5,10,6,12,2,12,10,13,6,9,2,14,3,10,2,17,2,0,7,17,5,11,8,11,5,15,4,15,6,12,9,12,4,4,5,14,9,12,10,12,2,12,9,12,8,7,1,13,2,15,0,15,6,8,1,6,10,12,3,18,1,18,11,18,6,18,6,16,12,9,6,11,6,16,4,18,8,18,3,15,6,18,0,13,7,4,0,15,3,9,8,5,3,5,10,4,2,8,18,3,4,6,13,4,12,8,13,8,3,0,14,0,14,0,6,0,14,8,15,8,10,7,7,12,11,7,21,0,15,0,18,7,16,0,18,2,14,1,9,5,5,11,12,9,12,10,12,9,13,3,12,9,13,9,11,7,5,8,4,0,0,0,11,3,12,10,12,7,9,10,11,9,19,1,15,5,6,10,12,10,14,3,7,7,14,7,18,9,13,6,10,0,3,4,16,8,16,7,15,3,18,0,13,2,17,1,8,0,15,1,20,3,9,9,7,10,11,4,10,3,15,0,6,9,12,10,16,10,6,0,17,5,14,1,7,10,14,3,9,3,6,1,16,0,12,8,10,0,21,2,20,2,8,8,11,9,7,12,11,8,11,4,12,0,12,4,12,11,15,8,13,10,12,9,17,6,10,2,2,7,3,2,15,8,10,7,18,3,20,2,17,5,16,4,11,12,12,3,13,0,8,9,19,9,6,10,5,12,3,15,4,11,9,5,4,11,10,16,3,13,8,8,10,5,2,2,11,9,9,5,2,6,6,20,2,10,10,3,5,17,0,9,10,11,0,6,4,9,5,6,7,11,12,18,0,0,0,6,0,20,4,21,1,3,0,18,7,17,2,19,0,15,0,14,0,5,0,12,5,4,3,4,10,16,7,17,3,12,5,14,6,15,0,12,0,12,9,6,0,2,7,12,6,8,4,12,10,18,3,6,5,12,0,12,11,11,1,14,1,7,0,12,12,12,10,9,1,0,6,12,5,4,4,8,1,10,1,12,1,5,0,9,1,8,8,5,9,6,2,12,10,14,8,9,12,5,4,14,9,14,8,11,5,5,9,11,2,18,3,12,5,20,0,18,1,15,5,6,2,14,10,13,3,13,3,16,0,0,12,21,0,15,1,15,0,3,0,15,0,12,3,17,0,12};

  static  int rectangles_array5[2913] = {
  7,4,12,20,5,13,11,19,3,8,4,12,2,14,11,3,11,5,8,5,0,6,6,20,13,3,11,13,5,12,21,8,1,1,8,6,16,1,13,1,2,5,4,3,1,7,1,1,5,11,13,7,7,5,1,12,17,3,3,1,11,14,12,8,13,17,18,10,1,1,5,12,17,17,17,6,5,0,3,6,0,6,6,8,3,0,11,6,20,6,13,6,6,18,23,12,12,8,16,19,2,17,4,4,4,16,12,0,10,8,8,0,0,16,18,8,19,11,9,0,6,5,5,15,17,19,0,6,1,3,8,11,12,16,16,5,2,10,5,20,12,4,5,1,1,0,0,7,12,13,17,14,6,8,8,15,14,14,10,15,0,0,3,0,1,0,0,20,3,5,11,11,11,11,11,12,13,4,0,0,0,1,1,6,16,16,19,4,18,2,11,5,13,4,3,19,0,1,23,0,12,1,5,2,3,11,12,12,7,1,7,10,6,16,8,5,0,4,0,0,6,7,19,18,18,20,15,6,8,14,9,6,7,11,16,6,0,0,7,20,14,2,1,3,0,21,7,7,8,15,17,3,11,1,2,14,8,2,8,17,11,1,16,16,14,14,1,0,2,2,20,6,7,10,8,4,2,6,3,0,10,10,16,16,10,0,7,6,9,0,0,0,12,11,11,14,15,15,7,7,0,0,3,3,4,10,19,17,13,18,19,0,4,4,3,1,19,3,5,2,19,22,14,2,7,6,12,14,13,14,7,4,14,6,6,9,6,6,5,20,5,5,11,2,0,0,14,8,14,5,8,13,14,12,1,1,12,22,16,13,6,0,7,4,0,0,12,12,14,14,15,14,17,0,1,1,17,9,7,4,6,10,17,1,11,6,17,17,7,15,8,14,16,4,19,13,3,6,11,7,6,8,15,1,8,5,2,11,11,6,1,4,18,4,16,7,7,2,20,14,2,0,0,17,8,3,12,7,8,7,7,6,23,17,17,11,11,9,17,0,0,18,18,12,6,6,1,0,15,11,16,2,20,0,13,11,7,8,9,0,0,1,18,15,15,17,18,0,4,5,14,0,0,7,7,5,15,0,7,2,2,2,6,5,6,0,3,7,7,13,6,17,0,2,8,8,8,3,6,0,12,21,8,5,7,12,7,19,20,14,20,20,11,11,3,18,17,20,6,6,0,0,0,0,3,11,0,0,8,12,0,6,2,3,7,6,1,10,3,5,4,1,13,5,1,2,10,9,10,10,17,7,1,1,5,12,17,15,16,13,11,6,5,5,1,1,15,11,4,4,0,0,19,11,8,8,12,12,2,2,6,7,6,6,3,0,13,7,6,3,15,14,12,2,16,16,3,0,10,5,16,19,6,0,2,12,0,11,20,11,14,11,11,8,17,0,0,7,1,20,7,17,2,3,6,8,12,10,5,20,0,2,11,3,17,18,15,14,8,8,2,19,20,3,6,0,0,10,11,5,8,5,6,22,10,4,8,9,10,6,5,4,4,10,10,2,2,4,4,4,4,20,20,2,2,5,11,9,5,14,14,11,9,6,21,5,5,4,7,13,8,2,19,10,2,0,3,2,7,0,3,19,14,14,5,6,6,5,5,12,12,3,3,1,11,14,11,11,20,4,3,11,0,0,11,23,10,1,0,3,17,16,12,12,7,6,8,11,7,6,9,0,5,5,5,4,17,17,13,17,16,9,0,12,9,9,6,6,5,6,13,5,3,16,19,13,10,9,16,14,10,0,11,2,4,0,19,8,10,17,18,18,11,11,3,5,0,17,17,17,18,8,6,12,12,5,9,9,11,13,8,8,11,11,6,0,0,3,10,7,13,4,2,5,0,4,10,10,11,10,12,21,20,17,19,18,6,16,18,6,4,21,7,2,10,11,9,10,11,0,8,0,3,20,1,0,18,7,3,2,2,1,18,15,16,5,13,3,14,12,16,8,12,20,7,2,6,7,0,11,12,21,3,9,11,7,8,16,14,11,13,0,10,4,0,6,6,11,11,16,7,16,14,11,6,18,0,5,0,1,1,17,5,17,5,9,4,7,7,4,12,3,6,9,5,4,6,2,19,19,5,8,13,12,6,11,7,5,9,14,14,11,12,0,0,1,14,20,11,11,14,16,11,5,16,15,8,16,0,5,5,6,10,10,18,10,0,4,12,6,12,16,11,11,12,4,4,9,5,9,0,16,16,7,9,1,6,18,8,19,8,8,17,11,2,12,4,1,3,6,11,8,18,16,3,3,0,0,11,11,12,20,8,0,10,11,12,0,0,5,14,14,1,0,3,3,10,10,6,14,17,1,13,16,17,3,6,6,1,1,18,18,1,3,0,3,5,0,7,7,3,3,8,8,13,5,1,1,15,2,6,15,12,12,2,7,11,9,5,8,19,19,19,18,19,1,2,16,16,22,13,10,8,10,10,15,7,16,19,15,9,9,7,4,8,7,15,8,19,19,1,12,5,4,16,16,0,8,4,2,1,15,11,9,5,4,3,14,11,0,7,1,11,7,23,16,0,11,17,17,5,5,8,8,2,2,0,4,18,0,15,21,5,5,6,5,16,5,8,6,13,10,15,3,8,6,6,13,15,15,18,18,17,17,1,2,2,15,2,2,5,2,0,13,2,11,6,8,11,8,0,0,6,20,19,6,8,3,19,5,6,16,5,5,4,13,1,12,7,5,11,11,5,2,0,0,0,0,2,13,7,8,15,10,17,9,4,13,8,18,18,20,8,8,5,5,6,0,8,8,14,11,14,14,17,17,0,0,8,17,6,22,9,0,1,18,7,10,2,12,5,5,3,13,19,9,7,1,14,21,11,6,6,4,10,17,4,0,0,0,7,1,10,8,5,0,0,2,2,0,1,3,11,10,3,6,10,8,2,6,0,0,0,19,18,16,17,16,16,8,7,8,0,8,5,6,7,8,8,10,5,12,9,14,9,18,6,6,16,17,12,9,7,10,10,10,12,17,16,16,0,1,18,18,9,0,0,2,1,8,8,10,10,7,12,15,2,1,1,1,1,11,11,13,14,13,18,22,12,7,7,7,14,14,7,13,7,12,7,0,12,13,13,17,19,3,5,0,16,18,15,10,9,16,9,15,8,4,9,6,7,12,12,6,6,5,5,5,5,3,3,11,11,8,6,19,4,1,11,12,12,0,12,21,4,2,10,7,0,15,3,7,20,12,5,11,4,0,4,4,19,9,13,13,11,6,0,9,18,7,18,14,14,14,8,9,7,7,14,18,18,18,1,21,20,1,18,17,16,18,10,18,7,7,13,6,0,7,2,18,2,7,1,0,3,15,10,3,0,0,0,4,17,20,3,3,6,6,14,19,2,1,0,10,16,16,12,16,6,6,9,9,10,8,10,10,1,5,10,14,4,2,4,4,8,8,17,16,18,2,2,2,3,2,8,3,22,11,11,11,8,8,15,15,14,13,15,4,15,15,11,8,6,9,4,7,11,12,18,2,13,12,5,7,5,19,5,5,1,4,4,4,4,4,1,1,5,4,5,5,7,0,11,6,3,18,8,4,11,4,13,1,4,7,19,9,6,5,3,2,6,3,3,3,1,2,3,16,8,0,0,11,6,9,17,19,8,17,18,19,2,5,6,19,19,18,18,13,14,18,13,17,2,9,5,7,8,9,9,9,8,12,10,10,0,3,1,23,10,0,0,2,13,21,1,7,0,1,1,5,6,5,5,13,7,9,9,4,6,21,21,5,10,0,2,0,15,13,0,7,13,22,3,11,7,7,3,1,1,18,15,10,9,11,7,2,2,4,8,9,4,11,7,0,0,1,2,7,3,14,14,19,0,4,2,2,12,15,10,18,4,0,6,13,13,13,7,6,18,20,18,13,13,9,20,18,2,2,15,11,18,19,12,12,1,15,7,12,0,3,0,0,11,14,21,0,1,6,6,0,0,18,0,0,1,1,16,3,5,10,15,10,8,2,16,6,16,22,10,6,2,16,20,0,6,10,15,7,6,6,0,0,19,17,4,4,16,16,16,18,0,3,17,0,12,12,9,3,7,4,3,2,5,0,19,19,15,22,15,15,6,3,3,8,4,2,2,2,7,3,6,1,8,0,18,20,19,18,8,15,18,18,6,7,6,9,5,7,4,10,5,8,0,12,14,10,17,6,6,13,10,10,9,3,0,12,0,0,2,2,0,0,8,8,1,1,0,10,11,11,10,16,10,7,8,0,11,6,0,15,14,1,0,3,2,6,20,20,19,0,3,12,4,3,8,15,13,6,9,0,9,9,5,4,7,0,0,0,4,3,13,13,2,13,8,9,8,14,14,12,12,17,17,8,10,10,9,12,12,12,12,12,10,15,10,1,7,5,12,16,0,10,4,20,11,18,0,0,2,2,7,1,16,15,8,8,6,19,18,5,6,6,0,0,5,5,1,13,1,18,17,20,16,1,8,0,6,5,1,5,1,11,11,18,18,15,11,11,9,15,17,17,16,16,5,18,21,21,20,19,2,4,9,19,2,10,10,8,5,5,4,4,7,6,4,0,1,1,17,3,3,2,2,7,22,16,3,10,19,0,5,8,1,6,3,13,14,7,7,10,8,19,14,6,0,0,1,14,10,12,1,1,7,10,7,8,0,0,5,5,0,0,3,3,4,18,19,19,18,18,17,10,19,12,10,10,2,6,14,14,1,21,1,16,1,0,1,1,9,16,4,4,4,4,0,16,7,11,5,6,1,1,9,4,16,0,5,3,14,16,11,9,2,6,8,1,1,16,19,19,4,20,12,12,12,12,8,8,14,14,7,7,3,1,11,6,18,23,15,15,15,19,14,12,3,1,1,2,2,14,3,6,6,0,0,6,1,7,7,20,6,2,4,4,2,2,2,2,15,18,12,1,8,6,12,14,14,18,6,3,6,5,9,16,8,8,6,5,10,11,2,0,4,7,2,4,0,17,17,0,3,7,9,14,14,21,21,4,8,4,17,16,11,18,5,8,8,8,8,8,6,8,11,11,3,10,19,18,11,4,19,19,18,17,17,1,1,5,5,0,4,0,0,5,6,2,2,0,4,0,0,9,7,8,0,10,0,1,1,10,14,14,10,18,16,16,16,14,15,15,0,10,9,9,11,5,20,10,8,10,10,11,8,9,14,2,0,16,12,12,6,0,8,8,11,3,12,16,6,10,10,12,12,15,15,20,20,19,4,3,15,2,12,11,1,10,3,6,0,0,16,12,6,22,8,8,2,17,9,5,9,11,13,1,18,12,10,6,18,18,17,19,14,10,9,17,8,6,9,9,17,20,20,20,17,17,2,2,0,20,6,9,9,9,4,9,0,1,0,0,12,12,5,6,5,16,13,13,4,4,7,19,11,2,2,13,0,11,1,10,19,10,1,1,10,10,6,12,7,7,2,5,13,4,2,6,8,20,15,17,0,0,5,2,9,6,8,1,0,0,7,5,2,12,8,8,8,11,9,14,20,22,4,17,11,12,19,18,1,1,16,1,10,8,11,11,6,6,9,8,10,5,12,14,14,10,5,4,4,8,10,5,13,13,13,1,13,13,17,17,0,10,9,9,7,7,12,15,17,14,17,3,17,4,17,8,7,4,1,5,0,11,7,7,17,6,15,15,10,10,15,1,0,0,1,22,9,6,6,9,4,0,3,6,1,14,20,1,0,12,0,7,14,9,1,11,11,11,5,18,18,15,17,17,20,15,2,8,17,20,8,7,6,20,20,1,1,3,6,9,3,0,9,4,4,15,15,15,15,1,2,1,1,6,2,11,1,0,6,7,7,0,0,13,17,9,13,19,3,2,16,0,9,7,0,6,0,0,11,7,6,14,14,0,0,1,12,8,6,5,9,8,12,19,0,4,16,7,7,6,18,18,4,0,0,0,4,14,9,8,8,7,1,0,15,10,6,12,4,1,1,10,4,13,13,15,14,19,16,12,12,10,14,7,15,9,1,6,19,0,13,6,6,6,7,8,8,10,2,13,13,10,10,9,2,2,1,2,3,8,8,20,6,6,3,6,8,2,17,2,3,6,6,19,7,11,1,0,0,7,7,7,0,0,0,19,19,9,8,7,8,8,2,9,4,8,8,0,0,0,0,2,2,6,0,7,4,5,15,16,2,1,7,7,5,1,16,14,18,16,12,9,4,2,6,6,14,14,6,13,16,20,11,6,2,13,19,15,12,8,1,0,3,3,5,5,3,4,7,7,11,11,12,17,17,11,9,6,4,9,7,11,11,11,7,7,8,2,0,6,6,6,22,21,18,20,16,16,0,0,16,16,16,16,19,19,5,6,5,2,12,3,4,4,14,14,12,11,5,4,8,8,12,15,12,12,15,6,6,0,3,3,12,13,12,14,10,10,13,10,13,13,2,2,12,13,9,10,9,1,0,5,6,0,4,3,4,16,9,5,7,7,7,9,8,8,4,17,18,17,19,20,17,11,5,8,8,6,6,5,14,14,2,1,13,2,9,9,0,0,1,11,9,13,14,0,1,1,20,0,8,8,13,13,13,13,15,15,15,8,13,13,13,13,14,18,16,20,12,12,19,6,19,19,16,14,19,19,19,19,2,17,1};

  static  int rectangles_array6[2913] = {
  12,4,18,9,2,12,12,4,7,12,4,19,8,6,14,14,3,2,2,2,2,8,2,10,14,8,15,5,2,3,6,13,3,3,8,7,21,2,10,2,2,11,2,2,2,19,2,2,7,18,2,6,12,4,8,18,6,2,2,8,8,3,8,12,6,9,18,16,2,18,10,14,7,9,9,4,7,4,6,2,2,2,2,6,12,8,16,3,8,2,5,2,2,6,18,4,8,10,10,18,22,18,3,2,2,10,4,2,3,6,6,2,2,9,9,2,6,20,9,9,7,5,6,18,8,18,3,4,2,19,11,11,5,4,4,5,8,12,3,6,22,17,2,3,3,3,3,4,19,6,17,3,4,3,3,10,3,8,9,6,5,3,8,3,10,3,3,10,2,12,18,22,4,3,3,11,12,11,10,1,1,1,1,1,9,9,18,4,18,6,14,3,6,3,18,5,2,18,19,2,19,2,7,20,22,7,11,11,2,3,4,12,6,18,6,8,2,12,2,2,2,2,9,7,9,5,5,16,10,5,5,2,18,18,9,7,1,1,5,7,5,12,11,15,8,9,5,5,3,10,10,16,7,2,3,6,10,3,5,8,5,3,6,6,3,13,2,3,3,3,12,2,6,8,10,6,1,6,1,1,9,9,9,9,6,8,8,2,5,1,2,3,24,13,6,16,6,6,5,2,2,2,2,2,9,3,6,5,3,18,19,2,1,1,6,2,9,10,3,11,5,18,2,8,12,4,14,4,5,3,6,20,19,2,3,2,3,3,6,15,6,6,18,12,2,2,9,13,9,3,3,3,9,5,2,2,6,18,10,11,8,9,4,3,2,2,3,3,9,9,19,19,10,5,3,3,6,9,4,14,2,6,9,7,17,11,13,9,5,6,6,8,3,24,10,6,18,16,3,6,2,2,2,9,6,2,8,5,5,2,3,19,6,2,5,5,5,3,7,9,3,2,2,9,6,2,11,6,9,6,6,9,19,6,6,2,2,6,6,2,2,18,18,11,7,15,22,8,9,12,7,11,7,12,9,22,11,6,24,5,5,12,18,8,8,18,21,2,2,3,2,2,2,3,2,8,10,2,3,3,2,5,1,5,2,2,3,7,4,7,2,6,2,7,5,4,5,11,4,8,23,6,21,2,4,8,5,10,9,6,9,9,9,9,2,18,21,6,6,6,8,5,5,5,3,6,1,2,3,4,1,2,9,24,2,2,2,12,1,12,18,18,12,2,2,2,4,16,4,4,11,8,2,2,8,6,18,6,9,4,3,18,2,2,2,2,9,12,9,9,2,2,9,3,14,3,14,14,9,9,2,2,2,2,4,3,8,5,2,6,18,4,12,1,5,5,10,8,15,4,14,4,3,3,18,14,3,3,8,3,10,3,3,11,10,2,2,4,20,10,3,10,2,5,6,4,4,9,14,19,5,8,8,9,18,18,9,23,18,6,1,10,10,2,2,2,2,3,3,1,9,1,6,18,6,4,3,3,5,7,1,5,5,3,3,3,3,3,2,4,4,10,21,6,6,6,6,20,6,4,4,10,6,8,9,4,7,3,19,6,18,2,20,22,2,2,3,2,10,6,12,4,4,17,9,7,7,1,1,14,9,18,4,4,7,22,4,7,9,22,2,8,3,2,9,18,6,2,2,2,9,8,6,6,4,19,3,12,18,4,9,2,2,2,2,2,18,20,6,8,3,7,12,18,5,5,4,4,6,2,2,6,23,19,11,4,5,9,9,9,10,3,3,4,7,5,12,23,4,18,9,9,3,3,12,18,12,18,9,9,18,2,2,5,6,2,8,21,3,11,5,6,6,22,6,2,2,3,6,3,16,2,16,6,2,4,5,5,4,4,3,8,6,9,10,4,3,6,12,20,9,9,4,4,3,4,3,2,5,7,10,2,18,8,18,3,18,4,2,2,2,12,9,9,19,11,3,20,2,8,8,3,8,16,4,4,6,2,4,6,3,7,16,7,4,2,3,4,2,4,23,2,4,10,2,3,3,6,6,4,21,4,6,19,14,6,2,11,3,2,2,18,11,20,13,11,7,5,5,2,3,4,8,14,9,18,3,24,10,18,3,11,12,4,4,6,5,2,2,2,2,16,20,2,2,6,6,9,15,19,7,9,8,18,4,9,7,11,2,5,5,8,6,4,6,4,2,4,10,7,20,4,6,12,3,4,4,3,8,3,1,5,5,10,23,7,2,6,4,8,4,4,8,5,19,8,13,24,2,2,6,6,18,9,2,2,3,3,3,3,19,6,16,3,4,15,4,2,2,6,11,21,4,3,21,19,3,3,7,9,8,11,9,18,7,8,6,2,2,2,6,6,1,2,1,6,2,1,3,5,1,2,19,18,9,2,10,10,3,8,18,3,4,4,14,4,5,4,11,6,9,19,9,18,9,24,14,9,6,13,6,7,3,3,5,8,9,6,9,6,7,7,3,3,5,2,2,3,9,9,3,4,4,3,5,5,12,9,12,11,11,6,20,14,16,19,10,4,21,3,14,2,9,4,19,20,2,8,6,6,2,2,6,6,8,2,2,2,9,2,7,7,3,2,2,3,10,7,6,6,2,10,9,6,5,16,8,2,9,9,9,9,18,18,18,19,2,5,2,2,6,11,7,18,2,18,8,18,2,2,1,1,7,9,21,7,22,12,9,6,7,7,6,6,10,3,7,7,6,3,3,3,18,2,2,2,2,2,8,9,5,6,19,4,9,5,4,6,6,8,7,10,10,2,4,4,2,2,6,6,9,15,9,9,9,9,4,2,10,4,10,9,11,6,6,9,5,6,6,12,8,8,12,4,4,4,15,8,5,6,3,2,3,20,6,10,2,2,2,2,3,18,10,4,3,9,9,2,2,2,20,20,18,6,22,6,6,24,2,2,2,2,2,9,18,9,23,18,9,4,5,4,3,4,2,2,6,4,4,3,3,6,9,4,11,6,10,10,5,18,19,6,11,7,11,5,3,6,6,6,2,2,9,18,13,4,4,4,2,3,3,5,5,6,6,6,12,1,1,1,1,2,2,18,7,12,9,20,3,18,18,6,9,9,3,6,4,3,4,3,12,6,6,9,12,20,4,1,5,6,6,4,4,9,12,2,3,4,6,8,3,5,5,6,6,6,6,18,9,5,5,3,3,5,3,18,2,3,3,2,2,4,5,22,1,8,10,4,3,5,20,6,6,10,4,3,2,3,2,2,19,2,2,2,5,2,2,8,6,2,6,12,9,9,18,22,6,6,16,9,6,6,2,8,8,2,18,18,11,9,7,6,24,4,6,2,2,2,20,6,2,6,2,1,5,4,2,2,3,3,3,2,9,11,5,5,4,4,5,21,9,6,6,4,5,5,4,5,6,2,3,3,11,3,4,4,4,8,18,16,4,3,4,4,4,4,5,7,24,4,4,12,12,6,6,4,18,18,22,12,6,6,2,9,7,3,6,2,2,2,6,14,17,12,9,12,9,18,9,9,24,20,8,4,10,6,7,7,3,19,9,9,10,9,2,2,4,4,3,6,10,7,9,2,3,6,10,10,5,2,8,12,2,18,16,6,7,4,20,3,2,2,2,4,1,3,19,9,6,2,2,4,18,14,18,9,6,7,20,9,15,6,6,9,9,6,6,4,8,3,4,24,6,3,16,4,5,9,9,6,20,17,7,23,2,2,2,18,3,1,1,6,5,6,2,5,5,2,2,6,18,6,6,11,5,5,5,3,5,8,8,11,4,3,2,2,7,4,3,3,4,19,2,18,5,4,16,18,5,6,6,11,3,4,5,4,4,9,10,21,11,6,3,6,6,11,18,22,6,2,2,18,3,6,4,18,6,2,2,18,2,2,5,5,5,9,23,8,6,9,18,11,11,12,8,14,21,12,4,7,6,4,4,6,3,19,5,9,2,17,4,3,16,5,6,3,20,5,2,2,2,9,2,2,2,2,6,6,3,3,3,7,12,2,6,2,6,14,16,2,21,6,5,8,7,4,6,6,7,9,6,8,18,9,19,24,9,9,18,18,1,8,18,1,4,10,3,10,5,6,9,4,5,7,10,4,2,18,2,2,2,2,9,14,15,4,3,3,6,4,8,6,6,12,9,24,11,9,5,2,6,6,16,10,18,9,10,18,15,15,12,2,2,3,10,18,10,5,7,3,3,3,4,2,1,8,2,2,4,4,2,2,9,9,2,2,2,4,12,12,14,20,4,13,6,2,12,15,4,6,8,1,2,2,6,17,5,5,18,4,3,2,21,3,6,8,9,5,3,5,3,3,5,8,6,3,2,2,10,18,7,7,1,5,12,20,19,9,14,14,3,18,6,9,10,10,12,10,3,3,4,4,2,10,3,7,13,4,10,5,2,6,9,7,22,18,2,2,2,2,3,2,9,9,15,3,6,10,6,9,2,2,2,2,2,3,8,2,3,18,10,10,9,3,5,4,19,6,7,16,18,10,4,6,4,3,6,6,9,12,10,10,6,6,4,6,10,10,18,4,24,6,10,19,10,7,4,5,2,2,2,2,3,8,8,12,3,7,7,4,4,2,1,3,10,12,4,4,6,5,7,5,3,12,4,11,12,9,23,19,6,6,2,2,2,2,2,8,7,9,2,2,10,3,5,4,4,4,2,2,2,2,24,10,23,19,18,9,6,6,20,3,18,3,6,6,6,5,2,2,2,6,2,5,2,1,2,2,19,9,7,14,8,8,9,9,6,2,2,2,2,2,9,2,4,9,7,5,10,4,22,2,3,2,5,4,6,12,6,6,2,19,6,8,6,6,6,24,10,10,19,19,16,8,6,2,18,18,6,6,6,4,6,10,2,3,2,3,3,15,20,2,6,2,3,2,6,9,9,6,2,4,18,2,19,15,7,11,2,18,3,20,5,4,3,4,4,6,6,1,7,4,4,5,3,10,18,15,8,24,2,4,10,18,24,2,4,18,18,9,10,7,6,7,7,6,6,2,18,2,10,11,4,9,2,4,4,4,3,4,3,4,4,14,11,2,11,9,18,4,18,18,9,9,9,3,3,2,2,2,2,2,2,6,2,5,5,2,3,4,4,24,7,4,5,4,2,3,3,18,16,16,4,8,4,9,9,16,19,9,1,24,5,19,3,12,9,10,20,7,7,2,5,6,3,6,2,9,11,11,3,2,6,24,8,6,2,5,2,3,3,3,3,2,2,5,5,9,14,10,5,1,3,5,8,12,2,3,2,2,19,4,2,18,10,18,3,24,4,2,4,5,9,19,8,8,10,6,7,6,6,15,6,7,6,6,2,2,3,3,9,9,9,9,18,18,2,2,1,8,2,5,6,7,2,6,5,9,1,1,3,3,6,3,3,5,5,5,2,2,5,7,6,24,7,2,2,7,8,7,5,3,8,8,3,3,5,6,12,5,9,11,4,9,13,2,2,10,20,9,2,2,22,9,24,16,18,2,3,3,4,7,10,19,2,2,2,3,6,2,8,18,5,12,6,10,24,9,2,2,8,2,3,6,5,5,3,3,7,3,6,2,16,7,8,3,3,1,11,18,6,3,4,4,10,1,9,9,9,9,9,6,10,9,18,3,2,18,3,10,3,1,3,11,3,11,4,10,7,6,2,4,4,4,3,4,3,3,3,3,5,3,3,5,8,19,9,9,6,3,14,4,7,4,4,22,6,3,3,17,6,9,10,5,8,3,3,19,6,10,10,9,18,18,9,9,2,2,8,6,2,6,2,6,6,3,3,2,6,6,2,2,6,4,4,9,9,6,9,18,3,3,3,7,2,6,6,3,16,3,2,2,2,5,9,18,5,17,9,24,18,2,14,3,2,2,2,7,4,3,3,4,4,4,4,6,9,10,3,4,8,5,5,5,6,5,6,5,5,6,18,18,2,4,4,4,6,9,9,6,6,9,6,3,2,10,10,4,1,1,1,6,5,7,7,3,4,4,5,9,9,12,5,3,2,7,2,7,19,3,5,5,4,6,3,7,7,13,3,17,17,8,8,12,5,6,9,1,1,2,2,11,4,4,3,6,3,3,6,3,8,5,7,11,6,4,2,1,1,9,4,3,9,1,1,5,18,20,9,19,19,9,6,7,3,3,3,2,2,2,2,4,4,2,3,3,9,8,10,9,3,5,3,12,4,4,6,12,6,6,7,6,19,6,2,2,5,5,7,3,8,10,18,2,20,2,6,6,18,15,18,1,2,2,4,4,20,13,7,7,5,5,3,18,18,9,15,6,12,3,13,11,6,6,24,10,18,10,1,6,2,2,18,9,6,9,5,5,5,5,9,9,10,10,18,18,9,7,19,16,8,6,1,1,4,4,3,6,4,6,9,9,3,18,3,3,18,18,22,7,6,6,8,16,6,4,3,3,18,10,9,9,1,1,2,6,8,9,16,18,2,3,2,2,6,18,24,9,4,13,16,14,9,16,13,13,12,10,18,18,9,11,8,8,18,5,6,9,2,3,2,2,5,9,17,12,8,5,2,2,2,13,19,6,4,3,3,3,9,2,4,4,5,5,4,4,16,16,7,3,9,17,8,8,5,11,12,6,3,3,9,11,9,18,19,18,9,9,9,9,1,24,3};

  static  int rectangles_array7[2913] = {
  3,7,3,2,19,8,3,5,3,2,7,4,3,5,5,3,6,10,10,9,11,13,9,2,6,3,3,7,10,6,3,2,15,15,15,6,4,10,10,13,13,19,9,11,9,1,9,9,7,1,11,3,3,6,5,2,3,13,13,23,4,7,3,2,6,2,1,6,20,1,7,4,3,2,2,5,7,5,3,9,9,9,9,4,3,6,4,6,3,9,4,9,9,6,1,5,5,2,2,1,1,1,15,10,10,3,9,9,6,3,3,9,9,2,2,10,3,1,6,24,5,6,6,1,4,3,6,18,14,1,13,2,10,6,6,4,4,2,6,3,5,3,10,8,7,22,22,16,2,4,2,7,5,11,11,9,7,8,14,3,8,6,4,6,2,6,6,2,9,2,1,1,8,6,6,2,2,6,17,24,24,22,22,18,2,2,1,9,1,4,3,6,8,16,3,4,9,1,1,9,6,9,6,1,1,3,2,2,11,6,5,6,5,1,3,3,9,7,13,13,9,9,2,3,2,4,9,2,2,10,7,9,1,1,2,3,18,18,10,4,9,3,4,3,19,3,4,4,8,2,2,3,5,13,14,5,2,14,4,5,4,6,3,3,8,2,9,6,9,9,2,9,3,7,4,3,20,3,21,23,2,2,2,2,4,19,6,10,6,19,10,6,1,2,3,2,3,3,4,9,9,9,15,15,2,7,5,4,8,1,1,9,18,18,9,14,3,8,6,8,5,1,10,4,3,5,4,5,7,8,8,1,2,9,14,12,9,9,3,2,3,3,1,2,9,9,2,2,2,15,6,7,2,4,19,19,3,1,3,2,3,11,7,10,9,9,6,6,2,2,1,1,2,6,6,6,3,6,6,4,9,3,2,23,2,6,2,2,4,3,3,4,6,1,2,3,3,3,6,4,9,10,9,21,7,9,4,4,4,9,17,3,3,19,7,6,6,6,4,2,6,14,14,2,5,11,7,3,2,3,3,2,1,3,3,9,9,7,5,9,9,1,1,6,3,2,1,24,4,3,4,3,3,8,2,1,4,3,2,5,5,2,1,3,3,1,5,24,11,6,10,24,24,7,12,14,2,9,7,15,9,7,18,6,10,9,7,3,6,6,9,3,13,3,4,5,4,3,5,5,2,3,2,12,5,5,12,2,2,8,2,2,2,2,9,1,2,3,3,3,5,8,5,5,10,3,18,9,7,5,18,9,2,1,9,10,12,6,21,4,4,1,2,9,9,22,7,5,7,7,3,9,16,16,4,3,1,3,2,5,6,1,11,11,9,9,9,2,2,2,17,17,2,6,6,6,5,5,2,2,14,9,15,15,9,21,4,6,9,3,1,5,2,20,4,4,3,3,2,6,3,5,7,6,1,6,6,6,3,7,2,6,7,4,2,9,9,5,1,2,11,3,9,4,3,5,8,2,3,4,8,18,11,5,1,1,2,5,1,3,22,2,2,12,9,9,9,6,9,19,2,19,3,1,4,5,6,8,4,3,19,20,20,6,6,7,7,7,9,10,10,2,2,6,6,3,3,2,3,5,5,13,5,3,2,5,6,6,1,3,1,9,1,1,9,23,19,9,2,6,3,5,5,3,4,3,3,18,18,2,2,3,8,5,4,2,5,4,2,2,17,9,6,9,6,1,3,11,10,17,2,3,4,4,5,1,7,3,1,6,14,9,18,18,10,11,1,1,4,4,6,7,5,1,4,4,9,9,6,9,11,6,1,1,2,5,4,3,2,2,4,18,10,5,6,7,2,2,5,1,2,2,6,6,3,1,2,1,2,2,1,10,9,4,4,11,3,2,6,4,4,3,4,11,4,9,9,7,8,7,10,10,2,4,9,5,4,4,5,5,8,3,4,2,2,6,6,3,2,1,3,2,6,6,8,5,6,9,4,6,2,15,1,3,1,6,1,5,9,9,9,2,2,2,1,6,6,1,10,3,3,7,3,4,6,5,3,9,6,3,6,3,3,3,7,9,7,8,10,5,1,12,5,2,12,6,6,13,13,6,1,6,7,1,2,4,9,2,6,23,23,1,2,1,2,15,3,4,4,9,6,5,3,3,2,1,6,1,2,1,8,2,11,5,6,3,10,9,10,10,10,3,1,13,13,7,3,2,2,1,8,2,4,1,6,2,7,3,9,5,5,3,3,7,6,6,9,8,2,7,1,8,5,2,7,8,8,6,6,8,18,7,7,3,6,3,9,3,8,4,8,8,5,4,1,9,4,1,11,9,4,3,1,2,9,9,19,19,8,8,1,4,2,6,7,6,5,9,9,4,2,1,6,6,1,1,7,7,7,2,3,2,2,1,3,4,5,9,10,10,3,3,19,9,19,4,9,19,6,5,18,12,1,1,2,9,2,2,6,8,1,6,5,5,2,5,4,7,3,3,2,1,2,1,2,1,2,2,3,2,4,3,6,7,4,3,2,3,2,3,5,5,17,10,4,9,9,8,2,2,6,5,6,8,4,4,2,2,3,2,2,9,2,7,3,1,2,5,1,6,3,9,3,7,1,1,13,4,3,3,10,10,3,3,21,13,21,20,2,9,3,3,9,10,9,9,2,7,3,6,10,4,2,3,7,2,3,10,2,2,2,2,1,1,1,1,11,6,11,11,3,2,12,1,9,1,3,1,9,9,18,18,3,2,1,3,1,8,2,4,3,3,3,3,5,8,15,8,4,6,6,6,1,11,15,13,9,9,4,4,4,3,1,10,2,4,7,3,3,3,3,2,3,9,8,8,9,16,4,4,2,11,2,2,2,2,5,16,2,5,2,2,2,5,3,2,16,13,3,3,3,3,11,5,5,7,3,6,8,3,6,9,8,1,3,2,9,9,9,9,6,1,2,6,6,11,11,11,11,9,1,1,1,3,3,3,3,2,10,9,9,9,9,2,1,2,2,1,2,5,6,5,12,5,9,9,4,5,5,7,19,3,3,5,4,3,9,6,4,1,1,3,2,4,3,4,7,3,4,3,9,23,2,1,7,6,6,7,9,6,6,5,5,3,5,4,2,19,19,20,20,12,12,7,4,4,5,1,6,1,1,3,2,2,7,3,9,6,5,6,3,3,3,2,3,1,6,24,4,6,4,7,7,5,2,9,7,5,3,12,14,4,4,3,3,3,3,2,2,4,4,12,11,4,7,1,9,7,6,11,11,18,5,1,20,4,2,5,7,4,3,4,3,2,9,8,17,6,17,17,1,9,9,9,4,9,9,4,3,9,3,2,2,2,1,2,3,3,3,2,3,3,23,3,4,23,1,1,2,2,3,3,2,5,6,9,9,9,1,3,13,4,13,18,5,8,9,9,7,7,8,10,3,4,5,5,16,16,5,1,2,4,6,6,4,4,5,4,3,9,7,7,6,8,7,7,9,4,4,4,10,6,10,10,7,7,4,3,5,11,8,3,3,6,3,5,1,1,1,3,3,3,9,2,6,6,4,16,9,9,5,2,4,7,3,3,5,1,2,2,2,3,6,5,2,4,5,5,6,4,2,2,2,2,9,9,5,13,6,3,2,5,3,9,7,3,3,2,6,9,7,3,9,1,2,3,3,5,1,6,9,11,11,5,18,6,1,2,5,9,9,5,1,2,1,2,3,4,1,2,2,3,3,2,2,3,3,5,4,6,5,3,4,6,2,5,4,4,4,3,4,8,3,1,9,9,13,1,6,24,24,10,6,3,11,4,18,16,16,3,1,3,3,2,4,7,7,6,4,3,3,7,5,6,18,9,3,5,6,6,5,1,13,1,4,5,2,1,4,3,3,4,6,5,7,10,10,3,3,2,8,11,6,9,9,2,2,2,3,9,9,1,13,4,6,1,4,9,13,1,9,9,4,4,4,2,5,6,3,2,1,2,2,3,4,2,1,3,5,3,3,5,5,4,6,1,5,12,12,3,11,13,3,6,3,6,1,10,9,9,9,2,9,9,16,16,3,3,6,6,8,6,2,20,3,9,3,2,6,9,2,3,4,8,3,5,4,4,3,5,21,21,1,2,1,1,2,2,1,1,23,3,1,23,5,4,7,3,6,5,2,5,4,24,2,5,9,1,9,9,9,11,2,4,3,5,12,12,4,10,3,9,5,11,2,4,2,2,4,9,3,3,3,2,1,3,3,1,2,2,2,12,9,6,2,3,3,4,3,7,6,6,6,14,18,12,14,14,20,20,17,17,2,2,13,13,9,7,2,2,3,1,5,3,6,9,2,4,5,3,5,18,14,9,3,2,4,4,1,5,6,12,1,6,3,9,5,6,6,11,6,6,4,4,3,13,9,9,3,1,3,3,21,4,2,1,1,2,4,6,7,2,3,2,3,3,2,4,7,7,5,5,10,2,6,3,3,5,2,4,9,6,2,3,1,1,9,9,20,20,7,9,2,2,2,6,3,2,3,7,9,9,9,9,9,6,3,11,6,1,4,2,2,6,4,8,1,3,8,4,1,7,5,3,6,9,4,4,3,2,2,2,3,3,8,3,2,2,1,5,2,3,3,4,2,14,8,4,9,10,13,13,6,3,7,2,6,4,3,5,5,13,19,6,2,2,5,7,3,12,7,4,6,3,5,2,2,2,2,4,7,3,9,12,9,9,11,6,3,2,11,11,2,7,4,5,6,6,16,16,16,16,1,2,4,1,1,2,3,3,3,7,1,7,5,5,9,5,9,9,10,3,10,4,10,19,10,9,2,2,3,4,3,3,2,2,8,9,9,9,10,10,3,9,6,4,6,7,2,5,1,10,6,9,8,6,7,2,3,3,10,1,4,11,4,4,3,2,2,2,1,1,3,5,5,9,1,1,3,3,3,5,8,5,13,13,9,11,11,2,1,9,7,9,6,9,10,3,3,3,9,15,1,9,1,2,5,14,9,1,6,1,4,5,6,5,5,3,3,20,3,13,5,4,7,2,1,4,9,1,13,5,3,1,1,11,5,1,1,5,21,3,3,4,4,3,3,9,1,9,2,3,5,2,9,5,5,5,7,5,7,5,6,6,2,10,2,2,1,13,1,1,2,2,2,16,16,10,10,24,10,9,9,5,9,8,8,9,6,18,18,2,3,15,14,5,9,8,8,4,2,5,5,3,5,2,2,4,2,2,23,2,4,9,6,4,2,2,1,10,10,9,12,4,7,8,9,2,2,3,6,9,7,2,10,21,10,4,9,6,6,6,6,9,9,4,4,2,2,2,4,19,8,4,3,2,10,6,22,22,1,5,9,1,5,1,6,7,5,9,5,5,2,1,6,8,2,3,3,3,3,4,8,4,3,3,9,9,6,6,2,2,2,2,1,1,11,11,24,4,9,7,3,3,10,3,7,6,24,24,7,7,19,6,6,4,5,5,10,10,4,4,3,1,10,9,19,3,10,9,5,6,10,10,6,6,4,3,2,5,2,5,6,2,2,9,9,2,1,2,19,19,1,2,9,4,2,10,6,6,5,5,2,1,9,9,9,9,5,10,3,1,6,2,3,2,2,2,11,11,3,9,6,3,4,4,6,6,4,7,4,9,6,10,6,7,6,18,7,1,4,7,6,6,11,20,2,2,2,2,12,4,2,3,1,8,12,1,7,2,7,19,7,3,7,3,5,19,6,7,9,5,5,5,7,5,9,9,7,7,4,6,6,6,8,1,2,2,5,6,3,10,3,5,14,2,3,7,6,6,3,2,2,6,3,6,6,1,3,2,2,2,1,1,2,2,9,12,4,3,12,3,9,3,3,10,10,9,4,3,9,9,3,10,10,2,2,3,2,1,7,6,6,3,13,3,15,7,3,6,9,24,24,4,2,2,4,2,7,1,1,9,6,6,9,10,9,7,5,8,9,5,5,5,5,5,2,3,7,8,4,4,4,4,9,4,4,6,6,7,1,1,10,24,15,24,9,2,3,3,3,2,10,23,9,2,3,5,19,18,18,3,9,7,7,6,5,5,8,2,2,3,4,6,9,3,22,3,1,24,6,7,5,5,6,7,7,2,6,3,3,3,3,5,8,8,2,18,19,16,16,2,5,5,6,5,7,6,3,6,10,6,4,2,4,5,9,22,22,2,5,6,13,24,24,4,1,1,2,5,1,2,8,4,16,16,16,14,14,22,22,20,20,9,16,6,3,4,2,2,6,4,6,3,6,5,4,2,3,3,9,3,1,3,9,9,5,5,3,7,5,3,1,10,1,11,4,3,1,2,1,18,10,10,9,9,1,2,7,7,6,6,6,1,1,5,2,3,3,6,2,13,3,3,1,2,1,2,19,8,9,9,1,2,3,2,4,4,6,6,2,2,2,2,1,1,6,3,5,2,12,15,19,19,5,5,6,3,5,5,5,5,6,1,6,6,1,1,1,10,17,17,11,3,4,7,7,7,1,2,2,2,18,18,10,3,3,2,2,1,9,6,9,9,3,3,1,2,5,3,3,3,2,2,3,3,3,3,1,1,2,2,3,5,1,5,3,3,9,6,9,9,6,12,11,2,3,9,9,9,12,2,1,4,5,7,7,7,2,10,6,6,4,4,5,5,4,4,3,7,2,3,5,5,4,3,4,3,6,6,2,5,2,1,1,1,2,2,2,2,20,4,11};

  static  int rectangles_array8[2913] = {
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,12,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,0,8,0,0,0,0,0,11,0,0,0,0,0,0,0,11,0,0,0,0,11,12,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,11,6,0,0,0,0,0,0,0,11,0,12,9,10,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,0,0,0,0,0,0,0,12,0,0,0,11,0,0,0,0,0,0,0,0,0,0,0,12,2,0,0,0,0,0,0,0,0,0,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,2,11,0,0,0,0,0,0,0,9,0,12,0,0,0,0,0,9,3,0,0,0,0,0,7,0,0,0,3,11,0,0,0,0,0,12,1,0,0,0,0,0,17,11,0,0,0,0,0,9,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11,12,12,0,0,0,0,0,0,0,8,0,0,0,0,0,0,0,0,18,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,12,4,10,10,3,0,0,15,6,0,0,0,0,0,11,17,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,0,0,8,11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,12,0,0,0,0,0,0,1,0,0,12,0,0,0,0,14,5,0,0,5,11,0,0,0,0,0,0,0,0,16,0,0,0,0,5,0,0,12,0,0,0,0,0,0,0,0,12,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,7,0,0,0,11,0,0,0,11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,16,0,16,4,0,0,0,0,5,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11,10,0,0,7,0,0,12,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,12,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,13,0,0,0,7,0,0,0,0,0,14,7,0,0,0,0,0,0,0,0,12,0,0,6,14,6,0,0,5,0,0,10,0,0,0,0,20,0,0,2,0,0,0,0,7,12,0,0,0,11,7,10,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,17,0,0,0,10,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,12,0,0,0,0,16,4,12,0,0,6,0,0,0,0,0,0,0,0,3,0,0,0,0,12,0,0,13,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,13,0,0,0,0,0,0,11,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,6,0,11,10,0,0,8,12,0,4,0,0,0,0,0,0,0,10,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,11,0,0,0,0,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,12,1,0,9,10,4,0,16,0,8,0,10,0,5,0,0,7,0,0,10,10,0,9,0,0,0,0,0,0,0,0,9,16,0,16,4,0,0,0,0,0,0,0,0,6,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11,0,0,8,4,0,0,17,4,7,0,0,12,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,4,10,0,0,0,0,0,0,0,0,0,11,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,12,0,0,0,0,0,9,8,0,6,0,0,0,6,0,0,0,0,0,0,12,7,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,12,12,12,0,11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,12,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,12,0,11,5,12,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,9,11,2,0,0,0,0,0,0,0,0,0,0,0,0,0,10,0,0,0,0,0,0,6,10,0,0,0,6,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,10,0,9,6,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,0,9,0,9,0,10,0,9,11,11,0,6,10,16,11,8,10,3,5,0,0,0,12,0,0,12,0,0,0,0,0,0,0,0,0,15,4,0,0,14,7,0,0,0,0,11,12,0,0,0,0,0,0,0,0,0,0,0,12,0,0,0,0,4,10,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,15,5,0,0,0,0,10,0,0,0,0,0,0,0,0,0,0,0,9,10,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,10,14,0,0,12,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,10,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,8,0,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,17,4,14,0,3,0,0,0,0,0,0,0,0,0,6,12,14,5,0,11,7,11,10,11,0,7,0,0,10,10,0,0,15,0,15,5,11,9,0,0,0,0,10,12,0,7,0,8,0,0,0,0,12,6,0,0,0,0,0,0,0,0,9,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,16,0,0,0,0,0,0,0,10,0,0,0,0,0,0,0,0,9,12,0,0,0,0,0,0,0,0,0,12,13,0,0,0,0,0,8,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,9,0,16,0,0,4,0,11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,10,0,0,2,7,17,0,0,0,15,4,0,5,0,0,0,0,0,0,0,10,11,0,0,0,0,0,0,0,6,0,0,11,0,0,12,6,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,10,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,12,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11,0,0,0,0,0,0,0,0,0,0,0,12,6,0,9,0,5,12,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,14,0,0,7,0,5,0,0,0,0,0,0,0,0,10,0,0,0,0,11,0,0,0,0,5,0,0,12,0,0,1,0,0,0,10,8,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,12,6,0,14,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,0,0,0,0,0,0,0,0,0,0,0,8,0,0,0,0,0,14,0,0,7,12,0,0,0,0,0,0,0,9,12,0,0,0,0,0,0,10,7,0,0,0,0,0,0,0,0,0,0,0,9,3,11,0,11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11,0,0,0,0,0,6,12,0,12,15,7,0,0,0,0,4,0,17,0,0,0,0,4,0,0,0,7,0,0,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,7,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,11,5,12,0,0,0,12,0,0,0,0,0,12,0,5,0,11,7,12,0,0,0,12,0,0,0,0,0,0,0,0,0,0,13,0,0,12,13,9,4,0,0,0,15,5,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,9,0,0,11,0,11,6,11,0,11,0,0,0,0,0,0,0,6,0,0,0,0,12,11,11,5,0,0,9,6,0,0,0,0,0,13,12,7,12,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11,0,0,0,10,0,0,0,0,0,0,19,0,0,0,0,0,0,0,0,0,0,12,14,6,10,0,0,11,0,0,0,10,0,0,0,0,0,0,16,0,0,0,0,4,0,0,3,0,0,6,0,0,0,0,19,0,19,0,0,0,0,3,9,11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,0,6,0,0,0,0,0,0,13,0,0,0,0,0,0,7,8,0,0,0,0,0,0,0,0,0,0,12,0,0,0,0,0,0,0,0,6,0,11,0,0,11,1,0,0,0,0,0,0,0,10,0,12,9,16,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,13,0,13,12,4,0,0,0,0,0,0,9,0,0,0,0,0,0,0,8,14,7,0,9,0,0,0,0,19,3,0,0,11,12,0,0,20,0,7,0,0,0,0,0,0,0,0,8,0,0,20,2,0,0,0,0,7,0,0,0,7,0,0,0,7,9,0,0,7,0,0,0,0,0,0,0,0,12,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,12,0,0,15,7,0,0,0,11,0,0,12,9,5,0,0,6,0,0,0,12,0,0,1,0,0,0,0,0,0,0,4,11,0,0,6,0,0,10,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,12,0,0,0,0,0,12,0,0,0,0,13,3,10,12,0,0,6,0,0,0,0,7,0,0,0,0,0,0,0,0,12,4,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,18,3,13,0,12,9,0,6,14,6,0,0,0,0,0,0,0,0,5,0,6,0,0,0,0,0,0,0,0,0,0,0,0,9,0,0,0,0,0,0,0,0,0,0,0,12,15,5,11,9,0,0,2,0,10,11,0,12,0,0,13,0,8,11,0,0,0,0,0,0,0,0,0,12,0,0,4,8,0,0,0,10,0,0,0,0,0,0,0,0,0,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,5,0,0,7,10,0,6,0,0,0,0,0,0,0,9,0,0,0,0,0,0,0,0,0,0,0,0,0,12,7,0,0,10,8,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,12,5,0,0,0,14,0,0,0,0,0,0,9,0,0,0,0,10,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11,0,10,0,0,0,0,0,0,0,0,0,10,19,3,0,0,12,0,12,7,14,5,0,0,0,0,0,0,3,0,0,0,0,0,0,0,13,7,0,11,10,12,6,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,6,0,0,0,0,0,0,0,0,6,0,0,0,0,0,10,0,0,0,0,0,8,0,0,0,0,0,0,0,0,0,0,0,0,12,0,0,0,0,0,11,10,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,5,15,6,3,7,16,4,13,6,0,0,0,0,0,0,0,0,0,0,11,11,0,0,18,3,0,12,0,0,0,0,0,0,0,0,0,0,9};

  static  int rectangles_array9[2913] = {
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,12,0,0,0,0,0,0,0,0,0,0,0,0,12,0,0,0,0,0,0,0,20,0,0,0,0,0,15,0,0,0,0,0,0,0,12,0,0,0,0,11,12,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,19,0,0,0,11,11,0,0,0,0,0,0,0,15,0,11,11,11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11,0,0,0,0,0,0,0,8,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,15,10,0,0,0,0,0,0,0,0,0,13,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11,0,0,0,14,14,0,0,0,0,0,0,0,8,0,11,0,0,0,0,0,21,20,0,0,0,0,0,16,0,0,0,18,9,0,0,0,0,0,5,5,0,0,0,0,0,16,17,0,0,0,0,0,19,0,0,0,0,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11,11,10,0,0,0,0,0,0,0,19,0,0,0,0,0,0,0,0,15,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,9,11,14,14,0,0,18,18,0,0,0,0,0,6,7,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,21,0,0,13,13,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,0,0,0,0,0,0,5,0,8,15,0,0,0,0,5,5,3,0,18,18,0,0,0,0,0,0,0,0,14,0,0,0,0,14,0,0,9,0,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,8,0,0,0,14,0,0,0,17,0,0,0,0,0,0,0,0,0,0,0,0,15,0,0,0,17,0,17,17,0,0,0,0,9,0,0,0,0,18,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,13,15,0,0,19,14,0,20,20,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,13,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,0,0,0,9,0,0,0,0,0,9,9,0,0,0,0,0,0,0,0,8,0,0,8,19,19,0,0,9,0,0,11,0,0,0,0,11,0,0,11,0,0,0,0,6,6,0,0,0,9,9,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,13,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,16,5,0,0,0,15,15,11,0,0,11,0,0,0,0,0,0,0,0,14,0,0,0,0,7,0,0,15,0,0,0,0,0,6,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,12,0,0,0,0,0,0,10,0,0,0,0,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,0,0,0,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,11,0,0,0,15,0,15,15,0,0,7,9,0,6,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,9,0,0,0,0,0,0,0,13,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,19,0,10,10,9,0,17,0,16,0,12,0,13,0,0,16,0,0,12,12,0,11,0,0,0,0,0,0,0,0,21,16,0,16,16,0,0,0,0,0,0,0,0,15,11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,0,0,7,6,0,0,17,17,13,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,0,3,3,0,0,0,0,0,0,0,0,0,16,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,14,0,0,0,0,0,14,14,0,14,0,0,0,16,0,0,0,0,0,0,20,20,2,0,7,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,12,11,12,0,14,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11,0,9,9,19,0,0,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,21,21,22,11,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,5,4,0,0,0,5,0,0,0,0,18,0,0,0,0,0,0,0,0,0,0,0,0,13,0,0,0,0,0,12,0,11,11,11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,13,0,13,0,13,0,15,0,13,13,17,0,15,12,19,13,21,15,12,20,0,0,0,9,0,0,14,0,0,0,0,0,0,0,0,0,6,6,0,0,14,14,0,0,0,0,19,4,0,0,0,0,0,0,0,0,0,0,0,18,0,0,0,0,16,14,16,0,0,0,0,0,0,0,0,0,0,0,0,0,0,19,17,16,0,0,0,0,9,0,0,0,0,0,0,0,0,0,0,0,7,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,12,7,0,0,11,0,0,0,0,0,0,0,0,0,0,0,0,15,0,0,13,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,18,0,0,21,0,0,0,0,0,0,0,21,0,0,0,0,0,0,0,0,7,7,8,0,20,0,0,0,0,0,0,0,0,0,6,16,20,20,0,20,9,15,16,16,0,16,0,0,10,9,0,0,14,0,14,14,15,15,0,0,0,0,10,5,0,8,0,8,0,0,0,0,11,11,0,0,0,0,0,0,0,0,16,0,0,0,0,0,0,0,0,0,0,0,11,0,0,0,0,0,7,0,0,0,0,0,0,0,10,0,0,0,0,0,0,0,0,21,11,0,0,0,0,4,0,0,0,0,9,10,0,0,0,0,0,8,0,0,0,0,0,0,0,0,0,0,0,0,11,0,0,0,0,0,0,0,0,21,0,18,0,0,18,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,10,0,0,12,15,6,0,0,0,18,6,0,18,0,0,0,0,0,0,0,5,21,0,0,0,0,0,0,0,7,0,0,12,0,0,9,9,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,10,0,0,0,0,0,0,0,0,0,0,12,0,0,0,0,0,0,21,0,0,0,0,0,12,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,16,0,0,0,0,0,0,0,0,0,0,0,8,9,0,19,0,9,11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,16,0,0,9,0,7,0,0,0,0,0,0,0,0,15,0,0,0,0,7,0,0,0,0,9,0,0,11,0,0,21,0,0,0,21,21,0,0,0,0,0,0,0,0,7,0,0,18,0,0,0,10,9,0,16,16,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,0,0,9,0,0,9,11,0,0,0,0,0,0,0,9,8,0,0,0,0,0,0,16,16,0,0,0,0,0,0,0,0,0,0,0,10,13,13,0,16,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,14,0,0,0,0,0,9,21,0,12,15,15,0,0,0,0,4,0,7,0,0,0,0,7,0,0,0,8,0,0,0,0,0,0,0,0,0,0,12,0,0,0,0,0,0,21,0,0,0,0,0,0,12,0,0,0,0,0,0,0,0,0,0,9,11,2,0,0,0,8,0,0,0,0,0,18,0,17,0,12,12,12,0,0,0,15,0,0,0,0,0,0,0,0,0,0,12,0,0,14,12,12,9,0,0,0,6,6,0,0,0,0,0,0,0,0,0,0,0,0,0,17,0,0,0,0,0,11,0,0,11,0,11,20,11,0,11,0,0,0,0,0,0,0,2,0,0,0,0,15,11,11,12,0,0,4,11,0,0,0,0,0,8,15,16,7,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,13,0,0,0,11,0,0,0,0,0,0,13,0,0,0,0,0,0,0,0,0,0,18,19,19,21,0,0,9,0,0,0,15,0,0,0,0,0,0,5,0,0,0,0,5,0,0,5,0,0,12,0,0,0,0,13,0,13,0,0,0,0,14,13,13,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,14,0,0,0,0,0,0,0,10,0,0,0,0,0,0,15,0,0,0,0,0,0,15,21,0,0,0,0,0,0,0,0,0,0,17,9,0,0,0,0,0,0,0,13,0,10,0,0,14,15,0,0,0,0,0,0,0,20,0,16,16,18,18,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,14,0,14,16,15,0,0,0,0,0,0,21,0,0,0,0,0,0,0,15,15,15,0,22,0,0,0,0,13,13,0,0,15,16,0,0,14,0,7,0,0,0,0,0,0,0,0,20,0,0,14,14,0,0,0,0,12,0,0,0,11,0,0,0,11,11,0,0,10,0,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,14,0,0,12,12,0,0,0,11,0,0,12,12,13,0,0,14,0,0,0,17,0,0,11,0,0,0,0,0,0,0,15,15,0,0,12,0,0,12,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,12,0,0,0,0,0,11,0,0,0,0,19,7,6,6,0,0,11,0,0,0,0,10,0,0,0,0,0,0,0,0,3,9,0,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11,11,12,0,12,12,0,12,14,14,0,0,0,0,0,0,0,0,9,0,14,0,0,0,0,0,0,0,0,0,0,0,0,10,0,0,0,0,0,0,0,0,0,0,0,15,19,19,5,5,0,0,11,0,13,13,0,16,0,0,8,0,13,13,0,0,0,0,0,0,0,0,0,12,0,0,9,11,0,0,0,9,0,0,0,0,0,0,0,0,0,19,0,0,0,0,0,0,0,0,0,0,0,0,0,0,13,11,0,0,15,15,0,8,0,0,0,0,14,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,13,12,0,0,11,16,0,0,0,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,9,0,0,0,5,0,0,0,0,0,0,21,0,0,0,0,5,0,0,0,0,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,0,15,0,0,0,0,0,0,0,0,0,14,15,15,0,0,21,0,20,20,6,6,0,0,0,0,0,0,11,0,0,0,0,0,0,0,19,19,0,14,10,9,13,13,0,0,0,0,0,0,0,0,0,0,0,0,0,0,17,17,0,0,0,0,0,0,0,0,12,0,0,0,0,0,15,0,0,0,0,0,14,0,0,0,0,0,0,0,7,0,0,0,0,22,0,0,0,0,0,9,15,0,0,0,0,0,0,0,12,0,0,0,0,0,0,0,0,7,8,8,22,10,14,14,17,17,0,0,0,0,0,0,0,0,0,0,18,21,0,0,18,18,0,11,0,0,0,0,0,0,0,0,0,0,12};

  static  int rectangles_array10[2913] = {
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,0,6,0,0,0,0,0,8,0,0,0,0,0,0,0,10,0,0,0,0,4,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,10,0,0,0,6,6,0,0,0,0,0,0,0,9,0,7,5,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,5,0,0,0,10,0,0,0,0,0,0,0,0,0,0,0,12,11,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,11,11,0,0,0,0,0,0,0,8,0,12,0,0,0,0,0,7,9,0,0,0,0,0,5,0,0,0,9,7,0,0,0,0,0,12,11,0,0,0,0,0,3,10,0,0,0,0,0,6,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,10,3,11,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11,8,9,4,3,0,0,3,3,0,0,0,0,0,5,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,5,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,11,0,12,9,0,0,0,0,5,5,12,0,8,8,0,0,0,0,0,0,0,0,3,0,0,0,0,3,0,0,5,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,5,0,0,0,6,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,12,0,0,0,4,0,4,4,0,0,0,0,8,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,2,0,0,4,12,0,5,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,7,0,0,0,0,0,3,3,0,0,0,0,0,0,0,0,6,0,0,6,4,4,0,0,8,0,0,7,0,0,0,0,2,0,0,2,0,0,0,0,6,12,0,0,0,9,7,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,12,0,0,0,4,4,6,0,0,6,0,0,0,0,0,0,0,0,10,0,0,0,0,5,0,0,4,0,0,0,0,0,12,0,12,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,12,0,0,0,11,0,0,0,8,0,3,8,0,0,4,6,0,4,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,8,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,11,0,5,5,8,0,4,0,4,0,4,0,7,0,0,6,0,0,4,4,0,8,0,0,0,0,0,0,0,0,6,4,0,4,4,0,0,0,0,0,0,0,0,6,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,4,3,0,0,3,3,7,0,0,11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,0,10,10,0,0,0,0,0,0,0,0,0,4,11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,0,0,7,7,0,3,0,0,0,3,0,0,0,0,0,0,5,5,12,0,12,0,11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,6,6,0,10,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,12,0,6,7,7,0,0,10,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,7,10,10,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,6,6,0,0,0,6,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,10,0,3,9,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,4,0,4,0,2,0,4,4,3,0,6,9,4,11,6,10,10,5,0,0,0,11,0,0,5,0,0,0,0,0,0,0,0,0,4,4,0,0,3,3,0,0,0,0,6,12,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,9,3,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,4,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,5,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,3,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11,0,0,6,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,3,3,3,0,9,0,0,0,0,0,0,0,0,0,6,4,5,5,0,5,6,2,3,3,0,3,0,0,4,8,0,0,4,0,4,4,4,4,0,0,0,0,4,12,0,6,0,4,0,0,0,0,6,6,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,8,0,0,0,0,0,3,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,6,10,0,0,0,0,12,0,0,0,0,7,4,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,6,0,4,0,0,4,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,11,4,3,0,0,0,4,3,0,4,0,0,0,0,0,0,0,5,6,0,0,0,0,0,0,0,9,0,0,11,0,0,6,6,11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,0,0,0,0,12,0,0,0,0,0,0,6,0,0,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,0,0,0,8,7,0,6,0,7,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,6,0,4,0,0,0,0,0,0,0,0,2,0,0,0,0,4,0,0,0,0,8,0,0,12,0,0,11,0,0,0,6,6,0,0,0,0,0,0,0,0,12,0,0,3,0,0,0,5,7,0,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,3,0,0,3,6,0,0,0,0,0,0,0,5,8,0,0,0,0,0,0,7,7,0,0,0,0,0,0,0,0,0,0,0,9,10,10,0,10,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,6,10,0,9,2,2,0,0,0,0,8,0,3,0,0,0,0,3,0,0,0,6,0,0,0,0,0,0,0,0,0,0,9,0,0,0,0,0,0,6,0,0,0,0,0,0,10,0,0,0,0,0,0,0,0,0,0,8,8,12,0,0,0,4,0,0,0,0,0,12,0,4,0,5,7,5,0,0,0,11,0,0,0,0,0,0,0,0,0,0,2,0,0,9,2,2,10,0,0,0,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,5,0,0,2,0,2,5,2,0,2,0,0,0,0,0,0,0,9,0,0,0,0,2,2,2,9,0,0,9,7,0,0,0,0,0,3,2,5,4,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,6,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,3,4,4,6,0,0,7,0,0,0,3,0,0,0,0,0,0,4,0,0,0,0,4,0,0,9,0,0,6,0,0,0,0,2,0,2,0,0,0,0,2,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,3,0,0,0,0,0,0,4,0,0,0,0,0,0,4,8,0,0,0,0,0,0,0,0,0,0,3,12,0,0,0,0,0,0,0,6,0,6,0,0,11,11,0,0,0,0,0,0,0,5,0,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,4,5,9,0,0,0,0,0,0,6,0,0,0,0,0,0,0,2,3,3,0,9,0,0,0,0,2,2,0,0,2,5,0,0,2,0,5,0,0,0,0,0,0,0,0,5,0,0,2,2,0,0,0,0,7,0,0,0,8,0,0,0,8,8,0,0,5,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,10,0,0,0,0,0,0,0,0,0,0,0,0,10,0,0,2,2,0,0,0,6,0,0,3,3,7,0,0,2,0,0,0,3,0,0,11,0,0,0,0,0,0,0,9,9,0,0,9,0,0,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,4,0,0,0,0,5,3,3,5,0,0,9,0,0,0,0,4,0,0,0,0,0,0,0,0,6,9,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,2,0,6,2,0,6,4,4,0,0,0,0,0,0,0,0,7,0,6,0,0,0,0,0,0,0,0,0,0,0,0,9,0,0,0,0,0,0,0,0,0,0,0,3,4,4,4,4,0,0,10,0,4,8,0,5,0,0,5,0,5,5,0,0,0,0,0,0,0,0,0,9,0,0,9,6,0,0,0,10,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,4,0,0,7,7,0,3,0,0,0,0,12,0,0,9,0,0,0,0,0,0,0,0,0,0,0,0,0,8,5,0,0,6,4,0,0,0,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,8,0,0,0,5,0,0,0,0,0,0,6,0,0,0,0,6,0,0,0,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,3,0,0,0,0,0,0,0,0,0,6,2,2,0,0,6,0,5,5,5,5,0,0,0,0,0,0,9,0,0,0,0,0,0,0,4,4,0,6,4,6,9,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,0,0,0,0,0,0,0,0,8,0,0,0,0,0,2,0,0,0,0,0,4,0,0,0,0,0,0,0,12,0,0,0,0,11,0,0,0,0,0,9,2,0,0,0,0,0,0,0,8,0,0,0,0,0,0,0,0,3,3,3,9,2,4,4,5,5,0,0,0,0,0,0,0,0,0,0,5,11,0,0,3,3,0,11,0,0,0,0,0,0,0,0,0,0,3};

  static  int rectangles_array11[2913] = {
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,0,3,0,0,0,0,0,3,0,0,0,0,0,0,0,7,0,0,0,0,5,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,3,3,0,0,0,0,0,0,0,6,0,5,6,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,0,8,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,2,6,0,0,0,0,0,0,0,0,0,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,2,2,0,0,0,0,0,0,0,3,0,7,0,0,0,0,0,3,2,0,0,0,0,0,7,0,0,0,2,3,0,0,0,0,0,3,4,0,0,0,0,0,8,2,0,0,0,0,0,5,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,6,8,0,0,0,0,0,0,0,5,0,0,0,0,0,0,0,0,9,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,3,11,7,10,0,0,6,6,0,0,0,0,0,6,6,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,6,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,3,0,8,2,0,0,0,0,5,5,2,0,3,3,0,0,0,0,0,0,0,0,7,0,0,0,0,7,0,0,7,0,0,0,0,0,0,0,0,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,8,0,0,0,3,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,7,0,7,7,0,0,0,0,4,0,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,9,0,0,5,2,0,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,3,0,0,0,0,0,7,7,0,0,0,0,0,0,0,0,3,0,0,3,5,5,0,0,3,0,0,6,0,0,0,0,9,0,0,9,0,0,0,0,6,3,0,0,0,4,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,5,0,0,0,9,9,6,0,0,6,0,0,0,0,0,0,0,0,4,0,0,0,0,7,0,0,5,0,0,0,0,0,3,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,6,0,0,0,3,0,7,3,0,0,5,3,0,6,0,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,3,0,0,0,0,0,0,0,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,3,0,5,5,3,0,7,0,6,0,8,0,7,0,0,5,0,0,8,8,0,6,0,0,0,0,0,0,0,0,3,8,0,8,8,0,0,0,0,0,0,0,0,4,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,6,6,0,0,7,7,7,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,2,2,0,0,0,0,0,0,0,0,0,7,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,5,5,0,10,0,0,0,8,0,0,0,0,0,0,4,4,2,0,3,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,3,6,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,0,4,3,3,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,2,3,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,5,3,0,0,0,3,0,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,9,0,0,0,0,0,2,0,6,11,11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,5,0,5,0,9,0,5,5,7,0,3,3,5,4,3,9,6,4,0,0,0,2,0,0,4,0,0,0,0,0,0,0,0,0,6,6,0,0,6,6,0,0,0,0,4,2,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,2,7,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,7,7,0,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,7,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,3,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,7,7,8,0,3,0,0,0,0,0,0,0,0,0,6,6,4,4,0,4,3,9,7,7,0,8,0,0,9,4,0,0,10,0,10,10,7,7,0,0,0,0,8,3,0,6,0,5,0,0,0,0,3,3,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,6,0,0,0,0,0,0,0,5,0,0,0,0,0,0,0,0,3,3,0,0,0,0,3,0,0,0,0,3,5,0,0,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,3,0,5,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,7,5,6,0,0,0,5,6,0,5,0,0,0,0,0,0,0,4,3,0,0,0,0,0,0,0,3,0,0,8,0,0,9,9,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,3,0,0,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,8,3,0,4,0,3,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,5,0,5,0,0,0,0,0,0,0,0,9,0,0,0,0,5,0,0,0,0,3,0,0,11,0,0,2,0,0,0,3,3,0,0,0,0,0,0,0,0,2,0,0,6,0,0,0,4,3,0,6,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,6,0,0,6,3,0,0,0,0,0,0,0,4,4,0,0,0,0,0,0,3,3,0,0,0,0,0,0,0,0,0,0,0,2,3,3,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,3,2,0,7,9,9,0,0,0,0,3,0,6,0,0,0,0,6,0,0,0,3,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,3,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,3,7,2,0,0,0,5,0,0,0,0,0,2,0,7,0,12,7,4,0,0,0,2,0,0,0,0,0,0,0,0,0,0,11,0,0,2,11,11,2,0,0,0,6,6,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,5,0,0,10,0,10,4,10,0,10,0,0,0,0,0,0,0,2,0,0,0,0,9,10,10,3,0,0,4,6,0,0,0,0,0,6,9,8,6,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,10,0,0,0,0,0,0,9,0,0,0,0,0,0,0,0,0,0,6,5,5,3,0,0,3,0,0,0,7,0,0,0,0,0,0,5,0,0,0,0,5,0,0,5,0,0,3,0,0,0,0,9,0,9,0,0,0,0,9,5,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,10,0,0,0,0,0,0,0,6,0,0,0,0,0,0,5,0,0,0,0,0,0,5,3,0,0,0,0,0,0,0,0,0,0,6,4,0,0,0,0,0,0,0,4,0,8,0,0,2,3,0,0,0,0,0,0,0,4,0,6,6,6,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,5,5,2,0,0,0,0,0,0,3,0,0,0,0,0,0,0,9,6,6,0,2,0,0,0,0,11,11,0,0,9,7,0,0,10,0,7,0,0,0,0,0,0,0,0,4,0,0,10,10,0,0,0,0,10,0,0,0,10,0,0,0,10,10,0,0,4,0,0,0,0,0,0,0,0,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,11,11,0,0,0,3,0,0,6,6,4,0,0,9,0,0,0,7,0,0,7,0,0,0,0,0,0,0,2,2,0,0,12,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,5,0,0,0,0,4,6,6,6,0,0,2,0,0,0,0,10,0,0,0,0,0,0,0,0,3,2,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,10,10,9,0,3,9,0,3,10,10,0,0,0,0,0,0,0,0,3,0,3,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,0,0,0,9,5,5,5,5,0,0,3,0,8,4,0,4,0,0,4,0,6,6,0,0,0,0,0,0,0,0,0,3,0,0,2,10,0,0,0,3,0,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,5,0,0,7,7,0,6,0,0,0,0,5,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,10,6,0,0,4,5,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,4,0,0,0,4,0,0,0,0,0,0,3,0,0,0,0,3,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,6,0,0,0,0,0,0,0,0,0,8,9,9,0,0,3,0,4,4,6,6,0,0,0,0,0,0,6,0,0,0,0,0,0,0,5,5,0,3,5,5,5,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,7,0,0,0,0,0,0,0,0,3,0,0,0,0,0,9,0,0,0,0,0,5,0,0,0,0,0,0,0,3,0,0,0,0,2,0,0,0,0,0,3,9,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,7,7,7,2,10,6,6,4,4,0,0,0,0,0,0,0,0,0,0,4,3,0,0,6,6,0,5,0,0,0,0,0,0,0,0,0,0,11};

  uint10_t addr_list[12];
  #pragma HLS array_partition variable=addr_list complete dim=0


  bit enable_list[12] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
  #pragma HLS array_partition variable=enable_list complete dim=0



  uint18_t values[12];
  #pragma HLS array_partition variable=values complete dim=0



  uint18_t _II[WINDOW_SIZE*WINDOW_SIZE];
  #pragma HLS array_partition variable=_II complete dim=0

  static uint18_t coord[12];
  #pragma HLS array_partition variable=coord complete dim=0


  stddev = data_in[0];
  result_in = data_in[1];

	  COPY_LOOP1: for (int i = 0; i < WINDOW_SIZE; i ++ ){
	    #pragma HLS unroll
	    COPY_LOOP2: for (int j = 0; j < WINDOW_SIZE; j ++ ){
	      #pragma HLS unroll
	      _II[i*25+j] = data_in[i*WINDOW_SIZE+j+2];
	    }
	  }

		SII[0][0] = data_in[WINDOW_SIZE*WINDOW_SIZE+2];
		SII[0][1] = data_in[WINDOW_SIZE*WINDOW_SIZE+3];
		SII[1][0] = data_in[WINDOW_SIZE*WINDOW_SIZE+4];
		SII[1][1] = data_in[WINDOW_SIZE*WINDOW_SIZE+5];
  if(result_in < 0){
	  *result = -1;
	  return;
  }




  haar_counter = 52;

 /******************************************/
 // REST 23 STAGES
 /*****************************************/

  Stages: for ( i = 3; i < 25; i++ ){
    Filters: for ( j = 0; j < stages_array[i] ; j++ ){

      #pragma HLS pipeline
      if ( j == 0 ) {
        stage_sum = 0; s=0;
      }

      r_id = r_index;
      w_id = w_index;

      tr0.x = rectangles_array0[haar_counter];
      tr0.width = rectangles_array2[haar_counter];
      tr0.y = rectangles_array1[haar_counter];
      tr0.height = rectangles_array3[haar_counter];

      tr1.x = rectangles_array4[haar_counter];
      tr1.width = rectangles_array6[haar_counter];
      tr1.y = rectangles_array5[haar_counter];
      tr1.height = rectangles_array7[haar_counter];

      tr2.x = rectangles_array8[haar_counter];
      tr2.width = rectangles_array10[haar_counter];
      tr2.y = rectangles_array9[haar_counter];
      tr2.height = rectangles_array11[haar_counter];

      /* Calculates addresses/locations of all the 12 co-ordinates */
      addr_list[ 0] =  tr0.y    *25+ tr0.x;
      addr_list[ 1] =  tr0.y    *25+tr0.x+tr0.width;
      addr_list[ 2] = (tr0.y+tr0.height)*25+tr0.x;
      addr_list[ 3] = (tr0.y+tr0.height)*25+tr0.x+tr0.width;
      addr_list[ 4] =  tr1.y    *25+tr1.x;
      addr_list[ 5] =  tr1.y    *25+tr1.x+tr1.width;
      addr_list[ 6] = (tr1.y+tr1.height)*25+tr1.x;
      addr_list[ 7] = (tr1.y+tr1.height)*25+tr1.x+tr1.width;


      if (!(tr2.x ==0 && tr2.width==0 && tr2.y==0 && tr2.height==0 ) && tr2.width!=0 && tr2.height!=0)
      {

        addr_list[ 8] =  tr2.y    *25+tr2.x;
        addr_list[ 9] =  tr2.y    *25+tr2.x+tr2.width;
        addr_list[10] = (tr2.y+tr2.height)*25+tr2.x;
        addr_list[11] = (tr2.y+tr2.height)*25+tr2.x+tr2.width;
        enable_list[ 8] = 1;
        enable_list[ 9] = 1;
        enable_list[10] = 1;
        enable_list[11] = 1;

        }
        else
        {
          addr_list[ 8] =  addr_list[0];
          addr_list[ 9] =  addr_list[1];
          addr_list[10] =  addr_list[2];
          addr_list[11] =  addr_list[3];
          enable_list[ 8] = 0;
          enable_list[ 9] = 0;
          enable_list[10] = 0;
          enable_list[11] = 0;

        }

        /* Read the values corresponding to the 12 locations from _II which is the copy of integral image window */
        get_all_data(values, addr_list, _II);

  	for ( k = 0; k < 12; k++ ){
	  if ( enable_list[k] == 0 )
            coord[k] = 0;
 	  else
	    coord[k] = values[k];
        }

        s = weakClassifier      ( stddev,
                                  coord,
                                  haar_counter,
                                  w_id
                                );

        stage_sum = stage_sum + s;
        haar_counter = haar_counter+1;
        w_index = w_index+3;
        r_index = r_index+12;

    } /* end of j loop */
    if( stage_sum < 0.4*stages_thresh_array[i] ){
    	*result =  -i;
    	return;
    }
  } /* end of i loop */
 *result = 1;
 return;
}


int weakClassifier
(
  int stddev,
  uint18_t coord[12],  
  int haar_counter,
  int w_id 
)
{
  /* weights and threshold values for various classifiers */
                                                                                             
  #include "haar_dataEWC_with_partitioning.h"
  # pragma HLS INLINE

  int t = tree_thresh_array[haar_counter] * stddev; 
  
  int sum0 =0;
  int sum1 =0;
  int sum2 =0;
  int final_sum =0;
  int return_value;
	             
  sum0 = (coord[0] - coord[1] - coord[2] + coord[3]) * weights_array0[haar_counter];
  sum1 = (coord[4] - coord[5] - coord[6] + coord[7]) * weights_array1[haar_counter];  
  sum2 = (coord[8] - coord[9] - coord[10] + coord[11]) * weights_array2[haar_counter];
  final_sum = sum0+sum1+sum2;
  
  if(final_sum >= t) 
    return_value =  alpha2_array[haar_counter];  
  else   
    return_value =  alpha1_array[haar_counter];
  
  return return_value ; 
}


void imageScaler
(
  unsigned char inData[IMAGE_HEIGHT*IMAGE_WIDTH+1],
  unsigned char IMG1_data[IMAGE_HEIGHT][IMAGE_WIDTH]
)
{
#pragma HLS INTERFACE ap_hs port=inData
#pragma HLS INTERFACE ap_hs port=IMG1_data

  static unsigned char Data[IMAGE_HEIGHT][IMAGE_WIDTH];
  int y;
  int j;
  int x;
  int i;
  unsigned char* t;
  unsigned char* p;
  unsigned char LoadOrScale;
  static int w1 = IMAGE_WIDTH;
  static int h1 = IMAGE_HEIGHT;
  static int w2 = IMAGE_WIDTH;
  static int h2 = IMAGE_HEIGHT;
  static float factor = 1.2;
  int rat = 0;
  float  scaleFactor = 1.2;

  int x_ratio = 0;
  int y_ratio = 0;
  LoadOrScale = inData[0];

  if (LoadOrScale){
    for( i = 0; i < IMAGE_HEIGHT; i++){
      for( j = 0; j < IMAGE_WIDTH; j++){
    	  Data[i][j] = inData[i*IMAGE_WIDTH+j+1];
      }
    }
    return;
  }
  factor = factor*1;
  MySize sz = { (int)( IMAGE_WIDTH/factor ), (int)( IMAGE_HEIGHT/factor ) };
  w2 = sz.width;
  h2 = sz.height;

  factor *= scaleFactor;
  //printf("---%d, %d, %d, %d\n", w1, h1, w2, h2);

  x_ratio = (int)((w1<<16)/w2) +1;
  y_ratio = (int)((h1<<16)/h2) +1;




  imageScalerL1: for ( i = 0 ; i < IMAGE_HEIGHT ; i++ ){ 
    imageScalerL1_1: for (j=0;j < IMAGE_WIDTH ;j++){
      #pragma HLS pipeline
      if ( j < w2 && i < h2 ) 
        IMG1_data[i][j] =  Data[(i*y_ratio)>>16][(j*x_ratio)>>16];
       
    }
  }
}

unsigned int int_sqrt 
( 
  ap_uint<32> value
)
{
  int i;
  unsigned int a = 0, b = 0, c = 0;

  for ( i = 0 ; i < (32 >> 1) ; i++ )
  {
    #pragma HLS unroll
    c<<= 2;   
    #define UPPERBITS(value) (value>>30)
    c += UPPERBITS(value);
    #undef UPPERBITS
    value <<= 2;
    a <<= 1;
    b = (a<<1) | 1;
    if ( c >= b )
    {
      c -= b;
      a++;
    }
  }
  return a;
}

int max
(
  int a,
   int b
)
{
 if ( a > b )
   return a;
 else 
   return b;
}

int min
(
  int a,
  int b
)
{
  if ( a < b )
    return a;
  else 
    return b;
}

