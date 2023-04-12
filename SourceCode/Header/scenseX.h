/////////////////////////////////////////////////////////////////////////////////
//
//
//
//
/////////////////////////////////////////////////////////////////////////////////
#ifndef _SCENSE_X_H_
#define _SCENSE_X_H_
//

#include <Windows.h>


#define GRID_COUNTROW 15
#define GRID_COUNTCOL 20 // N * N 的矩阵方块,一个 N 的大小
#define MAX_LEVEL 8 // 最大关卡数量。如果要增加关卡，请先修改此值

// 以下 3 个分别为方块阻挡物、黑洞、出口的值
#define RIGID_BLOCK 1//
#define BLACK_HOLE 2//
#define EXIT 3//
//choose
#define HEART 4
#define MUSHROOM 5
#define GRASS 6
#define FIRETREE 7
#define COIN 8
//
//第二关
#define SPIDER 9
#define MUSHROOM_TWO 10
#define BLOCK_BAR 11
#define BLOCK 12
#define POTION 13
#define VIRUS 14
#define JUMP_BLOCK 15
//第三关
#define BLESS 16
#define MAGMA 17
#define ENTER2 117
#define ENTER3 18
#define FIREPEA 19
#define LONGBLOCKBAR 20
#define BARBASE 21
//four
#define CLOUDA 22
#define CLOUDA1 23
#define CLOUDA2 24
#define CLOUDA3 25
#define CLOUDB 26
#define CLOUDB1 27
#define CLOUDB2 28
#define CACTUS1 29
#define CACTUS2 30
#define EXIT1 31
#define EXIT2 32
#define SNAKE 33
#define FIRECIRCLE 34
#define SNAKE2 35

extern float  g_fWorldLeft ;
extern float  g_fWorldRight ;
extern float  g_fWorldTop ;
extern float  g_fWorldBottom ;

extern float  g_fVelocityLeft ;
extern float  g_fVelocityRight ;
extern float  g_fVelocityUp ;
extern float  g_fVelocityDown ;

extern int g_iGameState;
extern int g_iMoveState;

extern int g_iCurLevel;

extern const float  g_fGridStartX;
extern const float g_fGridStartY;
extern const float g_fGridSize;

extern int g_iRigidBlockCount ;
extern int  g_iExitCount;



extern int g_iGridData[GRID_COUNTROW][GRID_COUNTCOL];
extern int iControlStartX,iControlStartY ;
extern float countdown;

extern int hp;
extern int n;
extern int jump;
extern int coin;
extern int g_iheartCount;
extern int g_imushroomCount;
extern int g_igrassCount;
extern int g_ifiretreeCount;
extern int g_icoinCount;
extern int coindeletecount;
//two
extern int g_ispiderCount ;
extern int g_imushroom2Count;
extern int g_iblockbarCount;
extern int g_iblockCount;
extern int g_ivirusCount;
extern int g_ipotionCount;
extern int g_ijumpblockCount;

extern int g_iblockbarToLeft;
extern float g_fblockbarRotation;
extern int iblockbarstart0;
extern int iblockbarstart1;
//three
extern int g_iblessCount;
extern int g_imagmaCount;
extern int g_ienter2Count;
extern int g_ienter3Count;
extern int g_ifirepeaCount;
extern int g_ilongblockbarCount;
extern int g_ibarbaseCount;

extern int ilongblockbarstart;
extern int g_ilongblockbarToLeft;
extern float g_flongblockbarRotation;
//
extern int g_icloudaCount;
extern int g_iclouda1Count;
extern int g_iclouda2Count;
extern int g_iclouda3Count;
extern int g_icloudbCount;
extern int g_icloudb1Count;
extern int g_icloudb2Count;
extern int g_icactus1Count;
extern int g_icactus2Count;
extern int g_icoinCount;
extern int g_iexit1Count;
extern int g_iexit2Count;
extern int g_isnakeCount;
extern int g_isnake2Count;
extern int g_ifirecircleCount;
//
extern int islivefirepea0;
extern int islivefirepea1;
extern int islivefirepea1just;
extern int islivecactus20;
extern int islivecactus21;
extern int islivesnake11;

extern int islivesnake12;
extern int islivesnake22;
extern int islivefiretree;
extern int islivemushrooom2;
extern int islivespider;

extern void GameInit();
extern void	GameMainLoop( float	fDeltaTime );
extern void OnMouseMove( const float fMouseX, const float fMouseY );
extern void OnMouseClick( const int iMouseType, const float fMouseX, const float fMouseY );
extern void OnMouseUp( const int iMouseType, const float fMouseX, const float fMouseY );
extern void OnKeyDown( const int iKey, const bool bAltPress, const bool bShiftPress, const bool bCtrlPress );
extern void OnKeyUp( const int iKey );
extern void OnSpriteColSprite( const char *szSrcName, const char *szTarName );
extern void OnSpriteColWorldLimit( const char *szName, const int iColSide );

extern void MoveSpriteToBlock( const char *szName, const int iIndexX, const int iIndexY );
extern int SpritePosXToIndexX ( const float fPosX ) ;
extern int SpritePosYToIndexY( const float fPosY ) ;
extern int SpriteIndexXToPosX(int iIndexX);
extern int SpriteIndexYToPosY( int iIndexY );
extern void coljugde();
extern void MapSet();
extern void SpriteColSet0();
extern void ClsPreSprite0();
extern void SpriteHPset(float fDeltaTime);


extern const int m_iLevelData11[GRID_COUNTROW][GRID_COUNTCOL];
extern const int m_iLevelData12[GRID_COUNTROW][GRID_COUNTCOL];
extern const int m_iLevelData21[GRID_COUNTROW][GRID_COUNTCOL];
extern const int m_iLevelData22[GRID_COUNTROW][GRID_COUNTCOL];
extern const int m_iLevelData31[GRID_COUNTROW][GRID_COUNTCOL];
extern const int m_iLevelData32[GRID_COUNTROW][GRID_COUNTCOL];
extern const int m_iLevelData41[GRID_COUNTROW][GRID_COUNTCOL];
extern const int m_iLevelData42[GRID_COUNTROW][GRID_COUNTCOL];
extern void MakeInitSprite1();
extern void MakeInitSprite2();
extern void MakeInitSprite3();
extern void MakeInitSprite4();

extern void coljugde1(int iIndexX,int iIndexY);
extern void coljugde2(int iIndexX,int iIndexY);
extern void coljugde3(int iIndexX,int iIndexY);
extern void coljugde4(int iIndexX,int iIndexY);

extern void SpriteColSet1();
extern void ClsPreSprite1();
extern void SpriteColSet2();
extern void ClsPreSprite2();
extern void SpriteColSet3();
extern void ClsPreSprite3();
extern void SpriteColSet4();
extern void ClsPreSprite4();
extern void OnSpriteColSprite1( const char *szSrcName, const char *szTarName );
extern void OnSpriteColSprite2( const char *szSrcName, const char *szTarName );
extern void OnSpriteColSprite3( const char *szSrcName, const char *szTarName );
extern void OnSpriteColSprite4( const char *szSrcName, const char *szTarName );
//guanqia2
extern void OnfiretreeWorldLimit( const char *szName, const int iColSide );
extern void OnspiderWorldLimit( const char *szName, const int iColSide );
extern void OnsnakeWorldLimit( const char *szName, const int iColSide );
extern void OnotherWorldLimit( const char *szName, const int iColSide );
//
extern void left_and_rightmove(const char *szName,int x,int y);
extern void up_and_rightmove(const char *szName,int x,int y,int z,int w);
extern void Onclouda1WorldLimit( const char *szName, const int iColSide );
extern void Oncloudb2WorldLimit( const char *szName, const int iColSide );
extern void clouda3upright(const char *szName, const int iColSide );
extern void blockbarRotation(float fDeltaTime);
//3
extern void longblockbarRotation(float fDeltaTime);
#endif
