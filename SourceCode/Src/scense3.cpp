#include "CommonAPI.h"
#include "scenseX.h"
#include<stdio.h>
int g_iblessCount =0;
int g_imagmaCount=0;
int g_ienter2Count=0;
int g_ienter3Count=0;
int g_ifirepeaCount=0;
int g_ilongblockbarCount=0;
int g_ibarbaseCount=0;
int islivefirepea0=1;
int islivefirepea1=1;
int islivefirepea1just=1;
int ilongblockbarstart=0;
int g_ilongblockbarToLeft=0;
float g_flongblockbarRotation=0;
int f5=0;
const int m_iLevelData31[GRID_COUNTROW][GRID_COUNTCOL]=
{
    {          0,     0,           0,           0,           0,           0,           0,          0,           0,          0,           0,          0,           0,          0,          0,           0,    0,    0,ENTER2,    0},
    {          0,     0,           0,           0,           0,           0,           0,          RIGID_BLOCK, 0,          RIGID_BLOCK,           0,          0,           0,          0,          0,           0,    0,    0,BLOCK,    0},
    {          0,     0,           0,           0,           0,           0,           0,          0,       BLOCK,          0,           0,          0,           0,          0,          0,           0,    0,    0,BLOCK,    0},
    {          0,     0,           0,           0,           0,           0,           0,      BLOCK,       BLOCK,          0,           0,          0,           0,          0,          0,           0,    0,    0,BLOCK,    0},
    {          0,     0,           0,           0,       BLOCK,           0,           0,      BLOCK,           0,          0,       BLOCK,          0,           0,       MAGMA,          0,           0, MAGMA,    MAGMA,    BLOCK,BLOCK},
    {      HEART,     0,           0,           0,           0,           0,           0,          0,           0,          0,           0,          0,           0,          0,          0,           0,    0,    0,    0,    0},
    {      BLOCK,     0,           0,           0,           0,           0,           0,          0,           0,          0,           0,          0,           0,          0,          0,           0,    0,    0,    0,    0},
    {          0, BLOCK,           0,           0,           0,           0,     FIREPEA,          0,           0,          BLESS,           0,          0,           0,          0,          0,           0,    0,    0,    0,    0},
    {      BLOCK,     0,           0,       BLOCK,           0,           0,       BLOCK,          0,           0,      BLOCK,           0,      MAGMA,           0,      BLOCK,          0,       BLOCK,    0,    0,    0,    0},
    {          0,     0,           0,           0,           0,           0,           0,          0,           0,          0,           0,          0,           0,          0,          0,           0,    0,    0,    0,    0},
    {          0,     0,           0,           0,           0,       0,           0,          0,           0,          0,           0,          0,           0,          0,          0,           0,    0,    0,    0,BLOCK},
    {          0,     0,           0,           0,       0,           0,           0,      0,           0,          BLOCK,           0,          0,           0,          0,          0,           0,    0,    0,BLOCK,    0},
    {         0,     RIGID_BLOCK,           0,           0,           0,           0,           0,          0,           0,          0,           BLESS,         RIGID_BLOCK,           0,          0,          0,           0,    0,BLOCK,    0,BLOCK},
    {          0, BLOCK,           0,           0,       MAGMA,           0,           0,      MAGMA,           0,          0,       BLOCK,          0,           0,      MAGMA,          0,       MAGMA,MAGMA,    BLOCK,    0,BLOCK},
    {          0, BLOCK,           0,           0,       BLOCK,           0,           0,      BLOCK,           0,          0,       BLOCK,          0,           0,      BLOCK,          0,           0,BLOCK,    0,    0,BLOCK}
};

const int m_iLevelData32[GRID_COUNTROW][GRID_COUNTCOL]=
{
    {          0,     0,           0,           0,           0,           0,           0,          0,           0,          0,           0,          0,           RIGID_BLOCK,          0,          0,           0,     0,    0,    0,    0},
    {          0, BLOCK,           0,           0,       BLOCK,           0,           0,      BLOCK,           0,          0,           0,          0,           0,      BLOCK,          0,       BLOCK,    0,    0,BLOCK,    0},
    {          0,     0,           0,           0,           0,           0,           0,          0,           0,          0,           0,          0,           0,          0,          0,           0,    0,    0,    0,    0},
    {          0,     0,           0,           0,           0,           0,           0,          0,           0,          0,           0,          0,           0,          0,          0,           0,    0,    0,    0,    0},
    {          0, BLESS,           0,           0,           0,           0,           0,          0,           0,          0,           0,          0,           0,          0,          0,           0,    0,    0,    0,    0},
    {          0, BLOCK,           0,           0,       BLOCK,           0,           0,      MAGMA,           0,      MAGMA,       MAGMA,      MAGMA,       MAGMA,          0,      BLOCK,           0,BLOCK,    0,    0,    0},
    {          0,     0,           0,           0,           0,           0,           0,          0,           0,          0,           0,          0,           0,          0,          0,           0,    0,    0,    0,    0},
    {          0,     0,           0,           0,           0,           0,           0,          0,           0,          0,           0,          0,           0,          0,          0,           0,    0,    0,    0,    0},
    {          0,     0,           0,           0,           HEART,           0,     FIREPEA,          0,           0,          0,           0,          0,           0,          0,          0,           0,    0,    0,    0,    0},
    {          0,     0,           0,       BLOCK,           0,           0,       BLOCK,          0,           0,      BLOCK,           0,          0,       MAGMA,          0,      BLOCK,       BLOCK,    0,    0,BLOCK,    0},
    {          0,     0,           0,           0,           0,           0,           0,          0,           0,          0,           0,          0,           0,          0,          0,           0,    0,    0,ENTER3,    0},
    {          0,     0,           0,           0,           0,           0,           0,          0,           0,          0,           0,          0,           0,          0,          0,           0,    0,    0,BLOCK,    0},
    {          0,     0,       BLOCK,           0,           0,           0,           0,          0,           0,   0,           LONGBLOCKBAR,0,           0,          0,          0,           0,    0,    0,BLOCK,    0},
    {          0, BLOCK,       BLOCK,           0,           0,           0,           0,          0,           0,        0,BARBASE,      0,           0,          0,          0,           0,    0,    0,BLOCK,    0},
    {          0, BLOCK,           0,           0,       BLOCK,           0,           0,      BLOCK,           0,          0,       BLOCK,          0,           0,      BLOCK,          0,           0,BLOCK,    0,    0,BLOCK}
};

void MakeInitSprite3()
{
    char* szName = NULL;
    int iLoopX = 0, iLoopY = 0;
    for( iLoopY = 0; iLoopY < GRID_COUNTROW; iLoopY++ )
    {
        for( int iLoopX = 0; iLoopX < GRID_COUNTCOL; iLoopX++ )
        {
            if( 0 == g_iGridData[iLoopY][iLoopX] )
                continue;

            if( RIGID_BLOCK == g_iGridData[iLoopY][iLoopX] )
            {
                szName = dMakeSpriteName( "RigidBlock", g_iRigidBlockCount );
                dCloneSprite( "RigidBlock", szName );
                MoveSpriteToBlock( szName, iLoopX, iLoopY );
                g_iRigidBlockCount++;
               dSetSpriteConstantForceY(szName,30.f );
            }
            else if( HEART == g_iGridData[iLoopY][iLoopX] )
            {
                szName = dMakeSpriteName( "heart", g_iheartCount );
                dCloneSprite( "heart", szName );
                MoveSpriteToBlock( szName, iLoopX, iLoopY );
                g_iheartCount++;
            }
            if( BLESS == g_iGridData[iLoopY][iLoopX] )
            {
                szName = dMakeSpriteName( "bless", g_iblessCount );
                dCloneSprite( "bless", szName );
                MoveSpriteToBlock( szName, iLoopX, iLoopY );
                g_iblessCount++;
            }
            else if( MAGMA  == g_iGridData[iLoopY][iLoopX] )
            {
                szName = dMakeSpriteName( "magma", g_imagmaCount );
                dCloneSprite( "magma", szName );
                MoveSpriteToBlock( szName, iLoopX, iLoopY );
                g_imagmaCount++;
            }
            else if( ENTER3 == g_iGridData[iLoopY][iLoopX] )
            {
                szName = dMakeSpriteName( "enter3", g_ienter3Count );
                dCloneSprite( "enter3", szName );
                MoveSpriteToBlock( szName, iLoopX, iLoopY );
                g_ienter3Count++;
            }
            else if( ENTER2 == g_iGridData[iLoopY][iLoopX] )
            {
                szName = dMakeSpriteName( "enter2", g_ienter2Count );
                dCloneSprite( "enter2", szName );
                MoveSpriteToBlock( szName, iLoopX, iLoopY );
                g_ienter2Count++;
            }
            //
            else if( FIREPEA == g_iGridData[iLoopY][iLoopX] )
            {
                szName = dMakeSpriteName( "firepea", g_ifirepeaCount );
                dCloneSprite( "firepea", szName );
                MoveSpriteToBlock( szName, iLoopX, iLoopY );
                g_ifirepeaCount++;
            }
            else if( BLOCK == g_iGridData[iLoopY][iLoopX] )
            {
                szName = dMakeSpriteName( "block", g_iblockCount );
                dCloneSprite( "block", szName );
                MoveSpriteToBlock( szName, iLoopX, iLoopY );
                g_iblockCount++;
            }
            else if( BLOCK == g_iGridData[iLoopY][iLoopX] )
            {
                szName = dMakeSpriteName( "block", g_iblockCount );
                dCloneSprite( "block", szName );
                MoveSpriteToBlock( szName, iLoopX, iLoopY );
                g_iblockCount++;
            }
            else if( LONGBLOCKBAR == g_iGridData[iLoopY][iLoopX] )
            {
                szName = dMakeSpriteName( "longblockbar", g_ilongblockbarCount );
                dCloneSprite( "longblockbar", szName );
                MoveSpriteToBlock( szName, iLoopX, iLoopY );
                g_ilongblockbarCount++;
            }
            else if( BARBASE == g_iGridData[iLoopY][iLoopX] )
            {
                szName = dMakeSpriteName( "barbase", g_ibarbaseCount );
                dCloneSprite( "barbase", szName );
                MoveSpriteToBlock( szName, iLoopX, iLoopY );
                g_ibarbaseCount++;
            }
        }
    }
    dSetSpriteLinearVelocity( "WaterDrop", 0.f, 0.f );
    MoveSpriteToBlock( "WaterDrop", iControlStartX, iControlStartY );
    dSetSpriteConstantForce("WaterDrop",0,10,0);
    dSetSpriteLinearVelocity( "Drop", 0.f, 0.f );
    MoveSpriteToBlock( "Drop", iControlStartX+1, iControlStartY-1 );
    dSetSpriteConstantForce("Drop",0,10,0);
}

void coljugde3(int iIndexX,int iIndexY)
{
    if(( ENTER3 == g_iGridData[iIndexY][iIndexX] ))
    {
        g_iGameState = 1;
        g_iCurLevel=14;
        GameInit();
    }
}

void SpriteColSet3()
{
    dSetSpriteCollisionSend("WaterDrop",true);
    dSetSpriteCollisionPhysicsSend("WaterDrop",true);
    //heart
    dSetSpriteCollisionReceive("magma",true);
    dSetSpriteCollisionPhysicsReceive("magma",true);
    //firetree
    dSetSpriteCollisionReceive("bless",true);
    dSetSpriteCollisionPhysicsReceive("bless",true);
    //firetree
    dSetSpriteCollisionReceive("block",true);
    dSetSpriteCollisionPhysicsReceive("block",true);
    //
    dSetSpriteCollisionReceive("RigidBlock",true);
    dSetSpriteCollisionPhysicsReceive("RigidBlock",true);
     //
    dSetSpriteCollisionReceive("longblockbar",true);
    dSetSpriteCollisionPhysicsReceive("longblockbar",true);
     //
    dSetSpriteCollisionReceive("barbase",true);
    dSetSpriteCollisionPhysicsReceive(" barbase",true);
    //
    dSetSpriteCollisionReceive("heart",true);
    dSetSpriteCollisionPhysicsReceive("heart",true);
     //
    dSetSpriteCollisionReceive("firepea",true);
    dSetSpriteCollisionPhysicsReceive("firepea",true);
}

void OnSpriteColSprite3( const char *szSrcName, const char *szTarName )
{

    if(strstr(szTarName,"bless")&&strstr(szSrcName,"WaterDrop"))
    {
        dPlaySound("hp+.wav",0,1);
        dPlayEffect("Blesseffect",3.f, dGetSpritePositionX("WaterDrop"), dGetSpritePositionY("WaterDrop"), 0.f );
        hp+=3;
        dSetTextValue("hp1",hp);
        dDeleteSprite(szTarName);
    }
    else if(strstr(szTarName,"firepea")&&strstr(szSrcName,"WaterDrop"))
    {
        dPlayEffect("smokeExplode",3.f, dGetSpritePositionX("WaterDrop"), dGetSpritePositionY("WaterDrop"), 0.f );
        hp--;
        dSetTextValue("hp1",hp);
    }
    else if(strstr(szTarName,"magma")&&strstr(szSrcName,"WaterDrop"))
    {
       dPlayEffect("smokeExplode",3.f, dGetSpritePositionX("WaterDrop"), dGetSpritePositionY("WaterDrop"), 0.f );
        hp--;
        dSetTextValue("hp1",hp);
    }
    else if(strstr(szTarName,"longblockbar")&&strstr(szSrcName,"WaterDrop"))
    {
        ilongblockbarstart=1;
    }
    else if(strstr(szTarName,"heart")&&strstr(szSrcName,"WaterDrop"))
    {
        dPlaySound("hp+.wav",0,1);
        dDeleteSprite(szTarName);
        hp++;
        dSetTextValue("hp1",hp);
    }
    if(strstr(szSrcName,"Bullet2")&&strstr(szTarName,"firepea"))
    {
        dPlayEffect("littleExplode",3.f, dGetSpritePositionX(szTarName), dGetSpritePositionY(szTarName), 0.f );
        f5++;
        if(f5==3)
        {
            dPlaySound("baozha.wav",0,1);
            dPlayEffect("bigExplode",3.f, dGetSpritePositionX(szTarName), dGetSpritePositionY(szTarName), 0.f );
            dDeleteSprite(szTarName);
            f5=0;
            if(strstr(szTarName,"firepea0"))
            {
                islivefirepea0=0;
                islivefirepea1just=0;
            }
            if(strstr(szTarName,"firepea1"))
            islivefirepea1=0;
        }
        dDeleteSprite(szSrcName);
    }
}

void ClsPreSprite3()
{
    int  iLoop = 0;
    char* szName = NULL;
    for( iLoop = 0; iLoop < g_ifirepeaCount; iLoop++ )
    {
        szName = dMakeSpriteName( "firepea", iLoop );
        dDeleteSprite( szName );
    }
    for( iLoop = 0; iLoop < g_ienter3Count; iLoop++ )
    {
        szName = dMakeSpriteName( "enter3", iLoop );
        dDeleteSprite( szName );
    }
    for( iLoop = 0; iLoop < g_ienter2Count; iLoop++ )
    {
        szName = dMakeSpriteName( "enter2", iLoop );
        dDeleteSprite( szName );
    }
    for( iLoop = 0; iLoop < g_imagmaCount; iLoop++ )
    {
        szName = dMakeSpriteName( "magma", iLoop );
        dDeleteSprite( szName );
    }
    for( iLoop = 0; iLoop < g_iblessCount; iLoop++ )
    {
        szName = dMakeSpriteName( "bless", iLoop );
        dDeleteSprite( szName );
    }
    for( iLoop = 0; iLoop < g_iblockCount; iLoop++ )
    {
        szName = dMakeSpriteName( "block", iLoop );
        dDeleteSprite( szName );
    }
    for( iLoop = 0; iLoop < g_iRigidBlockCount; iLoop++ )
    {
        szName = dMakeSpriteName( "RigidBlock", iLoop );
        dDeleteSprite( szName );
    }
    for( iLoop = 0; iLoop < g_ilongblockbarCount; iLoop++ )
    {
        szName = dMakeSpriteName( "longblockbar", iLoop );
        dDeleteSprite( szName );
    }
    for( iLoop = 0; iLoop < g_ilongblockbarCount; iLoop++ )
    {
        szName = dMakeSpriteName( "barbase", iLoop );
        dDeleteSprite( szName );
    }
    for( iLoop = 0; iLoop < g_iheartCount; iLoop++ )
    {
        szName = dMakeSpriteName( "heart", iLoop );
        dDeleteSprite( szName );
    }
}

void longblockbarRotation(float fDeltaTime)
{
    float fPosX = dGetSpritePositionX( "WaterDrop" );
    float fPosY = dGetSpritePositionY( "WaterDrop" );
    int  iIndexX = SpritePosXToIndexX( fPosX );
    int  iIndexY = SpritePosYToIndexY( fPosY );
    if(g_iCurLevel==6)
    {
        const  float fRotateSpeed =  15.f;
        float fThisRotate = fRotateSpeed * fDeltaTime;


        if(ilongblockbarstart)
        {
            if( g_ilongblockbarToLeft==0)    // ni转动
        {
            g_flongblockbarRotation -= fThisRotate;
            if( g_flongblockbarRotation <= -20.f )
            {
                g_flongblockbarRotation = -20.f;
                g_ilongblockbarToLeft = 1;
            }
        }
        else  if((g_ilongblockbarToLeft == 1)&&iIndexX>10&&iIndexX<17&&iIndexY>6)         // shun转动
        {
            g_flongblockbarRotation += fThisRotate;
            if( g_flongblockbarRotation >= 20.f )
            {
                g_flongblockbarRotation = 20.f;
            }

        }
            dSetSpriteRotation( "longblockbar0", g_flongblockbarRotation );
        }
    }
}
