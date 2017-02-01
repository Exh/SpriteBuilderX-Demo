#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

#include "cocos/editor-support/spritebuilder/SpriteBuilder.h"
#include "cocos/editor-support/spritebuilder/CCBXNodeLoaderLibrary.h"
#include "CocosLogo.h"

USING_NS_CC;
using namespace cocos2d::spritebuilder;
using namespace cocos2d::ui;

class HelloWorld : public cocos2d::Node, public cocos2d::spritebuilder::CCBXReaderOwner
{
public:

    static cocos2d::Scene* createScene();
    
    virtual bool init();
    void click(cocos2d::Ref* target);

    CREATE_FUNC(HelloWorld);
    
private:
    
    CocosLogo *_cocosLogoSprite;
    Label *_labelHello;
    Label *_clickedLabel;
    
protected:
    HelloWorld();
    
};

#endif // __HELLOWORLD_SCENE_H__
