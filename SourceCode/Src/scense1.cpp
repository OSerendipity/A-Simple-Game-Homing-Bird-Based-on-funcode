#include "CommonAPI.h"
#include "scenseX.h"
#include<stdio.h>
int g_iheartCount=0;
int g_imushroomCount=0;
int g_igrassCount=0;
int g_ifiretreeCount=0;
int g_icoinCount=0;
int coindeletecount=0;

const int m_iLevelData11[GRID_COUNTROW][GRID_COUNTCOL] =
{
    {          0,          0,           0, 0,          0,          0,          0,          0,          0,          0,          0,          0,          0,          0,          0,           0,    0, 0, 0,0},
    {          0,          0,           0, 0,          0,          0,          0,          0,          0,          0,          0,          0,          0,          0,          0,           0,    0, 0, 0, 0},
    {MUSHROOM   ,          COIN, 0       , 0,          0,          0,          0,          0,          0,          0,          0,          0,          0,          0,          0,           0,          0, 0, 0, 0},
    {RIGID_BLOCK,RIGID_BLOCK, RIGID_BLOCK, 0,          0,          0,          0,          0,          0,          0,          0,          0,          0,          0,          0,           0,          0, 0, 0, 0},
    {RIGID_BLOCK,          0,           0, 0,          0,          0,          0,          0,          0,          0,          0,          0,          0,          0,          0,           0,          0,   0, 0,0},
    {RIGID_BLOCK,          0,           0, 0,RIGID_BLOCK,RIGID_BLOCK,RIGID_BLOCK,          0,          0,          0,          0,          0,          0,          0,          0,           0,          0,          0, 0,   0},
    {RIGID_BLOCK,          0, COIN       , 0,          0,          0,RIGID_BLOCK, COIN      ,          MUSHROOM,          0,          0,          0,          0,          0,          0,           0,         COIN,   MUSHROOM,          0,   ENTER2 },
    {RIGID_BLOCK,RIGID_BLOCK, RIGID_BLOCK, 0,          0,          0,RIGID_BLOCK,RIGID_BLOCK,RIGID_BLOCK,          0,          0,          0,          0,          0,          0,           0,RIGID_BLOCK,RIGID_BLOCK,RIGID_BLOCK,RIGID_BLOCK},
    {RIGID_BLOCK,          0,           0, 0,       COIN,          MUSHROOM,RIGID_BLOCK,          0,          0,          0,          0,          0,          0,          0,       MUSHROOM,           0,          0, 0, 0, 0},
    {RIGID_BLOCK,          0,           0, 0,RIGID_BLOCK,RIGID_BLOCK,RIGID_BLOCK,          0,          0,          0,          0,          0,          0,RIGID_BLOCK,RIGID_BLOCK,           0,          0, 0, 0, 0},
    {RIGID_BLOCK,          0, COIN       , 0,          0,          0,RIGID_BLOCK,          0,          0,          0,          0,          0,          0,          0,          0,           0,          0,          0, 0, 0},
    {RIGID_BLOCK,RIGID_BLOCK, RIGID_BLOCK, 0,          0,          0,RIGID_BLOCK,   FIRETREE,          0,          0,          0,          0,          0,          0,          0,           0,RIGID_BLOCK,RIGID_BLOCK, 0, 0},
    {0          ,          0,           0, 0,          0,          0,RIGID_BLOCK,          HEART,          0,          0,          0,          COIN,      0,          0,RIGID_BLOCK, RIGID_BLOCK,    0, 0, 0, 0},
    {0          ,          0,          0, 0,RIGID_BLOCK,RIGID_BLOCK,RIGID_BLOCK,RIGID_BLOCK,RIGID_BLOCK,RIGID_BLOCK,RIGID_BLOCK,RIGID_BLOCK,RIGID_BLOCK,          0,          0, RIGID_BLOCK,    0, 0, 0, 0},
    {RIGID_BLOCK,RIGID_BLOCK,RIGID_BLOCK, RIGID_BLOCK, RIGID_BLOCK, RIGID_BLOCK,RIGID_BLOCK,RIGID_BLOCK,RIGID_BLOCK,RIGID_BLOCK,RIGID_BLOCK,RIGID_BLOCK,RIGID_BLOCK,          0,          0, RIGID_BLOCK,    0, 0, 0, 0}
};

const int m_iLevelData12[GRID_COUNTROW][GRID_COUNTCOL] =
{
    {          0,          0,           0,          0,          0,          0,          0,          0,          0,          0,          0,          0,          0,          0,          0,           0,          0, 0, 0,0},
    {          0,          0,           0,          0,          0,          0,          0,          0,          0,          0,          0,          0,          0,          0,          0,           0,          0, 0, 0, 0},
    {          0,          0,           0,          0,          0,          0,          0,          0,          0,          0,          0,          0,          0,          0,          0,           0,          0, 0, 0, 0},
    {          0,          0,           0,          0,          0,          0,          0,          0,          0,          0,          0,          0,          0,          0,          0,           0,          0, 0, 0, 0},
    {          0,          0,           0,          0,          0,          0,          0,          0,RIGID_BLOCK,RIGID_BLOCK,RIGID_BLOCK,          0,          0,          0,          0,           0,          0,   0, 0,0},
    {          0,          0,           COIN,          MUSHROOM,          0,          0,       0,          0,          0,          0,RIGID_BLOCK,       COIN,          MUSHROOM,          0,          0,           0,          0,          0, 0,   0},
    {          0,       0, RIGID_BLOCK,RIGID_BLOCK,          0,RIGID_BLOCK,RIGID_BLOCK,          0,          0,          0,RIGID_BLOCK,RIGID_BLOCK,RIGID_BLOCK,          0,          0,           0,          0,   0,          0,     0},
    {RIGID_BLOCK,RIGID_BLOCK, RIGID_BLOCK,          0,          0,          0,          0,          0,          0,          0,RIGID_BLOCK,          COIN,          0,          0,          0,           0,          0, 0,  0, 0},
    {          0,          0,           0,          0,          0,          0,          0,          0,          0,          0,RIGID_BLOCK,          0,          0,   HEART,          MUSHROOM,           0,          0, 0, 0, 0},
    {          0,          0,           0,          0,RIGID_BLOCK,       COIN,          0,          0,          0,          0,RIGID_BLOCK,RIGID_BLOCK,RIGID_BLOCK,RIGID_BLOCK,RIGID_BLOCK,           0,       COIN, 0, 0, 0},
    {          0,          0,           0,          0,          0,RIGID_BLOCK,          0,          0,          0,          0,          0,          0,          0,          0,          0,           0,          0,          0, 0, 0},
    {          0,          0,           0,          0,      0,          0,          0,          MUSHROOM,          0,          0,          0,          0,          0,          0,          0,           0,          0, 0, 0, 0},
    {       COIN,          0,    MUSHROOM,          HEART,          0,          0,          0,RIGID_BLOCK,RIGID_BLOCK,          0,          0,       0,          COIN,          0,          MUSHROOM,    0,          0, 0, 0,EXIT},
    {RIGID_BLOCK,RIGID_BLOCK, RIGID_BLOCK,RIGID_BLOCK,RIGID_BLOCK,RIGID_BLOCK,RIGID_BLOCK,RIGID_BLOCK,          0,          0,RIGID_BLOCK,RIGID_BLOCK,RIGID_BLOCK,RIGID_BLOCK,RIGID_BLOCK, RIGID_BLOCK,RIGID_BLOCK,RIGID_BLOCK,RIGID_BLOCK,RIGID_BLOCK},
    {          0,          0,           0,          0,          0,          0,          0,          0,          0,          0,          0,          0,          0,          0,          0,           0,          0, 0, 0}
};

void MakeInitSprite1()
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
            }
            else if( ENTER2 == g_iGridData[iLoopY][iLoopX] )
            {
                szName = dMakeSpriteName( "enter2", g_ienter2Count );
                dCloneSprite( "enter2", szName );
                MoveSpriteToBlock( szName, iLoopX, iLoopY );
                g_ienter2Count++;
            }
            else if( EXIT == g_iGridData[iLoopY][iLoopX] )
            {
                szName = dMakeSpriteName( "Exit", g_iExitCount );
                dCloneSprite( "Exit", szName );
                MoveSpriteToBlock( szName, iLoopX, iLoopY );
                g_iExitCount++;
            }
            else if( MUSHROOM == g_iGridData[iLoopY][iLoopX] )
            {
                szName = dMakeSpriteName( "mushroom", g_imushroomCount );
                dCloneSprite( "mushroom", szName );
                MoveSpriteToBlock( szName, iLoopX, iLoopY );
                g_imushroomCount++;
            }
            else if( FIRETREE == g_iGridData[iLoopY][iLoopX] )
            {
               szName = dMakeSpriteName( "firetree", g_ifiretreeCount );
                dCloneSprite( "firetree", szName );
                MoveSpriteToBlock( szName, iLoopX, iLoopY );
                g_ifiretreeCount++;
                float fSpeedX;
                fSpeedX = dRandomRange(5, 10);
		        dSetSpriteLinearVelocity(szName, fSpeedX, 0);
		        float f_leftboundary=SpriteIndexXToPosX(6);
		        float f_rightboundary=SpriteIndexXToPosX(13);
		        dSetSpriteWorldLimit(szName, WORLD_LIMIT_BOUNCE, f_leftboundary, g_fGridStartY , f_rightboundary, g_fGridStartY+80.f);
            }
            else if( HEART == g_iGridData[iLoopY][iLoopX] )
            {
                szName = dMakeSpriteName( "heart", g_iheartCount );
                dCloneSprite( "heart", szName );
                MoveSpriteToBlock( szName, iLoopX, iLoopY );
                g_iheartCount++;
            }
             else if( GRASS == g_iGridData[iLoopY][iLoopX] )
            {
                szName = dMakeSpriteName( "grass", g_igrassCount );
                dCloneSprite( "grass", szName );
                MoveSpriteToBlock( szName, iLoopX, iLoopY );
                g_igrassCount++;
            }
             else if( COIN == g_iGridData[iLoopY][iLoopX] )
            {
                szName = dMakeSpriteName( "coin", g_icoinCount );
                dCloneSprite( "coin", szName );
                MoveSpriteToBlock( szName, iLoopX, iLoopY );
                g_icoinCount++;
            }
        }
    }
    dSetSpriteLinearVelocity( "WaterDrop", 0.f, 0.f );
    MoveSpriteToBlock( "WaterDrop", iControlStartX, iControlStartY );
    dSetSpriteConstantForce("WaterDrop",0,10,0);
}

void coljugde1(int iIndexX,int iIndexY)
{
    if(( EXIT == g_iGridData[iIndexY][iIndexX] )&&(coindeletecount>12))
    {
        g_iGameState = 1;
        g_iCurLevel=12;
        GameInit();
    }
}

void SpriteColSet1()
{
    dSetSpriteCollisionSend("WaterDrop",true);
    dSetSpriteCollisionPhysicsSend("WaterDrop",true);
    //coin可以接收碰撞
    dSetSpriteCollisionReceive("RigidBlock",true);
    dSetSpriteCollisionReceive("coin",true);
    dSetSpriteCollisionPhysicsReceive("RigidBlock",true);
    dSetSpriteCollisionPhysicsReceive("coin",true);
    //mushroom
    dSetSpriteCollisionReceive("mushroom",true);
    dSetSpriteCollisionPhysicsReceive("mushroom",true);
    //heart
    dSetSpriteCollisionReceive("heart",true);
    dSetSpriteCollisionPhysicsReceive("heart",true);
    //firetree
    dSetSpriteCollisionReceive("firetree",true);
    dSetSpriteCollisionPhysicsReceive("firetree",true);
}
void OnSpriteColSprite1( const char *szSrcName, const char *szTarName )
{
    if(strstr(szTarName,"coin")&&strstr(szSrcName,"WaterDrop"))
    {
        dPlaySound("coin.wav",0,1);
        dDeleteSprite(szTarName);
        coindeletecount++;
        dSetTextValue("coincount",coindeletecount);
    }
    else if(strstr(szTarName,"heart")&&(g_iCurLevel==1||g_iCurLevel==2))
    {
        dPlayEffect("wavebang",3.f, dGetSpritePositionX(szSrcName), dGetSpritePositionY(szSrcName), 0.f );
        dPlaySound("hp+.wav",0,1);
        dDeleteSprite(szTarName);
        hp++;
        dSetTextValue("hp1",hp);
    }
    else if(strstr(szTarName,"mushroom")&&(g_iCurLevel==1||g_iCurLevel==2))
    {
        dPlaySound("water.wav",0,1);
        hp--;
        dSetTextValue("hp1",hp);

    }
    else if(strstr(szTarName,"firetree")&&(g_iCurLevel==1||g_iCurLevel==2))
    {
        dPlaySound("water.wav",0,1);
        hp--;
        dSetTextValue("hp1",hp);

    }
}

void ClsPreSprite1()
{

    int  iLoop = 0;
    char* szName = NULL;
    for( iLoop = 0; iLoop < g_iRigidBlockCount; iLoop++ )
    {
        szName = dMakeSpriteName( "RigidBlock", iLoop );
        dDeleteSprite( szName );
    }
    for( iLoop = 0; iLoop < g_ienter2Count; iLoop++ )
    {
        szName = dMakeSpriteName( "enter2", iLoop );
        dDeleteSprite( szName );
    }
    for( iLoop = 0; iLoop < g_iheartCount; iLoop++ )
    {
        szName = dMakeSpriteName( "heart", iLoop );
        dDeleteSprite( szName );
    }
    for( iLoop = 0; iLoop < g_imushroomCount; iLoop++ )
    {
        szName = dMakeSpriteName( "mushroom", iLoop );
        dDeleteSprite( szName );
    }
    for( iLoop = 0; iLoop < g_icoinCount; iLoop++ )
    {
        szName = dMakeSpriteName( "coin", iLoop );
        dDeleteSprite( szName );
    }
    for( iLoop = 0; iLoop < g_ifiretreeCount; iLoop++ )
    {
        szName = dMakeSpriteName( "firetree", iLoop );
        dDeleteSprite( szName );
    }
    for( iLoop = 0; iLoop < g_iExitCount; iLoop++ )
    {
        szName = dMakeSpriteName( "Exit", iLoop );
        dDeleteSprite( szName );
    }
    // 总数置 0，重新创建
}

void OnfiretreeWorldLimit( const char *szName, const int iColSide )
{
    bool	bFlip;
    float	fSpeedX;
    float	fPosY;
    if(strstr(szName, "firetree"))
    {
        if(iColSide == 1)  // 右边
        {
            bFlip = true;
            fSpeedX = -dRandomRange(10, 15);	// 随机速度
        }
        else if(iColSide == 0)   // 左边
        {
            bFlip = false;
            fSpeedX = dRandomRange(10, 15);     // 随机速度
        }
        dSetSpriteFlipX(szName, bFlip);
        dSetSpriteLinearVelocity(szName, fSpeedX, 0);
    }

}
