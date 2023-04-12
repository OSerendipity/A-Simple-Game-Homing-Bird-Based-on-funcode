/////////////////////////////////////////////////////////////////////////////////
//
//
//
//
/////////////////////////////////////////////////////////////////////////////////
#ifndef _VIRUSPLANE_H_
#define _VIRUSPLANE_H_

#include "scenseX.h"
#include <Windows.h>

#define MAX_NAME_LEN  128
#define CONTROL_MAX_HP 1000
#define BULLET_DAMAGE_1 100
#define VER_MIN_CREATE 1
#define VER_MAX_CREATE 6

extern int g_iCreatedSpriteCount;
extern bool  g_bControlCanFire;
extern int g_iMaxScore;
extern float  g_fVerCreateTime;

enum ESpriteType
{
    SPRITE_CONTROL,
    SPRITE_VER,
    SPRITE_BULLET1,
    SPRITE_BULLET2,
     SPRITE_BULLET3,
      SPRITE_BULLET4,
    SPRITE_BIG_BOSS,
    SPRITE_SNAKE,
    SPRITE_HEALTH
};

extern struct SGameSprite
{
    char szName[MAX_NAME_LEN];
    int iHp;
    int iScore;
    int iDamage;
    ESpriteType eSpriteType;
    int iBulletType;
    float fFireAfterCreate;
    float fBulletTime;
    float fBulletTime2;
    float fFloatTime;
    bool bFloatUp;
}mstructure;

extern void	GameMainLoop( float	fDeltaTime );
extern void OnMouseMove( const float fMouseX, const float fMouseY );
extern void OnMouseClick( const int iMouseType, const float fMouseX, const float fMouseY );
extern void OnMouseUp( const int iMouseType, const float fMouseX, const float fMouseY );
extern void OnKeyDown( const int iKey, const bool bAltPress, const bool bShiftPress, const bool bCtrlPress );
extern void OnKeyUp( const int iKey );
extern void OnSpriteColSprite( const char *szSrcName, const char *szTarName );
extern void OnSpriteColWorldLimit( const char *szName, const int iColSide );


extern void InitTemplateData();
extern void virusinit();
extern void virusrun(float fDeltaTime);
extern void UpdateMovement();
extern void movespriteFlipset();
extern void virusspritecolsprite(const char *szSrcName, const char *szTarName);
extern void virusworldlimit( const char *szName, const int iColSide);
#endif
