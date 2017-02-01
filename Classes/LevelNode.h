//
//  LevelNode.h
//  SLOW
//
//  Created by Volodymyr Klymenko on 19.01.17
//
//

#ifndef __LevelNode__
#define __LevelNode__

#include "cocos2d.h"
#include "cocos/editor-support/spritebuilder/SpriteBuilder.h"
#include "cocos/editor-support/spritebuilder/CCBXNodeLoader.h"
#include "cocos/editor-support/spritebuilder/CCBXSpriteLoader.h"

USING_NS_CC;
using namespace cocos2d::spritebuilder;

class LevelNode : public Node, public CCBXReaderOwner {
public:
    virtual bool init();
    CREATE_FUNC(LevelNode);
protected:
    LevelNode();
    ~LevelNode();

};

#endif
