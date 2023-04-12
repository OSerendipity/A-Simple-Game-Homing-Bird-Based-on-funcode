#include "CommonAPI.h"
#include"virusplane.h"
#include "List.h"
#include<stdio.h>

int cao=0;
int g_iCreatedSpriteCount=0;
bool  g_bControlCanFire;
int g_iMaxScore=0;
float  g_fVerCreateTime = 2.f;

SGameSprite g_ControlSprite;
SGameSprite g_Bullet1Template;
SGameSprite g_Bullet2Template;
SGameSprite g_VerTemplate;
SGameSprite g_firepea0;
SGameSprite g_cactus20;

void        CreateVerTick( float fDeltaTime );
void        VerLoopTick( SGameSprite *pSprite, float fDeltaTime );
bool        IsGameLost();
bool        IsDead( SGameSprite *pSprite );

void InitTemplateData()
{
    strcpy( g_ControlSprite.szName, "WaterDrop" );
    g_ControlSprite.iHp     = CONTROL_MAX_HP;
    g_ControlSprite.iScore    = 0;
    g_ControlSprite.iDamage   = 500;
    g_ControlSprite.eSpriteType   = SPRITE_CONTROL;
    g_ControlSprite.iBulletType   = 0;
    g_ControlSprite.fFireAfterCreate  = 0.f;
    g_ControlSprite.fBulletTime   = 0.3f;
    g_ControlSprite.fBulletTime2   = 0.f;
    g_ControlSprite.fFloatTime   = 0.f;
    g_ControlSprite.bFloatUp   = true;
    //
    strcpy( g_VerTemplate.szName, "VerTemplate" );
    g_VerTemplate.szName[0]   = '\0';
    g_VerTemplate.iHp     = 100;
    g_VerTemplate.iScore    = 50;
    g_VerTemplate.iDamage    = 500;
    g_VerTemplate.eSpriteType   = SPRITE_VER;
    g_VerTemplate.iBulletType   = 0;
    g_VerTemplate.fFireAfterCreate  = 1.f;
    g_VerTemplate.fBulletTime   = 2.f;
    g_VerTemplate.fBulletTime2   = 0.f;
    g_VerTemplate.fFloatTime   = 0.f;
    g_VerTemplate.bFloatUp   = true;
    //
    strcpy( g_Bullet1Template.szName, "Bullet1Template" );
    g_Bullet1Template.szName[0]  = '\0';
    g_Bullet1Template.iHp    = 1;
    g_Bullet1Template.iScore   = 10;
    g_Bullet1Template.iDamage   = 0;
    g_Bullet1Template.eSpriteType  = SPRITE_BULLET1;
    g_Bullet1Template.iBulletType  = 0;
    g_Bullet1Template.fFireAfterCreate = 0.f;
    g_Bullet1Template.fBulletTime  = 0.0f;
    g_Bullet1Template.fBulletTime2  = 0.f;
    g_Bullet1Template.fFloatTime  = 0.f;
    g_Bullet1Template.bFloatUp   = true;
    //2
    strcpy( g_Bullet2Template.szName, "Bullet2Template" );
    g_Bullet1Template.szName[0]  = '\0';
    g_Bullet1Template.iHp    = 1;
    g_Bullet1Template.iScore   = 10;
    g_Bullet1Template.iDamage   = 0;
    g_Bullet1Template.eSpriteType  = SPRITE_BULLET2;
    g_Bullet1Template.iBulletType  = 0;
    g_Bullet1Template.fFireAfterCreate = 0.f;
    g_Bullet1Template.fBulletTime  = 0.0f;
    g_Bullet1Template.fBulletTime2  = 0.f;
    g_Bullet1Template.fFloatTime  = 0.f;
    g_Bullet1Template.bFloatUp   = true;

}

void virusinit()
{
    dSetSpriteColorGreen( g_ControlSprite.szName, 255 );
    dSetSpriteColorBlue( g_ControlSprite.szName, 255 );
    GList_DeleteAllSprite();
    g_bControlCanFire=false;
    g_fVelocityLeft  = 0.f;
    g_fVelocityRight = 0.f;
    g_fVelocityUp  = 0.f;
    g_fVelocityDown  = 0.f;
    g_fVerCreateTime = 2.f;
    g_ControlSprite.iHp   = CONTROL_MAX_HP;
    g_ControlSprite.iScore  = 0;
    g_ControlSprite.fBulletTime = 0.3f;
    InitTemplateData();
}


SGameSprite *CreateBullet1( const int iBulletType, const float fPosX, const float fPosY )
{
    SGameSprite *pSprite = (SGameSprite*)malloc( sizeof(SGameSprite) );
    memcpy( pSprite, &g_Bullet1Template, sizeof(SGameSprite) );
    sprintf( pSprite->szName, "Bullet1_%d", g_iCreatedSpriteCount++ );
    pSprite->iDamage  = BULLET_DAMAGE_1;
    pSprite->iBulletType = iBulletType;
    GList_AddSprite( pSprite );
    dCloneSprite( "Bullet1_Template", pSprite->szName );
    dSetSpritePosition( pSprite->szName, fPosX, fPosY );
    if( 1 == iBulletType )
    {
        if(g_iCurLevel==5||g_iCurLevel==6)
            dSetSpriteLinearVelocityX( pSprite->szName, 30.f );
        if(g_iCurLevel==7||g_iCurLevel==8)
            dSetSpriteLinearVelocityX( pSprite->szName, -30.f );
    }
    dSetSpriteWorldLimit( pSprite->szName, WORLD_LIMIT_NULL, g_fWorldLeft,g_fWorldTop, g_fWorldRight, g_fWorldBottom );
    return pSprite;
    free(pSprite);
}


SGameSprite *CreateBullet2( const int iBulletType, const float fPosX, const float fPosY )
{

    SGameSprite *pSprite = (SGameSprite*)malloc( sizeof(SGameSprite) );
    memcpy( pSprite, &g_Bullet1Template, sizeof(SGameSprite) );
    sprintf( pSprite->szName, "Bullet2_%d", g_iCreatedSpriteCount++ );
    pSprite->iDamage  = BULLET_DAMAGE_1;
    pSprite->iBulletType = iBulletType;
    GList_AddSprite( pSprite );
    dCloneSprite( "Bullet2_Template", pSprite->szName );
    dSetSpritePosition( pSprite->szName, fPosX, fPosY );
     if( 1 != iBulletType )
    {
        if(dGetSpriteFlipX("WaterDrop")==0)
            dSetSpriteLinearVelocityX( pSprite->szName, 60.f );
        else
            dSetSpriteLinearVelocityX( pSprite->szName,-60.f );
    }
    dSetSpriteWorldLimit( pSprite->szName, WORLD_LIMIT_NULL, g_fWorldLeft,g_fWorldTop, g_fWorldRight, g_fWorldBottom );
    return pSprite;
    free(pSprite);
}

void virusrun(float fDeltaTime)
{
    g_ControlSprite.fBulletTime -= fDeltaTime;
    if(g_ControlSprite.fBulletTime < 0 && g_bControlCanFire)
    {
        g_ControlSprite.fBulletTime = 0.3;
        CreateBullet2( 0, dGetSpritePositionX( g_ControlSprite.szName ),dGetSpritePositionY( g_ControlSprite.szName ) );
    }
    CreateVerTick(fDeltaTime);
    int iListSize = GList_GetListSize();
    int iLoop  = 0;
    for( iLoop = 0; iLoop < iListSize; iLoop++ )
    {
        SGameSprite *pSprite = GList_GetSpriteByIndex( iLoop );
        if( NULL != pSprite )
        {
            switch( pSprite->eSpriteType )
            {
            case SPRITE_VER:
                VerLoopTick( pSprite, fDeltaTime );
                break;
            };
        }
    }
}

void movespriteFlipset()
{
    if((g_fVelocityLeft + g_fVelocityRight) > 0)
    {
        dSetSpriteFlipX("WaterDrop", false);
    }

    else if((g_fVelocityLeft + g_fVelocityRight) < 0)
    {
        dSetSpriteFlipX("WaterDrop", true);
    }
    dSetSpriteLinearVelocity("WaterDrop",g_fVelocityLeft + g_fVelocityRight, g_fVelocityUp +g_fVelocityDown);
}

bool IsDead( SGameSprite *pSprite )
{
    return ( NULL != pSprite && pSprite->iHp <= 0 );
}

bool IsControlSprite( const char *szName )
{
    return ( strcmp( g_ControlSprite.szName, szName ) == 0 );
}

bool IsBullet1Sprite( const char *szName )
{
    return ( strstr( g_Bullet1Template.szName, szName ) !=NULL );
}

bool IsControlSpriteBullet( SGameSprite *pSprite )
{
    if( NULL != pSprite )
    {
        if( SPRITE_BULLET1 == pSprite->eSpriteType || SPRITE_BULLET2 == pSprite->eSpriteType )
            return ( 0 == pSprite->iBulletType );
    }
    return false;
}

void EnemyColOther( SGameSprite *pEnemy, SGameSprite *pOther )
{
    if( NULL == pOther || NULL == pEnemy )
        return;
    if( IsControlSpriteBullet( pOther ) || SPRITE_CONTROL == pOther->eSpriteType )
    {
        pEnemy->iHp -= pOther->iDamage;
        if( IsDead( pEnemy ) )
        {
            if( SPRITE_BIG_BOSS == pEnemy->eSpriteType )
                {
                    dPlayEffect("bigExplode",3.f, dGetSpritePositionX(pEnemy->szName), dGetSpritePositionY(pEnemy->szName), 0.f );
                }

            else
            {
                dPlayEffect("enemyExplode",3.f, dGetSpritePositionX(pEnemy->szName), dGetSpritePositionY(pEnemy->szName), 0.f );
                dPlaySound("baozha.wav",0,1);
            }

        }
    }
}


void Bullet1ColOther( SGameSprite *pBullet, SGameSprite *pOther )
{
    if( NULL == pOther || NULL == pBullet )
        return;
    if( IsControlSpriteBullet( pBullet ) )
    {
        if( SPRITE_BULLET2 == pOther->eSpriteType || SPRITE_CONTROL == pOther->eSpriteType )
            return;
        pBullet->iHp -= pOther->iDamage;
        dPlayEffect( "smallExplosion", 1.0, dGetSpritePositionX(pBullet->szName),dGetSpritePositionY(pBullet->szName), 0.f );
        g_ControlSprite.iScore += pOther->iScore;
        dPlaySound("baozha.wav",0,1);
        dSetTextValue( "CurScoreText", g_ControlSprite.iScore );
    }  // 敌方子弹
    else
    {
        if(SPRITE_CONTROL==pOther->eSpriteType|| IsControlSpriteBullet( pOther ) )
        {
            pBullet->iHp -= pOther->iDamage;
            dPlayEffect("smallExplosion", 1.0, dGetSpritePositionX(pBullet->szName), dGetSpritePositionY(pBullet->szName), 0.f );
        }
    }
}

void Bullet2ColOther( SGameSprite *pBullet, SGameSprite *pOther )
{
    if( NULL == pOther || NULL == pBullet )
        return;
    if( IsControlSpriteBullet( pBullet ) )
    {
        if( SPRITE_BULLET1 == pOther->eSpriteType || SPRITE_CONTROL == pOther->eSpriteType )
            return;
        pBullet->iHp -= pOther->iDamage;
        dPlayEffect( "smallExplosion", 1.0, dGetSpritePositionX(pBullet->szName),dGetSpritePositionY(pBullet->szName), 0.f );
        g_ControlSprite.iScore += pOther->iScore;
        dPlaySound("baozha.wav",0,1);
        dSetTextValue( "CurScoreText", g_ControlSprite.iScore );
    }
    else
    {
        if(SPRITE_CONTROL==pOther->eSpriteType|| IsControlSpriteBullet( pOther ) )
        {
            pBullet->iHp -= pOther->iDamage;
            dPlayEffect("smallExplosion", 1.0, dGetSpritePositionX(pBullet->szName), dGetSpritePositionY(pBullet->szName), 0.f );
        }
    }
}

void ControlColOther( SGameSprite *pControl, SGameSprite *pOther )
{
    if( NULL == pOther || NULL == pControl )
        return;
    if( IsControlSpriteBullet( pOther ) )
        return;
    int iHp = 0;
        pControl->iHp -= pOther->iDamage;
        if( pControl->iDamage >= pOther->iHp )
        {
              hp--;
             dSetTextValue("hp1",hp);
            pControl->iScore += pOther->iScore;
        }
    dSetTextValue( "CurScoreText", pControl->iScore );
}

void virusspritecolsprite(const char *szSrcName, const char *szTarName)
{
    SGameSprite *pSrcSprite = IsControlSprite( szSrcName ) ? &g_ControlSprite :    GList_GetSpriteByName( szSrcName );
    SGameSprite *pTarSprite = IsControlSprite( szTarName ) ? &g_ControlSprite :    GList_GetSpriteByName( szTarName );
    if( NULL == pSrcSprite || NULL == pTarSprite )
        return;
    if( SPRITE_CONTROL == pSrcSprite->eSpriteType )
        ControlColOther( pSrcSprite, pTarSprite );
    else if( SPRITE_BULLET1 == pSrcSprite->eSpriteType )
        Bullet1ColOther( pSrcSprite, pTarSprite );
    else if( SPRITE_BULLET2 == pSrcSprite->eSpriteType )
        Bullet2ColOther( pSrcSprite, pTarSprite );
    else
        EnemyColOther( pSrcSprite, pTarSprite );


    // Tar 碰撞--> Src
    if( SPRITE_CONTROL == pTarSprite->eSpriteType )
        ControlColOther( pTarSprite, pSrcSprite );
    else if( SPRITE_BULLET1 == pTarSprite->eSpriteType )
        Bullet1ColOther( pTarSprite, pSrcSprite );
    else if( SPRITE_BULLET2 == pTarSprite->eSpriteType )
        Bullet2ColOther( pTarSprite, pSrcSprite );
    else
        EnemyColOther( pTarSprite, pSrcSprite );
    // 死亡判断，死亡之后删除该 Sprite。
    if( SPRITE_CONTROL != pSrcSprite->eSpriteType )
    {
        if( IsDead( pSrcSprite ) )
            GList_DeleteSprite( pSrcSprite, true );
    }
    if( SPRITE_CONTROL != pTarSprite->eSpriteType )
    {
        if( IsDead( pTarSprite ) )
            GList_DeleteSprite( pTarSprite, true );
    }
}

void virusworldlimit( const char *szName, const int iColSide)
{
    if(strstr(szName, "Bullet")!=NULL)
    {
        SGameSprite *pSzSprite = IsBullet1Sprite( szName ) ? &g_Bullet1Template :    GList_GetSpriteByName( szName );
        if(iColSide == 1)  // 右边
        {
            GList_DeleteSprite( pSzSprite, true );
            dDeleteSprite(szName);
        }
        else if(iColSide == 0)   // 左边
        {
            GList_DeleteSprite( pSzSprite, true );
            dDeleteSprite(szName);
        }
    }
}

void CreateVerTick( float fDeltaTime )
{
    // 是否到时间创建
    g_fVerCreateTime -= fDeltaTime;
    if( g_fVerCreateTime <= 0.f )
    {
        g_fVerCreateTime = (float)dRandomRange( 5, 10 ) ;
        int iPosBase = dRandomRange((int)g_fWorldTop + 5, (int)g_fWorldTop + 25);
        // 随机数量
        int iCount ;
        if(g_iCurLevel==8)
            iCount = dRandomRange( VER_MIN_CREATE, VER_MAX_CREATE );
        else
         iCount = 1;
        for( int iLoop = 0; iLoop < iCount; iLoop++ )
        {
            SGameSprite *pSprite=(SGameSprite*)malloc( sizeof(SGameSprite) );
            memcpy( pSprite, &g_VerTemplate, sizeof(SGameSprite) );
            sprintf(pSprite->szName,"VerticalSprite_%d",g_iCreatedSpriteCount++ );
            pSprite->fFloatTime=(float)dRandomRange(0, 10) / 10.f;
            pSprite->bFloatUp=dRandomRange(0,1) == 1 ? true : false;
            dCloneSprite( "VerticalSprite_Template", pSprite->szName );
            GList_AddSprite( pSprite );
            int iRandom =dRandomRange((int)g_fWorldRight, (int)g_fWorldRight );
            float fPosY = g_fWorldTop+ 20.f * iLoop+ iPosBase ;
            dSetSpritePosition( pSprite->szName, (float)iRandom, fPosY );
            dSetSpriteLinearVelocityX( pSprite->szName, -10.f );
            dSetSpriteWorldLimit(pSprite->szName,WORLD_LIMIT_NULL,g_fWorldLeft,g_fWorldTop,g_fWorldRight, g_fWorldBottom );
        }
    }
}



void VerLoopTick( SGameSprite *pSprite, float fDeltaTime )
{
    pSprite->fFireAfterCreate -= fDeltaTime;
    if( pSprite->fFireAfterCreate <= 0.f )
    {
        pSprite->fBulletTime -= fDeltaTime;
        if( pSprite->fBulletTime <= 0.f )
        {
            // 子弹时间固定
            pSprite->fBulletTime = g_VerTemplate.fBulletTime;
            if(g_iCurLevel==7)
            {
                if(islivecactus21)
                CreateBullet1(1,dGetSpritePositionX("cactus21")-5.f,dGetSpritePositionY("cactus21") );
                if(islivecactus20)
                CreateBullet1(1,dGetSpritePositionX("cactus20")-5.f,dGetSpritePositionY("cactus20") );
            }
            else if(g_iCurLevel==8&&(dGetSpritePositionX(pSprite->szName)||dGetSpritePositionY(pSprite->szName)))
            {
                CreateBullet1(1,dGetSpritePositionX(pSprite->szName),dGetSpritePositionY(pSprite->szName) );
            }
            if(g_iCurLevel==5&&islivefirepea0)
            {
                  CreateBullet1(1,dGetSpritePositionX("firepea0")+5.f,dGetSpritePositionY("firepea0") );
                  cao=1;
            }
            else if(g_iCurLevel==6&&islivefirepea1)
            {
                if(cao)
                CreateBullet1(1,dGetSpritePositionX("firepea1")+5.f,dGetSpritePositionY("firepea1") );
                else if(cao==0&&islivefirepea1just)
                {
                    CreateBullet1(1,dGetSpritePositionX("firepea0")+5.f,dGetSpritePositionY("firepea0") );
                }

            }
        }
    }
    if( pSprite->bFloatUp )
    {
        // 上漂
        pSprite->fFloatTime += fDeltaTime;
        if( pSprite->fFloatTime >= 1.f )
        {
            pSprite->bFloatUp = false;
        }
        float fPosY = dGetSpritePositionY(pSprite->szName);
        fPosY   += 6.f * fDeltaTime;
        dSetSpritePositionY( pSprite->szName, fPosY );
    }
    else
    {
        // 下漂
        pSprite->fFloatTime -= fDeltaTime;
        if( pSprite->fFloatTime <= 0.f )
        {
            pSprite->bFloatUp = true;
        }
        float fPosY = dGetSpritePositionY(pSprite->szName);
        fPosY   -= 6.f * fDeltaTime;
        dSetSpritePositionY( pSprite->szName, fPosY );
    }

}

