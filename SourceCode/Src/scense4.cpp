#include "CommonAPI.h"
#include "scenseX.h"
#include"stdio.h"
int g_icloudaCount=0;
int g_iclouda1Count=0;
int g_iclouda2Count=0;
int g_iclouda3Count=0;
int g_icloudbCount=0;
int g_icloudb1Count=0;
int g_icloudb2Count=0;
int g_icactus1Count=0;
int g_icactus2Count=0;
int g_iexit1Count=0;
int g_iexit2Count=0;
int g_isnakeCount=0;

int g_isnake2Count=0;
int g_ifirecircleCount=0;
int islivecactus20=1;
int islivecactus21=1;
int islivesnake11=1;

int islivesnake12=1;
int islivesnake22=1;
int islivefiretree=1;
int islivemushrooom2=1;
int islivespider=1;
int f=0;
int f2=0;
int f3=0;
int f4=0;

const int m_iLevelData41[GRID_COUNTROW][GRID_COUNTCOL]=
{
    {          0,     0,           0,           0,           0,           0,           0,          0,           0,          0,           0,          0,           0,          0,          0,           0,    0,    0,    0,    0},
    {          0,     0,           0,           0,           0,           0,           0,       0,           0,          0,           0,          0,           0,          COIN,       CACTUS2,           0,    0,    0,    0,    0},
    {      BLOCK,     0,           0,           0,           0,           0,           0,          0,           0,          0,     CLOUDB1,          0,           0,          0,      BLOCK,           0,    0,    0,    0,    0},
    {      BLOCK,     0,           0,           0,     CLOUDA1,           0,           0,          0,           0,          0,           0,          0,           0,          0,          0,           0,    0,CLOUDB2,    0,    0},
    {      BLOCK,     0,           0,           0,           0,           0,           0,          0,           0,          0,           0,          0,        0,          0,          0,           0,    0,    0,    0,    0},
    {      BLOCK,     0,           0,           0,           0,           0,           0,          0,           0,          0,           0,          0,           0,          0,          0,           0,    0,    0,    0,    0},
    {          0,     0,           0,           0,           0,           0,           0,          0,           0,          0,           0,          0,           0,          0,          0,           0,    0,    0,    0,    0},
    {          0,     0,           0,           0,           0,           0,           0,          0,      CLOUDB,          0,           0,          0,           0,          0,          0,           0,    0,    SNAKE,COIN,    EXIT1},
    {          0,     0,           0,           0,           0,      CLOUDA,           0,          0,           0,          0,           0,          0,           0,          0,          0,           0,    0,BLOCK,BLOCK,BLOCK},
    {          0,     0,           0,           0,           0,           0,           0,          0,           0,          0,           0,          0,           0,          0,          0,           0,    0,    0,    0,    0},
    {          0,     0,           0,           0,           0,           0,           0,          0,           0,          0,           0,          0,           0,          0,          0,           0,    0,    0,    0,    0},
    {          0,     0,           0,           0,           0,           0,           0,          0,        CACTUS2,          COIN,     CLOUDA3,          0,           0,          0,          0,           0,    0,    0,    0,    0},
    {         0,CLOUDA2,           0,           0,           0,           0,           0,          0,       BLOCK,          0,           0,          0,           0,          0,          0,           0,    0,    0,    0,    0},
    {          0,     0,           0,           0,           0,           0,           0,          0,           0,          0,           0,          0,           0,          0,          0,           0,    0,    0,    0,    0},
    {          0,     0,           0,           0,           0,           0,           0,          0,           0,          0,           0,          0,           0,          0,          0,           0,    0,    0,    0,    0}
};

const int m_iLevelData42[GRID_COUNTROW][GRID_COUNTCOL]=
{
    {          0,     0,           0,           0,           0,           0,           0,          0,           0,          0,           0,          0,           0,          0,          0,           0,    0,    0,    0,    0},
    {          0,     0,           0,           0,           0,           0,           0,          0,           0,          0,           0,          0,           0,          0,          0,           0,    0,    0,    0,    0},
    {          0,     0,           0,           0,           0,           0,           0,          0,           0,          0,           0,          0,           0,          0,          0,           0,    0,    0,    0,    0},
    {          0,     0,           0,           0,           0,           0,           0,          0,           0,          0,           0,      SNAKE,           0,          0,       COIN,           0,    0,    0,    0,    0},
    {          0,     0,           0,           0,           0,           0,           0,          0,           0,          0,           0,      BLOCK,       BLOCK,          0,      BLOCK,           0,    0,    0,    0,    0},
    {          0,     0,           0,           0,           0,           0,           0, FIRECIRCLE,           0,          0,           0,          0,           0,          0,          0,           0,    0,    0,    0,    0},
    {          0,     0,           0,           0,           0,           0,       BLOCK,      BLOCK,       BLOCK,          0,           0,          0,           0,          0,          0,           0,    0,    0,    0,    0},
    {          0,     0,  FIRECIRCLE,           0,           0,           0,           0,          0,           0,          0,           0,          0,           0,          0,          FIRETREE,           0,    0,    0,    0,    0},
    {      BLOCK, BLOCK,           0,       BLOCK,           0,           0,           0,          0,           0,          0,           0,          0,           0,            0,          0,           COIN,    0,    0,    0,    0},
    {          0,     0,           0,           0,           0,           0,           0,          0,           0,          0,           0,          0,           0,            0,      BLOCK,       BLOCK,BLOCK,    BLOCK,    0,    0},
    {          0,     0,           0,           0,           0,           0,           0,           FIRECIRCLE,           0,      SNAKE2,          0,          0,           0,       COIN,          0,           0,    0,    0,    0,    0},
    {          0,     0,           0,           0,           0,           0,           0,          BLOCK,          BLOCK,      BLOCK,       BLOCK,          0,       BLOCK,      0,          0,           0,    0,    0,   0,    0},
    {          0,     0,           0,           0,           MUSHROOM_TWO,           COIN,           0,          0,           0,          0,           0,          0,           0,          0,          0,           0,    0,    0,    0,    0},
    {          0,     0,           0,           0,           BLOCK,          BLOCK,           0,          0,           0,          0,           0,          0,        COIN,          0,     SPIDER,           0,    0,    0,    0, EXIT2},
    {          0,     0,           0,           0,           BLOCK,           BLOCK,           0,          0,           0,          0,           0,          0,       BLOCK,      BLOCK,      BLOCK,       BLOCK,BLOCK,BLOCK,BLOCK,BLOCK}
};
void MakeInitSprite4()
{
    char* szName = NULL;
    int iLoopX = 0, iLoopY = 0;
    for( iLoopY = 0; iLoopY < GRID_COUNTROW; iLoopY++ )
    {
        for( int iLoopX = 0; iLoopX < GRID_COUNTCOL; iLoopX++ )
        {
            if( 0 == g_iGridData[iLoopY][iLoopX] )
                continue;
            if( CLOUDA == g_iGridData[iLoopY][iLoopX] )
            {
                szName = dMakeSpriteName( "clouda", g_icloudaCount );
                dCloneSprite( "clouda", szName );
                MoveSpriteToBlock( szName, iLoopX, iLoopY );
                g_icloudaCount++;
            }
            else if( CLOUDA1== g_iGridData[iLoopY][iLoopX] )
            {
                szName = dMakeSpriteName( "clouda1", g_iclouda1Count );
                dCloneSprite( "clouda1", szName );
                MoveSpriteToBlock( szName, iLoopX, iLoopY );
                g_iclouda1Count++;
                dSetSpriteFlipX(szName, false);
                left_and_rightmove(szName,2,13);
            }
            else if( CLOUDA2 == g_iGridData[iLoopY][iLoopX] )
            {
                szName = dMakeSpriteName( "clouda2", g_iclouda2Count );
                dCloneSprite( "clouda2", szName );
                MoveSpriteToBlock( szName, iLoopX, iLoopY );
                g_iclouda2Count++;
                dSetSpriteFlipX(szName, false);
                left_and_rightmove(szName,-1,8);
            }
            else if(CLOUDA3 == g_iGridData[iLoopY][iLoopX] )
            {
                szName = dMakeSpriteName( "clouda3", g_iclouda3Count );
                dCloneSprite( "clouda3", szName );
                MoveSpriteToBlock( szName, iLoopX, iLoopY );
                g_iclouda3Count++;
                up_and_rightmove(szName,8,18,10,15);
            }
            else if( CLOUDB == g_iGridData[iLoopY][iLoopX] )
            {
                szName = dMakeSpriteName( "cloudb", g_icloudbCount );
                dCloneSprite( "cloudb", szName );
                MoveSpriteToBlock( szName, iLoopX, iLoopY );
                g_icloudbCount++;
            }
            else if( CLOUDB1 == g_iGridData[iLoopY][iLoopX] )
            {
                szName = dMakeSpriteName( "cloudb1", g_icloudb1Count );
                dCloneSprite( "cloudb1", szName );
                MoveSpriteToBlock( szName, iLoopX, iLoopY );
                g_icloudb1Count++;
                dSetSpriteFlipX(szName, true);
                left_and_rightmove(szName,5,13);
            }
            else if( CLOUDB2 == g_iGridData[iLoopY][iLoopX] )
            {
                szName = dMakeSpriteName( "cloudb2", g_icloudb2Count );
                dCloneSprite( "cloudb2", szName );
                MoveSpriteToBlock( szName, iLoopX, iLoopY );
                g_icloudb2Count++;
                up_and_rightmove(szName,8,19,5,11);
            }
            else if( BLOCK == g_iGridData[iLoopY][iLoopX] )
            {
                szName = dMakeSpriteName( "block", g_iblockCount );
                dCloneSprite( "block", szName );
                MoveSpriteToBlock( szName, iLoopX, iLoopY );
                g_iblockCount++;
            }
            else if( CACTUS2 == g_iGridData[iLoopY][iLoopX] )
            {
                szName = dMakeSpriteName( "cactus2", g_icactus2Count );
                dCloneSprite( "cactus2", szName );
                MoveSpriteToBlock( szName, iLoopX, iLoopY );
                g_icactus2Count++;
            }
            else if( COIN == g_iGridData[iLoopY][iLoopX] )
            {
                szName = dMakeSpriteName( "coin", g_icoinCount );
                dCloneSprite( "coin", szName );
                MoveSpriteToBlock( szName, iLoopX, iLoopY );
                g_icoinCount++;
            }
            else if( EXIT1 == g_iGridData[iLoopY][iLoopX] )
            {
                szName = dMakeSpriteName( "exit1", g_iexit1Count );
                dCloneSprite( "exit1", szName );
                MoveSpriteToBlock( szName, iLoopX, iLoopY );
                g_iexit1Count++;
            }
            else if( EXIT2 == g_iGridData[iLoopY][iLoopX] )
            {
                szName = dMakeSpriteName( "exit2", g_iexit2Count );
                dCloneSprite( "exit2", szName );
                MoveSpriteToBlock( szName, iLoopX, iLoopY );
                g_iexit2Count++;
            }
            else if( SPIDER == g_iGridData[iLoopY][iLoopX] )
            {
                szName = dMakeSpriteName( "spider", g_ispiderCount );
                dCloneSprite( "spider", szName );
                MoveSpriteToBlock( szName, iLoopX, iLoopY );
                g_ispiderCount++;
                left_and_rightmove(szName,10,20);
            }
            else if( FIRETREE == g_iGridData[iLoopY][iLoopX] )
            {
               szName = dMakeSpriteName( "firetree", g_ifiretreeCount );
                dCloneSprite( "firetree", szName );
                MoveSpriteToBlock( szName, iLoopX, iLoopY );
                g_ifiretreeCount++;
               left_and_rightmove(szName,12,20);
            }
            else if( SNAKE == g_iGridData[iLoopY][iLoopX] )
            {
                szName = dMakeSpriteName( "snake", g_isnakeCount );
                dCloneSprite( "snake", szName );
                MoveSpriteToBlock( szName, iLoopX, iLoopY );
                g_isnakeCount++;
                 if(g_iCurLevel==8)
                    left_and_rightmove(szName,9,16);
                if(g_iCurLevel==7)
                    left_and_rightmove(szName,15,20);
            }
            else if( SNAKE2 == g_iGridData[iLoopY][iLoopX] )
            {
                szName = dMakeSpriteName( "snak", g_isnakeCount );
                dCloneSprite( "snak", szName );
                MoveSpriteToBlock( szName, iLoopX, iLoopY );
                g_isnakeCount++;
                left_and_rightmove(szName,4,15);
            }
             else if( MUSHROOM_TWO == g_iGridData[iLoopY][iLoopX] )
            {
                szName = dMakeSpriteName( "mushroom2", g_imushroom2Count );
                dCloneSprite( "mushroom2", szName );
                MoveSpriteToBlock( szName, iLoopX, iLoopY );
                g_imushroom2Count++;
                left_and_rightmove(szName,1,8);
            }
            else if( FIRECIRCLE == g_iGridData[iLoopY][iLoopX] )
            {
                szName = dMakeSpriteName( "firecircle", g_ifirecircleCount );
                dCloneSprite( "firecircle", szName );
                MoveSpriteToBlock( szName, iLoopX, iLoopY );
                g_ifirecircleCount++;
                dSetSpriteAutoRot(szName, 30.f);
            }

        }
    }
    dSetSpriteLinearVelocity( "WaterDrop", 0.f, 0.f );
    MoveSpriteToBlock( "WaterDrop", iControlStartX, iControlStartY );
    dSetSpriteConstantForce("WaterDrop",0,10,0);
}

int EnemyDeath()
{
    if((!islivesnake12)&&(!islivesnake22)&&(!islivefiretree)&&(!islivemushrooom2)&&(!islivespider))
        return 1;

    else
        return 0;
}

void coljugde4(int iIndexX,int iIndexY)
{
    if(( EXIT2 == g_iGridData[iIndexY][iIndexX] )&&iIndexX>0&&EnemyDeath()&&(coindeletecount>15))
    {
        g_iGameState = 1;
        g_iCurLevel=10;
        GameInit();
    }
   if(( EXIT1 == g_iGridData[iIndexY][iIndexX] )&&iIndexX>0&&!islivecactus20&&!islivecactus21&&!islivesnake11&&(coindeletecount>5))//only odd number!!!!!
    {
        g_iGameState = 1;
        g_iCurLevel=8;
    }
    if(( FIRECIRCLE == g_iGridData[iIndexY][iIndexX] ))
    {
        dPlaySound("water.wav",0,1);
        hp--;
        dSetTextValue("hp1",hp);
    }
    EnemyDeath();
}

void SpriteColSet4()
{
    //
    dSetSpriteCollisionReceive("snake",true);
    dSetSpriteCollisionPhysicsReceive("snake",true);
    //
    dSetSpriteCollisionReceive("snak",true);
    dSetSpriteCollisionPhysicsReceive("snak",true);
     //mushroom
    dSetSpriteCollisionReceive("mushroom2",true);
    dSetSpriteCollisionPhysicsReceive("mushroom2",true);
    //firetree
    dSetSpriteCollisionReceive("firetree",true);
    dSetSpriteCollisionPhysicsReceive("firetree",true);
    //
    dSetSpriteCollisionSend("WaterDrop",true);
    dSetSpriteCollisionPhysicsSend("WaterDrop",true);
    //
    dSetSpriteCollisionReceive("coin",true);
    dSetSpriteCollisionPhysicsReceive("coin",true);
    //
    dSetSpriteCollisionReceive("clouda",true);
    dSetSpriteCollisionPhysicsReceive("clouda",true);
    //heart
    dSetSpriteCollisionReceive("clouda1",true);
    dSetSpriteCollisionPhysicsReceive("clouda1",true);
    //firetree
    dSetSpriteCollisionReceive("clouda2",true);
    dSetSpriteCollisionPhysicsReceive("clouda2",true);
    //heart
    dSetSpriteCollisionReceive("clouda3",true);
    dSetSpriteCollisionPhysicsReceive("clouda3",true);
    //firetree
    dSetSpriteCollisionReceive("cloudb",true);
    dSetSpriteCollisionPhysicsReceive("cloudb",true);
    //firetree
    dSetSpriteCollisionReceive("cloudb1",true);
    dSetSpriteCollisionPhysicsReceive("cloudb1",true);
    //firetree
    dSetSpriteCollisionReceive("cloudb2",true);
    dSetSpriteCollisionPhysicsReceive("cloudb2",true);
    //firetree
    dSetSpriteCollisionReceive("cactus2",true);
    dSetSpriteCollisionPhysicsReceive("cactus2",true);
    //
    dSetSpriteCollisionReceive("block",true);
    dSetSpriteCollisionPhysicsReceive("block",true);
    //heart
    dSetSpriteCollisionReceive("spider",true);
    dSetSpriteCollisionPhysicsReceive("spider",true);
}

void OnSpriteColSprite4( const char *szSrcName, const char *szTarName )
{
    if(strstr(szTarName,"coin")&&strstr(szSrcName,"WaterDrop"))
    {
        dPlaySound("coin.wav",0,1);
        dDeleteSprite(szTarName);
        coindeletecount++;
        dSetTextValue("coincount",coindeletecount);
    }
    if(strstr(szSrcName,"Bullet2")&&strstr(szTarName,"snake"))
    {
        dPlayEffect("smokeExplode",3.f, dGetSpritePositionX(szTarName), dGetSpritePositionY(szTarName), 0.f );
        f++;
        if(f==3)
        {
             dPlayEffect("bigExplode",3.f, dGetSpritePositionX(szTarName), dGetSpritePositionY(szTarName), 0.f );
            dDeleteSprite(szTarName);
            dPlaySound("baozha.wav",0,1);
            f=0;
            if(g_iCurLevel==7)
                islivesnake11=0;
            else if(g_iCurLevel==8)
                islivesnake12=0;
        }
          dDeleteSprite(szSrcName);
    }
    if(strstr(szSrcName,"Bullet2")&&strstr(szTarName,"cactus2"))
    {
        dPlayEffect("smokeExplode",3.f, dGetSpritePositionX(szTarName), dGetSpritePositionY(szTarName), 0.f );
        f3++;
        if(f3==4)
        {
            dPlayEffect("bigExplode",3.f, dGetSpritePositionX(szTarName), dGetSpritePositionY(szTarName), 0.f );
            dDeleteSprite(szTarName);
            dPlaySound("baozha.wav",0,1);
            f3=0;
            if(strstr(szTarName,"cactus20"))
            islivecactus20=0;
            if(strstr(szTarName,"cactus21"))
            islivecactus21=0;
        }
        dDeleteSprite(szSrcName);
    }
    if(strstr(szSrcName,"Bullet2")&&strstr(szTarName,"snak")&&(g_iCurLevel==8))
    {

        dPlayEffect("smokeExplode",3.f, dGetSpritePositionX(szTarName), dGetSpritePositionY(szTarName), 0.f );
        f2++;
        if(f2==5)
        {
            dPlayEffect("bigExplode",3.f, dGetSpritePositionX(szTarName), dGetSpritePositionY(szTarName), 0.f );
            dDeleteSprite(szTarName);
            dPlaySound("baozha.wav",0,1);
            f2=0;
            islivesnake22=0;
        }
        dDeleteSprite(szSrcName);
    }
     if(strstr(szSrcName,"Bullet2")&&strstr(szTarName,"mushroom2"))
    {
        dPlayEffect("smokeExplode",3.f, dGetSpritePositionX(szTarName), dGetSpritePositionY(szTarName), 0.f );
        f3++;
        if(f3==3)
        {
            dPlayEffect("bigExplode",3.f, dGetSpritePositionX(szTarName), dGetSpritePositionY(szTarName), 0.f );
            dDeleteSprite(szTarName);
            dPlaySound("baozha.wav",0,1);
            f3=0;
            islivemushrooom2=0;
        }
        dDeleteSprite(szSrcName);
    }
    if(strstr(szSrcName,"Bullet2")&&strstr(szTarName,"firetree"))
    {
        dPlayEffect("smokeExplode",3.f, dGetSpritePositionX(szTarName), dGetSpritePositionY(szTarName), 0.f );
        f4++;
        if(f4==4)
        {
            dPlayEffect("bigExplode",3.f, dGetSpritePositionX(szTarName), dGetSpritePositionY(szTarName), 0.f );
            dDeleteSprite(szTarName);
            dPlaySound("baozha.wav",0,1);
            f4=0;
            islivefiretree=0;
        }
        dDeleteSprite(szSrcName);
    }
    if(strstr(szSrcName,"Bullet2")&&strstr(szTarName,"spider"))
    {
        dPlayEffect("smokeExplode",3.f, dGetSpritePositionX(szTarName), dGetSpritePositionY(szTarName), 0.f );
        f4++;
        if(f4==4)
        {
            dPlayEffect("bigExplode",3.f, dGetSpritePositionX(szTarName), dGetSpritePositionY(szTarName), 0.f );
            dDeleteSprite(szTarName);
            dPlaySound("baozha.wav",0,1);
            f4=0;
            islivespider=0;
        }
        dDeleteSprite(szSrcName);
    }
    if(strstr(szSrcName,"WaterDrop")&&(strstr(szTarName,"cactus2")||strstr(szTarName,"snake")||strstr(szTarName,"spider")||strstr(szTarName,"snak")||strstr(szTarName,"firetree")||strstr(szTarName,"mushroom2")))
    {
        dPlaySound("water.wav",0,1);
        hp--;
        dSetTextValue("hp1",hp);
        dPlayEffect("WaterExplode",3.f, dGetSpritePositionX(szSrcName), dGetSpritePositionY(szSrcName), 0.f );
    }

}

void ClsPreSprite4()
{
    int  iLoop = 0;
    char* szName = NULL;
    for( iLoop = 0; iLoop < g_icloudaCount; iLoop++ )
    {
        szName = dMakeSpriteName( "clouda", iLoop );
        dDeleteSprite( szName );
    }
    for( iLoop = 0; iLoop < g_iclouda1Count; iLoop++ )
    {
        szName = dMakeSpriteName( "clouda1", iLoop );
        dDeleteSprite( szName );
    }
    for( iLoop = 0; iLoop < g_iclouda2Count; iLoop++ )
    {
        szName = dMakeSpriteName( "clouda2", iLoop );
        dDeleteSprite( szName );
    }
    for( iLoop = 0; iLoop < g_iclouda3Count; iLoop++ )
    {
        szName = dMakeSpriteName( "clouda3", iLoop );
        dDeleteSprite( szName );
    }
    for( iLoop = 0; iLoop < g_icloudbCount; iLoop++ )
    {
        szName = dMakeSpriteName( "cloudb", iLoop );
        dDeleteSprite( szName );
    }
    for( iLoop = 0; iLoop < g_icloudb1Count; iLoop++ )
    {
        szName = dMakeSpriteName( "cloudb1", iLoop );
        dDeleteSprite( szName );
    }
    for( iLoop = 0; iLoop < g_icloudb2Count; iLoop++ )
    {
        szName = dMakeSpriteName( "cloudb2", iLoop );
        dDeleteSprite( szName );
    }
    for( iLoop = 0; iLoop < g_imushroom2Count; iLoop++ )
    {
        szName = dMakeSpriteName( "mushroom2", iLoop );
        dDeleteSprite( szName );
    }
    for( iLoop = 0; iLoop < g_icactus2Count; iLoop++ )
    {
        szName = dMakeSpriteName( "cactus2", iLoop );
        dDeleteSprite( szName );
    }
    for( iLoop = 0; iLoop < g_iblockCount; iLoop++ )
    {
        szName = dMakeSpriteName( "block", iLoop );
        dDeleteSprite( szName );
    }
    for( iLoop = 0; iLoop < g_icactus1Count; iLoop++ )
    {
        szName = dMakeSpriteName( "cactus1", iLoop );
        dDeleteSprite( szName );
    }
    for( iLoop = 0; iLoop < g_icactus2Count; iLoop++ )
    {
        szName = dMakeSpriteName( "cactus2", iLoop );
        dDeleteSprite( szName );
    }
    for( iLoop = 0; iLoop < g_iblockCount; iLoop++ )
    {
        szName = dMakeSpriteName( "block", iLoop );
        dDeleteSprite( szName );
    }
    for( iLoop = 0; iLoop < g_iexit1Count; iLoop++ )
    {
        szName = dMakeSpriteName( "exit1", iLoop );
        dDeleteSprite( szName );
    }
    for( iLoop = 0; iLoop < g_iexit2Count; iLoop++ )
    {
        szName = dMakeSpriteName( "exit2", iLoop );
        dDeleteSprite( szName );
    }
    for( iLoop = 0; iLoop < g_icoinCount; iLoop++ )
    {
        szName = dMakeSpriteName( "coin", iLoop );
        dDeleteSprite( szName );
    }
    for( iLoop = 0; iLoop < g_ispiderCount; iLoop++ )
    {
        szName = dMakeSpriteName( "spider", iLoop );
        dDeleteSprite( szName );
    }
    for( iLoop = 0; iLoop < g_isnakeCount; iLoop++ )
    {
        szName = dMakeSpriteName( "snake", iLoop );
        dDeleteSprite( szName );
    }
     for( iLoop = 0; iLoop < g_isnake2Count; iLoop++ )
    {
        szName = dMakeSpriteName( "snake2", iLoop );
        dDeleteSprite( szName );
    }
    for( iLoop = 0; iLoop < g_ifirecircleCount; iLoop++ )
    {
        szName = dMakeSpriteName( "firecircle", iLoop );
        dDeleteSprite( szName );
    }
}

void Onclouda1WorldLimit( const char *szName, const int iColSide )
{
    bool	bFlip;
    float	fSpeedX;
    float	fPosY;
    if(strstr(szName, "cloud"))
    {
        if(strstr(szName, "clouda"))
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
        if(strstr(szName, "cloudb"))
        {
            if(iColSide == 1)  // 右边
            {
                bFlip = false;
                fSpeedX = -dRandomRange(10, 15);	// 随机速度
            }
            else if(iColSide == 0)   // 左边
            {
                bFlip = true;
                fSpeedX = dRandomRange(10, 15);     // 随机速度
            }
            dSetSpriteFlipX(szName, bFlip);
            dSetSpriteLinearVelocity(szName, fSpeedX, 0);
        }
    }
}

void OnsnakeWorldLimit( const char *szName, const int iColSide )
{
    bool	bFlip;
    float	fSpeedX;
    float	fPosY;
    if(strstr(szName, "snak")||strstr(szName, "spider"))
    {
        if(iColSide == 1)  // 右边
        {
            bFlip = false;
            fSpeedX = -dRandomRange(10, 15);	// 随机速度
        }
        else if(iColSide == 0)   // 左边
        {
            bFlip = true;
            fSpeedX = dRandomRange(10, 15);     // 随机速度
        }
        dSetSpriteFlipX(szName, bFlip);
        dSetSpriteLinearVelocity(szName, fSpeedX, 0);
    }

}

void OnotherWorldLimit( const char *szName, const int iColSide )
{
    bool	bFlip;
    float	fSpeedX;
    float	fPosY;
    if(strstr(szName, "mushroom2")||strstr(szName, "firetree"))
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

void Oncloudb2WorldLimit( const char *szName, const int iColSide )
{
    bool	bFlip;
    float	fSpeedX;
    float	fSpeedY;
    float	fPosY;
    if(strstr(szName, "cloudb2"))
    {
        if(iColSide == 1)  // 右边
        {
            bFlip = false;
            fSpeedX = -10;
            fSpeedY=5.f;
        }
        else if(iColSide == 2)  // up边
        {
            bFlip = false;
            fSpeedY = 5.f;
            fSpeedX = -10.f;
        }
        else if(iColSide == 0)   // 左边
        {
            bFlip = true;
            fSpeedY = -5.f;
            fSpeedX = 10.f;
        }
        else if(iColSide == 3)   // down边
        {
            bFlip = true;
            fSpeedY = -50.f;  // 随机速度
            fSpeedX=10.f;
        }
        dSetSpriteFlipX(szName, bFlip);
        dSetSpriteLinearVelocity(szName, fSpeedX, fSpeedY);
    }

}

void clouda3upright(const char *szName, const int iColSide )
{
    bool	bFlip;
    float	fSpeedX;
    float	fSpeedY;
    float	fPosY;
    if(strstr(szName, "clouda3"))
    {
        if(iColSide == 1)  // 右边
        {
            bFlip = true;
            fSpeedX = -10.f;
            //fSpeedY=5.f;
        }
        else if(iColSide == 2)  // up边
        {
            bFlip = true;
            fSpeedY = 5.f;
            fSpeedX = -10.f;
        }
        else if(iColSide == 0)   // 左边
        {
            bFlip =false ;
            fSpeedY = -5.f;
            fSpeedX = 10.f;
        }
        else if(iColSide == 3)   // down边
        {
            bFlip = false;
            //fSpeedY = -5.f;  // 随机速度
            fSpeedX=10.f;
        }
        dSetSpriteFlipX(szName, bFlip);
        dSetSpriteLinearVelocity(szName, fSpeedX, fSpeedY);

    }

}
void left_and_rightmove(const char *szName,int x,int y)
{
    float fSpeedX;
    fSpeedX = dRandomRange(5, 10);
    dSetSpriteLinearVelocity(szName, fSpeedX, 0);
    float f_leftboundary=SpriteIndexXToPosX(x);
    float f_rightboundary=SpriteIndexXToPosX(y);
    dSetSpriteWorldLimit(szName, WORLD_LIMIT_BOUNCE, f_leftboundary, g_fGridStartY, f_rightboundary, g_fGridStartY+80.f);
}

void up_and_rightmove(const char *szName,int x,int y,int z,int w)
{
    float fSpeedX;
    fSpeedX = dRandomRange(5, 10);
    dSetSpriteLinearVelocityX(szName, fSpeedX);
    float f_leftboundary=SpriteIndexXToPosX(x);
    float f_rightboundary=SpriteIndexXToPosX(y);
    float f_upboundary=SpriteIndexXToPosX(z);
    float f_downboundary=SpriteIndexXToPosX(w);
    dSetSpriteWorldLimit(szName, WORLD_LIMIT_BOUNCE, f_leftboundary,f_upboundary, f_rightboundary, f_downboundary);
}
