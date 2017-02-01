#include "HelloWorldScene.h"
#include "ui/CocosGUI.h"
#include "CocosLogo.h"

#include "cocos/editor-support/spritebuilder/CCBXNodeLoader.h"
#include "cocos/editor-support/spritebuilder/CCBXSpriteLoader.h"

#include "LevelNode.h"

USING_NS_CC;

using namespace cocos2d::spritebuilder;


Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

HelloWorld::HelloWorld()
{

}


// on "init" you need to initialize your instance
bool HelloWorld::init() {

    if ( !Node::init() ) {
        return false;
    }

    CCBX_SIMPLE_MEMBER_VARIABLE(cocosLogoSprite);
    CCBX_SIMPLE_MEMBER_VARIABLE(labelHello);
    CCBX_SIMPLE_MEMBER_VARIABLE(clickedLabel);
    
    CCBX_SIMPLE_SELECTOR_CLICK(click);
    
    //custom loader
    cocos2d::spritebuilder::NodeLoaderLibrary *library = NodeLoaderLibrary::getDefault();
    library->registerNodeLoader("CocosLogo", &CocosLogoSpriteLoader::create);
    
    //simple loader, just examlpe, not been used or created in SBX
    using LevelNodeLoader = SimpleNodeLoader<LevelNode>;
    library->registerNodeLoader("LevelNode", &LevelNodeLoader::create);
    
    CCBXReader *reader = CCBXReader::createFromFile("HelloWorldScene.ccbi");
    cocos2d::Node * scene = reader->createNode(this, SceneScaleType::MINSCALE);
    this->addChild(scene);
    
    _labelHello->setString(StringUtils::format("Hello\nCocos2d-x v%s",_cocosLogoSprite->version.c_str()));
  
    return true;
}

void HelloWorld::click(cocos2d::Ref* target) {
    _clickedLabel->stopAllActions();
    _clickedLabel->runAction(Blink::create(0.4, 3));
}
