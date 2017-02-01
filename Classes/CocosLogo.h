//
//  
//  
//
//  Created by Volodymyr Klymenko on 19.01.17
//
//

#ifndef __CocosLogo__
#define __CocosLogo__

#include "cocos2d.h"
#include "cocos/editor-support/spritebuilder/SpriteBuilder.h"
#include "cocos/editor-support/spritebuilder/CCBXNodeLoader.h"
#include "cocos/editor-support/spritebuilder/CCBXSpriteLoader.h"


USING_NS_CC;
using namespace std;
using namespace cocos2d::spritebuilder;

class CocosLogo : public Sprite, public CCBXReaderOwner {
public:
    string version;
    CREATE_FUNC(CocosLogo);
protected:
    CocosLogo();
    ~CocosLogo();
};


class CocosLogoSpriteLoader : public SpriteLoader {
    public:
        static SpriteLoader* create() {
            CocosLogoSpriteLoader *ret = new CocosLogoSpriteLoader();
            ret->autorelease();
            return ret;
        }
        virtual Node *createNodeInstance(const Size &parentSize, float mainScale, float additionalScale, CCBXReaderOwner *owner, Node *rootNode, CCBXReaderOwner *rootOwner) const override {
            return CocosLogo::create();
        }
        virtual void onNodeLoaded(Node *node) const override {
            CocosLogo* cocosLogo = static_cast<CocosLogo*>(node);
            ValueMap properties = this->getCustomProperties();
            if (properties.find("version") != properties.end() ) {
                //myClass->setVersion(properties.at("version").asString());
                cocosLogo->version = properties.at("version").asString();
            }
        }
};

#endif
